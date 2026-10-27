#include <iostream>
#include <iomanip>
using namespace std;

int grade_value(char grade);
double calculate_gpa(char score[], int sks[], int n);

int main(){
    int n;
    char score[100];
    int sks[100];

    cout << "Enter number of courses: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        cout << "Course " << i + 1 << " score (A/B/C/D/E): ";
        cin >> score[i];
        cout << "Course " << i + 1 << " SKS: ";
        cin >> sks[i];
    }

    double gpa = calculate_gpa(score, sks, n);

    cout << fixed << setprecision(1) << "\nGPA = " << gpa << endl;

    return 0;
}

int grade_value(char grade){
    if (grade == 'A' || grade == 'a'){
        return 4;
    } else if (grade == 'B' || grade == 'b'){
        return 3;
    } else if (grade == 'C' || grade == 'c'){
        return 2;
    } else if (grade == 'D' || grade == 'd'){
        return 1;
    } else{
        return 0;
    }
}

double calculate_gpa(char score[], int sks[], int n){
    double total_point = 0;
    int total_sks = 0;

    for (int i = 0; i < n; i++){
        total_point = total_point + grade_value(score[i]) * sks[i];
        total_sks = total_sks + sks[i];
    }

    return total_point / total_sks;
}

/*
PSEUDOCODE

FUNCTION grade_value(grade)
    IF grade = 'A' OR grade = 'a' THEN
        RETURN 4
    ELSE IF grade = 'B' OR grade = 'b' THEN
        RETURN 3
    ELSE IF grade = 'C' OR grade = 'c' THEN
        RETURN 2
    ELSE IF grade = 'D' OR grade = 'd' THEN
        RETURN 1
    ELSE
        RETURN 0
    END IF
END FUNCTION

FUNCTION calculate_gpa(score, sks, n)
    total_point = 0
    total_sks = 0
    FOR i = 0 TO n - 1
        total_point = total_point + grade_value(score[i]) * sks[i]
        total_sks = total_sks + sks[i]
    END FOR
    RETURN total_point / total_sks
END FUNCTION

BEGIN
    DECLARE n as INT
    DECLARE score[100] as CHAR
    DECLARE sks[100] as INT

    OUTPUT "Enter number of courses: "
    INPUT n

    FOR i = 0 TO n - 1
        OUTPUT "Course ", i + 1, " score (A/B/C/D/E): "
        INPUT score[i]
        OUTPUT "Course ", i + 1, " SKS: "
        INPUT sks[i]
    END FOR

    gpa = calculate_gpa(score, sks, n)

    OUTPUT "GPA = ", gpa (rounded to 1 decimal place)
END
*/