#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
 {
 	char *name;
 	char *prenom;
 	int age;
 }node;

typedef struct 
 {
 	node person;
 	struct tries *alphabet[26];	
 }tries;
 
 tries *root;
 
int hash(char name);
void insertion(node info);
 void print(char *key);

int main(void)
{
	root = malloc(sizeof(tries));
	if(root == NULL)
		return 1;
	for(int j = 0; j < 26; j++)
	{
		root->alphabet[j] = NULL;
	}
	printf("%p\n", root->alphabet[0]);
	node p1 = {"Kudo", "Shinichi", 17};
	node p2 = {"Edogawa", "Conan", 10};
	node p3 = {"Kaito", "Kid", 17};
	insertion(p1);
	print("Kudo");
	insertion(p2);
	print("Edogawa");
	insertion(p3);
	print("Kaito");
	print("Heiji");
	
	free(root);
	return 0;
}

int hash(char name)
{
		for(int j = 0; j < 26 ; j++)
		{
			if(name == 'a' + j)
			{
				return j;
			}
		}	
	
}

void insertion(node info)
{
	tries *current = root;
	for(int i = 0; info.name[i] != '\0'; i++)
	{
		tries *new = malloc(sizeof(tries));
		if(new == NULL)
			exit(EXIT_FAILURE);
		for(int j = 0; j < 26; j++)
		{
			new->alphabet[j] = NULL;
		}
		
		current->alphabet[hash(info.name[i])] = new;
		
		current = current->alphabet[hash(info.name[i])];
	}
	current->person.age = info.age;
	strcpy(current->person.name, info.name);
	strcpy(current->person.prenom, info.prenom);
	
}

void print(char *key)
{
	tries *current = root;
	int i;
	for(i = 0; key[i] != '\0'; i++)
	{
		if(current->alphabet[hash(key[i])] != NULL)
			current = current->alphabet[hash(key[i])];
		else
		{
			printf("could'nt found information about %s\n", key);
			break;
		
		}
	}
	if(key[i] == '\0')
	{
		printf("Name : %s\n", current->person.name);
		printf("Prenom : %s\n", current->person.prenom);
		printf("Age : %i\n", current->person.age);
		printf("////////////{{{{{{{{{{///////////\n");
	}
}

/*void freeTries()
{
	node *previous = NULL;
	node *current = root;
	
	
	
}*/
