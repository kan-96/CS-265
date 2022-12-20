/***-*-C-*-****************************************
 * triangles.c -- Given leg dimension, integer n, prints out 4 right triangles
 *
 * Khoa Nguyen, Yahmin Haj
 * 10/27
 *
 * 
 * 5.4.0-125-generic x86_64 GNU/Linux
 * gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
 *****************************************************/

#include <stdio.h>

void lr( size_t n )
{
	for (size_t i =0; i < n ;i++)	{
		for (size_t j =0 ; j <n-i ; j++)
			fputs(" ",stdout);
		for (size_t j =0 ; j<=i; j++)
			fputs("*",stdout);
		fputs("\n",stdout);
	}
}

void ll( size_t n )
{
	for (size_t i =0; i < n; i++)	{
		for (size_t j = 0; j<=i ; j++)	
			fputs("*",stdout);
		fputs("\n",stdout);
	}
}

void ul( size_t n )
{
	for (size_t i = n ; i >0 ; i--)	{
		for (size_t j = 0; j<i ; j++)	
			fputs("*",stdout);
		fputs("\n",stdout);
	}
}

void ur( size_t n )
{
	for (size_t i =n; i >0 ;i--)	{
		for (size_t j =0 ; j <n-i ; j++)
			fputs(" ",stdout);
		for (size_t j =0 ; j<i; j++)
			fputs("*",stdout);
		fputs("\n",stdout);
	}
}

int main( int argc, char* argv[] )
{
	size_t  n ;

	sscanf( argv[1], "%zu", &n ) ;

	fprintf( stderr, "\n### We got a %zu for n\n", n ) ;

	fputs( "\n", stdout ) ;
	ll( n ) ;
	fputs( "\n", stdout ) ;
	lr( n ) ;
	fputs( "\n", stdout ) ;
	ul( n ) ;
	fputs( "\n", stdout ) ;
	ur( n ) ;
	fputs( "\n", stdout ) ;

	return 0 ;
}
