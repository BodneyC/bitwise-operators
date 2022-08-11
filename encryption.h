#ifndef ENCRYPTION_H
#define ENCRYPTION_H

/*
 * Includes should be within the include guards
 *
 * Assuming that the vector library includes similar `#ifndef` or `#pragma once`
 *  guards this won't cause an issue. However, if they don't then the very thing
 *  that the guards are trying to prevent will happen, multiple source files
 *  including this header will include vector multiple times and define symbols
 *  multiple times... leading to a compilation error
 */
#include <vector>

std::vector<char> encrypt_message (std::vector<char> &message, std::vector<char> &key);

#endif
