//Program Name:	Quick sort algorithm
//Date:		14th Aug 2013
//Author: 	Kashinath Chillal
//Venue: 	IIIT Bangalore

#include<stdio.h>
#include<stdlib.h>

void quick_sort(int a[],int first, int last);
int partition(int a[],int first,int last);

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
//middle=(first+last)/2;

    //merge_sort(first,middle,last,a);
 quick_sort(a,first,last);
 //merge(a,first,middle,last);

    for (i = 0; i < arguments; i++)
        printf("%d ", a[i]);
    printf("\n");

    free(a);
}

/*
void quick_sort(int x[],int first,int last){
    int pivot,j,temp,i;
 
     if(first<last){
         pivot=first;
         i=first;
         j=last;
 
         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }
 
         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quick_sort(x,first,j-1);
         quick_sort(x,j+1,last);
 
    }
}
*/

void quick_sort(int a[],int first, int last)
{

int q=0;
	
	if(first<last)
	{
		q=partition(a,first,last);
		quick_sort(a,first,q-1);
		quick_sort(a,q+1,last);		
	}
}

int partition(int a[],int first,int last)
{
	int i=first,j=last,k=0,pivot=first;
	int temp;
	//i=first;
	//j=middle+1;

//temp = (int *)malloc((arguments) * sizeof(int));

  while(i<j)
  {
	while(a[i]<=a[first]&&i<last)	//a[first] is considered pivot element
	{
		i++;
	}

	while(a[j]>a[first])//&&j>=first)	//a[first] is considered pivot element
	{
		j--;
	}
	
	if(i<j)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	else
	{
		
	pivot=j;
	}
  }
	temp=a[j];
	a[j]=a[first];
	a[first]=temp;

return j;
}
