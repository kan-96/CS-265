/********************************************************************************
 * stack-ll.c -- implementation for stack functions (built over a linked list)
 *
 * Kurt Schmidt
 * NOV 2020
 *
 * gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0, on
 * GNU/Linux 4.15.0-117-generic x86_64
 *
 * EDITOR:  tabstop=2, cols=120
 *
 * NOTES (Invariants):
 *	- Stack is empty iff stack's head ptr is NULL
 *
 ********************************************************************************/

#include <assert.h>
#include <stdlib.h>

#include "stack-ll.h"


void init( stack* s )
{
	// TODO:  Init fields
	s->head = NULL;
	return ;
}

void kill( stack* s )
{
	sNode *p = s->head, *q ;
	while( p != 0 ) 
	{
		q = p->next ;
		free( p ) ;
		p = q ;
	}
}

_Bool isEmpty( const stack* s ) 
{
	// TODO

	return s->head == NULL;
}

void push( stack* s, ELEM i ) 
{
	// TODO
	sNode* p = (sNode*) malloc(sizeof(sNode));
	if ( isEmpty(s))	{
		p->data = i;
		p->next = NULL;
		s->head = p;
	}
	else	{
		p->data = i;
		p->next = s->head;
		s->head = p;
	}
	return ;
}

ELEM pop( stack* s ) 
{
	// TODO
	sNode* temp = s->head;
	ELEM pop = s->head->data;
	s->head = s->head->next;
	free(temp);
	return pop;	
}

ELEM top( const stack* s ) 
{
	// TODO
	ELEM top = s->head->data;
	return top;
	}


