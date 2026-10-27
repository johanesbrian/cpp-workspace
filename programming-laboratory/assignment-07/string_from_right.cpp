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

/*
PSEUDOCODE

FUNCTION string_from_right(st, n)
    IF n > LENGTH(st) THEN
        n = LENGTH(st)
    END IF
    start_index = LENGTH(st) - n
    result = ""
    FOR i = start_index TO LENGTH(st) - 1
        result = result + st[i]
    END FOR
    RETURN result
END FUNCTION

BEGIN
    DECLARE st as STR
    DECLARE n as INT

    OUTPUT "Enter a string: "
    INPUT st (whole line)
    OUTPUT "Enter the number of characters to retrieve from the right: "
    INPUT n

    result = string_from_right(st, n)
    OUTPUT "Result: ", result
END
*/