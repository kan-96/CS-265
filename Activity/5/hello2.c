/*
 *hello2 - the program used printf to personalise the message inclunding the client's usename.
 * Khoa Nguyen
 *10/18/2022
 */

#include <stdio.h>
#include <stdlib.h>

int main ()	{
	char *user = NULL;
	user = getenv("USER");
	printf ("Hello, there, %s\n",user);
	
	return 0;
}
