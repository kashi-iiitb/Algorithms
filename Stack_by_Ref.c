//Program Name:	Linked List
//Date:		17th Sep 2013
//Author: 	Kashinath Chillal
//Venue: 	IIIT Bangalore

#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node* next;
};

//struct node *top;

int push_stack(struct node** top,int data);
int display_stack(struct node** top);
int pop_stack(struct node** top);


int main(int argc, char *argv[])
{
int ch=0,num=0;
char choice;
struct node* top;
top=NULL;	//Initialization of the top pointer

  do{
	printf("\nPlease Enter you choice:");
	printf("\n1:push");
	printf("\n2:Display");
	printf("\n3:pop");
	scanf("%d",&ch);
	printf("\nYour choice is %d",ch);
	switch(ch)
	{
	  case 1:printf("\nEnter the number to push:");
		scanf("%d",&num);
		push_stack(&top,num);
		break;
	  
	  case 2:display_stack(&top);
		break;

	  case 3://printf("\nEnter the number to pop:");
		//scanf("%d",&num);
		printf("\n%d is popped",pop_stack(&top));
		break;
	}
	getchar(); //Extra getchar() to bypass newline character in input buffer
	printf("\nDo you want to continue (y/n)");
	scanf("%c",&choice);
    }while(choice=='y'||choice=='Y');
}

int push_stack(struct node** top,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node ));

	temp->data=data;
	temp->next=NULL;

	if(*top==NULL)
	{
	   *top=temp;
		printf("First node pushed into stack\n");
	}
	else
	{
	  temp->next=*top;
	  *top=temp;
	}
return 0;
}

int display_stack(struct node** top)
{
	struct node *temp;
//	temp=(struct node *)malloc(sizeof(struct node ));
	
if(*top==NULL)
{
	printf("\nThe stack is empty.");	
	return 0;
}
	temp=*top;
	printf("\n");
	while(temp->next!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("%d\t",temp->data);
return 0;

}

int pop_stack(struct node** top)
{
struct node* cur;
struct node* temp;
struct node* prev;
int data=0;


cur = *top;
temp = cur;

if(cur==NULL)
	{
	  printf("\nThe stack is empty. Can't pop.");
	  return -1;
	}
else 
	
		if(cur->next==NULL)
		{
			data=cur->data;			
			*top=NULL;
			free(temp);
			return data;
		}		
		else
		{
			data=cur->data;
			cur=cur->next;
			*top=cur;
			free(temp);
	//		printf("\nThe Link is empty after deletion.");
			return data;
		}
//		free(cur);

}

