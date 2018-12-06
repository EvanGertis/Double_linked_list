#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *prev;
	int info;
	struct node *next;
};

struct node *createList(struct node *start);
void displayList(struct node *start);
struct node *insertInEmptyList(struct node *start, int data);
struct node *insertInBeginning(struct node *start, int data);
void insertAtEnd(struct node *start, int data);
void insertAfter(struct node *start, int data, int x);
struct node *insertBefore(struct node *start, int data, int x);
struct node *deleteNode(struct node *start, int data);
struct node *reverseList(struct node *start);


int main() 
{
	int choice, data, x;
	struct node *start = NULL;
	
	start = createList(start);
	
	while(1){
		printf("\n");
		printf("1. Display List \n");
		printf("2. Insert in empty list \n");
		printf("3. Insert a node in beginning of the list \n");
		printf("4. Insert a node at the end of the list \n");
		printf("5. Insert a node after a specified node \n");
		printf("6. Insert a node before a specified node \n");
		printf("7. Delete a node \n");
		printf("8. Reverse the list \n");
		printf("9. Quit \n");
		printf("enter your choice : ");
		scanf("%d", &choice);
		
		if(choice = 9){
			break;
		}
		
		switch(choice){
			case 1:
				displayList(start);
				break;
			case 2: 
				printf("Enter the element to be inserted : ");
				scanf("%d", &data);
				start = insertInEmptyList(start, data);
				break;
			case 3:
				printf("Enter the element to be inserted : ");
				scanf("%d", &data);
				start = insertInBeginning(start, data);
				break;
			case 4: 
				printf("Enter the element to be inserted : ");
				scanf("%d", &data);
				insertAtEnd(start, data);
				break;
			case 5:
				printf("Enter the node which you would like to insert data after : ");
				scanf("%d", &x);
				printf("Enter the element that you would like to be inserted : ");
				insertAfter(start, data, x);
				break;
			case 6:
				printf("Enter the node which you would like to insert data before : ");
				scanf("%d", &x);
				printf("Enter the element that you would like to be inserted : ");
				start = insertBefore(start, data, x);
				break;
			case 7:
				printf("Enter the element of the node that you would like to delete : ");
				start = deleteNode(start, data);
				break;
			case 8: 
				start = reverseList(start);
				break;
			default:
				printf("wrong choice");
				break;
		}/*end switch*/
		
	}/*end while*/
	
	return 0;
}/*end main*/

struct node *createList(struct node *start){
	int i, n, data;
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	
	printf("Enter the number of nodes : ");
	scanf("%d", &n);
	
	start = NULL;
	
	if(n == 0){
		return start;
	}
	
	if(n == 1){
		printf("Enter the data for node %d : ", n);
		scanf("%d", &data);
		insertInEmptyList(start, data);
		return start;
	}
	
	for(i = 1; i < n; i++){
		printf("Enter the data for node %d : ", i);
		scanf("%d", &data);
		insertAtEnd(start, data);
	}
	
	return start;
}/* end createList */

void displayList(struct node *start){
	struct node *p;
	if(start == NULL){
		printf("The list is empty");
		return;
	}
	
	p = start;
	printf("List is :\n");
	while(p != NULL){
		printf("%d", p->info);
		p = p->next;
	}
	printf("\n");
	
}/* end displayList */

struct node *insertInEmptyList(struct node *start, int data){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	
	temp->prev = NULL;
	temp->next = start;
	
	start->prev = temp;
	start = temp;
	
	return start;
}/* end insertInEmptyList */

struct node *insertInBeginning(struct node *start, int data){
	
	return start;
}/* end insertInBeginning */

void insertAtEnd(struct node *start, int data){
	struct node *temp, *p; 
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	
	while(p != NULL){
		p->next;
	}
	
	temp->prev = p;
	temp->next = p->next;
	p->next->prev = temp;
	p->next = temp;
	
}/* end insertAtEnd */

void insertAfter(struct node *start, int data, int x){
	struct node *temp, *p;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	
	p = start;
	while(p != NULL){
		if(p->info == x){
			break;
		}
		p = p-> next;
	}
	
	if(p == NULL){
		printf("%d not present in the list\n", x);
	} else{
		temp->prev = p;
		temp->next = p->next;
		if(p->next != NULL){
			p->next->prev = temp;
		}
		p->next = temp;
	}
	
}/* end insertAfter */

struct node *insertBefore(struct node *start, int data, int x){
	struct node *temp, *p;
	
	if(start == NULL){
		printf("List is empty\n");
		return start;
	}
	
	if(start->info == x){
		temp = (struct node *)malloc(sizeof(struct node));
		temp->info = data;
		
		temp->prev = NULL;
		temp->next = start;
		start->prev = temp;
		start = temp;
		return start;
	}
	
	
	p = start;
	while(p != NULL){
			if(p->info == x)
				break;
			p = p->next;
	}
		
	if(p == NULL){
		printf("%d not present in the list\n", x);
	} else {
		temp = (struct node *)malloc(sizeof(struct node));
		temp->info = data;
		
		temp->prev = p->prev;
		temp->next = p;
	}
	
	
	return start;
	
}/* end insertBefore */

struct node *deleteNode(struct node *start, int data){
	
	return start;
}/* end deleteNode*/

struct node *reverseList(struct node *start){
	
	return start;
}/* end reverseList */

