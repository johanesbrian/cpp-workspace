#include <iostream>
using namespace std;
int main() {
    while (true) {
    int score;
    cout << "Enter your exam score: ";
    cin >> score;

    if (cin.fail()) {
        cout << "Invalid score!" << endl;
        return 0;
    }

    string final_grade;
        if (score >= 85){
        final_grade = "A";
    } else if (score >= 70){
        final_grade = "B";
    } else if (score >= 55){
        final_grade = "C";
    } else if (score >= 40){
        final_grade = "D";
    } else {
        final_grade = "E";
    }

    cout << "Your grade is: " << final_grade << endl;
}
}