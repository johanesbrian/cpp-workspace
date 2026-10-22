/*  
    ASSIGNMENT 4.2:
    Write an algorithm and program to display numbers whose value is less than or equal to the input number.
    Then display it from the largest value to zero.
    Example:
    - Input: 7 -> Output: 6 4 2 0
    - Input: 4 -> Output: 4 2 0
*/

#include <iostream>
using namespace std;
int main(){
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number % 2 != 0){
        number --;
    }

    for (int i = number; i >= 0; i -= 2){
        cout << i << " ";
    }
    return 0;
}

/*
PSEUDOCODE
START
    DECLARE int number
    
    PRINT "Enter a number: "
    READ number
    
    IF number MOD 2 != 0 THEN
        number := number - 1
    END IF
    
    FOR i := number TO 0 STEP -2 DO
        PRINT i + " "
    END FOR
END
*/