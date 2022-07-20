#include "vector_utils.h"

#include <fstream>
#include <string>
#include <vector>

void print_vector_to_file(std::vector<char> vector, std::ofstream &file)
{
    for (int index = 0; index < vector.size(); index++)
    {
        file.write(&vector[index], sizeof(vector[index]));
    }
}

std::vector<char> convert_string_to_vector(std::string string)
{
    std::vector<char> vector;

    for (int letter = 0; letter < string.length(); letter++)
    {
        vector.push_back(string[letter]);
    }

    return vector;
}