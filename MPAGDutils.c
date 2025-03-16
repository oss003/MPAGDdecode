//===============================================================
// Utils
//===============================================================

extern unsigned char *cBuff;
extern unsigned long int event_ptr;
extern unsigned int IFstack[1000];
extern unsigned int WHILEstack[1000];
extern unsigned int DATAsFtack[1000];
extern unsigned long int lSize;
extern unsigned int Event[22];
extern int VarAddress;
extern int ptr_offset;
extern int iflag;
extern int debug;
extern FILE *fpDest;

extern char MSG[255][255];

//===============================================================
//===============================================================

int ReadParam(offset){
	return cBuff[event_ptr + offset];
}

//===============================================================
//===============================================================

int ReadAddress(offset){
	return (cBuff[offset + 1] << 8) + cBuff[offset];
}


int GetVarName(int offset){

	int Address;
	int var_ptr;

	Address = (cBuff[event_ptr + offset + 1] << 8) + cBuff[event_ptr + offset];
	var_ptr = Address - VarAddress;
	return var_ptr;
}

int GetSprVarName(int offset){

	int var_ptr;

	var_ptr = cBuff[event_ptr + offset];
	return var_ptr;
}

int GetOperator(int offset){
	
	int jmp1;
	int jmp2;
	int jmp3;
	int ret;
	
	jmp1 = cBuff[event_ptr + offset];
	jmp2 = cBuff[event_ptr + offset + 2];
	jmp3 = cBuff[event_ptr + offset + 3];
	
	ret = 0;
		
	switch (jmp1){
	case 0xda:
		if (jmp3 == 0xca){
			ptr_offset = 6;
			ret=1;				// LT
		} else {
			ptr_offset = 3;
			ret=2;				// LTEQ
		}
		break;
	case 0xc2:
		ptr_offset = 3;
		ret=3;					// EQ
		break;
	case 0x28:
		ptr_offset = 5;
		ret=4;					// GTEQ
		break;
	case 0xd2:
		ptr_offset = 3;
		ret=5;					// GT
		break;
	case 0xca:
		ptr_offset = 3;
		ret=6;					// NE
		break;
	}

	return ret;
}

//===============================================================
//===============================================================

const char *ReadVarName(offset){

	long int Address;
	char *VARname;

	Address = (cBuff[event_ptr + offset + 1] << 8) + cBuff[event_ptr + offset];
//	if (Address == CallPrtmod){
//		Address = VarAddress + 37;
//	}
//printf("Offset:%d\n",Address - VarAddress);

	switch (Address - VarAddress){
		case  0: VARname = "TOPEDGE"; break;
		case  1: VARname = "LEFTEDGE"; break;
		case  2: VARname = "BOTTOMEDGE"; break;
		case  3: VARname = "RIGHTEDGE"; break;
		case  4: VARname = "SCREEN"; break;
		case  5: VARname = "LIVES"; break;
		case  6: VARname = "A"; break;
		case  7: VARname = "B"; break;
		case  8: VARname = "C"; break;
		case  9: VARname = "D"; break;
		case 10: VARname = "E"; break;
		case 11: VARname = "F"; break;
		case 12: VARname = "G"; break;
		case 13: VARname = "H"; break;
		case 14: VARname = "I"; break;
		case 15: VARname = "J"; break;
		case 16: VARname = "K"; break;
		case 17: VARname = "L"; break;
		case 18: VARname = "M"; break;
		case 19: VARname = "N"; break;
		case 20: VARname = "O"; break;
		case 21: VARname = "P"; break;
		case 22: VARname = "Q"; break;
		case 23: VARname = "R"; break;
		case 24: VARname = "S"; break;
		case 25: VARname = "T"; break;
		case 26: VARname = "U"; break;
		case 27: VARname = "V"; break;
		case 28: VARname = "W"; break;
		case 29: VARname = "Z"; break;
		case 30: VARname = "CONTROL"; break;
		case 31: VARname = "LINE"; break;
		case 32: VARname = "COLUMN"; break;
		case 33: VARname = "CLOCK"; break;
		case 34: VARname = "RND"; break;
		case 35: VARname = "OBJ"; break;
		case 36: VARname = "OPT"; break;
//		case 37: VARname = "PRINTMODE";break;
		default: VARname = "???";
	}
	return VARname;
}

//===============================================================
//===============================================================

char * GetPattern(){

	char *cPattern;

	sprintf(cPattern, "%02X%02X%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

	return cPattern;
}

//===============================================================
//===============================================================

const char *ReadSprVarName(offset){

	char *VARname;


	switch (offset){
		case  0: VARname = "TYPE"; break;
		case  1: VARname = "IMAGE"; break;
		case  2: VARname = "FRAME"; break;
		case  3: VARname = "Y"; break;
		case  4: VARname = "X"; break;
		case  5: VARname = "TYPE"; break;
		case  6: VARname = "IMAGE"; break;
		case  7: VARname = "FRAME"; break;
		case  8: VARname = "Y"; break;
		case  9: VARname = "X"; break;
		case 10: VARname = "DIRECTION"; break;
		case 11: VARname = "SETTINGA"; break;
		case 12: VARname = "SETTINGB"; break;
		case 13: VARname = "AIRBORNE"; break;
		case 14: VARname = "JUMPSPEED"; break;
		default: VARname = "???";
	}
	return VARname;

}

//===============================================================
//===============================================================

const char *ReadSprName(offset){

	char *VARname;

	switch (offset){
		case 0: VARname = "PLAYER"; break;
		case 1: VARname = "1"; break;
		case 2: VARname = "2"; break;
		case 3: VARname = "3"; break;
		case 4: VARname = "4"; break;
		case 5: VARname = "5"; break;
		case 6: VARname = "6"; break;
		case 7: VARname = "7"; break;
		case 8: VARname = "8"; break;
		default: VARname = "???";
	}
	return VARname;

}


int PushIFstack(Offset){
	
// Add jump address to the IFstack

	int i;
	for (i = 0; i < 100; i++){
		if (IFstack[i] == 0){
			IFstack[i] = cBuff[event_ptr + Offset] + (cBuff[event_ptr + Offset + 1] << 8);
			break;
		}
	}
	return;
	
}

int DisplayIFstack(){
	int i;
	
	for (i = 0;i < 10;i++){
		printf("%04X ",IFstack[i]);
	}
		return 0;
}

int CheckIFstack(Address){
	
	int i;

	for (i = 0; i < 100; i++){
		if (IFstack[i] == Address){
			IFstack[i] = 0;
			iflag = 1;
			if (cBuff[Address - SnapshotOffset - 3] != 0xc3){
				sprintf (Dummy, "%04X ENDIF\n", Address);
				PrtReport(Dummy,1);
			} else {
				if ((cBuff[Address-SnapshotOffset-2] + (cBuff[Address-SnapshotOffset -1] << 8)) != event_ptr+ SnapshotOffset){
					sprintf (Dummy,"%04X ELSE\n", Address,event_ptr);
					PrtReport(Dummy,1);
					PushIFstack(-2);
				} else {
					sprintf (Dummy, "%04X ENDIF\n", Address);
					PrtReport(Dummy,1);
//					ident--;
				}
			}
		}
	}
	return;
}

int PushWHILEstack(Address){
	
// Add jump address to the IFstack[

	int i;
	for (i = 0; i < 100; i++){
		if (WHILEstack[i] == 0){
			WHILEstack[i] = Address; 
//			ident++;
			break;
		}
	}
	return;
	
}

int CheckWHILEstack(Address){
	
	int i;
	for (i = 0; i < 100; i++){
		if (WHILEstack[i] == Address){
			WHILEstack[i] = 0;
//			ident--;
			iflag = 1;
			sprintf (Dummy,"%04X ENDWHILE\n", Address,event_ptr);
			PrtReport(Dummy,1);
		}
	}
	return;
}

//===============================================================
// PushDATAstack(Address)
//
// READ command pushes unique DATA address to the stack
//===============================================================

int PushDATAstack(Address){
	
// Add jump address to the DATAstack

	int i;

// Check if Address already in stack

	for (i = 0; i < 100; i++){
		if (DATAstack[i] == Address){
			return;
		}
	} 

// Add unique address to stack

	for (i = 0; i < 100; i++){
		if (DATAstack[i] == 0){
			DATAstack[i] = Address; 
			break;
		}
	}
	return;
	
}

int CheckDATAstack(Address){
	
	int i;
	int ptr;
	int Getal;
	int DATAstart;
	int DATAlen;
	int READend;
	int Offset;
	
	for (i = 0; i < 100; i++){
		if (DATAstack[i] == Address){
			DATAstack[i] = 0;
			if (Events < 9){
				DATAstart = ((cBuff[Address - SnapshotOffset + 18] << 8) + cBuff[Address - SnapshotOffset + 17]);
				Offset = 28;
			} else {
				DATAstart = ((cBuff[Address - SnapshotOffset + 2] << 8) + cBuff[Address - SnapshotOffset + 1]) + 2;
				Offset = 22;
			}
			DATAlen = Address - DATAstart;
			for (ptr = 0; ptr < DATAlen; ptr++){
				Getal = ptr % 10;
				if (Getal == 0){
					if (ptr != 0) printf("\n");
					sprintf (Dummy,"%04X DATA %d ",DATAstart + ptr,cBuff[DATAstart - SnapshotOffset + ptr]);
					PrtReport(Dummy,1);
				} else {
					sprintf(Dummy,"%d ",cBuff[DATAstart - SnapshotOffset + ptr]);
					PrtReport(Dummy,0);
				}
			}
			printf("\n");
			event_ptr = event_ptr + Offset;
		}
	}
	return;
}

int FindAddress(char *AsmCodeString){
	
	char Filter[64];
	int i;
	int flag=0;
	long int address;
	
	for (i = 0; i < lSize; i++){
		switch (strlen(AsmCodeString) / 2){
				case 3: 
					sprintf(Filter,"%02X%02X%02X",cBuff[i],cBuff[i+1],cBuff[i+2]);
					break;
				case 4: 
					sprintf(Filter,"%02X%02X%02X%02X",cBuff[i],cBuff[i+1],cBuff[i+2],cBuff[i+3]);
					break;
				case 5: 
					sprintf(Filter,"%02X%02X%02X%02X%02X",cBuff[i],cBuff[i+1],cBuff[i+2],cBuff[i+3],cBuff[i+4]);
					break;
				case 6: 
					sprintf(Filter,"%02X%02X%02X%02X%02X%02X",cBuff[i],cBuff[i+1],cBuff[i+2],cBuff[i+3],cBuff[i+4],cBuff[i+5]);
					break;
				case 7: 
					sprintf(Filter,"%02X%02X%02X%02X%02X%02X%02X",cBuff[i],cBuff[i+1],cBuff[i+2],cBuff[i+3],cBuff[i+4],cBuff[i+5],cBuff[i+6]);
					break;
				case 8: 
					sprintf(Filter,"%02X%02X%02X%02X%02X%02X%02X%02X",cBuff[i],cBuff[i+1],cBuff[i+2],cBuff[i+3],cBuff[i+4],cBuff[i+5],cBuff[i+6],cBuff[i+7]);
					break;
				case 9: 
					sprintf(Filter,"%02X%02X%02X%02X%02X%02X%02X%02X%02X",cBuff[i],cBuff[i+1],cBuff[i+2],cBuff[i+3],cBuff[i+4],cBuff[i+5],cBuff[i+6],cBuff[i+7],cBuff[i+8]);
					break;
				case 10: 
					sprintf(Filter,"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",cBuff[i],cBuff[i+1],cBuff[i+2],cBuff[i+3],cBuff[i+4],cBuff[i+5],cBuff[i+6],cBuff[i+7],cBuff[i+8],cBuff[i+9]);
					break;
		}
		
		if (strcmp(Filter, AsmCodeString) == 0){
			address = i + SnapshotOffset;
			flag++;
		}
	}
	if (debug != 0){
		if (flag == 0) printf("  Pattern %s NOT FOUND\n",AsmCodeString);
		if (flag == 2) printf("  Pattern %s MULTIPLE ENTRIES FOUND\n",AsmCodeString);
	}
	return address;
}

void Init(){

	int i;
	int evntloc;
	
// Locate routines in engine by unique code

	PrtReport("\nChecking reference patterns:\n",2);
	EngineStart = FindAddress("22365C") - 3;
	CallSpawn   = FindAddress("C92B2BC9") + 4;
	CallCangoL  = FindAddress("C9DD6E08DD7E09D602")+1;
	CallCangoR  = FindAddress("6E08DD7E09C6106722")-1;
	CallCangoU  = FindAddress("C9DD7E08DD6609D6026F")+1;
	CallCangoD  = FindAddress("DD7E08DD6609C6106F");
	CallCspr    = FindAddress("DD7E08FEB1D0");
	CallSktype  = FindAddress("7E3D18") + 4;
	CallRandom  = FindAddress("7E470F0F0F") - 3;
	CallAnimesp = FindAddress("D82638C9") + 4;
	CallAnimBack= CallAnimesp + 24;
	CallAddSc   = FindAddress("011027CD") - 3;
	CallPrtmod	= FindAddress("347EFE1838") + 13;
	CallChr		= FindAddress("A778C2") - 7;
	CallClw		= FindAddress("DD19C92A") + 3;
	CallCls		= FindAddress("DDE1C921") + 3;
	CallGravst	= FindAddress("DD7E0EDD360D00");
	CallIFall	= FindAddress("DD7E0DA7C0DD6609");
	CallDisply	= FindAddress("DDE5D1EBED52") + 12;
	CallNum2dd	= FindAddress("FE20C80203C9") + 6;
	CallExplod	= FindAddress("4FDDE5DD6E08");
	CallGetob	= FindAddress("36FEC9") + 3;
	CallGetcol	= FindAddress("B8C0CD") - 5;
	CallGotob	= FindAddress("BE3006CD") - 3;
	CallScrL	= FindAddress("1600197EC9") + 5;
	CallScrR	= FindAddress("3602C93A") + 3;
	CallScrU	= FindAddress("3602C93A") + 9;
	CallScrD	= FindAddress("3602C93A") + 16;
	CallIFall	= FindAddress("06007EFE6438") + 15;
	CallLadderU	= FindAddress("C6106F18") + 5;
	CallLadderD	= FindAddress("C6106F18") - 11;
	CallJump	= FindAddress("ED444F");
	CallDmsg	= FindAddress("E57EE67FFE0D28") - 19;
	CallSwpsb	= FindAddress("06061A4EEB7112") - 6;
	CallLcol	= FindAddress("7EA728") - 8;
	CallWaitkey	= FindAddress("7E34C8CD") + 13;
	CallRedraw	= FindAddress("FEB130") - 23;
	CallShoot	= FindAddress("C6076FDD66") - 4;
	CallRemob	= FindAddress("BED0F5CD") - 3;
	CallTfall	= FindAddress("DD7E0DA7C0CD");
	CallTjump   = FindAddress("DD7E0DA7C0DD360D");
	CallPut		= FindAddress("BEC87723") - 11;
	CallVapour	= FindAddress("DDE5DD6E08DD660911");
	CallDig		= FindAddress("DD66093E10DD86086F18") - 10;
	CallMenu	= FindAddress("E51601AF32") - 21;
	CallInv		= CallMenu - 17;
	
	sndtype		= FindAddress("78E67F3C3D20") + 12;
	prtmod		= FindAddress("7EE5E67FFE0D") - 1;
	evntloc		= FindAddress("5E2356EBE9") - SnapshotOffset + 7;
	msgdata		= FindAddress("E51601AF32") - SnapshotOffset - 5;

// Calculate locations in engine

	VarAddress  = EngineStart;
	while (cBuff[VarAddress - SnapshotOffset] != 0xc3){
			VarAddress++;
	}
	VarAddress 	= VarAddress + 10;
	ScrFormat	= VarAddress - 5;
	nexlev		= VarAddress + 38;
	gamwon		= VarAddress + 41;
	ogptr		= evntloc + SnapshotOffset - 2;
	score		= FindAddress("7BFE18D8E1C9") - 20;
	seed		= score - 1;
	hiscor		= score + 6;
	bonus		= hiscor + 6;
	spptr		= score - 3;
	skptr		= FindAddress("DD7E00B828") - 2;
	
// Update templates with right engine routine addresses

	sprintf(cmd_ANIMATE      ,"AFCD%02X%02X"            ,CallAnimesp  & 0xff, CallAnimesp  >> 8);
	sprintf(cmd_ANIMMED      ,"3E01CD%02X%02X"          ,CallAnimesp  & 0xff, CallAnimesp  >> 8);
	sprintf(cmd_ANIMSLOW	 ,"3E03CD%02X%02X"          ,CallAnimesp  & 0xff, CallAnimesp  >> 8);
	sprintf(cmd_ANIMVSLOW	 ,"3E07CD%02X%02X"          ,CallAnimesp  & 0xff, CallAnimesp  >> 8);
	sprintf(cmd_ANIMBACK      ,"AFCD%02X%02X"           ,CallAnimBack  & 0xff, CallAnimBack  >> 8);
	sprintf(cmd_ANIMBACKMED   ,"3E01CD%02X%02X"         ,CallAnimBack  & 0xff, CallAnimBack  >> 8);
	sprintf(cmd_ANIMBACKSLOW  ,"3E03CD%02X%02X"         ,CallAnimBack  & 0xff, CallAnimBack  >> 8);
	sprintf(cmd_ANIMBACKVSLOW ,"3E07CD%02X%02X"         ,CallAnimBack  & 0xff, CallAnimBack  >> 8);
	sprintf(cmd_ATVALVAL     ,"21xxxx22%02X%02X"        ,(VarAddress + 31)  & 0xff, (VarAddress + 31)  >> 8);
	sprintf(cmd_BEEPVAL      ,"3Exx32%02X%02X"          ,sndtype  & 0xff, sndtype  >> 8);
	sprintf(cmd_BEEPVAR      ,"3AxxxxE67F32%02X%02X"    ,sndtype  & 0xff, sndtype  >> 8);
	sprintf(cmd_BEEPSPRVAR   ,"DD7ExxE67F32%02X%02X"    ,sndtype  & 0xff, sndtype  >> 8);
	sprintf(cmd_BONUSVAL     ,"CD%02X%02X21xxxxCDxxxx"  ,CallSwpsb  & 0xff, CallSwpsb  >> 8);
	sprintf(cmd_BONUSVAR     ,"CD%02X%02X3Axxxx6F2600"  ,CallSwpsb  & 0xff, CallSwpsb  >> 8);
	sprintf(cmd_CANGOLEFT    ,"CD%02X%02XC2xxxx"        ,CallCangoL & 0xff, CallCangoL >> 8);
	sprintf(cmd_CANGORIGHT   ,"CD%02X%02XC2xxxx"        ,CallCangoR & 0xff, CallCangoR >> 8);
	sprintf(cmd_CANGOUP      ,"CD%02X%02XC2xxxx"        ,CallCangoU & 0xff, CallCangoU >> 8);
	sprintf(cmd_CANGODOWN    ,"CD%02X%02XC2xxxx"        ,CallCangoD & 0xff, CallCangoD >> 8);
	sprintf(cmd_CHRVAL       ,"3ExxCD%02X%02X"          ,CallChr  & 0xff, CallChr  >> 8);
	sprintf(cmd_CHRVAR       ,"3AxxxxCD%02X%02X"        ,CallChr  & 0xff, CallChr  >> 8);
	sprintf(cmd_CLS          ,"CD%02X%02X"              ,CallCls  & 0xff, CallCls  >> 8);
	sprintf(cmd_CLW          ,"CD%02X%02XCDxxxx"        ,CallClw  & 0xff, CallClw  >> 8);
	sprintf(cmd_CRASHSPRVAR  ,"DD7ExxF68032%02X%02X"    ,sndtype  & 0xff, sndtype  >> 8);
	sprintf(cmd_CRASHVAL     ,"3Exx32%02X%02X"          ,sndtype  & 0xff, sndtype  >> 8);
	sprintf(cmd_CRASHVAR     ,"3AxxxxF68032%02X%02X"    ,sndtype  & 0xff, sndtype  >> 8);
	sprintf(cmd_CRASHZERO    ,"3E8032%02X%02X"          ,sndtype  & 0xff, sndtype  >> 8);
	sprintf(cmd_DETECTOBJ    ,"CDxxxx32%02X%02X"        ,(VarAddress + 35)  & 0xff, (VarAddress + 35)  >> 8);
	sprintf(cmd_DIGZERO      ,"AFCD%02X%02X"			,CallDig & 0xff, CallDig >> 8);
	sprintf(cmd_DIGVAL       ,"3ExxCD%02X%02X"			,CallDig & 0xff, CallDig >> 8);
	sprintf(cmd_DISPLAYDBLVAR,"3Axxxx01xxxxCD%02X%02XCDxxxx"     ,CallNum2dd  & 0xff, CallNum2dd  >> 8);
	sprintf(cmd_DISPLAYVAR   ,"3AxxxxCD%02X%02X"        ,CallDisply  & 0xff, CallDisply  >> 8);
	sprintf(cmd_ENDGAME      ,"21%02X%02X74"            ,gamwon  & 0xff, gamwon  >> 8);
	sprintf(cmd_ENDSPRITE    ,"DD2A%02X%02X"            ,ogptr  & 0xff, ogptr  >> 8);
	sprintf(cmd_EXPLVAL      ,"3ExxCD%02X%02X"			,CallExplod  & 0xff, CallExplod  >> 8);
	sprintf(cmd_EXPLVAR      ,"3AxxxxCD%02X%02X"        ,CallExplod  & 0xff, CallExplod  >> 8);
	sprintf(cmd_FALL         ,"CD%02X%02X"        		,CallIFall  & 0xff, CallIFall  >> 8);
	sprintf(cmd_GETBLOCKS    ,"CD%02X%02X"              ,CallGetcol  & 0xff, CallGetcol  >> 8);
	sprintf(cmd_GETVAL       ,"3ExxCD%02X%02X"          ,CallGetob  & 0xff, CallGetob  >> 8);
	sprintf(cmd_GETVAR       ,"3AxxxxCD%02X%02X"        ,CallGetob & 0xff, CallGetob  >> 8);
	sprintf(cmd_IFCOLLBULLET ,"CD%02X%02XD2xxxx"		,CallLcol & 0xff, CallLcol >> 8);
	sprintf(cmd_IFGOTVAL     ,"3ExxCD%02X%02XDAxxxx"    ,CallGotob  & 0xff, CallGotob  >> 8);
	sprintf(cmd_IFGOTVAR     ,"3AxxxxCD%02X%02XDAxxxx"  ,CallGotob  & 0xff, CallGotob  >> 8);
	sprintf(cmd_IFGOTZERO    ,"AFCD%02X%02XDAxxxx"      ,CallGotob  & 0xff, CallGotob  >> 8);
	sprintf(cmd_INVZERO	 	 ,"AFCD%02X%02X"            ,CallInv  & 0xff, CallInv  >> 8);
	sprintf(cmd_INVVAL		 ,"3ExxCD%02X%02X"          ,CallInv  & 0xff, CallInv  >> 8);
	sprintf(cmd_INVVAR		 ,"3AxxxxCD%02X%02X"        ,CallInv  & 0xff, CallInv  >> 8);
	sprintf(cmd_INVSPRVAR	 ,"DD7ExxCD%02X%02X"        ,CallInv  & 0xff, CallInv  >> 8);
	sprintf(cmd_JUMPVAL      ,"3ExxCD%02X%02X"          ,CallJump  & 0xff, CallJump  >> 8);
	sprintf(cmd_JUMPVAR      ,"3AxxxxCD%02X%02X"        ,CallJump  & 0xff, CallJump  >> 8);
	sprintf(cmd_JUMPSPRVAR   ,"DD7ExxCD%02X%02X"        ,CallJump  & 0xff, CallJump  >> 8);
	sprintf(cmd_LADDERABOVE  ,"CD%02X%02XC2xxxx"        ,CallLadderU  & 0xff, CallLadderU  >> 8);
	sprintf(cmd_LADDERBELOW  ,"CD%02X%02XC2xxxx"        ,CallLadderD  & 0xff, CallLadderD  >> 8);
	sprintf(cmd_LASERVAL	 ,"3ExxCD%02X%02X"		    ,CallShoot  & 0xff, CallShoot  >> 8);
	sprintf(cmd_LASERSPRVAR	 ,"DD7ExxCD%02X%02X"	    ,CallShoot  & 0xff, CallShoot  >> 8);
	sprintf(cmd_LASERVAR	 ,"3AxxxxCD%02X%02X"	    ,CallShoot  & 0xff, CallShoot  >> 8);
	sprintf(cmd_LASERZERO	 ,"AFCD%02X%02X"		    ,CallShoot  & 0xff, CallShoot  >> 8);
	sprintf(cmd_MENUZERO	 ,"AFCD%02X%02X"            ,CallMenu  & 0xff, CallMenu  >> 8);
	sprintf(cmd_MENUVAL		 ,"3ExxCD%02X%02X"          ,CallMenu  & 0xff, CallMenu  >> 8);
	sprintf(cmd_MENUVAR		 ,"3AxxxxCD%02X%02X"        ,CallMenu  & 0xff, CallMenu  >> 8);
	sprintf(cmd_MENUSPRVAR	 ,"DD7ExxCD%02X%02X"        ,CallMenu  & 0xff, CallMenu  >> 8);
	sprintf(cmd_MESSAGEVAL   ,"3ExxCD%02X%02X"          ,CallDmsg  & 0xff, CallDmsg  >> 8);
	sprintf(cmd_MESSAGEVAR   ,"3AxxxxCD%02X%02X"        ,CallDmsg  & 0xff, CallDmsg  >> 8);
	sprintf(cmd_MESSAGEZERO  ,"AFCD%02X%02X"            ,CallDmsg  & 0xff, CallDmsg  >> 8);
	sprintf(cmd_NEXTLEVEL    ,"21%02X%02X74"            ,nexlev  & 0xff, nexlev  >> 8);
	sprintf(cmd_OTHER        ,"DD2A%02X%02X"            ,skptr  & 0xff, skptr  >> 8);
	sprintf(cmd_PRINTMODEVAL ,"3Exx32%02X%02X"          ,prtmod  & 0xff, prtmod  >> 8);
	sprintf(cmd_PRINTMODEVAR ,"3Axxxx32%02X%02X"        ,prtmod  & 0xff, prtmod  >> 8);
	sprintf(cmd_PRINTMODEZERO,"AF32%02X%02X"            ,prtmod  & 0xff, prtmod  >> 8);
	sprintf(cmd_PRINTVAL     ,"3ExxCD%02X%02X"          ,CallDmsg  & 0xff, CallDmsg  >> 8);
	sprintf(cmd_PRINTZERO    ,"AFCD%02X%02X"            ,CallDmsg  & 0xff, CallDmsg  >> 8);
	sprintf(cmd_PUT			 ,"CD%02X%02X"              ,CallPut  & 0xff, CallPut  >> 8);
	sprintf(cmd_RANDOMIZEVAL ,"3Exx32%02X%02X"          ,seed  & 0xff, seed  >> 8);
	sprintf(cmd_RANDOMIZEVAR ,"3Axxxx32%02X%02X"        ,seed  & 0xff, seed  >> 8);
	sprintf(cmd_REDRAW       ,"CD%02X%02X"              ,CallRedraw  & 0xff, CallRedraw  >> 8);
	sprintf(cmd_REMOBJZERO   ,"AFCD%02X%02X"           	,CallRemob  & 0xff, CallRemob  >> 8);
	sprintf(cmd_REMOBJVAL    ,"3ExxCD%02X%02X"       	,CallRemob  & 0xff, CallRemob  >> 8);
	sprintf(cmd_REMOBJVAR    ,"3AxxxxCD%02X%02X"       	,CallRemob  & 0xff, CallRemob  >> 8);
	sprintf(cmd_REMOBJSPRVAR ,"DD7ExxCD%02X%02X"      	,CallRemob  & 0xff, CallRemob  >> 8);
	sprintf(cmd_SCOREVAL     ,"21xxxxCD%02X%02X"        ,CallAddSc  & 0xff, CallAddSc  >> 8);
	sprintf(cmd_SCREENL      ,"CD%02X%02X"              ,CallScrL  & 0xff, CallScrL  >> 8);
	sprintf(cmd_SCREENR      ,"CD%02X%02X"              ,CallScrR  & 0xff, CallScrR  >> 8);
	sprintf(cmd_SCREENU      ,"CD%02X%02X"              ,CallScrU  & 0xff, CallScrU  >> 8);
	sprintf(cmd_SCREEND      ,"CD%02X%02X"              ,CallScrD  & 0xff, CallScrD  >> 8);
	sprintf(cmd_SHOWBONUS    ,"21%02X%02X0606CDxxxx"    ,bonus  & 0xff, bonus  >> 8);
	sprintf(cmd_SHOWHIGHSCORE,"21%02X%02X0606CDxxxx"    ,hiscor  & 0xff, hiscor  >> 8);
	sprintf(cmd_SHOWSCORE    ,"21%02X%02X0606CDxxxx"    ,score  & 0xff, score  >> 8);
	sprintf(cmd_SPAWNVALVAL  ,"01xxxxCD%02X%02X"        ,CallSpawn  & 0xff, CallSpawn  >> 8);
	sprintf(cmd_SPAWNED      ,"DD2A%02X%02X"  	        ,spptr  & 0xff, spptr  >> 8);
	sprintf(cmd_STOPFALL	 ,"CD%02X%02X"				,CallGravst  & 0xff, CallGravst  >> 8);
	sprintf(cmd_TABLEFALL    ,"CD%02X%02X"  	        ,CallTfall  & 0xff, CallTfall  >> 8);
	sprintf(cmd_TABLEJUMP    ,"CD%02X%02X"  	        ,CallTjump  & 0xff, CallTjump  >> 8);
	sprintf(cmd_TRAIL	     ,"CD%02X%02X"  	        ,CallVapour  & 0xff, CallVapour  >> 8);
	sprintf(cmd_WAITKEY		 ,"CD%02X%02X"			    ,CallWaitkey  & 0xff, CallWaitkey  >> 8);
	sprintf(cmd_ZEROBONUS    ,"21%02X%02X010500363011"  ,bonus  & 0xff, bonus  >> 8);

// Find Event[0-8] locations
	
	for (i = 0; i < 9; i++){
		Event[i] = cBuff[evntloc + i*2] + (cBuff[evntloc +1 + i*2] << 8);
	}
// Find Event[9] location
	
	evntloc = FindAddress("C1E1DDE111") - SnapshotOffset ;
	Event[9] = cBuff[evntloc - 2] + (cBuff[evntloc - 1] << 8);

// Find Event[10-11]+[16-18] location
	
	evntloc = FindAddress("3CBE30") - SnapshotOffset ;
	Event[10] = cBuff[evntloc - 55] + (cBuff[evntloc - 54] << 8);
	Event[11] = cBuff[evntloc - 45] + (cBuff[evntloc - 44] << 8);
	Event[16] = cBuff[evntloc + 21] + (cBuff[evntloc + 22] << 8);
	Event[17] = cBuff[evntloc + 31] + (cBuff[evntloc + 32] << 8);
	Event[18] = cBuff[evntloc + 11] + (cBuff[evntloc + 12] << 8);

// Find Event[12-13] location
	
	evntloc = FindAddress("01FF0236") - SnapshotOffset ;
	Event[12] = cBuff[evntloc - 8] + (cBuff[evntloc - 7] << 8);
	Event[13] = cBuff[evntloc + 34] + (cBuff[evntloc + 35] << 8);

// Find Event[14]+[19] location
	
	evntloc = FindAddress("010600EDB0CD") - SnapshotOffset ;
	Event[14] = cBuff[evntloc + 15] + (cBuff[evntloc + 16] << 8);
	Event[19] = cBuff[evntloc + 6] + (cBuff[evntloc + 7] << 8);

// Find Event[15] location
	
	evntloc = FindAddress("DD360E00FE08CA") - SnapshotOffset ;
	Event[15] = cBuff[evntloc + 7] + (cBuff[evntloc + 8] << 8);


// Find Event[20] location
	
	evntloc = FindAddress("B8C0CD") - SnapshotOffset ;
	Event[20] = cBuff[evntloc + 6] + (cBuff[evntloc + 7] << 8);

// Event[21] is end of code

	Event[21] = EngineStart;	// Will be updated in Info
	
// Mapdata

	i			= FindAddress("5F1600197E") - 1;
	mapwid		= cBuff[i - SnapshotOffset];
	i			= FindAddress("5F1600197E") - 5;
	mapdat		= ReadAddress(i - SnapshotOffset);
	i			= cBuff[Event[0] - SnapshotOffset - 1];
	mapstart	= cBuff[mapdat + mapwid + i - SnapshotOffset];
	
	return;
	
}

int PrintIdent(int Nr){

		int i;
		
		for (i = 0; i <  Nr; i++){
				printf(" ");
				sprintf(Dummy," ");
				PrtReport(Dummy,0);
		}
		
		return 0;
}

void Info(){

	int Address;
	int msgdat;
	int palett;
	int jtab;

	int i;
	int msgptr;
	int strPtr;
	char tmpString[255];
	
	msgdat = ReadAddress(FindAddress("E51601AF32") - 5 - SnapshotOffset);
	objdta = ReadAddress(FindAddress("47112700DD7E") - 5 - SnapshotOffset);

	frmlst = ReadAddress(VarAddress + 44- SnapshotOffset);
	chgfx  = ReadAddress(VarAddress + 46- SnapshotOffset);
	bcol   = ReadAddress(VarAddress + 48- SnapshotOffset);
	bprop  = ReadAddress(VarAddress + 50- SnapshotOffset);
    scdat  = ReadAddress(VarAddress + 52- SnapshotOffset);
	nmedat = ReadAddress(VarAddress + 54- SnapshotOffset);
	
	nummsg = cBuff[scdat - SnapshotOffset - 1];
	numsc  = cBuff[chgfx - SnapshotOffset - 1];
	numobj = cBuff[VarAddress - 1 - SnapshotOffset];
	numblk = bprop - bcol;
	numspr = (nmedat - frmlst) / 2 - 1;
	
	sprgfx = bprop + (bprop - bcol);
	palett = objdta + 39 * numobj;
	font   = palett + 64;
	jtab   = font + 768;
	keys   = jtab;
    while (cBuff[keys - SnapshotOffset] != 0x63){
		keys++;
	}
	keys++;
	
// Read messages into array

	msgptr = msgdat - SnapshotOffset;
	
	for (i = 0; i < nummsg; i++){
		strPtr = 0;
		while (cBuff[msgptr] < 128){
			tmpString[strPtr] = cBuff[msgptr];
			msgptr++;
			strPtr++;
		}
		tmpString[strPtr] = cBuff[msgptr] - 128;
		strPtr++;
		tmpString[strPtr] = 0;
		msgptr++;
		strcpy(MSG[i], tmpString);
	}

	Event[21] = msgdat - 1;

//	for (i = 0; i < nummsg; i++){
//			printf("%s\n",MSG[i]);
//	}

// Print table addresses

	sprintf (Dummy,"\nEngineAddress: %04X\n",EngineStart);
	PrtReport(Dummy,2);
	sprintf (Dummy,"VarAddress   : %04X\n",VarAddress);
	PrtReport(Dummy,2);
	sprintf (Dummy,"ScrFormats   : %04X\n",ScrFormat);
	PrtReport(Dummy,2);
	
	sprintf (Dummy," \n%04X\tmsgdat\n",msgdat);
	PrtReport(Dummy,2);
	sprintf (Dummy," %d\tnummsg\n",nummsg);
	PrtReport(Dummy,2);
	sprintf (Dummy," %04X\tscdat\n",scdat);
	PrtReport(Dummy,2);
	sprintf (Dummy," %d\tnumsc\n",numsc);
	PrtReport(Dummy,2);
	sprintf (Dummy," %04X\tchgfx\n",chgfx);
	PrtReport(Dummy,2);
	sprintf (Dummy," %d\tnumblk\n",numblk);
	PrtReport(Dummy,2);
	sprintf (Dummy," %04X\tbcol\n",bcol);
	PrtReport(Dummy,2);
	sprintf (Dummy," %04X\tbprop\n",bprop);
	PrtReport(Dummy,2);
	sprintf (Dummy," %04X\tsprgfx\n",sprgfx);
	PrtReport(Dummy,2);
	sprintf (Dummy," %d\tnumsprx\n",numspr);
	PrtReport(Dummy,2);
	sprintf (Dummy," %04X\tfrmlst\n",frmlst);
	PrtReport(Dummy,2);
	sprintf (Dummy," %04X\tnmedat\n",nmedat);
	PrtReport(Dummy,2);
	sprintf (Dummy," %d\tnumobj\n",numobj);
	PrtReport(Dummy,2);
	sprintf (Dummy," %04X\tobjdta\n",objdta);
	PrtReport(Dummy,2);
	sprintf (Dummy," %04X\tpalett\n",palett);
	PrtReport(Dummy,2);
	sprintf (Dummy," %04X\tfont\n",font);
	PrtReport(Dummy,2);
	sprintf (Dummy," %04X\tjtab\n",jtab);
	PrtReport(Dummy,2);
	sprintf (Dummy," %04X\tkeys\n\n",keys);
	PrtReport(Dummy,2);

// Print Event locations

	for (i = 0; i < 21; i++){
		sprintf (Dummy," Event[%d]=$%04X\n",i,Event[i]);
	}

	
	return;
}

int ConvertKey(int Code){
	
	int ch;
	
	switch (Code)
	{
		case 32: ch = ' '; break;
		case 38: ch = 'A'; break;
		case  0: ch = 'B'; break;
		case 15: ch = 'C'; break;
		case 22: ch = 'D'; break;
		case 21: ch = 'E'; break;
		case 14: ch = 'F'; break;
		case  6: ch = 'G'; break;
		case  1: ch = 'H'; break;
		case 18: ch = 'I'; break;
		case  9: ch = 'J'; break;
		case 17: ch = 'K'; break;
		case 25: ch = 'L'; break;
		case 16: ch = 'M'; break;
		case  8: ch = 'N'; break;
		case 26: ch = 'O'; break;
		case 34: ch = 'P'; break;
		case 37: ch = 'Q'; break;
		case 13: ch = 'R'; break;
		case 30: ch = 'S'; break;
		case  5: ch = 'T'; break;
		case 10: ch = 'U'; break;
		case  7: ch = 'V'; break;
		case 29: ch = 'W'; break;
		case 23: ch = 'X'; break;
		case  2: ch = 'Y'; break;
		case 31: ch = 'Z'; break;
		case 39: ch = '~'; break;
		case 36: ch = '1'; break;
		case 28: ch = '2'; break;
		case 20: ch = '3'; break;
		case 12: ch = '4'; break;
		case 35: ch = '0'; break;
		case  4: ch = '5'; break;
		case  3: ch = '6'; break;
		case 11: ch = '7'; break;
		case 19: ch = '8'; break;
		case 27: ch = '9'; break;
	}
	return ch;
}

void PrtReport(char *String, int Flag){

	if (debug == 1){
		printf ("%s", String);
	} else {
		switch (Flag){
				case 0:
					printf ("%s", String);
					fprintf(fpDest, "%s", String);
					break;
				case 1:
					if (strncmp(String + 5, "ENDIF", 5) == 0) {
						ident--;
					}
					if (strncmp(String + 5, "ENDWHILE", 8) == 0) {
						ident--;
					}
					if (strncmp(String + 5, "ENDREPEAT", 9) == 0) {
						ident--;
					}
					if (strncmp(String + 5, "ELSE", 4) == 0) {
						ident--;
					}
					PrintIdent(ident);
					printf ("%s", String + 5);
					fprintf(fpDest, "%s", String + 5);
					if (strncmp(String + 5, "IF", 2) == 0) {
						ident++;
					}
					if (strncmp(String + 5, "WHILE", 5) == 0) {
						ident++;
					}
					if (strncmp(String + 5, "REPEAT", 6) == 0) {
						ident++;
					}
					if (strncmp(String + 5, "ELSE", 4) == 0) {
						ident++;
					}
					break;
				case 2:
					if (debug == 1){
						printf ("%s", String);
						break;
					}
					break;
				default:
					break;
		}
	}
	return;
}