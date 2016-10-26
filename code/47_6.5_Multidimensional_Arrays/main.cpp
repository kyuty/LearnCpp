#include <iostream>

int main()
{
    // Initializing two-dimensional arrays
    {
        int array0[3][5] =
        {
            { 1, 2, 3, 4, 5 }, // row 0
            { 6, 7, 8, 9, 10 }, // row 1
            { 11, 12, 13, 14, 15 } // row 2
        };

        int array1[3][5] =
        {
            { 1, 2  }, // row 0 = 1, 2, 0, 0, 0
            { 6, 7, 8 }, // row 1 = 6, 7, 8, 0, 0
            { 11, 12, 13, 14 } // row 2 = 11, 12, 13, 14, 0
        };

        int array2[][5] =
        {
            { 1, 2, 3, 4, 5 },
            { 6, 7, 8, 9, 10 },
            { 11, 12, 13, 14, 15 }
        };

        // the inner parenthesis are ignored,
        // the compiler can not tell whether you intend to
        // declare a 1¡Á8, 2¡Á4, 4¡Á2, or 8¡Á1 array in this case.
        //int array3[][] =
        //{
        //    { 1, 2, 3, 4 },
        //    { 5, 6, 7, 8 }
        //};

        int array4[3][5] = { 0 };
    }

    // A two-dimensional array example
    {
        // Declare a 10x10 array
        const int numRows = 10;
        const int numCols = 10;
        int product[numRows][numCols] = { 0 };

        // Calculate a multiplication table
        for (int row = 0; row < numRows; ++row)
            for (int col = 0; col < numCols; ++col)
                product[row][col] = row * col;

        // Print the table
        for (int row = 0; row < numRows; ++row){
            for (int col = 0; col < numCols; ++col){
                std::cout << product[row][col] << "\t";
            }
            std::cout << '\n';
        }
    }
    return 0;
}

/*
0   0   0   0   0   0   0   0   0   0   
0   1   2   3   4   5   6   7   8   9   
0   2   4   6   8   10  12  14  16  18  
0   3   6   9   12  15  18  21  24  27  
0   4   8   12  16  20  24  28  32  36  
0   5   10  15  20  25  30  35  40  45  
0   6   12  18  24  30  36  42  48  54  
0   7   14  21  28  35  42  49  56  63  
0   8   16  24  32  40  48  56  64  72  
0   9   18  27  36  45  54  63  72  81  
*/