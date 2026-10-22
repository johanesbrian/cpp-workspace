/*  
    PROBLEM 2:
    Create a program using the string_from_right function ro retrieve n characters of a string entered by the user, starting from the right.
    This function needs two input parameters, namely the string st and int n which represents the number of n characters to be retrieved.
    
    Example:
    - string_from_right("Yogyakarta", 5) "karta"
    - string_from_right("Yogyakarta", 2) "ta"
*/

#include <iostream>
#include <string>
using namespace std;
string string_from_right(string st, int n){
    int start_index = st.length() - n;
    string result = "";

    for(int i = start_index; i < st.length(); i++){
        result += st[i];
    }
    return result;
}

int main(){
    string st;
    cout << "Enter a string: ";
    getline(cin, st);

    int n;
    cout << "Enter the number of characters to retrieve from the right: ";
    cin >> n;

    string result = string_from_right(st, n);
    cout << "Result: " << result << endl;
    return 0;
}