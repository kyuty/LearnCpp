#include <iostream>
#include <string>

enum ItemType
{
    ITEMTYPE_SWORD,
    ITEMTYPE_TORCH,
    ITEMTYPE_POTION
};

std::string getItemName(ItemType itemType)
{
    if (itemType == ITEMTYPE_SWORD)
        return std::string("Sword");
    if (itemType == ITEMTYPE_TORCH)
        return std::string("Torch");
    if (itemType == ITEMTYPE_POTION)
        return std::string("Potion");
}

// print enum === fisrt
enum Color
{
    COLOR_BLACK, // assigned 0
    COLOR_RED, // assigned 1
    COLOR_BLUE, // assigned 2
    COLOR_GREEN, // assigned 3
    COLOR_WHITE, // assigned 4
    COLOR_CYAN, // assigned 5
    COLOR_YELLOW, // assigned 6
    COLOR_MAGENTA // assigned 7
};

void printColor(Color color)
{
    if (color == COLOR_BLACK)
        std::cout << "Black";
    else if (color == COLOR_RED)
        std::cout << "Red";
    else if (color == COLOR_BLUE)
        std::cout << "Blue";
    else if (color == COLOR_GREEN)
        std::cout << "Green";
    else if (color == COLOR_WHITE)
        std::cout << "White";
    else if (color == COLOR_CYAN)
        std::cout << "Cyan";
    else if (color == COLOR_YELLOW)
        std::cout << "Yellow";
    else if (color == COLOR_MAGENTA)
        std::cout << "Magenta";
    else
        std::cout << "Who knows!";
}
// print enum === end

int main()
{
    {
        // Declare a new enumeration named Color
        enum Color
        {
            // Here are the enumerators
            // These define all the possible values this type can hold
            // Each enumerator is separated by a comma, not a semicolon
            COLOR_BLACK,
            COLOR_RED,
            COLOR_BLUE,
            COLOR_GREEN,
            COLOR_WHITE,
            COLOR_CYAN,
            COLOR_YELLOW,
            COLOR_MAGENTA // for maximum compatibility, the last enumerator should not have a comma
        }; // however the enum itself must end with a semicolon
        // Define a few variables of enumerated type Color
        Color paint = COLOR_WHITE;
        Color house(COLOR_BLUE);
    }

    {
        enum Color
        {
            COLOR_BLACK, // assigned 0
            COLOR_RED, // assigned 1
            COLOR_BLUE, // assigned 2
            COLOR_GREEN, // assigned 3
            COLOR_WHITE, // assigned 4
            COLOR_CYAN, // assigned 5
            COLOR_YELLOW, // assigned 6
            COLOR_MAGENTA // assigned 7
        };
        Color paint(COLOR_WHITE);
        std::cout << paint << "\n";
    }

    {
        // define a new enum named Animal
        enum Animal
        {
            ANIMAL_CAT = -3,
            ANIMAL_DOG, // assigned -2
            ANIMAL_PIG, // assigned -1
            ANIMAL_HORSE = 5,
            ANIMAL_GIRAFFE = 5, // shares same value as ANIMAL_HORSE
            ANIMAL_CHICKEN // assigned 6
        };
        int mypet = ANIMAL_PIG;
        std::cout << ANIMAL_HORSE << "\n"; // evaluates to integer before being passed to std::cout

        // Best practice: Don¡¯t assign specific values to your enumerators.
        // Rule: Don¡¯t assign the same value to two enumerators in the same enumeration
        // unless there¡¯s a very good reason.
    }
    {
        //Animal animal = 5; // will cause compiler error
        //Color color = static_cast<Color>(5); // ugly
    }
    {
        enum Color
        {
            COLOR_BLACK, // assigned 0
            COLOR_RED, // assigned 1
            COLOR_BLUE, // assigned 2
            COLOR_GREEN, // assigned 3
            COLOR_WHITE, // assigned 4
            COLOR_CYAN, // assigned 5
            COLOR_YELLOW, // assigned 6
            COLOR_MAGENTA // assigned 7
        };
        Color color;
        //std::cin >> color; // will cause compiler error

        int inputColor;
        std::cin >> inputColor;
        std::cin.ignore(32767,'\n');
        color = static_cast<Color>(inputColor);
    }

    {
        // ItemType is the enumerated type we've declared above.
        // itemType (lower case i) is the name of the variable we're defining (of type ItemType).
        // ITEMTYPE_TORCH is the enumerated value we're initializing variable itemType with.
        ItemType itemType(ITEMTYPE_TORCH);

        std::cout << "You are carrying a " << getItemName(itemType) << "\n";
    }

    return 0;
}

/*
enum Color
{
RED,
BLUE, // BLUE is put into the global namespace
GREEN
};

enum Feeling
{
HAPPY,
TIRED,
BLUE // error, BLUE was already used in enum Color in the global namespace
};
*/
