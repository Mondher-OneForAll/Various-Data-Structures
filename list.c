#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char nom[26];
	char prenom[26];
	struct node *suivant;
}node;

node *premier = NULL;

node *initialisation();	
void insertion(node * p, char *nom, char *prenom);
void print(node *p);
void freeMemory(node *p);
void changer(node *p, char *nom);
void lire(char *name, int longueur);
void viderBuffer();


int main(void)
{
	node *maListe = initialisation();
	
	insertion(maListe, "Kaito", "Kid");
	insertion(maListe, "Edogawa", "Conan");
	insertion(maListe, "Saeba", "Ryo");
	
	changer(maListe, "Kaito");

	print(maListe);
	
	
	
	
	return 0;
	
}

node *initialisation()
{
	//premier = malloc(sizeof(node));
	node *n = malloc(sizeof(node));
	strcpy(n->nom, "Kudo");
	strcpy(n->prenom, "Shinichi");
	n->suivant = NULL;
	premier = n;
	return premier;
}

void insertion(node * p, char *nom, char *prenom)
{
	node *n = malloc(sizeof(node));
	if(n == NULL || p == NULL)
	{
		exit(EXIT_FAILURE);;
	}
	strcpy(n->nom, nom);
	strcpy(n->prenom, prenom);
	n->suivant = premier;
	premier = n;
}
void print(node *p)
{
	if(p == NULL)
	{
		exit(EXIT_FAILURE);;
	}
	int i = 1;
	for(node *tmp = premier;tmp != NULL;tmp = tmp->suivant)
	{
		printf("Etudiant %i :\n",i);
		printf("Nom : %s\n",tmp->nom);
		printf("Prenom : %s\n",tmp->prenom);
		printf("///////////////////////\n");
		i++;
	}
}

void freeMemory(node *p)
{
	if(p == NULL)
	{
		exit(EXIT_FAILURE);;
	}
	while(premier != NULL)
	{
		node *tmp = premier->suivant;
		free(premier);
		premier = tmp;
	}
}

void changer(node *p, char *nom)
{
	char name[26];
	if(p == NULL)
	{
		exit(EXIT_FAILURE);;
	}
	for(node *tmp  = premier;tmp != NULL;tmp = tmp->suivant)
	{
		if(strcmp(tmp->nom, nom) == 0)
		{
			printf("Saisissez le nouveau nom !!\n");
		
			lire(name, 26);
			printf("///////////////////////\n");
			strcpy(tmp->nom, name);
		}
	}
}
void lire(char *name, int longueur)
{
	if(fgets(name, longueur, stdin))
	{
		char * position = NULL;
		position = strchr(name, '\n');
		if(position != NULL)
		{
			*position = '\0';
		}
		viderBuffer();
	}
	viderBuffer();
}

void viderBuffer()
{
	int c = 0;

	while(c != '\0' && c != EOF)
	{
		c = getchar();
	}
	
}
