#include <iostream>
#include <cmath>
#include <string>

void addition(double a, double b, double &result);
void subtraction(double a, double b, double &result);
void multiplication(double a, double b, double &result);
void division(double a, double b, double &result);
void squareRoot(double a, double &result);
void getSquare(double a, double &result);
int main(){
    bool replay = true;
    while(replay){
    std::string input;
    double num1, num2;
    char operation;
    double result = 0;
    bool running = true;
    std::cout << "Welcome to the Calculator Program!\n";
    std::cout << "What operation would you like to perform? (+, -, *, /, 'q' for squareroot, 's' for square): ";
    while(running){
    std::cin >> operation;
    if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
        std::cout << "Enter number 1: ";
        while(true){
        std::cin >> input;
        try{
            num1 = std::stod(input);
            break;
        }
        catch (const std::invalid_argument&){
            std::cout << "Invalid input for number 1. Please enter a valid number: ";
        }
        }
        std::cout << "Enter number 2: ";
        while(true){
        std::cin >> input;
        try{
            num2 = std::stod(input);
            break;
        }
        catch (const std::invalid_argument&){
            std::cout << "Invalid input for number 2. Please enter a valid number: ";
            continue;
        }
        }
        switch (operation) {
            case '+':
                addition(num1, num2, result);
                break;
            case '-':
                subtraction(num1, num2, result);
                break;
            case '*':
                multiplication(num1, num2, result);
                break;
            case '/':
                division(num1, num2, result);
                break;
        }
        running = false;
    }
    else if (operation == 'q') {
        std::cout << "Enter a number to find its square root: ";
        while(true){
        std::cin >> input;
        try{
            num1 = std::stod(input);
            break;
        } catch (const std::invalid_argument&){
            std::cout << "Invalid input for number 1. Please enter a valid number: ";
        }
        }        
        squareRoot(num1, result);
        running = false;
    }
    else if (operation == 's') {
        std::cout << "Enter a number to find its square: ";
        while(true){
        std::cin >> input;
        try{
            num1 = std::stod(input);
            break;
        } catch (const std::invalid_argument&){
            std::cout << "Invalid input for number 1. Please enter a valid number: ";
        }
        }
        getSquare(num1, result);
        running = false;
    }
    else {
        std::cout << "Invalid operation selected. Please enter an operation: ";
    }
    }
    std::cout << "Do you want to perform another calculation? (y/n): ";
    char again;
    std::cin >> again;
    if (again == 'y' || again == 'Y') {
        replay = true;
    } 
    else if(again == 'n' || again == 'N'){
        replay = false;
        std::cout << "Thank you for using the Calculator Program. Goodbye!\n";
    }
    else {
        std::cout << "Invalid input. Exiting the program.\n";
        replay = false;
    }
    }
    return 0;
}
void addition(double a, double b, double &result){
    result = a + b;
    std::cout << "Result: " << result << '\n';
}
void subtraction(double a, double b, double &result){
    result = a - b;
    std::cout << "Result: " << result << '\n';
}
void multiplication(double a, double b, double &result){
    result = a * b;
    std::cout << "Result: " << result << '\n';
}
void division(double a, double b, double &result){
    if (b != 0) {
        result = a / b;
        std::cout << "Result: " << result << '\n';
    } else {
        std::cout << "Result : Undefined (division by zero)\n";
    }
}
void squareRoot(double a, double &result){
    if (a >= 0) {
        result = std::sqrt(a);
        std::cout << "Result: " << result << '\n';
    } else {
        std::cout << "Error: Cannot compute square root of a negative number.\n";
    }
}
void getSquare(double a, double &result){
    result = a * a;
    std::cout << "Result: " << result << '\n';
}