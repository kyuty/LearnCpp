#include <iostream>

struct Person
{
    int age;
    double weight;
};

int main()
{
    {
        Person person;

        // Member selection using actual struct variable
        person.age = 5;
    }
    {
        // Member selection using reference to struct
        Person &ref = person;
        ref.age = 5;
    }
    {
        // Member selection using pointer to struct
        Person *ptr = &person;
        (*ptr).age= 5;
        ptr->age = 5;
    }
    return 0;
}
