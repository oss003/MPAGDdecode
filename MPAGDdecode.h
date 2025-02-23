#define SnapshotOffset	(0x4000 - 0x1b)
#define debug 0

int CodeStart;
int EngineStart;
int VarAddress;
int ScrFormat;
int CallSpawn;
int CallCangoL;
int CallCangoR;
int CallCangoU;
int CallCangoD;
int CallCspr;
int CallSktype;
int CallRandom;
int CallAnimesp;
int CallAnimBack;
int CallAddSc;
int CallPrtmod;
int CallChr;
int CallClw;
int CallCls;
int CallDisply;
int CallNum2dd;
int CallExplod;
int CallGetob;
int CallGotob;
int CallGetcol;
int CallGravst;
int CallScrL;
int CallScrR;
int CallScrU;
int CallScrD;
int CallIFall;
int CallLadderU;
int CallLadderD;
int CallJump;
int CallDmsg;
int CallPut;
int CallSwpsb;
int CallLcol;
int CallWaitkey;
int CallRedraw;
int CallShoot;
int CallRemob;
int CallSpptr;
int CallTfall;
int CallTjump;
int CallVapour;

int ptr_offset;
int sndtype;
int nexlev;
int gamwon;
int prtmod;
int ident = 0;
int ogptr;
int score;
int seed;
int spptr;
int skptr;
int hiscor;
int bonus;
int font;

int mapdat;
int mapwid;
int mapstart;

int chgfx;
int bcol;
int bprop;
int numblk;
int msgdata;

int sprgfx;
int frmlst;
int numspr;

int numobj;
int objdta;

int scdat;
int numsc;

int nmedat;

int nummsg;

char cmd_ADDBONUS[]			= "CD4D71";
char cmd_ADD1TOVAR[]		= "3Axxxx3C32xxxx";
char cmd_ADD1TOSPRVAR[]		= "DD7Exx3C";
char cmd_ADDVARTOVAR[]		= "3Axxxx4F3Axxxx8132xxxx";
char cmd_ADDVARTOSPRVAR[]	= "3Axxxx4FDD7Exx81DD77xx";
char cmd_ADDSPRVARTOVAR[]	= "DD7Exx4F3Axxxx8132xxxx";
char cmd_ADDVALTOVAR[]		= "0Exx3Axxxx8132xxxx";
char cmd_ADDVALTOSPRVAR[]	= "0ExxDD7Exx81DD77xx";
char cmd_SUB1FROMVAR[]		= "3Axxxx3D32xxxx";
char cmd_SUB1FROMSPRVAR[]	= "DD7Exx3DDD77xx";
char cmd_SUBVARFROMVAR[]	= "3Axxxx4F3Axxxx9132xxxx";
char cmd_SUBVARFROMSPRVAR[]	= "3Axxxx4FDD7Exx91DD77xx";
char cmd_SUBSPRVARFROMVAR[]	= "DD7Exx4F3Axxxx9132xxxx";
char cmd_SUBVALFROMVAR[]	= "0Exx3Axxxx9132xxxx";
char cmd_SUBVALFROMSPRVAR[]	= "0ExxDD7Exx91DD77xx";

char cmd_ANIMBACK[]         = "AFCDxxxx";
char cmd_ANIMBACKVSLOW[]	= "3E07CDxxxx";
char cmd_ANIMBACKSLOW[]		= "3E03CDxxxx";
char cmd_ANIMBACKMED[]		= "3E01CDxxxx";

char cmd_ANIMATE[]          = "AFCDxxxx";
char cmd_ANIMVSLOW[]		= "3E07CDxxxx";
char cmd_ANIMSLOW[]			= "3E03CDxxxx";
char cmd_ANIMMED[]			= "3E01CDxxxx";
char cmd_ATVALVAL[]			= "21xxxx22xxxx";
char cmd_ATVARVAL[]			= "3Axxxx6F3Exx6722xxxx";
char cmd_ATVALVAR[]			= "2Exx3Axxxx6722xxxx";
char cmd_ATVARVAR[]			= "3Axxxx6F3Axxxx6722xxxx";
char cmd_BEEPVAL[]			= "3Exx32xxxx";
char cmd_BEEPVAR[]			= "3AxxxxE67F32xxxx";
char cmd_BEEPSPRVAR[]		= "DD7ExxE67F32xxxx";
char cmd_BONUSVAL[]			= "CDxxxx21xxxxCDxxxx";
char cmd_BONUSVAR[]			= "CDxxxx3Axxxx6F2600";
char cmd_BORDERZERO[]		= "AFCD9B22";
char cmd_BORDERVAR[]		= "3AxxxxCD9B22";
char cmd_BORDERVAL[]		= "3ExxCD9B22";
char cmd_CANGODOWN[]		= "CDxxxxC2xxxx";
char cmd_CANGOLEFT[]		= "CDxxxxC2xxxx";
char cmd_CANGORIGHT[]		= "CDxxxxC2xxxx";
char cmd_CANGOUP[]			= "CDxxxxC2xxxx";
char cmd_CHRVAR[]			= "3AxxxxCDxxxx";
char cmd_CHRVAL[]			= "3ExxCDxxxx";
char cmd_CLS[]				= "CDxxxx";
char cmd_CLW[]				= "CDxxxxCDxxxx";
char cmd_IFCOLLVAL[]		= "06xxCDxxxxD2xxxx";
char cmd_IFCOLLVAR[]		= "3Axxxx47CDxxxxD2xxxx";
char cmd_IFCOLLSPRVAR[]		= "DD7Exx47CDxxxxD2xxxx";
char cmd_IFCOLLBULLET[]		= "CDxxxxD2xxxx";
char cmd_COLOURZERO[]		= "AF328D5C";
char cmd_COLOURVAL[]		= "3Exx328D5C";
char cmd_COLOURVAR[]		= "3Axxxx328D5C";
char cmd_CRASHZERO[]		= "3E8032xxxx";
char cmd_CRASHVAR[]			= "3AxxxxF68032xxxx";
char cmd_CRASHVAL[]			= "3Exx32xxxx";
char cmd_CRASHSPRVAR[]		= "DD7ExxF68032xxxx";
char cmd_IFCUSTOM[]			= "0606CDxxxxB8C2xxxx";
char cmd_IFDEADLY[]			= "0605CDxxxxB8C2xxxx";
char cmd_DEFINEKEY[]		= "CD8E021C28FA21xxxx";
char cmd_DELAYVAL[]			= "DDE506xxCDxxxxDDE1";
char cmd_DELAYVAR[]			= "DDE53Axxxx47CDxxxxDDE1";
char cmd_DETECTOBJ[]		= "CDxxxx32xxxx";
char cmd_DISPLAYVAR[]		= "3AxxxxCDxxxx";
char cmd_DISPLAYDBLVAR[]	= "3Axxxx01xxxxCDxxxxCDxxxx";
char cmd_DISPLAYTRPVAR[]	= "3Axxxx01xxxxCDxxxxCDxxxx";
char cmd_DISPLAYSECVAR[]	= "3Axxxx571E3CCDxxxx";
char cmd_DIVVAR2[]			= "3AxxxxCB3F32xxxx";
char cmd_DIVVAR4[]			= "3Axxxx1F1FE63F32xxxx";
char cmd_DIVVAR8[]			= "3Axxxx1F1F1FE61F32xxxx";
char cmd_DIVVAR16[]			= "3Axxxx1F1F1F1FE60F32xxxx";
char cmd_DIVVAR32[]			= "3Axxxx070707E60732xxxx";
char cmd_DIVVAR64[]			= "3Axxxx0707E60332xxxx";
char cmd_DIVVAR128[]		= "3Axxxx07E60132xxxx";
char cmd_DIVVARVAL[]		= "3Axxxx573Exx5FCDxxxx7A32xxxx";
char cmd_DIVVARVAR[]		= "3Axxxx573Axxxx5FCDxxxx7A32xxxx";
char cmd_DIVVARSPRVAR[]		= "3Axxxx57DD7Exx5FCDxxxx7A32xxxx";
char cmd_DIVSPRVAR2[]		= "DD7ExxCB3FDD77xx";
char cmd_DIVSPRVAR4[]		= "DD7Exx1F1FE63FDD77xx";
char cmd_DIVSPRVAR8[]		= "DD7Exx1F1F1FE61FDD77xx";
char cmd_DIVSPRVAR16[]		= "DD7Exx1F1F1F1FE60FDD77xx";
char cmd_DIVSPRVAR32[]		= "DD7Exx070707E607DD77xx";
char cmd_DIVSPRVAR64[]		= "DD7Exx0707E603DD77xx";
char cmd_DIVSPRVAR128[]		= "DD7Exx07E601DD77xx";
char cmd_DIVSPRVARVAL[]		= "DD7Exx573Exx5FCDxxxx7ADD77xx";
char cmd_DIVSPRVARVAR[]		= "DD7Exx573Axxxx5FCDxxxx7ADD77xx";
char cmd_DIVSPRVARSPRVAR[]	= "DD7Exx57DD7Exx5FCDxxxx7ADD77xx";
char cmd_ENDGAME[]			= "21xxxx74";
char cmd_ENDREPEAT[]		= "21xxxx35C2xxxx";
char cmd_ENDSPRITE[]		= "DD2Axxxx";
char cmd_EXPLVAR[]			= "3AxxxxCDxxxx";
char cmd_EXPLVAL[]			= "3ExxCDxxxx";
char cmd_FALL[]				= "C3xxxx";
//char cmd_GETBLKZEROZERO[]	= "210000CDxxxx";
//char cmd_GETBLKZEROVAL[]	= "21xxxx22xxxxCDxxxx";
char cmd_GETBLKZEROVAR[]	= "26003Axxxx6F";
char cmd_GETBLKZEROSPRVAR[]	= "2600DD7Exx6F";
char cmd_GETBLKVARZERO[]	= "3Axxxx67AF6F";
char cmd_GETBLKVARVAL[]		= "3Axxxx673Exx";
char cmd_GETBLKVARVAR[]		= "3Axxxx673Axxxx";
char cmd_GETBLKVARSPRVAR[]	= "3Axxxx67DD7Exx";
//char cmd_GETBLKVALZERO[]	= "2100xx";
char cmd_GETBLKVALVAL[]		= "21xxxx22xxxxCDxxxx32xxxx";
char cmd_GETBLKVALVAR[]		= "26xx3Axxxx6F22";
char cmd_GETBLKVALSPRVAR[]	= "26xxDD7Exx6F";
char cmd_GETBLKSPRVARZERO[]	= "DD7Exx67AF6F22xxxxCD";
char cmd_GETBLKSPRVARVAL[]	= "DD7Exx673Exx6F22xxxxCD";
char cmd_GETBLKSPRVARVAR[]	= "DD7Exx673Axxxx6F22xxxxCD";
char cmd_GETBLKSPRVARSPRVAR[]	= "DD7Exx67DD7Exx6F22xxxxCD";
char cmd_GETBLOCKS[]		= "CDxxxx";
char cmd_GETRANDOMVAR[]		= "3Axxxx57CDxxxx67CDxxxx7C32xxxx";
char cmd_GETRANDOMVAL[]		= "3Exx57CDxxxx67CDxxxx7C32xxxx";
char cmd_GETVAR[]			= "3AxxxxCDxxxx";
char cmd_GETVAL[]			= "3ExxCDxxxx";
char cmd_IFGOTZERO[]		= "AFCDxxxxDAxxxx";
char cmd_IFGOTVAR[]			= "3AxxxxCDxxxxDAxxxx";
char cmd_IFGOTVAL[]			= "3ExxCDxxxxDAxxxx";
char cmd_IFVARZERO[]		= "AF21xxxxBE";
char cmd_IFSPRVARZERO[]		= "AFDDBExx";
char cmd_IFVARVAR[]			= "3Axxxx21xxxxBE";
char cmd_IFSPRVARVAR[]		= "3AxxxxDDBExx";
char cmd_IFVARSPRVAR[]		= "DDxxxx21xxxxBE";
char cmd_IFSPRVARSPRVAR[]	= "DD7ExxDDBExx";
char cmd_IFVARVAL[]			= "3Exx21xxxxBE";
char cmd_IFSPRVARVAL[]		= "3ExxDDBExx";
char cmd_IFKEY[]			= "3AxxxxE6xxCAxxxx";
char cmd_IFKEYOPTION[]		= "3AxxxxCDxxxxDAxxxx";
char cmd_INKZERO[]			= "AFE6074F218D5C7EE6F8B177";
char cmd_INKVAR[]			= "3AxxxxE6074F218D5C7EE6F8B177";
char cmd_INKVAL[]			= "3ExxE6074F218D5C7EE6F8B177";
char cmd_JUMPVAL[]			= "3ExxCDxxxx";
char cmd_JUMPVAR[]			= "3AxxxxCDxxxx";
char cmd_KILL[]             = "21xxxx74";
char cmd_LADDERABOVE[]		= "CDxxxxC2xxxx";
char cmd_LADDERBELOW[]		= "CDxxxxC2xxxx";
char cmd_LASERZERO[]		= "AFCDxxxx";
char cmd_LASERVAL[]			= "3ExxCDxxxx";
char cmd_LASERVAR[]			= "3AxxxxCDxxxx";
char cmd_LASERSPRVAR[]		= "DD7ExxCDxxxx";
char cmd_LETVAREQZERO[]		= "AF32xxxx";
char cmd_LETVAREQVAR[]		= "3Axxxx32xxxx";
char cmd_LETVAREQSPRVAR[]	= "DD7Exx32xxxx";
char cmd_LETVAREQVAL[]		= "3Exx32xxxx";
char cmd_LETSPRVAREQZERO[]	= "AFDD77xx";
char cmd_LETSPRVAREQVAR[]	= "3AxxxxDD77xx";
char cmd_LETSPRVAREQSPRVAR[]= "DD7ExxDD77xx";
char cmd_LETSPRVAREQVAL[]	= "3ExxDD77xx";
char cmd_MESSAGEZERO[]		= "AFCDxxxx";
char cmd_MESSAGEVAL[]		= "3ExxCDxxxx";
char cmd_MESSAGEVAR[]		= "3AxxxxCDxxxx";
char cmd_MULVAR2[]			= "3Axxxx8732xxxx";
char cmd_MULVAR3[]			= "3Axxxx57878232xxxx";
char cmd_MULVAR4[]			= "3Axxxx878732xxxx";
char cmd_MULVAR8[]			= "3Axxxx87878732xxxx";
char cmd_MULVAR16[]			= "3Axxxx8787878732xxxx";
char cmd_MULVAR32[]			= "3Axxxx0F0F0FE6E032xxxx";
char cmd_MULVAR64[]			= "3Axxxx0F0FE6C032xxxx";
char cmd_MULVAR128[]		= "3Axxxx0FE68032xxxx";
char cmd_MULVARVAL[]		= "3Axxxx573Exx67CDxxxx7D32xxxx";
char cmd_MULVARVAR[]		= "3Axxxx573Axxxx67CDxxxx7D32xxxx";
char cmd_MULVARSPRVAR[]		= "3Axxxx57DD7Exx67CDxxxx7D32xxxx";
char cmd_MULSPRVAR2[]		= "DD7Exx87DD77xx";
char cmd_MULSPRVAR3[]		= "DD7Exx578782DD77xx";
char cmd_MULSPRVAR4[]		= "DD7Exx8787DD77xx";
char cmd_MULSPRVAR8[]		= "DD7Exx878787DD77xx";
char cmd_MULSPRVAR16[]		= "DD7Exx87878787DD77xx";
char cmd_MULSPRVAR32[]		= "DD7Exx0F0F0FE6E0DD77xx";
char cmd_MULSPRVAR64[]		= "DD7Exx0F0FE6C0DD77xx";
char cmd_MULSPRVAR128[]		= "DD7Exx0FE680DD77xx";
char cmd_MULSPRVARVAL[]		= "DD7Exxx573Exx67CDxxxx7DDD77xx";
char cmd_MULSPRVARVAR[]		= "DD7Exx573Axxxx67CDxxxx7DDD77xx";
char cmd_MULSPRVARSPRVAR[]	= "DD7Exx57DD7Exx67CDxxxx7DDD77xx";
char cmd_NEXTLEVEL[]		= "21xxxx74";
char cmd_OTHER[]			= "DD2Axxxx";
char cmd_PAPERZERO[]		= "AF171717E6384F21";
char cmd_PAPERVAL[]			= "3Exx171717E6384F21";
char cmd_PAPERVAR[]			= "3Axxxx171717E6384F21";
char cmd_PRINTMODEZERO[]	= "AF32xxxx";
char cmd_PRINTMODEVAL[]		= "3Exx32xxxx";
char cmd_PRINTMODEVAR[]		= "3Axxxx32xxxx";
char cmd_PRINTZERO[]		= "AFCDxxxx";
char cmd_PRINTVAL[]			= "3ExxCDxxxx";
char cmd_PUTBLOCKZERO[]		= "21xxxx22xxxx2Axxxx22xxxxAF";
char cmd_PUTBLOCKVAL[]		= "21xxxx22xxxx2Axxxx22xxxx3Exx";
char cmd_PUTBLOCKVAR[]		= "21xxxx22xxxx2Axxxx22xxxx3Axxxx";
char cmd_PUT[]				= "CDxxxx";
char cmd_RANDOMIZEVAL[]		= "3Exx32xxxx";
char cmd_RANDOMIZEVAR[]		= "3Axxxx32xxxx";
char cmd_READVAR[]			= "CDxxxx32xxxx";
char cmd_READSPRVAR[]		= "CDxxxxDD77xx";
char cmd_REDRAW[]			= "CDxxxx";
char cmd_REMOVE[]			= "DD3605FF";
char cmd_REMOBJZERO[]		= "AFCDxxxx";
char cmd_REMOBJVAL[]		= "3ExxCDxxxx";
char cmd_REMOBJVAR[]		= "3AxxxxCDxxxx";
char cmd_REMOBJSPRVAR[]		= "DD7ExxCDxxxx";
char cmd_REPEATZERO[]		= "AF32xxxx";					// Test before LETVAREQVAR
char cmd_REPEATVAR[]		= "3Axxxx32815C";				// Test before LETVAREQVAR
char cmd_REPEATVAL[]		= "3Exx32xxxx";					// Test before LETVAREQVAL!!
char cmd_RESTART[]			= "21xxxx3601";
char cmd_RESTORE[]			= "DD3610FF";
char cmd_SCOREVAR[]         = "3Axxxx6F2600CDxxxx";
char cmd_SCOREVAL[]         = "21xxxxCDxxxx";
char cmd_SCREENL[]			= "CDxxxx";
char cmd_SCREENR[]			= "CDxxxx";
char cmd_SCREENU[]			= "CDxxxx";
char cmd_SCREEND[]			= "CDxxxx";
char cmd_SHOWBONUS[]		= "21xxxx0606CDxxxx";
char cmd_SHOWHIGHSCORE[]	= "21xxxx0606CDxxxx";
char cmd_SHOWSCORE[]		= "21xxxx0606CDxxxx";
char cmd_SPAWNVARVAR[]		= "3Axxxx4F3Axxxx47CDxxxx";
char cmd_SPAWNVARVAL[]		= "3Axxxx4F3Exx47CDxxxx";
char cmd_SPAWNVALVAR[]		= "0Exx3Axxxx47CDxxxx";
char cmd_SPAWNVARZERO[]		= "3Axxxx4FAF47CDxxxx";
char cmd_SPAWNVALVAL[]		= "01xxxxCDxxxx";
char cmd_SPAWNED[]			= "DD2Axxxx";
char cmd_SPRITEDOWN[]		= "DD3408DD3408";
char cmd_SPRITEINKVAR[]		= "3AxxxxE6074FCDxxxx";
char cmd_SPRITEINKVAL[]		= "3ExxE6074FCDxxxx";
char cmd_SPRITELEFT[]		= "DD3509DD3509";
char cmd_SPRITERIGHT[]		= "DD3409DD3409";
char cmd_SPRITEUP[]			= "DD3508DD3508";
char cmd_STARZERO[]			= "AF4FCDxxxxE603CCxxxx";
char cmd_STARVAL[]			= "3Exx4FCDxxxxE603CCxxxx";
char cmd_STARVAR[]			= "3Axxxx4FCDxxxxE603CCxxxx";
char cmd_STARSPRVAR[]		= "DD7Exx4FCDxxxxE603CCxxxx";
char cmd_STOPFALL[]			= "CDxxxx";
char cmd_TABLEFALL[]		= "CDxxxx";
char cmd_TABLEJUMP[]		= "CDxxxx";

char cmd_TICKERZERO[]		= "21xxxx36C9";
char cmd_TICKERVALVAL[]		= "01xxxxCDxxxx";
char cmd_TICKERVALVAR[]		= "3Exx473Axxxx4FCD";

char cmd_TICKERVARZERO[]	= "3Axxxx47AF4FCD";
char cmd_TICKERVARVAL[]		= "3Axxxx473Exx4FCD";
char cmd_TICKERVARVAR[]		= "3Axxxx473Axxxx4FCD";

char cmd_TRAIL[]			= "CDxxxx";
char cmd_UNDOSPRITEMOVE[]	= "DD7E03DD7708DD7E04DD7709";
char cmd_WAITKEY[]			= "CDxxxx";						// Test before READVAR and READSPRVAR!!
char cmd_ZEROBONUS[]		= "21xxxx010500363011";

//char cmd_WHILESPRVARNEVAR[]	= "3AxxxxDDBExxCAxxxx";

// VARIABLES -----VAR1----------VAR2----
// 		SPRVAR	= DDBExx		DD7Exx	
// 		VAR		= 21xxxxBE		3Axxxx		
// 		VAL		= 3Exx
// 		ZERO	= AF
// OPERATORS ---------------------------
// 		LT		= DAxxxxCAxxxx
//		LTEQ	= DAxxxx
//		EQ		= C2xxxx
//		GTEQ	= 28xxD2xxxx
//		GT		= D2xxxx
//		NE		= CAxxxx

char cmd_IFWHILEVAR[]		= "3Axxxx";
char cmd_IFWHILESPRVAR[]	= "DD7Exx";
char cmd_IFWHILEVAL[]		= "3Exx";
char cmd_IFWHILEZERO[]		= "AF";

const char *EventName[]={
	"EVENT PLAYER",
	"EVENT SPRITETYPE1",
	"EVENT SPRITETYPE2",
	"EVENT SPRITETYPE3",
	"EVENT SPRITETYPE4",
	"EVENT SPRITETYPE5",
	"EVENT SPRITETYPE6",
	"EVENT SPRITETYPE7",
	"EVENT SPRITETYPE8",
	"EVENT INITSPRITE",
	"EVENT MAINLOOP1",
	"EVENT MAINLOOP2",
	"EVENT INTROMENU",
	"EVENT GAMEINIT",
	"EVENT RESTARTSCREEN",
	"EVENT FELLTOOFAR",
	"EVENT KILLPLAYER",
	"EVENT LOSTGAME",
	"EVENT COMPLETEDGAME",
	"EVENT NEWHIGHSCORE",
	"EVENT COLLECTBLOCK",
	NULL};

const char *VARstring[]={
	"TOPEDGE",
	"LEFTEDGE",
	"BOTTOMEDGE",	
	"RIGHTEDGE",
	"SCREEN",
	"LIVES",
	"A",
	"B",
	"C",
	"D",
	"E",
	"F",
	"G",
	"H",
	"I",
	"J",
	"K",
	"L",
	"M",
	"N",
	"O",
	"P",
	"Q",
	"R",
	"S",
	"T",
	"U",
	"V",
	"W",
	"Z",
	"CONTROL",
	"LINE",
	"COLUMN",
	"CLOCK",
	"RND",
	"OBJ",
	"OPT",
	"BLOCK",
	NULL};

const char *SPRVARstring[]={
	"TYPE",
	"IMAGE",
	"FRAME",
	"Y",
	"X",
	"TYPE",
	"IMAGE",
	"FRAME",
	"Y",
	"X",
	"DIRECTION",
	"SETTINGA",
	"SETTINGB",
	"AIRBORNE",
	"JUMPSPEED",
	"PTR1",
	"PTR2",
	NULL};

const char *OPstring[]={
	"???",
	"<",
	"<=",
	"=",
	">=",
	">",
	"<>",
	NULL};

const char *KeyString[]={
	"",
	"RIGHT",
	"LEFT",
	"DOWN",
	"UP",
	"FIRE",
	"FIRE2",
	"FIRE3",
	NULL};

const char *BlockType[]={
	"EMPTYBLOCK",
	"PLATFORMBLOCK",
	"WALLBLOCK",
	"LADDERBLOCK",
	"FODDERBLOCK",
	"DEADLYBLOCK",
	"CUSTOMBLOCK",
	"WATERBLOCK",
	"COLLECTABLE",
	NULL};


