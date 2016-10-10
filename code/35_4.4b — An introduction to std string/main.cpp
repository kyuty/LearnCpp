#include <iostream>
#include <string>

int main()
{
    // String input and output
    {
        std::string myName("Alex");
        std::cout << "My name is: " << myName << "\n";
    }

    {

        std::cout << "Enter your full name: ";
        std::string name;
        std::cin >> name;
        std::cin.ignore(32767, '\n');

        std::cout << "Enter your age: ";
        std::string age;
        std::cin >> age;
        std::cin.ignore(32767, '\n');

        std::cout << "Your name is " << name << " and your age is " << age << "\n";
        //Here¡¯s the results from a sample run of this program:
        //    Enter your full name: John Doe
        //    Enter your age: 23
        //    Your name is John and your age is Doe
    }

    // Use std::getline() to input text
    {
        std::cout << "Enter your full name: ";
        std::string name;
        std::getline(std::cin, name); // read a full line of text into name

        std::cout << "Enter your age: ";
        std::string age;
        std::getline(std::cin, age); // read a full line of text into age

        std::cout << "Your name is " << name << " and your age is " << age << "\n";
    }

    //Mixing std::cin and std::getline()
    {
        std::cout << "Pick 1 or 2: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(32767, '\n');

        std::cout << "Now enter your name: ";
        std::string name;
        std::getline(std::cin, name);

        std::cout << "Hello, " << name << ", you picked " << choice << '\n';
    }

    // Appending strings
    {
        std::string a("45");
        std::string b("11");

        std::cout << a + b << "\n"; // a and b will be appended, not added
        a += " volts";
        std::cout << a << "\n";
    }

    // String length
    {
        std::string myName("Alex");
        std::cout << myName << " has " << myName.length() << " characters\n";
    }

    // Write a program that asks the user to enter their full name and their age.
    // As output, tell the user how many years they¡¯ve lived for each letter in their name
    // (for simplicity, count spaces as a letter).
    {
        std::cout << "Enter your full name: ";
        std::string name;
        std::getline(std::cin, name); // read a full line of text into name

        std::cout << "Enter your age: ";
        int age; // age needs to be an integer, not a string, so we can do math with it
        std::cin >> age;
        std::cin.ignore(32767,'\n');

        int letters = name.length(); // get number of letters in name (including spaces)
        double agePerLetter = static_cast<double>(age) / letters; // static cast age to double to avoid integer division
        std::cout << "You've lived " << agePerLetter << " years for each letter in your name.\n";
    }

    return 0;
}
