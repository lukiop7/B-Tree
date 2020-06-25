/**
 * @file file.h
 * @brief Contains functions for opening, reading commands and operating on input file
 * @author £ukasz Kwiecieñ
 */
#ifndef file_H
#define file_H
//#include "stdafx.h"
#include "structures.h"
#include "print_func.h"
#include "tree_func.h"
#include <iostream>
#include <fstream>
//#include <cctype>
#include <string>
#include <string.h>
#include <sstream>
#include <iomanip>

/*!
 Function checks if the input file is in the correct format. Compares name of the file with the ".txt" format.
 @param x  name of input file
 @param format format of the file
 @return true if format of the input file is valid, false if not.
 */
bool check_file(const char *x, const  char *format);

/*!
 Opens file, reads entire file line by line, interpret commands and check if there are any invalid commands.
 Calls functions connected with b-tree. Prints output to the file or standard output.
 @param name name of the input_t file
 @param order order of the tree
 @param root pointer to empty tree
 */
void openfile(string &name, int &order, node *&root);///reads input file, interprets commands


#endif
