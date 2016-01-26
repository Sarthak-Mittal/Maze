#include<stdio.h>
#include "random.c"

int main()
{
int i,*p;
int ranArr[4];
  p = rand_arr();
	
   for ( i = 0; i < 4; i++ ) 
   {
      ranArr[i] = *(p + i);  
	printf("%d",*(p+i));
   }

}
