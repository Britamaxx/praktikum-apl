#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_RESERVASI = 20;

struct Pasien {
    string nama;
};

struct Jadwal {
    string tanggal; // format: DD-MM-YYYY
    string jam;     // format: HH:MM
};

struct Dokter {
    string nama;
};

struct Reservasi {
    Pasien pasien;
    Jadwal jadwal;
    Dokter dokter;
};

Reservasi reservasi[MAX_RESERVASI];
int jumlah_reservasi = 0;

// Fungsi rekursif
int hitung_reservasi(int index) {
    if (index == 0) return 0;
    return 1 + hitung_reservasi(index - 1);
}

// Tambah reservasi
void tambah_reservasi(Reservasi* data, int* jumlah) {
    if (*jumlah >= MAX_RESERVASI) {
        cout << "Data reservasi penuh!\n";
        return;
    }

    cout << "\nMasukkan Nama Pasien : ";
    getline(cin, data[*jumlah].pasien.nama);
    cout << "Masukkan Tanggal (DD-MM-YYYY) : ";
    getline(cin, data[*jumlah].jadwal.tanggal);
    cout << "Masukkan Jam (HH:MM) : ";
    getline(cin, data[*jumlah].jadwal.jam);
    cout << "Masukkan Nama Dokter : ";
    string nama_dokter;
    getline(cin, nama_dokter);
    data[*jumlah].dokter.nama = "Drg. " + nama_dokter;

    (*jumlah)++;
    cout << "Reservasi berhasil ditambahkan!\n";
}

// Lihat reservasi
void lihat_reservasi(Reservasi* data, int jumlah) {
    cout << "\n=====================================================================" << endl;
    cout << "| No  | Nama Pasien          | Tanggal     | Jam   | Dokter          |" << endl;
    cout << "=====================================================================" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << "| " << setw(3) << i + 1 << " | "
             << setw(20) << left << (*(data + i)).pasien.nama << " | "
             << setw(10) << (*(data + i)).jadwal.tanggal << " | "
             << setw(5) << (*(data + i)).jadwal.jam << " | "
             << setw(15) << left << (*(data + i)).dokter.nama << " |" << endl;
    }
    cout << "=====================================================================" << endl;
    cout << "Total reservasi saat ini: " << hitung_reservasi(jumlah) << endl;
}

// Edit reservasi
void edit_reservasi(Reservasi* data, int jumlah) {
    lihat_reservasi(data, jumlah);

    int indeks;
    cout << "Masukkan nomor reservasi yang ingin diedit : ";
    cin >> indeks;
    cin.ignore();
    if (indeks < 1 || indeks > jumlah) {
        cout << "Nomor reservasi tidak valid!\n";
        return;
    }

    Reservasi* p = &data[indeks - 1];
    cout << "\n--- Masukkan Data Baru ---\n";
    cout << "Nama Pasien : ";
    getline(cin, p->pasien.nama);
    cout << "Tanggal (DD-MM-YYYY) : ";
    getline(cin, p->jadwal.tanggal);
    cout << "Jam (HH:MM) : ";
    getline(cin, p->jadwal.jam);
    cout << "Nama Dokter : ";
    string nama_dokter;
    getline(cin, nama_dokter);
    p->dokter.nama = "Drg. " + nama_dokter;

    cout << "Reservasi berhasil diperbarui!\n";
}

// Hapus reservasi
void hapus_reservasi(Reservasi* data, int* jumlah) {
    lihat_reservasi(data, *jumlah);

    int indeks;
    cout << "Masukkan nomor reservasi yang ingin dihapus : ";
    cin >> indeks;
    cin.ignore();
    if (indeks < 1 || indeks > *jumlah) {
        cout << "Nomor reservasi tidak valid!\n";
        return;
    }

    for (int i = indeks - 1; i < *jumlah - 1; i++) {
        data[i] = data[i + 1];
    }
    (*jumlah)--;
    cout << "Reservasi berhasil dihapus!\n";
}

// Fungsi-fungsi sorting
void sort_nama_pasien_asc(Reservasi* data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (data[i].pasien.nama > data[j].pasien.nama) {
                swap(data[i], data[j]);
            }
        }
    }
}

void sort_jam_desc(Reservasi* data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (data[i].jadwal.jam < data[j].jadwal.jam) {
                swap(data[i], data[j]);
            }
        }
    }
}

void sort_dokter_asc(Reservasi* data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if (data[i].dokter.nama > data[j].dokter.nama) {
                swap(data[i], data[j]);
            }
        }
    }
}

// Menu sorting
void menu_sorting(Reservasi* data, int jumlah) {
    int pilihan_sort;
    cout << "\n=== MENU SORTING ===\n";
    cout << "1. Sort Nama Pasien (A-Z)\n";
    cout << "2. Sort Jam (Terbaru ke Terlama)\n";
    cout << "3. Sort Nama Dokter (A-Z)\n";
    cout << "Pilih metode sorting: ";
    cin >> pilihan_sort;
    cin.ignore();

    switch (pilihan_sort) {
        case 1:
            sort_nama_pasien_asc(data, jumlah);
            cout << "Data berhasil diurutkan berdasarkan Nama Pasien (A-Z).\n";
            break;
        case 2:
            sort_jam_desc(data, jumlah);
            cout << "Data berhasil diurutkan berdasarkan Jam (Terbaru ke Terlama).\n";
            break;
        case 3:
            sort_dokter_asc(data, jumlah);
            cout << "Data berhasil diurutkan berdasarkan Nama Dokter (A-Z).\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            break;
    }
    lihat_reservasi(data, jumlah);
}

// Program Utama
int main() {
    string nama, nim;
    int kesempatan = 3;
    bool loginBerhasil = false;

    while (kesempatan > 0) {
        cout << "\n========================================\n";
        cout << "          LOGIN SISTEM KLINIK\n";
        cout << "========================================\n";
        cout << "Masukkan Nama : ";
        getline(cin, nama);
        cout << "Masukkan NIM : ";
        getline(cin, nim);

        if (nama == "britama" && nim == "2409106047") {
            loginBerhasil = true;
            break;
        } else {
            kesempatan--;
            cout << "Login gagal! Sisa kesempatan : " << kesempatan << "\n";
        }
    }

    if (!loginBerhasil) {
        cout << "Anda diblokir! Silahkan hubungi admin.\n";
        return 0;
    }

    int pilihan;
    do {
        cout << "\n========================================\n";
        cout << "   MENU MANAJEMEN RESERVASI KLINIK\n";
        cout << "========================================\n";
        cout << "1. Tambah Reservasi\n";
        cout << "2. Tampilkan Reservasi\n";
        cout << "3. Edit Reservasi\n";
        cout << "4. Hapus Reservasi\n";
        cout << "5. Sorting Reservasi\n";
        cout << "6. Keluar\n";
        cout << "========================================\n";
        cout << "Pilih menu : ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                tambah_reservasi(reservasi, &jumlah_reservasi);
                break;
            case 2:
                if (jumlah_reservasi == 0)
                    cout << "Tidak ada data reservasi!\n";
                else
                    lihat_reservasi(reservasi, jumlah_reservasi);
                break;
            case 3:
                if (jumlah_reservasi == 0)
                    cout << "Tidak ada data reservasi!\n";
                else
                    edit_reservasi(reservasi, jumlah_reservasi);
                break;
            case 4:
                if (jumlah_reservasi == 0)
                    cout << "Tidak ada data reservasi!\n";
                else
                    hapus_reservasi(reservasi, &jumlah_reservasi);
                break;
            case 5:
                if (jumlah_reservasi == 0)
                    cout << "Tidak ada data reservasi!\n";
                else
                    menu_sorting(reservasi, jumlah_reservasi);
                break;
            case 6:
                cout << "Terima kasih telah menggunakan program ini!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (pilihan != 6);

    return 0;
}