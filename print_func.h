/**
 * @file file.h
 * @brief Contains printing functions
 * @author £ukasz Kwiecieñ
 */
#ifndef print_func_H
#define print_func_H
//#include "stdafx.h"
#include "structures.h"
#include "tree_func.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*!
 Recursively prints tree of numbers(with intended levels) to given output.
 @param s output stream
 @param root pointer to the root node
 @param a auxiliary variable for intending levels of the tree
 */
void graph(ostream &s, node *&root, int a);

/*!
 Recursively prints sorted numbers in one line to given output.
 @param s output stream
 @param root pointer to the root node
 */
void print(ostream &s, node *&root);



#endif

