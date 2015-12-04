#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
//int a[10]={21,14,8,36,47,11,74,5,36,45};
int n=10,i,j,a[10];
int temp=0;

//srand(100);

for(i=0;i<n;i++)
  a[i]=rand()%100;

for(i=0;i<n-1;i++)
  for(j=0;j<n-i-1;j++)
	if(a[j]>a[j+1])
	  {
		temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
	  }

for(i=0;i<n;i++)
  printf("%d\t",a[i]);

return 0;
}


