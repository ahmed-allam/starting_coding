#include "utils.h"


//28-9-2020 TAKE CARE CUCMDUSD E_SI PDCMDUSD PTCMDUSD ARE DISCONTINUED

//28-9-2020 making point value vectors
std::vector<std::string> point_value_xxx({
		"NESNCHCHF",
		"MSUSUSD",
		"MSFTUSUSD" ,
		"MTNLEUR"  ,
		"MUUSUSD"  ,
		"MUV2DEEUR"  ,
		"NBLUSUSD"  ,
		"NDASESEK"  ,
		"NEEUSUSD"  ,
		"NEMUSUSD"  ,
		"NES1VFIEUR"  ,
		"MRKUSUSD"  ,
		"NFLXUSUSD"  ,
		"NGGBGBX"  ,
		"NHYNONOK"  ,
		"NKEUSUSD"  ,
		"NLDIDXEUR"  ,
		"NOCUSUSD"  ,
		"NOVNCHCHF"  ,
		"MGMUSUSD"  ,
		"MAERSKBDKDKK"  ,
		"MARUSUSD"  ,
		"MATUSUSD"  ,
		"MCFREUR"  ,
		"MCDUSUSD"  ,
		"MCHPUSUSD"  ,
		"MCKUSUSD"  ,
		"MDLZUSUSD"  ,
		"METUSUSD"  ,
		"MROUSUSD"  ,
		"MHGNONOK"  ,
		"MKSGBGBX"  ,
		"MMMUSUSD"  ,
		"MNDIGBGBX"  ,
		"MOUSUSD"  ,
		"MONUSUSD"  ,
		"MPCUSUSD"  ,
		"MRKDEEUR"  ,
		"NOVOBDKDKK"  ,
		"PGRUSUSD"  ,
		"PAYXUSUSD"  ,
		"PBRUSUSD"  ,
		"PCARUSUSD"  ,
		"PCGUSUSD"  ,
		"PCLNUSUSD"  ,
		"PEPUSUSD"  ,
		"PFCGBGBX"  ,
		"PFEUSUSD"  ,
		"PGUSUSD"  ,
		"PAH3DEEUR"  ,
		"PHUSUSD"  ,
		"PHIANLEUR"  ,
		"PLNIDXPLN"  ,
		"PMUSUSD"  ,
		"PNCUSUSD"  ,
		"PNDORADKDKK"  ,
		"PPGUSUSD"  ,
		"PRUGBGBX"  ,
		"PRUUSUSD"  ,
		"OKEUSUSD"  ,
		"NRE1VFIEUR"  ,
		"NRGUSUSD"  ,
		"NSCUSUSD"  ,
		"NVDAUSUSD"  ,
		"NWLUSUSD"  ,
		"NXTGBGBX"  ,
		"NZDJPY"  ,
		"NZYMBDKDKK"  ,
		"OJUICECMDUSX"  ,
		"MUSUSD"  ,
		"OMCUSUSD"  ,
		"ORFREUR"  ,
		"ORAFREUR"  ,
		"ORCLUSUSD"  ,
		"ORKNONOK"  ,
		"ORLYUSUSD"  ,
		"OTE1VFIEUR"  ,
		"OUT1VFIEUR"  ,
		"OXYUSUSD"  ,
		"ISRGUSUSD"  ,
		"ILMNUSUSD"  ,
		"IMTGBGBX"  ,
		"INDIDXUSD"  ,
		"INGANLEUR"  ,
		"INTCUSUSD"  ,
		"INTUUSUSD"  ,
		"INVEBSESEK"  ,
		"IPGUSUSD"  ,
		"ISATGBGBX"  ,
		"IJRUSUSD"  ,
		"ITRKGBGBX"  ,
		"ITUBUSUSD"  ,
		"ITVGBGBX"  ,
		"ITWUSUSD"  ,
		"ITXESEUR"  ,
		"IVEUSUSD"  ,
		"IVWUSUSD"  ,
		"IWDUSUSD"  ,
		"IWFUSUSD"  ,
		"HUMUSUSD"  ,
		"HEIDEEUR"  ,
		"HEIANLEUR"  ,
		"HEN3DEEUR"  ,
		"HESUSUSD"  ,
		"HMBSESEK"  ,
		"HMSOGBGBX"  ,
		"HONUSUSD"  ,
		"HPQUSUSD"  ,
		"0005HKHKD"  ,
		"IWMUSUSD"  ,
		"IAGGBGBX"  ,
		"IBBUSUSD"  ,
		"IBEESEUR"  ,
		"IBMUSUSD"  ,
		"ICEUSUSD"  ,
		"IEFUSUSD"  ,
		"IFXDEEUR"  ,
		"IHGGBGBX"  ,
		"IJHUSUSD"  ,
		"LMTUSUSD"  ,
		"LANDGBGBX"  ,
		"LENUSUSD"  ,
		"LGENGBGBX"  ,
		"LHADEEUR"  ,
		"LHNCHCHF"  ,
		"LIFREUR"  ,
		"LINDEEUR"  ,
		"LLOYGBGBX"  ,
		"LLYUSUSD"  ,
		"LUSUSD"  ,
		"LONNCHCHF"  ,
		"LOWUSUSD"  ,
		"LRFREUR"  ,
		"LRCXUSUSD"  ,
		"LSEGBGBX"  ,
		"LUVUSUSD"  ,
		"LVSUSUSD"  ,
		"LXSDEEUR"  ,
		"PSAUSUSD"  ,
		"KEYUSUSD"  ,
		"IYRUSUSD"  ,
		"JCIUSUSD"  ,
		"JNJUSUSD"  ,
		"JNKUSUSD"  ,
		"JPMUSUSD"  ,
		"JWNUSUSD"  ,
		"KUSUSD"  ,
		"KBCBEEUR"  ,
		"KERFREUR"  ,
		"MAUSUSD"  ,
		"KGFGBGBX"  ,
		"KHCUSUSD"  ,
		"KMBUSUSD"  ,
		"KMIUSUSD"  ,
		"KNINCHCHF"  ,
		"KOUSUSD"  ,
		"KPNNLEUR"  ,
		"KRUSUSD"  ,
		"KSSUSUSD"  ,
		"USOUSUSD"  ,
		"ULTAUSUSD"  ,
		"UMIBEEUR"  ,
		"UNANLEUR"  ,
		"UNHUSUSD"  ,
		"UNPUSUSD"  ,
		"UPSUSUSD"  ,
		"USBUSUSD"  ,
		"USDHUF"  ,
		"USDJPY"  ,
		"UKGILTTRGBP"  ,
		"USSC2000IDXUSD"  ,
		"USTBONDTRUSD"  ,
		"UTXUSUSD"  ,
		"VUSUSD"  ,
		"VALEUSUSD"  ,
		"VEAUSUSD"  ,
		"VFCUSUSD"  ,
		"VGKUSUSD"  ,
		"VIABUSUSD"  ,
		"TSLAUSUSD"  ,
		"TJXUSUSD"  ,
		"TKADEEUR"  ,
		"TLS1VFIEUR"  ,
		"TLSNSESEK"  ,
		"TLTUSUSD"  ,
		"TMOUSUSD"  ,
		"TROWUSUSD"  ,
		"TRVUSUSD"  ,
		"TRYJPY"  ,
		"VIEFREUR"  ,
		"TSMUSUSD"  ,
		"TSNUSUSD"  ,
		"TUI1DEEUR"  ,
		"TWTRUSUSD"  ,
		"TXNUSUSD"  ,
		"UBSGCHCHF"  ,
		"UCBBEEUR"  ,
		"UGFREUR"  ,
		"UHRCHCHF"  ,
		"XLPUSUSD"  ,
		"WYNNUSUSD"  ,
		"XUSUSD"  ,
		"XAGUSD"  ,
		"XAUUSD"  ,
		"XLEUSUSD"  ,
		"XLFUSUSD"  ,
		"XLIUSUSD"  ,
		"XLKUSUSD"  ,
		"XLNXUSUSD"  ,
		"WMTUSUSD"  ,
		"XLUUSUSD"  ,
		"XLVUSUSD"  ,
		"XLYUSUSD"  ,
		"XOMUSUSD"  ,
		"XOPUSUSD"  ,
		"YUMUSUSD"  ,
		"ZARJPY"  ,
		"ZBHUSUSD"  ,
		"ZURNCHCHF"  ,
		"VPKNLEUR"  ,
		"VIVFREUR"  ,
		"VKFREUR"  ,
		"VLOUSUSD"  ,
		"VMCUSUSD"  ,
		"VNADEEUR"  ,
		"VNQUSUSD"  ,
		"VOEATEUR"  ,
		"VOLVBSESEK"  ,
		"VOW3DEEUR"  ,
		"TIFUSUSD"  ,
		"VRTXUSUSD"  ,
		"VWSDKDKK"  ,
		"VXXUSUSD"  ,
		"VZUSUSD"  ,
		"WBAUSUSD"  ,
		"WDCUSUSD"  ,
		"WFCUSUSD"  ,
		"WHRUSUSD"  ,
		"WKLNLEUR"  ,
		"SANESEUR"  ,
		"RHTUSUSD"  ,
		"RIFREUR"  ,
		"RNOFREUR"  ,
		"ROGCHCHF"  ,
		"ROSTUSUSD"  ,
		"RRCUSUSD"  ,
		"RTNUSUSD"  ,
		"RWEDEEUR"  ,
		"SAFFREUR"  ,
		"RFUSUSD"  ,
		"SANFREUR"  ,
		"SANDSESEK"  ,
		"SAPDEEUR"  ,
		"SBUXUSUSD"  ,
		"SCABSESEK"  ,
		"SCHWUSUSD"  ,
		"SCMNCHCHF"  ,
		"SDFDEEUR"  ,
		"SEBASESEK"  ,
		"QQQUSUSD"  ,
		"PSMDEEUR"  ,
		"PSNGBGBX"  ,
		"PSONGBGBX"  ,
		"PSXUSUSD"  ,
		"PUBFREUR"  ,
		"PXUSUSD"  ,
		"PXDUSUSD"  ,
		"PYPLUSUSD"  ,
		"QCOMUSUSD"  ,
		"SECUBSESEK"  ,
		"RANDNLEUR"  ,
		"RBGBGBX"  ,
		"RBIATEUR"  ,
		"RDSANLEUR"  ,
		"REEESEUR"  ,
		"REGNUSUSD"  ,
		"RELGBGBX"  ,
		"RENNLEUR"  ,
		"REPESEUR"  ,
		"SYKUSUSD"  ,
		"STIUSUSD"  ,
		"STLNONOK"  ,
		"STTUSUSD"  ,
		"STZUSUSD"  ,
		"SUFREUR"  ,
		"SUGARCMDUSD"  ,
		"SWEDASESEK"  ,
		"SWKUSUSD"  ,
		"SWMASESEK"  ,
		"STERVFIEUR"  ,
		"SYMCUSUSD"  ,
		"SYYUSUSD"  ,
		"TUSUSD"  ,
		"TAPUSUSD"  ,
		"TEFESEUR"  ,
		"TELNONOK"  ,
		"TEL2BSESEK"  ,
		"TEVAUSUSD"  ,
		"TGTUSUSD"  ,
		"SLHNCHCHF"  ,
		"SGDIDXSGD"  ,
		"SGDJPY"  ,
		"SGOFREUR"  ,
		"SGSNCHCHF"  ,
		"SHWUSUSD"  ,
		"SIEDEEUR"  ,
		"SJMUSUSD"  ,
		"SKABSESEK"  ,
		"SKFBSESEK"  ,
		"HSBAGBGBX"  ,
		"SLVUSUSD"  ,
		"SNAPUSUSD"  ,
		"SOUSUSD"  ,
		"SOLBBEEUR"  ,
		"SOONCHCHF"  ,
		"SOYBEANCMDUSX"  ,
		"SPGUSUSD"  ,
		"SPYUSUSD"  ,
		"SRENCHCHF"  ,
		"BKUSUSD"  ,
		"BBDUSUSD"  ,
		"BBTUSUSD"  ,
		"BBVAESEUR"  ,
		"BBYUSUSD"  ,
		"BDXUSUSD"  ,
		"BEIDEEUR"  ,
		"BELGBEEUR"  ,
		"BIDUUSUSD"  ,
		"BIIBUSUSD"  ,
		"BAYNDEEUR"  ,
		"BLNDGBGBX"  ,
		"BLTGBGBX"  ,
		"BMWDEEUR"  ,
		"BMYUSUSD"  ,
		"BNFREUR"  ,
		"BNPFREUR"  ,
		"BNZLGBGBX"  ,
		"BOSSDEEUR"  ,
		"BPGBGBX"  ,
		"AZOUSUSD"  ,
		"ATCOASESEK"  ,
		"ATVIUSUSD"  ,
		"AUDJPY"  ,
		"AVGBGBX"  ,
		"AVBUSUSD"  ,
		"AVGOUSUSD"  ,
		"AXPUSUSD"  ,
		"AZNGBGBX"  ,
		"AZNUSUSD"  ,
		"BPUSUSD"  ,
		"BAGBGBX"  ,
		"BAUSUSD"  ,
		"BABGBGBX"  ,
		"BABAUSUSD"  ,
		"BACUSUSD"  ,
		"BAERCHCHF"  ,
		"BARCGBGBX"  ,
		"BASDEEUR"  ,
		"BATSGBGBX"  ,
		"CMIUSUSD"  ,
		"CFUSUSD"  ,
		"CHFJPY"  ,
		"CHIIDXUSD"  ,
		"CIUSUSD"  ,
		"CLUSUSD"  ,
		"CLNCHCHF"  ,
		"CMCSAUSUSD"  ,
		"HDUSUSD"  ,
		"CMGUSUSD"  ,
		"CERNUSUSD"  ,
		"CNAGBGBX"  ,
		"COCOACMDUSD"  ,
		"COFUSUSD"  ,
		"COFFEECMDUSX"  ,
		"COLUSUSD"  ,
		"COLOBDKDKK"  ,
		"CONDEEUR"  ,
		"COPUSUSD"  ,
		"COSTUSUSD"  ,
		"CAGUSUSD"  ,
		"BRBYGBGBX"  ,
		"BRKBUSUSD"  ,
		"BSXUSUSD"  ,
		"BTGBGBX"  ,
		"BUNDTREUR"  ,
		"CUSUSD"  ,
		"CAFREUR"  ,
		"CABKESEUR"  ,
		"CADJPY"  ,
		"ASMLNLEUR"  ,
		"CAHUSUSD"  ,
		"CAPFREUR"  ,
		"CARLBDKDKK"  ,
		"CATUSUSD"  ,
		"CBKDEEUR"  ,
		"CBSUSUSD"  ,
		"CCLGBGBX"  ,
		"CELGUSUSD"  ,
		"AALGBGBX"  ,
		"2318HKHKD"  ,
		"2388HKHKD"  ,
		"2628HKHKD"  ,
		"3333HKHKD"  ,
		"3968HKHKD"  ,
		"3988HKHKD"  ,
		"AUSUSD"  ,
		"AAUSUSD"  ,
		"AABAUSUSD"  ,
		"2018HKHKD"  ,
		"AALUSUSD"  ,
		"AAPLUSUSD"  ,
		"ABBNCHCHF"  ,
		"ABCUSUSD"  ,
		"ABEVUSUSD"  ,
		"ABFGBGBX"  ,
		"ABIBEEUR"  ,
		"ABTUSUSD"  ,
		"ACFREUR"  ,
		"0941HKHKD"  ,
		"0027HKHKD"  ,
		"0175HKHKD"  ,
		"0291HKHKD"  ,
		"0386HKHKD"  ,
		"0388HKHKD"  ,
		"0700HKHKD"  ,
		"0857HKHKD"  ,
		"0883HKHKD"  ,
		"0939HKHKD"  ,
		"ACAFREUR"  ,
		"0998HKHKD"  ,
		"1093HKHKD"  ,
		"1177HKHKD"  ,
		"1288HKHKD"  ,
		"1299HKHKD"  ,
		"1398HKHKD"  ,
		"1918HKHKD"  ,
		"2007HKHKD"  ,
		"AMGNUSUSD"  ,
		"AIRFREUR"  ,
		"AKZANLEUR"  ,
		"ALFASESEK"  ,
		"ALLUSUSD"  ,
		"ALOFREUR"  ,
		"ALVDEEUR"  ,
		"ALXNUSUSD"  ,
		"AMATUSUSD"  ,
		"AMDUSUSD"  ,
		"AIGUSUSD"  ,
		"AMPUSUSD"  ,
		"AMSESEUR"  ,
		"AMTUSUSD"  ,
		"AMZNUSUSD"  ,
		"ANTMUSUSD"  ,
		"ANTOGBGBX"  ,
		"APAUSUSD"  ,
		"APCUSUSD"  ,
		"APDUSUSD"  ,
		"AENAESEUR"  ,
		"ACSESEUR"  ,
		"ACXESEUR"  ,
		"ADBEUSUSD"  ,
		"ADENCHCHF"  ,
		"ADIUSUSD"  ,
		"ADMGBGBX"  ,
		"ADPUSUSD"  ,
		"ADSDEEUR"  ,
		"ADSKUSUSD"  ,
		"CMEUSUSD"  ,
		"AETUSUSD"  ,
		"AFFREUR"  ,
		"AGKGBGBX"  ,
		"AGNNLEUR"  ,
		"AGSBEEUR"  ,
		"AHNLEUR"  ,
		"AHTGBGBX"  ,
		"AIFREUR"  ,
		"EXPEUSUSD"  ,
		"ESRXUSUSD"  ,
		"EURHUF"  ,
		"EURJPY"  ,
		"EWHUSUSD"  ,
		"EWJUSUSD"  ,
		"EWWUSUSD"  ,
		"EWZUSUSD"  ,
		"EXCUSUSD"  ,
		"COTTONCMDUSX"  ,
		"EXPNGBGBX"  ,
		"EZJGBGBX"  ,
		"EZUUSUSD"  ,
		"FUSUSD"  ,
		"FBUSUSD"  ,
		"FCXUSUSD"  ,
		"FDXUSUSD"  ,
		"FEUSUSD"  ,
		"EMBUSUSD"  ,
		"EEMUSUSD"  ,
		"EFAUSUSD"  ,
		"EFXUSUSD"  ,
		"EIXUSUSD"  ,
		"ELUSUSD"  ,
		"ELEESEUR"  ,
		"ELI1VFIEUR"  ,
		"ELUXBSESEK"  ,
		"FERESEUR"  ,
		"EMRUSUSD"  ,
		"ENFREUR"  ,
		"ENGESEUR"  ,
		"ENGIFREUR"  ,
		"EOANDEEUR"  ,
		"EOGUSUSD"  ,
		"EQTUSUSD"  ,
		"GOOGUSUSD"  ,
		"GILDUSUSD"  ,
		"GISUSUSD"  ,
		"GIVNCHCHF"  ,
		"GLDUSUSD"  ,
		"GLEFREUR"  ,
		"GLENGBGBX"  ,
		"GLWUSUSD"  ,
		"GMUSUSD"  ,
		"GFSGBGBX"  ,
		"GOOGLUSUSD"  ,
		"GPSUSUSD"  ,
		"GSUSUSD"  ,
		"GSKGBGBX"  ,
		"GWWUSUSD"  ,
		"HALUSUSD"  ,
		"HCNUSUSD"  ,
		"HCPUSUSD"  ,
		"GALPPTEUR"  ,
		"FITBUSUSD"  ,
		"FMEDEEUR"  ,
		"FOXAUSUSD"  ,
		"FPFREUR"  ,
		"FRFREUR"  ,
		"FREDEEUR"  ,
		"FRESGBGBX"  ,
		"FXIUSUSD"  ,
		"ERICBSESEK"  ,
		"GAMESEUR"  ,
		"GASESEUR"  ,
		"GBPJPY"  ,
		"GDXUSUSD"  ,
		"GDXJUSUSD"  ,
		"GEUSUSD"  ,
		"GETIBSESEK"  ,
		"DIESELCMDUSD"  ,
		"DBKDEEUR"  ,
		"DEUSUSD"  ,
		"DFSUSUSD"  ,
		"DGFREUR"  ,
		"DGUSUSD"  ,
		"DGEGBGBX"  ,
		"DHIUSUSD"  ,
		"DHRUSUSD"  ,
		"DIAESEUR"  ,
		"DIAUSUSD"  ,
		"DB1DEEUR"  ,
		"DISUSUSD"  ,
		"DLTRUSUSD"  ,
		"DNBNONOK"  ,
		"DOLLARIDXUSD"  ,
		"DPWDEEUR"  ,
		"DSMNLEUR"  ,
		"DTEDEEUR"  ,
		"DUK+EUR"  ,
		"DUKUSUSD"  ,
		"CSXUSUSD"  ,
		"CPGGBGBX"  ,
		"CPIGBGBX"  ,
		"CRDAGBGBX"  ,
		"CRHGBGBX"  ,
		"CRMUSUSD"  ,
		"CSFREUR"  ,
		"CSUSUSD"  ,
		"CSCOUSUSD"  ,
		"CSGNCHCHF"  ,
		"EDFFREUR"  ,
		"CTLUSUSD"  ,
		"CTSHUSUSD"  ,
		"CTXSUSUSD"  ,
		"CVSUSUSD"  ,
		"CVXUSUSD"  ,
		"DUSUSD"  ,
		"DAIDEEUR"  ,
		"DALUSUSD"  ,
		"DANSKEDKDKK"  ,
		"LIGHTCMDUSD"  ,
		"DVYUSUSD"  ,
		"BRENTCMDUSD"  ,
		"FRAIDXEUR"  ,
		"USA30IDXUSD"  ,
		"DEUIDXEUR"  ,
		"EUSIDXEUR"  ,
		"GBRIDXGBP"  ,
		"HKGIDXHKD"  ,
		"ESPIDXEUR"  ,
		"DVNUSUSD"  ,
		"JPNIDXJPY"  ,
		"USATECHIDXUSD"  ,
		"USA500IDXUSD"  ,
		"CHEIDXCHF"  ,
		"AUSIDXAUD"  ,
		"EAUSUSD"  ,
		"EBAYUSUSD"  ,
		"EBSATEUR"  ,
		"EDPPTEUR"  ,
		"DVAUSUSD"
});

std::vector<std::string> point_value_xxxx({
		"COPPERCMDUSD"  ,
		"USDRON"  ,
		"USDTHB"  ,
		"USDCZK"  ,
		"GASCMDUSD"  ,
		"EURCZK"
});

std::vector<std::string> point_value_xxxxx({
		"GBPUSD"  ,
		"USDRUB"  ,
		"USDPLN"  ,
		"USDNOK"  ,
		"CHFSGD"  ,
		"USDMXN"  ,
		"EURSGD"  ,
		"AUDCAD"  ,
		"AUDCHF"  ,
		"USDILS"  ,
		"AUDNZD"  ,
		"AUDSGD"  ,
		"AUDUSD"  ,
		"EURTRY"  ,
		"USDHKD"  ,
		"USDDKK"  ,
		"USDCNH"  ,
		"USDCHF"  ,
		"USDCAD"  ,
		"HKDJPY"  ,
		"EURUSD"  ,
		"NZDCAD"  ,
		"USDZAR"  ,
		"EURSEK"  ,
		"EURRUB"  ,
		"EURPLN"  ,
		"EURNZD"  ,
		"EURNOK"  ,
		"USDSGD"  ,
		"EURHKD"  ,
		"EURGBP"  ,
		"CADCHF"  ,
		"CADHKD"  ,
		"GBPNZD"  ,
		"NZDCHF"  ,
		"EURDKK"  ,
		"NZDUSD"  ,
		"EURCHF"  ,
		"EURCAD"  ,
		"EURAUD"  ,
		"USDSEK"  ,
		"GBPAUD"  ,
		"GBPCAD"  ,
		"GBPCHF"  ,
		"USDTRY"

});

namespace symbols_enum_to_str_map_x
{
	//6-8-2020 i will make symbols_enum_to_str_map >>>extern and move definition to .cpp
	std::map<symbols_enum, std::string> symbols_enum_to_str_map = boost::assign::map_list_of
		(symbols_enum::GBPJPY, "GBPJPY")
		/*
		(symbols_enum::BRENTCMDUSD, "BRENTCMDUSD")
		(symbols_enum::LIGHTCMDUSD, "LIGHTCMDUSD")
		(symbols_enum::CUCMDUSD, "CUCMDUSD")
		(symbols_enum::AUCMDUSD, "AUCMDUSD")

		(symbols_enum::E_SI, "E_SI")
		(symbols_enum::PDCMDUSD, "PDCMDUSD")
		(symbols_enum::PTCMDUSD, "PTCMDUSD")
		(symbols_enum::AUSIDXAUD, "AUSIDXAUD")
		(symbols_enum::BRAIDXBRL, "BRAIDXBRL")
		(symbols_enum::NLDIDXEUR, "NLDIDXEUR")
		(symbols_enum::ITAIDXEUR, "ITAIDXEUR")
		(symbols_enum::ESPIDXEUR, "ESPIDXEUR")
		(symbols_enum::EUSIDXEUR, "EUSIDXEUR")
		(symbols_enum::FRAIDXEUR, "FRAIDXEUR")
		(symbols_enum::GBRIDXGBP, "GBRIDXGBP")
		(symbols_enum::DEUIDXEUR, "DEUIDXEUR")
		(symbols_enum::CHEIDXCHF, "CHEIDXCHF")
		(symbols_enum::USATECHIDXUSD, "USATECHIDXUSD")
		(symbols_enum::USACOMIDXUSD, "USACOMIDXUSD")
		(symbols_enum::USA30IDXUSD, "USA30IDXUSD")
		(symbols_enum::USA500IDXUSD, "USA500IDXUSD")
		(symbols_enum::USAMJRIDXUSD, "USAMJRIDXUSD")
		(symbols_enum::HKGIDXHKD, "HKGIDXHKD")
		(symbols_enum::JPNIDXJPY, "JPNIDXJPY")

		(symbols_enum::ZARJPY, "ZARJPY")
		(symbols_enum::USDZAR, "USDZAR")
		(symbols_enum::USDTRY, "USDTRY")
		(symbols_enum::USDRUB, "USDRUB")
		(symbols_enum::USDBRL, "USDBRL")
		(symbols_enum::USDDKK, "USDDKK")
		(symbols_enum::USDHKD, "USDHKD")
		(symbols_enum::USDHUF, "USDHUF")
		(symbols_enum::USDMXN, "USDMXN")
		(symbols_enum::USDPLN, "USDPLN")
		(symbols_enum::SGDJPY, "SGDJPY")
		(symbols_enum::MXNJPY, "MXNJPY")
		(symbols_enum::NZDSGD, "NZDSGD")
		(symbols_enum::HKDJPY, "HKDJPY")
		(symbols_enum::EURUSD, "EURUSD")
		(symbols_enum::EURZAR, "EURZAR")
		(symbols_enum::EURTRY, "EURTRY")
		(symbols_enum::EURRUB, "EURRUB")
		(symbols_enum::EURPLN, "EURPLN")
		(symbols_enum::EURSGD, "EURSGD")
		(symbols_enum::EURMXN, "EURMXN")
		(symbols_enum::EURHUF, "EURHUF")
		(symbols_enum::EURHKD, "EURHKD")
		(symbols_enum::EURDKK, "EURDKK")
		(symbols_enum::CHFSGD, "CHFSGD")
		(symbols_enum::CHFPLN, "CHFPLN")
		(symbols_enum::CADHKD, "CADHKD")
		(symbols_enum::AUDSGD, "AUDSGD")
		(symbols_enum::AUDNZD, "AUDNZD")
		(symbols_enum::AUDUSD, "AUDUSD")
		(symbols_enum::AUDJPY, "AUDJPY")
		(symbols_enum::EURCHF, "EURCHF")
		(symbols_enum::EURGBP, "EURGBP")
		(symbols_enum::EURJPY, "EURJPY")
		(symbols_enum::GBPCHF, "GBPCHF")
		(symbols_enum::GBPUSD, "GBPUSD")
		(symbols_enum::NZDUSD, "NZDUSD")
		(symbols_enum::USDCAD, "USDCAD")
		(symbols_enum::USDCHF, "USDCHF")
		(symbols_enum::USDJPY, "USDJPY")
		(symbols_enum::CADJPY, "CADJPY")
		(symbols_enum::EURAUD, "EURAUD")
		(symbols_enum::CHFJPY, "CHFJPY")
		(symbols_enum::EURCAD, "EURCAD")
		(symbols_enum::EURNOK, "EURNOK")
		(symbols_enum::EURSEK, "EURSEK")
		(symbols_enum::USDNOK, "USDNOK")
		(symbols_enum::USDSEK, "USDSEK")
		(symbols_enum::USDSGD, "USDSGD")
		(symbols_enum::AUDCAD, "AUDCAD")
		(symbols_enum::AUDCHF, "AUDCHF")
		(symbols_enum::CADCHF, "CADCHF")
		(symbols_enum::EURNZD, "EURNZD")
		(symbols_enum::GBPAUD, "GBPAUD")
		(symbols_enum::GBPCAD, "GBPCAD")
		(symbols_enum::GBPNZD, "GBPNZD")
		(symbols_enum::NZDCAD, "NZDCAD")
		(symbols_enum::NZDCHF, "NZDCHF")
		(symbols_enum::NZDJPY, "NZDJPY")
		(symbols_enum::XAGUSD, "XAGUSD")
		(symbols_enum::XAUUSD, "XAUUSD")
		*/
		;
}

std::ostream& operator<<(std::ostream& os, const std::vector<symbols_enum>& symbols_vector_enum_to_string)
{
	std::map<symbols_enum, std::string> xmap2 = boost::assign::map_list_of
	(symbols_enum::BRENTCMDUSD, "BRENTCMDUSD")
		(symbols_enum::LIGHTCMDUSD, "LIGHTCMDUSD")
		(symbols_enum::CUCMDUSD, "CUCMDUSD")
		(symbols_enum::AUCMDUSD, "AUCMDUSD")
		(symbols_enum::E_SI, "E_SI")
		(symbols_enum::PDCMDUSD, "PDCMDUSD")
		(symbols_enum::PTCMDUSD, "PTCMDUSD")
		(symbols_enum::AUSIDXAUD, "AUSIDXAUD")
		(symbols_enum::BRAIDXBRL, "BRAIDXBRL")
		(symbols_enum::NLDIDXEUR, "NLDIDXEUR")
		(symbols_enum::ITAIDXEUR, "ITAIDXEUR")
		(symbols_enum::ESPIDXEUR, "ESPIDXEUR")
		(symbols_enum::EUSIDXEUR, "EUSIDXEUR")
		(symbols_enum::FRAIDXEUR, "FRAIDXEUR")
		(symbols_enum::GBRIDXGBP, "GBRIDXGBP")
		(symbols_enum::DEUIDXEUR, "DEUIDXEUR")
		(symbols_enum::CHEIDXCHF, "CHEIDXCHF")
		(symbols_enum::USATECHIDXUSD, "USATECHIDXUSD")
		(symbols_enum::USACOMIDXUSD, "USACOMIDXUSD")
		(symbols_enum::USA30IDXUSD, "USA30IDXUSD")
		(symbols_enum::USA500IDXUSD, "USA500IDXUSD")
		(symbols_enum::USAMJRIDXUSD, "USAMJRIDXUSD")
		(symbols_enum::HKGIDXHKD, "HKGIDXHKD")
		(symbols_enum::JPNIDXJPY, "JPNIDXJPY")
		(symbols_enum::ZARJPY, "ZARJPY")
		(symbols_enum::USDZAR, "USDZAR")
		(symbols_enum::USDTRY, "USDTRY")
		(symbols_enum::USDRUB, "USDRUB")
		(symbols_enum::USDBRL, "USDBRL")
		(symbols_enum::USDDKK, "USDDKK")
		(symbols_enum::USDHKD, "USDHKD")
		(symbols_enum::USDHUF, "USDHUF")
		(symbols_enum::USDMXN, "USDMXN")
		(symbols_enum::USDPLN, "USDPLN")
		(symbols_enum::SGDJPY, "SGDJPY")
		(symbols_enum::MXNJPY, "MXNJPY")
		(symbols_enum::NZDSGD, "NZDSGD")
		(symbols_enum::HKDJPY, "HKDJPY")
		(symbols_enum::EURUSD, "EURUSD")
		(symbols_enum::EURZAR, "EURZAR")
		(symbols_enum::EURTRY, "EURTRY")
		(symbols_enum::EURRUB, "EURRUB")
		(symbols_enum::EURPLN, "EURPLN")
		(symbols_enum::EURSGD, "EURSGD")
		(symbols_enum::EURMXN, "EURMXN")
		(symbols_enum::EURHUF, "EURHUF")
		(symbols_enum::EURHKD, "EURHKD")
		(symbols_enum::EURDKK, "EURDKK")
		(symbols_enum::CHFSGD, "CHFSGD")
		(symbols_enum::CHFPLN, "CHFPLN")
		(symbols_enum::CADHKD, "CADHKD")
		(symbols_enum::AUDSGD, "AUDSGD")
		(symbols_enum::AUDNZD, "AUDNZD")
		(symbols_enum::AUDUSD, "AUDUSD")
		(symbols_enum::AUDJPY, "AUDJPY")
		(symbols_enum::EURCHF, "EURCHF")
		(symbols_enum::EURGBP, "EURGBP")
		(symbols_enum::EURJPY, "EURJPY")
		(symbols_enum::GBPCHF, "GBPCHF")
		(symbols_enum::GBPJPY, "GBPJPY")
		(symbols_enum::GBPUSD, "GBPUSD")
		(symbols_enum::NZDUSD, "NZDUSD")
		(symbols_enum::USDCAD, "USDCAD")
		(symbols_enum::USDCHF, "USDCHF")
		(symbols_enum::USDJPY, "USDJPY")
		(symbols_enum::CADJPY, "CADJPY")
		(symbols_enum::EURAUD, "EURAUD")
		(symbols_enum::CHFJPY, "CHFJPY")
		(symbols_enum::EURCAD, "EURCAD")
		(symbols_enum::EURNOK, "EURNOK")
		(symbols_enum::EURSEK, "EURSEK")
		(symbols_enum::USDNOK, "USDNOK")
		(symbols_enum::USDSEK, "USDSEK")
		(symbols_enum::USDSGD, "USDSGD")
		(symbols_enum::AUDCAD, "AUDCAD")
		(symbols_enum::AUDCHF, "AUDCHF")
		(symbols_enum::CADCHF, "CADCHF")
		(symbols_enum::EURNZD, "EURNZD")
		(symbols_enum::GBPAUD, "GBPAUD")
		(symbols_enum::GBPCAD, "GBPCAD")
		(symbols_enum::GBPNZD, "GBPNZD")
		(symbols_enum::NZDCAD, "NZDCAD")
		(symbols_enum::NZDCHF, "NZDCHF")
		(symbols_enum::NZDJPY, "NZDJPY")
		(symbols_enum::XAGUSD, "XAGUSD")
		(symbols_enum::XAUUSD, "XAUUSD");

	//string symbols_enum_to_string_string_value = (xmap2.find(symbols_vector_enum_to_string)->second);
	//os << symbols_enum_to_string_string_value;

	for (std::vector<symbols_enum>::const_iterator ii = symbols_vector_enum_to_string.begin(); ii != symbols_vector_enum_to_string.end(); ++ii)
	{
		std::string symbols_enum_to_string_string_value = (xmap2.find(*ii)->second);
		os << symbols_enum_to_string_string_value;
	}

	return os;
}

std::ostringstream& operator<<(std::ostringstream& os, const symbols_enum& symbol_enum_to_string)
{
	std::map<symbols_enum, std::string> xmap2 = boost::assign::map_list_of
	(symbols_enum::BRENTCMDUSD, "BRENTCMDUSD")
		(symbols_enum::LIGHTCMDUSD, "LIGHTCMDUSD")
		(symbols_enum::CUCMDUSD, "CUCMDUSD")
		(symbols_enum::AUCMDUSD, "AUCMDUSD")
		(symbols_enum::E_SI, "E_SI")
		(symbols_enum::PDCMDUSD, "PDCMDUSD")
		(symbols_enum::PTCMDUSD, "PTCMDUSD")
		(symbols_enum::AUSIDXAUD, "AUSIDXAUD")
		(symbols_enum::BRAIDXBRL, "BRAIDXBRL")
		(symbols_enum::NLDIDXEUR, "NLDIDXEUR")
		(symbols_enum::ITAIDXEUR, "ITAIDXEUR")
		(symbols_enum::ESPIDXEUR, "ESPIDXEUR")
		(symbols_enum::EUSIDXEUR, "EUSIDXEUR")
		(symbols_enum::FRAIDXEUR, "FRAIDXEUR")
		(symbols_enum::GBRIDXGBP, "GBRIDXGBP")
		(symbols_enum::DEUIDXEUR, "DEUIDXEUR")
		(symbols_enum::CHEIDXCHF, "CHEIDXCHF")
		(symbols_enum::USATECHIDXUSD, "USATECHIDXUSD")
		(symbols_enum::USACOMIDXUSD, "USACOMIDXUSD")
		(symbols_enum::USA30IDXUSD, "USA30IDXUSD")
		(symbols_enum::USA500IDXUSD, "USA500IDXUSD")
		(symbols_enum::USAMJRIDXUSD, "USAMJRIDXUSD")
		(symbols_enum::HKGIDXHKD, "HKGIDXHKD")
		(symbols_enum::JPNIDXJPY, "JPNIDXJPY")
		(symbols_enum::ZARJPY, "ZARJPY")
		(symbols_enum::USDZAR, "USDZAR")
		(symbols_enum::USDTRY, "USDTRY")
		(symbols_enum::USDRUB, "USDRUB")
		(symbols_enum::USDBRL, "USDBRL")
		(symbols_enum::USDDKK, "USDDKK")
		(symbols_enum::USDHKD, "USDHKD")
		(symbols_enum::USDHUF, "USDHUF")
		(symbols_enum::USDMXN, "USDMXN")
		(symbols_enum::USDPLN, "USDPLN")
		(symbols_enum::SGDJPY, "SGDJPY")
		(symbols_enum::MXNJPY, "MXNJPY")
		(symbols_enum::NZDSGD, "NZDSGD")
		(symbols_enum::HKDJPY, "HKDJPY")
		(symbols_enum::EURUSD, "EURUSD")
		(symbols_enum::EURZAR, "EURZAR")
		(symbols_enum::EURTRY, "EURTRY")
		(symbols_enum::EURRUB, "EURRUB")
		(symbols_enum::EURPLN, "EURPLN")
		(symbols_enum::EURSGD, "EURSGD")
		(symbols_enum::EURMXN, "EURMXN")
		(symbols_enum::EURHUF, "EURHUF")
		(symbols_enum::EURHKD, "EURHKD")
		(symbols_enum::EURDKK, "EURDKK")
		(symbols_enum::CHFSGD, "CHFSGD")
		(symbols_enum::CHFPLN, "CHFPLN")
		(symbols_enum::CADHKD, "CADHKD")
		(symbols_enum::AUDSGD, "AUDSGD")
		(symbols_enum::AUDNZD, "AUDNZD")
		(symbols_enum::AUDUSD, "AUDUSD")
		(symbols_enum::AUDJPY, "AUDJPY")
		(symbols_enum::EURCHF, "EURCHF")
		(symbols_enum::EURGBP, "EURGBP")
		(symbols_enum::EURJPY, "EURJPY")
		(symbols_enum::GBPCHF, "GBPCHF")
		(symbols_enum::GBPJPY, "GBPJPY")
		(symbols_enum::GBPUSD, "GBPUSD")
		(symbols_enum::NZDUSD, "NZDUSD")
		(symbols_enum::USDCAD, "USDCAD")
		(symbols_enum::USDCHF, "USDCHF")
		(symbols_enum::USDJPY, "USDJPY")
		(symbols_enum::CADJPY, "CADJPY")
		(symbols_enum::EURAUD, "EURAUD")
		(symbols_enum::CHFJPY, "CHFJPY")
		(symbols_enum::EURCAD, "EURCAD")
		(symbols_enum::EURNOK, "EURNOK")
		(symbols_enum::EURSEK, "EURSEK")
		(symbols_enum::USDNOK, "USDNOK")
		(symbols_enum::USDSEK, "USDSEK")
		(symbols_enum::USDSGD, "USDSGD")
		(symbols_enum::AUDCAD, "AUDCAD")
		(symbols_enum::AUDCHF, "AUDCHF")
		(symbols_enum::CADCHF, "CADCHF")
		(symbols_enum::EURNZD, "EURNZD")
		(symbols_enum::GBPAUD, "GBPAUD")
		(symbols_enum::GBPCAD, "GBPCAD")
		(symbols_enum::GBPNZD, "GBPNZD")
		(symbols_enum::NZDCAD, "NZDCAD")
		(symbols_enum::NZDCHF, "NZDCHF")
		(symbols_enum::NZDJPY, "NZDJPY")
		(symbols_enum::XAGUSD, "XAGUSD")
		(symbols_enum::XAUUSD, "XAUUSD");

	//string symbols_enum_to_string_string_value = (xmap2.find(symbols_vector_enum_to_string)->second);
	//os << symbols_enum_to_string_string_value;


	std::string symbols_enum_to_string_string_value = (xmap2.find(symbol_enum_to_string)->second);
	os << symbols_enum_to_string_string_value;


	return os;
}



void validate(boost::any& v,
	std::vector<std::string> const& values,
	symbols_enum* /* target_type */,
	int)
{
	// Make sure no previous assignment to 'v' was made.
	validators::check_first_occurrence(v);

	// Extract the first string from 'values'. If there is more than
	// one string, it's an error, and exception will be thrown.
	std::string const& s = validators::get_single_string(values);

	const std::string& s_capitalized = boost::to_upper_copy(s);

	if (s_capitalized == "BRENTCMDUSD") {
		v = boost::any(symbols_enum::BRENTCMDUSD);
	}
	else if (s_capitalized == "LIGHTCMDUSD") {
		v = boost::any(symbols_enum::LIGHTCMDUSD);
	}
	else if (s_capitalized == "CUCMDUSD") {
		v = boost::any(symbols_enum::CUCMDUSD);
	}
	else if (s_capitalized == "AUCMDUSD") {
		v = boost::any(symbols_enum::AUCMDUSD);
	}
	else if (s_capitalized == "E_SI") {
		v = boost::any(symbols_enum::E_SI);
	}
	else if (s_capitalized == "PDCMDUSD") {
		v = boost::any(symbols_enum::PDCMDUSD);
	}
	else if (s_capitalized == "PTCMDUSD") {
		v = boost::any(symbols_enum::PTCMDUSD);
	}
	else if (s_capitalized == "AUSIDXAUD") {
		v = boost::any(symbols_enum::AUSIDXAUD);
	}
	else if (s_capitalized == "BRAIDXBRL") {
		v = boost::any(symbols_enum::BRAIDXBRL);
	}
	else if (s_capitalized == "NLDIDXEUR") {
		v = boost::any(symbols_enum::NLDIDXEUR);
	}
	else if (s_capitalized == "ITAIDXEUR") {
		v = boost::any(symbols_enum::ITAIDXEUR);
	}
	else if (s_capitalized == "ESPIDXEUR") {
		v = boost::any(symbols_enum::ESPIDXEUR);
	}
	else if (s_capitalized == "EUSIDXEUR") {
		v = boost::any(symbols_enum::EUSIDXEUR);
	}
	else if (s_capitalized == "FRAIDXEUR") {
		v = boost::any(symbols_enum::FRAIDXEUR);
	}
	else if (s_capitalized == "GBRIDXGBP") {
		v = boost::any(symbols_enum::GBRIDXGBP);
	}
	else if (s_capitalized == "DEUIDXEUR") {
		v = boost::any(symbols_enum::DEUIDXEUR);
	}
	else if (s_capitalized == "CHEIDXCHF") {
		v = boost::any(symbols_enum::CHEIDXCHF);
	}
	else if (s_capitalized == "USATECHIDXUSD") {
		v = boost::any(symbols_enum::USATECHIDXUSD);
	}
	else if (s_capitalized == "USACOMIDXUSD") {
		v = boost::any(symbols_enum::USACOMIDXUSD);
	}
	else if (s_capitalized == "USA30IDXUSD") {
		v = boost::any(symbols_enum::USA30IDXUSD);
	}
	else if (s_capitalized == "USA500IDXUSD") {
		v = boost::any(symbols_enum::USA500IDXUSD);
	}
	else if (s_capitalized == "USAMJRIDXUSD") {
		v = boost::any(symbols_enum::USAMJRIDXUSD);
	}
	else if (s_capitalized == "HKGIDXHKD") {
		v = boost::any(symbols_enum::HKGIDXHKD);
	}
	else if (s_capitalized == "JPNIDXJPY") {
		v = boost::any(symbols_enum::JPNIDXJPY);
	}
	else if (s_capitalized == "ZARJPY") {
		v = boost::any(symbols_enum::ZARJPY);
	}
	else if (s_capitalized == "USDZAR") {
		v = boost::any(symbols_enum::USDZAR);
	}
	else if (s_capitalized == "USDTRY") {
		v = boost::any(symbols_enum::USDTRY);
	}
	else if (s_capitalized == "USDRUB") {
		v = boost::any(symbols_enum::USDRUB);
	}
	else if (s_capitalized == "USDBRL") {
		v = boost::any(symbols_enum::USDBRL);
	}
	else if (s_capitalized == "USDDKK") {
		v = boost::any(symbols_enum::USDDKK);
	}
	else if (s_capitalized == "USDHKD") {
		v = boost::any(symbols_enum::USDHKD);
	}
	else if (s_capitalized == "USDHUF") {
		v = boost::any(symbols_enum::USDHUF);
	}
	else if (s_capitalized == "USDMXN") {
		v = boost::any(symbols_enum::USDMXN);
	}
	else if (s_capitalized == "USDPLN") {
		v = boost::any(symbols_enum::USDPLN);
	}
	else if (s_capitalized == "SGDJPY") {
		v = boost::any(symbols_enum::SGDJPY);
	}
	else if (s_capitalized == "MXNJPY") {
		v = boost::any(symbols_enum::MXNJPY);
	}
	else if (s_capitalized == "NZDSGD") {
		v = boost::any(symbols_enum::NZDSGD);
	}
	else if (s_capitalized == "HKDJPY") {
		v = boost::any(symbols_enum::HKDJPY);
	}
	else if (s_capitalized == "EURUSD") {
		v = boost::any(symbols_enum::EURUSD);
	}
	else if (s_capitalized == "EURZAR") {
		v = boost::any(symbols_enum::EURZAR);
	}
	else if (s_capitalized == "EURTRY") {
		v = boost::any(symbols_enum::EURTRY);
	}
	else if (s_capitalized == "EURRUB") {
		v = boost::any(symbols_enum::EURRUB);
	}
	else if (s_capitalized == "EURPLN") {
		v = boost::any(symbols_enum::EURPLN);
	}
	else if (s_capitalized == "EURSGD") {
		v = boost::any(symbols_enum::EURSGD);
	}
	else if (s_capitalized == "EURMXN") {
		v = boost::any(symbols_enum::EURMXN);
	}
	else if (s_capitalized == "EURHUF") {
		v = boost::any(symbols_enum::EURHUF);
	}
	else if (s_capitalized == "EURHKD") {
		v = boost::any(symbols_enum::EURHKD);
	}
	else if (s_capitalized == "EURDKK") {
		v = boost::any(symbols_enum::EURDKK);
	}
	else if (s_capitalized == "CHFSGD") {
		v = boost::any(symbols_enum::CHFSGD);
	}
	else if (s_capitalized == "CHFPLN") {
		v = boost::any(symbols_enum::CHFPLN);
	}
	else if (s_capitalized == "CADHKD") {
		v = boost::any(symbols_enum::CADHKD);
	}
	else if (s_capitalized == "AUDSGD") {
		v = boost::any(symbols_enum::AUDSGD);
	}
	else if (s_capitalized == "AUDNZD") {
		v = boost::any(symbols_enum::AUDNZD);
	}
	else if (s_capitalized == "AUDUSD") {
		v = boost::any(symbols_enum::AUDUSD);
	}
	else if (s_capitalized == "AUDJPY") {
		v = boost::any(symbols_enum::AUDJPY);
	}
	else if (s_capitalized == "EURCHF") {
		v = boost::any(symbols_enum::EURCHF);
	}
	else if (s_capitalized == "EURGBP") {
		v = boost::any(symbols_enum::EURGBP);
	}
	else if (s_capitalized == "EURJPY") {
		v = boost::any(symbols_enum::EURJPY);
	}
	else if (s_capitalized == "GBPCHF") {
		v = boost::any(symbols_enum::GBPCHF);
	}
	else if (s_capitalized == "GBPJPY") {
		v = boost::any(symbols_enum::GBPJPY);
	}
	else if (s_capitalized == "GBPUSD") {
		v = boost::any(symbols_enum::GBPUSD);
	}
	else if (s_capitalized == "NZDUSD") {
		v = boost::any(symbols_enum::NZDUSD);
	}
	else if (s_capitalized == "USDCAD") {
		v = boost::any(symbols_enum::USDCAD);
	}
	else if (s_capitalized == "USDCHF") {
		v = boost::any(symbols_enum::USDCHF);
	}
	else if (s_capitalized == "USDJPY") {
		v = boost::any(symbols_enum::USDJPY);
	}
	else if (s_capitalized == "CADJPY") {
		v = boost::any(symbols_enum::CADJPY);
	}
	else if (s_capitalized == "EURAUD") {
		v = boost::any(symbols_enum::EURAUD);
	}
	else if (s_capitalized == "CHFJPY") {
		v = boost::any(symbols_enum::CHFJPY);
	}
	else if (s_capitalized == "EURCAD") {
		v = boost::any(symbols_enum::EURCAD);
	}
	else if (s_capitalized == "EURNOK") {
		v = boost::any(symbols_enum::EURNOK);
	}
	else if (s_capitalized == "EURSEK") {
		v = boost::any(symbols_enum::EURSEK);
	}
	else if (s_capitalized == "USDNOK") {
		v = boost::any(symbols_enum::USDNOK);
	}
	else if (s_capitalized == "USDSEK") {
		v = boost::any(symbols_enum::USDSEK);
	}
	else if (s_capitalized == "USDSGD") {
		v = boost::any(symbols_enum::USDSGD);
	}
	else if (s_capitalized == "AUDCAD") {
		v = boost::any(symbols_enum::AUDCAD);
	}
	else if (s_capitalized == "AUDCHF") {
		v = boost::any(symbols_enum::AUDCHF);
	}
	else if (s_capitalized == "CADCHF") {
		v = boost::any(symbols_enum::CADCHF);
	}
	else if (s_capitalized == "EURNZD") {
		v = boost::any(symbols_enum::EURNZD);
	}
	else if (s_capitalized == "GBPAUD") {
		v = boost::any(symbols_enum::GBPAUD);
	}
	else if (s_capitalized == "GBPCAD") {
		v = boost::any(symbols_enum::GBPCAD);
	}
	else if (s_capitalized == "GBPNZD") {
		v = boost::any(symbols_enum::GBPNZD);
	}
	else if (s_capitalized == "NZDCAD") {
		v = boost::any(symbols_enum::NZDCAD);
	}
	else if (s_capitalized == "NZDCHF") {
		v = boost::any(symbols_enum::NZDCHF);
	}
	else if (s_capitalized == "NZDJPY") {
		v = boost::any(symbols_enum::NZDJPY);
	}
	else if (s_capitalized == "XAGUSD") {
		v = boost::any(symbols_enum::XAGUSD);
	}
	else if (s_capitalized == "XAUUSD") {
		v = boost::any(symbols_enum::XAUUSD);
	}
	else {
		throw validation_error(validation_error::invalid_option_value);
	}
}
std::ostream& operator<<(std::ostream& os, const timeframe_enum& timeframe_enum_to_string)
{
	std::map<timeframe_enum, std::string> xmap = boost::assign::map_list_of
	(timeframe_enum::TICK, "TICK")
		(timeframe_enum::S_30, "S_30")
		(timeframe_enum::M1, "M1")
		(timeframe_enum::M2, "M2")
		(timeframe_enum::M5, "M5")
		(timeframe_enum::M10, "M10")
		(timeframe_enum::M15, "M15")
		(timeframe_enum::M30, "M30")
		(timeframe_enum::H1, "H1")
		(timeframe_enum::H4, "H4")
		(timeframe_enum::D1, "D1");

	std::string enum_string_value = (xmap.find(timeframe_enum_to_string)->second);
	os << enum_string_value;
	return os;
}


std::ostringstream& operator<<(std::ostringstream& os, const timeframe_enum& timeframe_enum_to_string)
{
	std::map<timeframe_enum, std::string> xmap = boost::assign::map_list_of
	(timeframe_enum::TICK, "TICK")
		(timeframe_enum::S_30, "S_30")
		(timeframe_enum::M1, "M1")
		(timeframe_enum::M2, "M2")
		(timeframe_enum::M5, "M5")
		(timeframe_enum::M10, "M10")
		(timeframe_enum::M15, "M15")
		(timeframe_enum::M30, "M30")
		(timeframe_enum::H1, "H1")
		(timeframe_enum::H4, "H4")
		(timeframe_enum::D1, "D1");

	std::string enum_string_value = (xmap.find(timeframe_enum_to_string)->second);
	os << enum_string_value;
	return os;
}
void validate(boost::any& v,
	std::vector<std::string> const& values,
	timeframe_enum* /* target_type */,
	int)
{
	// Make sure no previous assignment to 'v' was made.
	validators::check_first_occurrence(v);

	// Extract the first string from 'values'. If there is more than
	// one string, it's an error, and exception will be thrown.
	std::string const& s = validators::get_single_string(values);

	const std::string& s_capitalized = boost::to_upper_copy(s);

	if (s_capitalized == "TICK") {
		v = boost::any(timeframe_enum::TICK);
	}
	else if (s_capitalized == "S_30") {
		v = boost::any(timeframe_enum::S_30);
	}
	else if (s_capitalized == "M1") {
		v = boost::any(timeframe_enum::M1);
	}
	else if (s_capitalized == "M2") {
		v = boost::any(timeframe_enum::M2);
	}
	else if (s_capitalized == "M5") {
		v = boost::any(timeframe_enum::M5);
	}
	else if (s_capitalized == "M10") {
		v = boost::any(timeframe_enum::M10);
	}
	else if (s_capitalized == "M15") {
		v = boost::any(timeframe_enum::M15);
	}
	else if (s_capitalized == "M30") {
		v = boost::any(timeframe_enum::M30);
	}
	else if (s_capitalized == "H1") {
		v = boost::any(timeframe_enum::H1);
	}
	else if (s_capitalized == "H4") {
		v = boost::any(timeframe_enum::H4);
	}
	else if (s_capitalized == "D1") {
		v = boost::any(timeframe_enum::D1);
	}
	else {
		throw validation_error(validation_error::invalid_option_value);
	}
}
