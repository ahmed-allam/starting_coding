#pragma once
// constructing maps
#include <map> //Needed to use the std::map class.
#include <string>

const std::map<std::string, int> symbols = {//Create a map.
// commodities - energy    
{"BRENTCMDUSD", 0},  // Brent starting from Thursday Thu Jan  1 00:00:00 1970
{"LIGHTCMDUSD", 0}, // Light starting from Thursday Thu Jan  1 00:00:00 1970
// commodities - metals
{"CUCMDUSD", 0} // Copper starting from 
{"AUCMDUSD", 0} // GOLD
{"E_SI", 0}  //SILVER
{"PDCMDUSD", 0} // Palladium starting from 
{"PTCMDUSD", 0} // Platinum starting from 

// indices - Australia
{"AUSIDXAUD", 0} //S&P/ASX200 (AUSTRALIA)

// indices - BRAZIL
{"BRAIDXBRL", 0} //BRAZIL INDEX

// indices - Europe 
{"NLDIDXEUR", 0} // NETHERLANDS AEX 25 starting from 
{"ITAIDXEUR", 0} // ITALY starting from 
{"ESPIDXEUR", 0} // SPAIN IBEX starting from 
{"EUSIDXEUR", 0} // Europe 50 starting from 
{"FRAIDXEUR", 0} // France CAC 40 starting from 
{"GBRIDXGBP", 0} // UK FTSE 100 starting from 
{"DEUIDXEUR", 0} // Germany DAX 30 starting from 
{"CHEIDXCHF", 0} // Switzerland SMI20 starting from 
// indices - Americas
{"USATECHIDXUSD", 0} // US Tech 100 NASDAQ starting from 
{"USACOMIDXUSD", 0} // US NASDAQ Composite starting from 
{"USA30IDXUSD", 0} // US DOW JONES 30 starting from 
{"USA500IDXUSD", 0} // US S&P 500 starting from 
{"USAMJRIDXUSD", 0} // S&P 500 MAJOR starting from 
// indices - Asia / Pacific
{"HKGIDXHKD", 0} // Hong Kong HANG SENG40 starting from 
//    "E_SCKorea" => 0, // Korea 200 starting from 2012.01.19 16:00
{"JPNIDXJPY", 0} // Japan NIKKEI 225 starting from 

// stocks - Australia
//    "E_ANZASX" => 0, // Australia & Nz Banking starting from 2012.09.20 13:00
//    "E_BHPASX" => 0, // Bhp Billiton starting from 2012.09.20 16:00
//    "E_CBAASX" => 0, // Commonwealth Bank Of Australia starting from 2012.09.20 16:00
//    "E_NABASX" => 0, // National Australia Bank starting from 2012.09.20 16:00
//    "E_WBCASX" => 0, // Westpac Banking starting from 2012.09.20 16:00
// stocks - Hungary
//    "E_EGISBUD" => 0, // Egis Nyrt starting from 2012.09.20 13:00
//    "E_MOLBUD" => 0, // Mol Hungarian Oil & Gas Nyrt starting from 2012.09.20 13:00
//    "E_MTELEKOMBUD" => 0, // Magyar Telekom Telecommunications starting from 2012.09.20 13:00
//    "E_OTPBUD" => 0, // Ot Bank Nyrt starting from 2012.09.20 13:00
//   "E_RICHTERBUD" => 0, // Richter Gedeon Nyrt starting from 2012.09.20 13:00
// stocks - France
//    "E_BNPEEB" => 0, // BNP Paribas starting from 2012.07.06 17:00
//    "E_FPEEB" => 0, // Total starting from 2012.07.06 17:00
//    "E_FTEEEB" => 0, // France Telecom starting from 2012.07.06 17:00
//    "E_MCEEB" => 0, // LVMH Moet Hennessy Louis Vuitton starting from 2012.07.06 17:00
//    "E_SANEEB" => 0, // Sanofi starting from 2012.07.06 17:00
// stocks - Netherlands
//    "E_MTEEB" => 0, // ArcelorMittal starting from 2012.03.30 10:00
//    "E_PHIA" => 0, // Koninklijke Philips Electronics starting from 2012.07.04 13:00
//    "E_RDSAEEB" => 0, // Royal Dutch Shell starting from 2012.03.30 10:00
//    "E_UNAEEB" => 0, // Unilever starting from 2012.03.30 10:00
// stocks - Germany
//    "E_BAY" => 0, // Bayer starting from 2012.03.05 12:00
//    "E_BMWXET" => 0, // BMW starting from 2012.03.30 10:00
//    "E_EOANXET" => 0, // E.On starting from 2012.03.30 10:00
//    "E_SIEXET" => 0, // Siemens starting from 2012.07.06 20:00
//    "E_VOWXET" => 0, // Volkswagen starting from 2012.07.06 20:00
// stocks - Hong Kong
//    "E_0883HKG" => 0, // CNOOC starting from 2012.07.08 21:00
//    "E_0939HKG" => 0, // China Construction Bank starting from 2012.07.08 22:00
//    "E_0941HKG" => 0, // China Mobile starting from 2012.07.08 21:00
//    "E_1398HKG" => 0, // ICBC starting from 2012.07.08 21:00
//    "E_3988HKG" => 0, // Bank Of China starting from 2012.07.08 22:00
// stocks - UK
//    "E_BLTLON" => 0, // BHP Billiton starting from 2012.03.30 10:00
//    "E_BP" => 0, // BP starting from 2012.01.19 16:00
//    "E_HSBA" => 0, // HSBC Holdings starting from 2012.01.19 16:00
//    "E_RIOLON" => 0, // Rio Tinto starting from 2012.03.30 10:00
//    "E_VODLON" => 0, // Vodafone starting from 2012.03.30 10:00
// stocks - Spain
//    "E_BBVAMAC" => 0, // BBVA starting from 2012.09.20 14:00
//    "E_IBEMAC" => 0, // Iberdrola starting from 2012.09.20 14:00
//    "E_REPMAC" => 0, // Repsol starting from 2012.09.20 14:00
//    "E_SANMAC" => 0, // Banco Santander starting from 2012.09.20 14:00
//    "E_TEFMAC" => 0, // Telefonica starting from 2012.09.20 14:00
// stocks - Italy
//    "E_EN" => 0, // Enel starting from 2012.09.20 13:00
//    "E_ENIMIL" => 0, // Eni starting from 2012.09.20 13:00
//    "E_FIA" => 0, // Fiat starting from 2012.09.20 13:00
//    "E_GMIL" => 0, // Generali starting from 2012.09.20 13:00
//    "E_ISPMIL" => 0, // Intesa Sanpaolo starting from 2012.09.20 13:00
//    "E_UCGMIL" => 0, // Unicredit starting from 2012.09.20 13:00
// stocks - Denmark
//    "E_CARL_BOMX" => 0, // Carlsberg starting from 2012.09.20 14:00
//    "E_DANSKEOMX" => 0, // Danske Bank starting from 2012.09.20 14:00
//    "E_MAERSK_BOMX" => 0, // Moeller Maersk B starting from 2012.09.20 14:00
//    "E_NOVO_BOMX" => 0, // Novo Nordisk starting from 2012.09.20 14:00
//    "E_VWSOMX" => 0, // Vestas Wind starting from 2012.09.20 14:00
// stocks - Sweden
//    "E_SHB_AOMX" => 0, // Svenska Handelsbanken starting from 2012.09.20 14:00
//    "E_SWED_AOMX" => 0, // Swedbank starting from 2012.09.20 14:00
//    "E_TLSNOMX" => 0, // Teliasonera starting from 2012.09.20 14:00
//    "E_VOLV_BOMX" => 0, // Volvo B starting from 2012.09.20 14:00
//    "E_NDAOMX" => 0, // Nordea Bank starting from 2012.09.20 14:00
// stocks - Norway
//    "E_DNBOSL" => 0, // DNB starting from 2012.09.20 13:00
//    "E_SDRLOSL" => 0, // Seadrill starting from 2012.09.20 13:00
//    "E_STLOSL" => 0, // StatoilHydro starting from 2012.09.20 13:00
//    "E_TELOSL" => 0, // Telenor starting from 2012.09.20 13:00
//    "E_YAROSL" => 0, // Yara starting from 2012.09.20 13:00
// stocks - Singapore
//    "E_C07SES" => 0, // Jardine Matheson starting from 2012.09.20 14:00
//    "E_D05SES" => 0, // DBS Group starting from 2012.09.20 14:00
//    "E_O39SES" => 0, // Oversea-Chinese Banking starting from 2012.09.20 15:00
//    "E_U11SES" => 0, // United Overseas Bank starting from 2012.09.20 14:00
//    "E_Z74SES" => 0, // Singapore Telecommunications starting from 2012.09.20 14:00
// stocks - Switzerland
//    "E_CSGN" => 0, // Cs Group starting from 2012.01.19 16:00
//    "E_NESN" => 0, // Nestle starting from 2012.01.19 16:00
//    "E_NOVNSWX" => 0, // Novartis starting from 2012.03.30 10:00
//    "E_UBSN" => 0, // UBS starting from 2012.01.19 16:00
// stocks - Austria
//    "E_ANDRVIE" => 0, // Andritz starting from 2012.09.20 14:00
//    "E_EBS" => 0, // Erste Group Bank starting from 2012.09.20 14:00
//    "E_OMVVIE" => 0, // OMV starting from 2012.09.20 14:00
//    "E_RBIVIE" => 0, // Raiffeisen Bank starting from 2012.09.20 14:00
//    "E_VOE" => 0, // Voestalpine starting from 2012.09.20 14:00
// stocks - Poland
//    "E_KGHWAR" => 0, // KGHM Polska Miedz starting from 2012.09.20 13:00
//    "E_PEOWAR" => 0, // Bank Pekao starting from 2012.09.20 13:00
//    "E_PKNWAR" => 0, // Polski Koncern Naftowy Orlen starting from 2012.09.20 13:00
//    "E_PKOBL1WAR" => 0, // Powszechna Kasa Oszczednosci Bank Polski starting from 2012.09.20 13:00
//    "E_PZUWAR" => 0, // Powszechny Zaklad Ubezpieczen starting from 2012.09.20 13:00
// stocks - US
//    "E_AAPL" => 0, // Apple starting from 2012.03.30 10:00
//    "E_AMZN" => 0, // Amazon starting from 2011.12.20 10:00
//    "E_AXP" => 0, // American Express starting from 2012.01.19 16:00
//    "E_BAC" => 0, // Bank Of America starting from 2011.12.20 10:00
//    "E_CL" => 0, // Colgate Palmolive starting from 2012.03.30 10:00
//    "E_CSCO" => 0, // Cisco starting from 2011.12.20 10:00
//    "E_DELL" => 0, // Dell starting from 2012.01.19 16:00
//    "E_DIS" => 0, // Disney Walt starting from 2011.12.20 10:00
//    "E_EBAY" => 0, // Ebay starting from 2012.01.19 16:00
//    "E_GE" => 0, // General Electric starting from 2011.12.20 10:00
//    "E_GM" => 0, // General Motors starting from 2011.12.20 10:00
//    "E_GOOGL" => 0, // Google starting from 2011.12.20 10:00
//    "E_HD" => 0, // Home Depot starting from 2012.01.19 16:00
//    "E_HPQ" => 0, // Hewlett Packard starting from 2011.12.20 10:00
//    "E_IBM" => 0, // IBM starting from 2011.12.20 10:00
//    "E_INTC" => 0, // Intel starting from 2011.12.20 10:00
//    "E_JNJ" => 0, // Johnson & Johnson starting from 2011.12.20 10:00
//    "E_JPM" => 0, // JPMorgan Chase starting from 2011.12.20 10:00
//    "E_KO" => 0, // Coca Cola starting from 2011.12.20 10:00
//    "E_MCD" => 0, // McDonalds starting from 2011.12.20 10:00
//    "E_MMM" => 0, // 3M starting from 2011.12.20 10:00
//    "E_MSFT" => 0, // Microsoft starting from 2011.12.20 10:00
//    "E_ORCL" => 0, // Oracle starting from 2011.12.20 10:00
//    "E_PG" => 0, // Procter & Gamble starting from 2011.12.20 10:00
//    "E_PM" => 0, // Philip Morris starting from 2012.03.30 11:00
//    "E_SBUX" => 0, // Starbucks starting from 2012.01.19 16:00
//    "E_T" => 0, // AT&T starting from 2011.12.20 11:00
//    "E_UPS" => 0, // UPS starting from 2012.03.30 11:00
//    "E_VIXX" => 0, // Cboe Volatility Index starting from 2012.01.19 16:00
//    "E_WMT" => 0, // Wal-Mart Stores starting from 2012.01.19 16:00
//    "E_XOM" => 0, // Exxon Mobil starting from 2011.12.20 10:00
//    "E_YHOO" => 0, // Yahoo starting from 2012.01.19 16:00

{"ZARJPY", 0} // starting from 
{"USDZAR", 0} // starting from 
{"USDTRY", 0} // starting from 
{"USDRUB", 0} // starting from 
{"USDBRL", 0} // starting from 
{"USDDKK", 0} // starting from 
{"USDHKD", 0} // starting from 
{"USDHUF", 0} // starting from 
{"USDMXN", 0} // starting from 
{"USDPLN", 0} // starting from 
{"SGDJPY", 0} // starting from 
{"MXNJPY", 0} // starting from 
{"NZDSGD", 0} // starting from 
{"HKDJPY", 0} // starting from 
{"EURUSD", 0} // starting from 
{"EURZAR", 0} // starting from 
{"EURTRY", 0} // starting from 
{"EURRUB", 0} // starting from 
{"EURPLN", 0} // starting from 
{"EURSGD", 0} // starting from 
{"EURMXN", 0} // starting from 
{"EURHUF", 0} // starting from 
{"EURHKD", 0} // starting from 
{"EURDKK", 0} // starting from 
{"CHFSGD", 0} // starting from 
{"CHFPLN", 0} // starting from 
{"CADHKD", 0} // starting from 
{"AUDSGD", 0} // starting from 
{"AUDNZD", 0} // starting from 
{"AUDUSD", 0} // starting from 
{"AUDJPY", 0} // starting from 
{"EURCHF", 0} // starting from 
{"EURGBP", 0} // starting from 
{"EURJPY", 0} // starting from 
{"GBPCHF", 0} // starting from 
{"GBPJPY", 0} // starting from 
{"GBPUSD", 0} // starting from 
{"NZDUSD", 0} // starting from 
{"USDCAD", 0} // starting from 
{"USDCHF", 0} // starting from 
{"USDJPY", 0} // starting from 
{"CADJPY", 0} // starting from 
{"EURAUD", 0} // starting from 
{"CHFJPY", 0} // starting from 
{"EURCAD", 0} // starting from 
{"EURNOK", 0} // starting from 
{"EURSEK", 0} // starting from 
{"USDNOK", 0} // starting from 
{"USDSEK", 0} // starting from 
{"USDSGD", 0} // starting from 
{"AUDCAD", 0} // starting from 
{"AUDCHF", 0} // starting from 
{"CADCHF", 0} // starting from 
{"EURNZD", 0} // starting from 
{"GBPAUD", 0} // starting from 
{"GBPCAD", 0} // starting from 
{"GBPNZD", 0} // starting from 
{"NZDCAD", 0} // starting from 
{"NZDCHF", 0} // starting from 
{"NZDJPY", 0} // starting from 
{"XAGUSD", 0} // starting from 
{"XAUUSD", 0} // starting from 



