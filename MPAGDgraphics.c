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
char *k1, *k2,*k3,*k4;

// DEFINEWINDOW

	sprintf(Dummy,"\nDEFINEWINDOW\t%d %d %d %d\n", 
		cBuff[ScrFormat - SnapshotOffset],
		cBuff[ScrFormat - SnapshotOffset + 1],
		cBuff[ScrFormat - SnapshotOffset + 2],
		cBuff[ScrFormat - SnapshotOffset + 3]);
	PrtReport(Dummy,0);
	height = cBuff[ScrFormat - SnapshotOffset + 2];
	width = cBuff[ScrFormat - SnapshotOffset + 3];

// DEFINECONTROLS

	PrtReport("\nDEFINECONTROLS\t",0); 
	for (i = 0; i < 4; i++){
		sprintf(Dummy,"\'%c\' ",ConvertKey(cBuff[keys - SnapshotOffset + 3 - i]));
		PrtReport(Dummy,0);
	}
	for (i = 4; i < 11; i++){
		sprintf(Dummy,"\'%c\' ",ConvertKey(cBuff[keys - SnapshotOffset + i]));
		PrtReport(Dummy,0);
	}
	PrtReport("\n",0);
	
// DEFINEMESSAGES

	PrtReport("\nDEFINEMESSAGES\n",0); 
	for (i=0; i<nummsg; i++){
		sprintf(Dummy,"\t\t\"%s\"\n",MSG[i]);
		PrtReport(Dummy,0);
	}
	PrtReport("\n",0);
	
// DEFINEBLOCK

	for (i = 0; i < numblk; i++){
		sprintf(Dummy,"DEFINEBLOCK\t%s\n\t\t", BlockType[cBuff[bprop - SnapshotOffset + i]]);
		PrtReport(Dummy,0);
		for (j = 0; j < 8; j++){
			sprintf(Dummy,"%d ", cBuff[i * 8 + chgfx - SnapshotOffset + j]);
			PrtReport(Dummy,0);
		}
		sprintf(Dummy,"\n\t\t%d\n\n", cBuff[bcol - SnapshotOffset + i]);
		PrtReport(Dummy,0);
	}

// DEFINESPRITE

	OffsetPtr = sprgfx - SnapshotOffset;
	for (i = 0; i < numspr; i++){
		sprintf(Dummy,"DEFINESPRITE\t%d\n\t\t", cBuff[frmlst - SnapshotOffset + i*2 + 1]);
		PrtReport(Dummy,0);
		for (j = 0; j < cBuff[frmlst - SnapshotOffset + i*2 + 1]; j++){
			for (k = 0; k < 32; k++){
				sprintf(Dummy,"%d ", cBuff[OffsetPtr]);
				PrtReport(Dummy,0);
				OffsetPtr++;
				if (k == 15) PrtReport("\n\t\t",0);
			}
			OffsetPtr += 96;
			PrtReport("\n\t\t",0);
		}
		PrtReport("\n",0);
	}
	
// DEFINEOBJECT

	OffsetPtr = objdta - SnapshotOffset;
	for (i = 0; i < numobj; i++){
		sprintf(Dummy,"DEFINEOBJECT\t%d %d %d %d\n\t\t",
			cBuff[OffsetPtr + 32],
			cBuff[OffsetPtr + 33],
			cBuff[OffsetPtr + 34],
			cBuff[OffsetPtr + 35]
		);
		PrtReport(Dummy,0);
		for (k = 0; k < 32; k++){
			sprintf(Dummy,"%d ", cBuff[OffsetPtr + k]);
			PrtReport(Dummy,0);
			if (k == 15) PrtReport("\n\t\t",0);
		}
		OffsetPtr += 39;
		PrtReport("\n\n",0);
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
		PrtReport("DEFINESCREEN\t",0);
		while (k < width * height){
				if (cBuff[ScrDataPtr] != 0xff){
					sprintf(Dummy,"%3d ", cBuff[ScrDataPtr]);
					PrtReport(Dummy,0);
					ScrDataPtr++;
					k ++;
					if (k % width == 0)	PrtReport("\n\t\t",0);
				} else {
					blk = cBuff[ScrDataPtr + 1];
					nr = cBuff[ScrDataPtr + 2];
					if (nr == 0) nr = 256;
					for (j = 0; j < nr; j++){
						sprintf(Dummy,"%3d ", blk);
						PrtReport(Dummy,0);
						k ++;
						if (k % width == 0) PrtReport("\n\t\t",0);
					}
					ScrDataPtr += 3;
					j += 2;
				}
//				if (k % width == 0) printf("\n\t\t");
		}
		PrtReport("\n",0);

// SPRITEPOSITION

		j = NMEptr[i] - SnapshotOffset;
		while (cBuff[j] != 0xff){
			sprintf (Dummy,"SPRITEPOSITION\t%d %d %d %d\n",cBuff[j],cBuff[j + 1],cBuff[j + 2],cBuff[j + 3]);
			PrtReport(Dummy,0);
			j = j + 4;
		}
		PrtReport("\n",0);

	}

// MAP

	sprintf(Dummy,"MAP\t\tWIDTH %d\n",mapwid);
	PrtReport(Dummy,0);
	sprintf(Dummy,"\t\tSTARTSCREEN %d\n",mapstart);
	PrtReport(Dummy,0);

	for (i = 0; i < (Event[0] - mapdat - 1) / mapwid - 2; i++){
		PrtReport("\t\t",0);
		for (j = 0; j < mapwid; j++){
			sprintf(Dummy,"%3d ",cBuff[mapdat + mapwid + i * mapwid + j - SnapshotOffset]);	
			PrtReport(Dummy,0);
		}
		PrtReport("\n",0);
	}
	PrtReport("ENDMAP\n\n",0);

// FONT

	PrtReport("DEFINEFONT\t",0);
	for (i = 0; i < 96; i++){
		for (j = 0; j < 8; j++){
			sprintf(Dummy,"%d ",cBuff[font - SnapshotOffset + i * 8 + j]);
			PrtReport(Dummy,0);
		}
		PrtReport("\n\t\t",0);
	}

	return;
}
