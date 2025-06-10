#include <iostream>

#include <string>

#include <stdexcept> // for runtime_error

#include <cmath>



using namespace std;



class Operation {

protected:

    double Num1;

    double Num2;



public:

    Operation(double n1, double n2) : Num1(n1), Num2(n2) {}

    virtual ~Operation() = default;



    virtual double calculate() const = 0;

    virtual void printResult() const = 0;



    void setNum1(double n1) {

        Num1 = n1;

    }



    double getNum1() const {

        return Num1;

    }



    void setNum2(double n2) {

        Num2 = n2;

    }



    double getNum2() const {

        return Num2;

    }



    double add() const {

        return Num1 + Num2;

    }



    double sub() const {

        return Num1 - Num2;

    }



    double multiply() const {

        return Num1 * Num2;

    }



    double divide() const {

        if (Num2 == 0) {

            throw runtime_error("Error: Division by zero");

        }

        return Num1 / Num2;

    }



    double exponentiate() const {

        return pow(Num1, Num2);

    }



    double squareRoot() const {

        if (Num1 < 0) {

            throw runtime_error("Error: Cannot calculate square root of a negative number");

        }

        return sqrt(Num1);

    }



    double absoluteValue() const {

        return fabs(Num1);

    }



    double square() const {

        return Num1 * Num1;

    }



    double cube() const {

        return Num1 * Num1 * Num1;

    }



    double sin() const {

        return std::sin(Num1);

    }



    double cos() const {

        return std::cos(Num1);

    }



    double tan() const {

        return std::tan(Num1);

    }

};



class Addition : public Operation {

public:

    Addition(double n1, double n2) : Operation(n1, n2) {}



    double calculate() const override {

        return add();

    }



    void printResult() const override {

        cout << "Result of addition: " << calculate() << endl;

    }

};



class Subtraction : public Operation {

public:

    Subtraction(double n1, double n2) : Operation(n1, n2) {}



    double calculate() const override {

        return sub();

    }



    void printResult() const override {

        cout << "Result of subtraction: " << calculate() << endl;

    }

};



class Multiplication : public Operation {

public:

    Multiplication(double n1, double n2) : Operation(n1, n2) {}



    double calculate() const override {

        return multiply();

    }



    void printResult() const override {

        cout << "Result of multiplication: " << calculate() << endl;

    }

};



class Division : public Operation {

public:

    Division(double n1, double n2) : Operation(n1, n2) {}



    double calculate() const override {

        if (getNum2() == 0) {

            throw runtime_error("Error: Division by zero");

        }

        return divide();

    }



    void printResult() const override {

        try {

            cout << "Result of division: " << calculate() << endl;

        } catch (const runtime_error& e) {

            cout << e.what() << endl;

        }

    }

};



class Exponentiation : public Operation {

public:

    Exponentiation(double n1, double n2) : Operation(n1, n2) {}



    double calculate() const override {

        return exponentiate();

    }



    void printResult() const override {

        cout << "Result of exponentiation: " << calculate() << endl;

    }

};



class SquareRoot : public Operation {

public:

    SquareRoot(double n1) : Operation(n1, 0) {}



    double calculate() const override {

        return squareRoot();

    }



    void printResult() const override {

        try {

            cout << "Square root of Num1: " << calculate() << endl;

        } catch (const runtime_error& e) {

            cout << e.what() << endl;

        }

    }

};



class AbsoluteValue : public Operation {

public:

    AbsoluteValue(double n1) : Operation(n1, 0) {}



    double calculate() const override {

        return absoluteValue();

    }



    void printResult() const override {

        cout << "Absolute value of Num1: " << calculate() << endl;

    }

};



class Square : public Operation {

public:

    Square(double n1) : Operation(n1, 0) {}



    double calculate() const override {

        return square();

    }



    void printResult() const override {

        cout << "Square of Num1: " << calculate() << endl;

    }

};



class Cube : public Operation {

public:

    Cube(double n1) : Operation(n1, 0) {}



    double calculate() const override {

        return cube();

    }



    void printResult() const override {

        cout << "Cube of Num1: " << calculate() << endl;

    }

};



class Trigonometry : public Operation {

public:

    Trigonometry(double n1, double n2) : Operation(n1, n2) {}

};



class Sin : public Trigonometry {

public:

    Sin(double n1) : Trigonometry(n1, 0) {}



    double calculate() const override {

        return sin();

    }



    void printResult() const override {

        cout << "Result of sin: " << calculate() << endl;

    }

};



class Cos : public Trigonometry {

public:

    Cos(double n1) : Trigonometry(n1, 0) {}



    double calculate() const override {

        return cos();

    }



    void printResult() const override {

        cout << "Result of cos: " << calculate() << endl;

    }

};



class Tan : public Trigonometry {

public:

    Tan(double n1) : Trigonometry(n1, 0) {}



    double calculate() const override {

        return tan();

    }



    void printResult() const override {

        cout << "Result of tan: " << calculate() << endl;

    }

};



int main() {

    double num1, num2;

    char choice;

    do {

        cout << "Choose an operation:" << endl;

        cout << "a. Addition" << endl;

        cout << "b. Subtraction" << endl;

        cout << "c. Multiplication" << endl;

        cout << "d. Division" << endl;

        cout << "e. Exponentiation" << endl;

        cout << "f. Square Root" << endl;

        cout << "g. Absolute Value" << endl;

        cout << "h. Square" << endl;

        cout << "i. Cube" << endl;

        cout << "j. Sin" << endl;

        cout << "k. Cos" << endl;

        cout << "l. Tan" << endl;

        cout << "m. Exit program..." << endl;

        cout << "Enter your choice (1-12): ";


        cin >> choice;

        switch (choice) {

            case 'a': {

                cout << "Enter first number: ";

                cin >> num1;

                cout << "Enter second number: ";

                cin >> num2;

                Addition addition(num1, num2);

                addition.printResult();

                break;

            }

            case 'b': {

                cout << "Enter first number: ";

                cin >> num1;

                cout << "Enter second number: ";

                cin >> num2;

                Subtraction subtraction(num1, num2);

                subtraction.printResult();

                break;

            }

            case 'c': {

                cout << "Enter first number: ";

                cin >> num1;

                cout << "Enter second number: ";

                cin >> num2;

                Multiplication multiplication(num1, num2);

                multiplication.printResult();

                break;

            }

            case 'd': {

                cout << "Enter first number: ";

                cin >> num1;

                cout << "Enter second number: ";

                cin >> num2;

                Division division(num1, num2);

                division.printResult();

                break;

            }

            case 'e': {

                cout << "Enter base number: ";

                cin >> num1;

                cout << "Enter exponent: ";

                cin >> num2;

                Exponentiation exponentiation(num1, num2);

                exponentiation.printResult();

                break;

            }

            case 'f': {

                cout << "Enter a number for square root: ";

                cin >> num1;

                SquareRoot squareRoot(num1);

                squareRoot.printResult();

                break;

            }

            case 'g': {

                cout << "Enter a number for absolute value: ";

                

                cin >> num1;

                AbsoluteValue absoluteValue(num1);

                absoluteValue.printResult();

                break;

            }

            case 'h': {

                cout << "Enter a number for square: ";

                cin >> num1;

                Square square(num1);

                square.printResult();

                break;

            }

            case 'i': {

                cout << "Enter a number for cube: ";

                cin >> num1;

                Cube cube(num1);

                cube.printResult();

                break;

            }

            case 'j': {

                cout << "Enter a number for sin: ";

                cin >> num1;

                Sin sinOp(num1);

                sinOp.printResult();

                break;

            }

            case 'k': {

                cout << "Enter a number for cos: ";

                cin >> num1;

                Cos cosOp(num1);

                cosOp.printResult();

                break;

            }

            case 'l': {

                cout << "Enter a number for tan: ";

                cin >> num1;

                Tan tanOp(num1);

                tanOp.printResult();

                break;

            }

            case 'm' : {

            	  cout << "Program ended." << endl;

				break;

			}

            default:

                cout << "Invalid choice. Please enter a number between 1 and 12." << endl;

                break;

    }

    } while (true);



  



    return 0;

}

