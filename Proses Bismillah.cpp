#include <stdio.h>
#include <windows.h>
#include <string.h>


/* Modul yang ada di menu */

void tampilanSOS();
void tampilMenu();
void kredit();
void Exit();
void Play();
void ChooseLevel();
int inputMenu(int input);
int inputChooseYourLevel(int input);
int inputChooseYourEnemy(int input);
int inputExit(int input);

/* Modul Untuk Mode player vs player */
void UIinputnama1();
void UIinputnama2();
void tampilPapanPvP(char nama1[10], char nama2[10], int skor1, int skor2, int player, char papan[6][6]); // papan di mode player vs player dan player vs bot berbeda karena ada perbedaan di papan skor nya //
int cekPosisiInput(int m, int n, int k,int player,char papan[][6], int CekSudahBenar);
void playPlayervsPlayer();

/* Modul untuk Mode player vs komputer */
void EnterYourName();
void Level1();
void Level2();
void Level3();

/* Modul yang ada di Mode player vs player dan Mode player vs komputer */
void CekWin(int skor1, int skor2, char nama1[10], char nama2[10]);
void max6Huruf(char nama[10]);
void Retry();
void inputDiRetry(int inputRetry);
int OlahInputSO(int x);
int OlahInputBaris(int y);
int OlahInputKolom(int z);
int cekSkor(int m,int n,int k,char papan[][6]);
int cekKotakPenuh(int cekPenuh, int i, int j);
int ketikSO (int inputSO, int k);
int ketikBaris(int inputBaris, int m);
int ketikKolom(int inputKolom,int n);

	
typedef struct{
	char nama[10];
	int skor;
}StatusPemain;

int main(){
	tampilMenu();
	return 0;
}

void tampilMenu(){
	int input;
	system("cls");
	printf("\t\t\t\t\t _______________________________________________\n");
	printf("\t\t\t\t\t|                                               |\n");
	printf("\t\t\t\t\t|         #######     #####    #######          |\n");
	printf("\t\t\t\t\t|         #           #   #    #                |\n");
	printf("\t\t\t\t\t|         #######     #   #    #######          |\n");
	printf("\t\t\t\t\t|               #     #   #          #          |\n");
	printf("\t\t\t\t\t|         #######     #####    #######          |\n");
	printf("\t\t\t\t\t|                                               |\n");
	printf("\t\t\t\t\t|                   GotAChange                  |\n");
	printf("\t\t\t\t\t|      ===================================      |\n");
	printf("\t\t\t\t\t|        PLAY    SCORE    CREDIT    Exit        |\n");
	printf("\t\t\t\t\t|        (1)      (2)      (3)      (4)         |\n");
	printf("\t\t\t\t\t|                                               |\n");
	printf("\t\t\t\t\t|_______________________________________________|");
	printf("\n\n\n\t\t\t\t\t\t inputkan angka (1,2,3, Atau 4) : ");
	inputMenu(input);
}

int inputMenu(int input){
	scanf("%d", &input);
	switch (input){
		case 1: Play();break;
		case 2: printf("\njiwa");break;
		case 3: kredit();break;
		case 4: Exit();break;
		default : printf("\nInput angka harus 1,2,atau 3!\n");system("pause");tampilMenu();break;
	}
	return input;
}

void kredit(){
	system("cls");
	printf("\t\t\t\t\t\t _______________________________\n");
	printf("\t\t\t\t\t\t|                               |\n");
	printf("\t\t\t\t\t\t|  Terimakasih telah memainkan  |\n");
	printf("\t\t\t\t\t\t|  game besutan kami, kelompok  |\n");
	printf("\t\t\t\t\t\t|  GotAChance. Semoga kalian    |\n");
	printf("\t\t\t\t\t\t|  Terhibur :)                  |\n");
	printf("\t\t\t\t\t\t|_______________________________|\n");
	system("pause");
	tampilMenu();
}

void Exit(){
	int input;
	system("cls");
	printf("\t\t\t\t\t\t _____________________\n");
	printf("\t\t\t\t\t\t|                     |\n");
	printf("\t\t\t\t\t\t|   Apa Anda Yakin?   |\n");
	printf("\t\t\t\t\t\t|   ===============   |\n");
	printf("\t\t\t\t\t\t|                     |\n");
	printf("\t\t\t\t\t\t|    (1)YA (2)TIDAK   |\n");
	printf("\t\t\t\t\t\t|_____________________|\n");
	printf("\n\t\t\t\t\t\t Input Exit :");
	inputExit(input);
}

int inputExit(int input){
	scanf("%d", &input);
	if(input==2){
		tampilMenu();
	}
	if(input!=1 && input!=2){
		printf("\nInput harus berupa angka 1 atau 2!\n");
		system("pause");
		Exit();
	}
	return input;
}

void Play(){
	int input;
	system("cls");
	printf("\t\t\t\t\t __________________________________________________\n");
	printf("\t\t\t\t\t|                 Choose your enemy                |\n");
	printf("\t\t\t\t\t|                                                  |\n");
	printf("\t\t\t\t\t|      __________                  __________      |\n");
	printf("\t\t\t\t\t|     |          |                |          |     |\n");
	printf("\t\t\t\t\t|     |          |                |          |     |\n");
	printf("\t\t\t\t\t|     | Computer |                |  1 vs 1  |     |\n");
	printf("\t\t\t\t\t|     |          |                |          |     |\n");
	printf("\t\t\t\t\t|     |__________|                |__________|     |\n");
	printf("\t\t\t\t\t|                                                  |\n");
	printf("\t\t\t\t\t|          1                            2          |\n");
	printf("\t\t\t\t\t|                                                  |\n");
	printf("\t\t\t\t\t|                                                  |\n");
	printf("\t\t\t\t\t|__________________________________________________|\n");
	inputChooseYourEnemy(input);
}

int inputChooseYourEnemy(int input){
	scanf("%d", &input);
	if(input==1){
		EnterYourName();
	}
	if(input==2){
		playPlayervsPlayer();
	}
	return input;
}
void ChooseLevel(){
	int input;
	system("cls");
	printf("\t\t\t\t\t ________________________________________________\n");
	printf("\t\t\t\t\t|                  Choose Level                  |\n");
	printf("\t\t\t\t\t|                                                |\n");
	printf("\t\t\t\t\t|   __________      __________     __________    |\n");
	printf("\t\t\t\t\t|  |          |    |          |   |          |   |\n");
	printf("\t\t\t\t\t|  |          |    |          |   |          |   |\n");
	printf("\t\t\t\t\t|  |  3 x 3   |    |  5 x 5   |   |  6 x 6   |   |\n");
	printf("\t\t\t\t\t|  |          |    |          |   |          |   |\n");
	printf("\t\t\t\t\t|  |__________|    |__________|   |__________|   |\n");
	printf("\t\t\t\t\t|                                                |\n");
	printf("\t\t\t\t\t|       (1)            (2)             (3)       |\n");
	printf("\t\t\t\t\t|                                                |\n");
	printf("\t\t\t\t\t|                                                |\n");
	printf("\t\t\t\t\t|________________________________________________|\n");
	inputChooseYourLevel(input);
}

int inputChooseYourLevel(int input){
	scanf("%d", &input);
	switch(input){
		case 1 :Level1(); break;
		case 2 :Level2(); break;
		case 3 :Level3(); break;
	}
}

void EnterYourName(){
	StatusPemain player;
	int lenght;
	system("cls");
	printf("\t\t\t\t\t ________________________________________________\n");
	printf("\t\t\t\t\t|                 Enter Your Name                |\n");
	printf("\t\t\t\t\t|________________________________________________|\n");
	printf("\t\t\t\t\t                  (Maks 5 Huruf)                \n\t\t\t\t\t\t\t      ");
	scanf("%s", &player.nama);
	lenght=strlen(player.nama);
	if (lenght>5){
		printf("\n\t\t\t\t\t\t      Jumlah Karakter Maks 5!\n");
		system("pause");
		EnterYourName();
	}
	ChooseLevel();
}

void Level1(){
	char papan[6][6];
	int i,j;
	for (i=0;i<6;i++){
		for (j=0;j<6;j++){
			papan[i][j]=' ';
		}
	}
	system ("mode 100,43");
	system("cls");
	printf("\n\n\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t\t\t SOS GotAChance \n");
	printf("\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t\t     Player 1   -  Player 2 \n");
    printf("\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t\t\t\t\t       |     |     |     |\n");
    printf("\t\t\t\t\t\t     1 |  %c  |  %c  |  %c  |\n", papan[0][0], papan[0][1], papan[0][2]);
    printf("\t\t\t\t\t\t       |_____|_____|_____|\n");
    printf("\t\t\t\t\t\t       |     |     |     |\n");
    printf("\t\t\t\t\t\t     2 |  %c  |  %c  |  %c  | (Baris)\n", papan[1][0], papan[1][1], papan[1][2]);
    printf("\t\t\t\t\t\t       |_____|_____|_____|\n");
    printf("\t\t\t\t\t\t       |     |     |     |\n");
    printf("\t\t\t\t\t\t     3 |  %c  |  %c  |  %c  |\n", papan[2][0], papan[2][1], papan[2][2]);
    printf("\t\t\t\t\t\t       |     |     |     |\n");
    printf("\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t\t\t\t\t         1      2     3     \n\n");
    printf("\t\t\t\t\t                    (Kolom)                 \n\n");
    printf("\t\t\t\t\t            Masukan Huruf S atau O :\n");
}

void Level2(){
	char papan[5][5];
	int i,j;
	for (i=0;i<5;i++){
		for (j=0;j<5;j++){
			papan[i][j]=' ';
		}
	}
	system ("mode 100,43");
	system("cls");
	printf("\n\n\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t\t\t SOS GotAChance \n");
	printf("\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t\t     Player 1   -  Player 2 \n");
    printf("\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t\t\t\t        |     |     |     |     |     |\n");
    printf("\t\t\t\t\t      1 |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[0][0], papan[0][1], papan[0][2], papan[0][3], papan[0][4]);
    printf("\t\t\t\t\t        |_____|_____|_____|_____|_____|\n");
    printf("\t\t\t\t\t        |     |     |     |     |     |\n");
    printf("\t\t\t\t\t      2 |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[1][0], papan[1][1], papan[1][2], papan[1][3], papan[1][4]);
    printf("\t\t\t\t\t        |_____|_____|_____|_____|_____|\n");
    printf("\t\t\t\t\t        |     |     |     |     |     |\n");
    printf("\t\t\t\t\t      3 |  %c  |  %c  |  %c  |  %c  |  %c  |  (Baris)\n", papan[2][0], papan[2][1], papan[2][2], papan[2][3], papan[2][4]);
    printf("\t\t\t\t\t        |_____|_____|_____|_____|_____|\n");
    printf("\t\t\t\t\t        |     |     |     |     |     |\n");
    printf("\t\t\t\t\t      4 |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[3][0], papan[3][1], papan[3][2], papan[3][3], papan[3][4]);
    printf("\t\t\t\t\t        |_____|_____|_____|_____|_____|\n");
    printf("\t\t\t\t\t        |     |     |     |     |     |\n");
    printf("\t\t\t\t\t      5 |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[4][0], papan[4][1], papan[4][2], papan[4][3], papan[4][4]);
    printf("\t\t\t\t\t        |     |     |     |     |     |\n");
    printf("\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t\t\t\t           1     2     3     4     5   \n\n");
    printf("\t\t\t\t\t                    (Kolom)           \n\n");
    printf("\t\t\t\t\t            Masukan Huruf S atau O :\n");
}


void Level3(){
	char papan[6][6];
	int i,j;
	for (i=0;i<6;i++){
		for (j=0;j<6;j++){
			papan[i][j]=' ';
		}
	}
	system ("mode 100,43");
	system("cls");
	printf("\n\n\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t\t\t SOS GotAChance \n");
	printf("\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t\t     Player 1   -  Player 2 \n");
    printf("\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t     |     |     |     |     |     |     |\n");
    printf("\t\t\t\t\t   1 |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[0][0], papan[0][1], papan[0][2], papan[0][3], papan[0][4], papan[0][5]);
    printf("\t\t\t\t\t     |_____|_____|_____|_____|_____|_____|\n");
    printf("\t\t\t\t\t     |     |     |     |     |     |     |\n");
    printf("\t\t\t\t\t   2 |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[1][0], papan[1][1], papan[1][2], papan[1][3], papan[1][4], papan[1][5]);
    printf("\t\t\t\t\t     |_____|_____|_____|_____|_____|_____|\n");
    printf("\t\t\t\t\t     |     |     |     |     |     |     |\n");
    printf("\t\t\t\t\t   3 |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[2][0], papan[2][1], papan[2][2], papan[2][3], papan[2][4], papan[2][5]);
    printf("\t\t\t\t\t     |_____|_____|_____|_____|_____|_____|\n");
    printf("\t\t\t\t\t     |     |     |     |     |     |     |\n");
    printf("\t\t\t\t\t   4 |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  | (Baris)\n", papan[3][0], papan[3][1], papan[3][2], papan[3][3], papan[3][4], papan[3][5]);
    printf("\t\t\t\t\t     |_____|_____|_____|_____|_____|_____|\n");
    printf("\t\t\t\t\t     |     |     |     |     |     |     |\n");
    printf("\t\t\t\t\t   5 |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[4][0], papan[4][1], papan[4][2], papan[4][3], papan[4][4], papan[4][5]);
    printf("\t\t\t\t\t     |_____|_____|_____|_____|_____|_____|\n");
    printf("\t\t\t\t\t     |     |     |     |     |     |     |\n");
    printf("\t\t\t\t\t   6 |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[5][0], papan[5][1], papan[5][2], papan[5][3], papan[5][4], papan[5][5]);
    printf("\t\t\t\t\t     |     |     |     |     |     |     |\n");
    printf("\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t\t\t\t        1     2     3     4     5     6   \n\n");
    printf("\t\t\t\t\t                    (Kolom)                 \n\n");
    printf("\t\t\t\t\t            Masukan Huruf S atau O :\n");
}	

// ===============================================================================================================================================================//
//                                                             MODE PLAYER VS PLAYER                                                                              //
// ===============================================================================================================================================================//

void playPlayervsPlayer(){
	/* Kamus Data */
	int inputSO, inputKolom, inputBaris;
	int cekPenuh=0;
	int player=1;
	int penanda=1;
	int CekSudahBenar=1,CekPosisi;
	int m,n,k;
	char papan[6][6];
	int i,j;
	StatusPemain player1;
	StatusPemain player2;
	player1.skor=0;
	player2.skor=0;
	
	/* Algoritma */
	UIinputnama1();
	scanf("%s", &player1.nama);
	max6Huruf( player1.nama);
	UIinputnama2();
	scanf("%s", &player2.nama);
	max6Huruf( player2.nama);
	for (i=0;i<6;i++){
		for (j=0;j<6;j++){
			papan[i][j]=' ';
		}
	}
	do {
    	if (player%2==1){
     	  	player=1;
		}else{
			player=2;
		}
		tampilPapanPvP( player1.nama,  player2.nama,  player1.skor,  player2.skor,  player, papan);
		k=ketikSO (inputSO, k);
		m=ketikBaris(inputBaris, m);
		n=ketikKolom(inputKolom, n);	
		CekPosisi=cekPosisiInput(m, n, k,player, papan, CekSudahBenar);
		if (CekPosisi==1){
			player--;
			cekPenuh--;
		}
    	if (cekSkor(m,n,k,papan)==1 && CekPosisi==0){
    		if (player==1){
    			player1.skor++;
    			player--;
			}else if (player==2){
				player2.skor++;
				player--;
			}
		}
		player++;
    	cekPenuh++;
    	penanda=cekKotakPenuh(cekPenuh,i,j);
	}while (penanda!=0);
	tampilPapanPvP( player1.nama,  player2.nama,  player1.skor,  player2.skor,  player, papan);
	CekWin(player1.skor,player2.skor,player1.nama,player2.nama);
	Retry();
}

void CekWin(int skor1, int skor2, char nama1[10], char nama2[10]){
	if (skor1>skor2){
		printf("\n\t\t\t\t\t\t   SELAMAT %s MENANG! \n", nama1);
		system("pause");
	}else if (skor1==skor2){
		printf("\n\t\t\t\t\t\t   MANTAP SKOR MASIH IMBANG! \n");
		system("pause");
	}else{
		printf("\n\t\t\t\t\t\t   SELAMAT %s MENANG! \n", nama2);
		system("pause");
	}
}

void max6Huruf(char nama[10]){
	int lenght;
	lenght=strlen(nama);
	if (lenght>6){
		printf("\nNama maksimal 6 karakter\n");
		system("pause");
		playPlayervsPlayer();
	}
}

void UIinputnama1(){
	system("cls");
	printf("\t\t\t\t\t ________________________________________________\n");
	printf("\t\t\t\t\t|               Enter Name Player1               |\n");
	printf("\t\t\t\t\t|________________________________________________|\n");
	printf("\t\t\t\t\t                  (Maks 6 huruf)              \n\t\t\t\t\t\t\t      ");
}

void UIinputnama2(){
	system("cls");
	printf("\t\t\t\t\t ________________________________________________\n");
	printf("\t\t\t\t\t|               Enter Name Player2               |\n");
	printf("\t\t\t\t\t|________________________________________________|\n");
	printf("\t\t\t\t\t                  (Maks 6 huruf)              \n\t\t\t\t\t\t\t      ");
}

void tampilPapanPvP(char nama1[10], char nama2[10], int skor1, int skor2, int player, char papan[6][6]){
	system ("mode 100,43");
	system("cls");
	printf("\n\n\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t\t\t SOS GotAChance \n");
	printf("\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t\t     Player 1   -  Player 2 \n");
	printf("\t\t\t\t\t\t     (%s)        (%s)   \n", nama1,nama2);
	printf("\t\t\t\t\t\t        %d            %d    \n", skor1,skor2);
    printf("\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t     |     |     |     |     |     |     |\n");
    printf("\t\t\t\t\t   1 |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[0][0], papan[0][1], papan[0][2], papan[0][3], papan[0][4], papan[0][5]);
    printf("\t\t\t\t\t     |_____|_____|_____|_____|_____|_____|\n");
    printf("\t\t\t\t\t     |     |     |     |     |     |     |\n");
    printf("\t\t\t\t\t   2 |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[1][0], papan[1][1], papan[1][2], papan[1][3], papan[1][4], papan[1][5]);
    printf("\t\t\t\t\t     |_____|_____|_____|_____|_____|_____|\n");
    printf("\t\t\t\t\t     |     |     |     |     |     |     |\n");
    printf("\t\t\t\t\t   3 |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[2][0], papan[2][1], papan[2][2], papan[2][3], papan[2][4], papan[2][5]);
    printf("\t\t\t\t\t     |_____|_____|_____|_____|_____|_____|\n");
    printf("\t\t\t\t\t     |     |     |     |     |     |     |\n");
    printf("\t\t\t\t\t   4 |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  | (Baris)\n", papan[3][0], papan[3][1], papan[3][2], papan[3][3], papan[3][4], papan[3][5]);
    printf("\t\t\t\t\t     |_____|_____|_____|_____|_____|_____|\n");
    printf("\t\t\t\t\t     |     |     |     |     |     |     |\n");
    printf("\t\t\t\t\t   5 |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[4][0], papan[4][1], papan[4][2], papan[4][3], papan[4][4], papan[4][5]);
    printf("\t\t\t\t\t     |_____|_____|_____|_____|_____|_____|\n");
    printf("\t\t\t\t\t     |     |     |     |     |     |     |\n");
    printf("\t\t\t\t\t   6 |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", papan[5][0], papan[5][1], papan[5][2], papan[5][3], papan[5][4], papan[5][5]);
    printf("\t\t\t\t\t     |     |     |     |     |     |     |\n");
    printf("\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t\t\t\t        1     2     3     4     5     6   \n\n");
    printf("\t\t\t\t\t                    (Kolom)                 \n\n");
    printf("sekarang giliran player %d\n", player);
}

void Retry(){
	int inputRetry;
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t\t ___________________________________________\n");
	printf("\t\t\t\t\t|                                           |\n");
	printf("\t\t\t\t\t|       APAKAH MAU MENGULANG PERMAINAN?     |\n");
	printf("\t\t\t\t\t|    ====================================   |\n");
	printf("\t\t\t\t\t|                                           |\n");
	printf("\t\t\t\t\t|               YA(1)   TIDAK(2)            |\n");
	printf("\t\t\t\t\t|___________________________________________|\n\n");
	printf("\t\t\t\t\t          Masukkan Angka (1 atau 2):");
	inputDiRetry(inputRetry);
}

void inputDiRetry(int inputRetry){
	scanf("%d", &inputRetry);
	switch (inputRetry){
		case 1 : playPlayervsPlayer();break;
		case 2 : tampilMenu();break;
		default : printf("\nInput harus angka 1 atau 2\n");system("pause");Retry();break;
	}
}


int cekKotakPenuh(int cekPenuh, int i, int j){
	int penanda;
	if (cekPenuh==(i*j)){
		penanda=0;
	}else {
		penanda=1;
	}
	return penanda;
}

int cekPosisiInput(int m, int n, int k,int player,char papan[][6], int CekSudahBenar){
    if (papan[m][n]==' '){
   		 papan[m][n]=k;	
   		 CekSudahBenar=0;
   		 return CekSudahBenar;
	}else {
		printf("\nMAAF KOTAK SUDAH DIISI\n");
		system("pause");
		CekSudahBenar=1;
		return CekSudahBenar;
	}
}

int ketikSO (int inputSO, int k){
	printf("\t\t\t\t\t  Ketikan Angka 1 untuk (S) atau angka 2 untuk (O) :");
	scanf("%d", &inputSO);
	if (inputSO==1 || inputSO==2){
		k=OlahInputSO (inputSO);
   		return k;
	}else{
		printf("\nERROR (INPUT HARUS ANGKA 1 ATAU 2)\n");
		system("pause");
		ketikSO (inputSO,k);
	}
}

int ketikBaris(int inputBaris, int m){
	printf("\n\t\t\t\t\t  Masukan Posisi Baris (Angka 1-6):");
	scanf("%d", &inputBaris);
	if (inputBaris>=1 && inputBaris<=6){
	    m=OlahInputBaris (inputBaris);
    	return m;
	}else{
		printf("\nERROR (INPUT POSISI BARIS HARUS ANGKA ANTARA 1-6)\n");
		system("pause");
		ketikBaris(inputBaris,m);	
	}
}

int ketikKolom(int inputKolom,int n){
	printf("\n\t\t\t\t\t  Masukan Posisi Kolom (Angka 1-6):");
	scanf("%d", &inputKolom);
	if (inputKolom>=1 && inputKolom<=6){
		n=OlahInputKolom (inputKolom);
    	return n;
	}else{
		printf("\nERROR (INPUT POSISI KOLOM HARUS ANGKA ANTARA 1-6)\n");
		system("pause");
		ketikKolom(inputKolom,n);
	}
}


int cekSkor(int m,int n,int k,char papan[6][6]){
	if (k==83){
			if ((papan[m][n-1])=='O' && (papan[m][n-2])=='S')
		{
			return 1;
		}
	        if ((papan[m][n+1]== 'O') && (papan[m][n+2] == 'S'))
        {
            return 1;
        }
        if((papan[m+1][n] == 'O') && (papan[m+2][n] == 'S'))
        {
            return 1;
        }
        if((papan[m-1][n] == 'O') && (papan[m-2][n] == 'S'))
        {
            return 1;
        }
        if((papan[m+1][n+1] == 'O') && (papan[m+2][n+2] == 'S'))
        {
            return 1;
        }
        if((papan[m-1][n-1] == 'O') && (papan[m-2][n-2] == 'S'))
        {
            return 1;
        }
        if((papan[m+1][n-1] == 'O') && (papan[m+2][n-2] == 'S'))
        {
            return 1;
        }
        if((papan[m-1][n+1] == 'O') && (papan[m-2][n+2] == 'S'))
        {
            return 1;
        }	
	}
    else if (k==79){
    	if((papan[m+1][n] == 'S') && (papan[m-1][n] == 'S'))
        {
            return 1;
        }
        if((papan[m][n+1] == 'S') && (papan[m][n-1] == 'S'))
        {
            return 1;
        }
        if((papan[m+1][n+1] == 'S') && (papan[m-1][n-1] == 'S'))
        {
            return 1;
        }
        if((papan[m+1][n-1] == 'S') && (papan[m-1][n+1] == 'S'))
        {
            return 1;
        }	
	}else {
		return 0;
	}
}


int OlahInputSO(int x){
	if(x==1){
		x=83;
	}else if (x==2){
		x=79;
	}
	return x;
}

int OlahInputBaris(int y){
	y=y-1;
	return y;
}

int OlahInputKolom(int z){
	z=z-1;
	return z;
}
