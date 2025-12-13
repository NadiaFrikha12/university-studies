<<<<<<< HEAD
//Applications de quelques fonctions d'ajout et de suppression sur une liste simplement chainée
=======
//Application de fonctions sur les listes doublement chainÃ©es 
>>>>>>> Ajouter_Liste_Doublement_Chainee/main

#include<stdio.h>
#include<stdlib.h>

<<<<<<< HEAD
// Définition de la structure de la boîte
struct BOX{
    int data;            // Donnée stockée dans la boîte
    struct BOX* next;    // Pointeur vers la prochaine boîte
};
typedef struct BOX BOX;  // Alias pour la structure BOX

// Fonction pour ajouter un élément au début de la liste
BOX* AjouterAuDebut (BOX* debut , int element){
    BOX* b; // Déclaration d'un pointeur de boîte
    
    b=(BOX*)malloc(sizeof(BOX)); // Allocation de mémoire pour une nouvelle boîte
    
    if (b==NULL){ // Vérification de l'allocation réussie
        printf("erreur de l'allocation");
        exit (-1); // Quitter le programme avec un code d'erreur
    }
    
    b->data = element; // Assigner la valeur à la boîte créée
    
    if (debut->next == NULL){ // Vérifier si la liste est vide
        b->next = NULL; // Si oui, la prochaine boîte pointe vers NULL
    }
    
    b->next= debut; // La nouvelle boîte pointe vers l'ancien début de liste
    return b; // Retourner la nouvelle boîte qui est maintenant le début de la liste
}

// Fonction pour ajouter des éléments au milieu de la liste 
BOX* AjouterAuMilieu (BOX* p,BOX* p1 , int element){
	BOX* b; // Déclaration d'un pointeur de boîte
    
    b=(BOX*)malloc(sizeof(BOX)); // Allocation de mémoire pour une nouvelle boîte
    
    if (b==NULL){ // Vérification de l'allocation réussie
        printf("erreur de l'allocation");
        exit (-1); // Quitter le programme avec un code d'erreur
    }
    
    b->data = element; // Assigner la valeur à la boîte créée
    
    p->next=b;
    b->next=p1;
    p1=NULL; //supprimer l'ancienne liaison 
    
    return b;	
}

// Fonction pour ajouter des éléments a la fin de la liste 
BOX* AjouterQueue(BOX* p1, int element){
	
	BOX* b; // Déclaration d'un pointeur de boîte
    
    b=(BOX*)malloc(sizeof(BOX)); // Allocation de mémoire pour une nouvelle boîte
    
    if (b==NULL){ // Vérification de l'allocation réussie
        printf("erreur de l'allocation");
        exit (-1); // Quitter le programme avec un code d'erreur
    }
    
    b->data = element; // Assigner la valeur à la boîte créée
    
    p1->next=b;
    b->next=NULL;
    return b;
}


// Fonction pour supprimer un élément au début de la liste
BOX* SupprimerTeteListe (BOX* p){
	BOX* p1= p->next; 
	free(p);
	p=NULL;
	return p1;
}

// Fonction pour supprimer un élément a la fin de la liste
BOX* SupprimerQueueListe(BOX* p){
	BOX* p1 = NULL;
	while (p->next != NULL){
		p1 =p; //l'adresse de l'avant dernier element 
		p=p->next; //l'adresse du dernier element
	}
	free(p);
	p=NULL;
	p1->next=NULL;
	return p1;
}

// Fonction pour supprimer un élément au milieu de la liste
BOX* SupprimerAuMilieu (BOX* p,BOX* p1){
	BOX* p3=NULL;
	p3=p1;
	p->next=p1->next;
	p3->next=NULL;
	free(p3);
	p3=NULL;
	return p->next;
}
 
// Fonction pour afficher les éléments de la liste
void afficheListe(BOX* debut){
    if (debut == NULL){
        printf("la liste est vide\n");
        return; //quitter la fonction
    }
    
    while(debut != NULL){
        printf("%d --> ", debut->data);
        debut = debut->next;
    }
    printf("NULL\n");
=======
// DÃ©finition de la structure de la boÃ®te
struct BOX{
    int data;            // DonnÃ©e stockÃ©e dans la boÃ®te
    struct BOX* next;    // Pointeur vers la prochaine boÃ®te
    struct BOX* prev;	 // Pointeur vers la boÃ®te prÃ©cÃ©dante 
};
typedef struct BOX BOX;

BOX* CreationBoite (int element){
	BOX* b; // DÃ©claration d'un pointeur de boÃ®te
    
    b=(BOX*)malloc(sizeof(BOX)); // Allocation de mÃ©moire pour une nouvelle boÃ®te
    
    if (b==NULL){ // VÃ©rification de l'allocation rÃ©ussie
        printf("erreur de l'allocation");
        exit (-1); // Quitter le programme avec un code d'erreur
    }
    
    b->data = element; // Assigner la valeur Ã  la boÃ®te crÃ©Ã©e
    // initialiser les pointeurs Ã  NULL
    b->next =NULL; 
    b->prev = NULL; 
    
	return b;
}

void AfficheChaine (BOX* p){
	if (p->next == NULL){
		printf("la chaine est vide");
		return ; //quitter
	}
	while (p!= NULL){
		printf("%d --> ",p->data);
		p= p->next;
	}
	printf("NULL\n");
}


BOX* AjouterAuDebut (BOX* debut , int element){
	BOX* b= CreationBoite (element);
	    
	b->next = debut; 
	if(debut != NULL){
		debut->prev = b;
	}   
	
	//il s'execule soit la liste est vide ou non
	debut = b;
	return debut;  
    
}

BOX* AjouterFin (BOX* debut , int element){
	BOX* b= CreationBoite (element);
    
    if (debut->next == NULL){
    	debut = b ;
	}
    
    //Recherche du dernier element 
    BOX* p1 = debut;
    while (p1->next != NULL){
    	p1=p1->next;
	}
	b->prev = p1;
	p1->next = b;

	return b;
>>>>>>> Ajouter_Liste_Doublement_Chainee/main
}



<<<<<<< HEAD
int main(){
	BOX* p=NULL; // Initialisation du pointeur de début de liste à NULL
	
	//remplissage du premier element 
	p=(BOX*)malloc(sizeof(BOX)); // Allocation de mémoire pour chaque boite 
	if (p==NULL){ // Vérification de l'allocation réussie
	    printf("erreur de l'allocation");
	    return 1; // Quitter le programme avec un code d'erreur
	}
	printf("donner les donnees de la boite 1 : ");
	scanf("%d",&p->data);
	p->next = NULL; // Initialisation du champ 'next' à NULL
	
	//remplissage du reste de la liste chainee 
	BOX* p1 = p; // Utilisation de p1 pour garder une référence à la tête de la liste
	for (int i=0; i<3 ; i++){
		p1->next=(BOX*)malloc(sizeof(BOX)); // Allocation de mémoire pour chaque boite 
	    if (p1->next==NULL){ // Vérification de l'allocation réussie
	        printf("erreur de l'allocation");
	        return 1; // Quitter le programme avec un code d'erreur
    	}
    	p1=p1->next; //avancer p1
		printf("donner les donnees de la boite %d : ",i+2);
		scanf("%d",&p1->data);
		p1->next = NULL; // Initialisation du champ 'next' à NULL pour la dernière boîte	
	}
	
	//ajout d'un élément à la tête de la liste
	int d1; //data
	printf("donner les donnees a ajouter a la tete de la liste : ");
	scanf("%d",&d1);
	p=AjouterAuDebut(p,d1);
	
	//ajout d'un élément au milieu de la liste
	int d2; //data
	printf("donner les donnees a ajouter au milieu de la liste : ");
	scanf("%d",&d2);
	p1=p->next;
	BOX* p2= AjouterAuMilieu (p,p1,d2);
	
	//ajout d'un élément à la fin de la liste 
	int d3; //data
	printf("donner les donnees a ajouter a la fin de la liste : ");
	scanf("%d",&d3);
	p1=p; //initialisation de p1
	while(p1->next != NULL){
		p1=p1->next;
	}
	p1= AjouterQueue(p1,d3);
	
	//affichage de la liste avant la supression
	printf("La chaine avant la suppression\n");
	afficheListe(p);
	
	//supprimer un élément au début de la liste
	p=SupprimerTeteListe(p);
	
	//affichage de la liste apres la supression
	printf("La chaine apres la suppression au debut : \n");
	afficheListe(p);
	
	//supprimer un élément a la fin de la liste
	p1=SupprimerQueueListe(p);
	
	//affichage de la liste apres la supression
	printf("La chaine apres la suppression a la fin \n");
	afficheListe(p);
	
	//supprimer un élément au milieu
	p1=p; // initialiser p1
	p2=NULL; 
	p1=p->next;
	p2= SupprimerAuMilieu (p,p1); //suppression de p1
	
	//affichage de la liste apres la supression
	printf("La chaine apres la suppression au milieu \n");
	afficheListe(p);
	
	
	//libération de la mémoire
	while (p->next != NULL){
		p=SupprimerTeteListe(p);	
	}
	free(p);
	p=NULL; 
	
	//affichage de la liste apres liberation 
	printf("La chaine apres la liberation : \n");
	afficheListe(p);
	
	return 0;
}
=======
BOX* AjouterAuMilieu (BOX* debut, int element , int c){
	
	BOX* p1 = debut;
	while (p1->data != c  &&  p1->next != NULL){
		p1=p1->next;
	}
	
	BOX* b= CreationBoite (element);
	
	BOX* p2 = p1->next;
	b->next =p2;
	b->prev = p1;
	p2->prev=b;
        p1->next=b;

	return b;
}

int main (){
	BOX* p=NULL;
	
	//remplissage de la premiere boite
	p=(BOX*)malloc(sizeof(BOX));
	if (p==NULL){
		printf("erreur de l'allocation");
		return 1;
	}
	printf ("donnee de la boite 1 : ");
	scanf("%d",&p->data);
	p->next = NULL;
	
	//Remplissage du reste de la liste chainee
	BOX* p1=p;  // Utilisation de p1 pour garder une rÃ©fÃ©rence Ã  la tÃªte de la liste 
	for (int i=0; i<3; i++){
		p1->next=(BOX*)malloc(sizeof(BOX));
		if (p1->next==NULL){
			printf("erreur de l'allocation");
			return 1;
		}
		p1=p1->next; //avancer p1
		printf("donnee de la boite %d : ",i+2);
		scanf("%d",&p1->data);
		p1->next = NULL; //pour la derniere boite	
	}
	
	//ajouter un element au debut
	int d1;
	printf("donnee de la boite a ajouter au debut :");
	scanf("%d",&d1);
	p=AjouterAuDebut(p,d1);
	
	
	//ajouter un element a la fin 
	int d2;
	printf("donnee de la boite a ajouter a la fin :");
	scanf("%d",&d2);
	BOX* p2=AjouterFin(p,d2);
	
	//ajouter un element au milieu
	int d3; int c;
	printf("donnez le contenu de la boite apres laquelle vous voulez ajouter un element :");
	scanf("%d",&c);
	printf("donnee de la boite a ajouter au milieu :");
	scanf("%d",&d3);
	BOX* p3=AjouterAuMilieu (p,d3,c);
	
	//affichage de la liste chainee avant modification
	AfficheChaine (p);
	
	return 0;
}
  
	
>>>>>>> Ajouter_Liste_Doublement_Chainee/main
