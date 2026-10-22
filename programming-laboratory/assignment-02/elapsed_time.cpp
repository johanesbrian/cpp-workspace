/*  
    ASSIGNMENT 2.1:
    Create a program that computes the elapsed time based on velocity and distance from the user's input!
    For example, if the program takes the input velocity = 40 and distance = 100, the elapsed time would be 2.5 seconds.
*/

#include <iostream>
using namespace std;
int main() {
    float velocity;
    float distance;

    cout << "Enter the velocity: ";
    cin >> velocity;
    cout << "Enter the distance: ";
    cin >> distance;

    float total_time = distance / velocity;
    cout << "Total elapsed time: " << total_time << " seconds" << endl;

    return 0;
}

/*
PSEUDOCODE:
    START
        DECLARE velocity AS FLOAT
        DECLARE distance AS FLOAT
        DECLARE total_time AS FLOAT

        PRINT "Enter the velocity: "
        INPUT velocity
        PRINT "Enter the distance: "
        INPUT distance

        total_time = distance / velocity

        PRINT "Total elapsed time: ", total_time, " seconds"
    END
*/