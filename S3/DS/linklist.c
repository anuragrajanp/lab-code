#include <stdio.h>
#include <stdlib.h>
struct node {
	int info;
	struct node* link;
};
struct node* start = NULL;
void createList()
{
	if (start == NULL) {
		int n;
		printf("\nEnter the number of nodes: ");
		scanf("%d", &n);
		if (n != 0) {
			int data;
			struct node* newnode;
			struct node* temp;
			newnode = malloc(sizeof(struct node));
			start = newnode;
			temp = start;
			printf("\nEnter number to be inserted : ");
			scanf("%d", &data);
			start->info = data;
			for (int i = 2; i <= n; i++) {
				newnode = malloc(sizeof(struct node));
				temp->link = newnode;
				printf("\nEnter number to be inserted : ");
				scanf("%d", &data);
				newnode->info = data;
				temp = temp->link;
			}
		}
		printf("\nThe list is created\n");
	}
	else
		printf("\nThe list is already created\n");
}
void traverse()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		printf("\nDisplaying elements : \n");
		while (temp != NULL) {
			printf("%d\n", temp->info);
			temp = temp->link;
		}
	}
}
void insertAtFront()
{
	int data;
	struct node* temp;
	temp = malloc(sizeof(struct node));
	printf("\nEnter number to be inserted : ");
	scanf("%d", &data);
	temp->info = data;
	temp->link = start;
	start = temp;
}
void insertAtEnd()
{
	int data;
	struct node *temp, *head;
	temp = malloc(sizeof(struct node));
	printf("\nEnter number to be inserted : ");
	scanf("%d", &data);
	temp->link = 0;
	temp->info = data;
	head = start;
	while (head->link != NULL) {
		head = head->link;
	}
	head->link = temp;
}
void insertAtPosition()
{
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = malloc(sizeof(struct node));                          
	printf("\nEnter position :");
	scanf("%d", &pos);
	printf("Enter the data : ");
	scanf("%d",&data);
	temp = start;
	newnode->info = data;
	newnode->link = 0;
	while (i < pos - 1) {
		temp = temp->link;
		i++;
	}
	newnode->link = temp->link;
	temp->link = newnode;
}
void deleteFirst()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		start = start->link;
		free(temp);
	}
}
void deleteEnd()
{
	struct node *temp, *prevnode;
	if (start == NULL)
		printf("\nList is Empty\n");
	else {
		temp = start;
		while (temp->link != 0) {
			prevnode = temp;
			temp = temp->link;
		}
		free(temp);
		prevnode->link = 0;
	}
}
void deletePosition()
{
	struct node *temp, *position;
	int i = 1, pos;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		printf("\nEnter index : ");
		scanf("%d", &pos);
		position = malloc(sizeof(struct node));
		temp = start;
		while (i < pos - 1) {
			temp = temp->link;
			i++;
		}
		position = temp->link;
		temp->link = position->link;
		free(position);
	}
}
int main()
{
	int choice;
	while (1) {
                printf("*********MENU**********");
		printf("\n1.Display\n");
		printf("\n2.Insertion at the Beginning\n");
		printf("\n3.Insertion at the End\n");
		printf("\n4.Insertion at any position\n");
		printf("\n5.Deletion at the Beginning\n");
		printf("\n6.Deletion at the End\n");
		printf("\n7.Deletion at any position\n");
		printf("\n8.To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteEnd();
			break;
		case 7:
			deletePosition();
			break;
		case 8:
			exit(1);
			break;
		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}

