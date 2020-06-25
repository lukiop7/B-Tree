//#include "stdafx.h"
#include "structures.h"
#include <iostream>
#include <iomanip>
#include "struct_func.h"




void addvalue(values_help*&L, double nb)
{
	if (L->cnt == 0)
	{
		values_list *pFirst = new values_list{ nb,nullptr,nullptr };
		L->cnt++;
		L->head = pFirst;
		L->tail = pFirst;
	}
	else

	{
		values_list *pNew = new values_list{ nb,L->tail,nullptr };
		L->tail->next = pNew;
		L->tail = pNew;
		L->cnt++;
		if (pNew->prev)
		{
			pNew->prev->next = pNew;
		}

	}

}
void changevalue(values_help*&L, double nb, int index)
{
	int pos = index + 1;
	auto p = L->head;
	for (int i = 1; i < pos; i++)
	{
		p = p->next;
	}
	p->key = nb;

}
void changespecvalue(values_list*&L, double nb)
{

	L->key = nb;

}

void changechild(child_help*&L, node * child, int index)
{
	int pos = index + 1;
	auto p = L->head;
	for (int i = 1; i < pos; i++)
	{
		p = p->next;
	}
	p->child = child;

}

void changespecchild(child_list*&L, node *chil)
{

	L->child = chil;

}


void addchild(child_help*&L, node *child)
{
	if (L->cnt == 0)
	{
		child_list *pFirst = new child_list{ child,nullptr,nullptr };
		L->cnt++;
		L->head = pFirst;
		L->tail = pFirst;
	}
	else

	{
		child_list *pNew = new child_list{ child,L->tail,nullptr };
		L->tail->next = pNew;
		L->tail = pNew;
		L->cnt++;
		if (pNew->prev)
		{
			pNew->prev->next = pNew;
		}

	}

}

void findelem(values_list*&p, int index)
{
	for (int j = 0; j < index; j++)
	{
		p = p->next;
	}
}

void findchild(child_list*&p, int index)
{
	for (int j = 0; j < index; j++)
	{
		p = p->next;
	}
}

void removechild(child_help*&L, child_list*e)
{
	L->cnt--;
	if (e->prev) e->prev->next = e->next;
	else        L->head = e->next;
	if (e->next) e->next->prev = e->prev;
	else        L->tail = e->prev;
	delete e;
}

void removevalue(values_help*&L, values_list*e)
{
	L->cnt--;
	if (e->prev) e->prev->next = e->next;
	else        L->head = e->next;
	if (e->next) e->next->prev = e->prev;
	else        L->tail = e->prev;
	delete e;
}

void free(node *&root)
{
	if (root != nullptr)
	{
		// There are n keys and n+1 children, travers through n keys
		// and first n children
		int i;
		auto p = root->value->tail;
		auto c = root->child->tail;

		// If this is not leaf, then before printing key[i],
		// traverse the subtree rooted with child C[i].
		if (root->leaf == false)
		{

			free(c->child);
			for (int i = root->n - 1; i >= 0; i--)
			{
				c = c->prev;
				free(c->child);
			}

		}
		if (root->child->cnt > 0)
		{
			auto c = root->child->tail;
			while (c->prev != nullptr)
			{
				c = c->prev;
				delete c->next;
				root->child->cnt--;
			}
			delete c;
			root->child->cnt--;
		}
		if (root->child->cnt == 0)
		{
			auto c = root->child;
			delete c;
		}
		if (root->value->cnt > 0)
		{
			auto p = root->value->tail;
			while (p->prev != nullptr)
			{
				p = p->prev;
				delete p->next;
				root->value->cnt--;
			}
			delete p;
			root->value->cnt--;
		}
		if (root->value->cnt == 0)
		{
			auto p = root->value;
			delete p;
		}
		delete root;
	}
	else
	{
		return;
	}

}
