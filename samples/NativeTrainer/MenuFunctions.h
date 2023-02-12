#pragma region definitions
///////////////////////
//menu bools
int submenu = 0;
int submenuLevel;
int lastSubmenu[20];
int lastOption[20];
bool showCoords;
bool showInfos;
bool newTimerTick = true;
int maxTimerCount;
int currentOption;
int optionCount;
bool optionPress = false;
int selectedPlayer;
bool test = false;

float titlex = 0.845f;
float titlebox = 0.845f;
float menutext = 0.745f;
float backx = 0.845f;
bool centerd = false;
int width = 30;


int titleTextRed = 255;
int titleTextGreen = 255;
int titleTextBlue = 255;
int titleTextOpacity = 255;
/////////////////////////////
int menutextcolor[4] = { titleTextRed, titleTextGreen, titleTextBlue, titleTextOpacity };
int titleTextFont = 7;
int titleRectRed = 20;
int titleRectGreen = 20;
int titleRectBlue = 20;
int titleRectOpacity = 255;//
////////////////////////////////
int optionsRed = 255;
int optionsGreen = 255;
int optionsBlue = 255;
int optionsOpacity = 255;
int optionsFont = 6;
/////////////////////////////
int scrollerRed = 125;
int scrollerGreen = 11;
int scrollerBlue = 225;
int scrollerOpacity = 190;
/////////////////////////////
int highlightRed = 49;
int highlightGreen = 65;
int highlightBlue = 185;
int highlightOpacity = 255;
//////////////////////////////
int indicatorRed = 255;//
int indicatorGreen = 44;//
int indicatorBlue = 55;
int indicatorOpacity = 255;
///////////////////////////////
int bannerTextRed = 255;
int bannerTextGreen = 255;
int bannerTextBlue = 255;
int bannerTextOpacity = 255;
int bannerTextFont = 1;
float Cunt = 0.080;
float Cunt2 = 0.225;
float Checkbox = 0.225;
float menuXCoord = 0.145f;
float ScrollX = 0.145f;
float textXCoord = 0.06f;
float TextRightCoord = 0.12f;
float titlebox3 = 0.928f;
int maxOptions = 18;
int bannerRectRed = 38;
int bannerRectGreen = 153;
int bannerRectBlue = 191;
int bannerRectOpacity = 195;
int backgroundRed = 0;
int backgroundGreen = 0;
int backgroundBlue = 0;
int backgroundOpacity = 195;
int bannerTextFont2 = 0;
int subr = 0;
int subb = 0;
int subg = 0;
int suba = 195;
int subFont = 6;
char *infoText;
int gGlareHandle;
int scaleform;
float gGlareDir;
float GlareX = 0.392f;
float GlareY = 0.385f;
float Glarewidth = 0.71f;
float Glareheight = 0.75f;
char* g_VehMenu[24] = { "Super Cars", "Sports Cars", "Sports Classic Cars","Muscle Cars", "Coupe Cars","Compact Cars", "Sedan Cars", "Utility", "SUVs", "Off Road", "Tuners", "Vans", "Boats", "Planes","Open Wheel","Emergency","Commercial","Service", "Military","Helicopters","Industrial","Cycles","Motorcycles","Remote Control" };
char* g_pcMainMenu[20] = { "Super Cars", "Sports Cars", "Sports Classic Cars", "Muscle Cars", "Sedans", "Coupes", "Compacts", "SUVs and Trucks", "Offroad Vehicles", "Vans", "Emergency Vehicles", "Service Vehicles", "Military Vehicles", "Motorcycles", "Bicycles", "Commercial Vehicles", "Helicopters", "Planes", "Boats", "Trailers" };
char* g_pcSportsCars[29] = { "Annis Elegy RH8", "Hijak Khamelion", "Grotti Carbonizzare", "Benefactor Feltzer 1", "Benefactor Feltzer 2", "Dewbauchee Rapid GT 1", "Inverto Coquette 1", "Dewbauchee Rapid GT 2", "Obey 9F Cabrio", "Obey 9F", "Benefactor Surano", "Bravado Banshee", "Pfister Comet", "Benefactor Schwartzer", "Schyster Fusilade", "Bravado Buffalo", "Bravado Buffalo 2", "Maibatsu Penumbra", "Karin Sultan", "Karin Futo", "Lampadati Furore GT", "Dewbauchee Massacro 1", "Dewbauchee Massacro 2", "Dinka Jester 1", "Dinka Jester 2", "Enus Windsor", "Albany Alpha", "Karin Kuruma 1", "Karin Kuruma 2" };
char* g_pcSportsClassicCars[20] = { "Inverto Coquette 2", "Inverto Coquette 3", "Truffade Z-Type", "Grotti Stinger GT", "Grotti Stinger", "Pegassi Monroe", "Dewbauchee JB 700", "Declasse Tornado 1", "Declasse Tornado 2", "Declasse Tornado 3", "Declasse Tornado 4", "Vapid Peyote", "Albany Manana", "Albany Virgo", "Albany Roosevelt", "Vapid Blade", "Benefactor Glendale", "Lampadati Pigalle", "Lampadati Casco", "Vapid Chino" };
char* g_pcMuscleCars[12] = { "Vapid Hotknife", "Bravado Gauntlet", "Declasse Vigero", "Vapid Dominator", "Albany Buccaneer", "Imponte Phoenix", "Declasse Sabre Turbo", "Imponte Ruiner", "Declasse Voodoo", "Cheval Picador", "Rat Loader 1", "Rat Loader 2" };
char* g_pcSedans[23] = { "Enus Super Diamond", "Ubermacht Oracle 1", "Ubermacht Oracle 2", "Dundreary Stretch", "Cheval Fugitive", "Cheval Surge", "Benefactor Schafter", "Karin Asterope", "Karin Intruder", "Albany Washington", "Vapid Stanier", "Vulcan Ingot", "Albany Emperor 1", "Albany Emperor 2", "Albany Emperor 3", "Albany Primo", "Dundreary Regina", "Chariot Romero Hearse", "Obey Tailgater", "Declasse Premier", "Zirconium Stratum", "Declasse Asea 1", "Declasse Asea 2" };
char* g_pcCoupes[10] = { "Dewbauchee Exemplar", "Enus Cognoscenti Cabrio", "Lampadati Felon GT", "Lampadati Felon", "Ubermacht Zion Cabrio", "Ubermacht Zion", "Ubermacht Sentinel XS", "Ubermacht Sentinel", "Ocelot F620", "Ocelot Jackal" };
char* g_pcOffRoads[19] = { "Monster Truck", "Vapid Sandking XL", "BF Dune Buggy", "BF Dune 2 (Space Docker)", "BF Injection", "BF Bifta", "Nagasaki Blazer 1", "Nagasaki Blazer 2 (Trevors)", "Canis Mesa (Merryweather)", "Vapid Sandking SWB", "Bravado Duneloader", "Canis Bodhi", "Declasse Rancher XL 1", "Declasse Rancher XL 2", "Karin Rebel 1", "Karin Rebel 2", "Nagasaki Blazer Lifeguard", "Coil Brawler", "Dinka Enduro" };
char* g_pcEmergencyCars[18] = { "FIB", "FIB SUV", "Firetruck", "Ambulance", "Police 1", "Police 2", "Police 3", "Police 4", "Police Bike", "Police Old 1", "Police Old 2", "Police Van", "Swat Truck", "Sheriff 1", "Sheriff 2", "Prison Bus", "Park Ranger", "Life Guard SUV" };
char* g_pcServicVehicles[6] = { "Airport Bus", "Dashhound", "Bus", "Rental Shuttle Bus", "Tour Bus", "Taxi" };
char* g_pcMilitary[7] = { "Rhino Tank", "Barracks 1", "Barracks 2", "Barracks 3", "Canis Crusader", "Tanker 1", "Tanker 2" };
char* g_pcMotorcycles[21] = { "Nagasaki Carbon RS", "Pegassi Bati 801RR", "Pegassi Bati 801", "LCC Hexer", "LCC Innovation", "Dinka Double-T", "Dinka Thrust", "Dinka Vindicator", "Pegassi Ruffian", "Shitzu Vader", "Shitzu PCJ 600", "Shitzu Hakuchou", "Dinka Akuma", "Maibatsu Sanchez (Decal)", "Maibatsu Sanchez", "Pegassi ***gio", "Western Daemon", "Western Bagger", "Principe Nemesis", "Sovereign", "Principe Lectro" };
char* g_pcBicycles[7] = { "Whippet Race Bike", "Tri-Cycles Race Bike", "Scorcher", "Endurex Race Bike", "Cruiser", "BMX", "Fixter" };
char* g_pcHelicopters[14] = { "Annihilator", "Buzzard Attack Chopper 1", "Buzzard Attack Chopper 2", "Frogger 1", "Frogger 2", "Maverick", "Cargobob 1", "Cargobob 2", "Cargobob 3", "Police Maverick", "Swift 1", "Swift 2", "Buckingham Valkyrie", "Savage" };
char* g_pcPlanes[19] = { "Titan", "Buckingham Luxor 1", "Buckingham Luxor 2", "Buckingham Shamal", "Buckingham Vestra", "Buckingham Miljet", "Velum 1", "Velum 2", "Mammatus", "Duster", "Mallard", "Cuban 800", "Cargo Plane", "Blimp", "P-996 Lazer", "Skylift", "Jet", "Bersa", "Mammoth Hydra" };
char* g_pcBoats[13] = { "Dinka Marquis", "Shitzu Jetmax", "Shitzu Squalo", "Shitzu Suntrap", "Shitzu Tropic", "Speedophile Seashark 1", "Speedophile Seashark 2", "Police Predator", "Submarine", "Pegassi Speeder", "Nagasaki Dinghy 1", "Nagasaki Dinghy 2", "Lampadati Toro" };
char* g_pcSuperCars[59] = { "Pfister811","adder","autarch","banshee2","openwheel1","bullet","champion","cheetah","cyclone","deveste","openwheel2","emerus","entityxf","entity2","entity3","sheava","fmj","furia","gp1","ignus","infernus","italigbt","italigbt2","krieger","lm87","osiris","nero","nero2","penetrator","formula","formula2","le7b","reaper","voltic2","s80","sc1","scramjet","sultanrs","t20","taipan","tempesta","tezeract","thrax","tigon","torero2","turismor","tyrant","tyrus","vacca","vagner","virtue","visione","voltic","voltic2","prototipo","xa21","zeno","zentorno","zorrusso" };
int g_uiSuperCars[59] = { 0x92EF6E04, 0xB779A091, 0xED552C74, 0x25C5AF13, 0x58F77553, 0x9AE6DDA1, 0xC972A155, 0xB1D95DA0, 0x52FF9437, 0x5EE005DA, 0x4669D038, 0x4EE74355, 0xB2FE5CF9, 0x8198AEDC, 0x6838FC1D, 0x30D3F6D8, 0x5502626C, 0x3944D5A0, 0x4992196C, 0xA9EC907B, 0x18F25AC7, 0x85E8E76B, 0xE33A477B, 	0xD86A0247, 0xFF5968CD, 0x767164D6, 0x3DA47243, 0x4131F378, 0x9734F3EA, 0x1446590A, 0x8B213907, 0xB6846A55, 0x0DF381E5, 0x3AF76F4A, 0xECA6B6A3, 0x5097F589, 0xD9F0503D, 0xEE6024BC, 0x6322B39A, 0xBC5DC07E, 0x1044926F, 0x3D7C6410, 0x3E3D1F59, 0xAF0B8D48, 0xF62446BA, 0x185484E1, 0xE99011C2, 0x7B406EFB, 0x142E0DC3, 0x7397224C,0x27E34161,0xC4810400,0x9F4B77BE,0x3AF76F4A, 0x7E8F677F,0x36B4A8A9,0x2714AA93,0xAC5DF515,0xD757D97D };
const char* g_pcSuperCars2[59] = { "Pfister811","adder","autarch","banshee2","openwheel1","bullet","champion","cheetah","cyclone","deveste","openwheel2","emerus","entityxf","entity2","entity3","sheava","fmj","furia","gp1","ignus","infernus","italigbt","italigbt2","krieger","lm87","osiris","nero","nero2","penetrator","formula","formula2","le7b","reaper","voltic2","s80","sc1","scramjet","sultanrs","t20","taipan","tempesta","tezeract","thrax","tigon","torero2","turismor","tyrant","tyrus","vacca","vagner","virtue","visione","voltic","voltic2","prototipo","xa21","zeno","zentorno","zorrusso" };
int g_uiSuperCars2[59] = { 0x92EF6E04, 0xB779A091, 0xED552C74, 0x25C5AF13, 0x58F77553, 0x9AE6DDA1, 0xC972A155, 0xB1D95DA0, 0x52FF9437, 0x5EE005DA, 0x4669D038, 0x4EE74355, 0xB2FE5CF9, 0x8198AEDC, 0x6838FC1D, 0x30D3F6D8, 0x5502626C, 0x3944D5A0, 0x4992196C, 0xA9EC907B, 0x18F25AC7, 0x85E8E76B, 0xE33A477B, 	0xD86A0247, 0xFF5968CD, 0x767164D6, 0x3DA47243, 0x4131F378, 0x9734F3EA, 0x1446590A, 0x8B213907, 0xB6846A55, 0x0DF381E5, 0x3AF76F4A, 0xECA6B6A3, 0x5097F589, 0xD9F0503D, 0xEE6024BC, 0x6322B39A, 0xBC5DC07E, 0x1044926F, 0x3D7C6410, 0x3E3D1F59, 0xAF0B8D48, 0xF62446BA, 0x185484E1, 0xE99011C2, 0x7B406EFB, 0x142E0DC3, 0x7397224C,0x27E34161,0xC4810400,0x9F4B77BE,0x3AF76F4A, 0x7E8F677F,0x36B4A8A9,0x2714AA93,0xAC5DF515,0xD757D97D };

int g_uiSportsCars[29] = { 0xDE3D9D22, 0x206D1B68, 0x7B8AB45F, 0x8911B9F5, 0xA29D6D10, 0x8CB29A14, 0x067BC037, 0x679450AF, 0x3D8FA25C, 0xA8E38B01, 0x16E478C1, 0xC1E908D2, 0xC1AE4D16, 0xD37B7976, 0x1DC0BA53, 0xEDD516C6, 0x2BEC3CBE, 0xE9805550, 0x39DA2754, 0x7836CE2F, 0xBF1691E0, 0xF77ADE32, 0xDA5819A3, 0xB2A716A3, 0xBE0E6126, 0x5E4327C8, 0x2DB8D1AA, 0xAE2BFE94, 0x187D938D };
int g_uiSportsClassicCars[20] = { 0x3C4E2113, 0x2EC385FE, 0x2D3BD401, 0x82E499FA, 0x5C23AF9B, 0xE62B361B, 0x3EAB5555, 0x1BB290BC, 0x5B42A5C4, 0x690A4153, 0x86CF7CDD, 0x6D19CCBC, 0x81634188, 0xE2504942, 0x06FF6914, 0xB820ED5E, 0x047A6BC1, 0x404B6381, 0x3822BDFE, 0x14D69010 };
int g_uiMuscleCars[12] = { 0x0239E390, 0x94B395C5, 0xCEC6B9B7, 0x04CE68AC, 0xD756460C, 0x831A21D5, 0x9B909C94, 0xF26CEFF9, 0x1F3766E3, 0x59E0FBF3, 0xD83C13CE, 0xDCE1D9F7 };
int g_uiSedans[23] = { 0x42F2ED16, 0x506434F6, 0xE18195B2, 0x8B13F083, 0x71CB2FFB, 0x8F0E3594, 0xB52B5113, 0x8E9254FB, 0x34DD8AA1, 0x69F06B57, 0xA7EDE74D, 0xB3206692, 0xD7278283, 0x8FC3AADC, 0xB5FCF74E, 0xBB6B404F, 0xFF22D208, 0x2560B2FC, 0xC3DDFDCE, 0x8FB66F9B, 0x66B4FC45, 0x94204D89, 0x9441D8D5 };
int g_uiCoupes[10] = { 0xFFB15B5E, 0x13B57D8A, 0xFAAD85EE, 0xE8A8BDA8, 0xBD1B39C3, 0xB8E2AE18, 0x50732C82, 0x3412AE2D, 0xDCBCBE48, 0xDAC67112 };
int g_uiOffRoads[19] = { 0xCD93A7DB, 0xB9210FD0, 0x9CF21E0F, 0x1FD824AF, 0x432AA566, 0xEB298297, 0x8125BCF9, 0xB44F0582, 0x84F42E51, 0x3AF8C345, 0x698521E3, 0xAA699BB6, 0x6210CBB0, 0x7341576B, 0xB802DD46, 0x8612B64B, 0xFD231729, 0xA7CE1BC5, 0x6882FA73 };
int g_uiEmergencyCars[18] = { 0x432EA949, 0x9DC66994, 0x73920F8E, 0x45D56ADA, 0x79FBB0C5, 0x9F05F101, 0x71FA16EA, 0x8A63C7B9, 0xFDEFAEC3, 0xA46462F7, 0x95F4C618, 0x1B38E955, 0xB822A1AA, 0x9BAA707C, 0x72935408, 0x885F3671, 0x2C33B46E, 0x1BF8D381 };
int g_uiServicVehicles[6] = { 0x4C80EB0E, 0x84718D34, 0xD577C962, 0xBE819C63, 0x73B1C3CB, 0xC703DB5F };
int g_uiMilitary[7] = { 0x2EA68690, 0xCEEA3F4B, 0x4008EABB, 0x2592B5CF, 0x132D5A1A, 0xD46F4737, 0x74998082 };
int g_uiMotorcycles[21] = { 0x00ABB0C0, 0xCADD5D2D, 0xF9300CC5, 0x11F76C14, 0xF683EACA, 0x9C669788, 0x6D6F8F43, 0xAF599F01, 0xCABD11E8, 0xF79A00F7, 0xC9CEAF06, 0x4B6C568A, 0x63ABADE7, 0x2EF89E46, 0xA960B13E, 0x0350D1AB, 0x77934CEE, 0x806B9CC3, 0xDA288376, 0x2C509634, 0x26321E67 };
int g_uiBicycles[7] = { 0x4339CD69, 0xE823FB48, 0xF4E1AA15, 0xB67597EC, 0x1ABA13B5, 0x43779C54, 0xCE23D3BF };
int g_uiHelicopters[14] = { 0x31F0B376, 0x2F03547B, 0x2C75F0DD, 0x2C634FBD, 0x742E9AC0, 0x9D0450CA, 0xFCFCB68B, 0x60A7EA10, 0x53174EEF, 0x1517D4D9, 0xEBC24DF2, 0x4019CB4C, 0xA09E15FD, 0xFB133A17 };
int g_uiPlanes[19] = { 0x761E2AD3, 0x250B0C5E, 0xB79F589E, 0xB79C1BF5, 0x4FF77E37, 0x09D80F93, 0x9C429B6A, 0x403820E8, 0x97E55D11, 0x39D6779E, 0x81794C70, 0xD9927FE3, 0x15F27762, 0xF7004C86, 0xB39B0AE6, 0x3E48BF23, 0x3F119114, 0x6CBD1D6D, 0x39D6E83F };
int g_uiBoats[13] = { 0xC1CE1183, 0x33581161, 0x17DF5EC2, 0xEF2295C9, 0x1149422F, 0xC2974024, 0xDB4388E4, 0xE2E7D4AB, 0x2DFF622F, 0x0DC60D2B, 0x3D961290, 0x107F392C, 0x3FD5AA2F };
int supercar, sportcar, sportclassic, musclecar, sedans, coupecar, compacts, suvtruck, offroad, emergancy, service, military, motorcycles, bikes, helicopter, planes, boats;
static LPCSTR weaponNames[] = {
		"WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR",
		"WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_MICROSMG", "WEAPON_SMG",
		"WEAPON_ASSAULTSMG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_MG",
		"WEAPON_COMBATMG", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN",
		"WEAPON_STUNGUN", "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_GRENADELAUNCHER", "WEAPON_GRENADELAUNCHER_SMOKE",
		"WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS",
		"WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN",
		"WEAPON_SNSPISTOL", "WEAPON_SPECIALCARBINE", "WEAPON_HEAVYPISTOL", "WEAPON_BULLPUPRIFLE", "WEAPON_HOMINGLAUNCHER",
		"WEAPON_PROXMINE", "WEAPON_SNOWBALL", "WEAPON_VINTAGEPISTOL", "WEAPON_DAGGER", "WEAPON_FIREWORK", "WEAPON_MUSKET",
		"WEAPON_MARKSMANRIFLE", "WEAPON_HEAVYSHOTGUN", "WEAPON_GUSENBERG", "WEAPON_HATCHET", "WEAPON_RAILGUN", "WEAPON_FLAREGUN",
		"WEAPON_KNUCKLE", "GADGET_NIGHTVISION", "GADGET_PARACHUTE", "WEAPON_MARKSMANPISTOL", "", ""
};
char * weather[] = { "Extra Sunny", "Clear", "Clouds", "Smog", "Foggy", "Thunder", "Overcast", "Snowlight", "Snow", "Blizzard", "Neutral" };
int weathers;
char * weathero[] = { "EXTRASUNNY", "CLEAR", "CLOUDS", "SMOG", "FOGGY", "THUNDER", "OVERCAST", "SNOWLIGHT", "SNOW", "BLIZZARD", "NEUTRAL" };
char * timecycle[] = { "CANYON_MISSION", "MP_CORONA_HEIST_DOF", "Barry1_Stoned", "BlackOut", "blackNwhite", "AmbientPUSH", "AP1_01_B_IntRefRange", "AP1_01_C_NoFog", "Bank_HLWD", "Barry1_Stoned",
"BarryFadeOut", "baseTONEMAPPING", "Bikers", "BikersSPLASH", "Bloom", "BloomLight", "BloomMid", "buggy_shack", "buildingTOP", "BulletTimeDark", "CAMERA_BW", "CAMERA_secuirity",
"CAMERA_secuirity_FUZZ", "canyon_mission", "carMOD_underpass", "carpark", "carpark_dt1_02", "carpark_dt1_03", "Carpark_MP_exit", };
int timecy, Hour = TIME::GET_CLOCK_HOURS(), Minute = TIME::GET_CLOCK_MINUTES(), Second = TIME::GET_CLOCK_SECONDS();
int DelayCounter = GetTickCount();
bool firstopenmenu = false;

bool keyboardActive = false;

int Messages, keyboardAction, *keyboardVar = 0;
bool SpawnedPedHasGodmode[20];
char* SoundToPlay;
char* SoundSetToPlay;
bool PlaySounds;
char* VehName;
Vehicle veh;
char *model;
HANDLE mainFiber;
DWORD wakeAt;
char str[50];
#pragma warning(disable : 4244 4305) // double <-> float conversions
uint32_t hash_veh;
int SpawnedVeh;
bool GodModeTog = false, VehicleGod = false;
char* VehicleString;
bool SpawningVehicle;
bool PlayerGodmod;
bool NoCops;
BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID());
using namespace std;
#pragma endregion
#pragma region Option Helpers
void drawNotification(char* msg)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(msg);
	UI::_SET_NOTIFICATION_MESSAGE("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", true, 4, "Synergy PC", "");
	UI::_DRAW_NOTIFICATION(false, true);
}
void drawTextAlt2(char * text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	UI::SET_TEXT_FONT(4);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center);
	//UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_TEXT(x, y);
}
void drawText(char * text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_TEXT(x, y);
}
bool isNumericChar(char x)
{
	return (x >= '0' && x <= '9') ? true : false;
}
int StoI(char *str)
{
	if (*str == NULL)
		return 0;

	int res = 0,
		sign = 1,
		i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	for (; str[i] != '\0'; ++i)
	{
		if (isNumericChar(str[i]) == false)
			return 0;
		res = res * 10 + str[i] - '0';
	}
	return sign * res;
}
char *ItoS(int num)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%i", num);
	return buf;
}
char* FtoS(float input)
{
	char returnvalue[64];
	int wholenumber = (int)input;
	input -= wholenumber;
	input *= 100;
	sprintf_s(returnvalue, "%d.%d", wholenumber, (int)input);
	return returnvalue;
}
float conv360(float base, float min, float max) {

	float fVar0;
	if (min == max) return min;
	fVar0 = max - min;
	base -= round(base - min / fVar0) * fVar0;
	if (base < min) base += fVar0;
	return base;
}

void drawGlare(float PositionX = GlareX, float ositionY = GlareY, float width = Glarewidth, float height = Glareheight, int r = 255, int g = 255, int b = 200)
{
	gGlareHandle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_MENU_GLARE");
	Vector3 rot = CAM::_GET_GAMEPLAY_CAM_ROT(2);
	float dir = conv360(rot.z, 0, 360);
	if ((gGlareDir == 0 || gGlareDir - dir > 0.5) || gGlareDir - dir < -0.5)
	{
		gGlareDir = dir;

		GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(gGlareHandle, "SET_DATA_SLOT");

		GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_FLOAT(gGlareDir);

		GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
	}
	GRAPHICS::DRAW_SCALEFORM_MOVIE(gGlareHandle, GlareX, GlareY, Glarewidth, Glareheight, r, g, b, 255, 0);
	GRAPHICS::_0xE3A3DB414A373DAB();
}
void changeSubmenu(int newSubmenu)
{
	lastSubmenu[submenuLevel] = submenu;
	lastOption[submenuLevel] = currentOption;
	currentOption = 1;
	submenu = newSubmenu;
	submenuLevel++;
}
void SetupTimer(int tickTime)
{
	if (newTimerTick) {
		maxTimerCount = GAMEPLAY::GET_GAME_TIMER() + tickTime;
		newTimerTick = false;
	}
}
bool IsTimerReady()
{
	return GAMEPLAY::GET_GAME_TIMER() > maxTimerCount;
}
void ResetTimer()
{
	newTimerTick = true;
}


//////////////////////////////////
void DRAW_TEXTURE(string Streamedtexture, string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
	}
	else
	{
		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x, y, width, height, rotation, r, g, b, a);
	}
}

void addTitle(char *title)
{
	drawText(title, bannerTextFont, menuXCoord, 0.070f, 0.75f, 0.75f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, true);
	GRAPHICS::DRAW_RECT(menuXCoord, 0.0850f, 0.19f, 0.080f, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity);
	drawGlare(menuXCoord, 0.1410f, 0.190f, 0.034f, 255, 255, 255);	
}
void addSubTitle(char *texting)
{//cunt 0.80f
	drawText(texting, subFont, menuXCoord, 0.125f, 0.40f, 0.40f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, true);
	GRAPHICS::DRAW_RECT(menuXCoord, 0.1410f, 0.190f, 0.034f, subr, subg, subb, suba);
}
void DrawSprite(char* Streamedtexture, char* textureName, float X, float Y, float Width, float Height, float Rotation, int R = 255, int G = 255, int B = 255, int A = 255)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);
	GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture);
	GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, X, Y, Width, Height, Rotation, R, G, B, A);
}
void DRAW_SPRITE(char* TextOne, char* TextTwo, float X, float Y, float Width, float Height, float Rotation, int R = 255, int G = 255, int B = 255, int A = 255)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(TextOne, false);
	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(TextOne))
		GRAPHICS::DRAW_SPRITE(TextOne, TextTwo, X, Y, Width, Height, Rotation, R, G, B, A);
}
void DrawSprite1(char * Streamedtexture, char * textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);
	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture))
		GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, r, g, b, a);
}
void addOption(char *option, char* info = NULL)
{
	optionCount++;
	if (currentOption == optionCount)
		infoText = info;
	if (currentOption <= maxOptions && optionCount <= maxOptions)
		drawText(option, optionsFont, textXCoord, (optionCount * 0.035f + 0.125f), 0.4f, 0.4f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
		drawText(option, optionsFont, textXCoord, ((optionCount - (currentOption - maxOptions)) * 0.035f + 0.125f), 0.4f, 0.4f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
}

bool rightPress = false;
bool leftPress = false;
void addIntOption(char *option, int *var, int min, int max, char* info = NULL)
{
	char buf[100];
	_snprintf_s(buf, sizeof(buf), "%s < %i >", option, *var);
	addOption(buf, info);
	if (currentOption == optionCount)
	{
		if (rightPress)
		{
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
			rightPress = false;
		}
		else if (leftPress)
		{
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
			leftPress = false;
		}
	}
}

bool rightPress1 = false;
bool leftPress1 = false;
void addArrayOption(char *test, int *var, int min, int max)
{//var = pointer to array
	addOption(test);
	if (currentOption == optionCount)
	{
		if (rightPress1)
		{
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
			rightPress1 = false;
		}
		else if (leftPress1)
		{
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
			leftPress1 = false;
		}
	}
}

int getOptionint()
{
	return currentOption;
}


void addSubmenuOption(char *option, int newSubmenu, char* info = NULL)
{
	addOption(option, info);
	if (currentOption == optionCount && optionPress)
		changeSubmenu(newSubmenu);
}

int getOption()
{
	if (optionPress)
	{
		return currentOption;
	}
	else return 0;
}

bool getKeyPressed(int key) {
	return (GetAsyncKeyState(key) & 0xFFFF) == 0x8001;
}


void playSound(char* sound)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound, "HUD_FRONTEND_DEFAULT_SOUNDSET",1);
}
void PlaySoundz(char* SoundName, char* SoundSetName)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, SoundName, SoundSetName, 1);
}


void monitorButtons()
{
	if (GetTickCount() - DelayCounter > 150)
	{
		if (submenu == 0)
		{
			if (getKeyPressed(VK_NUMPAD7) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_SCRIPT_LB) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_SCRIPT_PAD_DOWN)) && submenu == 0)
			{
				DelayCounter = GetTickCount();
				submenu = 1;
				submenuLevel = 0;
				currentOption = 1;
				SoundToPlay = "FLIGHT_SCHOOL_LESSON_PASSED";
				SoundSetToPlay = "HUD_AWARDS";
				PlaySounds = true;
			}
			ResetTimer();
		}
		else {

			if (getKeyPressed(VK_NUMPAD9) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_CANCEL) && submenu != 0)//exit
			{
				DelayCounter = GetTickCount();
				if (submenu == 1)
				{
					submenu = 0;
				}
				else {
					submenu = lastSubmenu[submenuLevel - 1];
					currentOption = lastOption[submenuLevel - 1];
					submenuLevel--;
				}
				SoundToPlay = "BACK";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_ACCEPT) && submenu != 0)//option select
			{
				DelayCounter = GetTickCount();
				optionPress = true;
				SoundToPlay = "SELECT";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_UP) && submenu != 0)//up
			{
				DelayCounter = GetTickCount();

				currentOption--;
				currentOption = currentOption < 1 ? optionCount : currentOption;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_DOWN) && submenu != 0)//down
			{
				DelayCounter = GetTickCount();
				currentOption++;
				currentOption = currentOption > optionCount ? 1 : currentOption;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_CELLPHONE_LEFT))//down
			{
				leftPress = true;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
			else if (getKeyPressed(VK_NUMPAD6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_CELLPHONE_RIGHT))//down
			{
				rightPress = true;
				SoundToPlay = "NAV_UP_DOWN";
				SoundSetToPlay = "HUD_FRONTEND_DEFAULT_SOUNDSET";
				PlaySounds = true;
			}
		}
	}
}
void normalMenuActions()
{
	UI::HIDE_HELP_TEXT_THIS_FRAME();
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_CIN_CAM, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_FRANKLIN, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_MICHAEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_TREVOR, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_SELECT_CHARACTER_MULTIPLAYER, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_CHARACTER_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_LIGHT, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_HEAVY, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_ALTERNATE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MULTIPLAYER_INFO, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MAP_POI, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);

	if (optionCount > maxOptions)
	{
		GRAPHICS::DRAW_RECT(menuXCoord, (((maxOptions * 0.035f) / 2) + 0.159f), 0.19f, (maxOptions * 0.035f), backgroundRed, backgroundGreen, backgroundBlue, backgroundOpacity); //Background
		if (currentOption > maxOptions)
		{
			GRAPHICS::DRAW_RECT(ScrollX, ((maxOptions * 0.035f) + 0.1415f), 0.19f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller
		}
		else
		{
			GRAPHICS::DRAW_RECT(ScrollX, ((currentOption * 0.035f) + 0.1415f), 0.19f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller
		}
		if (currentOption != optionCount)
		{
		}
	}
	else
	{
		GRAPHICS::DRAW_RECT(menuXCoord, (((optionCount * 0.035f) / 2) + 0.159f), 0.19f, (optionCount * 0.035f), backgroundRed, backgroundGreen, backgroundBlue, backgroundOpacity); //Background
		GRAPHICS::DRAW_RECT(ScrollX, ((currentOption * 0.035f) + 0.1415f), 0.19f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller
	}
	if (!GAMEPLAY::IS_STRING_NULL_OR_EMPTY(infoText))
	{
		if (optionCount > maxOptions)
		{
			drawText(infoText, optionsFont, menuXCoord, ((maxOptions + 1) * 0.035f + 0.125f), 0.4f, 0.4f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, true);
			GRAPHICS::DRAW_RECT(menuXCoord, (((maxOptions + 1) * 0.035f) + 0.1415f), 0.19f, 0.035f, subr, subg, subb, suba); //Info Box
			GRAPHICS::DRAW_RECT(menuXCoord, (((maxOptions + 1) * 0.035f) + 0.1230f), 0.19f, 0.003f, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity); //Box Line Hopefully
			UI::SET_TEXT_FONT(0);
			UI::SET_TEXT_SCALE(0.0f, 0.26f);
			UI::SET_TEXT_COLOUR(bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity);

			UI::_SET_TEXT_ENTRY("CM_ITEM_COUNT");
			UI::ADD_TEXT_COMPONENT_INTEGER(currentOption); // ! currentop_w_breaks
			UI::ADD_TEXT_COMPONENT_INTEGER(optionCount); // ! totalop - totalbreaks
			UI::_DRAW_TEXT(0.0705f + menuXCoord, (((maxOptions + 1) * 0.035f) + 0.1265f));
		}
		else
		{
			drawText(infoText, optionsFont, menuXCoord, ((optionCount + 1) * 0.035f + 0.125f), 0.4f, 0.4f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, true);
			GRAPHICS::DRAW_RECT(menuXCoord, (((optionCount + 1) * 0.035f) + 0.1415f), 0.19f, 0.035f, subr, subg, subb, suba); //Info Box
			GRAPHICS::DRAW_RECT(menuXCoord, (((optionCount + 1) * 0.035f) + 0.1230f), 0.19f, 0.003f, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity); //Box Line Hopefully
			UI::SET_TEXT_FONT(0);
			UI::SET_TEXT_SCALE(0.0f, 0.26f);
			UI::SET_TEXT_COLOUR(bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity);

			UI::_SET_TEXT_ENTRY("CM_ITEM_COUNT");
			UI::ADD_TEXT_COMPONENT_INTEGER(currentOption); // ! currentop_w_breaks
			UI::ADD_TEXT_COMPONENT_INTEGER(optionCount); // ! totalop - totalbreaks
			UI::_DRAW_TEXT(menuXCoord + 0.0705f, (((optionCount + 1) * 0.035f) + 0.1265f));
		}
	}		
	
}

void addBoolOption(char* option, bool b00l, char* text = "", bool meg = false)
{
	if (meg)
	{
		drawNotification(text);
	}
	char buf[30];
	if (b00l)
	{
		_snprintf_s(buf, sizeof(buf), "%s ~b~ON", option);
		addOption(buf);
	}
	else
	{
		_snprintf_s(buf, sizeof(buf), "%s ~r~OFF", option);
		addOption(buf);
	}
}
void drawTextR(char * text, int font = 0, float x = TextRightCoord, float y = 0.035f + (optionCount * 0.035f + 0.125f), int r = 255, int b = 255, int g = 255, int alpha = 255)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(0.3f, 0.3f);
	UI::SET_TEXT_OUTLINE();
	UI::SET_TEXT_COLOUR(r, b, g, alpha);	
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::SET_TEXT_WRAP(0.5f, 0.95f);//928
	UI::_DRAW_TEXT(x, y);
}

void addChar(char *left, char** right, int *var, int min, int max, char *info = NULL)
{
	char buf[60];
	_snprintf_s(buf, sizeof(buf), "%s(%i|%i)", right[*var], *var, max);
	drawTextR(buf);
	addOption(left, info);
	if (currentOption == optionCount)
	{
		if (rightPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
			rightPress = false;
		}
		else if (leftPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
			leftPress = false;
		}
	}
}
void addCharBool(char *left, char **Default, int *var, int min, int max, bool b00l, char *info = NULL)
{
	char buf[60];
	if (b00l)
		_snprintf_s(buf, sizeof(buf), "~g~%s ~c~(%i|%i)", Default[*var], *var, max);
	else
		_snprintf_s(buf, sizeof(buf), "~r~%s ~c~(%i|%i)", Default[*var], *var, max);

	drawTextR(buf);
	addOption(left, info);
	if (currentOption == optionCount)
	{
		if (rightPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
		}
		else if (leftPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
		}
	}
}
void addCheckBool(char *option, bool b00l1, char* info = NULL)
{
	char buf[30];
	if (b00l1)
	{
		_snprintf_s(buf, sizeof(buf), "%s", option);
		DrawSprite1("commonmenu", "shop_box_tick", Checkbox, (optionCount * 0.035f + 0.175f), 0.03, 0.04, 0, 255, 255, 255, 255);
		addOption(buf, info);
		
	}
	else
	{
		_snprintf_s(buf, sizeof(buf), "%s", option);
		DrawSprite1("commonmenu", "shop_box_blank", Checkbox, (optionCount * 0.035f + 0.175f), 0.03, 0.04, 0, 255, 255, 255, 255);
		addOption(buf, info);

	}
}
void addNotifyOption(char *option, char *notification)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		drawNotification(notification);
	}
}


char* StringToChar(std::string string)
{
	return _strdup(string.c_str());
}

void startKeyboard(int action, char *defaultText, int maxLength)
{
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "FMMC_KEY_TIP8", "", defaultText, "", "", "", maxLength);
	keyboardAction = action;
	keyboardActive = true;
}
void MenuRun()
{
	monitorButtons();
	optionPress = false;
}
#pragma endregion

