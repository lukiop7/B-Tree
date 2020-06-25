//#include "stdafx.h"
#include "structures.h"
#include "print_func.h"
#include <iostream>
#include <iomanip>


using namespace std;

void graph(ostream &s, node *&root, int a)
{
	int jump = 10;
	a++;
	// There are n keys and n+1 children, travers through n keys
	// and first n children
	int i;
	auto p = root->value->tail;
	auto c = root->child->tail;
	//findelem(p, root->n - 1);
	//findchild(c, root->n);
	for (i = root->n - 1; i >= 0; i--)
	{
		// If this is not leaf, then before printing key[i],
		// traverse the subtree rooted with child C[i].
		if (root->leaf == false)
		{

			graph(s, c->child, a);

		}
		if (i == root->n - 1 && root->n > 1)
		{
			s << setw(jump*a) << " " << p->key << "]" << endl;
		}
		if (i == 0 && root->n > 1)
		{
			s << setw(jump*a) << "[" << p->key << endl;
		}
		if (root->n == 1)
		{
			s << setw(jump*a) << "[" << p->key << "]" << endl;
		}
		if (i > 0 && i < root->n - 1)
		{
			s << setw(jump*a) << " " << p->key << endl;
		}
		if (c) { c = c->prev; }
		if (p) { p = p->prev; }
	}

	// Print the subtree rooted with last child
	if (root->leaf == false)

		graph(s, c->child, a);

}

void print(ostream &s, node *&root)
{
	// There are n keys and n+1 children, travers through n keys
	// and first n children
	int i;
	auto p = root->value->head;
	auto c = root->child->head;


	for (i = 0; i < root->n; i++)
	{
		// If this is not leaf, then before printing key[i],
		// traverse the subtree rooted with child C[i].
		if (root->leaf == false)
		{

			print(s, c->child);

		}

		s << " " << p->key;
		if (c) { c = c->next; }
		if (p) { p = p->next; }
	}

	// Print the subtree rooted with last child
	if (root->leaf == false)

		print(s, c->child);

}




