#include <iostream>
// === 1 === first
int main_1()
{ // start main block, i and d created here

    int i(5); // i initialized here
    double d(4.0); // d initialized here

    return 0;

} // i and d destroyed here
// === 1 === end

// === 2 === first
int main_2() // outer block, n created here
{
    int n(5); // n initialized here

    { // begin nested block, d created here
        double d(4.0); // d initialized here
    } // d destroyed here

    // d can not be used here because it was already destroyed!

    return 0;
} // n destroyed here
// === 2 === end

// === 3 === first
void someFunction()
{
    int value(4); // value defined here

    // value can be seen and used here

} // value destroyed here

int main_3()
{
    // value can not be seen or used inside this function.

    someFunction();

    // value still can not be seen or used inside this function.

    return 0;
}
// === 3 === end

// === 4 === first
// add's x can only be seen/used within function add()
int add(int x, int y) // add's x is created here
{
    return x + y;
} // add's x is destroyed here

// main's x can only be seen/used within function main()
int main_4() // main's x is created here
{
    int x = 5;
    int y = 6;
    std::cout << add(x, y) << std::endl; // the value from main's x is copied into add's x

    /*
        11
    */

    return 0;
} // main's x is destroyed here
// === 4 === end

// === 5 === first
int main_5()
{ // start outer block

    int x(5);

    { // start nested block
        int y(7);
        // we can see both x and y from here
        std::cout << x << " + " << y << " = " << x + y;
    } // y destroyed here

    // y can not be used here because it was already destroyed!

    /*
        5 + 7 = 12
    */

    return 0;
} // x is destroyed here
// === 5 === end

// === 6 === first
int main_6()
{ // outer block
    int apples(5);

    if (apples >= 5)
    { // nested block
        int apples(10); // hides previous variable named apples

        // apples now refers to the nested block apples
        // the outer block apples is hidden

        std::cout << apples << "\n";    // print 10

    } // nested block apples destroyed

    // apples now refers to the outer block apples
    std::cout << apples;    // print 5

    return 0;
} // outer block apples destroyed
// === 6 === end

// === 7 === first
int main_7()
{
    // do not define y here
    {
        // y is only used inside this block, so define it here
        int y(5);
        std::cout << y;     // print 5
    }
    // otherwise y could still be used here

    return 0;
}
// === 7 === end

// === 8 === first
int max(int x, int y) // x and y defined here
{
    // assign the greater of x or y to max
    int max = (x > y) ? x : y; // max defined here
    return max;
} // x, y, and max all die here
// === 8 === end

// === 9 === first
int main_9()
{
    std::cout << "Enter an integer: ";
    int smaller;
    std::cin >> smaller;

    std::cout << "Enter a larger integer: ";
    int larger;
    std::cin >> larger;

    // if user did it wrong
    if (smaller > larger)
    {
        // swap values of smaller and larger
        std::cout << "Swapping the values\n";

        int temp = larger;
        larger = smaller;
        smaller = temp;
    } // temp dies here

    std::cout << "The smaller value is: " << smaller << "\n";
    std::cout << "The larger value is: " << larger << "\n";

    /*
        Enter an integer: 13
        Enter a larger integer: 12
        Swapping the values
        The smaller value is: 12
        The larger value is: 13
    */

    return 0;
} // smaller and larger die here
// === 9 === end

int main() {
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    main_9();
}