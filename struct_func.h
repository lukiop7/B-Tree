/**
 * @file file.h
 * @brief Contains functions connected with structures
 * @author £ukasz Kwiecieñ
 */
#ifndef struct_func_H
#define struct_func_H

#include <iostream>
#include <iomanip>



/*!
 Recursively adds value to the doubly-linked list for values
 @param L pointer to the helper structure of list
 @param nb value to add
 */
void addvalue(values_help*&L, double nb);

/*!
 Recursively searches and changes value of (index)th element in the list of values
 @param L pointer to the helper structure of the list
 @param nb value to change
 @param index index of element to change
 */
void changevalue(values_help*&L, double nb, int index);

/*!
  Changes value of given element in the list of values
 @param L pointer to element to change in values list
 @param nb value to change
 */
void changespecvalue(values_list*&L, double nb);


/*!
  Recursively searches and changes pointer to child of (index)th element in the list of children
 @param L pointer to element to helper structure of the list
 @param child pointer to child
 @param index index of element to change
 */
void changechild(child_help*&L, node * child, int index);///searches for element to change and changes it

/*!
  Changes pointer to child of a given element in the list of values
 @param L pointer to element to change in values list
 @param chil value to change
 */
void changespecchild(child_list*&L, node *chil);///changes child pointer of specific element

/*!
   Recursively adds child pointer to the doubly-linked list for children
 @param L pointer to the helper structure of the list
 @param child child pointer to add
 */
void addchild(child_help*&L, node *child);

/*!
   Recursively finds (index)th element in values list
 @param p pointer to the helper structure of the list
 @param index index of the element
 */
void findelem(values_list*&p, int index);

/*!
   Recursively finds (index)th element in children list
 @param p pointer to the helper structure of the list
 @param index index of the element
 */
void findchild(child_list*&p, int index);

/*!
   Recursively removes element from children list
 @param L pointer to the helper structure of the list
 @param e pointer to element to be removed
 */
void removechild(child_help*&L, child_list*e);

/*!
   Recursively removes element from values list
 @param L pointer to the helper structure of the list
 @param e pointer to element to be removed
 */
void removevalue(values_help*&L, values_list*e);

/*!
 The functions removes all nodes of the tree, all elements of lists and lists.
 @param root pointer to a root of the tree
 */
void free(node *&root);







#endif
