#include "vector_utils.h"

/*
 * JUST A COMMENT:
 * 
 * Though commonly talked about as a code smell there are several places where
 *  single-letter variables names are a-okay, namely short functions and with
 *  often-used vars e.g. `f` for file, `v` for vector, `i` for index, `c` for
 *  char, etc.
 *  
 * These are, of course, a matter of preference with no real benefit either way,
 *  one-letter makes short lines which some argue are more readable, words make
 *  more linguistic sense which others argue is more readable
 *  
 * My point here is only that if you avoid them because "one-letter vars are 
 *  bad, full-stop" then I would reconsider
 *
 * ----------------------------------------------------------------------------
 *
 * Being needlessly picky here, I would question the name of the file, 
 *  `vector_utils.cpp`, these utils don't operate within the vector, they:
 *
 *  - Print a containe's elements
 *  - Split a string in characters
 *
 *  vectors as a type are almost a side effect of your implmentation - I would
 *  see them as printing utils and string utils or even, just "utils"
 *
 *  To take that even further, as they're single use in the project, is
 *  encapsulating them the right thing to do... more food for thought than
 *  anything
 *
 * If you have an hour to kill: https://www.youtube.com/watch?v=FyCYva9DhsI
 */

#include <fstream>
#include <string>
#include <vector>

/*
 * Naming pickiness again, though "printing to console" is perfectly valid, and
 *  the console is really just a file descriptor in *nix just like files are...
 *  "printing to file" is not valid, as can be seen in the `ofstream` method
 *  `.write`, ergo this function should be `write_vector_to_file`... again
 *  pickiness
 */
void print_vector_to_file(std::vector<char> vector, std::ofstream &file)
{
    for (int index = 0; index < vector.size(); index++)
    {
        file.write(&vector[index], sizeof(vector[index]));
    }
}

/*
 * In C++, particularly with the STL, there is usually a spicy initializer for
 * any and all purposes, this function could be:
 *
 *   std::vector<char> vec(str.begin(), str.end());
 *
 * in the calling code, same as your "read file to vector" constructor
 */
std::vector<char> convert_string_to_vector(std::string string)
{
    std::vector<char> vector;

    for (int letter = 0; letter < string.length(); letter++)
    {
        vector.push_back(string[letter]);
    }

    return vector;
}
