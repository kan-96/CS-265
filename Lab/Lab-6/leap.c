/*
 * leap.c - take input from usser and print yes if number is a leap yeat, no othewise
 *Khoa NGuyen
 *10/29
 *5.4.0-125-generic x86_64 GNU/Linux
 *gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
 *EDITOR: columns : 109, tabstop :3
 */

#include <stdio.h>

int main ()		{
	int year =0;
	printf ("Enter year number: ");
	scanf("%d",&year);
	if ( !(year%4) && (year%100) )
		printf ("YES\n");
	else
		printf ("NO\n");
return 0;
}
