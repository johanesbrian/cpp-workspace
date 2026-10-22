/*  
    PROBLEM 2:    
    A programming course uses the following grading weights:
    - Assignments: 10% for each assignment, total of 30% for 3 assignments
    - Midterm Exam: 30%
    - Final Exam: 40%

    Write a program that calculates the final grade of a student in the programming course.
    For example, if the user enters the following grades:
    - Assignment 1: 80
    - Assignment 2: 90
    - Assignment 3: 75
    - Midterm Exam: 85
    - Final Exam: 80
    The program should calculate and display:
    Final Grade: 82.00
*/

#include <iostream>
#include <iomanip> // So that it shows the final grade with 2 decimal places
using namespace std;
int main(){
    double assignment1, assignment2, assignment3, midterm, finalExam;
    cout << "Enter grade for Assignment 1: ";
    cin >> assignment1;
    cout << "Enter grade for Assignment 2: ";
    cin >> assignment2;
    cout << "Enter grade for Assignment 3: ";
    cin >> assignment3;
    cout << "Enter grade for Midterm Exam: ";
    cin >> midterm;
    cout << "Enter grade for Final Exam: ";
    cin >> finalExam;

    double finalGrade = (assignment1 * 0.1) + (assignment2 * 0.1) + (assignment3 * 0.1) + (midterm * 0.3) + (finalExam * 0.4);
    
    cout << fixed << setprecision(2); // Set the precision to 2 decimal places
    cout << "Final Grade: " << finalGrade << endl;

    return 0;
}