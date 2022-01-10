#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

#define HIGHSCORE_FILENAME "filehighscore.dat"

// Modul berikut berfungsi pada fitur main menu //
void tampilMenu();
void kredit();
void Exit();
void Play();
int inputExit(int input);
int inputMenu(int input);

// Modul berikut berfungsi pada fitur pilih lawan //
void Play();
int inputChooseYourEnemy(int input);

// Modul berikut berfungsi pada fitur pilih level/pilih papan //
int inputChooseYourLevel(int input);
void ChooseLevel();

// Modul berikut berfungsi untuk menampilkan dan juga menginput nama pemain1 dan pemain2 //
void UIinputnama1();
void UIinputnama2();

// Modul berikut berfungsi sebagai modul utama yang memanggil modul modul yang ada di mode player vs player //
void playPlayervsPlayer();

// Modul berikut berfungsi sebagai modul utama yang memanggil modul modul yang ada di mode player vs komputer //
void playPlayervsKomputer();

// Modul berikut berfungsi untuk menampilkan dan juga menginput nama user //
void EnterYourName();

// Modul berikut berfungsi untuk menampilkan papan permainan //
void Level1(int player, char papan[6][6]);
void Level2(int player, char papan[6][6]);
void Level3(int player, char papan[6][6]);

// Modul berikut berfungsi sebagai algoritma cara gerak komputer //
void komputer_gerak(int player,int ii, int jj, int k, int j, char papan[6][6]);
int komputer_cari_ss(int ii, int jj,int j, char papan[6][6]);
int komputer_cari_os(int ii, int jj,int j, char papan[6][6]);
void komputer_cari_kotak_kosong(int player,int ii, int jj, int k, int j, char papan[6][6]);

// Modul berikut berfungsi untuk mengecek siapa yang menang lalu menampilkannya ke layar //
void CekWin1(int skor1, int skor2, char nama1[10], char nama2[10]);
void CekWin2(int skor1, int skor2, char nama1[10], char nama2[10]);

// Modul berikut berfungsi pada fitur retry //
void Retry();
void inputDiRetry(int inputRetry);

// Modul berikut berfungsi sebagai algoritma cara gerak player //
int cekPosisiInput(int m, int n, int k,char papan[][6], int CekSudahBenar);
int OlahInputSO(int x);
int OlahInputBaris(int y);
int OlahInputKolom(int z);
int ketikSO (int inputSO, int k);
int ketikBaris(int inputBaris, int m, int inputLevel);
int ketikKolom(int inputKolom,int n, int inputLevel);

// Modul berikut berfungsi untuk mengecek dan juga menghitung skor ketika player berhasil membentuk kata SOS //
int cekSkor(int m,int n,int k,char papan[][6],int j);

// Modul berikut berfungsi untk mengecek apakah papan sudah penuh atau belum (sebagai penanda permainan selesai) //
int cekKotakPenuh(int cekPenuh, int i, int j);

// Modul berikut berfungsi pada fitur highscore //
void highscore();
void writeData1();
void writeData2();
int GetData();
void sortHighscore(int N );
void swap (int i, int j);

// Modul berikut berfungsi pada fitur help (how to play) //
void help();

typedef struct{
	char nama[10];
	int skor;
}StatusPemain;

typedef struct{
	char nama[10];
	int skor;
}Highscore;
 
/* Variabel Global */ 
StatusPemain player1;
StatusPemain player2;
Highscore data,list[100],temp;
char papan[6][6];


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
	printf("\t\t\t\t\t|      =====================================    |\n");
	printf("\t\t\t\t\t|       PLAY   SCORE   HELP   CREDIT   Exit     |\n");
	printf("\t\t\t\t\t|       (1)     (2)    (3)     (4)     (5)      |\n");
	printf("\t\t\t\t\t|                                               |\n");
	printf("\t\t\t\t\t|_______________________________________________|");
	printf("\n\n\n\t\t\t\t\t\t inputkan angka (1,2,3,4, atau 5) : ");
	inputMenu(input);
}

int inputMenu(int input){
	scanf("%d", &input);
	switch (input){
		case 1: Play();break;
		case 2: highscore();break;
		case 3: help();break;
		case 4: kredit();break;
		case 5: Exit();break;
		default : printf("\nInput angka harus 1,2,atau 3!\n");system("pause");tampilMenu();break;
	}
	return input;
}

void help(){
	system("cls");
	char isi[255];
    FILE *fptr;

    if ((fptr = fopen("filehelp.txt","r")) == NULL){
        return;
    }

    while(fgets(isi, sizeof(isi), fptr)){
        printf("%s", isi);
    }

    fclose(fptr);
    printf("\n\nKLIK APAPUN UNTUK KEMBALI KE MENU!\n");
    system("pause");
    tampilMenu();
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
		playPlayervsKomputer();
	}
	if(input==2){
		playPlayervsPlayer();
	}
	return input;
}

void highscore(){
	int i,N;
	N = GetData();
	system("cls");
	sortHighscore(N);
	printf("Daftar HighScore!\n\n");
	printf("\t\t\t\t        NAMA   SKOR \n");
	printf("\t\t\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\n");
	for (i=0 ; i<N; i++){
		printf("\t\t\t\t\t%-6s\t",list[i].nama);
		printf(" %d",list[i].skor);
		printf("\n");
	}
	printf("\n\n\n\n\n\nKLIK ENTER UNTUK KEMBALI KE MENU!\n");
	system("pause");
	tampilMenu();	
}

void writeData1(){
	strcpy(data.nama,player1.nama);
	data.skor=player1.skor;
	
	FILE *fp = fopen(HIGHSCORE_FILENAME, "ab");
	fwrite(&data, sizeof(Highscore), 1, fp);
	fclose(fp);
}

void writeData2(){
	if (player1.skor>player2.skor){
		strcpy(data.nama,player1.nama);
		data.skor=player1.skor;
		
		FILE *fp = fopen(HIGHSCORE_FILENAME, "ab");
		fwrite(&data, sizeof(Highscore), 1, fp);
		fclose(fp);	
	}else if (player2.skor>player1.skor){
		strcpy(data.nama,player2.nama);
		data.skor=player2.skor;
		
		FILE *fp = fopen(HIGHSCORE_FILENAME, "ab");
		fwrite(&data, sizeof(Highscore), 1, fp);
		fclose(fp);	
	}else{
		return ;
	}
}

int GetData() {
	int N = 0;
	FILE *fp = fopen(HIGHSCORE_FILENAME, "rb");
	while ( fread(&list[N], sizeof(Highscore), 1, fp ) == 1 ) N++;
	fclose(fp);
	return N;
}

void sortHighscore(int N ) {
	int i, j ;
	for ( i = 0 ; i < N-1 ; i++ ){
		for ( j = i+1 ; j < N ; j++){
			if (list[i].skor<list[j].skor){
				swap(i,j);
			}
		}
	}
}

void swap (int i, int j){
	temp = list[j] ;
	list[j] = list[i];
	list[i] = temp ;
}

// ===============================================================================================================================================================//
//                                                             MODE PLAYER VS KOMPUTER                                                                           //
// ===============================================================================================================================================================//

void playPlayervsKomputer(){
	/* Kamus Data */
	int inputLevel; // variabel untuk inputLevel yang diinginkan //
	int i,j; // variabel untuk menghitung jumlah baris (i) dan kolom (j) //
	int m,n,k; // m adalah input baris yang sudah dikurang 1, n adalah input kolom yang sudah dikurangi 1, dan k adalah input S atau O yang sudah diubah jadi angka //
	char papan[6][6]; // variabel untuk papan //
	int player=1; // variabel untuk player //
	int ii,jj; // variabel untuk input baris (ii) dan kolom (jj) dari komputer //
	int penanda=0; // variabel ini berguna sebagai penanda apakah game sudah selesai atau belum //
	int inputSO, inputKolom, inputBaris;; // ketiga variabel ini sama fungsi nya seperti m,n,k cuman belum di olah saja //
	int cekPenuh=0; // cekPenuh berfungsi sebagai penanda bahwa kotas sudah terisi penuh atau belum //
	int CekSudahBenar=1,CekPosisi; // variabel CekSudah benar berfungsi untuk mengecek input player apakah sudah benar atau belum (1 berarti True), dan variabel cek posisi untuk mengecek jika posisi yang diinput user salah maka player tersebut harus menginput lagi //
	int tempatSkorPlayer2; // variabel untuk menampung skor komputer saat ini (untuk mengecek apakah komputer dapat giliran lagi atau tidak) //
	
	// inisialisasi skor awal //
	player1.skor=0;
	player2.skor=0;
	
  	// inisialisasi nama BOT //
	player2.nama[0]='B';
	player2.nama[1]='O';
	player2.nama[2]='T';
	
	/* Algoritma */
	EnterYourName();
	ChooseLevel();
	inputLevel=inputChooseYourLevel(inputLevel);
	switch (inputLevel){
		case 1 :
			for (i=0;i<3;i++){
				for (j=0;j<3;j++){
					papan[i][j]=' ';
				}
			}Level1(player,papan);break;
		case 2 :
			for (i=0;i<5;i++){
				for (j=0;j<5;j++){
					papan[i][j]=' ';
				}
			}Level2(player,papan);break;
		case 3 :
			for (i=0;i<6;i++){
				for (j=0;j<6;j++){
					papan[i][j]=' ';
				}
			}Level3(player,papan);break;
	}
		do{
		tempatSkorPlayer2=player2.skor;
		if (player%2==1){
     	  	player=1;
		}else{
			player=2;
		}
		switch (inputLevel){
		case 1 : Level1(player,papan);break;
		case 2 : Level2(player,papan);break;
		case 3 : Level3(player,papan);break; 
		}
		if (player==1){
			k=ketikSO (inputSO, k);
			m=ketikBaris(inputBaris, m,inputLevel);
			n=ketikKolom(inputKolom, n,inputLevel);
			CekPosisi=cekPosisiInput(m, n, k, papan, CekSudahBenar);
			if (CekPosisi==1){
				player--;
				cekPenuh--;
			}	
			if (cekSkor(m,n,k,papan,j)>0 && CekPosisi==0){
				player1.skor = player1.skor + cekSkor (m,n,k,papan,j);
				player--;
			}		
		}
		if (player==2){
			komputer_gerak(player,ii,  jj,  k,  j,  papan);
			if (player2.skor>tempatSkorPlayer2){
				player--;	
			}
			printf("\nKLIK ENTER UNTUK MELANJUTKAN !\n");
			system("pause");
		}
		player++;
    	cekPenuh++;
    	penanda=cekKotakPenuh(cekPenuh,i,j);
	}while (penanda != 0);
	writeData1();
	switch (inputLevel){
		case 1 : Level1(player,papan);break;
		case 2 : Level2(player,papan);break;
		case 3 : Level3(player,papan);break; 
	}
	CekWin1(player1.skor,player2.skor,player1.nama,player2.nama);
	Retry();
}

void komputer_gerak(int player,int ii, int jj, int k, int j, char papan[6][6]){
	while (1){
		if (komputer_cari_ss( ii, jj, j,  papan)==1){
			break;
		}else if (komputer_cari_os(ii, jj, j, papan)==1){
			break;
		}
		else{
			komputer_cari_kotak_kosong(player, ii, jj, k, j, papan);break;
		}
	}		
}	


void  komputer_cari_kotak_kosong(int player,int ii, int jj, int k, int j, char papan[6][6]){
	int random;
	k=rand()%2;
	if (k==1){
		k=83;
	}else{
		k=79;
	}
	while (1){
		random=rand()%(j*j);
		ii=(random-1)/(j*j);
		jj=(random-1)%(j*j);
		
		if (papan[ii][jj]==' '){
			papan[ii][jj]=k;
			break;
		}
	}
	if (cekSkor(ii,jj,k,papan,j)>0);
}


int komputer_cari_ss(int ii,int jj,int j, char papan[6][6]){
	int simbol;
	for (ii=0; ii<j; ii++){
        for(jj=0; jj<j; jj++){  
				if((jj!=0) && (jj!=j-1) && (papan[ii][jj+1]=='S') && (papan[ii][jj-1] == 'S') && papan[ii][jj]==' '){
					simbol=79;
					papan[ii][jj]=simbol;
					if (cekSkor(ii,jj,simbol,papan,j)>0){
						player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j);
					}
					return 1;
                }
                if ((papan[ii+1][jj] == 'S') && (papan[ii-1][jj] =='S') && papan[ii][jj]==' '){
					simbol=79;
					papan[ii][jj]=simbol;
					if (cekSkor(ii,jj,simbol,papan,j)>0){
						player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j);
					}
					return 1;
                }
                if((jj!=0) && (jj!=j-1) && (papan[ii+1][jj+1] == 'S') && (papan[ii-1][jj-1] == 'S') && papan[ii][jj]==' '){
					simbol=79;
					papan[ii][jj]=simbol;
					if (cekSkor(ii,jj,simbol,papan,j)>0){
						player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j);
					}
					return 1;
                }
                if((jj!=0) && (jj!=j-1) && (papan[ii+1][jj-1] == 'S') && (papan[ii-1][jj+1] == 'S') && papan[ii][jj]==' '){
					simbol=79;
					papan[ii][jj]=simbol;
					if (cekSkor(ii,jj,simbol,papan,j)>0){
						player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j);
					}
					return 1;
                }
            }
		}
	return 0;
    }


int komputer_cari_os(int ii,int jj,int j, char papan[6][6]){
	int simbol;
	for (ii=0;ii<j;ii++){
		for (jj=0;jj<j;jj++){
			if ((jj!=j-1) && (papan[ii][jj+1]=='O') && (papan[ii][jj+2]=='S') && papan[ii][jj]==' '){
				simbol=83;
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j);
				}
				return 1;
			}
            if((jj!=0) && (papan[ii][jj-1]=='O') && (papan[ii][jj-2] == 'S') && papan[ii][jj]==' '){
            	simbol=83;
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j);
				}
                return 1;
            }
        	if ((papan[ii+1][jj] == 'O') && (papan[ii+2][jj] =='S') && papan[ii][jj]==' '){
        		simbol=83;
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j);
				}
				return 1;
			}
            if ((papan[ii-1][jj] == 'O') && (papan[ii-2][jj] =='S') && papan[ii][jj]==' '){
            	simbol=83;
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j);
				}
                return 1;
            }
			if((jj!=j-1) && (papan[ii+1][jj+1] == 'O') && (papan[ii+2][jj+2] == 'S') && papan[ii][jj]==' '){
				simbol=83;
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j);
				}
                return 1;
            }
            if((jj!=0) && (papan[ii-1][jj-1] == 'O') && (papan[ii-2][jj-2] == 'S') && papan[ii][jj]==' '){
            	simbol=83;
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j);
				}
                return 1;
            }
            if((jj!=0) && (papan[ii+1][jj-1] == 'O') && (papan[ii+2][jj-2] == 'S') && papan[ii][jj]==' '){
            	simbol=83;
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j);
				}
                return 1;
            }
            if((jj!=j-1) && (papan[ii-1][jj+1] == 'O') && (papan[ii-2][jj+2] == 'S') && papan[ii][jj]==' '){
            	simbol=83;
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j);
				}
                return 1;
            }
		}
	}
	return 0;
}


void ChooseLevel(){
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
}

int inputChooseYourLevel(int input){
	scanf("%d", &input);
	return input;
}

void EnterYourName(){
	system("cls");
	printf("\t\t\t\t\t ________________________________________________\n");
	printf("\t\t\t\t\t|                 Enter Your Name                |\n");
	printf("\t\t\t\t\t|________________________________________________|\n");
	printf("\t\t\t\t\t                  (Maks 6 Huruf)                \n\t\t\t\t\t\t\t      ");
	scanf("%s", &player1.nama);
	if (strlen(player1.nama)>6){
		printf("\n\t\t\t\t\t\t      Jumlah Karakter Maks 6!\n");
		system("pause");
		EnterYourName();
	}
}

void Level1(int player, char papan[6][6]){
	system ("mode 100,43");
	system("cls");
	printf("\n\n\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t\t\t SOS GotAChance \n");
	printf("\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t\t     Player 1   -  Player 2 \n");
	printf("\t\t\t\t\t\t     (%s)       (%s)      \n", player1.nama,player2.nama);
	printf("\t\t\t\t\t\t        %d             %d    \n", player1.skor, player2.skor);
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
    printf("SEKARANG GILIRAN PLAYER %d\n", player);
}

void Level2(int player, char papan[6][6]){
	system ("mode 100,43");
	system("cls");
	printf("\n\n\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t\t\t SOS GotAChance \n");
	printf("\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t\t     Player 1   -  Player 2 \n");
	printf("\t\t\t\t\t\t     (%s)       (%s)      \n", player1.nama,player2.nama);
	printf("\t\t\t\t\t\t        %d             %d    \n", player1.skor, player2.skor);
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
    printf("SEKARANG GILIRAN PLAYER %d\n", player);
}


void Level3(int player, char papan[6][6]){
	system ("mode 100,43");
	system("cls");
	printf("\n\n\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t\t\t SOS GotAChance \n");
	printf("\t\t\t\t\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\t\t\t\t\t\t     Player 1   -  Player 2 \n");
	printf("\t\t\t\t\t\t     (%s)       (%s)      \n", player1.nama,player2.nama);
	printf("\t\t\t\t\t\t        %d             %d    \n", player1.skor, player2.skor);
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
    printf("SEKARANG GILIRAN PLAYER %d\n", player);
}	

// ===============================================================================================================================================================//
//                                                             MODE PLAYER VS PLAYER                                                                              //
// ===============================================================================================================================================================//

void playPlayervsPlayer(){
	/* Kamus Data */
	int inputSO, inputKolom, inputBaris; // ketiga variabel ini sama fungsi nya seperti m,n,k cuman belum di kurangi aja //
	int cekPenuh=0;  // cekPenuh berfungsi sebagai penanda bahwa kotas sudah terisi penuh atau belum //
	int player=1; // variabel untuk player //
	int penanda=1; // variabel ini berguna sebagai penanda apakah game sudah selesai atau belum //
	int CekSudahBenar=1,CekPosisi; // variabel CekSudah benar berfungsi untuk mengecek input player apakah sudah benar atau belum (1 berarti True), dan variabel cek posisi untuk mengecek jika posisi yang diinput user salah maka player tersebut harus menginput lagi //
	int m,n,k; // m adalah input baris yang sudah dikurang 1, n adalah input kolom yang sudah dikurangi 1, dan k adalah input S atau O yang sudah diubah jadi angka //
	char papan[6][6]; // variabel untuk papan //
	int i,j; // variabel untuk menghitung jumlah baris (i) dan kolom (j) //
	int inputLevel=3; // variabel untuk menginput papan (otomatis papan level 3 (6x6)) //
	
	// inisialisasi skor awal //
	player1.skor=0;
	player2.skor=0;
	
	/* Algoritma */
	UIinputnama1();
	UIinputnama2();
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
		Level3(player, papan);
		k=ketikSO (inputSO, k);
		m=ketikBaris(inputBaris, m,inputLevel);
		n=ketikKolom(inputKolom, n,inputLevel);	
		CekPosisi=cekPosisiInput(m, n, k, papan, CekSudahBenar);
		if (CekPosisi==1){
			player--;
			cekPenuh--;
		}
    	if (cekSkor(m,n,k,papan,j)>0 && CekPosisi==0){
    		if (player==1){
    			player1.skor = player1.skor + cekSkor(m,n,k,papan,j);
    			player--;
			}else if (player==2){
				player2.skor = player2.skor + cekSkor(m,n,k,papan,j);
				player--;
			}
		}
		player++;
    	cekPenuh++;
    	penanda=cekKotakPenuh(cekPenuh,i,j);
	}while (penanda!=0);
	writeData2();
	Level3(player, papan);
	CekWin2(player1.skor,player2.skor,player1.nama,player2.nama);
	Retry();
}

void CekWin1(int skor1, int skor2, char nama1[10], char nama2[10]){
	if (skor1>skor2){
		printf("\n\t\t\t\t\t\t   SELAMAT ANDA MENANG! \n");
		system("pause");
	}else if (skor1==skor2){
		printf("\n\t\t\t\t\t\t    MANTAP SKOR MASIH IMBANG! \n");
		system("pause");
	}else{
		printf("\n\t\t\t\t\t\t   YAHH ANDA KURANG BERUNTUNG... \n", nama2);
		system("pause");
	}
}

void CekWin2(int skor1, int skor2, char nama1[10], char nama2[10]){
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


void UIinputnama1(){
	system("cls");
	printf("\t\t\t\t\t ________________________________________________\n");
	printf("\t\t\t\t\t|               Enter Name Player1               |\n");
	printf("\t\t\t\t\t|________________________________________________|\n");
	printf("\t\t\t\t\t                  (Maks 6 huruf)              \n\t\t\t\t\t\t\t      ");
	scanf("%s", &player1.nama);
	if (strlen(player1.nama)>6){
		printf("\n\t\t\t\t\t\t      Jumlah Karakter Maks 6!\n");
		system("pause");
		UIinputnama1();
	}
}

void UIinputnama2(){
	system("cls");
	printf("\t\t\t\t\t ________________________________________________\n");
	printf("\t\t\t\t\t|               Enter Name Player2               |\n");
	printf("\t\t\t\t\t|________________________________________________|\n");
	printf("\t\t\t\t\t                  (Maks 6 huruf)              \n\t\t\t\t\t\t\t      ");
	scanf("%s", &player2.nama);
	if (strlen(player2.nama)>6){
		printf("\n\t\t\t\t\t\t      Jumlah Karakter Maks 6!\n");
		system("pause");;
		UIinputnama2();
	}
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
	printf("\t\t\t\t\t           Masukan Angka (1 atau 2):");
	inputDiRetry(inputRetry);
}

void inputDiRetry(int inputRetry){
	scanf("%d", &inputRetry);
	switch (inputRetry){
		case 1 : Play();break;
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

int cekPosisiInput(int m, int n, int k,char papan[][6], int CekSudahBenar){
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

int ketikBaris(int inputBaris, int m, int inputLevel){
	if (inputLevel==1){
		printf("\n\t\t\t\t\t  Masukan Posisi Baris (Angka 1-3):");
		scanf("%d", &inputBaris);
		if (inputBaris>=1 && inputBaris<=3){
	    	m=OlahInputBaris (inputBaris);
    		return m;
		}else{
			printf("\nERROR (INPUT POSISI BARIS HARUS ANGKA ANTARA 1-3)\n");
			system("pause");
			ketikBaris(inputBaris,m,inputLevel);	
		}
	}
	else if (inputLevel==2){
		printf("\n\t\t\t\t\t  Masukan Posisi Baris (Angka 1-5):");
		scanf("%d", &inputBaris);
		if (inputBaris>=1 && inputBaris<=5){
	    	m=OlahInputBaris (inputBaris);
    		return m;
		}else{
			printf("\nERROR (INPUT POSISI BARIS HARUS ANGKA ANTARA 1-5)\n");
			system("pause");
			ketikBaris(inputBaris,m,inputLevel);	
		}
	}
	else if (inputLevel==3){
		printf("\n\t\t\t\t\t  Masukan Posisi Baris (Angka 1-6):");
		scanf("%d", &inputBaris);
		if (inputBaris>=1 && inputBaris<=6){
	    	m=OlahInputBaris (inputBaris);
    		return m;
		}else{
			printf("\nERROR (INPUT POSISI BARIS HARUS ANGKA ANTARA 1-6)\n");
			system("pause");
			ketikBaris(inputBaris,m,inputLevel);	
		}
	}
}

int ketikKolom(int inputKolom,int n, int inputLevel){
	if (inputLevel==1){
		printf("\n\t\t\t\t\t  Masukan Posisi Kolom (Angka 1-3):");
		scanf("%d", &inputKolom);
		if (inputKolom>=1 && inputKolom<=3){
			n=OlahInputKolom (inputKolom);
    		return n;
		}else{
			printf("\nERROR (INPUT POSISI KOLOM HARUS ANGKA ANTARA 1-3)\n");
			system("pause");
			ketikKolom(inputKolom,n,inputLevel);
		}	
	}
	else if (inputLevel==2){
		printf("\n\t\t\t\t\t  Masukan Posisi Kolom (Angka 1-5):");
		scanf("%d", &inputKolom);
		if (inputKolom>=1 && inputKolom<=5){
			n=OlahInputKolom (inputKolom);
    		return n;
		}else{
			printf("\nERROR (INPUT POSISI KOLOM HARUS ANGKA ANTARA 1-5)\n");
			system("pause");
			ketikKolom(inputKolom,n,inputLevel);
		}	
	}
	else if (inputLevel==3){
		printf("\n\t\t\t\t\t  Masukan Posisi Kolom (Angka 1-6):");
		scanf("%d", &inputKolom);
		if (inputKolom>=1 && inputKolom<=6){
			n=OlahInputKolom (inputKolom);
    		return n;
		}else{
			printf("\nERROR (INPUT POSISI KOLOM HARUS ANGKA ANTARA 1-6)\n");
			system("pause");
			ketikKolom(inputKolom,n,inputLevel);
		}	
	}
}


int cekSkor(int m,int n,int k,char papan[6][6],int j){
	int skor=0;
	if (k==83){
		if ((n!=0) && (papan[m][n-1])=='O' && (papan[m][n-2])=='S')
		{
			skor++;
		}
        if ((n!=j-1) && (papan[m][n+1]== 'O') && (papan[m][n+2] == 'S'))
        {
            skor++;
        }
        if((papan[m+1][n] == 'O') && (papan[m+2][n] == 'S'))
        {
            skor++;
        }
        if((papan[m-1][n] == 'O') && (papan[m-2][n] == 'S'))
        {
            skor++;
        }
        if((n!=j-1) && (papan[m+1][n+1] == 'O') && (papan[m+2][n+2] == 'S'))
        {
            skor++;
        }
        if((n!=0) && (papan[m-1][n-1] == 'O') && (papan[m-2][n-2] == 'S'))
        {
            skor++;
        }
        if((n!=0) && (papan[m+1][n-1] == 'O') && (papan[m+2][n-2] == 'S'))
        {
            skor++;
        }
        if((n!=j-1) &&(papan[m-1][n+1] == 'O') && (papan[m-2][n+2] == 'S'))
        {
            skor++;
        }	
	}
    else if (k==79){
    	if((papan[m+1][n] == 'S') && (papan[m-1][n] == 'S'))
        {
            skor++;
        }
        if((n!=j-1) && (n!=0) && (papan[m][n+1] == 'S') && (papan[m][n-1] == 'S'))
        {
            skor++;
        }
        if((n!=j-1) && (n!=0) && (papan[m+1][n+1] == 'S') && (papan[m-1][n-1] == 'S'))
        {
            skor++;
        }
        if((n!=j-1) && (n!=0) && (papan[m+1][n-1] == 'S') && (papan[m-1][n+1] == 'S'))
        {
            skor++;
        }	
	}
	return skor;
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
