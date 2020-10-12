#pragma once
// constructing maps
#include <map> //Needed to use the std::map class.
#include <string>

const std::map<std::string, int> symbols = {//Create a map.
// commodities - energy    
{"BRENTCMDUSD", 0},  // Brent starting from Thursday 1970-01-01 00:00:00
{"LIGHTCMDUSD", 0}, // Light starting from Thursday 1970-01-01 00:00:00
// commodities - metals
{"CUCMDUSD", 0}, // Copper starting from Thursday 1970-01-01 00:00:00
{"AUCMDUSD", 0}, // GOLD starting from Thursday 1970-01-01 00:00:00
{"E_SI", 0},  //SILVER starting from Thursday 1970-01-01 00:00:00
{"PDCMDUSD", 0}, // Palladium starting from Thursday 1970-01-01 00:00:00
{"PTCMDUSD", 0}, // Platinum starting from Thursday 1970-01-01 00:00:00

// indices - Australia
{"AUSIDXAUD", 0}, //S&P/ASX200 (AUSTRALIA) starting from Thursday 1970-01-01 00:00:00

// indices - BRAZIL
{"BRAIDXBRL", 0}, //BRAZIL INDEX starting from Thursday 1970-01-01 00:00:00

// indices - Europe 
{"NLDIDXEUR", 0}, // NETHERLANDS AEX 25 starting from Thursday 1970-01-01 00:00:00
{"ITAIDXEUR", 0}, // ITALY starting from Thursday 1970-01-01 00:00:00
{"ESPIDXEUR", 0}, // SPAIN IBEX starting from Thursday 1970-01-01 00:00:00
{"EUSIDXEUR", 0}, // Europe 50 starting from Thursday 1970-01-01 00:00:00
{"FRAIDXEUR", 0}, // France CAC 40 starting from Thursday 1970-01-01 00:00:00
{"GBRIDXGBP", 0}, // UK FTSE 100 starting from Thursday 1970-01-01 00:00:00
{"DEUIDXEUR", 0}, // Germany DAX 30 starting from Thursday 1970-01-01 00:00:00
{"CHEIDXCHF", 0}, // Switzerland SMI20 starting from Thursday 1970-01-01 00:00:00
// indices - Americas
{"USATECHIDXUSD", 0}, // US Tech 100 NASDAQ starting from Thursday 1970-01-01 00:00:00
{"USACOMIDXUSD", 0}, // US NASDAQ Composite starting from Thursday 1970-01-01 00:00:00
{"USA30IDXUSD", 0}, // US DOW JONES 30 starting from Thursday 1970-01-01 00:00:00
{"USA500IDXUSD", 0}, // US S&P 500 starting from Thursday 1970-01-01 00:00:00
{"USAMJRIDXUSD", 0}, // S&P 500 MAJOR starting from Thursday 1970-01-01 00:00:00
// indices - Asia / Pacific
{"HKGIDXHKD", 0}, // Hong Kong HANG SENG40 starting from Thursday 1970-01-01 00:00:00
//    "E_SCKorea" => 0, // Korea 200 starting from 2012.01.19 16:00
{"JPNIDXJPY", 0}, // Japan NIKKEI 225 starting from Thursday 1970-01-01 00:00:00

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

{"ZARJPY", 0}, // starting from Thursday 1970-01-01 00:00:00
{"USDZAR", 0}, // starting from Thursday 1970-01-01 00:00:00
{"USDTRY", 0}, // starting from Thursday 1970-01-01 00:00:00
{"USDRUB", 0}, // starting from Thursday 1970-01-01 00:00:00
{"USDBRL", 0}, // starting from Thursday 1970-01-01 00:00:00
{"USDDKK", 0}, // starting from Thursday 1970-01-01 00:00:00
{"USDHKD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"USDHUF", 0}, // starting from Thursday 1970-01-01 00:00:00
{"USDMXN", 0}, // starting from Thursday 1970-01-01 00:00:00
{"USDPLN", 0}, // starting from Thursday 1970-01-01 00:00:00
{"SGDJPY", 0}, // starting from Thursday 1970-01-01 00:00:00
{"MXNJPY", 0}, // starting from Thursday 1970-01-01 00:00:00
{"NZDSGD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"HKDJPY", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURUSD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURZAR", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURTRY", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURRUB", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURPLN", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURSGD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURMXN", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURHUF", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURHKD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURDKK", 0}, // starting from Thursday 1970-01-01 00:00:00
{"CHFSGD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"CHFPLN", 0}, // starting from Thursday 1970-01-01 00:00:00
{"CADHKD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"AUDSGD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"AUDNZD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"AUDUSD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"AUDJPY", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURCHF", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURGBP", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURJPY", 0}, // starting from Thursday 1970-01-01 00:00:00
{"GBPCHF", 0}, // starting from Thursday 1970-01-01 00:00:00
{"GBPJPY", 0}, // starting from Thursday 1970-01-01 00:00:00
{"GBPUSD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"NZDUSD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"USDCAD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"USDCHF", 0}, // starting from Thursday 1970-01-01 00:00:00
{"USDJPY", 0}, // starting from Thursday 1970-01-01 00:00:00
{"CADJPY", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURAUD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"CHFJPY", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURCAD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURNOK", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURSEK", 0}, // starting from Thursday 1970-01-01 00:00:00
{"USDNOK", 0}, // starting from Thursday 1970-01-01 00:00:00
{"USDSEK", 0}, // starting from Thursday 1970-01-01 00:00:00
{"USDSGD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"AUDCAD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"AUDCHF", 0}, // starting from Thursday 1970-01-01 00:00:00
{"CADCHF", 0}, // starting from Thursday 1970-01-01 00:00:00
{"EURNZD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"GBPAUD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"GBPCAD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"GBPNZD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"NZDCAD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"NZDCHF", 0}, // starting from Thursday 1970-01-01 00:00:00
{"NZDJPY", 0}, // starting from Thursday 1970-01-01 00:00:00
{"XAGUSD", 0}, // starting from Thursday 1970-01-01 00:00:00
{"XAUUSD", 0}, // starting from Thursday 1970-01-01 00:00:00
};