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

//struct node *head;

int insert_ll(struct node** head,int data);
int display_ll(struct node** head);
int delete_ll(struct node** head,int data);


int main(int argc, char *argv[])
{
int ch=0,num=0;
char choice;
struct node* head;
head=NULL;	//Initialization of the head pointer

  do{
	printf("\nPlease Enter you choice:");
	printf("\n1:Insert");
	printf("\n2:Display");
	printf("\n3:Delete");
	scanf("%d",&ch);
	printf("\nYour choice is %d",ch);
	switch(ch)
	{
	  case 1:printf("\nEnter the number to insert:");
		scanf("%d",&num);
		insert_ll(&head,num);
		break;
	  
	  case 2:display_ll(&head);
		break;

	  case 3:printf("\nEnter the number to delete:");
		scanf("%d",&num);
		delete_ll(&head,num);
		break;
	}
	getchar(); //Extra getchar() to bypass newline character in input buffer
	printf("\nDo you want to continue (y/n)");
	scanf("%c",&choice);
    }while(choice=='y'||choice=='Y');
}

int insert_ll(struct node** head,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node ));

	temp->data=data;
	temp->next=NULL;

	if(*head==NULL)
	{
	   *head=temp;
		printf("Creation of root node\n");
	}
	else
	{
	  temp->next=*head;
	  *head=temp;
	}
return 0;
}

int display_ll(struct node** head)
{
	struct node *temp;
//	temp=(struct node *)malloc(sizeof(struct node ));
	
if(*head==NULL)
{
	printf("\nThe list is empty.");	
	return 0;
}
	temp=*head;
	printf("\n");
	while(temp->next!=NULL)
	{
	printf("%d\t",temp->data);
	temp=temp->next;
	}
	printf("%d\t",temp->data);
return 0;

}

int delete_ll(struct node** head,int data)
{
struct node* cur;
struct node* temp;
struct node* prev;


cur = *head;

if(cur==NULL)
	{
	  printf("\nThe Link List is empty. Can't delete.");
	  return 0;
	}
else 
	if(cur->data==data) //&& cur->next==NULL)
	{
		if(cur->next==NULL)
		{
			*head=NULL;
			free(cur);
			return 0;
		}		
		else
		{
			cur=cur->next;
			*head=cur;
	//		printf("\nThe Link is empty after deletion.");
			return 0;
		}
//		free(cur);
	}
	else
		if(cur->next==NULL)
		{
			printf("\nElement not found.");			
			return 0;
		}

prev = cur;
cur = cur->next;

while(cur->data!=data && cur!=NULL)
{
  prev = cur;
  cur = cur->next;
    
  if(cur==NULL)
     break;

}
if(cur==NULL)
{
	printf("\nElement not found.");
	return 0;
}
else
{
  	prev->next=cur->next;
  	free(cur);
	printf("\nDeletion successful!!");
	return 0;
}

}

