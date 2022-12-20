/*********************************************************
 * readlines.c - reads until blank line or EOF
 *
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buff = NULL ;
	size_t len ;
	int cnt = 0 ;

	while( getline( &buff, &len, stdin ) > 1 )
	{
		++cnt ;
	}	
	double arr[cnt] = {0};
   for (int i = 0; i < cnt; i++)  {
      arr[i]=atof(*buff[i]);
      printf ("%lf",arr[i]);
		fflush();
   }
 
	printf( "\nEnd of input detected.  I read %d lines.\n", cnt ) ;

	free( buff ) ;
	return 0 ;
}
