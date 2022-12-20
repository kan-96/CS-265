
/*********************************************************
 * sd.c 0: Write a program which reads floats, one per line, stores them in an array. After input, compute and print the mean and standard deviation of the collection. You may assume that there will be no more than 100 inputs 
 * Khoa Nguyen, Yahmin Haj
 * 10/27
 * 
 *5.4.0-125-generic x86_64 GNU/Linux 
 *gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
 ******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   char *buff = NULL ;
   size_t len ;
   int cnt = 0 ;
	double sum, sum_dev;
	float arr[100];

   while( getline( &buff, &len, stdin ) > 1 )
   {
		float temp;
		sscanf(buff,"%f",&temp);
		arr[cnt] = temp;
      ++cnt ;
   }
	for (int i = 0; i < cnt; i++)	{

		sum += arr[i];
	}

	double mean = sum/cnt;
	printf ("Mean: %f\n",mean);
	for (int i=0; i < cnt ; i++)	{
		sum_dev += pow((arr[i]- mean),2);
	}
	sum_dev /=cnt;
	sum_dev = sqrt(sum_dev);
	printf ("Standard Deviation: %f\n",sum_dev);
   free( buff ) ;
   return 0 ;
}
