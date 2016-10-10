#include <iostream>

void sortArray(std::string *array, int length)
{
	// Step through each element of the array
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
		// smallestIndex is the index of the smallest element we've encountered so far.
		int smallestIndex = startIndex;

		// Look for smallest element remaining in the array (starting at startIndex+1)
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// If the current element is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
				// This is the new smallest number for this iteration
				smallestIndex = currentIndex;
		}

		// Swap our start element with our smallest element
		std::swap(array[startIndex], array[smallestIndex]);
	}
}

int main()
{
    {
        std::cout << "Enter a positive integer: ";
        int size;
        std::cin >> size;
        std::cin.ignore(32767,'\n');

        int *array = new int[size]; // use array new.  Note that size does not need to be constant!

        std::cout << "I just allocated an array of size " << size << '\n';

        array[0] = 5; // set element 0 to value 5

        delete[] array; // use array delete to deallocate array
        array = 0; // use nullptr instead of 0 in C++11
    }

    // Initializing dynamically allocated arrays
    {
        // If you want to initialize a dynamically allocated array to 0,
        // the syntax is quite simple:
        int size = 7;
        int *array = new int[size]();
    }
    {
        int *array = new int[5];
        array[0] = 9;
        array[1] = 7;
        array[2] = 5;
        array[3] = 3;
        array[4] = 1;
    }
    {
        int fixedArray[5] = { 9, 7, 5, 3, 1 }; // initialize a fixed array in C++03
        int *array = new int[5] { 9, 7, 5, 3, 1 }; // initialize a dynamic array in C++11
        int fixedArray_1[5] { 9, 7, 5, 3, 1 }; // initialize a fixed array in C++11
    }

    /*
    1) Write a program that:
        * Asks the user how many names they wish to enter.
        * Asks the user to enter each name.
        * Calls a function to sort the names (modify the selection sort code from lesson 6.4 -- Sorting an array using selection sort)
        * Prints the sorted list of names.

        Hint: Use a dynamic array of std::string to hold the names.
        Hint: std::string supports comparing strings via the comparison operators < and >

        Your output should match this:

        How many names would you like to enter? 5
        Enter name #1: Jason
        Enter name #2: Mark
        Enter name #3: Alex
        Enter name #4: Chris
        Enter name #5: John

        Here is your sorted list:
        Name #1: Alex
        Name #2: Chris
        Name #3: Jason
        Name #4: John
        Name #5: Mark
    */
    {
        std::cout << "How many names would you like to enter? ";
        int length;
        std::cin >> length;
        std::cin.ignore(32767,'\n');

        // Allocate an array to hold the names
        std::string *names = new std::string[length];

        // Ask user to enter all the names
        for (auto i = 0; i < length; ++i)
        {
            std::cout << "Enter name #" << i + 1 << ": ";
            //std::cin >> names[i];
            //std::cin.ignore(32767,'\n');
            std::getline(std::cin, names[i]);
        }

        // Sort the array
        sortArray(names, length);

        std::cout << "\nHere is your sorted list:\n";
        // Print the sorted array
        for (auto i = 0; i < length; ++i)
            std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';

        delete[] names; // don't forget to use array delete
        names = nullptr; // use 0 if not C++11
    }
    return 0;
}
