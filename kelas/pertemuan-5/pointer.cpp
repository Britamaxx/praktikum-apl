#include <iostream>
using namespace std;
struct Menu {
    string nama;
    float harga;
};
int main () {
    Menu nasgor;
    Menu *nasgorPtr = &nasgor;
    nasgor.nama = "Nasi Goreng Cumi Hitam Pak Kris";
    nasgor.harga = 15000;
    cout << nasgor.nama << " " << nasgor.harga<<endl;
    // kita bisa mengakses/manipulasi value variabel nasgor
    // melalui variabel nasgorPtr
    nasgorPtr->nama = "Nasi Goreng Mawut";
    nasgorPtr->harga = 13000;
    cout << nasgor.nama << " " << nasgor.harga <<endl;
    // kalau memberi value pada atribut biasa pakai ( . )
    // kalau memberi value pada atribut dari pointer pakai ( -> )
    return 0;
}