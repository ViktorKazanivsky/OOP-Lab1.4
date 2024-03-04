#pragma once
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>


class Polynomial {
private:
    int degree;
    double* coefficients;

public:
   
    Polynomial();
    Polynomial(int n, const double* coeffs);
    ~Polynomial();

    void Init(int n, const double* coeffs);
    void Read();
    void Display();

    std::string toString();
    double Evaluate(double x);
    Polynomial Add(const Polynomial& other);
    Polynomial Subtract(const Polynomial& other);
    Polynomial Multiply(const Polynomial& other);

    int getDegree() const;
    void setDegree(int n);
    double* getCoefficients() const;
    void setCoefficients(const double* coeffs);
};