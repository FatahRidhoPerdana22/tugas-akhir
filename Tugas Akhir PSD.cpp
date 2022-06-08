#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <iomanip>
#include <string>
using namespace std;

int pilih;
void pilihan();
struct SIMPUL
{
    string nama, gender;
    string Nama;
    int nk, mulai, selesai;
    int j_jam, perjam, biaya;
    int info;
    SIMPUL *left, *right;
};
SIMPUL *data, *first = NULL, *last = NULL, *help, *del, *q;
void BUAT_SIMPUL(int X)
{
    data = (SIMPUL *)malloc(sizeof(SIMPUL));
    if (data != NULL)
        data->info = X;
    else
    {
        cout << "Membuat simpul gagal";
        exit(1);
    }
}
void buat_data()
{
    data = new (SIMPUL);
    cout << "    No. Komputer : ";
    cin >> data->nk;
    cout << "    Nama Pelanggan : ";
    cin >> data->nama;
    cout << "    Masukkan Gender : ";
    cin >> data->gender;
    cout << "    Jam Mulai : ";
    cin >> data->mulai;
    cout << "    Jam Selesai : ";
    cin >> data->selesai;
    cout << "\n  ==========================";
    cout << "\n      Data telah dimasukkan   ";
    getch();
    data->left = NULL;
    data->right = NULL;
}
void insert_data()
{
    buat_data();
    if (first == NULL)
    {
        first = data;
        last = data;
        last->right = NULL;
    }
    else
    {
        last->right = data;
        last = data;
        last->right = NULL;
    }
    cout << endl
        << endl;
}
void hapus_data()
{
    string hapus, Nama;
    if (last == NULL)
    {
        cout << "\n    Data kosong, \nPenghapusan tidak dapat dilakukan" << endl;
        getch();
    }
    else
    {
        hapus = first->Nama;
        cout << "\n    Data Nama yang dihapus adalah :";
        cin >> Nama;
        cout << "    Data Nama " << Nama << " sudah dihapus";
        del = first;
        q = first->right;
        first = q;
        delete del;
        getch();
    }
}

void cetak_data()
{
    if (last == NULL)
    {
        cout << "    Data kosong!";
        getch();
    }
    else
    {
        help = first;
        
            cout << "______________________________________________________________________________________\n";
			cout << "|                                       WELCOME                                       |\n";
			cout << "|                                    WARNET TPLP002                                   |\n";
			cout << "______________________________________________________________________________________\n";
			cout << "| No. PC |    Name   |   Gender  |      Time      |   Total Time   |  Cost  |  Total  |\n";
			cout << "|        |           |           | Start   Finish |                |        |         |\n";
			cout << "______________________________________________________________________________________\n";
        while (help != NULL)
        {
        		help->j_jam = help->selesai - help->mulai;
        	if(help->j_jam <= 3){
        		help->perjam = 5000;cout<<endl;
			}
			else if(help->j_jam <= 6){
        		help->perjam = 4000;cout<<endl;
			}
			else if(help->j_jam <= 10){
        		help->perjam = 3000;cout<<endl;
			}
			else{
        		help->perjam = 2000;cout<<endl;
			}
			help->biaya = help->j_jam*help->perjam;
            cout <<setw(5)<<help->nk<<setw(12)<<help->nama<<setw(13)<<help->gender<<setw(8)<<help->mulai<<setw(9)<<help->selesai<<setw(14)<<help->j_jam<<setw(15)<<help->perjam<<setw(13)<<help->biaya<<endl;
            cout << "______________________________________________________________________________________\n";
            cout << endl;
            help = help->right;
        }
        getch();
    }
}
int main()
{
    do
    {
        system("cls");
        cout << "    MENU BILLING" << endl;
        cout << "   ==========================" << endl;
        cout << "    1. Tambah data "<<endl;
        cout << "    2. Hapus Data "<<endl;
        cout << "    3. Cetak Data "<<endl;
        cout << "    4. Exit "<<endl;
        cout << "    Pilihan (1-4) : ";
        cin >> pilih;
        cout << "    ==========================" << endl;
        cout << endl;
        pilihan();
    }
    while (pilih != 4);
}
void pilihan()
{
    if (pilih == 1)
    {
        insert_data();
    }
    else if (pilih == 2)
        hapus_data();
    else if (pilih == 3)
        cetak_data();
    else
    {
  
    }
}

