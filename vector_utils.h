#ifndef VECTOR_UTILS_H
#define VECTOR_UTILS_H

/*
 * See encryption.h for why these includes are moved
 */
#include <vector>
#include <fstream>
#include <string>

void print_vector_to_file(std::vector<char> vector, std::ofstream &file);

std::vector<char> convert_string_to_vector(std::string string);

#endif
