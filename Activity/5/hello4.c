/*
 *hello4 - the program that prompts the user for a float, stored it as double and print its out
 * Khoa Nguyen
 * 10/18
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()	{
	double num ;
 	printf ("Please enter a float number (x.xx): ");
 	fflush(stdout);
	scanf ("%lf",&num);
 	printf ("The float number the user enterd in is : %lf\n", num);
 	return 0;
}
