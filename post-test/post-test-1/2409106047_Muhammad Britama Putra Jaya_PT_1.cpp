#include <iostream>

using namespace std;


const int PIN = 6047;
const int kesempatan_maks = 3;

int main() {
    int saldo = 1000000; 
    int input_pin, kesempatan = 0;
    bool verifikasi = false;
    
    while (kesempatan < kesempatan_maks) {
        cout << "Masukkan PIN : ";
        cin >> input_pin;
        
        if (input_pin == PIN) {
            verifikasi = true;
            break;
        } else {
            cout << "PIN salah! Percobaan tersisa : " << (kesempatan_maks - (kesempatan + 1)) << "\n";
            kesempatan++;
        }
    }
    
    if (!verifikasi) {
        cout << "Anda telah 3 kali salah memasukkan PIN. ATM terblokir!\n";
        return 0;
    }
    
    int pilihan;
    do {
        cout << "=============================";
        cout << "\nMENU ATM\n";
        cout << "=============================";
        cout << "\n1. Setor Tunai\n";
        cout << "2. Cek Saldo\n";
        cout << "3. Tarik Tunai\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu : ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: {
                int setor;
                cout << "Masukkan jumlah setor tunai : ";
                cin >> setor;
                if (setor > 0) {
                    saldo += setor;
                    cout << "Setor tunai berhasil! Saldo saat ini : " << saldo << "\n";
                } else {
                    cout << "Jumlah setor tidak valid!\n";
                }
                break;
            }
            case 2:
                cout << "Saldo Anda saat ini : " << saldo << "\n";
                break;
            case 3: {
                int tarik;
                cout << "Masukkan jumlah tarik tunai : ";
                cin >> tarik;
                if (tarik > 0 && tarik <= saldo) {
                    saldo -= tarik;
                    cout << "Tarik tunai berhasil! Saldo saat ini : " << saldo << "\n";
                } else {
                    cout << "Jumlah tarik tidak valid atau saldo tidak mencukupi!\n";
                }
                break;
            }
            case 4:
                cout << "Terima kasih telah menggunakan ATM!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);
    
    return 0;
}