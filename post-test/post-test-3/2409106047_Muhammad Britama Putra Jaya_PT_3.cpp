#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_RESERVASI = 20;
int jumlah_reservasi = 0;

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

        if (pilihan == 1) {
            if (jumlah_reservasi >= MAX_RESERVASI) {
                cout << "Data reservasi penuh!" << endl;
            } else {
                cout << "\nMasukkan Nama Pasien : ";
                getline(cin, reservasi[jumlah_reservasi].pasien.nama);
                cout << "Masukkan Tanggal (DD-MM-YYYY) : ";
                getline(cin, reservasi[jumlah_reservasi].jadwal.tanggal);
                cout << "Masukkan Jam (HH:MM) : ";
                getline(cin, reservasi[jumlah_reservasi].jadwal.jam);
                cout << "Masukkan Nama Dokter : ";
                string nama_dokter;
                getline(cin, nama_dokter);
                reservasi[jumlah_reservasi].dokter.nama = "Drg. " + nama_dokter;
                jumlah_reservasi++;
                cout << "Reservasi berhasil ditambahkan!" << endl;
            }
        } else if (pilihan == 2 || pilihan == 3 || pilihan == 4) {
            if (jumlah_reservasi == 0) {
                cout << "Tidak ada data reservasi!" << endl;
            } else {
                cout << "\n=====================================================================" << endl;
                cout << "| No  | Nama Pasien          | Tanggal     | Jam   | Dokter          |" << endl;
                cout << "=====================================================================" << endl;
                for (int i = 0; i < jumlah_reservasi; i++) {
                    cout << "| " << setw(3) << i+1 << " | "
                         << setw(20) << left << reservasi[i].pasien.nama << " | "
                         << setw(10) << reservasi[i].jadwal.tanggal << " | "
                         << setw(5) << reservasi[i].jadwal.jam << " | "
                         << setw(15) << left << reservasi[i].dokter.nama << " |" << endl;
                }
                cout << "=====================================================================" << endl;
            }
        }

        if (pilihan == 3) {
            int indeks;
            cout << "Masukkan nomor reservasi yang ingin diedit : ";
            cin >> indeks;
            cin.ignore();
            if (indeks < 1 || indeks > jumlah_reservasi) {
                cout << "Nomor reservasi tidak valid!" << endl;
            } else {
                cout << "\nMasukkan Nama Pasien : ";
                getline(cin, reservasi[indeks-1].pasien.nama);
                cout << "Masukkan Tanggal (DD-MM-YYYY) : ";
                getline(cin, reservasi[indeks-1].jadwal.tanggal);
                cout << "Masukkan Jam (HH:MM) : ";
                getline(cin, reservasi[indeks-1].jadwal.jam);
                cout << "Masukkan Nama Dokter : ";
                string nama_dokter;
                getline(cin, nama_dokter);
                reservasi[indeks-1].dokter.nama = "Drg. " + nama_dokter;
                cout << "Reservasi berhasil diperbarui!" << endl;
            }
        }

        if (pilihan == 4) {
            int indeks;
            cout << "Masukkan nomor reservasi yang ingin dihapus : ";
            cin >> indeks;
            cin.ignore();
            if (indeks < 1 || indeks > jumlah_reservasi) {
                cout << "Nomor reservasi tidak valid!" << endl;
            } else {
                for (int i = indeks - 1; i < jumlah_reservasi - 1; i++) {
                    reservasi[i] = reservasi[i + 1];
                }
                jumlah_reservasi--;
                cout << "Reservasi berhasil dihapus!" << endl;
            }
        }

        if (pilihan == 5) {
            cout << "Terima kasih telah menggunakan program ini!" << endl;
        } else if (pilihan < 1 || pilihan > 5) {
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}
