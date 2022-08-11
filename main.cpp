/*
 * Though very possible and practically no different, including .c files
 *  directly is discouraged. Usually the content of .h files is definition and
 *  is wrapped in #include-guards (like #ifndef); the content of .c files is
 *  usually implementation and contains no such guards. In a larger project,
 *  you are likely to begin to see problem with this...
 */
#include "encryption.h"
#include "vector_utils.h"

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

    /*
     * This is the thing we already mentioned a couple of sessions back, by
     *  using a range initializer for this vector, you are reading the whole
     *  file into memory, if this were a drive I wished to encrypt, we may see
     *  some problems here
     *
     * ------------------------------------------------------------------------
     *
     * Also, we're using C++11 for the brace-initialization above... so we could
     *  use 
     *
     *  ```c++
     *  std::vector<char> message(
     *      std::istreambuf_iterator<char>(input_file), {});
     *  ```
     *
     * ------------------------------------------------------------------------
     *
     * On a real picky note, text widths apply to comments too :D
     */
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
