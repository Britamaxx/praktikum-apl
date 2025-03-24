#include <iostream>
#include <string>

using namespace std;

// Struct untuk menyimpan alamat
struct Alamat {
    string jalan;
    string kota;
};

// Struct untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
    Alamat alamat;
};

const int MAX_MAHASISWA = 100;
Mahasiswa daftarMahasiswa[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

// Fungsi untuk menambahkan data mahasiswa
int tambahMahasiswa() {
    if (jumlahMahasiswa >= MAX_MAHASISWA) {
        cout << "Data mahasiswa penuh!" << endl;
        return 0;
    }
    Mahasiswa mhs;
    cin.ignore();
    cout << "Masukkan Nama: ";
    getline(cin, mhs.nama);
    cout << "Masukkan NIM: ";
    getline(cin, mhs.nim);
    cout << "Masukkan IPK: ";
    cin >> mhs.ipk;
    cin.ignore();
    cout << "Masukkan Alamat Jalan: ";
    getline(cin, mhs.alamat.jalan);
    cout << "Masukkan Alamat Kota: ";
    getline(cin, mhs.alamat.kota);

    daftarMahasiswa[jumlahMahasiswa] = mhs;
    jumlahMahasiswa++;
    cout << "Data mahasiswa berhasil ditambahkan!\n";
    return 1;
}

// Fungsi untuk menampilkan seluruh data mahasiswa
int tampilkanMahasiswa() {
    if (jumlahMahasiswa == 0) {
        cout << "Tidak ada data mahasiswa!" << endl;
        return 0;
    }
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama      : " << daftarMahasiswa[i].nama << endl;
        cout << "NIM       : " << daftarMahasiswa[i].nim << endl;
        cout << "IPK       : " << daftarMahasiswa[i].ipk << endl;
        cout << "Alamat    : " << daftarMahasiswa[i].alamat.jalan << ", " << daftarMahasiswa[i].alamat.kota << endl;
    }
    return 1;
}

// Fungsi untuk mengupdate data mahasiswa berdasarkan NIM
int updateMahasiswa() {
    string nim;
    cin.ignore();
    cout << "Masukkan NIM mahasiswa yang ingin diupdate: ";
    getline(cin, nim);

    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (daftarMahasiswa[i].nim == nim) {
            cout << "Masukkan Nama Baru: ";
            getline(cin, daftarMahasiswa[i].nama);
            cout << "Masukkan IPK Baru: ";
            cin >> daftarMahasiswa[i].ipk;
            cin.ignore();
            cout << "Masukkan Alamat Jalan Baru: ";
            getline(cin, daftarMahasiswa[i].alamat.jalan);
            cout << "Masukkan Alamat Kota Baru: ";
            getline(cin, daftarMahasiswa[i].alamat.kota);
            cout << "Data mahasiswa berhasil diperbarui!\n";
            return 1;
        }
    }
    cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan!" << endl;
    return 0;
}

// Fungsi untuk menghapus data mahasiswa berdasarkan NIM
int hapusMahasiswa() {
    string nim;
    cin.ignore();
    cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
    getline(cin, nim);
    
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (daftarMahasiswa[i].nim == nim) {
            for (int j = i; j < jumlahMahasiswa - 1; j++) {
                daftarMahasiswa[j] = daftarMahasiswa[j + 1];
            }
            jumlahMahasiswa--;
            cout << "Data mahasiswa berhasil dihapus!\n";
            return 1;
        }
    }
    cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan!" << endl;
    return 0;
}

int main() {
    int pilihan;
    do {
        cout << "\nMenu: " << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Tampilkan Mahasiswa" << endl;
        cout << "3. Update Mahasiswa" << endl;
        cout << "4. Hapus Mahasiswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahMahasiswa();
                break;
            case 2:
                tampilkanMahasiswa();
                break;
            case 3:
                updateMahasiswa();
                break;
            case 4:
                hapusMahasiswa();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);
    
    return 0;
}