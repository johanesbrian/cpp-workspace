/*
    ASSIGNMENT 5.1:
    Create a pseudocode and a C++ program to compute the average value of an array consisting of N integers.
    The program receives N integers from the user, calculates their total sum, and divides the sum by N to obtain the average value.
*/

#include <iostream>
using namespace std;
int main(){
    int N;
    int arr[10];
    float sum =0;
    float average;
    
    cout << "Enter total number of data: ";
    cin >> N;
    if (N < 1 || N > 10)
    
    {
     cout << "Number not valid!";
     return 0;
    }
    
    for (int i = 0; i < N; i++){
        cout << "Enter a number " << (i + 1) << ": ";
        cin >> arr[i];
        sum +=arr[i];
    }
   
    average = sum / N ;
    cout << "The total average of data = " << average << endl;

    return 0;
}

/*
PSEUDOCODE

START
    DECLARE N
    DECLARE arr[10]
    DECLARE sum = 0
    DECLARE average

    DISPLAY "Enter total number of data: "
    INPUT N

    IF N < 1 OR N > 10 THEN
        DISPLAY "Number not valid!"
        END PROGRAM
    END IF

    FOR i = 0 TO N - 1
        DISPLAY "Enter a number ", i + 1, ": "
        INPUT arr[i]
        sum = sum + arr[i]
    END FOR

    average = sum / N

    DISPLAY "The total average of data = ", average
END
*/
