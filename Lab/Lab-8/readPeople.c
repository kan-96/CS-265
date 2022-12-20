/**********************************************************************************
 * readPeople.c - Reads people (max 100), fills in array
 *
 * NOTES:
 *  - Input is:
 *    last
 *    first
 *    age
 *   , no blank lines.
 *	- Assume that input is valid (if you find a last name, then there are 2 more lines)
 *  - Input is terminated w/a blank line or EOF
 * 
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define CAP 100

typedef struct
{
	char first[10] ;
	char last[20] ;
	int age ;
} person ;

	// reads people from file handle f, format described above
	// a must be large enough to hold all entries
void readPeople( person* a[], FILE* f ) ;

	// Returns heap memory pointed to by elements of a
	// a is of size n
	// Elements point to a person, or are NULL
void freePeople( person* a[], size_t n ) ;

int main( int argc, char **argv )
{
	FILE *fin = stdin ;

	person* team[CAP] = { NULL } ; /* rest are initialised to 0 */

	if( argc>1 ) {
		fin = fopen( argv[1], "r" ) ;
		if( fin == NULL ) {
			fprintf( stderr, "Couldn't open %s for reading.  Exiting. ", argv[1] ) ;
			exit( 1 ) ;
		}
	}

	readPeople( team, fin ) ;

	freePeople( team, CAP ) ;

	return 0 ;
}

void readPeople( person* a[], FILE* f ) 
{
	char *buff = NULL ;
	size_t len ;
	size_t cnt = 0 ;

	while( getline( &buff, &len, f ) > 1 ) 
	{
		// We read a last name (with the newline)
		// - get memory for person
		a[cnt] = (person*)malloc(sizeof(person));
		// - append to array
		sscanf(buff,"%s", a[cnt]->last);
		// - read next 2 lines, fill it in 
		// read first name
		getline(&buff,&len,f);
		sscanf(buff,"%s", a[cnt]->first);
		// read age
		getline(&buff,&len,f);
		sscanf(buff,"%d", &a[cnt]->age);
		fprintf (stdout, "Last name: %s ; First name: %s ; Age %d", a[cnt]->last, a[cnt]->first, a[cnt]->age);
		//free (a[cnt]);
		++cnt ;
	}

	free( buff ) ;
}

void freePeople( person* a[], size_t n ) 
{
	// Do NOT assume array is dense.  Check every element
	size_t i =0 ;
	while (a[i] != NULL && i < n)	{
		free(a[i]);
		i++;
	}
}
