/************************************ 
 *func1.c - take input from stdin, then put in array and calculate arithmetic mean of array
 *
 *Khoa Nguyen
 *11/5/2022
 *5.4.0-125-generic x86_64 GNU/Linux
 *gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
 ***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double arrAvg( double *s, size_t sizeArr)	{
	double ans;
	for (int i =0; i < sizeArr; i++)
		ans+=s[i];
	ans = ans/sizeArr;
	return ans;
}
int main ()	{
	char *buff = NULL;
	size_t cnt =0;
	size_t len;
	double s[100];
	while (getline(&buff,&len,stdin)>1)	{
		double temp;
		sscanf(buff,"%lf",&temp);
		s[cnt] = temp;
		++cnt;
	}
	double ans = arrAvg(s,cnt);
	printf ("User entered: \t%ld numbers\n", cnt);	
	printf ("The mean is: \t%lf\n", ans);
	free(buff);
	return 0;

}	

