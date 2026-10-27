#include <iostream>
#include <cmath>
using namespace std;

//Function to ask for a number input with character validation.
//If the user types letters, the buffer is cleared and the input is asked again.
double inputNumber(string message) {
    double number;
    cout << message;
    while (!(cin >> number)) {
        cout << "Error: Input must be a number!\n";
        cin.clear();             // reset cin error state
        cin.ignore(1000, '\n');  // discard the remaining invalid input
        cout << message;
    }
    return number;
}

int main() {
    int choice;
    double a, b, result;

    do {
        cout << "\n===== SIMPLE CALCULATOR =====\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Power\n";
        cout << "6. Square Root\n";
        cout << "7. Exit\n";
        cout << "Choose menu (1-7): ";

        // Menu input validation
        while (!(cin >> choice)) {
            cout << "Error: Input must be a number!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Choose menu (1-7): ";
        }

        // 3 & 4. Process the operation
        switch (choice) {
            case 1:
                a = inputNumber("Enter number a: ");
                b = inputNumber("Enter number b: ");
                cout << "Result: " << a << " + " << b << " = " << a + b << endl;
                break;

            case 2:
                a = inputNumber("Enter number a: ");
                b = inputNumber("Enter number b: ");
                cout << "Result: " << a << " - " << b << " = " << a - b << endl;
                break;

            case 3:
                a = inputNumber("Enter number a: ");
                b = inputNumber("Enter number b: ");
                cout << "Result: " << a << " x " << b << " = " << a * b << endl;
                break;

            case 4:
                a = inputNumber("Enter number a: ");
                b = inputNumber("Enter number b: ");
                if (b == 0) {
                    cout << "Error: Cannot divide by zero!\n";
                } else {
                    cout << "Result: " << a << " / " << b << " = " << a / b << endl;
                }
                break;

            case 5:
                a = inputNumber("Enter number a (base): ");
                b = inputNumber("Enter number b (exponent): ");
                result = pow(a, b);
                cout << "Result: " << a << " ^ " << b << " = " << result << endl;
                break;

            case 6:
                a = inputNumber("Enter a number: ");
                if (a < 0) {
                    cout << "Error: Cannot calculate the square root of a negative number!\n";
                } else {
                    result = sqrt(a);
                    cout << "Result: sqrt(" << a << ") = " << result << endl;
                }
                break;

            case 7:
                cout << "Thank you, program finished.\n";
                break;

            default:
                cout << "Error: Menu not available, choose 1-7!\n";
        }

    } while (choice != 7);

    return 0;
}