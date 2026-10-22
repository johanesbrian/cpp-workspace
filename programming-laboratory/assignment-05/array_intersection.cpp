/*
    ASSIGNMENT 5.2:
    Write a pseudocode and program to insert an array, then display the array result that contains the intersections of the two existing arrays.
    The intersection is the elements contained in both arrays.
    Example:
    A = {1, 2, 3, 5, 6, 8}
    B = {4, 6, 1, 5, 2, 8}

    Output:
    1 2 5 6 8
*/

#include <iostream>
using namespace std;
int main(){
     int arrA[6];
    int arrB[6];

    for (int i = 0; i < 6; i++){
        cout << "Enter the value for array A: ";
        cin >> arrA[i];
    }
    
    cout << "\n";
    
    for (int i = 0; i < 6; i++){
        cout << "Enter the value for array B: ";
        cin >> arrB[i];
    }

    cout << "\nA: ";
    for (int i = 0; i < 6; i++){
        cout << arrA[i]<< " 1 ";
    }
    
    cout << "\nB: ";
    for (int i = 0; i < 6; i++){
        cout << arrB[i]<< " ";
    }

    cout << "\n";
    cout << "Intersection: ";
    
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (arrA[i]==arrB[j]){
                cout << arrA[i]<<" ";
                
                break;
            }
        }
    }

    return 0;
}

/*
PSEUDOCODE

START

    DECLARE arrA[6]
    DECLARE arrB[6]

    FOR i = 0 TO 5
        DISPLAY "Enter the value for array A: "
        INPUT arrA[i]
    END FOR

    DISPLAY new line

    FOR i = 0 TO 5
        DISPLAY "Enter the value for array B: "
        INPUT arrB[i]
    END FOR

    DISPLAY "A: "

    FOR i = 0 TO 5
        DISPLAY arrA[i]
    END FOR

    DISPLAY "B: "

    FOR i = 0 TO 5
        DISPLAY arrB[i]
    END FOR

    DISPLAY new line
    DISPLAY "Intersection: "

    FOR i = 0 TO 5
        FOR j = 0 TO 5
            IF arrA[i] == arrB[j] THEN
                DISPLAY arrA[i]
                BREAK
            END IF
        END FOR
    END FOR
END
*/