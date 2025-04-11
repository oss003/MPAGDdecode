// ********************************************************************
// MPAGD decode, convert an MPAGD file into an AGD ASCII file
// ********************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "MPAGDdecode.h"
#include "MPAGDcommands.c"
#include "MPAGDutils.c"
#include "MPAGDgraphics.c"
extern int AdvMode;


// Definitions
 

// Prototypes. 

// global variables   
FILE *fpSource;
FILE *fpDest;

unsigned char *cSrc;
unsigned char *cBuff;

int endif_ptr;
unsigned long int lSize;
unsigned long int data_ptr;
unsigned long int engine_addr;
unsigned long int event_ptr;
unsigned long int offset;
unsigned long int joyaddr;
unsigned int DataByte;
unsigned int IFstack[1000];
unsigned int WHILEstack[1000];
unsigned int DATAstack[1000];
unsigned int Event[22];
int keys;
int iflag;
int debug = 0;
int AdvMode;

char MSG[255][255];
int NMEptr[100];

int Events;


//===============================================================
// Main routine
//===============================================================

int main( int argc, const char* argv[] )
{
	unsigned int Address;
	short int d, i;
	char szSourceFilename[ 128 ];
	char szDestFilename[ 128 ] = "";
	char cChar[64];
	char *ext;
	
//===============================================================
// GENERAL
//===============================================================

	endif_ptr = 0;

//
// ----- Handle parameters ----- 
//

	if (argc > 1)
	{
		for (i = 2; i < argc; ++i)
		{
		  d = tolower(argv[i][0]);
		  if ( d == 'd' || d == 'D') debug = 1;
		}
	} else {
		puts ("Usage: MPAGDdecode <MPAGD snapshot>");
		exit (1);
	}

//
// ----- Print program info ------ 
//
	sprintf (Dummy,"==============================================================\n");
	PrtReport(Dummy,2);
	sprintf (Dummy,"MPAGD v0.7.10 decoder v1.6 KC 2025\n");
	PrtReport(Dummy,2);
	sprintf (Dummy,"; Sourcefile: %s.sna\n",argv[1]);
	PrtReport(Dummy,2);
	sprintf (Dummy,"==============================================================\n\n");
	PrtReport(Dummy,2);

//
// ----- open source project file. ----- 
//

	
	sprintf( szSourceFilename, "%s.sna", argv[ 1 ] );
	fpSource = fopen( szSourceFilename, "rb" );

	strcpy(szDestFilename,szSourceFilename);
	ext = strstr(szDestFilename,".sna");
	if (ext != NULL) {
		strcpy(ext,"-org.agd");
	}
	if ( !fpSource )
	{
       	fprintf( stderr, "Unable to read snapshot file: %s\n", szSourceFilename );
		exit( 1 );
	}

//
// Establish size project file. 
//

	fseek( fpSource, 0, SEEK_END );
	lSize = ftell( fpSource );
	rewind( fpSource );
	sprintf(Dummy, "File length  : %d bytes\n\n", lSize );
	PrtReport(Dummy,3);
	
//
// Allocate buffer for the snapshot. 
//

	cSrc = ( char* )malloc( lSize);
	cBuff = cSrc;
	if ( !cSrc )
	{
		fputs( "Out of memory\n", stderr );
		exit( 1 );
	}

//
// Read source file into the buffer. 
//

	lSize = fread( cBuff, 1, lSize, fpSource );

//===============================================================
// DECODE and read parameters
//===============================================================

//
// Set Engine addresses + data pointer to first event
//

	Init();
	Info();
	AdvMode		= FindAddress("772373237223F1772322");

// Locate start of eventdata

	Address = FindAddress("C5DD7E003C20") - SnapshotOffset - 20;
	data_ptr = cBuff[Address] + (cBuff[Address + 1] << 8) - SnapshotOffset ;
	sprintf(Dummy,"EventData:%04X-%04X\n",data_ptr, data_ptr + SnapshotOffset);
	PrtReport(Dummy,3);
	
// Open output file

    fpDest = fopen(szDestFilename, "w");
    if (fpDest == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
	sprintf(Dummy,";----------------------------------------------------------------\n");
	PrtReport(Dummy,0);
	sprintf (Dummy,"; MPAGD v0.7.10 decoder v1.6 KC 2025\n");
	PrtReport(Dummy,0);
	sprintf (Dummy,"; Sourcefile: %s.sna\n",argv[1]);
	PrtReport(Dummy,0);
	if (AdvMode > 0){
		PrtReport(";\n; Adventuremode used\n",2);
	}	
	sprintf(Dummy,";----------------------------------------------------------------\n");
	PrtReport(Dummy,0);
	
//
// Start decoding
//

	GraphDecode();

	event_ptr = data_ptr;
	
	for (Events = 0; Events < 21; Events++){
		
 if (ident != 0){
			d=ident;
			sprintf(Dummy,"     ENDIF\n");
			for (i=0; i<d; i++){
					PrtReport(Dummy,1);
			}
		}
		
		sprintf(Dummy,"\n;----------------------------------------------------------------\n");
		PrtReport(Dummy,0);
		sprintf(Dummy,"%s\n",EventName[Events]);
		PrtReport(Dummy,0);
		sprintf(Dummy,";----------------------------------------------------------------\n");
		PrtReport(Dummy,0);

		ident = 0;
		while (event_ptr != Event[Events+1] - SnapshotOffset){

			iflag = 0;
			CheckDATAstack (event_ptr + SnapshotOffset);
			CheckWHILEstack (event_ptr + SnapshotOffset);
			CheckIFstack (event_ptr + SnapshotOffset);
			
			switch(cBuff[event_ptr]){
				case 0x01:
					if (tst_SPAWNVALVAL())        break;
					if (tst_TICKERVALVAL())		  break;
					if (debug == 1) printf("    %02X-%04X\n", cBuff[event_ptr],event_ptr + SnapshotOffset);
					event_ptr++;
					break;
				case 0x06:
					if (tst_IFCOLLVAL())          break;
					if (tst_IFCUSTOM())           break;
					if (tst_IFDEADLY())           break;
					if (debug == 1) printf("    %02X-%04X\n", cBuff[event_ptr],event_ptr + SnapshotOffset);
					event_ptr++;
					break;
				case 0x0e:
					if (tst_ADDVALTOVAR())        break;
					if (tst_SUBVALFROMVAR())	  break;
					if (tst_SUBVALFROMSPRVAR())   break;
					if (tst_ADDVALTOSPRVAR())     break;
					if (tst_SPAWNVALVAR())        break;
					if (debug == 1) printf("    %02X-%04X\n", cBuff[event_ptr],event_ptr + SnapshotOffset);
					event_ptr++;
					break;
				case 0x21:
					if (tst_RESTART())            break;
					if (tst_PLOTVALVAL())		  break;
					if (tst_SOUNDZERO())		  break;
					if (tst_SOUNDVAL())			  break;
					if (tst_TICKERZERO())		  break;
					if (tst_ENDREPEAT())          break;
					if (tst_PUTBLOCKZERO())       break;
					if (tst_PUTBLOCKVAL())        break;
					if (tst_PUTBLOCKVAR())        break;
					if (tst_PUTBLOCKSPRVAR())     break;
					if (tst_ATVALVAL())           break;
					if (tst_SHOWBONUS())          break;
					if (tst_SHOWSCORE())          break;
					if (tst_SHOWHIGHSCORE())      break;
					if (tst_SCOREVAL())           break;
					if (tst_GETBLKVALVAL())       break;
					if (tst_NEXTLEVEL())          break;
					if (tst_ENDGAME())            break;
					if (tst_KILL())               break;
					if (tst_ZEROBONUS())          break;
					if (debug == 1) printf("    %02X-%04X\n", cBuff[event_ptr],event_ptr + SnapshotOffset);
					event_ptr++;
					break;
				case 0x26:
					if (tst_PLOTVALVAR())		  break;
					if (tst_RESTORE2())			  break;
					if (tst_PLOTVALSPRVAR())	  break;
					if (tst_GETBLKVALVAR())       break;
					if (tst_GETBLKVALSPRVAR())    break;
					if (tst_GETBLKZEROSPRVAR())	  break; 
					if (tst_GETBLKVALSPRVAR())	  break;
					if (debug == 1) printf("    %02X-%04X\n", cBuff[event_ptr],event_ptr + SnapshotOffset);
					event_ptr++;
					break;
				case 0x2e:
					if (tst_ATVALVAR())           break;
					if (tst_ATZEROSPRVAR())		  break;
					if (tst_ATVALSPRVAR())		  break;
					if (debug == 1) printf("    %02X-%04X\n", cBuff[event_ptr],event_ptr + SnapshotOffset);
					event_ptr++;
					break;
				case 0x3a:
					if (tst_RANDOMIZEVAR())		  break;
					if (tst_SOUNDVAR())			  break;
					if (tst_PLOTVARZERO())		  break;
					if (tst_PLOTVARVAL())		  break;
					if (tst_PLOTVARVAR())		  break;
					if (tst_PLOTVARSPRVAR())	  break;
					if (tst_IFWHILE(1))           break;
					if (tst_CLUTVAR())			  break;
					if (tst_ATVARZERO())		  break;
					if (tst_ATVARSPRVAR())		  break;
					if (tst_TICKERVARZERO())	  break;
					if (tst_TICKERVARVAL())		  break;
					if (tst_TICKERVARVAR())		  break;
					if (tst_STARVAR())			  break;
					if (tst_MENUVAR())			  break;
					if (tst_INVVAR())			  break;
					if (tst_CRASHVAR())           break;
					if (tst_MULVAR())             break;
					if (tst_DIVVAR())             break;
					if (tst_JUMPVAR())            break;
					if (tst_PRINTMODEVAR())       break;
					if (tst_PAPERVAR())           break;
					if (tst_SPRITEINKVAR())       break;
					if (tst_IFGOTVAR())           break;
					if (tst_INKVAR())             break;
					if (tst_GETRANDOMVAR())       break;
					if (tst_EXPLVAR())            break;
					if (tst_GETVAR())             break;
					if (tst_COLOURVAR())          break;
					if (tst_IFCOLLVAR())          break;
					if (tst_DISPLAYVAR())         break;
					if (tst_DISPLAYDBLVAR())      break;
					if (tst_DISPLAYTRPVAR())      break;
					if (tst_DISPLAYSECVAR())      break;
					if (tst_REPEATVAR())          break;
					if (tst_LETVAREQVAR())        break;
					if (tst_IFKEY())              break;
					if (tst_IFKEYOPTION())        break;
					if (tst_BEEPVAR())            break;
					if (tst_ATVARVAL())           break;
					if (tst_ATVARVAR())           break;
					if (tst_BORDERVAR())          break;
					if (tst_GETBLKVARZERO())	  break;
					if (tst_GETBLKVARVAR())       break;
					if (tst_GETBLKVARVAL())       break;
					if (tst_GETBLKVARSPRVAR())	  break;
					if (tst_LETSPRVAREQVAR())     break;
					if (tst_SUB1FROMVAR())        break;
					if (tst_SUBVARFROMVAR())	  break;
					if (tst_SUBVARFROMSPRVAR())   break;
					if (tst_ADDVARTOVAR())        break;
					if (tst_ADDVARTOSPRVAR())     break;
					if (tst_SPAWNVARVAR())        break;
					if (tst_SPAWNVARVAL())        break;
					if (tst_SPAWNVARZERO())       break;
					if (tst_ADD1TOVAR())          break;
					if (tst_SCOREVAR())           break;
					if (tst_CHRVAR())             break;
					if (tst_MESSAGEVAR())         break;
					if (tst_LASERVAR())           break;
					if (tst_REMOBJVAR())          break;
					if (tst_PUT())				  break;
					if (debug == 1) printf("    %02X-%04X\n", cBuff[event_ptr],event_ptr + SnapshotOffset);
					event_ptr++;
					break;
				case 0x3e:
					if (tst_RANDOMIZEVAL())		  break;
					if (tst_IFWHILE(2))           break;
					if (tst_CLUTVAL())			  break;
					if (tst_TICKERVALVAR())		  break;
					if (tst_DIGVAL())			  break;
					if (tst_MENUVAL())			  break;
					if (tst_INVVAL())			  break;
					if (tst_CRASHZERO())          break;
					if (tst_CRASHVAL())           break;
					if (tst_PRINTMODEVAL())       break;
					if (tst_STARVAL())            break;
					if (tst_PAPERVAL())           break;
					if (tst_IFGOTVAL())           break;
					if (tst_INKVAL())             break;
					if (tst_EXPLVAL())            break;
					if (tst_GETRANDOMVAL())       break;
					if (tst_GETVAL())             break;
					if (tst_SPRITEINKVAL())       break;
					if (tst_COLOURVAL())          break;
					if (tst_LETSPRVAREQVAL())     break;
					if (tst_ANIMVSLOW())          break;
					if (tst_ANIMSLOW())           break;
					if (tst_ANIMMED())            break;
					if (tst_ANIMBACKVSLOW())      break;
					if (tst_ANIMBACKSLOW())       break;
					if (tst_ANIMBACKMED())        break;
					if (tst_BEEPVAL())            break;
					if (tst_CHRVAL())             break;
					if (tst_BORDERVAL())          break;
					if (tst_REPEATVAL())          break;
					if (tst_LETVAREQVAL())        break;
					if (tst_JUMPVAL())            break;
					if (tst_PRINTVAL())           break;
					if (tst_LASERVAL())           break;
					if (tst_REMOBJVAL())          break;
					if (tst_PUT())				  break;
					if (debug == 1) printf("    %02X-%04X\n", cBuff[event_ptr],event_ptr + SnapshotOffset);
					event_ptr++;
					break;
				case 0xaf:
					if (tst_IFWHILE(3))           break;
					if (tst_STARZERO())			  break;
					if (tst_CLUTZERO())			  break;
					if (tst_JUMPZERO())		      break;
					if (tst_MENUZERO())			  break;
					if (tst_INVZERO())			  break;
					if (tst_DIGZERO())			  break;
					if (tst_COLOURZERO())         break;
					if (tst_REPEATZERO())         break;
					if (tst_PAPERZERO())          break;
					if (tst_PRINTMODEZERO())      break;
					if (tst_LETVAREQZERO())       break;
					if (tst_IFGOTZERO())          break;
					if (tst_ANIMATE())            break;
					if (tst_ANIMBACK())			  break;
					if (tst_LETSPRVAREQZERO())    break;
					if (tst_BORDERZERO())         break;
					if (tst_PRINTZERO())          break;
					if (tst_INKZERO())            break;
					if (tst_LASERZERO())          break;
					if (tst_REMOBJZERO())         break;
					if (tst_PUT())				  break;
					if (debug == 1) printf("    %02X-%04X\n", cBuff[event_ptr],event_ptr + SnapshotOffset);
					event_ptr++;
					break;
				case 0xc9:
					if (tst_EXIT(Events))         break;
					if (debug == 1) printf("    %02X-%04X\n", cBuff[event_ptr],event_ptr + SnapshotOffset);
					event_ptr++;
					break;
				case 0xcd:
					if (tst_WAITKEY())            break;
					if (tst_SILENCE())			  break;
					if (tst_TRAIL())			  break;
					if (tst_DEFINEKEY())          break;
					if (tst_GETBLOCKS())          break;
					if (tst_DETECTOBJ())          break;
					if (tst_CANGOUP())            break;
					if (tst_CANGODOWN())          break;
					if (tst_CANGOLEFT())          break;
					if (tst_CANGORIGHT())         break;
					if (tst_REDRAW())             break;
					if (tst_ADDBONUS())           break;
					if (tst_READVAR())            break;
					if (tst_READSPRVAR())         break;
					if (tst_CLW())                break;
					if (tst_CLS())                break;
					if (tst_SCREENDOWN())         break;
					if (tst_SCREENLEFT())         break;
					if (tst_SCREENRIGHT())        break;
					if (tst_SCREENUP())           break;
					if (tst_FALL())               break;
					if (tst_LADDERABOVE())        break;
					if (tst_LADDERBELOW())        break;
					if (tst_BONUSVAL())           break;
					if (tst_BONUSVAR())           break;
					if (tst_IFCOLLBULLET())       break;
					if (tst_STOPFALL())			  break;
					if (tst_TABLEFALL())		  break;
					if (tst_TABLEJUMP())          break;
					if (debug == 1) printf("    %02X-%04X\n", cBuff[event_ptr],event_ptr + SnapshotOffset);
					event_ptr++;
					break;
				case 0xdd:
					if (tst_IFWHILE(4))           break;
					if (tst_REPEATSPRVAR())		  break;
					if (tst_SOUNDSPRVAR())		  break;
					if (tst_PLOTSPRVARZERO())	  break;
					if (tst_PLOTSPRVARVAL())	  break;
					if (tst_PLOTSPRVARVAR())	  break;
					if (tst_PLOTSPRVARSPRVAR())	  break;
					if (tst_BEEPSPRVAR())		  break;
					if (tst_ATSPRVARZERO())		  break;
					if (tst_ATSPRVARVAL())		  break;
					if (tst_ATSPRVARVAR())		  break;
					if (tst_CLUTSPRVAR())		  break;
					if (tst_JUMPSPRVAR())		  break;
					if (tst_STARSPRVAR())		  break;
					if (tst_MENUSPRVAR())		  break;
					if (tst_INVSPRVAR())		  break;
					if (tst_UNDOSPRITEMOVE())	  break;
					if (tst_CRASHSPRVAR())        break;
					if (tst_MULSPRVAR())          break;
					if (tst_DIVSPRVAR())          break;
					if (tst_IFCOLLSPRVAR())       break;
					if (tst_SPRITEUP())           break;
					if (tst_SPRITEDOWN())         break;
					if (tst_SPRITELEFT())         break;
					if (tst_SPRITERIGHT())        break;
					if (tst_ENDSPRITE())          break;
					if (tst_SPAWNED())            break;
					if (tst_LETVAREQSPRVAR())     break;
					if (tst_LETSPRVAREQSPRVAR())  break;
					if (tst_ADD1TOSPRVAR())       break;
					if (tst_ADDSPRVARTOVAR())     break;
					if (tst_ATSPRVARSPRVAR())	  break;
					if (tst_SUBSPRVARFROMVAR())   break;
					if (tst_SUB1FROMSPRVAR())     break;
					if (tst_REMOVE())             break;
					if (tst_OTHER())              break;
					if (tst_RESTORE1())            break;
					if (tst_DELAYVAL())           break;
					if (tst_DELAYVAR())           break;
					if (tst_LASERSPRVAR())        break;
					if (tst_REMOBJSPRVAR())       break;
					if (tst_GETBLKSPRVARZERO())	  break;
					if (tst_GETBLKSPRVARVAL())	  break;
					if (tst_GETBLKSPRVARVAR())	  break;
					if (tst_GETBLKSPRVARSPRVAR()) break;
					if (tst_PUT())				  break;
					if (debug == 1) printf("    %02X-%04X\n", cBuff[event_ptr],event_ptr + SnapshotOffset);
					event_ptr++;
					break;
				default:
					if (debug == 1) printf("    %02X-%04X\n", cBuff[event_ptr],event_ptr + SnapshotOffset);
					event_ptr++;
			}
		}
	}

// Close output file

	fclose(fpDest);
	
	return;
}





















