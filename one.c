#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *createLinkedList(int ar[],int n){
	struct Node *head = NULL, *temp = NULL, *current = NULL;
	int i;
	for(i=0;i<n;i++){
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data =  ar[i];
		temp->next = NULL;
		if(head == NULL){
			head = temp;
			current = temp;
		}
		else{
			current->next = temp;
			current = current->next;
		}

	}
	current->next = NULL;
	return head;
}

struct Node *insertNodeAtBegin(struct Node *head,int n){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = n;
	temp->next = head;
	return temp;
};

struct Node *insertNodeAtEnd(struct Node *current,int n){
	struct Node *head = current;
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = n;
	while(head->next != NULL){
		head = head->next;
	}

	head->next = temp;
	temp->next = NULL;
	return current;

};

void insertAtMiddle(struct Node *head,int pos,int n){
	int ct = 0;
	while(head != NULL){
		int k = head->data;
		if(k == pos){
			struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

			temp->data = n;
			temp->next = head->next;
			head->next = temp;
			return;
		}
		else{
			head = head->next;
		}
	}
}


int main()
{
	int ar[] = {3,5 ,9,15};

	struct Node *head = createLinkedList(ar,4);

	struct Node *current = insertNodeAtBegin(head,2);
	current = insertNodeAtEnd(current,222);
	head = current;
	insertAtMiddle(current,5,123);

	while(current != NULL){
		printf("%d\n",current->data);
		current = current->next;
	}
}
