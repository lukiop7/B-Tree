/**
 * @file file.h
 * @brief Contains functions for creating, adding and removing elements in b-tree
 * @author £ukasz Kwiecieñ
 */
#ifndef tree_func_H
#define tree_func_H
//#include "stdafx.h"
#include "structures.h"
#include "struct_func.h"
#include "print_func.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*!
 Function to split child of parent node and insert the middle key to parent node.
 @param parent pointer to parent node
 @param index index of the key in parent node
 @param child pointer to child node
 */
void split(node *&parent, int index, node *&child);

/*!
 Function adds a new key to node which is not full(n<2*t-1).
 @param root pointer to a  node of a tree
 @param val value to add
 */
void addtononfull(node *&root, double val);

/*!
 The main function that inserts a new key in this B-Tree. Functions depending on the amount of nodes etc. creates or splits nodes.
 @param root pointer to a node of the tree
 @param val value to add
 */
void add(node *&root, double val, int d);

/*!
 Function returns the index of the first key that is greater than or equal to k
 @param root pointer to a root of a tree
 @param val value to add
 */
int search(node *&root, double val);


/*!
 Functions to borrow a key from (idx+1)th child and place it in (idx)th child.
 @param idx index of a key from parent node
 @param root pointer to a node of a tree
 */
void borrowFromNext(int idx, node *& root);



/*!
 Functions to borrow a key from (idx-1)th child and place it in (idx)th child.
 @param idx index of a key from parent node
 @param root pointer to a node  of a tree
 */
void borrowFromPrev(int idx, node *&root);



/*!
 Function merges (idx+1)th child and (idx)th child and free (idx+1)th child.
 @param idx index of a key from parent node
 @param root pointer to a node  of a tree
 */
void merge(int idx, node*& root);


/*!
 Function fills (idx)th child which has less than t-1 keys
 @param idx index of a key from parent node
 @param root pointer to a node  of a tree
 */
void fill(int idx, node *&root);


/*!
 Function gets predecessor of a (idx)th key
 @param idx index of a key from parent node
 @param root pointer to a node  of a tree
 @return value of predecessor
 */
double getPred(int idx, node*& root);

/*!
 Function gets successor of a (idx)th key
 @param idx index of a key from parent node
 @param root  pointer to a node  of a tree
 @return value of successor
 */
double getSucc(int idx, node *& root);


/*!
 Function removes the (idx)th key from node which is leaf node.
 @param idx index of a key
 @param x pointer to leaf node
 */
void deleteFromLeaf(int idx, node *& x);

void deletefromtree(node*&, double);


/*!
 A function to remove the idx-th key from  node  which is a non-leaf node
 @param idx index of a key
 @param x pointer to leaf node
 */
void deleteFromNonLeaf(int idx, node *& root);

/*!
 Function for removing key from a node, calls other auxiliary functions.
 @param root pointer to a root of a tree
 @param val value to remove
 */
void deletefromtree(node *&root, double val);

/*!
 Main function for removing a key from the tree.
 @param root pointer to a root of a tree
 @param val value to remove
 */
void deleteval(node *&root, double val);



#endif
