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

struct node *insertAtBegin(struct node *head,int n){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = n;
	temp->next = head;
	return temp;
}

void insertAtEnd(struct node *head,int n){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = n;
	while(head->next != NULL){
		head = head->next;
	}

	head->next = temp;
	temp->next = NULL;
}

void insertAtMiddle(struct node *head,int pos,int n){
	int ct = 0;
	while(head != NULL){
		ct++;
		if(ct == pos){
			struct node *temp =(struct node *)malloc(sizeof(struct node));
			temp->data = n;
			temp->next = head->next;
			head->next = temp;
			return ;
		}
		else{
			head = head->next;
		}
	}
}


int main()
{
	int ar[] = {5,10,15,20,25};

	struct node *head = createLinkedList(ar,5);

	head = insertAtBegin(head,1);

	struct node *temp = head;
	struct node *newHead = head;

	insertAtEnd(temp,30);

	insertAtMiddle(head,3,12);

	while(newHead != NULL){
		printf("%d   ",newHead->data);
		newHead = newHead->next;
	}
}
