// Decode graphics data in MPAGD file

extern unsigned char *cBuff;
extern int ScrFormat;
extern int keys;

extern int numblk;
extern int chgfx;
extern int bcol;
extern int bprop;
extern int font;

extern int numspr;
extern int sprgfx;
extern int frmlst;

extern int nmedat;
extern int NMEptr[100];

void GraphDecode(){

int OffsetPtr = SnapshotOffset;
int ScrDataPtr;
int scrlen;
int i;
int j;
int k;
int nr;
int blk;
int width;
int height;

// DEFINEWINDOW

	printf("\nDEFINEWINDOW\t%d %d %d %d\n", 
		cBuff[ScrFormat - SnapshotOffset],
		cBuff[ScrFormat - SnapshotOffset + 1],
		cBuff[ScrFormat - SnapshotOffset + 2],
		cBuff[ScrFormat - SnapshotOffset + 3]);
	
	height = cBuff[ScrFormat - SnapshotOffset + 2];
	width = cBuff[ScrFormat - SnapshotOffset + 3];

// DEFINECONTROLS

	printf("\nDEFINECONTROLS\t"); 
	printf("\'%c\' ",ConvertKey(cBuff[keys - SnapshotOffset + 3]));
	printf("\'%c\' ",ConvertKey(cBuff[keys - SnapshotOffset + 2]));
	printf("\'%c\' ",ConvertKey(cBuff[keys - SnapshotOffset + 1]));
	printf("\'%c\' ",ConvertKey(cBuff[keys - SnapshotOffset]));
	for (i = 4; i < 11; i++){
		printf("\'%c\' ",ConvertKey(cBuff[keys - SnapshotOffset + i]));
	}
	printf ("\n");

// DEFINEMESSAGES

	printf("\nDEFINEMESSAGES\n"); 
	for (i=0; i<nummsg; i++){
		printf("\t\t\"%s\"\n",MSG[i]);
	}
	printf("\n");
	
// DEFINEBLOCK

	for (i = 0; i < numblk; i++){
		printf("DEFINEBLOCK\t%s\n\t\t", BlockType[cBuff[bprop - SnapshotOffset + i]]);
		for (j = 0; j < 8; j++){
				printf("%d ", cBuff[i * 8 + chgfx - SnapshotOffset + j]);
		}
		printf("\n\t\t%d\n\n", cBuff[bcol - SnapshotOffset + i]);
	}

// DEFINESPRITE

	OffsetPtr = sprgfx - SnapshotOffset;
	for (i = 0; i < numspr; i++){
		printf("DEFINESPRITE\t%d\n\t\t", cBuff[frmlst - SnapshotOffset + i*2 + 1]);
		for (j = 0; j < cBuff[frmlst - SnapshotOffset + i*2 + 1]; j++){
			for (k = 0; k < 32; k++){
				printf("%d ", cBuff[OffsetPtr]);
				OffsetPtr++;
				if (k == 15) printf("\n\t\t");
			}
			OffsetPtr += 96;
			printf("\n\t\t");
		}
		printf("\n");
	}
	
// DEFINEOBJECT

	OffsetPtr = objdta - SnapshotOffset;
	for (i = 0; i < numobj; i++){
		printf("DEFINEOBJECT\t%d %d %d %d\n\t\t",
			cBuff[OffsetPtr + 32],
			cBuff[OffsetPtr + 33],
			cBuff[OffsetPtr + 34],
			cBuff[OffsetPtr + 35]
		);
		for (k = 0; k < 32; k++){
			printf("%d ", cBuff[OffsetPtr + k]);
			if (k == 15) printf("\n\t\t");
		}
		OffsetPtr += 39;
		printf("\n\n");
	}

// Read SPRITEPOSITION data

	k = 1;
	j = 0;
	NMEptr[0] = nmedat;
	for (i = 1; i <= numsc; i++){
		while (cBuff[nmedat - SnapshotOffset + j] != 0xff){
			j = j + 4;
		}
		j++;
		NMEptr[i] = nmedat + j;
	}

// DEFINESCREEN

	OffsetPtr = scdat - SnapshotOffset;
	ScrDataPtr = OffsetPtr + numsc * 2;
	for (i = 0; i < numsc; i++){
		scrlen = (cBuff[OffsetPtr + i * 2 + 1]) * 256 + cBuff[OffsetPtr + i * 2] ;
		k = 0;
		printf("DEFINESCREEN\t");
		while (k < width * height){
				if (cBuff[ScrDataPtr] != 0xff){
					printf("%3d ", cBuff[ScrDataPtr]);
					ScrDataPtr++;
					k ++;
					if (k % width == 0){
						printf("\n\t\t");
					}
				} else {
					blk = cBuff[ScrDataPtr + 1];
					nr = cBuff[ScrDataPtr + 2];
					if (nr == 0) nr = 256;
					for (j = 0; j < nr; j++){
						printf("%3d ", blk);
						k ++;
						if (k % width == 0) printf("\n\t\t");
					}
					ScrDataPtr += 3;
					j += 2;
				}
		}
		printf("\n");

// SPRITEPOSITION

		j = NMEptr[i] - SnapshotOffset;
		while (cBuff[j] != 0xff){
			printf ("SPRITEPOSITION\t%d %d %d %d\n",cBuff[j],cBuff[j + 1],cBuff[j + 2],cBuff[j + 3]);
			j = j + 4;
		}
		printf("\n");

	}

// MAP

	printf("MAP\t\tWIDTH %d\n",mapwid);
	printf("\t\tSTARTSCREEN %d\n",mapstart);

	for (i = 0; i < (Event[0] - mapdat - 1) / mapwid - 2; i++){
		printf("\t\t");
		for (j = 0; j < mapwid; j++){
			printf("%3d ",cBuff[mapdat + mapwid + i * mapwid + j - SnapshotOffset]);	
		}
		printf("\n");
	}
	printf("ENDMAP\n\n");

// FONT

	printf("DEFINEFONT\t\t");
	for (i = 0; i < 96; i++){
		for (j = 0; j < 8; j++){
			printf("%d ",cBuff[font - SnapshotOffset + i * 8 + j]);
		}
		printf("\n\t\t");
	}

	return;
}
