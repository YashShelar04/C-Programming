#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{int a[50], n, i, large;

 printf("Enter array size \n");
 scanf("%d", &n);
 printf("Enter array elements \n");
 for(i=0; i<n; i++)
 {scanf("%d", a[i]);}

 printf("\nArray elemnts are ");
 for(i=0; i<n; i++)
 {printf("%d ", a[i]);}

 large=a[0];
 for(i=0; i<n; i++)
 {  if(a[i]>large)
    {large=a[i];}
 }

 printf("\n%d is the largest array elemnt", large);
 return 0;

}
