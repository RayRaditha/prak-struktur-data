//Tugas 3 untuk Praktikum Struktur Data IF-F 2021
//Putu Raditha
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
using namespace std;

typedef string typenama;
typedef int typeumur;
typedef string typegoldar;
typedef string typestatus;
typedef int typeinfo;
typedef struct typedonor *typeptr;

//Deklarasi Struct
struct typedonor {
	typenama nama;
	typeumur umur;
	typegoldar goldar;
	typestatus status;
	typeinfo info;
	typeptr next;
};

//Deklarasi variabel dan fungsi
typeptr data, awal, akhir;
int listkosong();
void inputdata();
void buatlistbaru();
void lihatdata();
void cekdonor();
void cekdonor2(string goldar);
void hapusdata();

//Fungsi utama tempat semua fungsi berjalan
int main() {
	int pilih;
	char ulang;
	bool y = true;
	
	buatlistbaru();
	
	//Tampilan Menu
	do {
		cout << "|=======================================|" << endl;
		cout << "|     UNIT PELAYANAN TRANSFUSI DARAH    |" << endl;
		cout << "|=======================================|" << endl;
		cout << " Daftar Menu : " << endl;
		cout << " 1. Input Data Pendonor" << endl;
		cout << " 2. Lihat Data Pendonor" << endl;
		cout << " 3. Cek Kandidat Pendonor" << endl;
		cout << " 4. Hapus Data Pendonor" << endl;
		cout << " 5. Keluar" << endl;
		cout << "-----------------------------" << endl;
		cout << " Masukkan Pilihan : "; cin >> pilih;
		
		//Switch case pilih
		switch (pilih) {
			case 1:
				inputdata();
				break;
			
			case 2:
				lihatdata();
				break;
			
			case 3:
				cekdonor();
				break;
				
			case 4:
				hapusdata();
				break;
				
			case 5:
				break;
			
			//error handling jika user menginput angka selain 1-5
			default:
				cout << "Silahkan ulangi input an";
				break;
		}
		
		//Jika user memilih menu 5
		if (pilih == 5) {
			y = false;		//nilai bool y menjadi false, program pun selesai (keluar)
		} else {
			cout << endl;
			cout << "Kembali ke Menu (y/t): "; cin >> ulang;
			if (ulang=='y' || ulang=='Y') {
				system("cls");
			} else {
				y = false;
			}
		}
		
	} while(y == true);
}

//Fungsi list kosong
int listkosong() { 
	if (awal==NULL) {  
		return true;  
	} else {   
		return false; 
	}
} 

//fungsi untuk menginput data (saat user memilih menu 1)
void inputdata() {
    typeptr NB;
    NB = new typedonor;
    int jumlah;

	cout << endl;
	cout << "---------------------------" << endl;
    cout << "    Input data Pendonor    " << endl;
	cout << " ------------------------- " << endl;
    cout << " Banyak data yang diinput : "; cin >> jumlah; 
    
    cin.ignore(); 
    for (int i = 1; i <= jumlah; i++){
		cout << endl;
        cout << "Data ke- " << i << endl;
        cout << "Nama Pendonor    :";
        getline(cin,NB->nama);
        cout << "Umur             :";
        cin >> NB->umur; cin.ignore();
        
        do {
			cout << "Golongan darah   :";
            getline(cin,NB->goldar);
        } while (NB->goldar != "O" && NB->goldar != "B" && NB->goldar != "A" && NB->goldar != "AB");
        
        if (NB->umur >= 17 && NB->umur <= 60){
            NB->status = "Bisa donor";
        } else {
            NB->status = "Tidak bisa donor";
        }
        cout << "Status           :" << NB->status;
        
        
        if (NB->status == "Bisa donor") {
            if (listkosong()) {
                awal = NB;
                NB->next = NULL;
                akhir = NB;
            } else {
                akhir->next = NB;
                akhir = NB;
                akhir->next = NULL;
            }
        }
    }
}

//fungsi untuk melihat data (saat user memilih menu 2)
void lihatdata() {
	typeptr bantu;
	int i = 0;
	
	cout << "Lihat Data " << endl;
	cout << "Data berdasar urutan : " << endl;
	bantu=awal;
	
	if (listkosong()) {
		cout << "! DATA MASIH KOSONG !";
	} else {
		while (bantu!=NULL) {
			cout << "Pendonor ke- " << i+1 << endl;
			cout << "Nama Pendonor : " << bantu->nama;
			cout << "\nUmur Pendonor : " << bantu->umur;
			cout << "\nGolongan Darah : " << bantu->goldar;
			cout << endl;
			i++;
			bantu = bantu->next;
		};
	}
	
}

//fungsi untuk membuat list baru dengan variabel bernilai NULL
//Nantinya variabel tersebut akan terisi oleh data-data yang diinput
void buatlistbaru() {
	data=new typedonor;
	data=NULL;
	awal=data;
	akhir=data;
}

//fungsi untuk mengecek pendonor yang sesuai (saat user memilih menu 3)
void cekdonor() {
	typenama nama;
	typeumur umur;
	typegoldar goldar;
	
	//Menginput data penerima donor
	cout << "Nama Penerima donor   : "; cin.ignore(); 
	getline(cin,nama);
	cout << "Umur                  : "; cin >> umur; 
	cin.ignore();
	cout << "Golongan darah         : ";
	getline(cin,goldar);
	
	//Error Handling jika user menginput goldar selain A,B,AB atau O
	if (((goldar=="A" || goldar=="B") || goldar=="AB") || goldar=="O") {
		cekdonor2(goldar);
	} else {
		cout << "! Golongan darah tidak ditemukan !" << endl;
	}
	
}

void cekdonor2(string goldar) {
	typeptr bantu;
	int i = 0;
	
	bantu=awal;
	
	//Pengecekan goldar
	if (goldar=="A"){
        while (bantu!=NULL){
            if (bantu->goldar == "A" || bantu->goldar == "AB"){
                cout << " Pendonor ke-" << i+1 << endl;
                cout << "Nama pendonor   : " << bantu->nama << endl;
                cout << "Umur pendonor   : " << bantu->umur << endl;
                cout << "Golongan darah  : " << bantu->goldar << endl; 
                cout << endl;   
            }
            i++;
            bantu=bantu->next;
        }
    } else if (goldar=="B") {
        while (bantu!=NULL){
            if (bantu->goldar=="B" || bantu->goldar=="AB"){
                cout << "Pendonor ke-" << i+1 << endl;
                cout << "Nama pendonor   : " << bantu->nama << endl;
                cout << "Umur pendonor   : " << bantu->umur << endl;
                cout << "Golongan darah  : " << bantu->goldar << endl;  
                cout << endl;   
            }
            i++;
            bantu=bantu->next;
        }
    } else if (goldar=="AB") {
        while (bantu!=NULL){
            if (bantu->goldar=="AB"){   //Jika Goldarnya AB, maka hanya menampilkan Pendonor dengan Goldar AB
                cout << "Pendonor ke-" << i+1 << endl;
                cout << "Nama pendonor   : " << bantu->nama << endl;
                cout << "Umur pendonor   : " << bantu->umur << endl;
                cout << "Golongan darah  : " << bantu->goldar << endl;  
                cout << endl;   
            }
            i++;
            bantu=bantu->next;
        }
    }  else if (goldar=="O"){			//Jika Goldarnya O, maka semua Goldar akan tampil
        while (bantu!=NULL){
            cout << "Pendonor ke-" << i+1 << endl;
                cout << "Nama pendonor   : " << bantu->nama << endl;
                cout << "Umur pendonor   : " << bantu->umur << endl;
                cout << "Golongan darah  : " << bantu->goldar << endl;  
            cout << endl;   
            i++;
            bantu=bantu->next;
        }
     }
}

//fungsi untuk hapus data (saat user memilih menu 4)
void hapusdata() {
	typeptr hapus,bantu;
	typenama nama;
    
    lihatdata(); //Untuk menampilkan data-data pendonor yang ada

	//Hapus data pendonor berdasarkan nama nya
    cout << endl;
    cout << "Masukkan Nama Pendonor yang datanya ingin dihapus" << endl;
    cout << "Hapus data pendonor : "; cin.ignore(); 
    getline(cin,nama);

	//Pengecekan data nama untuk dihapus
	if (awal->nama==nama) {
        hapus=awal;
        awal=hapus->next;
        free(hapus);
    } else if (akhir->nama==nama) {
        bantu=awal;
        
        while (bantu->next!= akhir) {
			bantu=bantu->next;
		}
		
        akhir=bantu;
        akhir->next=NULL;
        
    } else {
        bantu=awal;
        
        while (bantu->next->nama != nama && bantu->next != akhir) {
            bantu=bantu->next;
        }
        
        hapus=bantu->next;
        if (hapus==akhir) {
			cout << endl;
            cout << "! Data Tidak Ada !" << endl;
        } else {
            bantu->next=hapus->next;
            free(hapus);

        }
    }
}
