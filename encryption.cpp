#include "encryption.h"

#include <vector>

std::vector<char> encrypt_message (std::vector<char> message, std::vector<char> key)
{
    for (int letter = 0; letter < message.size(); letter++)
    {
        message[letter] = message[letter] ^ key[letter % key.size()];
    }

    return message;
}