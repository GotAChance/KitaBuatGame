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
void komputer_gerak(int ii, int jj, int k, int j, char papan[6][6]);
int komputer_cari_ss(int ii, int jj,int j, char papan[6][6]);
int komputer_cari_os(int ii, int jj,int j, char papan[6][6]);
void komputer_cari_kotak_kosong(int ii, int jj, int k, int j, char papan[6][6]);

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

// Modul berikut berfungsi untuk menampilkan fitur gameover //
void gameover();

// Modul untuk menampilkan warna //
void setwarna(unsigned short color){
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}

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
int m,n;

int main(){
	tampilMenu();
	return 0;
}

// UI tampil Menu //
void tampilMenu(){
	int input;
	system("cls");
	setwarna(15); // setting warna  menjadi warna default (putih) // 
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

// input di fitur Menu //
int inputMenu(int input){
	scanf("%d", &input);
	switch (input){
		/* Pemilihan Menu */
		case 1: Play();break;
		case 2: highscore();break;
		case 3: help();break;
		case 4: kredit();break;
		case 5: Exit();break;
		default : printf("\nInput angka harus 1,2,3,4 atau 5!\n");system("pause");tampilMenu();break; // jika input bukan merupakan angka 1-5 //
	}
	return input;
}

// Menampilkan fitur help (how to play) //
void help(){
	system("cls");
	char isi[255];
    FILE *fptr;
    
    if ((fptr = fopen("filehelp.txt","r")) == NULL){
       tampilMenu(); // jika isi file kosong maka kembali ke menu //
    }
    
	 // buka isi filehelp //
    while(fgets(isi, sizeof(isi), fptr)){
        printf("%s", isi);
    }

    fclose(fptr);
    printf("\n\nKLIK APAPUN UNTUK KEMBALI KE MENU!\n");
    system("pause");
    tampilMenu();
}

// menampilkan fitur kredit //
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

// menampilkan fitur exit //
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

// input di fitur exit //
int inputExit(int input){
	scanf("%d", &input);
	if(input==2){
		tampilMenu();
	}
	if(input!=1 && input!=2){ // jika input bukan berupa angka 1 atau 2 //
		printf("\nInput harus berupa angka 1 atau 2!\n");
		system("pause");
		Exit();
	}
	return input;
}

// tampil UI fitur pilih mode lawan //
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

// input di fitur pilih mode lawan //
int inputChooseYourEnemy(int input){
	scanf("%d", &input);
	if(input==1){
		playPlayervsKomputer();
	}
	if(input==2){
		playPlayervsPlayer();
	}else{ // jika input bukan merupakan angka 1 atau 2 //
		printf("\ninput harus berupa angka 1 atau 2!\n");
		system("pause");
		Play();
	}
	return input;
}

// untuk menampilkan UI fitur highscore //
void highscore(){
	int i,N;
	N = GetData(); // N merupakah variabel untuk menampung banyaknya data pada file highscore //
	system("cls");
	sortHighscore(N); 
	printf("Daftar HighScore!\n\n");
	printf("\t\t\t\t        NAMA   SKOR \n");
	printf("\t\t\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("\n");
	// menampilkan data highscore yang sudah di sorting //
	for (i=0 ; i<N; i++){
		printf("\t\t\t\t\t%-6s\t",list[i].nama);
		printf(" %d",list[i].skor);
		printf("\n");
	}
	printf("\n\n\n\n\n\nKLIK ENTER UNTUK KEMBALI KE MENU!\n");
	system("pause");
	tampilMenu();	
}

// memasukan data pemain (nama,dan skor) yang menang di mode player vs komputer //
void writeData1(){
	if (player1.skor>player2.skor){
		strcpy(data.nama,player1.nama);
		data.skor=player1.skor;
	
		FILE *fp = fopen(HIGHSCORE_FILENAME, "ab");
		fwrite(&data, sizeof(Highscore), 1, fp);
		fclose(fp);
	}
}

// memasukan data pemain (nama,dan skor) yang menang di mode player vs player //
void writeData2(){
	if (player1.skor>player2.skor){ // jika skor player 1 lebih tinggi dari player 2 //
		strcpy(data.nama,player1.nama);
		data.skor=player1.skor;
		
		FILE *fp = fopen(HIGHSCORE_FILENAME, "ab");
		fwrite(&data, sizeof(Highscore), 1, fp);
		fclose(fp);	
	}else if (player2.skor>player1.skor){ // jika skor player 2 lebih tinggi dari player 1 //
		strcpy(data.nama,player2.nama);
		data.skor=player2.skor;
		
		FILE *fp = fopen(HIGHSCORE_FILENAME, "ab");
		fwrite(&data, sizeof(Highscore), 1, fp);
		fclose(fp);	
	}else{ // jika seri return //
		return ;
	}
}

// membaca data dan menghitung isi data di file highscore //
int GetData() {
	int N = 0;
	FILE *fp = fopen(HIGHSCORE_FILENAME, "rb");
	while ( fread(&list[N], sizeof(Highscore), 1, fp ) == 1 ) N++;
	fclose(fp);
	return N;
}

// mengurutkan data berdasarkan skor tertinggi ke terendah //
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

// menukar posisi list //
void swap (int i, int j){
	temp = list[j] ;
	list[j] = list[i];
	list[i] = temp ;
}

// ===============================================================================================================================================================//
//                                                             MODE PLAYER VS KOMPUTER                                                                           //
// ===============================================================================================================================================================//

// Modul untuk menampung semua modul yang berjalan di mode player vs komputer //
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
	EnterYourName(); // input nama player //
	ChooseLevel(); // tampil UI fitur pilih level // 
	inputLevel=inputChooseYourLevel(inputLevel); // input level permainan (3x3), (5x5), dan (6x6) // 
	// inisialisasi papan //
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
		// mulai perulangan permainan sampai papan penuh //
		do{
		tempatSkorPlayer2=player2.skor; // tempatSkorPlayer2 adalah variabel untuk menampung skor player 2 //
		// player di mod kan dengan 2 agar player 1 dan player 2 dapat saling bertukar giliran //
		if (player%2==1){
     	  	player=1;
		}else{
			player=2;
		}
		// tampilkan papan sesuai input level yang dipilih //
		switch (inputLevel){
		case 1 : Level1(player,papan);break;
		case 2 : Level2(player,papan);break;
		case 3 : Level3(player,papan);break; 
		}
		if (player==1){ // jika player=1 (manusia/user) //
		// k,m,n merupakah variabel variabel yang digunakan untuk input user //
			k=ketikSO (inputSO, k); // input angka 1 untuk S, angka 2 untuk O // 
			m=ketikBaris(inputBaris, m,inputLevel); // input posisi baris //
			n=ketikKolom(inputKolom, n,inputLevel); // input posisi kolom //
			
			// cek posisi berguna untuk mengecek apakah player sudah benar menginputkan di kotak yang kosong atau belum//
			CekPosisi=cekPosisiInput(m, n, k, papan, CekSudahBenar);
			if (CekPosisi==1){
				player--; // jika player malah menginput di kotak yang ada huruf S atau O maka giliran player tersebut diulang lagi dengan fungsi player-- //
				cekPenuh--; // cekPenuh pun akan berkurang jika user salah input//
			}	
			// cek skor apakah player berhasil medapatkan kata SOS atau tidak, lalu jika iya maka pada kondisi player=1 maka skor player 1 bertambah //
			if (cekSkor(m,n,k,papan,j)>0 && CekPosisi==0){
				player1.skor = player1.skor + cekSkor (m,n,k,papan,j);
				player--; // player-- maka player1 akan mendapat giliran lagi jika berhasil menyusun kata SOS //
			}		
		}
		if (player==2){ // jika player=2 (komputer) //
			komputer_gerak(ii,  jj,  k,  j,  papan); // kecerdasan buatan / algoritma bot berjalan //
			if (player2.skor>tempatSkorPlayer2){ // kondisi ini digunakan jika komputer berhasil mendapatkan skor, dengan cara kerjanya yaitu membandingkan skor komputer dengan skor komputer sebelum bertambah //
				player--; // player-- , maka palyer 2 akan mendapat giliran lagi jika berhasil menyusun kata SOS //
			}
			printf("\nKLIK ENTER UNTUK MELANJUTKAN !\n"); // jeda dulu untuk melanjutkan
			system("pause");
		}
		player++;
    	cekPenuh++;
    	penanda=cekKotakPenuh(cekPenuh,i,j); // penanda berfungsi untuk mengecek apakah papan sudah poenuh atau belum, jika sudah maka keluar while //
	}while (penanda != 0);
	writeData1(); // menyimpan data user jika menang untuk keperluan highscore //
	gameover(); // tampil UI gameover // 
	CekWin1(player1.skor,player2.skor,player1.nama,player2.nama); //menampilkan siapakah pemenangnya //
	Retry(); // menampilkan UI fitur retry //
}

// modul algoritma komputer //
void komputer_gerak(int ii, int jj, int k, int j, char papan[6][6]){
	while (1){
		// komputer mencari kata ss di papan //
		if (komputer_cari_ss( ii, jj, j,  papan)==1){
			break;
		// komputer mencari kata os di papan //
		}else if (komputer_cari_os(ii, jj, j, papan)==1){
			break;
		}
		// jika tidak ada maka random //
		else{
			komputer_cari_kotak_kosong(ii, jj, k, j, papan);break;
		}
	}		
}	


void  komputer_cari_kotak_kosong(int ii, int jj, int k, int j, char papan[6][6]){
	int random; // random menampung variabel random //
	            // j merupakah variabel untuk menampung besarnya kolom papan //
	k=rand()%2; // untuk merandom angka, modulus 2 berarti membatasi random sampai angka 2 saja, sehingga huruf yang terbentuk nanti akan muncul antara huruf S atau O//
	if (k==1){
		k=83; // k variabel untuk menampung simbol S atau O //
	}else{
		k=79;
	}
	while (1){
		random=rand()%((j*j)+1); // (j*j)+1, ditambah 1 karena untuk menghindari angka random=0 //
		ii=(random-1)/j; // ii merupakah variabel untuk menampung baris //
		jj=(random-1)%j; // jj merupakan variabel untuk menampung kolom //
		
		if (papan[ii][jj]==' '){
			papan[ii][jj]=k;
			break;
		}
	}
	if (cekSkor(ii,jj,k,papan,j)>0){
		player2.skor = player2.skor + cekSkor (ii,jj,k,papan,j); // menambah skor player2 (bot) jika berhasil menyusun kata SOS //
	}
}


int komputer_cari_ss(int ii,int jj,int j, char papan[6][6]){
	/* ii merupakah variabel untuk menampung baris
	   jj merupakan variabel untuk menampung kolom
	   j merupakah variabel untuk menampung besarnya kolom papan 
	   simbol  variabel untuk menampung simbol S atau O */
	int simbol;
	for (ii=0; ii<j; ii++){
        for(jj=0; jj<j; jj++){  
        // fungsi (jj!=0) untuk mencegah terjadinya indeks kolom minus //
        // fungsi (jj!=j-1) untuk mencegah terjadinya indeks kolom yang melebihi j //
				if((jj!=0) && (jj!=j-1) && (papan[ii][jj+1]=='S') && (papan[ii][jj-1] == 'S') && papan[ii][jj]==' '){
					simbol=79; // simbol 79, isi simbol dengan huruf O //
					papan[ii][jj]=simbol;
					if (cekSkor(ii,jj,simbol,papan,j)>0){ // cek terbentuknya kata SOS //
						player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j); // meanmbah skor player 2 //
					}
					return 1;
                }
                if ((papan[ii+1][jj] == 'S') && (papan[ii-1][jj] =='S') && papan[ii][jj]==' '){
					simbol=79;
					papan[ii][jj]=simbol;
					if (cekSkor(ii,jj,simbol,papan,j)>0){ // cek terbentuknya kata SOS //
						player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j); // meanmbah skor player 2 //
					}
					return 1;
                }
                if((jj!=0) && (jj!=j-1) && (papan[ii+1][jj+1] == 'S') && (papan[ii-1][jj-1] == 'S') && papan[ii][jj]==' '){
					simbol=79;
					papan[ii][jj]=simbol;
					if (cekSkor(ii,jj,simbol,papan,j)>0){ // cek terbentuknya kata SOS //
						player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j); // meanmbah skor player 2 //
					}
					return 1;
                }
                if((jj!=0) && (jj!=j-1) && (papan[ii+1][jj-1] == 'S') && (papan[ii-1][jj+1] == 'S') && papan[ii][jj]==' '){
					simbol=79;
					papan[ii][jj]=simbol;
					if (cekSkor(ii,jj,simbol,papan,j)>0){ // cek terbentuknya kata SOS //
						player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j); // meanmbah skor player 2 //
					}
					return 1;
                }
            }
		}
	return 0;
    }


int komputer_cari_os(int ii,int jj,int j, char papan[6][6]){
	/* ii merupakah variabel untuk menampung baris
	   jj merupakan variabel untuk menampung kolom
	   j merupakah variabel untuk menampung besarnya kolom papan 
	   simbol  variabel untuk menampung simbol S atau O */
	int simbol;
	for (ii=0;ii<j;ii++){
		for (jj=0;jj<j;jj++){
		// fungsi (jj!=0) untuk mencegah terjadinya indeks kolom minus //
        // fungsi (jj!=j-1) untuk mencegah terjadinya indeks kolom yang melebihi j //
			if ((jj!=j-1) && (papan[ii][jj+1]=='O') && (papan[ii][jj+2]=='S') && papan[ii][jj]==' '){
				simbol=83; // simbol 83, isi simbol dengan huruf S // 
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){ // cek terbentuknya kata SOS //
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j); // meanmbah skor player 2 //
				}
				return 1;
			}
            if((jj!=0) && (papan[ii][jj-1]=='O') && (papan[ii][jj-2] == 'S') && papan[ii][jj]==' '){
            	simbol=83;
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){ // cek terbentuknya kata SOS //
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j); // meanmbah skor player 2 //
				}
                return 1;
            }
        	if ((papan[ii+1][jj] == 'O') && (papan[ii+2][jj] =='S') && papan[ii][jj]==' '){
        		simbol=83;
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){ // cek terbentuknya kata SOS //
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j); // meanmbah skor player 2 //
				}
				return 1;
			}
            if ((papan[ii-1][jj] == 'O') && (papan[ii-2][jj] =='S') && papan[ii][jj]==' '){
            	simbol=83;
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){ // cek terbentuknya kata SOS //
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j); // meanmbah skor player 2 //
				}
                return 1;
            }
			if((jj!=j-1) && (papan[ii+1][jj+1] == 'O') && (papan[ii+2][jj+2] == 'S') && papan[ii][jj]==' '){
				simbol=83;
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){ // cek terbentuknya kata SOS //
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j); // meanmbah skor player 2 //
				}
                return 1;
            }
            if((jj!=0) && (papan[ii-1][jj-1] == 'O') && (papan[ii-2][jj-2] == 'S') && papan[ii][jj]==' '){
            	simbol=83;
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){ // cek terbentuknya kata SOS //
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j); // meanmbah skor player 2 //
				}
                return 1;
            }
            if((jj!=0) && (papan[ii+1][jj-1] == 'O') && (papan[ii+2][jj-2] == 'S') && papan[ii][jj]==' '){
            	simbol=83;
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){ // cek terbentuknya kata SOS //
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j); // meanmbah skor player 2 //
				}
                return 1;
            }
            if((jj!=j-1) && (papan[ii-1][jj+1] == 'O') && (papan[ii-2][jj+2] == 'S') && papan[ii][jj]==' '){
            	simbol=83;
				papan[ii][jj]=simbol;
				if (cekSkor(ii,jj,simbol,papan,j)>0){ // cek terbentuknya kata SOS //
					player2.skor = player2.skor + cekSkor (ii,jj,simbol,papan,j); // meanmbah skor player 2 //
				}
                return 1;
            }
		}
	}
	return 0;
}

// UI fitur pilih level //
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

// input di fitur level //
int inputChooseYourLevel(int input){
	scanf("%d", &input);
	return input;
}

// menampilkan UI dan menginputkan nama di mode player vs komputer //
void EnterYourName(){
	system("cls");
	printf("\t\t\t\t\t ________________________________________________\n");
	printf("\t\t\t\t\t|                 Enter Your Name                |\n");
	printf("\t\t\t\t\t|________________________________________________|\n");
	printf("\t\t\t\t\t                  (Maks 6 Huruf)                \n\t\t\t\t\t\t\t      ");
	scanf("%s", &player1.nama);
	if (strlen(player1.nama)>6){ // jika ternyata jumlah karakter input namanya melebihi 6 karakter //
		printf("\n\t\t\t\t\t\t      Jumlah Karakter Maks 6!\n");
		system("pause");
		EnterYourName();
	}
}

// tampil papan 3x3 //
void Level1(int player, char papan[6][6]){
	system ("mode 100,43");
	system("cls");
	if (player==1){ // jika player=1, maka setting warna menjadi warna aqua //
		setwarna(11);
	}else{ // jika player bukan sama dengan 1, maka setting warna menjadi warna hijau //
		setwarna(10);
	}
	printf("input 9 untuk kembali ke menu!\n");	
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

// tampil papan 5x5 //
void Level2(int player, char papan[6][6]){
	system ("mode 100,43");
	system("cls");
	if (player==1){ // jika player=1, maka setting warna menjadi warna aqua //
		setwarna(11);
	}else{ // jika player bukan sama dengan 1, maka setting warna menjadi warna hijau //
		setwarna(10);
	}
	printf("input 9 untuk kembali ke menu!\n");
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

// tampil papan 6x6 // 
void Level3(int player, char papan[6][6]){
	system ("mode 100,43");
	system("cls");
	if (player==1){ // jika player sama dengan 1, maka setting warna menjadi warna aqua //
		setwarna(11);
	}else{ // jika player bukan sama dengan 1, maka setting warna menjadi warna hijau //
		setwarna(10);
	}
	printf("input 9 untuk kembali ke menu!\n");
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

// Modul untuk menampung semua modul yang berjalan di mode player vs player //
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
	// Inputkan nama player 1 dan player 2 //
	UIinputnama1();
	UIinputnama2();
	// inisialisasi isi papan //
	for (i=0;i<6;i++){
		for (j=0;j<6;j++){
			papan[i][j]=' ';
		}
	}
	// mulai perulangan permainan sampai papan penuh //
	do {
		// player di mod kan dengan 2 agar player 1 dan player 2 dapat saling bertukar giliran //
    	if (player%2==1){
     	  	player=1;
		}else{
			player=2;
		}
		Level3(player, papan);  // Papan otomatis ke yang 6x6 untuk mode player vs player //
		
		// k,m,n merupakah variabel variabel yang digunakan untuk input user //
		k=ketikSO (inputSO, k); // input angka 1 untuk S, angka 2 untuk O // 
		m=ketikBaris(inputBaris, m,inputLevel); // input posisi baris //
		n=ketikKolom(inputKolom, n,inputLevel);	 // input posisi kolom //
		
		// cek posisi berguna untuk mengecek apakah player sudah benar menginputkan di kotak yang kosong atau belum//
		CekPosisi=cekPosisiInput(m, n, k, papan, CekSudahBenar);
		if (CekPosisi==1){
			player--; // jika player malah menginput di kotak yang ada huruf S atau O maka giliran player tersebut diulang lagi dengan fungsi player-- //
			cekPenuh--; // cekPenuh pun akan berkurang jika user salah input//
		}
		// cek skor apakah player berhasil medapatkan kata SOS atau tidak, lalu jika iya maka pada kondisi player=1 maka skor player 1 bertambah, jika player 2 maka skor player 2 bertambah //
    	if (cekSkor(m,n,k,papan,j)>0 && CekPosisi==0){
    		if (player==1){
    			player1.skor = player1.skor + cekSkor(m,n,k,papan,j);
    			player--; // player-- maka player1 akan mendapat giliran lagi jika berhasil menyusun kata SOS //
			}else if (player==2){
				player2.skor = player2.skor + cekSkor(m,n,k,papan,j);
				player--; // player-- maka player2 akan mendapat giliran lagi jika berhasil menyusun kata SOS //
			}
		}
		player++;
    	cekPenuh++;
    	penanda=cekKotakPenuh(cekPenuh,i,j); // penanda berfungsi untuk mengecek apakah papan sudah poenuh atau belum, jika sudah maka keluar while //
	}while (penanda!=0);
	writeData2(); // menyimpan data pemain yang menang untuk keperluan highscore //
	gameover(); // tampil UI gameover // 
	CekWin2(player1.skor,player2.skor,player1.nama,player2.nama); //menampilkan siapakah pemenangnya //
	Retry(); // menampilkan UI fitur retry //
}

// UI gameover //
void gameover(){
	setwarna(15); // set warna menjadi default (putih) //
	system("cls");
	printf("\t\t\t\t\t _______________________\n");
	printf("\t\t\t\t\t|        GAME OVER      |\n");
	printf("\t\t\t\t\t|_______________________|\n");
}

// menampilkan siapa pemenangnya di mode player vs komputer //
void CekWin1(int skor1, int skor2, char nama1[10], char nama2[10]){
	if (skor1>skor2){ // user/player1 menang //
		printf("\n\t\t\t\t\t   SELAMAT ANDA MENANG! \n");
		system("pause");
	}else if (skor1==skor2){ // skor seri //
		printf("\n\t\t\t\t\tMANTAP SKOR MASIH IMBANG! \n");
		system("pause");
	}else{ // komputer menang //
		printf("\n\t\t\t\t\tYAHH ANDA KURANG BERUNTUNG... \n", nama2);
		system("pause");
	}
}
// menampilkan siapa pemenangnya di mode player vs player //
void CekWin2(int skor1, int skor2, char nama1[10], char nama2[10]){
	if (skor1>skor2){ // player 1 menang // 
		printf("\n\t\t\t\t\t  SELAMAT %s MENANG! \n", nama1);
		system("pause");
	}else if (skor1==skor2){ // skor seri //
		printf("\n\t\t\t\t\tMANTAP SKOR MASIH IMBANG! \n");
		system("pause");
	}else{ // player 2 menang //
		printf("\n\t\t\t\t\t  SELAMAT %s MENANG! \n", nama2);
		system("pause");
	}	
}

// UI tampilan dan input nama player 1, di mode player vs player //
void UIinputnama1(){
	system("cls");
	printf("\t\t\t\t\t ________________________________________________\n");
	printf("\t\t\t\t\t|               Enter Name Player1               |\n");
	printf("\t\t\t\t\t|________________________________________________|\n");
	printf("\t\t\t\t\t                  (Maks 6 huruf)              \n\t\t\t\t\t\t\t      ");
	scanf("%s", &player1.nama);
	if (strlen(player1.nama)>6){ // jika ternyata jumlah karakter input namanya melebihi 6 karakter //
		printf("\n\t\t\t\t\t\t      Jumlah Karakter Maks 6!\n");
		system("pause");
		UIinputnama1();
	}
}

// UI tampilan dan input nama player 2, di mode player vs player //
void UIinputnama2(){
	system("cls");
	printf("\t\t\t\t\t ________________________________________________\n");
	printf("\t\t\t\t\t|               Enter Name Player2               |\n");
	printf("\t\t\t\t\t|________________________________________________|\n");
	printf("\t\t\t\t\t                  (Maks 6 huruf)              \n\t\t\t\t\t\t\t      ");
	scanf("%s", &player2.nama);
	if (strlen(player2.nama)>6){ // jika ternyata jumlah karakter input namanya melebihi 6 karakter //
		printf("\n\t\t\t\t\t\t      Jumlah Karakter Maks 6!\n");
		system("pause");;
		UIinputnama2();
	}
}

// UI retry //
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

// input di fitur retry //
void inputDiRetry(int inputRetry){
	scanf("%d", &inputRetry);
	switch (inputRetry){
		case 1 : Play();break;
		case 2 : tampilMenu();break;
		default : printf("\nInput harus angka 1 atau 2\n");system("pause");Retry();break;
	}
}

// Modul mengecek apakah kota sudah penuh atau belum //
int cekKotakPenuh(int cekPenuh, int i, int j){
	int penanda;
	if (cekPenuh==(i*j)){ // jika cekpenuh = banyaknya isi papan, maka penanda = 0 (berarti keluar permainan) //
		penanda=0;
	}else {
		penanda=1; // jika cekpenuh tidak sama dengan banyaknya isi papan, maka penanda = 1 (masih di dalam permainan) //
	}
	return penanda;
}

// Modul untuk mengecek posisi input user apakah sudah benar di kotak yang kosong atau tidak //
int cekPosisiInput(int m, int n, int k,char papan[][6], int CekSudahBenar){
    if (papan[m][n]==' '){
   		 papan[m][n]=k;	
   		 CekSudahBenar=0;
   		 return CekSudahBenar;
	}else { // jika ternyata kotak sudah diisi //
		printf("\nMAAF KOTAK SUDAH DIISI\n");
		system("pause");
		CekSudahBenar=1;
		return CekSudahBenar;
	}
}

// Modul untuk huruf S atau O, input angka 1 untuk S, input angka 2 untuk O //
int ketikSO (int inputSO, int k){
	printf("\t\t\t\t\t  Ketikan Angka 1 untuk (S) atau angka 2 untuk (O) :");
	scanf("%d", &inputSO);
	if (inputSO==1 || inputSO==2){
		k=OlahInputSO (inputSO);
   		return k;
	}else if (inputSO==9){ // jika input=9 maka back to menu //
		tampilMenu();
	}
	else{ // jika input bukan merupakan angka 1 atau 2 atau juga bukan 9 //
		printf("\nERROR (INPUT HARUS ANGKA 1 ATAU 2)\n");
		system("pause");
		ketikSO (inputSO,k);
	}
}

// Modul untuk menginput posisi baris dari user //
int ketikBaris(int inputBaris, int m, int inputLevel){
	if (inputLevel==1){ // jika di level 1 (papan 3x3) //
		printf("\n\t\t\t\t\t  Masukan Posisi Baris (Angka 1-3):");
		scanf("%d", &inputBaris);
		if (inputBaris>=1 && inputBaris<=3){
	    	m=OlahInputBaris (inputBaris);
    		return m;
		}else if (inputBaris == 9){ // jika input=9 maka back to menu //
			tampilMenu();
		}
		else{ // jika input bukan merupakan angka 1-3 atau bukan 9 //
			printf("\nERROR (INPUT POSISI BARIS HARUS ANGKA ANTARA 1-3)\n");
			system("pause");
			ketikBaris(inputBaris,m,inputLevel);	
		}
	}
	else if (inputLevel==2){ // jika di level 2 (papan 5x5) //
		printf("\n\t\t\t\t\t  Masukan Posisi Baris (Angka 1-5):");
		scanf("%d", &inputBaris);
		if (inputBaris>=1 && inputBaris<=5){
	    	m=OlahInputBaris (inputBaris);
    		return m;
		}else if (inputBaris == 9){ // jika input=9 maka back to menu //
			tampilMenu();
		}
		else{ // jika input bukan merupakan angka 1-5 atau bukan 9 //
			printf("\nERROR (INPUT POSISI BARIS HARUS ANGKA ANTARA 1-5)\n");
			system("pause");
			ketikBaris(inputBaris,m,inputLevel);	
		}
	}
	else if (inputLevel==3){ // jika di level 3 (papan 6x6) //
		printf("\n\t\t\t\t\t  Masukan Posisi Baris (Angka 1-6):");
		scanf("%d", &inputBaris);
		if (inputBaris>=1 && inputBaris<=6){
	    	m=OlahInputBaris (inputBaris);
    		return m;
		}else if (inputBaris == 9){ // jika input=9 maka back to menu //
			tampilMenu();
		}else{ // jika input bukan merupakan angka 1-6 atau bukan 9 //
			printf("\nERROR (INPUT POSISI BARIS HARUS ANGKA ANTARA 1-6)\n");
			system("pause");
			ketikBaris(inputBaris,m,inputLevel);	
		}
	}
}

// Modul untuk menginput posisi kolom dari user //
int ketikKolom(int inputKolom,int n, int inputLevel){
	if (inputLevel==1){ // jika di level 1 (papan 3x3) //
		printf("\n\t\t\t\t\t  Masukan Posisi Kolom (Angka 1-3):");
		scanf("%d", &inputKolom);
		if (inputKolom>=1 && inputKolom<=3){
			n=OlahInputKolom (inputKolom);
    		return n;
		}else if (inputKolom == 9){ // jika input=9 maka back to menu //
			tampilMenu();
		}else{ // jika input bukan merupakan angka 1-3 atau bukan 9 //
			printf("\nERROR (INPUT POSISI KOLOM HARUS ANGKA ANTARA 1-3)\n");
			system("pause");
			ketikKolom(inputKolom,n,inputLevel);
		}	
	}
	else if (inputLevel==2){ // jika di level 2 (papan 5x5) //
		printf("\n\t\t\t\t\t  Masukan Posisi Kolom (Angka 1-5):");
		scanf("%d", &inputKolom);
		if (inputKolom>=1 && inputKolom<=5){
			n=OlahInputKolom (inputKolom);
    		return n;
		}else if (inputKolom == 9){ // jika input=9 maka back to menu //
			tampilMenu();
		}else{ // jika input bukan merupakan angka 1-5 atau bukan 9 //
			printf("\nERROR (INPUT POSISI KOLOM HARUS ANGKA ANTARA 1-5)\n");
			system("pause");
			ketikKolom(inputKolom,n,inputLevel);
		}	
	}
	else if (inputLevel==3){ // jika di level 3 (papan 6x6) //
		printf("\n\t\t\t\t\t  Masukan Posisi Kolom (Angka 1-6):");
		scanf("%d", &inputKolom);
		if (inputKolom>=1 && inputKolom<=6){
			n=OlahInputKolom (inputKolom);
    		return n;
		}else if (inputKolom == 9){ // jika input=9 maka back to menu //
			tampilMenu();
		}else{ // jika input bukan merupakan angka 1-6 atau bukan 9 //
			printf("\nERROR (INPUT POSISI KOLOM HARUS ANGKA ANTARA 1-6)\n");
			system("pause");
			ketikKolom(inputKolom,n,inputLevel);
		}	
	}
}

// Modul cek kata SOS //
int cekSkor(int m,int n,int k,char papan[6][6],int j){
	/* variabel m untuk menampung indeks baris
	   variabel n untuk menampung indeks kolom
	   variabel k untuk menampung simbol S atau O
	   variabel j untuk menampung panjangnya kolom papan */
	int skor=0; // set awal skor=0 //
	if (k==83){ // simbol 83, isi simbol dengan huruf S // 
		// fungsi (jj!=0) untuk mencegah terjadinya indeks kolom minus //
        // fungsi (jj!=j-1) untuk mencegah terjadinya indeks kolom yang melebihi j //
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
    else if (k==79){ // simbol 79, isi simbol dengan huruf O // 
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
	return skor; // return jumlah skor //
}

// Modul untuk mengubah inputan angka 1 menjadi huruf S, dan inputan angka 2 menjadi huruf O //
int OlahInputSO(int x){
	if(x==1){
		x=83;
	}else if (x==2){
		x=79;
	}
	return x;
}

// Modul untuk mengurangi inputan posisi baris dari user, ini dilakukan karena bahasa C memulai indeks array nya dari 0 //
int OlahInputBaris(int y){
	y=y-1;
	return y;
}

// Modul untuk mengurangi inputan posisi kolom dari user, ini dilakukan karena bahasa C memulai indeks array nya dari 0 //
int OlahInputKolom(int z){
	z=z-1;
	return z;
}



