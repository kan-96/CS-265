/************************************
 *func2.c - Write a function called void int2string. writes the string into array pointed to by answer
 *
 *Khoa Nguyen
 *11/5/2022
 *5.4.0-125-generic x86_64 GNU/Linux
 *gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
 ***************************************/

#include <stdio.h>
#include <stdlib.h>

void int2string(int n, char* answer)	{
	// calculate length of array	
	int l =0;
	int temp1 = n;
	while (temp1>9)		{
		l +=1;
		temp1 = temp1/10;
	}
	l +=1;
	//covert int to  string 	
	for (int i = 0 ; i < l ; i++)	{
		int temp = n%10;
		answer[l-i-1] = (char) temp +'0';
		n = n/10;
	}
	answer[l] = '\0';
}
int main ()	{
	char *buff = NULL;
	size_t len;
	while (getline(&buff,&len,stdin)>1)	{
		int temp;
		char ans[10];
		sscanf(buff,"%d",&temp);
		int2string(temp,ans);
		printf ("int to String is: %s\n", ans);
		fflush(stdout);
	}
	free(buff);
	return 0;
}
