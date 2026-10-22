/*  
    ASSIGNMENT 3.2:
    Create a program using switch conditional structure to read month code data [1..12]
    from user input, then display the number of days in that month.
*/

#include <iostream>
using namespace std;
int main(){
   cout << "=== MONTH READER === " << endl;
   int month;
   cout << "Enter the month number (1-12): " << endl;
   cin >> month;

   switch (month){
    case 1:
        cout << "January has 31 days" << endl;
        break;
    case 2:
        cout << "February has 28 days" << endl;
        break;
    case 3:
        cout << "March has 31 days" << endl;
        break;
    case 4:
        cout << "April has 30 days" << endl;
        break;
    case 5:
        cout << "May has 31 days" << endl;
        break;
    case 6:
        cout << "June has 30 days" << endl;
        break;
    case 7:
        cout << "July has 31 days" << endl;
        break;
    case 8:
        cout << "August has 31 days" << endl;
        break;
    case 9:
        cout << "September has 30 days" << endl;
        break;
    case 10:
        cout << "October has 31 days" << endl;
        break;
    case 11:
        cout << "November has 30 days" << endl;
        break;
    case 12:
        cout << "December has 31 days" << endl;
        break;
    default:
        cout << "Invalid month number!" << endl;
   }
}

/*
PSEUDOCODE
    START
        DISPLAY "=== MONTH READER ==="
        DISPLAY "Enter the month number (1-12): "
        INPUT month

        SWITCH month
            CASE 1:
                DISPLAY "January has 31 days"
                BREAK
            CASE 2:
                DISPLAY "February has 28 days"
                BREAK
            CASE 3:
                DISPLAY "March has 31 days"
                BREAK
            CASE 4:
                DISPLAY "April has 30 days"
                BREAK
            CASE 5:
                DISPLAY "May has 31 days"
                BREAK
            CASE 6:
                DISPLAY "June has 30 days"
                BREAK
            CASE 7:
                DISPLAY "July has 31 days"
                BREAK
            CASE 8:
                DISPLAY "August has 31 days"
                BREAK
            CASE 9:
                DISPLAY "September has 30 days"
                BREAK
            CASE 10:
                DISPLAY "October has 31 days"
                BREAK
            CASE 11:
                DISPLAY "November has 30 days"
                BREAK
            CASE 12:
                DISPLAY "December has 31 days"
                BREAK
            DEFAULT:
                DISPLAY "Invalid month number!"
        END SWITCH
    END
*/
