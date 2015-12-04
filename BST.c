//Program Name:	Binary Search Tree
//Date:		04th Oct 2013
//Author: 	Kashinath Chillal
//Venue: 	IIIT Bangalore

#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node* left;
struct node* right;
struct node* parent;
};

struct snode {
struct node* data;
struct snode* next;
};

//struct node *head;

int insert_bst(struct node** head,int data);
int display_bst(struct node** head);
//int delete_bst(struct node** head,int data);
int in_traverse(struct node* temp_ptr);
int nr_display_bst(struct node** head);

int spush_stack(struct snode** top,struct node* data);
int sdisplay_stack(struct snode** top);
struct node* spop_stack(struct snode** top);




int main(int argc, char *argv[])
{
int ch=0,num=0;
char choice;
struct node* head;
head=NULL;	//Initialization of the head pointer

//struct snode* stop;
//stop=NULL;

  do{
	printf("\nPlease Enter you choice:");
	printf("\n1:Insert");
	printf("\n2:Recursive Display");
	printf("\n3:Non Recursive Display");
	scanf("%d",&ch);
	printf("\nYour choice is %d",ch);
	switch(ch)
	{
	  case 1:printf("\nEnter the number to insert:");
		scanf("%d",&num);
		insert_bst(&head,num);
		break;
	  
	  case 2:display_bst(&head);
		break;

	  case 3:
		nr_display_bst(&head);//printf("\nEnter the number to delete:");
		//scanf("%d",&num);
		//delete_bst(&head,num);
		break;
	}
	getchar(); //Extra getchar() to bypass newline character in input buffer
	printf("\nDo you want to continue (y/n)");
	scanf("%c",&choice);
    }while(choice=='y'||choice=='Y');
}

int insert_bst(struct node** head,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node ));

	struct node *xptr;
	struct node *yptr;

	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;


	if(*head==NULL)
	{
	   *head=temp;
		printf("Creation of root node\n");
	}
	else
	{
	  xptr=*head;
	  
	  while(xptr!=NULL)
	  {
		yptr=xptr;
		
		if(data < xptr->data)
			xptr=xptr->left;
		else
			xptr=xptr->right;
	  }
	  if(data < yptr->data)
		yptr->left = temp;
	  else
		yptr->right = temp;
		
	  printf("\nInsertion successful!!");
	}
return 0;
}

int display_bst(struct node** head)
{
	struct node *temp,*xptr;
//	temp=(struct node *)malloc(sizeof(struct node ));
	
if(*head==NULL)
{
	printf("\nThe list is empty.");	
	return 0;
}
	temp=*head;
	in_traverse(temp);
	printf("\n");
return 0;

}

int in_traverse(struct node* temp_ptr)
{
	if(temp_ptr!=NULL)
	{
		in_traverse(temp_ptr->left);
		printf("%d ",temp_ptr->data);
		in_traverse(temp_ptr->right);
	}
}

int nr_display_bst(struct node** head)
{
	struct snode* stop;
	struct node *temp;
	stop=NULL;
	temp=*head;
//	temp=(struct node *)malloc(sizeof(struct node ));
	
if(temp==NULL)
{
	printf("\nThe list is empty.");	
	return 0;
}
else
{
	while(1)
	{
	  while(temp)
	  {
		spush_stack(&stop,temp);
		temp=temp->left;		
	  }
	
	if(stop==NULL)
		break;
	temp = spop_stack(&stop);
	printf("%d\t",temp->data);
	temp = temp->right;

	}
	
}
return 0;

}

int spush_stack(struct snode** stop,struct node* data)
{
	struct snode *temp;
	temp=(struct snode *)malloc(sizeof(struct snode ));

	temp->data=data;
	temp->next=NULL;


	if(*stop==NULL)
	{
		*stop=temp;
	}
	else
	{
	  temp->next=*stop;
	  *stop=temp;
	}
return 0;
}

struct node* spop_stack(struct snode** stop)
{
struct snode* cur;
struct snode* temp;
struct node* data;

//int data=0;


cur = *stop;
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
			*stop=NULL;
//			free(temp);
			return data;
		}		
		else
		{
			data=cur->data;
			cur=cur->next;
			*stop=cur;
			return data;
		}

}


/*
int delete_bst(struct node** head,int data)
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
			printf("\nDeletion successful!!");			
			return 0;		
		}
		else
		{		
			cur=cur->next;
			*head=cur;
			//free(cur->prev);
			cur->prev=NULL;
			printf("\nDeletion successful!!");
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
	if(cur->next==NULL)	//Last note to be deleted
	{
		prev->next=NULL;
		free(cur);
		printf("\nDeletion successful!!");
	}
	else
	{
	  	prev->next=cur->next;
		(cur->next)->prev=prev;
	  	free(cur);
		printf("\nDeletion successful!!");
	}
	return 0;
}

}
*/
