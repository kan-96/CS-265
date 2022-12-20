/*
 * hello3- the program print the nu,ber of columns in the current section with name of user
 * Khoa Nguyen
 *10/18/2022
 */

#include <stdio.h>
#include <stdlib.h>

int main ()	{
	char *user = NULL;
	user = getenv("USER");
	char *t = NULL;
	t = getenv("COLUMNS");
	int cols;
	cols =atoi (t);
	printf ("Hello, there, %s!\t This terminal is %d columns wide.\n",user,cols);
	
	return 0;
}
