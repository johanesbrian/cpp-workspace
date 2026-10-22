/*  
    PROBLEM 1:
    Given two time values: T1 (hours1, minutes1, seconds1) and T2 (hours2, minutes2, seconds2).
    Write a program to calculate the time difference from T1 to T2.
    (Difference shown in hours, minutes, and seconds)
*/

#include <iostream>
using namespace std;
int main() {
    int hours1, minutes1, seconds1, hours2, minutes2, seconds2;

    cout << "Input the 1st hour: ";
    cin >> hours1;
    cout << "Input the 1st minute: ";
    cin >> minutes1;
    cout << "Input the 1st second: ";
    cin >> seconds1;
    cout << "Input the 2nd hour: ";
    cin >> hours2;
    cout << "Input the 2nd minute: ";
    cin >> minutes2;
    cout << "Input the 2nd second: ";
    cin >> seconds2;

    int total_seconds1 = (hours1 * 3600) + (minutes1 * 60) + seconds1;
    int total_seconds2 = (hours2 * 3600) + (minutes2 * 60) + seconds2;

    int total_time_difference = total_seconds2 - total_seconds1;
    int hours_diff = total_time_difference / 3600;
    int minutes_diff = (total_time_difference % 3600) / 60;
    int seconds_diff = total_time_difference % 60;

    cout << "The time difference is: " << hours_diff << " hours, " << minutes_diff << " minutes, and " << seconds_diff << " seconds." << endl;

    return 0;
}