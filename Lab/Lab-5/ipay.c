/*
 * ipay: calculate subtoal of bill with tax and tip for serve. and return them in double type.
 * Khoa Nguyen
 * 10/17
 * 
 *gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
 * 5.4.0-125-generic x86_64 GNU/Linux
 * EDITOR: columns = 95 tabspace =3
 */

#include <stdio.h>
#include <math.h>

int main ()	{
	double tax = 0.07, tip =0.22;
	double subtotal;
	printf ("The amount of user comsumed: ");
	scanf("%lf",&subtotal);
	
	subtotal = subtotal + subtotal*tax + subtotal*tip; 
	
	printf ("Total amount is:  %.2lf\n", subtotal);
	return 0;
}
