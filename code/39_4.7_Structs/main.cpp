#include <iostream>

struct Employee
{
    short id;
    int age;
    double wage;
};

void printInformation(Employee employee)
{
    std::cout << "ID:   " << employee.id << "\n";
    std::cout << "Age:  " << employee.age << "\n";
    std::cout << "Wage: " << employee.wage << "\n";
}

struct Point3d
{
    double x;
    double y;
    double z;
};

Point3d getZeroPoint()
{
    Point3d temp = { 0.0, 0.0, 0.0 };
    return temp;
}

int main()
{
    // Accessing struct members
    {
        Employee joe; // create an Employee struct for Joe
        joe.id = 14; // assign a value to member id within struct joe
        joe.age = 32; // assign a value to member age within struct joe
        joe.wage = 24.15; // assign a value to member wage within struct joe

        Employee frank; // create an Employee struct for Frank
        frank.id = 15; // assign a value to member id within struct frank
        frank.age = 28; // assign a value to member age within struct frank
        frank.wage = 18.27; // assign a value to member wage within struct frank

        int totalAge = joe.age + frank.age;

        if (joe.wage > frank.wage)
            std::cout << "Joe makes more than Frank\n";
        else if (joe.wage < frank.wage)
            std::cout << "Joe makes less than Frank\n";
        else
            std::cout << "Joe and Frank make the same amount\n";

        // Frank got a promotion
        frank.wage += 2.50;

        // Today is Joe's birthday
        ++joe.age; // use pre-increment to increment Joe's age by 1
    }

    // Initializing structs
    {
        Employee joe = { 1, 32, 60000.0 }; // joe.id = 1, joe.age = 32, joe.wage = 60000.0
        Employee frank = { 2, 28 }; // frank.id = 2, frank.age = 28, frank.wage = 0.0 (default initialization)

        // In C++11
        //Employee joe { 1, 32, 60000.0 }; // joe.id = 1, joe.age = 32, joe.wage = 60000.0
        //Employee frank { 2, 28 }; // frank.id = 2, frank.age = 28, frank.wage = 0.0 (default initialization)
    }

    // C++11/14: Non-static member initialization
    {
        struct Triangle
        {
            double length = 1.0;
            double width = 1.0;
        };
        Triangle x; // length = 1.0, width = 1.0
        x.length = 2.0; // you can assign other values like normal
    }

    // Structs and functions
    {
        Employee joe = { 14, 32, 24.15 };
        Employee frank = { 15, 28, 18.27 };

        // Print Joe's information
        printInformation(joe);

        std::cout << "\n";

        // Print Frank's information
        printInformation(frank);
    }

    {
        Point3d zero = getZeroPoint();

        if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
            std::cout << "The point is zero\n";     // print
        else
            std::cout << "The point is not zero\n";
    }

    // Nested structs
    {
        struct Employee
        {
            short id;
            int age;
            float wage;
        };

        struct Company
        {
            Employee CEO; // Employee is a struct within the Company struct
            int numberOfEmployees;
        };

        Company myCompany = {{ 1, 42, 60000.0f }, 5 };
    }

    // Struct size and data structure alignment
    {
        std::cout << sizeof(short) << " " << sizeof(int) << " " << sizeof(double) << std::endl;     // 2 + 4 + 8 = 14
        std::cout << "The size of Employee is " << sizeof(Employee) << "\n";    // print 16

        /*
            It turns out, we can only say that the size of a struct will be at least as large as the size of all the variables it contains. 
            But it could be larger! 
            For performance reasons, the compiler will sometimes add gaps into structures (this is called padding).
        */
    }

    return 0;
}
/*
struct Fraction
{
    int numerator;
    int denominator;
};

void multiply(Fraction f1, Fraction f2)
{
    using namespace std;

    // Don't forget the static cast, otherwise the compiler will do integer division!
    cout << static_cast<float>(f1.numerator * f2.numerator) /
        (f1.denominator* f2.denominator);
}
*/
