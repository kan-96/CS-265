#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// capitalise take in an array of char, then convert all lowercase leet to uppercase
//using islower() to identify lower case letter, and the ntoupper to uppercase letter.
void capitalise(char *s) {
   int len =0;
   while (*(s+len)) {
      len++;
   }
   for (int i=0 ; i < len; i++)  {
      char temp = *(s+i);
      if (islower(temp))
         *(s+i) = toupper(temp);
   }

}
//binSearch funtion, take in an array of number(n) of interger
//return number of index of targert element
int binSearch (int target, int *array, size_t n)	{
	int low = 0;
	int high = n-1;
	int mid;
	while (high - low > 1)	{
		mid = (high + low) /2 ;
		if (array[mid] < target)
			low = mid +1;
		else
			high = mid;
	}
	if (array[low] == target)
		return low+1;
	else if (array[high] == target)
		return high+1;
	else
		return -1;
}
//arrStats takes array of doubles, along with array length(size_t)
// then calculat mean max min as double
void arrStats(double* mean, double* max, double* min, double *s, size_t n)	{
	*max = *(s+0);
	*min = *(s+0);
	*mean =*(s+0);
	for(int i=0; i < n; i++)	{
		*max = *(s+i) > *max ? *(s+i) : *max;
		*min = *(s+i) < *min ? *(s+i) : *min;
		*mean += *(s+i);
	}
	*mean = *mean/n;
}
//arrFind take an array and target interger
//return address of target interger
int* arrFind( int* arr, size_t n, int target)	{
	int* temp = NULL;
	for (int i=0 ; i < n ;i++)	{
		if (*(arr+i) == target)
			temp = arr +i;
	}
	return temp;
}

int main() {
  /*char str[] = "Hello, HOW are You?";
    capitalise(str);
    printf("%s\n", str);
    return 0;*/
	int array[11] = {0,1,2,5,8,10,52,65,77,99,10};
	size_t n =11;
	int target = 1;
	int *ans = arrFind(array, n, target);
	printf ("Adress of number %d is %p\n", target, ans);
	return 0;
	/*double s[5] = {2.56,2.88,5.98,9.99,7.77};
	size_t n =5;
	double mean,max,min;
	arrStats(&mean,&max,&min,s,n);
	printf ("Mean: \t%lf | max: \t%lf | min: \t%lf\n", mean,max,min);
	return 0;
	*/
	
}
