/*  
    ASSIGNMENT 2.2:
    Create a program that reads the two data in form of time, then computes the difference between the data!
    The dialogue is as the following:
    - Input the first hour: ...
    - Input the first minute: ...
    - Input the second hour: ...
    - Input the second minute: ...
    - Output: The difference between the two times is ... minutes
    Assume that the first time is always earlier than the second time.
*/ 

#include <iostream>
using namespace std;
int main(){
    int first_hour, first_minute, second_hour, second_minute;

    cout << "Input the first hour: ";
    cin >> first_hour;
    cout << "Input the first minute: ";
    cin >> first_minute;
    cout << "Input the second hour: ";
    cin >> second_hour;
    cout << "Input the second minute: ";
    cin >> second_minute;

    int total_first_time = (first_hour * 60) + first_minute;
    int total_second_time = (second_hour * 60) + second_minute;

    int time_difference = total_second_time - total_first_time;

    cout << "The difference between the two times is " << time_difference << " minutes" << endl;

    return 0;
}

/*
PSEUDOCODE:
    START
        DECLARE first_hour AS INTEGER
        DECLARE first_minute AS INTEGER
        DECLARE second_hour AS INTEGER
        DECLARE second_minute AS INTEGER
        DECLARE total_first_time AS INTEGER
        DECLARE total_second_time AS INTEGER
        DECLARE time_difference AS INTEGER

        PRINT "Input the first hour: "
        INPUT first_hour
        PRINT "Input the first minute: "
        INPUT first_minute
        PRINT "Input the second hour: "
        INPUT second_hour
        PRINT "Input the second minute: "
        INPUT second_minute

        total_first_time = (first_hour * 60) + first_minute
        total_second_time = (second_hour * 60) + second_minute

        time_difference = total_second_time - total_first_time

        PRINT "The difference between the two times is ", time_difference, " minutes"
    END
*/