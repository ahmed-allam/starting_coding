#include "HTTPRequest_12_multiple_threads.h"
#include <ninety47/dukascopy.h>
#include <ninety47/dukascopy/defs.h>
#include <fstream>
#include <iomanip>
#include "modules/utils/utils.h"

std::string HTTPRequest::output_compressed_file_2(unsigned char** data_bin_buffer, size_t buffer_size, const char * file_name)
{
	std::string file_name_path_string = file_name;
	std::ofstream ofs2(file_name_path_string, std::ios::binary);
	ofs2.write(reinterpret_cast<const char*>(*data_bin_buffer), buffer_size);
	ofs2.close();
	return file_name_path_string;
}

std::string HTTPRequest::output_compressed_file(boost::asio::streambuf& taskStreambuf, const std::string& file_name)
{
	std::string file_name_path_string = mHTTPRequest_HTTPClient_shared_pointer->m_dataDailyGet() + "/" + file_name;
	std::ofstream ofs(file_name_path_string,  std::ios::binary);
	ofs.write(boost::asio::buffer_cast<const char*>(taskStreambuf.data()), taskStreambuf.data().size() );
	ofs.close();
	return file_name_path_string;
}
/*
//8-10-2020
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/lzma.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include <fstream>
#include <iostream>
#include <lzma.h>

namespace io = boost::iostreams;

void HTTPRequest::read_bi5_to_bin_boost(std::string input_file_path, std::string output_file_path) {
    namespace io = boost::iostreams;

    std::ifstream file(input_file_path, std::ios::binary);
    std::ofstream out(output_file_path, std::ios::binary);

    boost::iostreams::filtering_istreambuf in;
    in.push(io::lzma_decompressor());
    in.push(file);

    try {
        io::copy(in, out);
    } catch(io::lzma_error const& e) {
        std::cout << boost::diagnostic_information(e, true);
        std::cout << e.code() << ": " << e.code().message() << "\n";
    } catch(boost::exception const& e) {
        std::cout << boost::diagnostic_information(e, true);
    }
}
*/
int HTTPRequest::read_bi5_main(boost::filesystem::path p, ptime epoch)
{
	boost::unique_lock<boost::mutex> read_bi5_to_bin_lock(mBOOST_LOGMutex,boost::defer_lock);
	boost::unique_lock<boost::mutex> read_bi5_to_bin_lock2(m_read_bi5_to_binMutex, boost::defer_lock);

	unsigned char *buffer;
	size_t buffer_size;

	//8-10-2020
	//unsigned char *buffer_bin;
	//size_t buffer_size_bin;

	int counter;

	size_t raw_size = 0;

	std::string filename_string = p.generic_string();
	path p2 = p;
	p2.replace_extension(".bin");
	std::string filename_string_to_bin =p2.generic_string() ;

	path p3 = p;
	p3.replace_extension(".csv");
	std::string filename_string_to_csv = p3.generic_string();

	const char *filename = filename_string.c_str();
	const char *filename_to_bin = filename_string_to_bin.c_str();
	const char *filename_to_csv = filename_string_to_csv.c_str();

	//22-9-2020 here I open the downloaded file if possible
	if (fs::exists(p) && fs::is_regular(p))
	{
		buffer_size = fs::file_size(p);
		buffer = new unsigned char[buffer_size];
	}
	else {
		read_bi5_to_bin_lock.lock();
		BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << "Error: couldn't access the data file. |"
			<< filename << "|" << std::endl;
		read_bi5_to_bin_lock.unlock();
		return 2;
	}


	//22-9-2020 here I read the downloaded file into filestream
	std::ifstream fin(filename, std::ifstream::binary);
	fin.read(reinterpret_cast<char*>(buffer), buffer_size);

	//8-10-2020
	//boost::iostreams::filtering_istreambuf in;
	//in.push(io::lzma_decompressor());
	//in.push(fin);

	fin.close();

	//22-9-2020 here I check if file is related to japanese yen so that I determine how to write its value
	/*
	if symbols_xxx has mHTTPRequest_Symbol_str then PV=0.001
	else if symbols_xxxx has mHTTPRequest_Symbol_str then PV=0.0001
	else if symbols_xxxx has mHTTPRequest_Symbol_str then PV=0.00001
	*/
	//28-9-2020 I will make 3 vectors in utils.h for 3,4,5 point value ,then I find symbol in vector,
	//std::size_t pos = mHTTPRequest_Symbol_str.find("JPY");

	double PV;

	std::vector<std::string>::iterator it3 = std::find(point_value_xxx.begin(), point_value_xxx.end(), mHTTPRequest_Symbol_str);

	std::vector<std::string>::iterator it4 = std::find(point_value_xxxx.begin(), point_value_xxxx.end(), mHTTPRequest_Symbol_str);

	std::vector<std::string>::iterator it5 = std::find(point_value_xxxxx.begin(), point_value_xxxxx.end(), mHTTPRequest_Symbol_str);
	if (it3 != point_value_xxx.end())
	{
		PV = 0.001;
	}
	else if (it4 != point_value_xxxx.end())
	{
		PV = 0.0001;
	}
	else if (it5 != point_value_xxxxx.end())
	{
		PV = 0.00001;
	}
	else
	{
		//10-1-2020throw;
		PV = 0.001;

	}
	read_bi5_to_bin_lock2.lock();
	unsigned char *data_bin_buffer = 0 ;
	/*
	//8-10-2020
    std::ofstream out(filename_to_bin, std::ios::binary);

	try {
		boost::iostreams::filtering_istreambuf in;
		in.push(io::lzma_decompressor());
		in.push(fin);
		int x=in.size();
		io::copy(in, out);
	} catch(io::lzma_error const& e) {
		std::cout << boost::diagnostic_information(e, true);
		std::cout << e.code() << ": " << e.code().message() << "\n";
	} catch(boost::exception const& e) {
		std::cout << boost::diagnostic_information(e, true);
	}
	*/
	//////////////////////////////////////////////////////////////////////////////////////
	n47::tick_data *data = n47::read_bi5_to_bin(buffer, buffer_size, epoch, PV, &raw_size, &data_bin_buffer);

	//5-11-2020 here i will save binary file
	std::string file_name_path_string=output_compressed_file_2(&data_bin_buffer, raw_size, filename_to_bin);
	read_bi5_to_bin_lock2.unlock();

	path file_name_path_2{ file_name_path_string };

	//8-10-2020path file_name_path_2{ filename_to_bin };

	buffer_size = 0;
	//22-9-2020 here I open the binary file if possible
	//n47::tick_data *data=0;
	if (fs::exists(file_name_path_2) && fs::is_regular(file_name_path_2))
	{
		read_bi5_to_bin_lock.lock();
		BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << boost::this_thread::get_id() <<"\t we can access the data .bin file. |"
			<< filename_to_bin << "| with size ="<< fs::file_size(file_name_path_2) << std::endl;
		read_bi5_to_bin_lock.unlock();

		//8-10-2020
		//buffer_size_bin = fs::file_size(file_name_path_2);
		//buffer_bin = new unsigned char[buffer_size_bin];

		// here I read the binary file into filestream
		//std::ifstream fin_bin(filename_to_bin, std::ifstream::binary);
		//fin_bin.read(reinterpret_cast<char*>(buffer_bin), buffer_size_bin);

		// convert to tick data (with read_bin).
		//data = n47::read_bin(buffer_bin, buffer_size_bin, epoch, PV);

	}
	else {
		read_bi5_to_bin_lock.lock();
		BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << "Error: couldn't access the data .bin file. |"
			<< filename_to_bin << "|" << std::endl;
		read_bi5_to_bin_lock.unlock();
		return 2;
	}

	n47::tick_data_iterator iter;

	//5-11-2020 here i will save file.csv from data which is pointer to vector to pointers to ticks
	if (data == 0)
	{
		read_bi5_to_bin_lock.lock();
		BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << "Failure: Failed to load the data!" << std::endl;
		read_bi5_to_bin_lock.unlock();
	}
	//5-15-2020 take care that without else ,error happens with empty files because data is pointer to vector of pointers to ticks .so when data is made inside read_bi5 ,it is made as null pointer and later it is assigned to vector if file has ticks.if file does not have ticks ,then it is just returned as null pointer .so when dereferencing null pointer we got error
	else if (data->size() != (raw_size / n47::ROW_SIZE))
	{
		read_bi5_to_bin_lock.lock();
		BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << "Failure: Loaded " << data->size()
			<< " ticks but file size indicates we should have loaded "
			<< (raw_size / n47::ROW_SIZE) << std::endl;
		read_bi5_to_bin_lock.unlock();
	}
	//22-9-2020 in last if and if else I checked if file is either empty or has error of data size So now I have good clean file to work with
	//read_bi5_to_bin_lock.lock();
	//BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << "time, bid, bid_vol, ask, ask_vol" << std::endl;
	//read_bi5_to_bin_lock.unlock();

	counter = 0;

	std::ofstream out_csv(filename_string_to_csv);
	if (data == 0)
	{

	}
	else if (data != 0)
	{
		for (iter = data->begin(); iter != data->end(); iter++) {
			//5-11-2020 here i will save file.csv from data which is pointer to vector to pointers to ticks>>>>>>>here i should open file stream for output and save data to it
			out_csv
			//<< std::setfill('0')<<std::setw(sizeof((*iter)->epoch + (*iter)->td))<<std::fixed<<((*iter)->epoch + (*iter)->td) << ","
			//<< std::setfill('0')<<std::setw(27)<<std::fixed<<((*iter)->epoch + (*iter)->td) << ","
			<< std::setfill('0')<<((*iter)->epoch + (*iter)->td) << ","
			<< std::setfill('0')<<std::setw(sizeof(*iter)->bid)<<std::fixed << (*iter)->bid << ","
			<< std::setfill('0')<<std::setw(sizeof(*iter)->bidv)<<std::fixed << (*iter)->bidv << ","
			<< std::setfill('0')<<std::setw(sizeof(*iter)->ask)<<std::fixed << (*iter)->ask << ","
			<< std::setfill('0')<<std::setw(sizeof(*iter)->askv)<<std::fixed << (*iter)->askv << std::endl;
			//??5-17-2020 isolate multithreaded error
			/*
			read_bi5_to_bin_lock.lock();
			BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) <<
				boost::this_thread::get_id() << "\t"<<((*iter)->epoch + (*iter)->td) << ", "
				<< (*iter)->bid << ", " << (*iter)->bidv << ", "
				<< (*iter)->ask << ", " << (*iter)->askv << std::endl;
			BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) <<
							boost::this_thread::get_id() << "\t"<< std::setfill('0')<< std::setw(sizeof((*iter)->epoch + (*iter)->td))<<((*iter)->epoch + (*iter)->td) << ","
							<< std::setfill('0')<<std::setw(sizeof(*iter)->bid)<< (*iter)->bid << ","
							<< std::setfill('0')<<std::setw(sizeof(*iter)->bidv)<< (*iter)->bidv << ","
							<< std::setfill('0')<<std::setw(sizeof(*iter)->ask)<< (*iter)->ask << ","
							<< std::setfill('0')<<std::setw(sizeof(*iter)->askv)<< (*iter)->askv << std::endl;
			read_bi5_to_bin_lock.unlock();
			*/
			counter++;
		}
		////read_bi5_to_bin_lock.unlock();

	}
	out_csv.close();
	//5-13-2020

	//??5-17-2020 isolate multithreaded error
	read_bi5_to_bin_lock.lock();

	BOOST_LOG((*mHTTPRequest_LoggingInstance_shared_pointer).mloggerCoutLog) << ".end." << std::endl << std::endl
		<< "From " << raw_size << " bytes we read " << counter
		<< " records." << std::endl
		<< raw_size << " / " << n47::ROW_SIZE << " = "
		<< (raw_size / n47::ROW_SIZE) << std::endl;
	read_bi5_to_bin_lock.unlock();


	delete data;
	delete[] buffer;
	delete [] data_bin_buffer;
	return 0;
}
