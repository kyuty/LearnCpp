#include <iostream>
#include <cstring> // use strcpy

int main()
{
    // C-style strings
    {
        char mystring[] = "string";// 6 + 1 = 7
        std::cout << mystring << " has " << sizeof(mystring) << " characters.\n";// print "string has 7 characters."
        for (int index = 0; index < sizeof(mystring); ++index){
            std::cout << static_cast<int>(mystring[index]) << " ";// print "115 116 114 105 110 103 0"
        }
        std::cout << std::endl;
    }
    {
        char mystring[] = "string";
        mystring[1] = 'p';
        std::cout << mystring << "\n"; // print "spring"
    }
    {
        char name[20] = "Alex"; // only use 5 characters (4 letters + null terminator)
        std::cout << "My name is: " << name << '\n'; // print "My name is: Alex"
    }

    // C-style strings and std::cin
    {
        char name[255]; // declare array large enough to hold 255 characters
        std::cout << "Enter your name: ";
        std::cin >> name;
        std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer
        std::cout << "You entered: " << name << '\n';
    }
    {
        // The recommended way of reading strings using cin is as follows:
        char name[255]; // declare array large enough to hold 255 characters
        std::cout << "Enter your name: ";
        std::cin.getline(name, 255);
        std::cout << "You entered: " << name << '\n';
        //In this way, we guarantee that we will not overflow the array!
    }

    // Manipulating C-style strings
    {
        char source[] = "Copy this!";
        char dest[50];
        strcpy(dest, source);
        std::cout << dest << "\n"; // prints "Copy this!"
    }
    {
        char source[] = "Copy this!";
        char dest[50];
        strncpy(dest, source, 49); // copy at most 49 characters (indices 0-48)
        dest[49] = 0; // ensures the last character is a null terminator
        std::cout << dest << "\n"; // prints "Copy this!"
    }
    {
        char name[20] = "Alex"; // only use 5 characters (4 letters + null terminator)
        std::cout << "My name is: " << name << '\n';
        std::cout << name << " has " << strlen(name) << " letters.\n";                  //长度是4
        std::cout << name << " has " << sizeof(name) << " characters in the array.\n";  //大小是20
    }
    {
        // Ask the user to enter a string
        char buffer[255];
        std::cout << "Enter a string: ";
        std::cin.getline(buffer, 255);

        int spacesFound = 0;
        // Loop through all of the characters the user entered
        for (int index = 0; index < strlen(buffer); ++index)
        {
            // If the current character is a space, count it
            if (buffer[index] == ' ')
                spacesFound++;
        }

        std::cout << "You typed " << strlen(buffer) << " numbers.\n";
        std::cout << "You typed " << spacesFound << " spaces!\n";
    }
    return 0;
}
