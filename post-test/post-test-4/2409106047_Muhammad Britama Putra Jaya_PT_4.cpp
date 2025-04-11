#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_RESERVASI = 20;

struct Pasien {
    string nama;
};

struct Jadwal {
    string tanggal;
    string jam;
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

int hitung_reservasi(int index) {
    if (index == 0)
        return 0;
    return 1 + hitung_reservasi(index - 1);
}

void tampilkan_tabel() {
    cout << "\n=====================================================================" << endl;
    cout << "| No  | Nama Pasien          | Tanggal     | Jam   | Dokter          |" << endl;
    cout << "=====================================================================" << endl;
}

void tampilkan_tabel(string pesan) {
    cout << "\n== " << pesan << " ==" << endl;
    tampilkan_tabel();
}

void lihat_reservasi(Reservasi data[], int jumlah) {
    tampilkan_tabel();
    for (int i = 0; i < jumlah; i++) {
        cout << "| " << setw(3) << i + 1 << " | "
             << setw(20) << left << data[i].pasien.nama << " | "
             << setw(10) << data[i].jadwal.tanggal << " | "
             << setw(5) << data[i].jadwal.jam << " | "
             << setw(15) << left << data[i].dokter.nama << " |" << endl;
    }
    cout << "=====================================================================" << endl;
    cout << "Total reservasi saat ini: " << hitung_reservasi(jumlah) << endl;
}

void tambah_reservasi(Reservasi data[], int &jumlah) {
    if (jumlah >= MAX_RESERVASI) {
        cout << "Data reservasi penuh!" << endl;
        return;
    }

    cout << "\nMasukkan Nama Pasien : ";
    getline(cin, data[jumlah].pasien.nama);
    cout << "Masukkan Tanggal (DD-MM-YYYY) : ";
    getline(cin, data[jumlah].jadwal.tanggal);
    cout << "Masukkan Jam (HH:MM) : ";
    getline(cin, data[jumlah].jadwal.jam);
    cout << "Masukkan Nama Dokter : ";
    string nama_dokter;
    getline(cin, nama_dokter);
    data[jumlah].dokter.nama = "Drg. " + nama_dokter;
    jumlah++;
    cout << "Reservasi berhasil ditambahkan!" << endl;
}

void edit_reservasi(Reservasi data[], int jumlah) {
    lihat_reservasi(data, jumlah);

    int indeks;
    cout << "Masukkan nomor reservasi yang ingin diedit : ";
    cin >> indeks;
    cin.ignore();
    if (indeks < 1 || indeks > jumlah) {
        cout << "Nomor reservasi tidak valid!" << endl;
        return;
    }

    cout << "\n--- Data Lama ---" << endl;
    cout << "Nama Pasien : " << data[indeks - 1].pasien.nama << endl;
    cout << "Tanggal     : " << data[indeks - 1].jadwal.tanggal << endl;
    cout << "Jam         : " << data[indeks - 1].jadwal.jam << endl;
    cout << "Dokter      : " << data[indeks - 1].dokter.nama << endl;

    cout << "\n--- Masukkan Data Baru ---" << endl;
    cout << "Nama Pasien : ";
    getline(cin, data[indeks - 1].pasien.nama);
    cout << "Tanggal (DD-MM-YYYY) : ";
    getline(cin, data[indeks - 1].jadwal.tanggal);
    cout << "Jam (HH:MM) : ";
    getline(cin, data[indeks - 1].jadwal.jam);
    cout << "Nama Dokter : ";
    string nama_dokter;
    getline(cin, nama_dokter);
    data[indeks - 1].dokter.nama = "Drg. " + nama_dokter;

    cout << "Reservasi berhasil diperbarui!" << endl;
}

void hapus_reservasi(Reservasi data[], int &jumlah) {
    lihat_reservasi(data, jumlah);

    int indeks;
    cout << "Masukkan nomor reservasi yang ingin dihapus : ";
    cin >> indeks;
    cin.ignore();
    if (indeks < 1 || indeks > jumlah) {
        cout << "Nomor reservasi tidak valid!" << endl;
        return;
    }

    cout << "\nAnda akan menghapus reservasi berikut:" << endl;
    cout << "Nama Pasien : " << data[indeks - 1].pasien.nama << endl;
    cout << "Tanggal     : " << data[indeks - 1].jadwal.tanggal << endl;
    cout << "Jam         : " << data[indeks - 1].jadwal.jam << endl;
    cout << "Dokter      : " << data[indeks - 1].dokter.nama << endl;

    char konfirmasi;
    cout << "Yakin ingin menghapus? (y/n): ";
    cin >> konfirmasi;
    cin.ignore();

    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        for (int i = indeks - 1; i < jumlah - 1; i++) {
            data[i] = data[i + 1];
        }
        jumlah--;
        cout << "Reservasi berhasil dihapus!" << endl;
    } else {
        cout << "Penghapusan dibatalkan." << endl;
    }
}

int main() {
    string nama, nim;
    int kesempatan = 3;
    bool loginBerhasil = false;

    while (kesempatan > 0) {
        cout << "\n========================================" << endl;
        cout << "          LOGIN SISTEM KLINIK" << endl;
        cout << "========================================" << endl;
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
        cout << "Anda diblokir! Silahkan hubungi admin." << endl;
        return 0;
    }

    int pilihan;
    do {
        cout << "\n========================================" << endl;
        cout << "   MENU MANAJEMEN RESERVASI KLINIK" << endl;
        cout << "========================================" << endl;
        cout << "1. Tambah Reservasi" << endl;
        cout << "2. Tampilkan Reservasi" << endl;
        cout << "3. Edit Reservasi" << endl;
        cout << "4. Hapus Reservasi" << endl;
        cout << "5. Keluar" << endl;
        cout << "========================================" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                tambah_reservasi(reservasi, jumlah_reservasi);
                break;
            case 2:
                if (jumlah_reservasi == 0)
                    cout << "Tidak ada data reservasi!" << endl;
                else
                    lihat_reservasi(reservasi, jumlah_reservasi);
                break;
            case 3:
                if (jumlah_reservasi == 0)
                    cout << "Tidak ada data reservasi!" << endl;
                else
                    edit_reservasi(reservasi, jumlah_reservasi);
                break;
            case 4:
                if (jumlah_reservasi == 0)
                    cout << "Tidak ada data reservasi!" << endl;
                else
                    hapus_reservasi(reservasi, jumlah_reservasi);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }

    } while (pilihan != 5);

    return 0;
}