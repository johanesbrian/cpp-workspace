#include <iostream>
using namespace std;

int binomial_coefficient(int n, int k){
    if (k == 0 || k == n){
        return 1;
    } else{
        return binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k);
    }
}
 
int main(){
    int n;
    int k;
    int result;
 
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;
 
    if (n < 0 || k < 0 || k > n){
        cout << "Invalid input! n and k must be >= 0 and k must not be greater than n" << endl;
    } else{
        result = binomial_coefficient(n, k);
        cout << "The binomial coefficient C (" << n << ", " << k << ") is: " << result << endl;
    }
    return 0;
}

/*
PSEUDOCODE:

FUNCTION binomial_coefficient(n, k)
    IF k = 0 OR k = n THEN
        RETURN 1
    ELSE
        RETURN binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k)
    END IF
END FUNCTION

START
    INPUT n, k
    IF n < 0 OR k < 0 OR k > n THEN
        OUTPUT "Invalid input!"
    ELSE
        result <- binomial_coefficient(n, k)
        OUTPUT result
    END IF
END
*/