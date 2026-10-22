/*  
    PROBLEM 3:
    The following is the grading system at a university:
    Letter Grade    Numerical Grade     Letter Grade Conversion
    A               80.00 - 100         4
    A-              77.50 - 79.99       3.75
    A/B             75.00 - 77.49       3.5
    B+              72.50 - 74.99       3.25
    B               70.00 - 72.49       3
    B-              67.50 - 69.99       2.75
    B/C             65.00 - 67.49       2.5
    C+              62.50 - 64.99       2.25
    C               60.00 - 62.49       2
    C-              57.50 - 59.99       1.75
    C/D             55.00 - 57.49       1.5
    D+              52.50 - 54.99       1.25
    D               50.00 - 52.49       1
    E               < 50.00             0

    Create a program that can convert several numerical values and credit units (SKS) as input cumulatively into a letter grade.
    Example:
    Letter grade of 3 courses
    92, 2 credits + 70, 3 credits, + 60, 4 credits
    = (4 * 2 + 3 * 3 + 2 * 4) / (2 + 3 + 4)
    = (8 + 9 + 8) / (2 + 3 + 4)
    = (25) / (9)
    = ~2.778
    = B-
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    int ncourses;
    cout << "Enter the number of courses: ";
    cin >> ncourses;

    double total_points = 0.0;
    int total_credits = 0;

    for (int i = 0; i < ncourses; i++) {
        double score;
        int credits;
        cout << "Enter score for course " << i + 1 << ": ";
        cin >> score;
        cout << "Enter credits for course " << i + 1 << ": ";
        cin >> credits;

        // Convert individual course score to conversion point
        double point;
        if (score >= 80.00) {
            point = 4.0;
        } else if (score >= 77.50) {
            point = 3.75;
        } else if (score >= 75.00) {
            point = 3.5;
        } else if (score >= 72.50) {
            point = 3.25;
        } else if (score >= 70.00) {
            point = 3.0;
        } else if (score >= 67.50) {
            point = 2.75;
        } else if (score >= 65.00) {
            point = 2.5;
        } else if (score >= 62.50) {
            point = 2.25;
        } else if (score >= 60.00) {
            point = 2.0;
        } else if (score >= 57.50) {
            point = 1.75;
        } else if (score >= 55.00) {
            point = 1.5;
        } else if (score >= 52.50) {
            point = 1.25;
        } else if (score >= 50.00) {
            point = 1.0;
        } else {
            point = 0.0;
        }

        total_points += point * credits;
        total_credits += credits;
    }

    double gpa = total_points / total_credits;
    cout << fixed << setprecision(2);
    cout << "\nYour GPA is: " << gpa << endl;
    
    string final_grade;
    if (gpa >= 4.0) {
        final_grade = "A";
    } else if (gpa >= 3.75) {
        final_grade = "A-";
    } else if (gpa >= 3.5) {
        final_grade = "A/B";
    } else if (gpa >= 3.25) {
        final_grade = "B+";
    } else if (gpa >= 3.0) {
        final_grade = "B";
    } else if (gpa >= 2.75) {
        final_grade = "B-";
    } else if (gpa >= 2.5) {
        final_grade = "B/C";
    } else if (gpa >= 2.25) {
        final_grade = "C+";
    } else if (gpa >= 2.0) {
        final_grade = "C";
    } else if (gpa >= 1.75) {
        final_grade = "C-";
    } else if (gpa >= 1.5) {
        final_grade = "C/D";
    } else if (gpa >= 1.25) {
        final_grade = "D+";
    } else if (gpa >= 1.0) {
        final_grade = "D";
    } else {
        final_grade = "E";
    }

    cout << "Your Final Letter Grade is: " << final_grade << endl;
    return 0;
}