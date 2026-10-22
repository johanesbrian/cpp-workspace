/*  
    PROBLEM 1:
    Write a program starting with bookStock set to 67. A customer wants to buy 7 books.
    - previewSale should take stock by value and calculate the stock after selling the books.
    - applySale should take stock by non-const reference and subtract quantitiy from it 
    
    The program should produce the following output:
    - Starting stock: 67
    - Preview after selling 7 : 60
    - Stock after preview: 67
    - Stock after applying sale: 60
*/

#include <iostream>
using namespace std;

int preview_sale(int stock, int quantity) {
    stock -= quantity;
    return stock;
}

void apply_sale(int &stock, int quantity) {
    stock -= quantity;
}

int main(){
    int book_stock = 67;
    cout << "Starting stock: " << book_stock << endl;
    
    int preview = preview_sale(book_stock, 7);
    cout << "Preview after selling 7: " << preview << endl;
    cout << "Stock after preview: " << book_stock << endl;

    apply_sale(book_stock, 7);
    cout << "Stock after applying sale: " << book_stock << endl;

    return 0;
}
