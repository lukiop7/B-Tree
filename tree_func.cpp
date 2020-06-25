//#include "stdafx.h"
#include "structures.h"
#include "struct_func.h"
#include "print_func.h"
#include <iostream>
#include <iomanip>


using namespace std;

void split(node *&parent, int index, node *&child)
{
	int j;
	//Allocate a new node to store child_array's node.
	node *new_node = new node;
	new_node->t = child->t;
	new_node->value = new values_help{ nullptr,nullptr,0 };
	new_node->child = new child_help{ nullptr,nullptr,0 };
	new_node->n = parent->t - 1;
	new_node->leaf = child->leaf;

	//Move child_array's right half nodes to the new node.


	auto c = child->value->head;
	findelem(c, parent->t);
	int cnt = 0;
	for (j = 0; j < parent->t - 1; j++)
	{
		addvalue(new_node->value, c->key);
		//if (parent->t > 2) {
			//c = c->next;
			//removevalue(child->value, c->prev);
		//}
		//else { removevalue(child->value, c); }
		if (c->next) { c = c->next; }
		cnt++;
	}
	for (j = 0; j < cnt - 1; j++)
	{
		removevalue(child->value, c->prev);
	}
	removevalue(child->value, c);

	///If child_array is not leaf node,then move child_array's [child_array]s to the new
	///node's [child_array]s.
	if (child->leaf == false) {
		auto c = child->child->head;				///find tth child
		findchild(c, parent->t);
		int cnt = 0;
		for (j = 0; j < parent->t; j++) {
			addchild(new_node->child, c->child);
			//if (parent->t > 2) {
			//	c = c->next;
			//	removechild(child->child, c->prev);
			//}
			//else {
			//	if (j == 1)
			//	{
			if (c->next) { c = c->next; }
			cnt++;
			//	removechild(child->child, c->prev);
			//	removechild(child->child, c);

			//}
		//}

		}
		for (j = 0; j < cnt - 1; j++)
		{
			removechild(child->child, c->prev);
		}
		removechild(child->child, c);
	}
	child->n = parent->t - 1;					///update child key counter


	//Right shift ptrParent's [child_array] from index i


	addchild(parent->child, nullptr);
	auto p = parent->child->tail->prev;
	for (int j = parent->n; j >= index + 1; j--)
	{
		changechild(parent->child, p->child, j + 1);
		p = p->prev;
	}


	//Set ptrParent's ith child_array to the newNode.


	p = parent->child->head;
	findchild(p, index + 1);
	changespecchild(p, new_node);

	addvalue(parent->value, 0);
	auto d = parent->value->tail->prev;
	//findelem(d, parent->n - 1);
	for (int j = parent->n - 1; j >= index; j--)
	{
		changevalue(parent->value, d->key, j + 1);
		//j--;
		d = d->prev;

	}

	for (int j = 0; j < 1; j++)
	{
		auto n = parent->value->head;
		auto c = child->value->head;
		findelem(n, index);
		findelem(c, parent->t - 1);
		changespecvalue(n, c->key);
		removevalue(child->value, c);


	}



	//Increase ptrParent's Key number.
	parent->n += 1;

}
void addtononfull(node *&root, double val)
{
	int i = (root->n) - 1;
	if (root->leaf == true)
	{
		addvalue(root->value, 0);
		auto p = root->value->head;
		findelem(p, i);
		while (i >= 0 && p->key > val)
		{
			if (i == 0)
			{
				changevalue(root->value, p->key, i + 1);
				i--;
			}
			else {
				changevalue(root->value, p->key, i + 1);
				i--;
				p = p->prev;
			}

		}
		changevalue(root->value, val, i + 1);

		root->n += 1;
	}
	else // If this node is not leaf
	{
		auto p = root->value->head;
		bool splitted = false;
		findelem(p, i);
		// Find the child which is going to have the new key

		while (i >= 0 && p->key > val)
		{
			if (i == 0)
			{
				i--;
			}
			else {
				i--;
				p = p->prev;
			}
		}
		// See if the found child is full
		auto c = root->child->head;
		findchild(c, i + 1);

		if (c->child->n == (2 * root->t) - 1)
		{
			// If the child is full, then split it

			split(root, i + 1, c->child);
			splitted = true;

			if (p->key < val)
			{
				p = p->next;
				i++;
			}


		}
		if (splitted == true)
		{
			c = root->child->head;
			findchild(c, i + 1);
		}
		addtononfull(c->child, val);
	}
}



void add(node *&root, double val, int d)
{
	if (root == nullptr) //if tree is empty
	{
		node *newnode = new node;
		newnode->t = d;
		newnode->value = new values_help{ nullptr,nullptr,0 };
		//for (int j = 0; j < ((2 * newnode->t)-1); j++)
		//{ addvalue(newnode->value, 0); }
		//changevalue(newnode->value, val, 0);
		addvalue(newnode->value, val);
		newnode->child = new child_help{ nullptr,nullptr,0 };
		//for (int i = 0; i < ((2 * d)); i++) { addchild(newnode->child,nullptr); }
		newnode->n = 1;
		newnode->leaf = true;
		root = newnode;
	}
	else if (root->n == (2 * d) - 1) //root is full , create new and move one key up
	{
		node *s = new node;
		s->t = d;
		s->value = new values_help{ nullptr,nullptr,0 };
		//for (int j = 0; j < ((2 * s->t) - 1); j++) { addvalue(s->value, 0); }
		s->child = new child_help{ nullptr,nullptr,0 };
		//for (int i = 0; i < ((2 * d)); i++) { addchild(s->child,nullptr); }
		addchild(s->child, root);
		s->n = 0;
		s->leaf = false;
		split(s, 0, root);
		/*if (root->child[0] != nullptr) {
			for (int j = 0; j <= root->n ; j++) {
				s->child[1]->child[j]->prev = s->child[1];
			}
		}*/
		addtononfull(s, val);
		root = s;

	}
	else if (root->n < (2 * d)) { addtononfull(root, val); }


}

int search(node *&root, double val)
{
	int idx = 0;
	auto p = root->value->head;
	while (idx < root->n && p->key < val)
	{
		++idx;
		p = p->next;
	}
	return idx;
}

// A function to borrow a key from the C[idx+1] and place
// it in C[idx]
void borrowFromNext(int idx, node *& root)
{

	auto child = root->child->head;
	findchild(child, idx);
	auto sibling = child->next;
	auto p = root->value->head;
	findelem(p, idx);

	// keys[idx] is inserted as the last key in C[idx]
	addvalue(child->child->value, p->key);

	// Sibling's first child is inserted as the last child
	// into C[idx]
	if ((child->child->leaf) == false)
	{
		addchild(child->child->child, sibling->child->child->head->child);
		removechild(sibling->child->child, sibling->child->child->head);
	}
	//The first key from sibling is inserted into keys[idx]
	changespecvalue(p, sibling->child->value->head->key);
	removevalue(sibling->child->value, sibling->child->value->head);
	// Moving all keys in sibling one step behind
	//for (int i = 1; i < sibling->n; ++i)
		//sibling->value[i - 1] = sibling->value[i];

	// Moving the child pointers one step behind
//	if (sibling->leaf==false)
	//{
	//	for (int i = 1; i <= sibling->n; ++i)
	//		sibling->child[i - 1] = sibling->child[i];
	//}

	// Increasing and decreasing the key count of C[idx] and C[idx+1]
	// respectively
	child->child->n += 1;
	sibling->child->n -= 1;


}

// A function to borrow a key from C[idx-1] and insert it
// into C[idx]
void borrowFromPrev(int idx, node *&root)
{
	auto child = root->child->head;
	findchild(child, idx);
	auto sibling = child->prev;


	// The last key from C[idx-1] goes up to the parent and key[idx-1]
	// from parent is inserted as the first key in C[idx]. Thus, the  loses
	// sibling one key and child gains one key

	// Moving all key in C[idx] one step ahead
	//for (int i = child->n - 1; i >= 0; --i)
		//child->child->value[i + 1] = child->value[i];
	addvalue(child->child->value, 0);
	auto d = child->child->value->tail->prev;
	for (int j = child->child->n - 1; j >= 0; --j)
	{
		changevalue(child->child->value, d->key, j + 1);
		//j--;
		d = d->prev;

	}

	// If C[idx] is not a leaf, move all its child pointers one step ahead
	if (child->child->leaf == false)
	{
		//for (int i = child->n; i >= 0; --i)
			//child->child[i + 1] = child->child[i];
		addchild(child->child->child, nullptr);
		auto p = child->child->child->tail->prev;
		for (int j = child->child->n; j >= 0; --j)
		{
			changechild(child->child->child, p->child, j + 1);
			p = p->prev;
		}
	}

	// Setting child's first key equal to keys[idx-1] from the current node
	auto p = root->value->head;
	findelem(p, idx - 1);
	changespecvalue(child->child->value->head, p->key);
	// Moving sibling's last child as C[idx]'s first child
	if (child->child->leaf == false)
	{
		changespecchild(child->child->child->head, sibling->child->child->tail->child);
		removechild(sibling->child->child, sibling->child->child->tail);
		//child->child[0] = sibling->child[sibling->n];
	}
	// Moving the key from the sibling to the parent
	// This reduces the number of keys in the sibling
	//root->value[idx - 1] = sibling->value[sibling->n - 1];
	changespecvalue(p, sibling->child->value->tail->key);
	removevalue(sibling->child->value, sibling->child->value->tail);

	child->child->n += 1;
	sibling->child->n -= 1;


}






// A function to merge C[idx] with C[idx+1]
// C[idx+1] is freed after merging
void merge(int idx, node*& root)
{
	auto child = root->child->head;
	findchild(child, idx);
	auto sibling = child->next;

	//node *child = root->child[idx];
	//node  *sibling = root->child[idx + 1];

	// Pulling a key from the current node and inserting it into (t-1)th
	// position of C[idx]
	auto p = root->value->head;
	findelem(p, idx);
	addvalue(child->child->value, p->key);


	// Copying the keys from C[idx+1] to C[idx] at the end
	for (int i = 0; i < sibling->child->n; ++i)
		//child->value[i + root->t] = sibling->value[i];
	{
		addvalue(child->child->value, sibling->child->value->head->key);
		removevalue(sibling->child->value, sibling->child->value->head);
	}

	// Copying the child pointers from C[idx+1] to C[idx]
	if (child->child->leaf == false)
	{
		for (int i = 0; i <= sibling->child->n; ++i)
		{
			//child->child[i + root->t] = sibling->child[i];
			addchild(child->child->child, sibling->child->child->head->child);
			removechild(sibling->child->child, sibling->child->child->head);
		}
	}

	// Moving all keys after idx in the current node one step before -
	// to fill the gap created by moving keys[idx] to C[idx]
	//auto d = root->value->head;
	//findelem(d, idx + 1);
	//for (int i = idx + 1; i <root->n; ++i)
	//{
	//	changevalue(root->value, p->next->key, i - 1);
	//	p = p->next;
	//}
	removevalue(root->value, p);

	// Moving the child pointers after (idx+1) in the current node one
	// step before
	//for (int i = idx + 2; i <= root->n; ++i)
		//root->child[i - 1] = root->child[i];
	//auto a = root->child->head;
	//findelem(p, idx + 2);
	//for (int i = idx + 2; i <= root->n; ++i)
	//{
	//	changechild(root->child, a->child, i - 1);
	//	a = a->next;
	//}
//

	// Updating the key count of child and the current node
	child->child->n += sibling->child->n + 1;
	delete sibling->child->child;
	delete sibling->child->value;
	delete sibling->child;
	removechild(root->child, sibling);
	root->n--;

	// Freeing the memory occupied by sibling


}

// A function to fill child C[idx] which has less than t-1 keys
void fill(int idx, node *&root)
{
	auto p = root->child->head;
	findchild(p, idx);
	// If the previous child(C[idx-1]) has more than t-1 keys, borrow a key
	// from that child
	if (idx > 0 && p->prev->child->n >= root->t)
		borrowFromPrev(idx, root);

	// If the next child(C[idx+1]) has more than t-1 keys, borrow a key
	// from that child
	else if (idx < root->n && p->next->child->n >= root->t)
		borrowFromNext(idx, root);

	// Merge C[idx] with its sibling
	// If C[idx] is the last child, merge it with with its previous sibling
	// Otherwise merge it with its next sibling
	else
	{
		if (idx != root->n)
			merge(idx, root);
		else
			merge(idx - 1, root);
	}

}


//A function to get predecessor of keys[idx]
double getPred(int idx, node*& root)
{
	// Keep moving to the right most node until we reach a leaf
	auto d = root->child->head;
	findchild(d, idx);
	while (!d->child->leaf)
		d = d->child->child->tail;
	//cur = cur->child[cur->n];

	// Return the last key of the leaf
	return d->child->value->tail->key;
}

double getSucc(int idx, node *& root)
{

	// Keep moving the left most node starting from C[idx+1] until we reach a leaf
	auto d = root->child->head;
	findchild(d, idx + 1);
	//node *cur = root->child[idx + 1];
	while (!d->child->leaf)
		d = d->child->child->head;

	// Return the first key of the leaf
	return d->child->value->head->key;
}

// A function to remove the idx-th key from this node - which is a leaf node
void deleteFromLeaf(int idx, node *& x)
{
	auto d = x->value->head;
	findelem(d, idx + 1);
	/*for (int j = parent->n - 1; j >= index; j--)
	{
		changevalue(parent->value, d->key, j + 1);
		//j--;
		d = d->prev;

	}*/
	// Move all the keys after the idx-th pos one place backward
	for (int i = idx + 1; i < x->n; ++i)
	{
		//x->value[i - 1] = x->value[i];
		changevalue(x->value, d->key, i - 1);
		d = d->next;
	}
	// Reduce the count of keys
	d = x->value->tail;
	removevalue(x->value, d);
	x->n--;

}

void deletefromtree(node*&, double);

// A function to remove the idx-th key from this node - which is a non-leaf node
void deleteFromNonLeaf(int idx, node *& root)
{
	auto p = root->value->head;
	findelem(p, idx);
	double k = p->key;
	auto d = root->child->head;
	findchild(d, idx);
	// If the child that precedes k (C[idx]) has atleast t keys,
	// find the predecessor 'pred' of k in the subtree rooted at
	// C[idx]. Replace k by pred. Recursively delete pred
	// in C[idx]
	if (d->child->n >= root->t)
	{
		double pred = getPred(idx, root);
		p->key = pred;
		deletefromtree(d->child, pred);
	}

	// If the child C[idx] has less that t keys, examine C[idx+1].
	// If C[idx+1] has atleast t keys, find the successor 'succ' of k in
	// the subtree rooted at C[idx+1]
	// Replace k by succ
	// Recursively delete succ in C[idx+1]
	else if (d->next->child->n >= root->t)
	{
		double succ = getSucc(idx, root);
		p->key = succ;
		deletefromtree(d->next->child, succ);
	}

	// If both C[idx] and C[idx+1] has less that t keys,merge k and all of C[idx+1]
	// into C[idx]
	// Now C[idx] contains 2t-1 keys
	// Free C[idx+1] and recursively delete k from C[idx]
	else
	{
		merge(idx, root);
		deletefromtree(d->child, k);
	}

}

void deletefromtree(node *&root, double val)
{
	int idx = search(root, val);
	auto p = root->value->head;
	findelem(p, idx);
	// The key to be removed is present in this node
	if (idx < root->n && p->key == val)
	{

		// If the node is a leaf node - removeFromLeaf is called
		// Otherwise, removeFromNonLeaf function is called
		if (root->leaf == true)
		{
			deleteFromLeaf(idx, root);
		}
		else
		{
			deleteFromNonLeaf(idx, root);
		}
	}

	else
	{

		// If this node is a leaf node, then the key is not present in tree
		if (root->leaf == true)
		{
			cout << "The key " << val << " does not exist in the tree" << endl;
			return;
		}

		// The key to be removed is present in the sub-tree rooted with this node
		// The flag indicates whether the key is present in the sub-tree rooted
		// with the last child of this node
		bool flag;
		if (idx == root->n)
		{
			flag = true;
		}
		else
		{
			flag = false;
		}


		// If the child where the key is supposed to exist has less that t keys,
		// we fill that child
		auto p = root->child->head;
		findchild(p, idx);
		if (p->child->n < root->t)
			fill(idx, root);

		// If the last child has been merged, it must have merged with the previous
		// child and so we recurse on the (idx-1)th child. Else, we recurse on the
		// (idx)th child which now has atleast t keys
		p = root->child->head;
		//if (idx > root->n)
		//{
			//idx--;
		//}
		if (root->child->cnt > 1)
		{

			if (flag && idx > root->n)
			{
				findchild(p, idx - 1);
				deletefromtree(p->child, val);

			}

			else
			{
				findchild(p, idx);
				deletefromtree(p->child, val);
			}
		}
		else
		{
			findchild(p, idx - 1);
			if (flag && idx > root->n)
				deletefromtree(p->child, val);
			else
				deletefromtree(p->child, val);
		}
	}

	//}
}

void deleteval(node *&root, double val)
{
	if (root == nullptr)
	{
		cout << "The tree is empty\n";

	}

	// Call the remove function for root
	deletefromtree(root, val);

	// If the root node has 0 keys, make its first child as the new root
	//  if it has a child, otherwise set root as NULL
	if (root->n == 0)
	{
		node *tmp = root;
		if (root->leaf == true)
			root = nullptr;
		else
			root = root->child->head->child;

		// Free the old root
		delete tmp->value;
		if (tmp->child->cnt > 0)
		{
			auto c = tmp->child->tail;
			while (c->prev != nullptr)
			{
				c = c->prev;
				delete c->next;
				tmp->child->cnt--;
			}
			delete c;
			tmp->child->cnt--;
		}
		delete tmp->child;
		delete tmp;
	}
	return;
}

