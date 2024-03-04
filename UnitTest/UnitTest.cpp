#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP Lab1.4/Polynomial.h"
#include "../OOP Lab1.4/Polynomial.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestEvaluate)
        {
            Polynomial poly(2, new double[3] {1.0, 2.0, 3.0});

            double result = poly.Evaluate(2.0);

            Assert::AreEqual(result, 17.0, 0.0001);  
        }
    };
}