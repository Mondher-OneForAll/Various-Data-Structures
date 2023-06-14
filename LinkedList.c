#include <stdio.h>
#include <stdlib.h>


typedef struct 
 {
 	int value;
 	struct node *next;
 	
 }node;
 
 node *head;
 
 void insertion();
 void afficher();
 void freeList();
 void reverseList();
 
 
 int main(void)
 {
 	int n;
 	printf("Enter the number of data : ");
 	scanf("%i", &n);
 	for(int i = 0;i < n ;i++)
 		insertion();

 	afficher();
 	
 	reverseList();
 	afficher();
 	
 	freeList();
 	return 0;
 }

 void insertion()
 {
 	node *new = malloc(sizeof(node));
 	if(new == NULL)
 		exit(EXIT_FAILURE);
 	
 	printf("Enter the desired value : ");
 	scanf("%i", &(new->value));
 	
 	new->next = head;
 	head = new;
 	
 	
 }
 
 void afficher()
 {
 	node *current = malloc(sizeof(node));
 	current = head;
 	
 	while(current != NULL)
 	{
 		printf(" -> %i", current->value);
 		current = current->next;
 	}
 	printf("\n");
 }
 
 void freeList()
 {
 	node *current = head;
 	node *previous = NULL;
 	while(current != NULL)
 	{
 		previous = current;
 		current = current->next;
 		free(previous);
 		
 	}
 }
 void reverseList()
 {
 	node *current = head;
 	node *previous = NULL;
 	node *tmp = current->next;
 
 	while(tmp != NULL) 
 	{
 		previous = current;
 		current = tmp;
 		tmp = tmp->next;
 	
 		current->next = previous;
 		if(previous == head)
 			previous->next = NULL;
 		
 	}
 	
 	head = current;
 
 	
 	
 }

 
