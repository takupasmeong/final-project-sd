#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#define MAX 50

using namespace std;

struct Mahasiswa
{
    int nim;
    char nama[MAX];
    string prodi;
    string angkatan;
    struct Mahasiswa* next;
};
Mahasiswa* head = NULL;
Mahasiswa* current = NULL;

//main program function
void MainMenu();
void AddData();
void ShowData();
void ShowDataQueue();
void ShowDataSearch();
void CheckOutData();
void SortingData();
//void EditData();

//linkedlist function
int isEmpty();

int main() {
    while (true)
    {
        int pilih;
        MainMenu();
    reinput:
        cout << "No. Menu [1..5] : "; cin >> pilih;

        switch (pilih)
        {
        case 1:
            AddData();
            break;
        case 2:
            CheckOutData();
            break;
        case 3:
            ShowData();
            break;
        case 4:
            SortingData();
            break;
        case 5:
            return 0;
        default:
            cout << "opsi tidak tersedia" << endl;
            goto reinput;
        }
    }
}

int isEmpty()
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void  MainMenu()
{
    system("cls");
    cout << "MENU UTAMA" << endl;
    cout << "1. Input Data Mahasiswa\n2. Checkout Data Mahasiswa\n3. Tampilkan Data Mahasiswa\n4. Sorting Nim Mahasiswa\n5. Keluar" << endl;
}

void AddData()
{
    system("cls");
    cout << "Input Data Mahasiswa" << endl;

    Mahasiswa* new_mahasiswa = new Mahasiswa;

    cout << "Nim : "; cin >> new_mahasiswa->nim; cin.ignore();
    cout << "Nama : "; cin.getline(new_mahasiswa->nama, MAX);
    cout << "Program Studi : "; getline(cin, new_mahasiswa->prodi);
    cout << "Angkatan : "; getline(cin, new_mahasiswa->angkatan);
    new_mahasiswa->next = NULL;

    if (isEmpty() == 1)
    {
        head = new_mahasiswa;
        head->next = NULL;
    }
    else
    {
        current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_mahasiswa;
    }
    cout << "Data Masuk" << endl;

    cout << endl << "tekan ENTER untuk kembali ke Menu Utama..." << endl;
    _getch();
}

void ShowDataQueue()
{
    system("cls");
    cout << "Tampilan Data Antrian Mahasiswa" << endl << endl;

    int num = 1;

    current = head;
    if (isEmpty() == 0)
    {
        while (current != NULL)
        {
            cout << "Antrean Urutan Ke-" << num << endl;
            cout << "Nim : " << current->nim << endl;
            cout << "Nama : " << current->nama << endl;
            cout << "Program Studi : " << current->prodi << endl;
            cout << "Angkatan : " << current->angkatan << endl << endl;
            current = current->next;
            num++;
        }
        cout << endl;
    }
    else
    {
        cout << "Data Masih Kosong" << endl << endl;
    }

    cout << "tekan ENTER untuk kembali ke Menu Utama..." << endl;
    _getch();
}

void ShowDataSearch()
{
    system("cls");
    cout << "Tampilan Data Mahasiswa Yang Dicari" << endl << endl;

    Mahasiswa* ptr;
    int search_nim, i = 0;
    string search_nama, search_prodi, search_angkatan;
    bool status = false;

    ptr = head;
    if (isEmpty() == 0)
    {
        cout << "Input Nim : "; cin >> search_nim;
        cout << endl;

        while (ptr != NULL)
        {
            if (ptr->nim == search_nim)
            {
                cout << "Data Berada Pada Antrean Ke-" << i + 1 << endl;
                search_nama = ptr->nama;
                search_prodi = ptr->prodi;
                search_angkatan = ptr->angkatan;
                status = true;
            }
            i++;
            ptr = ptr->next;
        }
        if (status == false)
        {
            cout << "Data Tidak Ditemukan" << endl << endl;
        }
        else
        {
            cout << "Nim : " << search_nim << endl;
            cout << "Nama : " << search_nama << endl;
            cout << "Prodi : " << search_prodi << endl;
            cout << "Angkatan : " << search_angkatan << endl << endl;
        }
    }
    else
    {
        cout << "Data Masih Kosong" << endl << endl;
    }

    cout << "tekan ENTER untuk kembali ke Menu Utama..." << endl;
    _getch();

}

void ShowData()
{
    system("cls");

    int pilih;

    cout << "1. Tampilkan Antrean Mahasiswa\n2. Cari Data Mahasiswa" << endl;
    reinput:
    cout << "pilih [1..2] : "; cin >> pilih;

    if (pilih == 1)
    {
        ShowDataQueue();
    }
    else if (pilih == 2)
    {
        ShowDataSearch();
    }
    else
    {
        cout << "Pilihan Tidak Tersedia" << endl;
        goto reinput;
    }
}

void CheckOutData()
{
    system("cls");
    cout << "Checkout Data Mahasiswa" << endl << endl;

    Mahasiswa* hapus;
    int delete_nim;
    string delete_nama, delete_prodi, delete_angkatan;

    if (isEmpty() == 0)
    {
        if (head->next != NULL)
        {
            hapus = head;
            delete_nim = hapus->nim;
            delete_nama = hapus->nama;
            delete_prodi = hapus->prodi;
            delete_angkatan = hapus->angkatan;
            head = head->next;
            delete hapus;
        }
        else
        {
            delete_nim = head->nim;
            delete_nama = head->nama;
            delete_prodi = head->prodi;
            delete_angkatan = head->angkatan;
            head = NULL;
        }
        cout << "Data Mahasiswa dengan " << endl;
        cout << "NIM : " << delete_nim << endl;
        cout << "Nama : " << delete_nama << endl;
        cout << "Program Studi : " << delete_prodi << endl;
        cout << "Angkatan : " << delete_angkatan << endl;
        cout << "BERHASIL DIPROSES" << endl << endl;

    }
    else
    {
        cout << "Data Masih Kosong" << endl << endl;
    }

    cout << "tekan ENTER untuk kembali ke Menu Utama..." << endl;
    _getch();
} 

void SortingData()
{
    system("cls");
    cout << "Sorting NIM Mahasiswa" << endl << endl;
    Mahasiswa* index = NULL;
    int nim, i = 1;

    current = head;

    if (isEmpty() == 0)
    {
        while (current != NULL)
        {
            index = current->next;
            while (index != NULL)
            {
                if (current->nim > index->nim)
                {
                    nim = current->nim;
                    current->nim = index->nim;
                    index->nim = nim;
                }
                index = index->next;
            }
            cout << i << ". Nim : " << current->nim << endl;
            current = current->next;
            i++;
        }
        cout << endl;
    }
    else
    {
        cout << "Data Masih Kosong" << endl << endl;
    }

    cout << "tekan ENTER untuk kembali ke Menu Utama..." << endl;
    _getch();
}

/*void EditData()
{
    system("cls");
    cout << "Edit Data Mahasiswa" << endl;

    Mahasiswa* ptr = head;
    int search_nim, new_nim;
    char new_nama[MAX];
    string new_prodi, new_angkatan;

    if (isEmpty() == 0)
    {
        cout << "Ganti Data Pada Nim : "; cin >> search_nim;
        cout << "Input Nim Baru : "; cin >> new_nim; cin.ignore();
        cout << "Input Nama Baru : "; cin.getline(new_nama, MAX);
        cout << "Input Program Studi Baru : "; getline(cin, new_prodi);
        cout << "Input Angkatan Baru : "; getline(cin, new_angkatan);
        while (ptr != NULL)
        {
            if (ptr->nim == search_nim)
            {
                new_nim = ptr->nim;
                strcpy_s(new_nama, ptr->nama);
                new_prodi = ptr->prodi;
                new_angkatan = ptr->angkatan;
                cout << "\nData berhasil diganti" << endl << endl;
            }
            else
            {
                cout << "\nData tidak ditemukan" << endl << endl;
            }
            ptr = ptr->next;
        }
    }
    else
    {
        cout << "Data Masih Kosong" << endl << endl;
    }

    cout << "tekan ENTER untuk kembali ke Menu Utama..." << endl;
    _getch();
}*/