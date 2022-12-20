/*
 * start.c - a test driver for the List in Activity 8
 *
 * Kurt Schmidt
 * FEB 22
 *
 * gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0, on
 * 5.4.0-100-generic x86_64 GNU/Linux
 *
 * NOTES
 *  - you can have more than one driver, to test various functions as you implement them, if desired
 *    - Add other entries similar to `start' to your makefile
 *
 */

#include <stdlib.h>
#include <stdio.h>

#include "act8.h"

int main()
{
	elem_t arr[] = { 37, 7, 62, 7, 62, 17, 40, 62 } ;

	List l = make_list( arr, 8) ;

	printList( l, stdout ) ;
	printf ("\n");
	///test1
	printf ("Test 1: %ld\n",size(l));
	//Test 2
	printf ("Test2: %ld\n", count(l,7));
	//test 3
	l = remove_first(l, 7);
	printf ("Test 3: ");
	//test 4
	printList(l, stdout);
	l= remove_all(l,62);
	printf ("Test 4: ");
	printList( l, stdout);
	return 0 ;
}
