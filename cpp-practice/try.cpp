#include <iostream>
using namespace std;
int main(){
    string first = "Johanes", last = "Brian";
    string full = first + " " + last;
    cout << full << '\n';
    cout << full.size() << '\n';
    first += "!";
    cout << first << " | " << full;
}