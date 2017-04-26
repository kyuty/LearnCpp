#include <iostream>

int main()
{
    // C-style string symbolic constants
    {
        char myName[] = "Alex";
        std::cout << myName << "\n";    // print Alex
    }
    {
        const char *myName = "Alex";
        std::cout << myName << "\n";    // print Alex
    }

    // std::cout and char pointers
    {
        int nArray[5] = { 9, 7, 5, 3, 1 };
        char cArray[] = "Hello!";
        const char *name = "Alex";

        std::cout << nArray << '\n'; // nArray will decay to type int*      // print 0x7fff4dbac760
        std::cout << cArray << '\n'; // cArray will decay to type char*     // print Hello!
        std::cout << name << '\n'; // name is already type char*            // Alex

        /*
            On the author’s machine, this printed:

            003AF738
            Hello!
            Alex
            Why did the int array print an address, but the character arrays printed strings?

            The answer is that std::cout makes some assumptions about your intent. 
            If you pass it a non-char pointer, it will simply print the contents of that pointer (the address that the pointer is holding). 
            However, if you pass it an object of type char* or const char*, it will assume you’re intending to print a string. 
            Consequently, instead of printing the pointer’s value, it will print the string being pointed to instead!
        */
    }

    {
        /*
            While this is great 99% of the time, it can lead to unexpected results. Consider the following case:
        */
        char c = 'Q';
        std::cout << &c << "\n";        // print Q // print Q╠╠╠╠╜╡4

        char* d = "Q";
        std::cout << d << "\n";         // print Q
                                        // waring : conversion from string literal to 'char *' is deprecated.

        const char *e = "Q";
        std::cout << e << "\n";         // print Q

        /*
            In this case, the programmer is intending to print the address of variable c. 
            However, &c has type char*, so std::cout tries to print this as a string! On the author’s machine, this printed:
                Q╠╠╠╠╜╡4;¿■A
            
            Why did it do this? Well, it assumed &c (which has type char*) was a string. 
            So it printed the ‘Q’, and then kept going. 
            Next in memory was a bunch of garbage. 
            Eventually, it ran into some memory holding a 0 value, which it interpreted as a null terminator, so it stopped. 
            What you see may be different depending on what’s in memory after variable c.
            
            This case is somewhat unlikely to occur in real-life (as you’re not likely to actually want to print memory addresses), 
            but it is illustrative of how things work under the hood, and how programs can inadvertently go off the rails.
        */
    }
    return 0;
}
