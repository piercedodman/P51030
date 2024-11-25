/* 
 * main.cpp
 * 
 * 
 *  COSC 1030 Fall 2024 
 *  Project #5 
 * 
 *  Due on: DEC 6, 2024 
 *  Author: Dodman  rpd62 
 * 
 * 
 *  In accordance with the class policies and Georgetown's 
 *  Honor Code, I certify that, with the exception of the 
 *  class resources and those items noted below, I have neither 
 *  given nor received any assistance on this project. 
 * 
 *  References not otherwise commented within the program source code. 
 *  Note that you should not mention any help from the TAs, the professor, 
 *  or any code taken from the class textbooks. 
 * 
 */ 


#include "main.h"


int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
        throw missing_arguments("Usage: " + std::string(argv[0]) + " <input file>");
    }

    // Open the input file
    std::ifstream input_file(argv[1]);
    if (!input_file) {
        throw file_open_error("Error opening file: " + std::string(argv[1]));
    }

    // Read the input file
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(input_file, line)) {
        lines.push_back(line);
    }


    return 0;
}