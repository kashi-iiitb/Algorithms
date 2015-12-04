//Program Name:	Merge sort algorithm
//Date:		14th Aug 2013
//Author: 	Kashinath Chillal
//Venue: 	IIIT Bangalore

#include<stdio.h>
#include<stdlib.h>

void merge_sort(int a[],int first,int middle, int last);
int merge(int a[],int first,int middle,int last);

int arguments=0;

int main(int argc, char *argv[])
{
//int a[10]={21,14,8,36,47,11,74,5,38,45};
int first, middle,last;
int i;
 int *a;

arguments=argc-1;  
  a = (int *)malloc((arguments) * sizeof(int));
    for (i = 0; i < arguments; i++)
        a[i] = atoi(argv[i + 1]);

	for (i = 0; i < arguments; i++)
        printf("%d ", a[i]);
    printf("\n");
    
first=0;
last=argc-2;
middle=(first+last)/2;

    //merge_sort(first,middle,last,a);
  merge_sort(a,first,middle,last);
 //merge(a,first,middle,last);

    for (i = 0; i < arguments; i++)
        printf("%d ", a[i]);
    printf("\n");

    free(a);
}

void merge_sort(int a[],int first, int middle, int last)
{
	if(first<last)
	{
	
		merge_sort(a,first,(first+middle)/2,middle);
		merge_sort(a,middle+1,(last+middle)/2,last);
		merge(a,first,middle,last);
	}
}

int merge(int a[],int first,int middle,int last)
{
	int i=0,j=0,k=0;
	int *temp;
	i=first;
	j=middle+1;

temp = (int *)malloc((arguments) * sizeof(int));

	while(i<=middle&&j<=last)
	{
		if(a[i]>a[j])
			temp[k++]=a[j++];
		else
			temp[k++]=a[i++];	
	}
	while(i<=middle)
		temp[k++]=a[i++];
	while(j<=last)
		temp[k++]=a[j++];

	k=0;
	for(i=first;i<=last;i++)
	{
		a[i]=temp[k++];
	}
return 0;
}
