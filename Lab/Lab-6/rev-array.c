/**********************************
 * rev-array: read doubles from stdin, one per line, until EOF or blank line. Copy the numbers to a second array of just the right size, reversing order of the numbers.
 * 
 *Khoa Nguyen
 * 10/29
 *5.4.0-125-generic x86_64 GNU/Linux
 * gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
 *
*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Becuase this gcc version doesn't support strrev, so this strrev() use to reverse string
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main ()	{
	char *buff = NULL;
	double arr_temp[100];
	size_t len;
	int cnt=0;
	
	while (getline(&buff,&len,stdin)>1)	{
		double temp;
		buff = strrev(buff);
		sscanf(buff,"%lg",&temp);
		arr_temp[cnt] = temp;
		++cnt;
	}
	printf ("There is %d numbers in array\n", cnt);
	printf ("The last number is %lf\n", arr_temp[cnt-1]);
	free(buff);
	return 0;
}

