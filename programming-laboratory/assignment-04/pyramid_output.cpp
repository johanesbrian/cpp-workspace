/*  
    ASSIGNMENT 4.1:
    Write an algorithm and program to create a full pyramid using * symbols with the height of the pyramid determined by the user.
    eg. if the user enters 5, the output will be:
                *
              * * *
            * * * * *
          * * * * * * *
        * * * * * * * * * 
*/

#include <iostream>
using namespace std;
int main(){
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= rows -i; j++){
            cout << "  ";
        }


        for (int j = 1; j <= 2 * i - 1; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

/*
PSEUDOCODE
    
START
    
    INPUT rows
    
    FOR i = 1 TO rows
    FOR j = 1 TO rows - i
    PRINT " "
    END FOR
    
    FOR j = 1 TO 2 * i - 1
    PRINT "* "
    END FOR
    
    PRINT new line
    END FOR
END
*/
