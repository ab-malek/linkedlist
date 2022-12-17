#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *createLinkedList(int ar[],int n){
	struct node *head = NULL, *temp = NULL, *current = NULL;

	int i;
	for(i=0;i<n;i++){
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = ar[i];

		if(head == NULL){
			head = temp;
			current = temp;
		}
		else{
			current->next = temp;
			current = temp;
		}
	}
	current->next = NULL;
	return head;
}


int main()
{
	int ar[] = {5,10,15,20,25};

	struct node *head = createLinkedList(ar,5);
	struct node *temp = head;

	while(temp != NULL){
		printf("%d   ",temp->data);
		temp = temp->next;
	}
}
