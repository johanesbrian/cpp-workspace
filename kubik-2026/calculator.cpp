/* 
    Buatlah Kalkulator sederhana berbasis CLI menggunakan bahasa C++ dengan menu interaktif. Ketentuan:
    1. Alur Utama dan Looping
        - Layar harus terus menampilkan menu utama dan meminta input pengguna sampai pengguna secara spesifik memilih nomor menu untuk "Keluar / Exit".

    2. Urutan Interaksi Menu
        - Tampilkan daftar menu operasi yang tersedia secara jelas dengan nomor urut (contoh: 1. Tambah, ... 7. Keluar).
        - Setelah operasi dipilih, program kemudian meminta input angkanya:
            - Minta input 2 angka (a dan b) untuk operasi aritmatika dasar dan pangkat.
            - Minta input 1 angka saja untuk operasi akar.

    3. Pemrosesan Operasi
        - Program harus mampu memproses dan mencetak hasil untuk 6 operasi berikut:
        Penjumlahan, Pengurangan, Perkalian, Pembagian, Pangkat (menggunakan pow <cmath>), Akar Kuadrat (menggunakan sqrt <cmath>).
 
    4. Sanitasi Input dan Validasi Error
        - Validasi Pembagian: Jika operasi pembagian dipilih dan angka kedua (b) adalah 0, tampilkan pesan error.
        - Validasi Akar: Jika operasi akar dipilih dan angkanya bernilai negatif, tampilkan pesan error.
        - Validasi Karakter: Program harus mampu menangani input mismatch. Jika pengguna mengetikkan huruf saat program meminta angka,
        bersihkan buffer input (menggunakan kombinasi cin.clear() dan cin.ignore()) agar program
       tidak masuk ke dalam infinite loop.
 */

#include <iostream>
#include <cmath>
using namespace std;

// Fungsi buat minta input angka dengan validasi karakter
// Jika user mengetik huruf, buffer dibersihkan lalu input diminta ulang
double inputNumber(string message){
    double number;
    cout << message;
    while (!(cin >> number)){
        cout << "Error: Input must be a number!\n";
        cin.clear();             // reset status error cin
        cin.ignore(1000, '\n');  // buang sisa input yang salah
        cout << message;
    }
    return number;
}

int main(){
    int choice;
    double a, b, result;

    do{
        cout << "\n===== SIMPLE CALCULATOR =====\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Power\n";
        cout << "6. Square Root\n";
        cout << "7. Exit\n";
        cout << "Choose menu (1-7): ";

        // Validasi input menu
        while (!(cin >> choice)){
            cout << "Error: Input must be a number!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Choose menu (1-7): ";
        }

        // 3 & 4 Proses operasi
        switch (choice){
            case 1:
                a = inputNumber("Enter number a: ");
                b = inputNumber("Enter number b: ");
                cout << "Result: " << a << " + " << b << " = " << a + b << endl;
                break;

            case 2:
                a = inputNumber("Enter number a: ");
                b = inputNumber("Enter number b: ");
                cout << "Result: " << a << " - " << b << " = " << a - b << endl;
                break;

            case 3:
                a = inputNumber("Enter number a: ");
                b = inputNumber("Enter number b: ");
                cout << "Result: " << a << " x " << b << " = " << a * b << endl;
                break;

            case 4:
                a = inputNumber("Enter number a: ");
                b = inputNumber("Enter number b: ");
                if (b == 0) {
                    cout << "Error: Cannot divide by zero!\n";
                } else {
                    cout << "Result: " << a << " / " << b << " = " << a / b << endl;
                }
                break;

            case 5:
                a = inputNumber("Enter number a (base): ");
                b = inputNumber("Enter number b (exponent): ");
                result = pow(a, b);
                cout << "Result: " << a << " ^ " << b << " = " << result << endl;
                break;

            case 6:
                a = inputNumber("Enter a number: ");
                if (a < 0) {
                    cout << "Error: Cannot calculate the square root of a negative number!\n";
                } else {
                    result = sqrt(a);
                    cout << "Result: sqrt(" << a << ") = " << result << endl;
                }
                break;

            case 7:
                cout << "Thank you, program finished.\n";
                break;

            default:
                cout << "Error: Menu not available, choose 1-7!\n";
        }

    } while (choice != 7);

    return 0;
}