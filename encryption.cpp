#include "encryption.h"

#include <vector>

/*
 * Here, you are recieving the vectors as references, so instead of copying the
 *  vector, you simply pass a pointer to the class instance
 *
 * Nothing wrong here, but it means that anything you do `message` happens to
 *  the vector of the receiving function (`main`)
 *
 * In other words, you mutate the input... this is seen as bad in some (mainly
 *  functional) languages but is honestly standard practice in C/C++, the point
 *  I would make is that you return the same reference you passed in where you
 *  could have just continued using the mutated `message` variable in main
 *
 * In an effort to save a few bytes, you have actually lost eight :D
 */
std::vector<char> encrypt_message (std::vector<char> &message, std::vector<char> &key)
{
    for (int letter = 0; letter < message.size(); letter++)
    {
        message[letter] = message[letter] ^ key[letter % key.size()];
    }

    return message;
}
