#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// prototype of function

// read data example
/**
 * @brief This function reads the file and stores the data in a vector
 * idea: read the file line by line, then using for loop to read each character
 *      and store it in a vector (row). After we done with each line/row, we push
 *      the row into the board vector.
 * @param fileName - the name of the file
 * @return vector<vector<char>> - the vector containing the data from the file
 */
vector<vector<char>> readData(string fileName);

// using nested for loops and isAlpha()
/**
 * @brief This function replace all the alphabets in the board with '_'
 * idea: using nested for loops to go through the board, and check if the character
 *     is an alphabet, if it is, replace it with '_' by using isAlpha() function
 * Notes: isAlpha() function is from cctype library. It returns true if the character
 *    is an alphabet, otherwise, it returns false.
 * Notes: 1st for loop is for going through the rows, 2nd for loop is for going through the columns
 * @param v - the vector containing the data from the file
 * @return vector<vector<char>> - return the board with all alphabets replaced with '_'
 */
vector<vector<char>> replace1(vector<vector<char>> v);

// using nested loops and if statements
/**
 * @brief same as replace1() function, but using if statements instead of isAlpha()
 *
 * @param v
 * @return vector<vector<char>>
 */
vector<vector<char>> replace2(vector<vector<char>> v);

// print 2d vector
/**
 * @brief This function prints the 2d vector -> literlly take from textbook (307-310 - Richard L. Halterman book)
 *
 * @param v - the vector containing the data from the file
 */
void print2dVector(vector<vector<char>> v);

int main()
{
    // make 2d vector for data from files
    vector<vector<char>> data1; // use just nested loop and if
    vector<vector<char>> data2; // use nested loop and isAlpha()

    // read data from files
    data1 = readData("ex.txt");
    data2 = readData("ex.txt");

    // print data from files
    cout << "Before replace\n";
    print2dVector(data1);
    cout << '\n';
    print2dVector(data2);

    cout << "------------------------------------------------------------\n";

    cout
        << "\nAfter replace using method 1 or replace1\n";
    data1 = replace1(data1);
    print2dVector(data1);

    cout << "\nAfter replace using method 2 or replace2\n";
    data2 = replace2(data2);
    print2dVector(data2);

    return 0;
}

// using just netsed for loops to read in data
vector<vector<char>> readData(string fileName)
{
    vector<vector<char>> board; // 2d vector to store data

    ifstream file(fileName); // open file

    if (file)
    {
        string line;

        //! checkpoint: read and make sure you understand this part/how it works
        //! don't blindly just copy my code
        while (getline(file, line)) // get line from file
        {
            vector<char> row;                       // we will store each line/row in a vector
            for (int i = 0; i < line.length(); i++) // this will loop through each charatcer in the line
            {
                row.push_back(line[i]); // add each character to the row vector
            }
            board.push_back(row); // add the row vector to the board vector
        }
        //! end of checkpoint if you read it, you will know how to fix the errors in the code
    }
    else
    {
        cout << "File not found\n";
    }
    file.close();
    return board;
}

// using nested for loops and isAlpha()
vector<vector<char>> replace1(vector<vector<char>> v)
{
    // we already has data for v -> no need to read again
    // so just need nested loop to replace those char that not ! and - with _ with help from isAlpha()
    for (int i = 0; i < v.size(); i++) // loop rows
    {
        for (int j = 0; j < v[i].size(); j++) // loop cols
        {
            //! checkpoint: read and make sure you understand this part/how it works
            //!  understand the point of 1st and 2nd for loop and why it there
            // so if it is letter -> we will replace it with _
            // reference to c++ library: https://www.cplusplus.com/reference/cctype/isalpha/ for more info

            if (isalpha(v[j][i])) // isalpha() is a function that check if the char is a letter
            {
                v[j][i] = '_';
            }
            //! again, the code will need be change little bit to work -> hint: i (row) and j (col)
            //! line 124->127 will need to be change
        }
    }

    // return 2d vector
    return v;
}

// using nested loops and if statements
vector<vector<char>> replace2(vector<vector<char>> v)
{
    // we already has data for v -> no need to read again
    // so just need nested loop to replace those char that not ! and - with _
    for (int i = 0; i < v.size(); i++) // loop rows
    {
        for (int j = 0; j < v[i].size(); j++) // loop cols
        {
            //! checkpoint: same with above
            // so if it is letter -> we will replace it with _
            if (v[j][i] != '!' && v[j][i] != '-')
            {
                v[j][i] = '_';
            }
            //! again, the code will need be change little bit to work -> hint: i (row) and j (col)
        }
    }

    // return 2d vector
    return v;
}

// print 2d vector
void print2dVector(vector<vector<char>> v)
{
    //! this will give hints to help replace1 & 2 function
    //! this is in the book (the free one) -> 307-310. Please read it to understand how it works
    // print 2d vector
    for (int i = 0; i < v.size(); i++) // this will loop through each row
    {
        for (int j = 0; j < v[i].size(); j++) // this will loop through each column
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}