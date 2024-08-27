//Program to implement simple calculator using c++ 

#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operation;

    // User inputs the first number
    cout << "Enter the first number: ";
    cin >> num1;

    // User inputs the operation
    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;

    // User inputs the second number
    cout << "Enter the second number: ";
    cin >> num2;

    // Perform the chosen operation
    switch (operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            // Check for division by zero
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Error: Division by zero is not allowed." << endl;
            break;
        default:
            cout << "Error: Invalid operation." << endl;
            break;
    }

    return 0;
}
