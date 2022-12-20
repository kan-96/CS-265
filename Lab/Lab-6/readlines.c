/*********************************************************
 * readlines.c -read numbers (doubles) from the user, prompting for each one. (So, blank line or EOF to quit.) After all inputs are read, print out, in neat, tabular form, the max, min, and mean.
 *Khoa Nguyen
 * 10/29
 *5.4.0-125-generic x86_64 GNU/Linux
 * gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
 *
*******************************************************/

#include <stdio.h>
#include <stdlib.h>
//functrion uses to find maximun number
double MAX(double a, double b)	{
	if ( a > b)	return a;
	return b;
}
//function uses to dinf minimum number
double MIN(double a, double b)	{
	if (a < b)	return a;
	return b;
}
int main()
{
	char *buff = NULL ;
	size_t len ;
	int cnt = 0 ;
	double max=0.0, min=0.0, mean=0.0;

	while( getline( &buff, &len, stdin ) > 1 )
	{
		double temp;
		sscanf (buff,"%lf",&temp);
		if (cnt == 0) {
			min = temp; 
			max = temp;
		}
		min = MIN(min,temp);
		max = MAX(max,temp);
		mean += temp;
		++cnt ;
	}
	mean /=cnt;
	printf ("Max\t|Min\t|Mean\t\n");
	printf ("%4.2lf\t|%4.2lf\t|%4.2lf\t\n",max,min,mean);

	free( buff ) ;
	return 0 ;
}
