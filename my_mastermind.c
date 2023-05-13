#include "gameminds.h"

int pgamelan(char* xc3, char xc9) {
    int ljk = 0;
    while (xc3[ljk]) {
        if (xc3[ljk] == xc9) {
            return 1;
        }
        ljk++;
    }
    return 0;
}
int jolshn(char* fvc) {
    int oik;
    for (oik = 0; fvc[oik] != '\0'; oik++);
    return oik;
}

int termglan(char* tsz2) {
    int ljh = 0;
    while (tsz2[ljh]) {
        if (!(tsz2[ljh] > 47 && tsz2[ljh] < 57 && jolshn(tsz2) == 4)) {
            return 1;
        }
        ljh++;
    }
    return 0;
}

int qsqaglan(char* fty) {
    int jpt = 0;
    while (jpt < jolshn(fty)) {
        int knv = jpt + 1;
        while (knv < jolshn(fty)) {
            if (fty[jpt] == fty[knv]) {
                return 0;
            }
            knv++;
        }
        jpt++;
    }
    return 1;
}

char* rndmglan(){
    int aplf = 4;
    char* uiux = malloc(4);
    srand(time(NULL));
    for (int kmn = 0; kmn < aplf; ){
        char dsq = rand() % 9 + '0';
        if(pgamelan(uiux, dsq) == 0){
            uiux[kmn++] = dsq;
        }        
    }
    return uiux;
}

void shqartgame(){
    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");
}

void ststsx(int gf3){
    printf("---\nRound %d\n", gf3);
    write( 1, ">", 1);
}

char* qatexcv(){
    printf("Wrong input!\n");
    write( 1, ">", 1);
    fflush(stdout);
    return 0;
}

int gwels(char* yaym2,char* yaym3){
int edil = 0;
int jko = 0;
while(jko < jolshn(yaym2)){
if(yaym2[jko] == yaym3[jko]){
edil++;
}
jko++;
}
return edil;
}

int gplacx(char* dcc ,char* fgg){
int edilovs = 0;
int edd = 0;
while (edd < jolshn(dcc)) {
int gty = 0;
while (gty < jolshn(fgg)) {
if (dcc[edd] == fgg[gty] && edd != gty) {
edilovs++;
}
gty++;
}
edd++;
}
return edilovs;
}

char* fn_rdx(){ 
    char* stf = malloc(4);
    char fvz;
    int koiz;
    for(koiz = 0; read(0, &fvz, 1); koiz++){ 
        if(fvz == '\n'){
            if((termglan(stf)==1 || qsqaglan(stf)==0)){
                qatexcv();
                return fn_rdx();
            }  
            if((termglan(stf)==0) && (qsqaglan(stf)==1)){
                return stf;
            }
        }   
        stf[koiz] = fvz;
    }
    return "abc";
}

void rnglanz(char* rd4, int rf5){
shqartgame();
char* iou;
for(int lpo = 0; lpo < rf5; lpo++){
ststsx(lpo);
iou = fn_rdx();
if(strcmp(iou, "abc") == 0) return;
if(gwels(rd4, iou) == 4){
printf("Congratz! You did it!\n");
break;
}
else {
printf("Well placed pieces: %d\nMisplaced pieces: %d\n", gwels(rd4, iou), gplacx(rd4, iou));
}
}
}

void brgnz(int nty, char** fgd){
char* rwq = NULL;
int attemp = 10;
int tnz = 1;
while(tnz < nty){
if(strcmp(fgd[tnz] , "-c")==0){
rwq = fgd[tnz+1];
}
if(strcmp(fgd[tnz] , "-t")==0){
attemp = atoi(fgd[tnz+1]);
}
tnz++;
}
if(rwq == NULL){
rwq = rndmglan();
}
rnglanz(rwq,attemp);
}

int main(int jnx, char** pkn) {
    brgnz(jnx , pkn);
    return 0;
}