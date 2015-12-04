//Program Name:	Merge algorithm
//Date:		14th Aug 2013
//Author: 	Kashinath Chillal
//Venue: 	IIIT Bangalore

#include<stdio.h>
#include<stdlib.h>

void shell_sort(int a[],int n);

int main(int argc, char *argv[])
{
//int a[10]={21,14,8,36,47,11,74,5,38,45};
int n=10,i,j;
int temp=0,gap=0;


 int *a;

    a = (int *)malloc((argc - 1) * sizeof(int));
    for (i = 0; i < argc - 1; i++)
        a[i] = atoi(argv[i + 1]);

	for (i = 0; i < argc - 1; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    shell_sort(a, argc-1);

    for (i = 0; i < argc - 1; i++)
        printf("%d ", a[i]);
    printf("\n");

    free(a);
}

void shell_sort(int a[],int n)
{
int i,j,temp=0,gap;

for(gap=n/2;gap>0;gap=gap/2)
{  
//printf("Gap value is %d\n",gap);
	for(i=gap;i<n;i++)
	{
	  j=i;
	  temp=a[i];
	  while((j>=gap) && (a[j-gap]>a[j]))
	  {
		a[j]=a[j-gap];
		j=j-gap;
	  	a[j]=temp;
	  }
	  
	}
	
}  
}


