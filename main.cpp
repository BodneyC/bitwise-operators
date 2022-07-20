#include "encryption.h"
#include "encryption.cpp"

#include "vector_utils.h"
#include "vector_utils.cpp"

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
    // If the user hasn't entered the correct number of arguments, tell them how to use the program and quit
    if (argc != 4)
    {
        std::cerr << "Usage: ./main [key] [input file] [output file]" << '\n';
        return 1;
    }

    // Set up input file stream. If the file isn't there, error and quit
    std::ifstream input_file{ argv[2], std::ios::binary | std::ios::in };
    if (!input_file)
    {
        std::cerr << "Input file could not be read";
        return 1;
    }

    // Set up output file stream. If the file isn't there, error and quit
    std::ofstream output_file { argv[3], std::ios::binary | std::ios::out } ;
    if (!output_file)
    {
        std::cerr << "Output file could not be read or created";
        return 1;
    }

    // Add the content of the input file into a vector. This is done using the the istreambuf_iterator because when we decrypt a message, we'll be reading in binary that can't be translated into text
    std::vector<char> message(
        (std::istreambuf_iterator<char>(input_file)),
        (std::istreambuf_iterator<char>()));

    // Convert the key into a vector
    std::vector<char> key = convert_string_to_vector(argv[1]);

    // Encrypt the message using the key
    std::vector<char> encrypted_message = encrypt_message(message, key);

    // Print the encrypted message to a file
    print_vector_to_file(encrypted_message, output_file);

    return 0;
}