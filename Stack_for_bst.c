//Program Name:	stack for BST(Binary Search Tree)
//Date:		05th Oct 2013
//Author: 	Kashinath Chillal
//Venue: 	IIIT Bangalore

#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node* next;
};

struct snode {
struct node* data;
struct snode* next;
};
//struct node *top;

int push_stack(struct node** top,int data);
int display_stack(struct snode** stop,struct node** top);
int pop_stack(struct node** top);


int spush_stack(struct snode*** stop,struct node* data);
int sdisplay_stack(struct snode** stop);
struct node* spop_stack(struct snode*** stop);


int main(int argc, char *argv[])
{
int ch=0,num=0;
char choice;
struct node* top;
struct snode* stop;
top=NULL;	//Initialization of the top pointer
stop=NULL;

  do{
	printf("\nPlease Enter you choice:");
	printf("\n1:push");
	printf("\n2:Display");
	printf("\n3:pop");
	printf("\n4:Display sstack");
	scanf("%d",&ch);
	printf("\nYour choice is %d",ch);
	switch(ch)
	{
	case 1:printf("\nEnter the number to push:");
		scanf("%d",&num);
		push_stack(&top,num);
		break;
	  
	case 2:display_stack(&stop,&top);
		break;

	case 3://printf("\nEnter the number to pop:");
		//scanf("%d",&num);
		printf("\n%d is popped",pop_stack(&top));
		break;
	case 4:sdisplay_stack(&stop);
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

int display_stack(struct snode** stop,struct node** top)
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
		spush_stack(&stop,temp);
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	spush_stack(&stop,temp);	
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

int spush_stack(struct snode*** stop,struct node* data)
{
	struct snode *temp;
	temp=(struct snode *)malloc(sizeof(struct snode ));

	temp->data=data;
	temp->next=NULL;


	if(**stop==NULL)
	{
		**stop=temp;
	}
	else
	{
	  temp->next=**stop;
	  **stop=temp;
	}
return 0;
}

int sdisplay_stack(struct snode** stop)
{
	struct snode *temp;
	struct node *temp2;
	
if(*stop==NULL)
{
	printf("\nThe sstack is empty.");	
	return 0;
}
else
{
	temp=*stop;
	printf("\n");
	//while(temp->next!=NULL)
	while(temp!=NULL)
	{
		temp2 = spop_stack(&stop);
		while(temp2!=NULL)		
		{
			printf("%d\t",temp2->data);
			temp2=temp2->next;
		}
		printf("\n");
		temp=temp->next;
	}
	//temp2 = spop_stack(&stop);
}	//printf("%d\t",temp2->data);
return 0;

}

struct node* spop_stack(struct snode*** stop)
{
struct snode* cur;
struct snode* temp;
struct node* data;

//int data=0;


cur = **stop;
temp = cur;

if(cur==NULL)
	{
	  printf("\nThe sstack is empty. Can't pop.");
	  return NULL;
	}
else 
	
		if(cur->next==NULL)
		{
			data=cur->data;			
			**stop=NULL;
//			free(temp);
			return data;
		}		
		else
		{
			data=cur->data;
			cur=cur->next;
			**stop=cur;
//			free(temp);
	//		printf("\nThe Link is empty after deletion.");
			return data;
		}
//		free(cur);

}
