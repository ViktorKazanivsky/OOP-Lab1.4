#include "Polynomial.h"
#include <cmath>
#include <sstream>
#include <string>

#include "Polynomial.h"

void Menu(Polynomial&);

int main() {
    Polynomial poly;
    Menu(poly);

    return 0;
}

void Menu(Polynomial& poly) {
    int choice;
    double x;
    //Меню 
    //1 Ініціалізація многочлена
    //2 Введення многочлена
    //3 Виведення многочлена 
    //4 Перетворення до літерного рядку
    //5 Обчислення значення многочлена для заданого аргументу 
    //6 Додавання многочленів 
    //7 Віднімання многочленів
    //8 Множення многочленів 
    //0 Вихід
    do {
        std::cout << "Menu options:" << std::endl;
        std::cout << "PRESS" << std::endl;
        std::cout << "1 to initialize the polynomial" << std::endl;
        std::cout << "2 to input the polynomial" << std::endl;
        std::cout << "3 to display the polynomial" << std::endl;
        std::cout << "4 to convert to string" << std::endl;
        std::cout << "5 to evaluate the polynomial for a given argument" << std::endl;
        std::cout << "6 to add polynomials" << std::endl;
        std::cout << "7 to subtract polynomials" << std::endl;
        std::cout << "8 to multiply polynomials" << std::endl;
        std::cout << "0 to exit" << std::endl;

        std::cout << "Press the button";
        std::cin >> choice;

        switch (choice) {
        case 1:
        {
            int n;
            std::cout << "Enter the degree of the polynomial: ";
            std::cin >> n;
            double* coeffs = new double[n + 1];
            std::cout << "Enter the coefficients of the polynomial (from a0 to an): ";
            for (int i = 0; i <= n; ++i) {
                std::cin >> coeffs[i];
            }
            poly.Init(n, coeffs);
            delete[] coeffs;
            break;
        }
        case 2:
            poly.Read();
            break;
        case 3:
            poly.Display();
            break;
        case 4:
            std::cout << poly.toString() << std::endl;
            break;
        case 5:
            std::cout << "Enter the argument x: ";
            std::cin >> x;
            std::cout << "The value of the polynomial for x = " << x << ": " << poly.Evaluate(x) << std::endl;
            break;
        case 6:
        {
            Polynomial other;
            std::cout << "Enter another polynomial for addition:" << std::endl;
            other.Read();
            Polynomial sum = poly.Add(other);
            std::cout << "Result of addition: ";
            sum.Display();
            break;
        }
        case 7:
        {
            Polynomial other;
            std::cout << "Enter another polynomial for subtraction:" << std::endl;
            other.Read();
            Polynomial difference = poly.Subtract(other);
            std::cout << "Result of subtraction: ";
            difference.Display();
            break;
        }
        case 8:
        {
            Polynomial other;
            std::cout << "Enter another polynomial for multiplication:" << std::endl;
            other.Read();
            Polynomial product = poly.Multiply(other);
            std::cout << "Result of multiplication: ";
            product.Display();
            break;
        }
        case 0:
            std::cout << "Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 0);
}