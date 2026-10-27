#include <iostream>
#include <cmath>
using namespace std;

// Fungsi untuk meminta input angka dengan validasi karakter.
// Jika user mengetik huruf, buffer dibersihkan lalu input diminta ulang.
double inputAngka(string pesan) {
    double angka;
    cout << pesan;
    while (!(cin >> angka)) {
        cout << "Error: Input harus berupa angka!\n";
        cin.clear();             // reset status error cin
        cin.ignore(1000, '\n');  // buang sisa input yang salah
        cout << pesan;
    }
    return angka;
}

int main() {
    int pilihan;
    double a, b, hasil;

    do {
        // 1 & 2. Tampilkan menu utama
        cout << "\n===== KALKULATOR SEDERHANA =====\n";
        cout << "1. Tambah\n";
        cout << "2. Kurang\n";
        cout << "3. Kali\n";
        cout << "4. Bagi\n";
        cout << "5. Pangkat\n";
        cout << "6. Akar Kuadrat\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu (1-7): ";

        // Validasi input menu
        while (!(cin >> pilihan)) {
            cout << "Error: Input harus berupa angka!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Pilih menu (1-7): ";
        }

        // 3 & 4. Proses operasi
        switch (pilihan) {
            case 1:
                a = inputAngka("Masukkan angka a: ");
                b = inputAngka("Masukkan angka b: ");
                cout << "Hasil: " << a << " + " << b << " = " << a + b << endl;
                break;

            case 2:
                a = inputAngka("Masukkan angka a: ");
                b = inputAngka("Masukkan angka b: ");
                cout << "Hasil: " << a << " - " << b << " = " << a - b << endl;
                break;

            case 3:
                a = inputAngka("Masukkan angka a: ");
                b = inputAngka("Masukkan angka b: ");
                cout << "Hasil: " << a << " x " << b << " = " << a * b << endl;
                break;

            case 4:
                a = inputAngka("Masukkan angka a: ");
                b = inputAngka("Masukkan angka b: ");
                if (b == 0) {
                    cout << "Error: Tidak bisa membagi dengan nol!\n";
                } else {
                    cout << "Hasil: " << a << " / " << b << " = " << a / b << endl;
                }
                break;

            case 5:
                a = inputAngka("Masukkan angka a (basis): ");
                b = inputAngka("Masukkan angka b (pangkat): ");
                hasil = pow(a, b);
                cout << "Hasil: " << a << " ^ " << b << " = " << hasil << endl;
                break;

            case 6:
                a = inputAngka("Masukkan angka: ");
                if (a < 0) {
                    cout << "Error: Tidak bisa menghitung akar dari bilangan negatif!\n";
                } else {
                    hasil = sqrt(a);
                    cout << "Hasil: akar(" << a << ") = " << hasil << endl;
                }
                break;

            case 7:
                cout << "Terima kasih, program selesai.\n";
                break;

            default:
                cout << "Error: Menu tidak tersedia, pilih 1-7!\n";
        }

    } while (pilihan != 7);

    return 0;
}