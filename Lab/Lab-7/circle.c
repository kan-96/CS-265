/************************************
 *circle.c, which expects two command-line arguments, a name (as a string), and a radius (a double). You will then print the circle's name and area.
 *
 *Khoa Nguyen
 *11/5/2022
 *5.4.0-125-generic x86_64 GNU/Linux
 *gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
 ***************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, char* argv[] )	{
	if (argc == 3)	{
		// if user put in 2 argument, convert 2nd argument to double;
		//calculate area
		char *ptr;
		double radius = strtod(argv[2],&ptr);
		double area = M_PI*radius*radius;
		printf ("%s, your area is %.4lf unit square\n", argv[1], area);
	}
	else {
		fprintf (stderr,"%s", "Need 2 arguments, a name and radius.\n");
		return -1;
	}
	return 0;
}
