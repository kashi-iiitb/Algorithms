#include<stdio.h>
#include<stdlib.h>
#define N 100

int n=100;

int main(int argc, char *argv[])
{

int i,j,a[N];
int temp=0;

srand(120);

for(i=0;i<N;i++)
  a[i]=rand()%100;

if(insertion_sort(a)==0)
{
  for(i=0;i<N;i++)
    printf("%d\t",a[i]);
}
else
    printf("bubble sort unsuccessful!!!\n");
/*
if(selection_sort(a)==0)
{
  for(i=0;i<N;i++)
    printf("%d\t",a[i]);
}
else
    printf("bubble sort unsuccessful!!!\n");
*/
/*
if(bubble_sort(a)==0)
{
  for(i=0;i<N;i++)
    printf("%d\t",a[i]);
}
else
    printf("bubble sort unsuccessful!!!\n");
*/
return 0;
}

/*int bubble_sort(int *a)
{
int i=0,j=0,temp=0;
for(i=0;i<N-1;i++)
  for(j=0;j<N-i-1;j++)
	if(a[j]>a[j+1])
	  {
		temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
	  }
return 0;
}*/

//Bubble sort algorithm
int bubble_sort(int *a)
{
int i=0,j=0,temp=0;
for(i=0;i<N-1;i++)
  for(j=0;j<N-i-1;j++)
	if(*(a+j)>*(a+j+1))
	  {
		temp=*(a+j);
		*(a+j)=*(a+j+1);
		*(a+j+1)=temp;
	  }
return 0;
}

//Selection sort algorithm
int selection_sort(int *a)
{
int i=0,j=0,k=0,temp=0;
for(i=0;i<N-1;i++)
{
  k=0;
  for(j=1;j<N-i;j++)
	if(*(a+j)>*(a+k))
	  {
		k=j;
	  }
  
  {
	temp=*(a+j-1);
	*(a+j-1)=*(a+k);
	*(a+k)=temp;
  }
}
}

//Insertion sort algorithm
int insertion_sort(int *a)
{
int i=0,j=0,k=0,temp=0;
int key=0;

for(i=1;i<=N-1;i++)
{
  key=a[i];
  for(j=i;j>0;j--)
	//if(*(a+j)<*(a+j-1))
	if(key<*(a+j-1))
  	{
		/*temp=*(a+j-1);
		*(a+j-1)=*(a+j);
		*(a+j)=temp;*/
		*(a+j)=*(a+j-1);
  	}
	else
	  break;

	a[j]=key;
}
return 0;
}
