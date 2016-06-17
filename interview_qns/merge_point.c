#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

int get_len(struct node *ptr)
{
	int count = 0;
	while(ptr!=NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}

int main()
{
	struct node *head1=NULL;
	struct node *head2=NULL;
	struct node *temp = (struct node*) malloc (sizeof(struct node));
	temp->data=30;
	temp->next=NULL;
	head1 = temp;
	head2 = temp;
	temp = (struct node*) malloc (sizeof(struct node));
	temp->data=15;
	temp->next=head1;
	head1 = temp;
	head2 = temp;

	temp = (struct node*) malloc (sizeof(struct node));
	temp->data=10;
	temp->next=head1;
	head1 = temp;

	temp = (struct node*) malloc (sizeof(struct node));
	temp->data=9;
	temp->next=head2;
	head2 = temp;

	temp = (struct node*) malloc (sizeof(struct node));
	temp->data=6;
	temp->next=head2;
	head2 = temp;

	//display the list contents
	printf("The contents of 1st list:\n");
	struct node *ptr1 = head1;
	struct node *ptr2 = head2;
	while(ptr1!=NULL)
	{	printf("%d \n",ptr1->data);
		ptr1=ptr1->next;
	}

	printf("The contents of 2nd list:\n");
	ptr2 = head2;
	while(ptr2!=NULL)
	{	printf("%d \n",ptr2->data);
		ptr2 = ptr2->next;
	}	

	ptr1 = head1;
	ptr2 = head2;
	int len1=0, len2 =0;
	len1 = get_len(head1);
	len2 = get_len(head2);
	int diff =0;
	if(len1>len2)
	{
		diff = len1-len2;
		for(int i=0;i<diff;i++)
			ptr1 = ptr1->next;	
	}
	else
	{
		diff = len2-len1;
		for(int i=0;i<diff;i++)
			ptr2 = ptr2->next;	
		
	}
		printf("%d \n",ptr1->data);
		printf("%d \n",ptr2->data);

	while((ptr1!=ptr2)&&(ptr1!=NULL)&&(ptr2!=NULL))
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}	
	
	if(ptr1!=NULL)
		printf("The linked lists merge at %d.\n", ptr1->data);
	else
		printf("The linked lists dont merge.\n");
	return 0;	
}
