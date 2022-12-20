/*
 * act8.c - implementations for list functions, Activity 8
 *
 * Kurt Schmidt
 * FEB 22
 *
 * gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0, on
 * 5.4.0-100-generic x86_64 GNU/Linux
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "act8.h"


void printList( List p, FILE* fout ) 
{
	fputs( "<", fout ) ;
	if( p!=NULL )
	{
		fprintf( fout, "%hd", p->data ) ;
		p = p->next ;
	}
	while( p!=NULL )
	{
		fprintf( fout, ", %hd", p->data ) ;
		p = p->next ;
	}
	fputs( ">", fout ) ;
}
size_t size (List p)	{
	size_t cnt =0;
	while (p != NULL)	{
		cnt++;
		p =p->next;
	}
	return cnt;
}
size_t count (List p, elem_t t)	{
	size_t cnt =0;
	while(p != NULL)	{
		if (p->data == t)
			cnt++;
		p = p->next;
	}
	return cnt;
}	
sNode* remove_first(List p, elem_t t)	{
  List temp  = p;
  sNode* head = NULL;
  if (temp != NULL && temp->data == t)   {
    sNode* tempLink = temp;
    temp = temp->next;
    head = temp;
    free( tempLink);
    return head;
   }
  head = temp;
  while (temp->next != NULL)   {
	if (temp->next->data == t)  {
		sNode* tempLink = temp;
      temp->next = temp->next->next;
      free( tempLink);
		return p;
    }
	 temp = temp->next;
   }
  return head;	
}
sNode* remove_all(List p, elem_t t)	{
	sNode* temp =p;
	//sNode* firstNode = NULL;
	if (temp != NULL)	{
		//save the first node before we remove anything
		while (temp->data == t)	{
			sNode* nodeRemoved = temp;
			temp = temp->next;
			free(nodeRemoved);
		}
		//firstNode = temp;
		while (temp->next != NULL)	{
			if (temp->next->data == t)	{
				sNode* nodeRemoved = temp->next;
				temp->next = temp->next->next;
				free(nodeRemoved);
			}
			temp = temp->next;
		}
	}
	return temp;
}
List make_list( elem_t a[], size_t n )
{
	List rv = NULL ;

	if( n==0 )
		return rv ;
	
	rv = make_list( a+1, n-1 ) ;

	sNode* t = (sNode*) malloc( sizeof( sNode )) ;
	if( t==NULL ) return NULL ;

	t->data = a[0] ;
	t->next = rv ;
	rv = t ;

	return rv ;
}


