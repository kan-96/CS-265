/*
 * bills.c : a program use sancf and print to present the fewest numver of $20, $10, $5, and $1
 * Khoa Nguyen
 * 10/22
 * gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
 * 5.4.0-125-generic x86_64 GNU/Linux
 * EDITOR: columns = 95 , tabspace = 3
 */

 #include <stdio.h>
 #include <math.h>
 int main ()	{
	int b20, b10, b5 ,b1;
	int amount =0;
	printf ( "Enter a dolalr amount => ");
	scanf ("%d",&amount);
	b20 = amount%20;
	b20 = (amount - b20)/20;
	amount -= b20*20;
	b10 = amount%10;
	b10 = (amount - b10)/10;
	amount -= b10*10;
	b5 = amount%5;
	b5 = (amount - b5)/5;
	amount -=b5*5;
	b1 = amount;
	printf ("\n");
	printf ("$20 bills: %5d\n", b20);
	printf ("$10 bills: %5d\n", b10);
	printf ("$ 5 bilss: %5d\n", b5);
	printf ("$ 1 bilss: %5d\n", b1);
	return 0;
}
