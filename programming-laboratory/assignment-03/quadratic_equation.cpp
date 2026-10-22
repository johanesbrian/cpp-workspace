/*  
    ASSIGNMENT 3.1:
    Create a program to calculate the determinant value from quadratic equation, then determine the value of each root.
    After the determinant value is known, there are 3 possibilities that can be determined the roots of the equation:

    - If D > 0, then x1 and x2 are real values and different, the formula for determining the values is as follows:
      x1 = (-b + sqrt(D)) / (2a)
      x2 = (-b - sqrt(D)) / (2a)
    - If D == 0, then x1 and x2 are real values and equal, the formula for determining the value is as follows:
      x1 = x2 = -b / (2a)
    - If D < 0, then x1 and x2 are imaginary numbers, the formula for determining the values is as follows:
      x1 = (-b + sqrt(abs(D))) / (2a) + i
      x2 = (-b - sqrt(abs(D))) / (2a) - i 
      
    Use: #include <cmath> to use sqrt function and #include <iomanip> to se decimal presicion
    eg. cout << fixed << setprecision(2); cout << "D= " << D << endl;
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    double a, b, c, D;

    cout << "=== QUADRATIC EQUATION DETERMINANT CALCULATOR ===" << endl;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    cout << "Enter the value of c: ";
    cin >> c;

    if (a == 0){
        cout << "\nNot a quadratic equation!" << endl;
        return 0;
    }

    D = pow(b, 2) - 4 * a * c;
    cout << "D = " << D << endl;

    if (D > 0){
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        cout << "x1: " << x1 << " | x2: " << x2 << endl;
    }

    else if (D == 0){
        double x1 = -b / (2 * a);
        double x2 = x1;
        cout << "x1: " << x1 << " | x2: " << x2 << endl;
    }

    else {
        double real_part = -b / (2 * a);
        double imaginary_part = sqrt(abs(D)) / (2 * a);
        cout << "x1: " << real_part << " + " << imaginary_part << "i" << endl;
        cout << "x2: " << real_part << " - " << imaginary_part << "i" << endl;
    }
}

/*
PSEUDOCODE
    START
        DISPLAY "=== QUADRATIC EQUATION DETERMINANT CALCULATOR ==="
        INPUT value of a, b, c

        IF a == 0 THEN
            DISPLAY "Not a quadratic equation!"
            ELSE
                CALCULATE D = b^2 - 4ac
                DISPLAY "D = " + D

                IF D > 0 THEN
                    CALCULATE x1 = (-b + sqrt(D)) / (2a)
                    CALCULATE x2 = (-b - sqrt(D)) / (2a)
                    DISPLAY "x1: " + x1 + " | x2: " + x2
                ELSE IF D == 0 THEN
                    CALCULATE x1 = -b / (2a)
                    SET x2 = x1
                    DISPLAY "x1: " + x1 + " | x2: " + x2
                ELSE
                    CALCULATE real_part = -b / (2a)
                    CALCULATE imaginary_part = sqrt(abs(D)) / (2a)
                    DISPLAY "x1: " + real_part + " + " + imaginary_part + "i"
                    DISPLAY "x2: " + real_part + " - " + imaginary_part + "i"
        ENDIF
    END
*/