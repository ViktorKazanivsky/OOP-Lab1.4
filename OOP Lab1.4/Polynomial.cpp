#include "Polynomial.h"
#include <cmath>
#include <sstream>
#include <string>

Polynomial::Polynomial() : degree(0), coefficients(nullptr) {}

Polynomial::Polynomial(int n, const double* coeffs) {
    Init(n, coeffs);
}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

void Polynomial::Init(int n, const double* coeffs) {
    degree = n;
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; ++i) {
        coefficients[i] = coeffs[i];
    }
}

void Polynomial::Read() {
    std::cout << "Enter the degree of the polynomial: ";
    std::cin >> degree;

    delete[] coefficients;
    coefficients = new double[degree + 1];

    std::cout << "Enter the coefficients of the polynomial (from a0 to an): ";
    for (int i = 0; i <= degree; ++i) {
        std::cin >> coefficients[i];
    }

    Init(degree, coefficients);  
}

void Polynomial::Display() {
    std::cout << "P(x) = ";
    for (int i = 0; i < degree; ++i) {
        std::cout << coefficients[i] << "x^" << i << " + ";
    }
    std::cout << coefficients[degree] << "x^" << degree << std::endl;
}

std::string Polynomial::toString() {
    std::string result = "P(x) = ";
    for (int i = 0; i < degree; ++i) {
        result += std::to_string(coefficients[i]) + "x^" + std::to_string(i) + " + ";
    }
    result += std::to_string(coefficients[degree]) + "x^" + std::to_string(degree);
    return result;
}

double Polynomial::Evaluate(double x) {
    double result = 0.0;
    for (int i = 0; i <= degree; ++i) {
        result += coefficients[i] * std::pow(x, i);
    }
    return result;
}

Polynomial Polynomial::Add(const Polynomial& other) {
    int newDegree = std::max(degree, other.getDegree());
    double* newCoefficients = new double[newDegree + 1] {0.0};

    for (int i = 0; i <= degree; ++i) {
        newCoefficients[i] += coefficients[i];
    }

    for (int i = 0; i <= other.getDegree(); ++i) {
        newCoefficients[i] += other.getCoefficients()[i];
    }

    Polynomial result(newDegree, newCoefficients);
    return result;
}

Polynomial Polynomial::Subtract(const Polynomial& other) {
    int newDegree = std::max(degree, other.getDegree());
    double* newCoefficients = new double[newDegree + 1] {0.0};

    for (int i = 0; i <= degree; ++i) {
        newCoefficients[i] += coefficients[i];
    }

    for (int i = 0; i <= other.getDegree(); ++i) {
        newCoefficients[i] -= other.getCoefficients()[i];
    }

    Polynomial result(newDegree, newCoefficients);
    return result;
}

Polynomial Polynomial::Multiply(const Polynomial& other) {
    int newDegree = degree + other.getDegree();
    double* newCoefficients = new double[newDegree + 1] {0.0};

    for (int i = 0; i <= degree; ++i) {
        for (int j = 0; j <= other.getDegree(); ++j) {
            newCoefficients[i + j] += coefficients[i] * other.getCoefficients()[j];
        }
    }

    Polynomial result(newDegree, newCoefficients);
    return result;
}

int Polynomial::getDegree() const {
    return degree;
}

void Polynomial::setDegree(int n) {
    degree = n;
}

double* Polynomial::getCoefficients() const {
    return coefficients;
}

void Polynomial::setCoefficients(const double* coeffs) {
    delete[] coefficients;
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; ++i) {
        coefficients[i] = coeffs[i];
    }
}