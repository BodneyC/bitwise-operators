#include <vector>
#include <fstream>
#include <string>

#ifndef VECTOR_UTILS_H
#define VECTOR_UTILS_H

void print_vector_to_file(std::vector<char> vector, std::ofstream &file);

std::vector<char> convert_string_to_vector(std::string string);

#endif