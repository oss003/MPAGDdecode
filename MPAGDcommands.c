//===============================================================
// COMMAND test routines
//===============================================================

void PrtReport(char String[], int Flag);

//extern long int SnapshotOffset;
//extern static const char cmd_SPRITEINK[];
//extern char cSearch;

extern unsigned char *cBuff;
extern unsigned long int event_ptr;
extern unsigned int DataByte;
extern unsigned int Event[22];
extern 	int Events;
extern char MSG[255][255];
extern unsigned int DATAstack[1000];
extern int keys;
extern int AdvMode;

const char *ReadSprName();
const char *ReadSprVarName();
const char *ReadVarName();
char Dummy[128];

//--------------------------------------------
// 1. ADDBONUS
//--------------------------------------------

int tst_ADDBONUS(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_ADDBONUS, cPattern) == 0){
		sprintf (Dummy,"%04X ADDBONUS\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. ADD 1 TO VAR
//--------------------------------------------

int tst_ADD1TOVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_ADD1TOVAR, cPattern) == 0){
		sprintf (Dummy,"%04X ADD 1 TO %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 7;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. ADD 1 TO SPRVAR
//--------------------------------------------

int tst_ADD1TOSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_ADD1TOSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X ADD 1 TO %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 7;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. ADD VAR TO VAR
//--------------------------------------------

int tst_ADDVARTOVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	const char *VARname = ReadVarName(1);
	const char *VARname2 = ReadVarName(5);

// Compare pattern with template

	if (strcmp(cmd_ADDVARTOVAR, cPattern) == 0){
		sprintf (Dummy,"%04X ADD %s TO %s\n", event_ptr + SnapshotOffset, VARname, VARname2); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. ADD VAR TO SPRVAR
//--------------------------------------------

int tst_ADDVARTOSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02Xxx%02X%02X%02Xxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 9]);

// Read parameters

	const char *VARname = ReadVarName(1);
	sprVARval = ReadParam(6);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template
	if (strcmp(cmd_ADDVARTOSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X ADD %s TO %s\n", event_ptr + SnapshotOffset, VARname, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. ADD SPRVAR TO VAR
//--------------------------------------------

int tst_ADDSPRVARTOVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	const char *VARname = ReadVarName(5);
	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template
	if (strcmp(cmd_ADDSPRVARTOVAR, cPattern) == 0){
		sprintf (Dummy,"%04X ADD %s TO %s\n", event_ptr + SnapshotOffset, sprVARname, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. ADD VAL TO VAR
//--------------------------------------------

int tst_ADDVALTOVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	DataByte = ReadParam(1);
	const char *VARname = ReadVarName(3);

// Compare pattern with template

	if (strcmp(cmd_ADDVALTOVAR, cPattern) == 0){
		sprintf (Dummy,"%04X ADD %d TO %s\n", event_ptr + SnapshotOffset, DataByte, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. ADD VAL TO SPRVAR
//--------------------------------------------

int tst_ADDVALTOSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02Xxx%02X%02X%02Xxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour
	sprVARval = ReadParam(4);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_ADDVALTOSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X ADD %d TO %s\n", event_ptr + SnapshotOffset, DataByte, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. SUBTRACT 1 FROM VAR
//--------------------------------------------

int tst_SUB1FROMVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_SUB1FROMVAR, cPattern) == 0){
		sprintf (Dummy,"%04X SUBTRACT 1 FROM %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 7;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. SUBTRACT 1 FROM SPRVAR
//--------------------------------------------

int tst_SUB1FROMSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02Xxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_SUB1FROMSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X SUBTRACT 1 FROM %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 7;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. SUBTRACT VAR FROM VAR
//--------------------------------------------

int tst_SUBVARFROMVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	const char *VARname = ReadVarName(1);
	const char *VARname1 = ReadVarName(5);

// Compare pattern with template

	if (strcmp(cmd_SUBVARFROMVAR, cPattern) == 0){
		sprintf (Dummy,"%04X SUBTRACT %s FROM %s\n", event_ptr + SnapshotOffset, VARname, VARname1); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. SUBTRACT VAR FROM SPRVAR
//--------------------------------------------

int tst_SUBVARFROMSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02Xxx%02X%02X%02Xxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 9]);

// Read parameters

	const char *VARname = ReadVarName(1);
	sprVARval = ReadParam(6);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_SUBVARFROMSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X SUBTRACT %s FROM %s\n", event_ptr + SnapshotOffset, VARname, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. SUBTRACT SPRVAR FROM VAR
//--------------------------------------------

int tst_SUBSPRVARFROMVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	const char *VARname = ReadVarName(5);
	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_SUBSPRVARFROMVAR, cPattern) == 0){
		sprintf (Dummy,"%04X SUBTRACT %s FROM %s\n", event_ptr + SnapshotOffset, sprVARname, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. SUBTRACT VAL FROM VAR
//--------------------------------------------

int tst_SUBVALFROMVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	DataByte = ReadParam(1);
	const char *VARname = ReadVarName(3);

// Compare pattern with template

	if (strcmp(cmd_SUBVALFROMVAR, cPattern) == 0){
		sprintf (Dummy,"%04X SUBTRACT %d FROM %s\n", event_ptr + SnapshotOffset, DataByte, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. SUBTRACT VAL FROM SPRVAR
//--------------------------------------------

int tst_SUBVALFROMSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02Xxx%02X%02X%02Xxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour
	sprVARval = ReadParam(4);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_SUBVALFROMSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X SUBTRACT %d FROM %s\n", event_ptr + SnapshotOffset, DataByte, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 3. ANIMATE
//--------------------------------------------

int tst_ANIMATE(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_ANIMATE, cPattern) == 0){
		sprintf (Dummy,"%04X ANIMATE\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 3. ANIMATE VERYSLOW
//--------------------------------------------

int tst_ANIMVSLOW(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Compare pattern with template

	if (strcmp(cmd_ANIMVSLOW, cPattern) == 0){
		sprintf (Dummy,"%04X ANIMATE VERYSLOW\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 3. ANIMATE SLOW
//--------------------------------------------

int tst_ANIMSLOW(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Compare pattern with template

	if (strcmp(cmd_ANIMSLOW, cPattern) == 0){
		sprintf (Dummy,"%04X ANIMATE SLOW\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 3. ANIMATE MEDIUM
//--------------------------------------------

int tst_ANIMMED(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Compare pattern with template

	if (strcmp(cmd_ANIMMED, cPattern) == 0){
		sprintf (Dummy,"%04X ANIMATE MEDIUM\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 4. ANIMBACK
//--------------------------------------------

int tst_ANIMBACK(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_ANIMBACK, cPattern) == 0){
		sprintf (Dummy,"%04X ANIMBACK\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 4. ANIMBACK VERYSLOW
//--------------------------------------------

int tst_ANIMBACKVSLOW(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Compare pattern with template

	if (strcmp(cmd_ANIMBACKVSLOW, cPattern) == 0){
		sprintf (Dummy,"%04X ANIMBACK VERYSLOW\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 4. ANIMBACK SLOW
//--------------------------------------------

int tst_ANIMBACKSLOW(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Compare pattern with template

	if (strcmp(cmd_ANIMBACKSLOW, cPattern) == 0){
		sprintf (Dummy,"%04X ANIMBACK SLOW\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 4. ANIMBACK MEDIUM
//--------------------------------------------

int tst_ANIMBACKMED(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Compare pattern with template

	if (strcmp(cmd_ANIMBACKMED, cPattern) == 0){
		sprintf (Dummy,"%04X ANIMBACK MEDIUM\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. AT ZERO,SPRVAR
//--------------------------------------------

int tst_ATZEROSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02Xxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	sprVARval = ReadParam(4);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template
	if (strcmp(cmd_ATZEROSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X AT 0 %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 6. AT VAL VAL
//--------------------------------------------

int tst_ATVALVAL(){

// Define variables

	char cPattern[64];
	int DataByte2;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour
	DataByte2 = ReadParam(2);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_ATVALVAL, cPattern) == 0){
		sprintf (Dummy,"%04X AT %d %d\n", event_ptr + SnapshotOffset, DataByte, DataByte2); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 6. AT VAL VAR
//--------------------------------------------

int tst_ATVALVAR(){

// Define variables

	char cPattern[64];
	int DataByte2;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	DataByte = ReadParam(1);
	const char *VARname = ReadVarName(3);

// Compare pattern with template

	if (strcmp(cmd_ATVALVAR, cPattern) == 0){
		sprintf (Dummy,"%04X AT %d %s\n", event_ptr + SnapshotOffset, DataByte, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. AT VAL,SPRVAR
//--------------------------------------------

int tst_ATVALSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02Xxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	DataByte = ReadParam(1);
	sprVARval = ReadParam(4);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template
	if (strcmp(cmd_ATVALSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X AT %d %s\n", event_ptr + SnapshotOffset, DataByte, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 6. AT VAR ZERO
//--------------------------------------------

int tst_ATVARZERO(){

// Define variables

	char cPattern[64];
	int DataByte2;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_ATVARZERO, cPattern) == 0){
		sprintf (Dummy,"%04X AT %s 0\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 6. AT VAR VAL
//--------------------------------------------

int tst_ATVARVAL(){

// Define variables

	char cPattern[64];
	int DataByte2;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Read parameters

	const char *VARname = ReadVarName(1);
	DataByte = ReadParam(5);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_ATVARVAL, cPattern) == 0){
		sprintf (Dummy,"%04X AT %s %d\n", event_ptr + SnapshotOffset, VARname, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 6. AT VAR VAR
//--------------------------------------------

int tst_ATVARVAR(){

// Define variables

	char cPattern[64];
	int DataByte2;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	const char *VARname1 = ReadVarName(1);
	const char *VARname2 = ReadVarName(5);

// Compare pattern with template

	if (strcmp(cmd_ATVARVAR, cPattern) == 0){
		sprintf (Dummy,"%04X AT %s %s\n", event_ptr + SnapshotOffset, VARname1, VARname2); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. AT VAR,SPRVAR
//--------------------------------------------

int tst_ATVARSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02Xxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	const char *VARname = ReadVarName(1);
	sprVARval = ReadParam(6);
	const char *sprVARname2 = ReadSprVarName(sprVARval);

// Compare pattern with template
	if (strcmp(cmd_ATVARSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X AT %s %s\n", event_ptr + SnapshotOffset, VARname, sprVARname2); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. AT SPRVAR,ZERO
//--------------------------------------------

int tst_ATSPRVARZERO(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template
	if (strcmp(cmd_ATSPRVARZERO, cPattern) == 0){
		sprintf (Dummy,"%04X AT %s 0\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. AT SPRVAR,VAL
//--------------------------------------------

int tst_ATSPRVARVAL(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02Xxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Read parameters

	DataByte = ReadParam(5);
	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template
	if (strcmp(cmd_ATSPRVARVAL, cPattern) == 0){
		sprintf (Dummy,"%04X AT %s %d\n", event_ptr + SnapshotOffset, sprVARname, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. AT SPRVAR,VAR
//--------------------------------------------

int tst_ATSPRVARVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);
	const char *VARname = ReadVarName(5);

// Compare pattern with template
	if (strcmp(cmd_ATSPRVARVAR, cPattern) == 0){
		sprintf (Dummy,"%04X AT %s %s\n", event_ptr + SnapshotOffset, sprVARname, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 2. AT SPRVAR,SPRVAR
//--------------------------------------------

int tst_ATSPRVARSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02Xxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);
	sprVARval = ReadParam(6);
	const char *sprVARname2 = ReadSprVarName(sprVARval);

// Compare pattern with template
	if (strcmp(cmd_ATSPRVARSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X AT %s %s\n", event_ptr + SnapshotOffset, sprVARname, sprVARname2); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 7. BEEP VAR
//--------------------------------------------

int tst_BEEPVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_BEEPVAR, cPattern) == 0){
		sprintf (Dummy,"%04X BEEP %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 8;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 7. BEEP VAL
//--------------------------------------------

int tst_BEEPVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_BEEPVAL, cPattern) == 0){
		sprintf (Dummy,"%04X BEEP %d\n", event_ptr + SnapshotOffset, DataByte); 
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 7. BEEP SPRVAR
//--------------------------------------------

int tst_BEEPSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_BEEPSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X BEEP %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 8;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 8. BONUS VAL
//--------------------------------------------

int tst_BONUSVAL(){

// Define variables

	char cPattern[64];
	int DataByte2;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02Xxxxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 6]);

// Read parameters

	DataByte = ReadParam(4);			// Read colour
	DataByte2 = ReadParam(5);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_BONUSVAL, cPattern) == 0){
		sprintf (Dummy,"%04X BONUS %d\n", event_ptr + SnapshotOffset, DataByte2 * 256 + DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 12;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 8. BONUS VAR
//--------------------------------------------

int tst_BONUSVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	const char *VARname = ReadVarName(4);

// Compare pattern with template

	if (strcmp(cmd_BONUSVAR, cPattern) == 0){
		sprintf (Dummy,"%04X BONUS %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 9. BORDER ZERO
//--------------------------------------------

int tst_BORDERZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_BORDERZERO, cPattern) == 0){
		sprintf (Dummy,"%04X BORDER 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 9. BORDER VAR
//--------------------------------------------

int tst_BORDERVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_BORDERVAR, cPattern) == 0){
		sprintf (Dummy,"%04X BORDER %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 9. BORDER VAL
//--------------------------------------------

int tst_BORDERVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_BORDERVAL, cPattern) == 0){
		sprintf (Dummy,"%04X BORDER %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 11. CANGODOWN
//--------------------------------------------

int tst_CANGODOWN(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_CANGODOWN, cPattern) == 0){
		sprintf (Dummy,"%04X IF CANGODOWN\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		PushIFstack(4);
//		ident++;
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 12. CANGOLEFT
//--------------------------------------------

int tst_CANGOLEFT(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_CANGOLEFT, cPattern) == 0){
		sprintf (Dummy,"%04X IF CANGOLEFT\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		PushIFstack(4);
//		ident++;
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 13. CANGORIGHT
//--------------------------------------------

int tst_CANGORIGHT(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_CANGORIGHT, cPattern) == 0){
		sprintf (Dummy,"%04X IF CANGORIGHT\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		PushIFstack(4);
//		ident++;
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 14. CANGOUP
//--------------------------------------------

int tst_CANGOUP(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_CANGOUP, cPattern) == 0){
		sprintf (Dummy,"%04X IF CANGOUP\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		PushIFstack(4);
//		ident++;
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 15. CHR VAR
//--------------------------------------------

int tst_CHRVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_CHRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X CHR %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 15. CHR VAL
//--------------------------------------------

int tst_CHRVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour


// Compare pattern with template

	if (strcmp(cmd_CHRVAL, cPattern) == 0){
		sprintf (Dummy,"%04X CHR %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 16. CLS
//--------------------------------------------

int tst_CLS(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_CLS, cPattern) == 0){
		sprintf (Dummy,"%04X CLS\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 17. CLUT ZERO
//--------------------------------------------

int tst_CLUTZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Compare pattern with template

	if (strcmp(cmd_CLUTZERO, cPattern) == 0){
		sprintf (Dummy,"%04X CLUT 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 14;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 17. CLUT VAL
//--------------------------------------------

int tst_CLUTVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour


// Compare pattern with template

	if (strcmp(cmd_CLUTVAL, cPattern) == 0){
		sprintf (Dummy,"%04X CLUT %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 17. CLUT VAR
//--------------------------------------------

int tst_CLUTVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_CLUTVAR, cPattern) == 0){
		sprintf (Dummy,"%04X CLUT %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 16;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 17. CLUT SPRVAR
//--------------------------------------------

int tst_CLUTSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_CLUTSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X CLUT %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 16;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 18. CLW
//--------------------------------------------

int tst_CLW(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_CLW, cPattern) == 0){
		sprintf (Dummy,"%04X CLW\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 19. IF COLLISION VAR
//--------------------------------------------

int tst_IFCOLLVAR(){

// Define variables

	char cPattern[64];
	char *cDir;
	int SPRval;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxxxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_IFCOLLVAR, cPattern) == 0){
		sprintf (Dummy,"%04X IF COLLISION %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		PushIFstack(8);
		event_ptr = event_ptr + 10;
//		ident++;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 19. IF COLLISION SPRVAR
//--------------------------------------------

int tst_IFCOLLSPRVAR(){
// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02Xxxxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7]);

// Read parameters

	DataByte = ReadParam(2);

// Compare pattern with template

	if (strcmp(cmd_IFCOLLSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X IF COLLISION %s\n", event_ptr + SnapshotOffset, SPRVARstring[DataByte]); 
		PrtReport(Dummy,1);
		PushIFstack(8);
		event_ptr = event_ptr + 10;
//		ident++;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 19. IF COLLISION VAL
//--------------------------------------------

int tst_IFCOLLVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02Xxxxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 5]);

// Read parameters

	DataByte = ReadParam(1);

// Compare pattern with template

	if (strcmp(cmd_TEST, cPattern) == 0){
		sprintf (Dummy,"%04X IF COLLISION %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		PushIFstack(6);
		event_ptr = event_ptr + 8;
//		ident++;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 19. IF COLLISION BULLET
//--------------------------------------------

int tst_IFCOLLBULLET(){
// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_IFCOLLBULLET, cPattern) == 0){
		sprintf (Dummy,"%04X IF COLLISION BULLET\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		PushIFstack(4);
		event_ptr = event_ptr + 6;
//		ident++;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 20. COLOUR ZERO
//--------------------------------------------

int tst_COLOURZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_COLOURZERO, cPattern) == 0){
		sprintf (Dummy,"%04X COLOUR 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}


//--------------------------------------------
// 20. COLOUR VAR
//--------------------------------------------

int tst_COLOURVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_COLOURVAR, cPattern) == 0){
		sprintf (Dummy,"%04X COLOUR %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}


//--------------------------------------------
// 20. COLOUR VAL
//--------------------------------------------

int tst_COLOURVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_COLOURVAL, cPattern) == 0){
		sprintf (Dummy,"%04X COLOUR %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 21. CRASH ZERO
//--------------------------------------------

int tst_CRASHZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Compare pattern with template

	if (strcmp(cmd_CRASHZERO, cPattern) == 0){
		sprintf (Dummy,"%04X CRASH 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 21. CRASH VAL
//--------------------------------------------

int tst_CRASHVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_CRASHVAL, cPattern) == 0){
		if (DataByte > 0x7f){
			sprintf (Dummy,"%04X CRASH %d\n", event_ptr + SnapshotOffset, DataByte - 0x80); 
			PrtReport(Dummy,1);
			event_ptr = event_ptr + 5;
		} else {
			sprintf (Dummy,"%04X BEEP %d\n", event_ptr + SnapshotOffset, DataByte); 
			PrtReport(Dummy,1);
			event_ptr = event_ptr + 5;
		}
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 21. CRASH VAR
//--------------------------------------------

int tst_CRASHVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_CRASHVAR, cPattern) == 0){
		sprintf (Dummy,"%04X CRASH %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 8;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 21. CRASH SPRVAR
//--------------------------------------------

int tst_CRASHSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_CRASHSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X CRASH %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 8;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 23. DELAY VAL
//--------------------------------------------

int tst_DELAYVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02Xxx%02Xxxxx%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	DataByte = ReadParam(3);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_DELAYVAL, cPattern) == 0){
		sprintf (Dummy,"%04X DELAY %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 23a. DEFINEKEY LEFT/RIGHT/UP/DOWN
//--------------------------------------------

int tst_DEFINEKEY(){

// Define variables

	char cPattern[64];
	int Address;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	Address = ReadAddress(event_ptr + 7) + 1 - keys;
	
//	DataByte = ReadParam(3);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_DEFINEKEY, cPattern) == 0){
		sprintf (Dummy,"%04X DEFINEKEY %s\n", event_ptr + SnapshotOffset, KeyString[Address]); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 14;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 23. DELAY VAR
//--------------------------------------------

int tst_DELAYVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02Xxxxx%02X%02Xxxxx%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 9],
		cBuff[event_ptr + 10]);

// Read parameters

	const char *VARname = ReadVarName(3);

// Compare pattern with template

	if (strcmp(cmd_DELAYVAR, cPattern) == 0){
		sprintf (Dummy,"%04X DELAY %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 24. DETECTOBJ
//--------------------------------------------

int tst_DETECTOBJ(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Compare pattern with template

	if (strcmp(cmd_DETECTOBJ, cPattern) == 0){
		sprintf (Dummy,"%04X DETECTOBJ\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 25. DIG ZERO
//--------------------------------------------

int tst_DIGZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_DIGZERO, cPattern) == 0){
		sprintf (Dummy,"%04X DIG %s\n", event_ptr + SnapshotOffset,KeyString[1]); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 25. DIG VAL
//--------------------------------------------

int tst_DIGVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);

// Compare pattern with template

	if (strcmp(cmd_DIGVAL, cPattern) == 0){
		sprintf (Dummy,"%04X DIG %s\n", event_ptr + SnapshotOffset, KeyString[DataByte+1]); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 26. DISPLAY VAR
//--------------------------------------------

int tst_DISPLAYVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_DISPLAYVAR, cPattern) == 0){
		sprintf (Dummy,"%04X DISPLAY %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 26. DISPLAY DOUBLEDIGITS VAR
//--------------------------------------------

int tst_DISPLAYDBLVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02Xxxxx%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 9]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_DISPLAYDBLVAR, cPattern) == 0){
		sprintf (Dummy,"%04X DISPLAY DOUBLEDIGITS %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 12;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 26. DISPLAY TRIPLEDIGITS VAR
//--------------------------------------------

int tst_DISPLAYTRPVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02Xxxxx%02Xxxxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 9]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_DISPLAYTRPVAR, cPattern) == 0){
		sprintf (Dummy,"%04X DISPLAY TRIPLEDIGITS %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 12;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 26. DISPLAY SECONDS VAR
//--------------------------------------------

int tst_DISPLAYSECVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_DISPLAYSECVAR, cPattern) == 0){
		sprintf (Dummy,"%04X DISPLAY SECONDS %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 28;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 27. DIVIDE VAR * VAL/VAR/SPRVAR
//--------------------------------------------

int tst_DIVVAR(){

// Define variables

	char cPattern1[64];
	char cPattern2[64];
	char cPattern3[64];
	char cPattern4[64];
	char cPattern5[64];
	char cPattern6[64];
	char cPattern7[64];
	char cPattern8[64];
	char cPattern9[64];
	char cPattern10[64];
	int sprVARval;
	
	sprintf(cPattern1, "%02Xxxxx%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5])											;	// DIV/2
	sprintf(cPattern2, "%02Xxxxx%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 6],cBuff[event_ptr + 7])	;	// DIV/4
	sprintf(cPattern3, "%02Xxxxx%02X%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 6],cBuff[event_ptr + 7],
		cBuff[event_ptr + 8])											;	// DIV/8
	sprintf(cPattern4, "%02Xxxxx%02X%02X%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 6],cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],cBuff[event_ptr + 9])						;	// DIV/16
	sprintf(cPattern5, "%02Xxxxx%02X%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 6],cBuff[event_ptr + 7],
		cBuff[event_ptr + 8])											;	// DIV/32
	sprintf(cPattern6, "%02Xxxxx%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 6],cBuff[event_ptr + 7])	;	// DIV/64
	sprintf(cPattern7, "%02Xxxxx%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 6])						;	// DIV/128
	sprintf(cPattern8, "%02Xxxxx%02X%02Xxx%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 6],cBuff[event_ptr + 7],cBuff[event_ptr + 10],
		cBuff[event_ptr + 11])											;	// DIV/VAL
	sprintf(cPattern9, "%02Xxxxx%02X%02Xxxxx%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],cBuff[event_ptr + 8],cBuff[event_ptr + 11],
		cBuff[event_ptr + 12])											;	// DIV/VAR
	sprintf(cPattern10, "%02Xxxxx%02X%02X%02Xxx%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 7],cBuff[event_ptr + 8],
		cBuff[event_ptr + 11],cBuff[event_ptr + 12])					;	// DIV/SPRVAR

	ptr_offset = 0;

// Read parameters

	const char *VARname = ReadVarName(1);
	const char *VARname1 = ReadVarName(5);
	sprVARval = ReadParam(6);
	const char *sprVARname = ReadSprVarName(sprVARval);
	DataByte = ReadParam(5);

// Compare pattern with template

	if (strcmp(cmd_DIVVAR2, cPattern1) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY 2\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 8;
		return 1;
	}
	if (strcmp(cmd_DIVVAR4, cPattern2) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY 4\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	}
	if (strcmp(cmd_DIVVAR8, cPattern3) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY 8\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	}
	if (strcmp(cmd_DIVVAR16, cPattern4) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY 16\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 12;
		return 1;
	}
	if (strcmp(cmd_DIVVAR32, cPattern5) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY 32\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	}
	if (strcmp(cmd_DIVVAR64, cPattern6) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY 64\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	}
	if (strcmp(cmd_DIVVAR128, cPattern7) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY 128\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	}
	if (strcmp(cmd_DIVVARVAL, cPattern8) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY %d\n", event_ptr + SnapshotOffset, VARname, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 14;
		return 1;
	}
	if (strcmp(cmd_DIVVARVAR, cPattern9) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY %s\n", event_ptr + SnapshotOffset, VARname, VARname1); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	}
	if (strcmp(cmd_DIVVARSPRVAR, cPattern10) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY %s\n", event_ptr + SnapshotOffset, VARname, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	}
	return 0;
}

//--------------------------------------------
// 27. DIVIDE SPRVAR * VAL/VAR/SPRVAR
//--------------------------------------------

int tst_DIVSPRVAR(){

// Define variables

	char cPattern1[64];
	char cPattern2[64];
	char cPattern3[64];
	char cPattern4[64];
	char cPattern5[64];
	char cPattern6[64];
	char cPattern7[64];
	char cPattern8[64];
	char cPattern9[64];
	char cPattern10[64];
	int sprVARval;
	int sprVARval1;
	
	sprintf(cPattern1, "%02X%02Xxx%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6])	;	// SPRVAR/2
	sprintf(cPattern2, "%02X%02Xxx%02X%02X%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],cBuff[event_ptr + 8])						;	// SPRVAR/4
	sprintf(cPattern3, "%02X%02Xxx%02X%02X%02X%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],cBuff[event_ptr + 8],cBuff[event_ptr + 9])	;	// SPRVAR/8
	sprintf(cPattern4, "%02X%02Xxx%02X%02X%02X%02X%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],cBuff[event_ptr + 8],cBuff[event_ptr + 9],
		cBuff[event_ptr + 10])											;	// SPRVAR/16
	sprintf(cPattern5, "%02X%02Xxx%02X%02X%02X%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],cBuff[event_ptr + 8],cBuff[event_ptr + 9])	;	// SPRVAR/32
	sprintf(cPattern6, "%02X%02Xxx%02X%02X%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],cBuff[event_ptr + 8])						;	// SPRVAR/64
	sprintf(cPattern7, "%02X%02Xxx%02X%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6],
		cBuff[event_ptr + 7])											;	// SPRVAR/128
	sprintf(cPattern8, "%02X%02Xxx%02X%02Xxx%02X%02Xxxxx%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 6],cBuff[event_ptr + 7],
		cBuff[event_ptr + 10],cBuff[event_ptr + 11],cBuff[event_ptr + 12]);	// SPRVAR/VAL
	sprintf(cPattern9, "%02X%02Xxx%02X%02Xxxxx%02X%02Xxxxx%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 7],cBuff[event_ptr + 8],
		cBuff[event_ptr + 11],cBuff[event_ptr + 12],cBuff[event_ptr + 13]);	// SPRVAR/VAR
	sprintf(cPattern10, "%02X%02Xxx%02X%02X%02Xxx%02X%02Xxxxx%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],cBuff[event_ptr + 11],cBuff[event_ptr + 12],
		cBuff[event_ptr + 13])											;	// SPRVAR/SPRVAR

	ptr_offset = 0;

// Read parameters

	const char *VARname = ReadVarName(5);
	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);
	sprVARval1 = ReadParam(6);
	const char *sprVARname1 = ReadSprVarName(sprVARval1);
	DataByte = ReadParam(5);

// Compare pattern with template

	if (strcmp(cmd_DIVSPRVAR2, cPattern1) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY 2\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 8;
		return 1;
	}
	if (strcmp(cmd_DIVSPRVAR4, cPattern2) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY 4\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	}
	if (strcmp(cmd_DIVSPRVAR8, cPattern3) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY 8\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	}
	if (strcmp(cmd_DIVSPRVAR16, cPattern4) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY 16\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 12;
		return 1;
	}
	if (strcmp(cmd_DIVSPRVAR32, cPattern5) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY 32\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	}
	if (strcmp(cmd_DIVSPRVAR64, cPattern6) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY 64\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	}
	if (strcmp(cmd_DIVSPRVAR128, cPattern7) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY 128\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	}
	if (strcmp(cmd_DIVSPRVARVAL, cPattern8) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY %d\n", event_ptr + SnapshotOffset, sprVARname, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 14;
		return 1;
	}
	if (strcmp(cmd_DIVSPRVARVAR, cPattern9) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY %s\n", event_ptr + SnapshotOffset, sprVARname, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	}
	if (strcmp(cmd_DIVSPRVARSPRVAR, cPattern10) == 0){
		sprintf (Dummy,"%04X DIVIDE %s BY %s\n", event_ptr + SnapshotOffset, sprVARname, sprVARname1); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	}
	return 0;
}

//--------------------------------------------
// 28. ENDGAME
//--------------------------------------------

int tst_ENDGAME(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_ENDGAME, cPattern) == 0){
		sprintf (Dummy,"%04X ENDGAME\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 30. ENDREPEAT
//--------------------------------------------

int tst_ENDREPEAT(){

// Define variables

	char cPattern[64];
	int Address;
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read paramters

	Address = ReadAddress(event_ptr + 1);

// Compare pattern with template

	if (strcmp(cmd_ENDREPEAT, cPattern) == 0){
		if (Address == 0x5c81 || Address == 0x5cb0 || Address == 0x5cb1){
//			ident--;
			sprintf (Dummy,"%04X ENDREPEAT\n", event_ptr + SnapshotOffset); 
			PrtReport(Dummy,1);
			event_ptr = event_ptr + 7;
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

//--------------------------------------------
// 31. ENDSPRITE
//--------------------------------------------

int tst_ENDSPRITE(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_ENDSPRITE, cPattern) == 0){
		sprintf (Dummy,"%04X ENDSPRITE\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 33. EXIT
//--------------------------------------------

int tst_EXIT(int Ptr){
	
	int DATAstart;
	int Offset;
	int i;
	int Flag;
	
	if ((event_ptr + SnapshotOffset) < (Event[Ptr + 1])){
		if ((event_ptr + SnapshotOffset + 1) != (Event[Ptr + 1])){
			Flag = 0;
			for (i = 0; i < 20; i++){
				if (DATAstack[i] != 0){
					if (Events < 9){
						DATAstart = ((cBuff[DATAstack[i] - SnapshotOffset + 18] << 8) + cBuff[DATAstack[i] - SnapshotOffset + 17]);
						Offset = 28;
					} else {
						DATAstart = (cBuff[DATAstack[i] - SnapshotOffset + 2] << 8) + (cBuff[DATAstack[i] - SnapshotOffset + 1]) + 2;
						Offset = 22;
					}
				}
				if (DATAstart != (event_ptr + SnapshotOffset + 3)){
					Flag = 1;
				}
			}
			if (Flag == 1){
				sprintf (Dummy,"%04X EXIT\n", event_ptr + SnapshotOffset);
				PrtReport(Dummy,1);
			}
		}
		event_ptr++;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 34. EXPLODE VAR
//--------------------------------------------

int tst_EXPLVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_EXPLVAR, cPattern) == 0){
		sprintf (Dummy,"%04X EXPLODE %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 34. EXPLODE VAL
//--------------------------------------------

int tst_EXPLVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_EXPLVAL, cPattern) == 0){
		sprintf (Dummy,"%04X EXPLODE %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 35. FALL 
//--------------------------------------------

int tst_FALL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_FALL, cPattern) == 0){
		sprintf (Dummy,"%04X FALL\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 36. GET VAR
//--------------------------------------------

int tst_GETVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_GETVAR, cPattern) == 0){
		sprintf (Dummy,"%04X GET %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 36. GET VAL
//--------------------------------------------

int tst_GETVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_GETVAL, cPattern) == 0){
		sprintf (Dummy,"%04X GET %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 37. GETBLOCK ZERO VAR 
//--------------------------------------------

int tst_GETBLKZEROVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02Xxxxx%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(3);

// Compare pattern with template

	if (strcmp(cmd_GETBLKZEROVAR, cPattern) == 0){
		sprintf (Dummy,"%04X GETBLOCK 0 %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 37. GETBLOCK ZERO SPRVAR 
//--------------------------------------------

int tst_GETBLKZEROSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02Xxx%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 5]);

// Read parameters

	sprVARval = ReadParam(4);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_GETBLKZEROSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X GETBLOCK 0,%s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 37. GETBLOCK VAR ZERO 
//--------------------------------------------

int tst_GETBLKVARZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_GETBLKVARZERO, cPattern) == 0){
		sprintf (Dummy,"%04X GETBLOCK %s,0\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 37. GETBLOCK VAR VAL
//--------------------------------------------

int tst_GETBLKVARVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	const char *VARname = ReadVarName(1);
	DataByte = ReadParam(5);

// Compare pattern with template

	if (strcmp(cmd_GETBLKVARVAL, cPattern) == 0){
		sprintf (Dummy,"%04X GETBLOCK %s,%d\n", event_ptr + SnapshotOffset, VARname, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 16;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 37. GETBLOCK VAR VAR
//--------------------------------------------

int tst_GETBLKVARVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxxxx%02X%02Xxxxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 11]);

// Read parameters

	const char *VARname1 = ReadVarName(1);
	const char *VARname2 = ReadVarName(5);

// Compare pattern with template

	if (strcmp(cmd_GETBLKVARVAR, cPattern) == 0){
		sprintf (Dummy,"%04X GETBLOCK %s,%s\n", event_ptr + SnapshotOffset, VARname1, VARname2); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 17;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 37. GETBLOCK VAR SPRVAR  
//--------------------------------------------

int tst_GETBLKVARSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02Xxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);
	sprVARval = ReadParam(6);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_GETBLKVARSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X GETBLOCK %s,%s\n", event_ptr + SnapshotOffset, VARname, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 17;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 37. GETBLOCK VAL VAL
//--------------------------------------------

int tst_GETBLKVALVAL(){

// Define variables

	char cPattern[64];
	int DataByte2;
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02Xxxxx%02Xxxxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 9]);

// Read parameters

	DataByte = ReadParam(2);
	DataByte2 = ReadParam(1);

// Compare pattern with template

	if (strcmp(cmd_GETBLKVALVAL, cPattern) == 0){
		sprintf (Dummy,"%04X GETBLOCK %d,%d\n", event_ptr + SnapshotOffset, DataByte, DataByte2); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 12;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 37. GETBLOCK VAL VAR
//--------------------------------------------

int tst_GETBLKVALVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02Xxxxx%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	const char *VARname = ReadVarName(3);
	DataByte = ReadParam(1);

// Compare pattern with template

	if (strcmp(cmd_GETBLKVALVAR, cPattern) == 0){
		sprintf (Dummy,"%04X GETBLOCK %d,%s\n", event_ptr + SnapshotOffset, DataByte, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 37. GETBLOCK VAL SPRVAR 
//--------------------------------------------

int tst_GETBLKVALSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02Xxx%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 5]);

// Read parameters

	DataByte = ReadParam(1);
	sprVARval = ReadParam(4);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_GETBLKVALSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X GETBLOCK %d,%s\n", event_ptr + SnapshotOffset, DataByte, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 37. GETBLOCK SPRVAR ZERO 
//--------------------------------------------

int tst_GETBLKSPRVARZERO(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02X%02Xxxxx%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 9]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_GETBLKSPRVARZERO, cPattern) == 0){
		sprintf (Dummy,"%04X GETBLOCK %s,0\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 37. GETBLOCK SPRVAR VAL 
//--------------------------------------------

int tst_GETBLKSPRVARVAL(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02Xxx%02X%02Xxxxx%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 10]);

// Read parameters

	DataByte = ReadParam(5);
	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_GETBLKSPRVARVAL, cPattern) == 0){
		sprintf (Dummy,"%04X GETBLOCK %s,%d\n", event_ptr + SnapshotOffset, sprVARname, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 16;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 37. GETBLOCK SPRVAR VAR  
//--------------------------------------------

int tst_GETBLKSPRVARVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02Xxxxx%02X%02Xxxxx%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 11]);

// Read parameters

	const char *VARname = ReadVarName(5);
	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_GETBLKSPRVARVAR, cPattern) == 0){
		sprintf (Dummy,"%04X GETBLOCK %s,%s\n", event_ptr + SnapshotOffset, sprVARname, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 17;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 37. GETBLOCK SPRVAR SPRVAR 
//--------------------------------------------

int tst_GETBLKSPRVARSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02Xxx%02X%02Xxxxx%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 11]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);
	sprVARval = ReadParam(6);
	const char *sprVARname1 = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_GETBLKSPRVARSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X GETBLOCK %s,%s\n", event_ptr + SnapshotOffset, sprVARname, sprVARname1); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 17;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 38. GETBLOCKS
//--------------------------------------------

int tst_GETBLOCKS(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_GETBLOCKS, cPattern) == 0){
		sprintf (Dummy,"%04X GETBLOCKS\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 39. GETRANDOM VAR
//--------------------------------------------

int tst_GETRANDOMVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxxxx%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 11],
		cBuff[event_ptr + 12]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_GETRANDOMVAR, cPattern) == 0){
		sprintf (Dummy,"%04X GETRANDOM %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 39. GETRANDOM VAL
//--------------------------------------------

int tst_GETRANDOMVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02Xxxxx%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 10],
		cBuff[event_ptr + 11]);

// Read parameters

	DataByte = ReadParam(1);

// Compare pattern with template

	if (strcmp(cmd_GETRANDOMVAL, cPattern) == 0){
		sprintf (Dummy,"%04X GETRANDOM %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 14;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 40. IF GOT ZERO
//--------------------------------------------

int tst_IFGOTZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Compare pattern with template

	if (strcmp(cmd_IFGOTZERO, cPattern) == 0){
		sprintf (Dummy,"%04X IF GOT 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		PushIFstack(5);
		event_ptr = event_ptr + 7;
//		ident++;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 40. IF GOT VAR
//--------------------------------------------

int tst_IFGOTVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_IFGOTVAR, cPattern) == 0){
		sprintf (Dummy,"%04X IF GOT %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		PushIFstack(7);
		event_ptr = event_ptr + 9;
//		ident++;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 40. IF GOT VAL
//--------------------------------------------

int tst_IFGOTVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	DataByte = ReadParam(1);

// Compare pattern with template

	if (strcmp(cmd_IFGOTVAL, cPattern) == 0){
		sprintf (Dummy,"%04X IF GOT %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		PushIFstack(6);
		event_ptr = event_ptr + 8;
//		ident++;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 41. IF/WHILE
//--------------------------------------------

int tst_IFWHILE(int Nr){

// Define variables

	char cPattern1[64];
	char cPattern2[64];
	char cPattern3[64];
	char cPattern4[64];
	char cPattern5[64];
	char cPattern6[64];
	char cPattern7[64];
	char cPattern8[64];
	char Var1[64];
	char Var2[64];
	char Oper[64];
	int JMPaddr;
	int RETaddr;
	
	sprintf(cPattern1, "%02X%02Xxxxx%02X",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 4]);	// VARZERO
	sprintf(cPattern2, "%02Xxxxx%02Xxxxx%02X",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 6]);	// VARVAR
	sprintf(cPattern3, "%02Xxxxx%02Xxxxx%02X",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 6]);	// VARSPRVAR
	sprintf(cPattern4, "%02Xxx%02Xxxxx%02X",
		cBuff[event_ptr + 0],cBuff[event_ptr + 2],cBuff[event_ptr + 5]);	// VARVAL
	sprintf(cPattern5, "%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 2]);	// SPRVARZERO
	sprintf(cPattern6, "%02Xxxxx%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4]);	// SPRVARVAR
	sprintf(cPattern7, "%02X%02Xxx%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],cBuff[event_ptr + 4]);	// SPRVARSPRVAR
	sprintf(cPattern8, "%02Xxx%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 2],cBuff[event_ptr + 3]);	// SPRVARVAL

	ptr_offset = 0;
	
	switch (Nr){

		// VAR
		case 1:
			if (strcmp(cmd_IFVARVAR, cPattern2) == 0){
				strcpy(Var1, VARstring[GetVarName(4)]); 
				strcpy(Oper, OPstring[GetOperator(7)]); 
				strcpy(Var2, VARstring[GetVarName(1)]); 
				JMPaddr = ReadAddress(event_ptr + ptr_offset + 5) - SnapshotOffset;
				RETaddr = (cBuff[JMPaddr -1] << 8) + cBuff[JMPaddr - 2];
				if (RETaddr == event_ptr + SnapshotOffset){
					sprintf (Dummy,"%04X WHILE %s %s %s\n",event_ptr + SnapshotOffset,Var1, Oper, Var2); 
					PrtReport(Dummy,1);
					PushWHILEstack(JMPaddr + SnapshotOffset);
				} else {
					sprintf (Dummy,"%04X IF %s %s %s\n",event_ptr + SnapshotOffset, Var1, Oper, Var2);
					PrtReport(Dummy,1);
					PushIFstack(ptr_offset + 5);
				}
				ptr_offset = ptr_offset + 7;
//				ident++;
				break;
			}
			if (strcmp(cmd_IFSPRVARVAR, cPattern6) == 0){
				strcpy(Var1, SPRVARstring[GetSprVarName(5)]); 
				strcpy(Oper, OPstring[GetOperator(6)]); 
				strcpy(Var2, VARstring[GetVarName(1)]); 
				JMPaddr = ReadAddress(event_ptr + ptr_offset + 4) - SnapshotOffset;
				RETaddr = (cBuff[JMPaddr -1] << 8) + cBuff[JMPaddr - 2];
				if (RETaddr == event_ptr + SnapshotOffset){
					sprintf (Dummy,"%04X WHILE %s %s %s\n",event_ptr + SnapshotOffset,Var1, Oper, Var2); 
					PrtReport(Dummy,1);
					PushWHILEstack(JMPaddr + SnapshotOffset);
				} else {
					sprintf (Dummy,"%04X IF %s %s %s\n",event_ptr + SnapshotOffset, Var1, Oper, Var2);
					PrtReport(Dummy,1);
					PushIFstack(ptr_offset + 4);
				}
				ptr_offset = ptr_offset + 6;
//				ident++;
				break;
			}
			return 0;

		// VAL
		case 2:
			if (strcmp(cmd_IFVARVAL, cPattern4) == 0){
				strcpy(Var1, VARstring[GetVarName(3)]); 
				strcpy(Oper, OPstring[GetOperator(6)]); 
				sprintf(Var2, "%d", ReadParam(1)); 
				if (strcmp(Var1,"BLOCK") == 0){
					strcpy(Var2, BlockType[ReadParam(1)]);
				}
				JMPaddr = ReadAddress(event_ptr + ptr_offset + 4) - SnapshotOffset;
				RETaddr = (cBuff[JMPaddr -1] << 8) + cBuff[JMPaddr - 2];
				if (RETaddr == event_ptr + SnapshotOffset){
					sprintf (Dummy,"%04X WHILE %s %s %s\n",event_ptr + SnapshotOffset,Var1, Oper, Var2); 
					PrtReport(Dummy,1);
					PushWHILEstack(JMPaddr + SnapshotOffset);
				} else {
					sprintf (Dummy,"%04X IF %s %s %s\n",event_ptr + SnapshotOffset, Var1, Oper, Var2);
					PrtReport(Dummy,1);
					PushIFstack(ptr_offset + 4);
				}
				ptr_offset = ptr_offset + 6;
//				ident++;
				break;
			}
			if (strcmp(cmd_IFSPRVARVAL, cPattern8) == 0){
				strcpy(Var1, SPRVARstring[GetSprVarName(4)]); 
				strcpy(Oper, OPstring[GetOperator(5)]); 
				sprintf(Var2, "%d", ReadParam(1)); 
				JMPaddr = ReadAddress(event_ptr + ptr_offset + 3) - SnapshotOffset;
				RETaddr = (cBuff[JMPaddr -1] << 8) + cBuff[JMPaddr - 2];
				if (RETaddr == event_ptr + SnapshotOffset){
					sprintf (Dummy,"%04X WHILE %s %s %s\n",event_ptr + SnapshotOffset,Var1, Oper, Var2); 
					PrtReport(Dummy,1);
					PushWHILEstack(JMPaddr + SnapshotOffset);
				} else {
					sprintf (Dummy,"%04X IF %s %s %s\n",event_ptr + SnapshotOffset, Var1, Oper, Var2);
					PrtReport(Dummy,1);
					PushIFstack(ptr_offset + 3);
				}
				ptr_offset = ptr_offset + 5;
//				ident++;
				break;
			}
			return 0;

		// ZERO
		case 3:
			if (strcmp(cmd_IFVARZERO, cPattern1) == 0){
				strcpy(Var1, VARstring[GetVarName(2)]); 
				strcpy(Oper, OPstring[GetOperator(5)]); 
				strcpy(Var2, "0"); 
				JMPaddr = ReadAddress(event_ptr + ptr_offset + 3) - SnapshotOffset;
				RETaddr = (cBuff[JMPaddr -1] << 8) + cBuff[JMPaddr - 2];
				if (RETaddr == event_ptr + SnapshotOffset){
					sprintf (Dummy,"%04X WHILE %s %s %s\n",event_ptr + SnapshotOffset,Var1, Oper, Var2); 
					PrtReport(Dummy,1);
					PushWHILEstack(JMPaddr + SnapshotOffset);
				} else {
					sprintf (Dummy,"%04X IF %s %s %s\n",event_ptr + SnapshotOffset, Var1, Oper, Var2);
					PrtReport(Dummy,1);
					PushIFstack(ptr_offset + 3);
				}
				ptr_offset = ptr_offset + 5;
//				ident++;
				break;
			}
			if (strcmp(cmd_IFSPRVARZERO, cPattern5) == 0){
				strcpy(Var1, SPRVARstring[GetSprVarName(3)]); 
				strcpy(Oper, OPstring[GetOperator(4)]); 
				strcpy(Var2, "0"); 
				JMPaddr = ReadAddress(event_ptr + ptr_offset + 2) - SnapshotOffset;
				RETaddr = (cBuff[JMPaddr -1] << 8) + cBuff[JMPaddr - 2];
				if (RETaddr == event_ptr + SnapshotOffset){
					sprintf (Dummy,"%04X WHILE %s %s %s\n",event_ptr + SnapshotOffset,Var1, Oper, Var2); 
					PrtReport(Dummy,1);
					PushWHILEstack(JMPaddr + SnapshotOffset);
				} else {
					sprintf (Dummy,"%04X IF %s %s %s\n",event_ptr + SnapshotOffset, Var1, Oper, Var2);
					PrtReport(Dummy,1);
					PushIFstack(ptr_offset + 2);
				}
				ptr_offset = ptr_offset + 4;
//				ident++;
				break;
			}
			return 0;

		// SPRVAR
		case 4:
			if (strcmp(cmd_IFVARSPRVAR, cPattern3) == 0){
				strcpy(Var1, VARstring[GetVarName(4)]); 
				strcpy(Oper, OPstring[GetOperator(7)]); 
				strcpy(Var2, SPRVARstring[GetSprVarName(2)]); 
				JMPaddr = ReadAddress(event_ptr + ptr_offset + 5) - SnapshotOffset;
				RETaddr = (cBuff[JMPaddr -1] << 8) + cBuff[JMPaddr - 2];
				if (RETaddr == event_ptr + SnapshotOffset){
					sprintf (Dummy,"%04X WHILE %s %s %s\n",event_ptr + SnapshotOffset,Var1, Oper, Var2); 
					PrtReport(Dummy,1);
					PushWHILEstack(JMPaddr + SnapshotOffset);
				} else {
					sprintf (Dummy,"%04X IF %s %s %s\n",event_ptr + SnapshotOffset, Var1, Oper, Var2);
					PrtReport(Dummy,1);
					PushIFstack(ptr_offset + 5);
				}
				ptr_offset = ptr_offset + 7;
//				ident++;
				break;
			}
			if (strcmp(cmd_IFSPRVARSPRVAR, cPattern7) == 0){
				strcpy(Var1, SPRVARstring[GetSprVarName(5)]); 
				strcpy(Oper, OPstring[GetOperator(6)]); 
				strcpy(Var2, SPRVARstring[GetSprVarName(2)]); 
				JMPaddr = ReadAddress(event_ptr + ptr_offset + 4) - SnapshotOffset;
				RETaddr = (cBuff[JMPaddr -1] << 8) + cBuff[JMPaddr - 2];
				if (RETaddr == event_ptr + SnapshotOffset){
					sprintf (Dummy,"%04X WHILE %s %s %s\n",event_ptr + SnapshotOffset,Var1, Oper, Var2); 
					PrtReport(Dummy,1);
					PushWHILEstack(JMPaddr + SnapshotOffset);
				} else {
					sprintf (Dummy,"%04X IF %s %s %s\n",event_ptr + SnapshotOffset, Var1, Oper, Var2);
					PrtReport(Dummy,1);
					PushIFstack(ptr_offset + 4);
				}
				ptr_offset = ptr_offset + 6;
//				ident++;
				break;
			}
			return 0;
			
		default:
			return 0;
	}
	event_ptr = event_ptr + ptr_offset;
	return 1;
}

//--------------------------------------------
// 42. IF CUSTOM
//--------------------------------------------

int tst_IFCUSTOM(){

// Define variables

	char cPattern[64];
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Compare pattern with template

	if (strcmp(cmd_IFCUSTOM, cPattern) == 0){
		sprintf (Dummy,"%04X IF CUSTOM\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		PushIFstack(7);
		event_ptr = event_ptr + 9;
//		ident++;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 43. IF DEADLY
//--------------------------------------------

int tst_IFDEADLY(){

// Define variables

	char cPattern[64];
	int Address;
	int JMPaddr;
	int RETaddr;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Compare pattern with template

	if (strcmp(cmd_IFDEADLY, cPattern) == 0){
		sprintf (Dummy,"%04X IF DEADLY\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		PushIFstack(7);
		event_ptr = event_ptr + 9;
//		ident++;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 44. IF KEY LEFT/RIGHT/UP/DOWN/FIRE/FIRE1/FIRE2
//--------------------------------------------

int tst_IFKEY(){

// Define variables

	char cPattern[64];
	char *cDir;
	int JMPaddr;
	int RETaddr;
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02Xxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 5]);

// Read parameters

	DataByte = ReadParam(4);			// Read direction

// Get direction

	switch (DataByte){
			case  1: 
				cDir = "RIGHT";
				break;		
			case  2: 
				cDir = "LEFT";		
				break;		
			case  4: 
				cDir = "DOWN";		
				break;		
			case  8: 
				cDir = "UP";	
				break;		
			case 16: 
				cDir = "FIRE1";		
				break;		
			case 32: 
				cDir = "FIRE2";		
				break;		
			case 64: 
				cDir = "FIRE3";		
				break;		
			default: 
				cDir = "???";
		}

// Compare pattern with template

	if (strcmp(cmd_IFKEY, cPattern) == 0){

// Check if command is WHILE

		JMPaddr = ((cBuff[event_ptr + 7] << 8) + cBuff[event_ptr + 6]) - SnapshotOffset;
		RETaddr = (cBuff[JMPaddr - 1] << 8) + cBuff[JMPaddr - 2] - SnapshotOffset;
		if (RETaddr == event_ptr){
			sprintf (Dummy,"%04X WHILE KEY %s\n", event_ptr + SnapshotOffset, cDir); 
			PrtReport(Dummy,1);
			PushWHILEstack(JMPaddr + SnapshotOffset);
			event_ptr = event_ptr + 6;
		} else {
			sprintf (Dummy,"%04X IF KEY %s\n", event_ptr + SnapshotOffset, cDir); 
			PrtReport(Dummy,1);
			PushIFstack(6);
		}
		event_ptr = event_ptr + 8;
//		ident++;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 44. IF KEY OPTION
//--------------------------------------------

int tst_IFKEYOPTION(){

// Define variables

	char cPattern[64];
	int Address;
	int JMPaddr;
	int RETaddr;
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02Xxxxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 6]);

// Compare pattern with template

	if (strcmp(cmd_IFKEYOPTION, cPattern) == 0){
		Address = ((cBuff[event_ptr + 2] << 8) + cBuff[event_ptr + 1]) - keys;
// Check if command is WHILE

		JMPaddr = ((cBuff[event_ptr + 8] << 8) + cBuff[event_ptr + 7]) - SnapshotOffset;
		RETaddr = (cBuff[JMPaddr - 1] << 8) + cBuff[JMPaddr - 2] - SnapshotOffset;
		if (RETaddr == event_ptr){
			sprintf (Dummy,"%04X WHILE KEY OPTION%d\n", event_ptr + SnapshotOffset, Address - 6); 
			PrtReport(Dummy,1);
			PushWHILEstack(JMPaddr + SnapshotOffset);
		} else {
			sprintf (Dummy,"%04X IF KEY OPTION%d\n", event_ptr + SnapshotOffset, Address - 6); 
			PrtReport(Dummy,1);
			PushIFstack(7);
		}
		event_ptr = event_ptr + 9;
//		ident++;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 45. LADDERABOVE
//--------------------------------------------

int tst_LADDERABOVE(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_LADDERABOVE, cPattern) == 0){
		sprintf (Dummy,"%X IF LADDERABOVE\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		PushIFstack(4);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 46. LADDERBELOW
//--------------------------------------------

int tst_LADDERBELOW(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_LADDERBELOW, cPattern) == 0){
		sprintf (Dummy,"%04X IF LADDERBELOW\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		PushIFstack(4);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 47. INK ZERO
//--------------------------------------------

int tst_INKZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 9],
		cBuff[event_ptr + 10],
		cBuff[event_ptr + 11]);

// Compare pattern with template

	if (strcmp(cmd_INKZERO, cPattern) == 0){
		sprintf (Dummy,"%04X INK 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 12;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 47. INK VAR
//--------------------------------------------

int tst_INKVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 9],
		cBuff[event_ptr + 10],
		cBuff[event_ptr + 11],
		cBuff[event_ptr + 12],
		cBuff[event_ptr + 13]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_INKVAR, cPattern) == 0){
		sprintf (Dummy,"%04X INK %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 14;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 47. INK VAL
//--------------------------------------------

int tst_INKVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 9],
		cBuff[event_ptr + 10],
		cBuff[event_ptr + 11],
		cBuff[event_ptr + 12]);

// Read parameters

	DataByte = ReadParam(1);

// Compare pattern with template

	if (strcmp(cmd_INKVAL, cPattern) == 0){
		sprintf (Dummy,"%04X INK %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 13;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 48. INV ZERO
//--------------------------------------------

int tst_INVZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_INVZERO, cPattern) == 0){
		sprintf (Dummy,"%04X INV 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 48. INV VAL
//--------------------------------------------

int tst_INVVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);

// Compare pattern with template

	if (strcmp(cmd_INVVAL, cPattern) == 0){
		sprintf (Dummy,"%04X INV %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 48. INV VAR
//--------------------------------------------

int tst_INVVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_INVVAR, cPattern) == 0){
		sprintf (Dummy,"%04X INV %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 48. INV SPRVAR
//--------------------------------------------

int tst_INVSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_INVSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X INV %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 49. JUMP VAL
//--------------------------------------------

int tst_JUMPVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);

// Compare pattern with template

	if (strcmp(cmd_JUMPVAL, cPattern) == 0){
		sprintf (Dummy,"%04X JUMP %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 49. JUMP ZERO
//--------------------------------------------

int tst_JUMPZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_JUMPZERO, cPattern) == 0){
		sprintf (Dummy,"%04X JUMP 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 49. JUMP VAR
//--------------------------------------------

int tst_JUMPVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_JUMPVAR, cPattern) == 0){
		sprintf (Dummy,"%04X JUMP %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 49. JUMP SPRVAR
//--------------------------------------------

int tst_JUMPSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template
	if (strcmp(cmd_JUMPSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X JUMP %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 50. KILL
//--------------------------------------------

int tst_KILL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_KILL, cPattern) == 0){
		sprintf (Dummy,"%04X KILL\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 51. LASER ZERO
//--------------------------------------------

int tst_LASERZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_LASERZERO, cPattern) == 0){
		sprintf (Dummy,"%04X LASER 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 51. LASER VAL
//--------------------------------------------

int tst_LASERVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);

// Compare pattern with template

	if (strcmp(cmd_LASERVAL, cPattern) == 0){
		sprintf (Dummy,"%04X LASER %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 51. LASER VAR
//--------------------------------------------

int tst_LASERVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_LASERVAR, cPattern) == 0){
		sprintf (Dummy,"%04X LASER %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 51. LASER SPRVAR
//--------------------------------------------

int tst_LASERSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_LASERSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X LASER %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 52. LET VAR = 0
//--------------------------------------------

int tst_LETVAREQZERO(){

// Define variables

	char cPattern[64];
	int Address;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1]);

// Read parameters

	const char *VARname = ReadVarName(2);

// Compare pattern with template

	if (strcmp(cmd_LETVAREQZERO, cPattern) == 0){
		sprintf (Dummy,"%04X LET %s = 0\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		if (VARname == "SCREEN") event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 52. LET VAR = VAR
//--------------------------------------------

int tst_LETVAREQVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3]);

// Read parameters

	const char *VARname1 = ReadVarName(4);
	const char *VARname2 = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_LETVAREQVAR, cPattern) == 0){
		sprintf (Dummy,"%04X LET %s = %s\n", event_ptr + SnapshotOffset, VARname1, VARname2); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		if (VARname1 == "SCREEN") event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 52. LET VAR = SPRVAR
//--------------------------------------------

int tst_LETVAREQSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3]);

// Read parameters

	const char *VARname = ReadVarName(4);
	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_LETVAREQSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X LET %s = %s\n", event_ptr + SnapshotOffset, VARname, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		if (VARname == "SCREEN") event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 52. LET VAR = VAL
//--------------------------------------------

int tst_LETVAREQVAL(){

// Define variables

	char cPattern[64];
	int Address;
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2]);

// Read parameters

	DataByte = ReadParam(1);
	
	const char *VARname = ReadVarName(3);

// Compare pattern with template

	if (strcmp(cmd_LETVAREQVAL, cPattern) == 0){
		sprintf (Dummy,"%04X LET %s = %d\n", event_ptr + SnapshotOffset, VARname, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		if (VARname == "SCREEN") event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 52. LET SPRVAR = 0
//--------------------------------------------

int tst_LETSPRVAREQZERO(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02Xxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Read parameters

	sprVARval = ReadParam(3);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_LETSPRVAREQZERO, cPattern) == 0){
		sprintf (Dummy,"%04X LET %s = 0\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 52. LET SPRVAR = VAR
//--------------------------------------------

int tst_LETSPRVAREQVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	const char *VARname = ReadVarName(1);
	sprVARval = ReadParam(5);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_LETSPRVAREQVAR, cPattern) == 0){
		sprintf (Dummy,"%04X LET %s = %s\n", event_ptr + SnapshotOffset, sprVARname, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 52. LET SPRVAR = SPRVAR
//--------------------------------------------

int tst_LETSPRVAREQSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02Xxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);
	sprVARval = ReadParam(5);
	const char *sprVARname2 = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_LETSPRVAREQSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X LET %s = %s\n", event_ptr + SnapshotOffset, sprVARname2, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 52. LET SPRVAL =  VAL
//--------------------------------------------

int tst_LETSPRVAREQVAL(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02Xxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour
	sprVARval = ReadParam(4);

	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_LETSPRVAREQVAL, cPattern) == 0){
		sprintf (Dummy,"%04X LET %s = %d\n", event_ptr + SnapshotOffset, sprVARname, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 53. MENU ZERO
//--------------------------------------------

int tst_MENUZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_MENUZERO, cPattern) == 0){
		sprintf (Dummy,"%04X MENU 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 53. MENU VAL
//--------------------------------------------

int tst_MENUVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);

// Compare pattern with template

	if (strcmp(cmd_MENUVAL, cPattern) == 0){
		sprintf (Dummy,"%04X MENU %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 53. MENU VAR
//--------------------------------------------

int tst_MENUVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_MENUVAR, cPattern) == 0){
		sprintf (Dummy,"%04X MENU %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 53. MENU SPRVAR
//--------------------------------------------

int tst_MENUSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_MENUSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X MENU %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 54. MESSAGE ZERO
//--------------------------------------------

int tst_MESSAGEZERO(){

// Define variables

	char cPattern[64];
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_MESSAGEZERO, cPattern) == 0){
		sprintf (Dummy,"%04X MESSAGE 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 54. MESSAGE VAR
//--------------------------------------------

int tst_MESSAGEVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_MESSAGEVAR, cPattern) == 0){
		sprintf (Dummy,"%04X MESSAGE %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 54. MESSAGE VAL
//--------------------------------------------

int tst_MESSAGEVAL(){
// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_MESSAGEVAL, cPattern) == 0){
		sprintf (Dummy,"%04X MESSAGE %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 55. MULTIPLY VAR * VAL/VAR/SPRVAR
//--------------------------------------------

int tst_MULVAR(){

// Define variables

	char cPattern1[64];
	char cPattern2[64];
	char cPattern3[64];
	char cPattern3a[64];
	char cPattern3b[64];
	char cPattern4[64];
	char cPattern4a[64];
	char cPattern5[64];
	char cPattern6[64];
	char cPattern7[64];
	char cPattern8[64];
	char cPattern9[64];
	char cPattern10[64];
	char cPattern11[64];
	int sprVARval;
	
	sprintf(cPattern1, "%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4])	;	// VAR*2
	sprintf(cPattern2, "%02Xxxxx%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 6])						;	// VAR*3
	sprintf(cPattern3, "%02Xxxxx%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5])											;	// VAR*4
	sprintf(cPattern3a, "%02Xxxxx%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 6],cBuff[event_ptr + 7])	;	// VAR*5
	sprintf(cPattern3b, "%02Xxxxx%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 6],cBuff[event_ptr + 7])	;	// VAR*6
	sprintf(cPattern4, "%02Xxxxx%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 6])						;	// VAR*8
	sprintf(cPattern4a, "%02Xxxxx%02X%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 6],cBuff[event_ptr + 7],
		cBuff[event_ptr + 8])											;	// VAR*10
	sprintf(cPattern5, "%02Xxxxx%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 6],cBuff[event_ptr + 7])	;	// VAR*16
	sprintf(cPattern6, "%02Xxxxx%02X%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 6],cBuff[event_ptr + 7],
		cBuff[event_ptr + 8])											;	// VAR*32
	sprintf(cPattern7, "%02Xxxxx%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 6],cBuff[event_ptr + 7])	;	// VAR*64
	sprintf(cPattern8, "%02Xxxxx%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 6])						;	// VAR*128
	sprintf(cPattern9, "%02Xxxxx%02X%02Xxx%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 6],cBuff[event_ptr + 7],cBuff[event_ptr + 10],
		cBuff[event_ptr + 11])											;	// VAR*VAL
	sprintf(cPattern10, "%02Xxxxx%02X%02Xxxxx%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],cBuff[event_ptr + 8],cBuff[event_ptr + 11],
		cBuff[event_ptr + 12])											;	// VAR*VAR
	sprintf(cPattern11, "%02Xxxxx%02X%02X%02Xxx%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 3],cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],cBuff[event_ptr + 7],cBuff[event_ptr + 8],
		cBuff[event_ptr + 11],cBuff[event_ptr + 12])					;	// VAR*SPRVAR

	ptr_offset = 0;

// Read parameters

	const char *VARname = ReadVarName(1);
	const char *VARname1 = ReadVarName(5);
	sprVARval = ReadParam(6);
	const char *sprVARname = ReadSprVarName(sprVARval);
	DataByte = ReadParam(5);

// Compare pattern with template

	if (strcmp(cmd_MULVAR2, cPattern1) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 2\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 7;
		return 1;
	}
	if (strcmp(cmd_MULVAR3, cPattern2) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 3\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	}
	if (strcmp(cmd_MULVAR4, cPattern3) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 4\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 8;
		return 1;
	}
	if (strcmp(cmd_MULVAR5, cPattern3a) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 5\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	}
	if (strcmp(cmd_MULVAR6, cPattern3b) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 6\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	}
	if (strcmp(cmd_MULVAR8, cPattern4) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 8\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	}
	if (strcmp(cmd_MULVAR10, cPattern4a) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 10\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	}
	if (strcmp(cmd_MULVAR16, cPattern5) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 16\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	}
	if (strcmp(cmd_MULVAR32, cPattern6) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 32\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	}
	if (strcmp(cmd_MULVAR64, cPattern7) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 64\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	}
	if (strcmp(cmd_MULVAR128, cPattern8) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 128\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	}
	if (strcmp(cmd_MULVARVAL, cPattern9) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY %d\n", event_ptr + SnapshotOffset, VARname, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 14;
		return 1;
	}
	if (strcmp(cmd_MULVARVAR, cPattern10) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY %s\n", event_ptr + SnapshotOffset, VARname, VARname1); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	}
	if (strcmp(cmd_MULVARSPRVAR, cPattern11) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY %s\n", event_ptr + SnapshotOffset, VARname, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	}
	return 0;
}

//--------------------------------------------
// 55. MULTIPLY SPRVAR * VAL/VAR/SPRVAR
//--------------------------------------------

int tst_MULSPRVAR(){

// Define variables

	char cPattern1[64];
	char cPattern2[64];
	char cPattern3[64];
	char cPattern3a[64];
	char cPattern3b[64];
	char cPattern4[64];
	char cPattern4a[64];
	char cPattern5[64];
	char cPattern6[64];
	char cPattern7[64];
	char cPattern8[64];
	char cPattern9[64];
	char cPattern10[64];
	char cPattern11[64];
	int sprVARval;
	int sprVARval1;
	
	sprintf(cPattern1, "%02X%02Xxx%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5])						;	// SPRVAR*2
	sprintf(cPattern2, "%02X%02Xxx%02X%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6],
		cBuff[event_ptr + 7])											;	// SPRVAR*3
	sprintf(cPattern3, "%02X%02Xxx%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6])	;	// SPRVAR*4
	sprintf(cPattern3a, "%02X%02Xxx%02X%02X%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],cBuff[event_ptr + 8])						;	// SPRVAR*5
	sprintf(cPattern3b, "%02X%02Xxx%02X%02X%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],cBuff[event_ptr + 8])						;	// SPRVAR*6
	sprintf(cPattern4, "%02X%02Xxx%02X%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6],
		cBuff[event_ptr + 7])											;	// SPRVAR*8
	sprintf(cPattern4a, "%02X%02Xxx%02X%02X%02X%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],cBuff[event_ptr + 8],cBuff[event_ptr + 9])	;	// SPRVAR*10
	sprintf(cPattern5, "%02X%02Xxx%02X%02X%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],cBuff[event_ptr + 8])						;	// SPRVAR*16
	sprintf(cPattern6, "%02X%02Xxx%02X%02X%02X%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],cBuff[event_ptr + 8],cBuff[event_ptr + 9])	;	// SPRVAR*32
	sprintf(cPattern7, "%02X%02Xxx%02X%02X%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],cBuff[event_ptr + 8])						;	// SPRVAR*64
	sprintf(cPattern8, "%02X%02Xxx%02X%02X%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 6],
		cBuff[event_ptr + 7])											;	// SPRVAR*128
	sprintf(cPattern9, "%02X%02Xxx%02X%02Xxx%02X%02Xxxxx%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 6],cBuff[event_ptr + 7],
		cBuff[event_ptr + 10],cBuff[event_ptr + 11],cBuff[event_ptr + 12]);	// SPRVAR*VAL
	sprintf(cPattern10, "%02X%02Xxx%02X%02Xxxxx%02X%02Xxxxx%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 7],cBuff[event_ptr + 8],
		cBuff[event_ptr + 11],cBuff[event_ptr + 12],cBuff[event_ptr + 13]);	// SPRVAR*VAR
	sprintf(cPattern11, "%02X%02Xxx%02X%02X%02Xxx%02X%02Xxxxx%02X%02X%02Xxx",
		cBuff[event_ptr + 0],cBuff[event_ptr + 1],cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],cBuff[event_ptr + 5],cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],cBuff[event_ptr + 11],cBuff[event_ptr + 12],
		cBuff[event_ptr + 13])											;	// SPRVAR*SPRVAR

	ptr_offset = 0;

// Read parameters

	const char *VARname = ReadVarName(5);
	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);
	sprVARval1 = ReadParam(6);
	const char *sprVARname1 = ReadSprVarName(sprVARval1);
	DataByte = ReadParam(5);

// Compare pattern with template

	if (strcmp(cmd_MULSPRVAR2, cPattern1) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 2\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 7;
		return 1;
	}
	if (strcmp(cmd_MULSPRVAR3, cPattern2) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 3\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	}
	if (strcmp(cmd_MULSPRVAR4, cPattern3) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 4\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 8;
		return 1;
	}
	if (strcmp(cmd_MULSPRVAR5, cPattern3a) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 5\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	}
	if (strcmp(cmd_MULSPRVAR6, cPattern3b) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 6\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	}
	if (strcmp(cmd_MULSPRVAR8, cPattern4) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 8\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	}
	if (strcmp(cmd_MULSPRVAR10, cPattern4a) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 10\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	}
	if (strcmp(cmd_MULSPRVAR16, cPattern5) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 16\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	}
	if (strcmp(cmd_MULSPRVAR32, cPattern6) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 32\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	}
	if (strcmp(cmd_MULSPRVAR64, cPattern7) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 64\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	}
	if (strcmp(cmd_MULSPRVAR128, cPattern8) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY 128\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	}
	if (strcmp(cmd_MULSPRVARVAL, cPattern9) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY %d\n", event_ptr + SnapshotOffset, sprVARname, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 14;
		return 1;
	}
	if (strcmp(cmd_MULSPRVARVAR, cPattern10) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY %s\n", event_ptr + SnapshotOffset, sprVARname, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	}
	if (strcmp(cmd_MULSPRVARSPRVAR, cPattern11) == 0){
		sprintf (Dummy,"%04X MULTIPLY %s BY %s\n", event_ptr + SnapshotOffset, sprVARname, sprVARname1); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	}
	return 0;
}

//--------------------------------------------
// 57. NEXTLEVEL
//--------------------------------------------

int tst_NEXTLEVEL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_NEXTLEVEL, cPattern) == 0){
		sprintf (Dummy,"%04X NEXTLEVEL\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 58. OTHER
//--------------------------------------------

int tst_OTHER(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_OTHER, cPattern) == 0){
		sprintf (Dummy,"%04X OTHER\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 60. PAPER ZERO
//--------------------------------------------

int tst_PAPERZERO(){

// Define variables

	char cPattern[64];
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Compare pattern with template

	if (strcmp(cmd_PAPERZERO, cPattern) == 0){
		sprintf (Dummy,"%04X PAPER 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 15;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 60. PAPER VAL
//--------------------------------------------

int tst_PAPERVAL(){
// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_PAPERVAL, cPattern) == 0){
		sprintf (Dummy,"%04X PAPER %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 16;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 60. PAPER VAR
//--------------------------------------------

int tst_PAPERVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 9]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_PAPERVAR, cPattern) == 0){
		sprintf (Dummy,"%04X PAPER %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 17;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 66. PLOT VAL VAL
//--------------------------------------------

int tst_PLOTVALVAL(){

// Define variables

	char cPattern[64];
	int DataByte2;
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	DataByte = ReadParam(2);
	DataByte2 = ReadParam(1);

// Compare pattern with template

	if (strcmp(cmd_PLOTVALVAL, cPattern) == 0){
		sprintf (Dummy,"%04X PLOT %d,%d\n", event_ptr + SnapshotOffset, DataByte, DataByte2); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 66. PLOT VAL VAR
//--------------------------------------------

int tst_PLOTVALVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02Xxxxx%02X%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 9],
		cBuff[event_ptr + 10],
		cBuff[event_ptr + 11]);

// Read parameters

	const char *VARname = ReadVarName(3);
	DataByte = ReadParam(1);

// Compare pattern with template

	if (strcmp(cmd_PLOTVALVAR, cPattern) == 0){
		sprintf (Dummy,"%04X PLOT %d,%s\n", event_ptr + SnapshotOffset, DataByte, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 12;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 66. PLOT VAL SPRVAR 
//--------------------------------------------

int tst_PLOTVALSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02Xxx%02X%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 9],
		cBuff[event_ptr + 10],
		cBuff[event_ptr + 11]);

// Read parameters

	DataByte = ReadParam(1);
	sprVARval = ReadParam(4);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_PLOTVALSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X PLOT %d,%s\n", event_ptr + SnapshotOffset, DataByte, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 12;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 66. PLOT VAR ZERO
//--------------------------------------------

int tst_PLOTVARZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 9],
		cBuff[event_ptr + 10],
		cBuff[event_ptr + 11]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_PLOTVARZERO, cPattern) == 0){
		sprintf (Dummy,"%04X PLOT %s,0\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 12;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 66. PLOT VAR VAL
//--------------------------------------------

int tst_PLOTVARVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxx%02X%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 10],
		cBuff[event_ptr + 11],
		cBuff[event_ptr + 12]);

// Read parameters

	const char *VARname = ReadVarName(1);
	DataByte = ReadParam(5);

// Compare pattern with template

	if (strcmp(cmd_PLOTVARVAL, cPattern) == 0){
		sprintf (Dummy,"%04X PLOT %s,%d\n", event_ptr + SnapshotOffset, VARname, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 13;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 66. PLOT VAR VAR
//--------------------------------------------

int tst_PLOTVARVAR(){

// Define variables

	char cPattern[64];
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxxxx%02X%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 11],
		cBuff[event_ptr + 12],
		cBuff[event_ptr + 13]);

// Read parameters

	const char *VARname = ReadVarName(1);
	const char *VARname2 = ReadVarName(5);

// Compare pattern with template

	if (strcmp(cmd_PLOTVARVAR, cPattern) == 0){
		sprintf (Dummy,"%04X PLOT %s,%s\n", event_ptr + SnapshotOffset, VARname, VARname2); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 14;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 66. PLOT VAR SPRVAR 
//--------------------------------------------

int tst_PLOTVARSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02Xxx%02X%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 11],
		cBuff[event_ptr + 12],
		cBuff[event_ptr + 13]);

// Read parameters

	const char *VARname = ReadVarName(1);
	sprVARval = ReadParam(6);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_PLOTVARSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X PLOT %s,%s\n", event_ptr + SnapshotOffset, VARname, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 14;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 66. PLOT SPRVAR ZERO 
//--------------------------------------------

int tst_PLOTSPRVARZERO(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02X%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 9],
		cBuff[event_ptr + 10],
		cBuff[event_ptr + 11]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_PLOTSPRVARZERO, cPattern) == 0){
		sprintf (Dummy,"%04X PLOT %s,0\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 12;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 66. PLOT SPRVAR VAL
//--------------------------------------------

int tst_PLOTSPRVARVAL(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02Xxx%02X%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 10],
		cBuff[event_ptr + 11],
		cBuff[event_ptr + 12]);

// Read parameters

	DataByte = ReadParam(5);
	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_PLOTSPRVARVAL, cPattern) == 0){
		sprintf (Dummy,"%04X PLOT %s,%d\n", event_ptr + SnapshotOffset, sprVARname, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 13;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 66. PLOT SPRVAR VAR
//--------------------------------------------

int tst_PLOTSPRVARVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02Xxxxx%02X%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 11],
		cBuff[event_ptr + 12],
		cBuff[event_ptr + 13]);

// Read parameters

	const char *VARname = ReadVarName(5);
	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_PLOTSPRVARVAR, cPattern) == 0){
		sprintf (Dummy,"%04X PLOT %s,%s\n", event_ptr + SnapshotOffset, sprVARname, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 14;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 66. PLOT SPRVAR SPRVAR
//--------------------------------------------

int tst_PLOTSPRVARSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02Xxx%02X%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 11],
		cBuff[event_ptr + 12],
		cBuff[event_ptr + 13]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);
	sprVARval = ReadParam(6);
	const char *sprVARname2 = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_PLOTSPRVARSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X PLOT %s,%s\n", event_ptr + SnapshotOffset, sprVARname, sprVARname2); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 14;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 67. PRINT ZERO
//--------------------------------------------

int tst_PRINTZERO(){

// Define variables

	char cPattern[64];
	char *cMsg;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_PRINTZERO, cPattern) == 0){
//		sprintf (Dummy,"%04X PRINT \"%s\"\n", event_ptr + SnapshotOffset, MSG[0]); 
		sprintf (Dummy,"%04X MESSAGE 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 67. PRINT VAL
//--------------------------------------------

int tst_PRINTVAL(){
// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_PRINTVAL, cPattern) == 0){
//		sprintf (Dummy,"%04X PRINT \"%s\"\n", event_ptr + SnapshotOffset, MSG[DataByte]); 
		sprintf (Dummy,"%04X MESSAGE %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 68. PRINTMODE ZERO
//--------------------------------------------

int tst_PRINTMODEZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_PRINTMODEZERO, cPattern) == 0){
		sprintf (Dummy,"%04X PRINTMODE 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 68. PRINTMODE VAL
//--------------------------------------------

int tst_PRINTMODEVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);

// Compare pattern with template

	if (strcmp(cmd_PRINTMODEVAL, cPattern) == 0){
		sprintf (Dummy,"%04X PRINTMODE %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 68. PRINTMODE VAR
//--------------------------------------------

int tst_PRINTMODEVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_PRINTMODEVAR, cPattern) == 0){
		sprintf (Dummy,"%04X PRINTMODE %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 69. PUT x,x,x
//--------------------------------------------

int tst_PUT(){

// Define variables

	char cPattern[64];
	char cPattern1[64];
	char cPattern2[64];
	char cPattern3[64];
	char cPattern4[64];
	const char *VARname;
	const char *sprVARname;
	int sprVARval;
	int i;
	int flag;
	
// Check for PUT call

	flag=0;
	for (i = 8; i<15; i++){
		sprintf(cPattern, "%02X%02X%02X",
			cBuff[event_ptr + i],
			cBuff[event_ptr + i+1],
			cBuff[event_ptr + i+2]);
		if (strcmp(cmd_PUT, cPattern) == 0){
			flag = 1;
			break;
		}
	}

	if (flag == 0) return 0;

// Test for parameter 1 zero, val, var, sprvar

	sprintf(cPattern1, "%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1]);
	sprintf(cPattern2, "%02Xxx%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2]);
	sprintf(cPattern3, "%02Xxxxx%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3]);
	sprintf(cPattern4, "%02X%02Xxx%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3]);

	if (strcmp("AF67", cPattern1) == 0){
		sprintf (Dummy,"%04X PUT 0,", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 2;
	}

	if (strcmp("3Exx67", cPattern2) == 0){
		DataByte = ReadParam(1);
		sprintf (Dummy,"%04X PUT %d,", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
	}

	if (strcmp("3Axxxx67", cPattern3) == 0){
		VARname = ReadVarName(1);
		sprintf (Dummy,"%04X PUT %s,", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
	}

	if (strcmp("DD7Exx67", cPattern4) == 0){
		sprVARval = ReadParam(2);
		sprVARname = ReadSprVarName(sprVARval);
		sprintf (Dummy,"%04X PUT %s,", event_ptr + SnapshotOffset,sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
	}

	// Check parameter 2 for zero, val, var, sprvar
	
		sprintf(cPattern1, "%02X%02X%02Xxxxx",
			cBuff[event_ptr + 0],
			cBuff[event_ptr + 1],
			cBuff[event_ptr + 2]);
		sprintf(cPattern2, "%02Xxx%02X%02Xxxxx",
			cBuff[event_ptr + 0],
			cBuff[event_ptr + 2],
			cBuff[event_ptr + 3]);
		sprintf(cPattern3, "%02Xxxxx%02X%02Xxxxx",
			cBuff[event_ptr + 0],
			cBuff[event_ptr + 3],
			cBuff[event_ptr + 4]);
		sprintf(cPattern4, "%02X%02Xxx%02X%02Xxxxx",
			cBuff[event_ptr + 0],
			cBuff[event_ptr + 1],
			cBuff[event_ptr + 3],
			cBuff[event_ptr + 4]);
		if (strcmp("AF6F22xxxx", cPattern1) == 0){
			sprintf (Dummy,"0,"); 
			PrtReport(Dummy,2);
			event_ptr = event_ptr + 5;
		}
		if (strcmp("3Exx6F22xxxx", cPattern2) == 0){
			DataByte = ReadParam(1);
			sprintf (Dummy,"%d,",DataByte); 
			PrtReport(Dummy,2);
			event_ptr = event_ptr + 6;
		}
		if (strcmp("3Axxxx6F22xxxx", cPattern3) == 0){
			VARname = ReadVarName(1);
			sprintf (Dummy,"%s,",VARname); 
			PrtReport(Dummy,2);
			event_ptr = event_ptr + 7;
		}
		if (strcmp("DD7Exx6F22xxxx", cPattern4) == 0){
			sprVARval = ReadParam(2);
			sprVARname = ReadSprVarName(sprVARval);
			sprintf (Dummy,"%s,",sprVARname); 
			PrtReport(Dummy,2);
			event_ptr = event_ptr + 7;
		}

// Check parameter 3 for zero, val, var, sprvar
	
		sprintf(cPattern1, "%02X%02Xxxxx",
			cBuff[event_ptr + 0],
			cBuff[event_ptr + 1]);
		sprintf(cPattern2, "%02Xxx%02Xxxxx",
			cBuff[event_ptr + 0],
			cBuff[event_ptr + 2]);
		sprintf(cPattern3, "%02Xxxxx%02Xxxxx",
			cBuff[event_ptr + 0],
			cBuff[event_ptr + 3]);
		sprintf(cPattern4, "%02X%02Xxx%02Xxxxx",
			cBuff[event_ptr + 0],
			cBuff[event_ptr + 1],
			cBuff[event_ptr + 3]);
		if (strcmp("AFCDxxxx", cPattern1) == 0){
			sprintf (Dummy,"0\n"); 
			PrtReport(Dummy,2);
			event_ptr = event_ptr + 4;
			return 1;
		}
		if (strcmp("3ExxCDxxxx", cPattern2) == 0){
			DataByte = ReadParam(1);
			sprintf (Dummy,"%d\n",DataByte); 
			PrtReport(Dummy,2);
			event_ptr = event_ptr + 5;
			return 1;
		}
		if (strcmp("3AxxxxCDxxxx", cPattern3) == 0){
			VARname = ReadVarName(1);
			sprintf (Dummy,"%s\n",VARname); 
			PrtReport(Dummy,2);
			event_ptr = event_ptr + 6;
			return 1;
		}
		if (strcmp("DD7ExxCDxxxx", cPattern4) == 0){
			sprVARval = ReadParam(2);
			sprVARname = ReadSprVarName(sprVARval);
			sprintf (Dummy,"%s\n",sprVARname); 
			PrtReport(Dummy,2);
			event_ptr = event_ptr + 6;
			return 1;
		}

	return 0;
}

//--------------------------------------------
// 70. PUTBLOCK ZERO
//--------------------------------------------

int tst_PUTBLOCKZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02Xxxxx%02Xxxxx%02Xxxxx%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 9],
		cBuff[event_ptr + 12]);

// Compare pattern with template

	if (strcmp(cmd_PUTBLOCKZERO, cPattern) == 0){
		sprintf (Dummy,"%04X PUTBLOCK 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 22;
		if (AdvMode > 0) event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 70. PUTBLOCK VAL
//--------------------------------------------

int tst_PUTBLOCKVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02Xxxxx%02Xxxxx%02Xxxxx%02Xxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 9],
		cBuff[event_ptr + 12]);

// Read parameters

	DataByte = ReadParam(13);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_PUTBLOCKVAL, cPattern) == 0){
		sprintf (Dummy,"%04X PUTBLOCK %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 23;
		if (AdvMode > 0) event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 70. PUTBLOCK VAR
//--------------------------------------------

int tst_PUTBLOCKVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02Xxxxx%02Xxxxx%02Xxxxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 9],
		cBuff[event_ptr + 12]);

// Read parameters

	const char *VARname = ReadVarName(13);

// Compare pattern with template

	if (strcmp(cmd_PUTBLOCKVAR, cPattern) == 0){
		sprintf (Dummy,"%04X PUTBLOCK %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 24;
		if (AdvMode > 0) event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 70. PUTBLOCK SPRVAR
//--------------------------------------------

int tst_PUTBLOCKSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02Xxxxx%02Xxxxx%02Xxxxx%02X%02Xxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 9],
		cBuff[event_ptr + 12],
		cBuff[event_ptr + 13]);

// Read parameters

	sprVARval = ReadParam(14);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_PUTBLOCKSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X PUTBLOCK %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 24;
		if (AdvMode > 0) event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 71. RANDOMIZE VAL
//--------------------------------------------

int tst_RANDOMIZEVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_RANDOMIZEVAL, cPattern) == 0){
		sprintf (Dummy,"%04X RANDOMIZE %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 71. RANDOMIZE VAR
//--------------------------------------------

int tst_RANDOMIZEVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_RANDOMIZEVAR, cPattern) == 0){
		sprintf (Dummy,"%04X RANDOMIZE %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 72. READ VAR
//--------------------------------------------

int tst_READVAR(){

// Define variables

	char cPattern[64];
	int Address;
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3]);

// Read parameters

	const char *VARname = ReadVarName(4);

// Compare pattern with template

	if (strcmp(cmd_READVAR, cPattern) == 0){
		Address = ((cBuff[event_ptr + 2] << 8) + cBuff[event_ptr + 1]) ;
		PushDATAstack(Address);
		sprintf (Dummy,"%04X READ %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 72. READ SPRVAR
//--------------------------------------------

int tst_READSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	int Address;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	sprVARval = ReadParam(5);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_READSPRVAR, cPattern) == 0){
		Address = ((cBuff[event_ptr + 2] << 8) + cBuff[event_ptr + 1]) ;
		PushDATAstack(Address);
		sprintf (Dummy,"%04X READ %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 73. REDRAW
//--------------------------------------------

int tst_REDRAW(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_REDRAW, cPattern) == 0){
		sprintf (Dummy,"%04X REDRAW\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 74. REMOVE
//--------------------------------------------

int tst_REMOVE(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_REMOVE, cPattern) == 0){
		sprintf (Dummy,"%04X REMOVE\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 75. REMOVEOBJ ZERO
//--------------------------------------------

int tst_REMOBJZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_REMOBJZERO, cPattern) == 0){
		sprintf (Dummy,"%04X REMOVEOBJ 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 75. REMOVEOBJ VAL
//--------------------------------------------

int tst_REMOBJVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_REMOBJVAL, cPattern) == 0){
		sprintf (Dummy,"%04X REMOVEOBJ %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 75. REMOVEOBJ VAR
//--------------------------------------------

int tst_REMOBJVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_REMOBJVAR, cPattern) == 0){
		sprintf (Dummy,"%04X REMOVEOBJ %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 75. REMOVEOBJ SPRVAR
//--------------------------------------------

int tst_REMOBJSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_REMOBJSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X REMOVEOBJ %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 76. REPEAT ZERO
//--------------------------------------------

int tst_REPEATZERO(){

// Define variables

	char cPattern[64];
	int Address;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1]);

// Read parameters

	Address = ReadAddress(event_ptr + 2);

// Compare pattern with template

	if (strcmp(cmd_REPEATZERO, cPattern) == 0){
		if (Address == 0x5c81 || Address == 0x5cb0 || Address == 0x5cb1){ 
			sprintf (Dummy,"%04X REPEAT 0\n", event_ptr + SnapshotOffset); 
			PrtReport(Dummy,1);
			event_ptr = event_ptr + 4;
//			ident++;
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

//--------------------------------------------
// 76. REPEAT VAR
//--------------------------------------------

int tst_REPEATVAR(){

// Define variables

	char cPattern[64];
	int Address;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3]);

// Read parameters

	const char *VARname = ReadVarName(1);
	Address = ReadAddress(event_ptr + 4);

// Compare pattern with template

	if (strcmp(cmd_REPEATVAR, cPattern) == 0){
		if (Address == 0x5c81 || Address == 0x5cb0 || Address == 0x5cb1){ 
			sprintf (Dummy,"%04X REPEAT %s\n", event_ptr + SnapshotOffset, VARname); 
			PrtReport(Dummy,1);
			event_ptr = event_ptr + 6;
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

//--------------------------------------------
// 76. REPEAT VAL
//--------------------------------------------

int tst_REPEATVAL(){

// Define variables

	char cPattern[64];
	int Address;
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour
	Address = ReadAddress(event_ptr + 3);
	
// Compare pattern with template

	if (strcmp(cmd_REPEATVAL, cPattern) == 0){
		if (Address == 0x5c81 || Address == 0x5cb0 || Address == 0x5cb1){ 
			sprintf (Dummy,"%04X REPEAT %d\n", event_ptr + SnapshotOffset, DataByte); 
			PrtReport(Dummy,1);
			event_ptr = event_ptr + 5;
//			ident++;
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

//--------------------------------------------
// 76. REPEAT SPRVAR
//--------------------------------------------

int tst_REPEATSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	int Address;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3]);

// Read parameters

	sprVARval = ReadParam(2);
	Address = ReadAddress(event_ptr + 4);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_REPEATSPRVAR, cPattern) == 0){
		if (Address == 0x5c81 || Address == 0x5cb0 || Address == 0x5cb1){ 
			sprintf (Dummy,"%04X REPEAT %s\n", event_ptr + SnapshotOffset, sprVARname); 
			PrtReport(Dummy,1);
			event_ptr = event_ptr + 6;
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

//--------------------------------------------
// 77. RESTART
//--------------------------------------------

int tst_RESTART(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Compare pattern with template

	if (strcmp(cmd_RESTART, cPattern) == 0){
		sprintf (Dummy,"%04X RESTART\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 78. RESTORE
//--------------------------------------------

int tst_RESTORE1(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_RESTORE1, cPattern) == 0){
		sprintf (Dummy,"%04X RESTORE\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 78. RESTORE
//--------------------------------------------

int tst_RESTORE2(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_RESTORE2, cPattern) == 0){
		sprintf (Dummy,"%04X RESTORE\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 79. SCORE VAR
//--------------------------------------------

int tst_SCOREVAR(){
// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_SCOREVAR, cPattern) == 0){
		sprintf (Dummy,"%04X SCORE %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 79. SCORE VAL
//--------------------------------------------

int tst_SCOREVAL(){
// Define variables

	char cPattern[64];
	int ScoreVAL;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	ScoreVAL = cBuff[event_ptr + 1] + (cBuff[event_ptr + 2] << 8);

// Compare pattern with template

	if (strcmp(cmd_SCOREVAL, cPattern) == 0){
		sprintf (Dummy,"%04X SCORE %d\n", event_ptr + SnapshotOffset, ScoreVAL); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 80. SCREENDOWN
//--------------------------------------------

int tst_SCREENDOWN(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_SCREEND, cPattern) == 0){
		sprintf (Dummy,"%04X SCREENDOWN\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 81. SCREENLEFT
//--------------------------------------------

int tst_SCREENLEFT(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_SCREENL, cPattern) == 0){
		sprintf (Dummy,"%04X SCREENLEFT\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 82. SCREENRIGHT
//--------------------------------------------

int tst_SCREENRIGHT(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_SCREENR, cPattern) == 0){
		sprintf (Dummy,"%04X SCREENRIGHT\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 83. SCREENUP
//--------------------------------------------

int tst_SCREENUP(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_SCREENU, cPattern) == 0){
		sprintf (Dummy,"%04X SCREENUP\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 84. SHOWBONUS
//--------------------------------------------

int tst_SHOWBONUS(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Compare pattern with template

	if (strcmp(cmd_SHOWBONUS, cPattern) == 0){
		sprintf (Dummy,"%04X SHOWBONUS\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 8;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 85. SHOWHIGHSCORE
//--------------------------------------------

int tst_SHOWHIGHSCORE(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Compare pattern with template

	if (strcmp(cmd_SHOWHIGHSCORE, cPattern) == 0){
		sprintf (Dummy,"%04X SHOWHIGH\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 8;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 86. SHOWSCORE
//--------------------------------------------

int tst_SHOWSCORE(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Compare pattern with template

	if (strcmp(cmd_SHOWSCORE, cPattern) == 0){
		sprintf (Dummy,"%04X SHOWSCORE\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 8;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 87. SILENCE
//--------------------------------------------

int tst_SILENCE(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_SILENCE, cPattern) == 0){
		sprintf (Dummy,"%04X SILENCE\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 88. SOUND ZERO
//--------------------------------------------

int tst_SOUNDZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Compare pattern with template

	if (strcmp(cmd_SOUNDZERO, cPattern) == 0){
		sprintf (Dummy,"%04X SOUND 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 88. SOUND VAL
//--------------------------------------------

int tst_SOUNDVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Read parameters

	DataByte = ReadParam(4);

// Compare pattern with template

	if (strcmp(cmd_SOUNDVAL, cPattern) == 0){
		sprintf (Dummy,"%04X SOUND %d\n", event_ptr + SnapshotOffset, DataByte - 0x50); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 88. SOUND VAR
//--------------------------------------------

int tst_SOUNDVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X%02Xxxxx%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 9],
		cBuff[event_ptr + 12],
		cBuff[event_ptr + 13]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_SOUNDVAR, cPattern) == 0){
		sprintf (Dummy,"%04X SOUND %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 16;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 88. SOUND SPRVAR
//--------------------------------------------

int tst_SOUNDSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02X%02Xxxxx%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 9],
		cBuff[event_ptr + 12],
		cBuff[event_ptr + 13]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_SOUNDSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X SOUND %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 16;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 89. SPAWN VAR VAR
//--------------------------------------------

int tst_SPAWNVARVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	const char *VARname = ReadVarName(1);
	const char *VARname2 = ReadVarName(5);

// Compare pattern with template

	if (strcmp(cmd_SPAWNVARVAR, cPattern) == 0){
		sprintf (Dummy,"%04X SPAWN %s %s\n", event_ptr + SnapshotOffset, VARname, VARname2); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 89. SPAWN VAR VAL
//--------------------------------------------

int tst_SPAWNVARVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Read parameters

	const char *VARname = ReadVarName(1);
	DataByte = ReadParam(5);

// Compare pattern with template

	if (strcmp(cmd_SPAWNVARVAL, cPattern) == 0){
		sprintf (Dummy,"%04X SPAWN %s %d\n", event_ptr + SnapshotOffset, VARname, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 89. SPAWN VAL VAR
//--------------------------------------------

int tst_SPAWNVALVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02Xxxxx%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	const char *VARname = ReadVarName(3);
	DataByte = ReadParam(1);

// Compare pattern with template

	if (strcmp(cmd_SPAWNVALVAR, cPattern) == 0){
		sprintf (Dummy,"%04X SPAWN %d %s\n", event_ptr + SnapshotOffset, DataByte, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 89. SPAWN VAR ZERO
//--------------------------------------------

int tst_SPAWNVARZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_SPAWNVARZERO, cPattern) == 0){
		sprintf (Dummy,"%04X SPAWN %s 0\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 89. SPAWN VAL VAL
//--------------------------------------------

int tst_SPAWNVALVAL(){

// Define variables

	char cPattern[64];
	unsigned char cVARname;
	int VARval;

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	DataByte = ReadParam(1);
	VARval = ReadParam(2);

// Compare pattern with template

	if (strcmp(cmd_SPAWNVALVAL, cPattern) == 0){
		sprintf (Dummy,"%04X SPAWN %d %d\n", event_ptr + SnapshotOffset, DataByte, VARval); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 90. SPAWNED
//--------------------------------------------

int tst_SPAWNED(){

// Define variables

	char cPattern[64];
	unsigned char cVARname;
	int VARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_SPAWNED, cPattern) == 0){
		sprintf (Dummy,"%04X SPAWNED\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 91. SPRITEDOWN
//--------------------------------------------

int tst_SPRITEDOWN(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Compare pattern with template

	if (strcmp(cmd_SPRITEDOWN, cPattern) == 0){
		sprintf (Dummy,"%04X SPRITEDOWN\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 92. SPRITEINK ZERO
//--------------------------------------------

int tst_SPRITEINKZERO(){
// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);


// Compare pattern with template

	if (strcmp(cmd_SPRITEINKZERO, cPattern) == 0){
		sprintf (Dummy,"%04X SPRITEINK 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 7;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 92. SPRITEINK VAR
//--------------------------------------------

int tst_SPRITEINKVAR(){
// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	const char *VARname = ReadVarName(1);


// Compare pattern with template

	if (strcmp(cmd_SPRITEINKVAR, cPattern) == 0){
		sprintf (Dummy,"%04X SPRITEINK %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 92. SPRITEINK VAL
//--------------------------------------------

int tst_SPRITEINKVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);
//	printf("Pattern:%s\n", cPattern);

// Read parameters

	DataByte = ReadParam(1);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_SPRITEINKVAL, cPattern) == 0){
		sprintf (Dummy,"%04X SPRITEINK %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 8;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 92. SPRITEINK SPRVAR
//--------------------------------------------

int tst_SPRITEINKSPRVAR(){
// Define variables

	char cPattern[64];
	int sprVARval;
// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_SPRITEINKSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X SPRITEINK %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 93. SPRITELEFT
//--------------------------------------------

int tst_SPRITELEFT(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Compare pattern with template

	if (strcmp(cmd_SPRITELEFT, cPattern) == 0){
		sprintf (Dummy,"%04X SPRITELEFT\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 94. SPRITERIGHT
//--------------------------------------------

int tst_SPRITERIGHT(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Compare pattern with template

	if (strcmp(cmd_SPRITERIGHT, cPattern) == 0){
		sprintf (Dummy,"%04X SPRITERIGHT\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 95. SPRITEUP
//--------------------------------------------

int tst_SPRITEUP(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Compare pattern with template

	if (strcmp(cmd_SPRITEUP, cPattern) == 0){
		sprintf (Dummy,"%04X SPRITEUP\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 96. STAR ZERO
//--------------------------------------------

int tst_STARZERO(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02Xxxxx%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_STARZERO, cPattern) == 0){
		sprintf (Dummy,"%04X STAR 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 96. STAR VAL
//--------------------------------------------

int tst_STARVAL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02Xxxxx%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	DataByte = ReadParam(1);			// Read colour

// Compare pattern with template

	if (strcmp(cmd_STARVAL, cPattern) == 0){
		sprintf (Dummy,"%04X STAR %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 96. STAR VAR 
//--------------------------------------------

int tst_STARVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxxxx%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 9]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_STARVAR, cPattern) == 0){
		sprintf (Dummy,"%04X STAR %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 12;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 96. STAR SPRVAR 
//--------------------------------------------

int tst_STARSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02Xxxxx%02X%02X%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 9]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_STARSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X STAR %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 12;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 97. STOPFALL
//--------------------------------------------

int tst_STOPFALL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_STOPFALL, cPattern) == 0){
		sprintf (Dummy,"%04X STOPFALL\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 98. TABLEFALL
//--------------------------------------------

int tst_TABLEFALL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_TABLEFALL, cPattern) == 0){
		sprintf (Dummy,"%04X TABLEFALL\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 99. TABLEJUMP
//--------------------------------------------

int tst_TABLEJUMP(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_TABLEJUMP, cPattern) == 0){
		sprintf (Dummy,"%04X TABLEJUMP\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 100. TICKER ZERO
//--------------------------------------------

int tst_TICKERZERO(){

// Define variables

	char cPattern[64];
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X" ,
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Compare pattern with template

	if (strcmp(cmd_TICKERZERO, cPattern) == 0){
		sprintf (Dummy,"%04X TICKER 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 100. TICKER VAL VAL 
//--------------------------------------------

int tst_TICKERVALVAL(){

// Define variables

	char cPattern[64];
	int DataByte2;
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02Xxxxx",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3]);

// Read parameters

	DataByte = ReadParam(2);
	DataByte2 = ReadParam(1);
	
// Compare pattern with template

	if (strcmp(cmd_TICKERVALVAL, cPattern) == 0){
		sprintf (Dummy,"%04X TICKER %d,%d\n", event_ptr + SnapshotOffset, DataByte, DataByte2); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 100. TICKER VAL VAR 
//--------------------------------------------

int tst_TICKERVALVAR(){

// Define variables

	char cPattern[64];
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02Xxxxx%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Read parameters

	DataByte = ReadParam(1);
	const char *VARname = ReadVarName(4);
	
// Compare pattern with template

	if (strcmp(cmd_TICKERVALVAR, cPattern) == 0){
		sprintf (Dummy,"%04X TICKER %d,%s\n", event_ptr + SnapshotOffset, DataByte, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 100. TICKER VAR ZERO 
//--------------------------------------------

int tst_TICKERVARZERO(){

// Define variables

	char cPattern[64];
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6]);

// Read parameters

	const char *VARname = ReadVarName(1);
	
// Compare pattern with template

	if (strcmp(cmd_TICKERVARZERO, cPattern) == 0){
		sprintf (Dummy,"%04X TICKER %s,0\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 9;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 100. TICKER VAR VAL 
//--------------------------------------------

int tst_TICKERVARVAL(){

// Define variables

	char cPattern[64];
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxx%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7]);

// Read parameters

	DataByte = ReadParam(5);
	const char *VARname = ReadVarName(1);
	
// Compare pattern with template

	if (strcmp(cmd_TICKERVARVAL, cPattern) == 0){
		sprintf (Dummy,"%04X TICKER %s,%d\n", event_ptr + SnapshotOffset, VARname, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 10;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 100. TICKER VAR VAR 
//--------------------------------------------

int tst_TICKERVARVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02Xxxxx%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Read parameters

	const char *VARname = ReadVarName(1);
	const char *VARname1 = ReadVarName(5);

// Compare pattern with template

	if (strcmp(cmd_TICKERVARVAR, cPattern) == 0){
		sprintf (Dummy,"%04X TICKER %s,%s\n", event_ptr + SnapshotOffset, VARname, VARname1); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 11;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 101. TRAIL
//--------------------------------------------

int tst_TRAIL(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_TRAIL, cPattern) == 0){
		sprintf (Dummy,"%04X TRAIL\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 102. UNDOSPRITEMOVE
//--------------------------------------------

int tst_UNDOSPRITEMOVE(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8],
		cBuff[event_ptr + 9],
		cBuff[event_ptr + 10],
		cBuff[event_ptr + 11]);

// Compare pattern with template

	if (strcmp(cmd_UNDOSPRITEMOVE, cPattern) == 0){
		sprintf (Dummy,"%04X UNDOSPRITEMOVE\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 12;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 103. USER
//--------------------------------------------

int tst_USER(){

// Define variables

	char cPattern[64];
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X" ,
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_USER, cPattern) == 0){
		sprintf (Dummy,"%04X USER\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 103. USER ZERO
//--------------------------------------------

int tst_USERZERO(){

// Define variables

	char cPattern[64];
	
// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X" ,
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3]);

// Compare pattern with template

	if (strcmp(cmd_USERZERO, cPattern) == 0){
		sprintf (Dummy,"%04X USER 0\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 4;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 103. USER VAL
//--------------------------------------------

int tst_USERVAL(){

// Define variables

	char cPattern[64];
	
// Read pattern from buffer

	sprintf(cPattern, "%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4]);

// Read parameters

	DataByte = ReadParam(1);
	
// Compare pattern with template

	if (strcmp(cmd_USERVAL, cPattern) == 0){
		sprintf (Dummy,"%04X USER %d\n", event_ptr + SnapshotOffset, DataByte); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 5;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 103. USER VAR 
//--------------------------------------------

int tst_USERVAR(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02Xxxxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	const char *VARname = ReadVarName(1);

// Compare pattern with template

	if (strcmp(cmd_USERVAR, cPattern) == 0){
		sprintf (Dummy,"%04X USER %s\n", event_ptr + SnapshotOffset, VARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 103. USER SPRVAR 
//--------------------------------------------

int tst_USERSPRVAR(){

// Define variables

	char cPattern[64];
	int sprVARval;

// Read pattern from buffer

	sprintf(cPattern, "%02X%02Xxx%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5]);

// Read parameters

	sprVARval = ReadParam(2);
	const char *sprVARname = ReadSprVarName(sprVARval);

// Compare pattern with template

	if (strcmp(cmd_USERSPRVAR, cPattern) == 0){
		sprintf (Dummy,"%04X USER %s\n", event_ptr + SnapshotOffset, sprVARname); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 6;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 105. WAITKEY
//--------------------------------------------

int tst_WAITKEY(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2]);

// Compare pattern with template

	if (strcmp(cmd_WAITKEY, cPattern) == 0){
		sprintf (Dummy,"%04X WAITKEY\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 3;
		return 1;
	} else {
		return 0;
	}
}

//--------------------------------------------
// 106. WHILE SPRVAR <> VAR -> ZIE 41
//--------------------------------------------

//--------------------------------------------
// 107. ZEROBONUS
//--------------------------------------------

int tst_ZEROBONUS(){

// Define variables

	char cPattern[64];

// Read pattern from buffer

	sprintf(cPattern, "%02X%02X%02X%02X%02X%02X%02X%02X%02X",
		cBuff[event_ptr + 0],
		cBuff[event_ptr + 1],
		cBuff[event_ptr + 2],
		cBuff[event_ptr + 3],
		cBuff[event_ptr + 4],
		cBuff[event_ptr + 5],
		cBuff[event_ptr + 6],
		cBuff[event_ptr + 7],
		cBuff[event_ptr + 8]);

// Compare pattern with template

	if (strcmp(cmd_ZEROBONUS, cPattern) == 0){
		sprintf (Dummy,"%04X ZEROBONUS\n", event_ptr + SnapshotOffset); 
		PrtReport(Dummy,1);
		event_ptr = event_ptr + 13;
		return 1;
	} else {
		return 0;
	}
}

