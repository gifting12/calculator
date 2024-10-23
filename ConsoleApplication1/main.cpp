#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw invalid_argument("Помилка: ділення на нуль!");
    }
    return a / b;
}


void runTests() {
    setlocale(LC_ALL, "Ukrainian");
    if (add(3, 2) == 5) {
        cout << "Тест складання пройдено." << endl;
    }
    else {
        cout << "Тест складання не пройдено." << endl;
    }

    
    if (subtract(5, 3) == 2) {
        cout << "Тест віднімання пройдено." << endl;
    }
    else {
        cout << "Тест віднімання не пройдено." << endl;
    }

    
    if (multiply(4, 2) == 8) {
        cout << "Тест множення пройдено." << endl;
    }
    else {
        cout << "Тест множення не пройдено." << endl;
    }

    try {
        if (divide(6, 2) == 3) {
            cout << "Тест ділення пройдено." << endl;
        }
        else {
            cout << "Тест ділення не пройдено." << endl;
        }
    }
    catch (const exception& e) {
        cout << "Тест ділення не пройдено: " << e.what() << endl;
    }

    
}

int main() {
    runTests();
    setlocale(LC_ALL, "Ukrainian");

    double num1, num2;
    char operation;

    cout << "Введіть перше число: ";
    cin >> num1;

    cout << "Введіть операцію (+, -, *, /): ";
    cin >> operation;

    cout << "Введіть друге число: ";
    cin >> num2;

    try {
        double result = 0;
        switch (operation) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            throw invalid_argument("Помилка: невірна операція!");
        }
        cout << "Результат: " << result << endl;
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}