#include <stdio.h>
#include <windows.h>
#include <string.h>

/* Modul yang ada di menu */

void tampilMenu();
void kredit();
void Exit();
void Play();
void ChooseLevel();
int inputMenu(int input);
int inputChooseYourLevel(int input);
int inputChooseYourEnemy(int input);
int inputExit(int input);

/* Modul Untuk Yang player vs player */
void UIinputnama1();
void UIinputnama2();
void tampilPapanPvP(char nama1[10], char nama2[10], int skor1, int skor2, int player, char papan[6][6]); // papan di mode player vs player dan player vs bot berbeda karena ada perbedaan di papan skor nya //
void inputUser(int inputSO, int inputBaris, int inputKolom, int m, int n, int k, int player,char papan[][6]);
void playPlayervsPlayer();

/* Modul untuk yang player vs komputer */
void EnterYourName();
void Level1();
void Level2();
void Level3();

/* Modul yang ada di player vs player dan player vs komputer */
int OlahInputSO(int x);
int OlahInputBaris(int y);
int OlahInputKolom(int z);
int cekSkor(int i,int j,char papan[6][6]);
int cekKotakPenuh(int cekPenuh, int i, int j);
void max6Huruf(char nama[10]);

	
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
	printf("\t\t\t\t\t|         #######  #####  #####  #   #          |\n");
	printf("\t\t\t\t\t|         #  #  #  #      #   #  #   #          |\n");
	printf("\t\t\t\t\t|         #  #  #  #####  #   #  #   #          |\n");
	printf("\t\t\t\t\t|         #  #  #  #      #   #  #   #          |\n");
	printf("\t\t\t\t\t|         #  #  #  #####  #   #  #####          |\n");
	printf("\t\t\t\t\t|                                               |\n");
	printf("\t\t\t\t\t|                 SOS GotAChange                |\n");
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
	int inputSO, inputKolom, inputBaris;
	int cekPenuh=0;
	int player=1;
	int penanda=1;
	int m,n,k;
	StatusPemain player1;
	StatusPemain player2;
	player1.skor=0;
	player2.skor=0;
	UIinputnama1();
	scanf("%s", &player1.nama);
	max6Huruf( player1.nama);
	UIinputnama2();
	scanf("%s", &player2.nama);
	max6Huruf( player2.nama);
	char papan[6][6];
	int i,j;
	for (i=0;i<6;i++){
		for (j=0;j<6;j++){
			papan[i][j]=' ';
		}
	}
	while (penanda==1) {
    if (player%2==1){
       	player=1;
	}else{
		player=2;
	}
	tampilPapanPvP( player1.nama,  player2.nama,  player1.skor,  player2.skor,  player, papan);
    inputUser( inputSO,  inputBaris,  inputKolom,  m,  n,  k,  player,papan);
    if (cekSkor(i,j,papan)==1){
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
    cekKotakPenuh(cekPenuh,i,j);
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
	printf("\t\t\t\t\t\t     (%s)       (%s)   \n", nama1,nama2);
	printf("\t\t\t\t\t\t        %d             %d    \n", skor1,skor2);
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
    printf("\t\t\t\t\t  Ketikan Angka 1 untuk (S) atau angka 2 untuk (O) :");
}

void inputUser(int inputSO, int inputBaris, int inputKolom, int m, int n, int k, int player,char papan[][6]){
	k=OlahInputSO (inputSO);
    printf("\n\t\t\t\t\t  Masukan Posisi Baris :");
    m=OlahInputBaris (inputBaris);
    printf("\n\t\t\t\t\t  Masukan Posisi Kolom :");
    n=OlahInputKolom (inputKolom);
    if (papan[m][n]==' '){
   		 papan[m][n]=k;	
	}else {
		printf("\nMAAF KOTAK SUDAH DIISI\n");
		system("pause");
		player--;
	}
}

int cekKotakPenuh(int cekPenuh, int i, int j){
	int penanda;
	if (cekPenuh==(i*j)){
		penanda=-1;
	}else {
		penanda=1;
	}
	return penanda;
}
int cekSkor(int i,int j,char papan[6][6]){
	int a,b;
	for (a=0;a<i;a++){
		for (b=0;b<j;b++){
			if (papan[a][b]=='S' && papan[a][b+1]=='O' && papan[a][b+2]=='S'){
				return 1;
			}else if (papan[a][b]=='S' && papan[a+1][b+1]=='O' && papan[a+2][b+2]=='S'){
				return 1;
			}else if (papan[a][b]=='S' && papan[a+1][b]=='O' && papan[a+2][b]=='S'){
				return 1;
			}else if (papan[a][b]=='S' && papan[a-1][b+1]=='O' && papan[a-2][b+2]=='S'){
				return 1;
			}else {
				return 0;
			}
		}
	}
}
int OlahInputSO(int x){
	scanf("%d", &x);
	if(x==1){
		x=83;
	}else if (x==2){
		x=79;
	}
	return x;
}

int OlahInputBaris(int y){
	scanf("%d", &y);
	y=y-1;
	return y;
}

int OlahInputKolom(int z){
	scanf("%d", &z);
	z=z-1;
	return z;
}
