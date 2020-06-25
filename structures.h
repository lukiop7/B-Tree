/**
 * @file file.h
 * @brief Contains structure of the tree , main and helper structures for storing values and children
 * @author £ukasz Kwiecieñ
 */
#ifndef structures_H
#define structures_H
//#include "stdafx.h"
#include <iostream>
#include <iomanip>


struct node;

///doubly-linked list for storing values
struct values_list
{
	double key; ///value
	values_list *prev, *next; ///pointers to previous and next element
};

///auxiliary structure for storing the number of elements and pointers to first and last
struct values_help
{
	values_list *head, *tail;///pointers to first and last elements of the values list
	int cnt; ///counter for the number of elements
};

///doubly-linked list for storing pointers to children
struct child_list
{
	node *child; ///pointer to child
	child_list *prev, *next; ///pointer to previous and next element
};

///auxiliary structure for storing the number of elements and pointers to first and last
struct child_help
{
	child_list *head, *tail;
	int cnt;
};

///structure of the b-tree
struct node {

	int  t; ///order of the tree(minimal number of keys)
	values_help *value; ///pointer to list of keys
	child_help *child; ///pointer to list of pointers to children
	int n; ///actual number of keys
	bool leaf; ///if true then no children

};







#endif

