/*
    ASSIGNMENT 8.2:
    The Ackerman function is recursively defined as follows:
    a(m,n) = n+1                  if m=0
    a(m,n) = a(m-1,1)             if m!=0 and n=0
    a(m,n) = a(m-1, a(m, n-1))    if m!=0 and n!=0
 
    Create a pseudocode and program to calculate the Ackerman function.
*/

#include <iostream>
using namespace std;
 
int ackerman(int m, int n){
    if (m == 0){
        return n + 1;
    } else if (n == 0){
        return ackerman(m - 1, 1);
    } else{
        return ackerman(m - 1, ackerman(m, n - 1));
    }
}
 
int main(){
    int m;
    int n;
    int result;
 
    cout << "Enter value of m (should be <= 3): ";
    cin >> m;
    cout << "Enter value of n: ";
    cin >> n;
 
    if (m < 0 || n < 0){
        cout << "Invalid input! m and n must be >= 0" << endl;
    } else{
        result = ackerman(m, n);
        cout << "Ackerman function (" << m << ", " << n << ") is: " << result << endl;
    }
    return 0;
}

/*
PSEUDOCODE:
 
FUNCTION ackerman(m, n)
    IF m = 0 THEN
        RETURN n + 1
    ELSE IF n = 0 THEN
        RETURN ackerman(m - 1, 1)
    ELSE
        RETURN ackerman(m - 1, ackerman(m, n - 1))
    END IF
END FUNCTION
 
START
    INPUT m, n
    IF m < 0 OR n < 0 THEN
        OUTPUT "Invalid input!"
    ELSE
        result <- ackerman(m, n)
        OUTPUT result
    END IF
END
*/