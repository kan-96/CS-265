/*
 * test.c - Test driver (contains the main function)
 *  - As you implement functions, test them here
 *
 *Khoa Nguyen  
 * 11/1/2022
 *
 * gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 on
 * GNU/Linux 5.4.0-66-generic x86_64
 *
 * EDITOR:  tabstop=2, cols=120
 *
 */

#include <stdio.h>
#include <stdbool.h>

#include "mystring.h"

const char* IND    = "  " ;  // indent - 2 spaces
const char* BOLD   = "\e[1m" ;
const char* RED    = "\e[0;31m" ;
const char* BRED   = "\e[1;31m" ;
const char* GREEN  = "\e[0;32m" ;
const char* BGREEN = "\e[1;32m" ;
const char* NORM   = "\e[0m" ;

int main()
{
	bool errors = false ;
	size_t l ;

		/****  MYSTRLEN  *********************/
	printf( "\n%smystrlen:\n", BOLD ) ;
	printf( "---------%s\n", NORM ) ;

	l = mystrlen( "apple" ) ;
	if( l != 5 ) {
		printf( "%s%sERROR:%s  `apple' has %zu characters\n", IND, BRED, NORM, l ) ;
		errors = true ;
	}

	l = mystrlen( "apple\t" ) ;
	if( l != 6 ) {
		printf( "%s%sERROR:%s  `apple\\t' has %zu characters\n", IND, BRED, NORM, l ) ;
		errors = true ;
	}

	l = mystrlen( "" ) ;
	if( l != 0 ) {
		printf( "%s%sERROR:%s  `' has %zu characters\n", IND, BRED, NORM, l ) ;
		errors = true ;
	}

	if( ! errors )
		printf( "\n%s%sPassed!%s\n", IND, BGREEN, NORM ) ;

		/****  MYSTRCPY  *********************/
	errors = false ;
	printf( "\n%smystrcpy:\n", BOLD ) ;
	printf( "---------%s\n", NORM ) ;

	if( ! errors )
		printf( "\n%s%sPassed!%s\n", IND, BGREEN, NORM ) ;


	puts( "" ) ;  // newline
	return 0 ;
}

