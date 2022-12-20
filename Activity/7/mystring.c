/*
 * mystring.c - implementation of my (your) string functions.
 *
 * <your name>
 * May 2021
 *
 * gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 on
 * GNU/Linux 5.4.0-66-generic x86_64
 *
 * EDITOR:  tabstop=2, cols=120
 *
 * NOTES
 *  - We include stddef.h so the compiler can check that the functions here jibe with the declarations in our contract
 *    - the <> indicate a standard library header file
 *      - the compiler knows where to search
 *    - A .h file in quotes is a user-defined file
 *      - Should be in (relative to) CWD
 *      - Should come after all system and standard includes
 *  - To compile
 *        gcc -c mystring.c
 *    - yields mystring.o (object file)
 *    - -c says "compile only"
 *    - does not link
 *  - You can use an s* much like an s[].
 *    - s[3] is valid (if length of string > 4)
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "mystring.h"


  /* It's a const, it must be initialised */
const unsigned short b_LUCKY = 1<<10 ;


size_t mystrlen( const char* s ) 
{
	size_t rv = 0 ;

	// ...
//	while (s[rv] != '\0')
//		rv++;
	rv = strlen(s);

	return rv ;
}
void mystrcpy(char* t, const char* s)	{
	int i;
	for ( i =0 ; s[i] != '\0'; i++)
		t[i] = s[i];
	t[i] = '\0';
	//strcpy(t,s);
}
void mystrcat( char* t, const char* s)	{
	size_t i = mystrlen(t);
	for ( int x = 0 ; s[x] != '\0'; x++, i++)
		t[i] = s[x];
	t[i] = '\0';
//	strcat(t,s);
}
/*
int main()	{
	char *s1 = "Hello"; 
	char *s2=" Khoa";
	printf ("String length of s1 is: %ld\n", mystrlen(s1));
	char s3[100];
	mystrcpy(s3,s1);
	printf ("String copied is: %s\n",s3);
	mystrcat(s3,s2);
	printf ("String cat is: %s\n", s3);
	return 0;
}
*/
