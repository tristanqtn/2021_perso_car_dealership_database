//LIBRARIES/////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
////////////////////////////////////////////////////////////////


//STRUCTURES////////////////////////////////////////////////////
typedef struct voiture
{
    char essence;

    char * marque;
    char * immatriculation;
    
    int anneeProd;

    struct voiture * suivant;

}t_voiture;
////////////////////////////////////////////////////////////////


//PROTOTYPES////////////////////////////////////////////////////
int menu ();
int menuSuppression ();

void affichageListe (t_voiture * ancre);
void affichageStruct (t_voiture * maStruct);

void sauvegardeListe (t_voiture * ancre);
void sauvegardeStruct (t_voiture * maStruct, FILE * fichier);

char * phraseDynamique ();

t_voiture * saisieStruct ();
t_voiture * ajoutFin (t_voiture * nouvelle, t_voiture * ancre);
////////////////////////////////////////////////////////////////


//MAIN//////////////////////////////////////////////////////////
int main()
{
    int choix;
    int choixSuppression;

    t_voiture * ancre = NULL;
    t_voiture * nouvelle = NULL;

    do
    {
        choix = menu();

        if(choix == 1)
        {
            nouvelle = saisieStruct();
            ancre = ajoutFin(nouvelle, ancre);
        }

        if(choix == 2)
        {
            affichageListe(ancre);
        }

        if(choix == 3)
        {
            choixSuppression = menuSuppression();

            if(choixSuppression == 1)
            {

            }
            if(choixSuppression == 2)
            {
                
            }
            if(choixSuppression == 3)
            {
                
            }
            if(choixSuppression == 4)
            {
                
            }      
        }

        if(choix == 4)
        {
            sauvegardeListe(ancre);
        }

    } while (choix != 5);
    
    return 0;
}
////////////////////////////////////////////////////////////////

//SAISIE PHRASE DYNA////////////////////////////////////////////
char * phraseDynamique ()
{
    ///déclarations
    char * phrase;
    char stockage [100];
    int longueur;

    //saisie de la chaine à stocker
    fflush(stdin);
    gets(stockage);

    //longueur de la chaine saisie
    longueur = strlen(stockage) + 1;

    //allocation dynamique de la chaine
    phrase = (char *) malloc (longueur * sizeof(char));

    //copie de la chaine dans le tab alloué
    strcpy(phrase, stockage);

    //rendre le tab dyna
    return phrase;
}
////////////////////////////////////////////////////////////////

//MENU SUPPRESSION DE VOITURE///////////////////////////////////
int menuSuppression ()
{
    ///déclarations
    int choixUtil;
    
    system("CLS");

    //affichage du menu
    printf("1 - Supprimer selon la plaque d'immatriculation\n");
    printf("2 - Supprimer selon l'annee de production\n");
    printf("3 - Supprimer selon la marque\n");
    printf("4 - Supprimer selon le carburant\n");
    printf("5 - Revenir au menu\n"); 
    printf("\n\t Choix : ");

    //saisie blindée du choix de l'utilisateur
    do
    {
        fflush(stdin);
        scanf("%d", &choixUtil);
    }while(  choixUtil < 1 || choixUtil > 5);

    //rendre le choix de l'utilisateur
    return choixUtil; 
}
////////////////////////////////////////////////////////////////

//AJOUT EN FIN DE LISTE/////////////////////////////////////////
t_voiture * ajoutFin (t_voiture * nouvelle, t_voiture * ancre)
{
    t_voiture * courant; 

    if(ancre == NULL)
    {
        ancre = nouvelle;
    }
    else
    {
        courant = ancre;

        while (courant->suivant != NULL)
        {
            courant = courant->suivant;
        }
        courant->suivant = nouvelle;
    }

    system("CLS");
    printf("\nLa voiture a bien ete enregistree dans la base de donnees\n");
    system("pause");

    return ancre;
}
////////////////////////////////////////////////////////////////

//MENU//////////////////////////////////////////////////////////
int menu ()
{
   ///déclarations
   int choixUtil;
   
    system("CLS");

   //affichage du menu
   printf("1 - Ajouter une nouvelle voiture dans la base de donnees\n");
   printf("2 - Afficher toute les voitures dans la base de donnees\n");
   printf("3 - Supprimer une voiture de la base de donnees\n");
   printf("4 - Sauvegarder la base de donnee\n");
   printf("5 - Charger une base de donnee sauvegardee\n");
   printf("6 - Quitter le programme\n"); 
   printf("\n\t Choix : ");

   //saisie blindée du choix de l'utilisateur
   do
   {
	fflush(stdin);
	scanf("%d", &choixUtil);
   }while(  choixUtil < 1 || choixUtil > 6);

   //rendre le choix de l'utilisateur
   return choixUtil;
}
////////////////////////////////////////////////////////////////

//SAISIE D'UNE STRUCT///////////////////////////////////////////
t_voiture * saisieStruct ()
{
  ///déclaration
  t_voiture * maStruct;

  //allocation dynamique de la structure
  maStruct = (t_voiture *) malloc (sizeof(t_voiture));
   
    if(maStruct != NULL)
    {
      ///saisie
      //marque
      printf("Veuillez saisir la marque de la voitrue : ");
      maStruct->marque = phraseDynamique ();

      //immatriculation
      printf("Veuillez saisir l'immatriculation de la voitrue: ");
      maStruct->immatriculation= phraseDynamique ();

      //essence
      printf("Veuillez saisir le type de carburant de la voitrue : ");
      scanf("%c", &maStruct->essence);

      //annee de production
      printf("Veuillez saisir l'annee de production de la voiture : ");
      scanf("%d", &maStruct->anneeProd);

      maStruct->suivant = NULL; //pointeur sur suivant
    }

  //rendre la structure à l'appellant
  return maStruct;
}
////////////////////////////////////////////////////////////////

//AFFICHAGE DE LA LISTE/////////////////////////////////////////
void affichageListe (t_voiture * ancre)
{
    t_voiture * courant;

    if(ancre != NULL)
    {
        system("CLS");
        courant = ancre;

        while(courant->suivant!=NULL)
        {
            affichageStruct(courant);
            printf("\n");
            courant = courant->suivant;
        }
        affichageStruct(courant);
        system("pause");
    }
    else
    {
        system("CLS");
        printf("Affichage impossible, base de donnee vide\n");
        system("pause");
    }
    
}
////////////////////////////////////////////////////////////////

//AFFICHAGE/////////////////////////////////////////////////////
void affichageStruct (t_voiture * maStruct)
{
    //affichage
    printf("Marque : %s \n", maStruct->marque);
    printf("Immatriculation : %s \n", maStruct->immatriculation);
    printf("Type de carburant : %c \n", maStruct->essence);
    printf("Annee de production : %d \n", maStruct->anneeProd);
}
////////////////////////////////////////////////////////////////

//SAUVEGARDE DE LA LISTE////////////////////////////////////////
void sauvegardeListe (t_voiture * ancre)
{
    FILE * fichier;
    
    t_voiture * courant; 

    fichier = fopen("base_donnee.txt", "w");

    if(fichier != NULL && ancre != NULL)
    {
        courant = ancre;

        while(courant->suivant!=NULL)
        {
            sauvegardeStruct(courant, fichier);
            printf("\n");
            courant = courant->suivant;
        }
        sauvegardeStruct(courant, fichier);

        printf("La base de donnee a bien ete sauvegardee\n");
        system("pause");

        fclose(fichier);
    }
       
    else
    {
        system("CLS");
        printf("Sauvegarde impossible, base de donnee vide\n");
        system("pause");
    }
}
////////////////////////////////////////////////////////////////

//AFFICHAGE/////////////////////////////////////////////////////
void sauvegardeStruct (t_voiture * maStruct, FILE * fichier)
{
    //affichage
    fprintf(fichier, "%s\n", maStruct->marque);
    fprintf(fichier, "%s\n", maStruct->immatriculation);
    fprintf(fichier, "%c\n", maStruct->essence);
    fprintf(fichier, "%d\n", maStruct->anneeProd);
    fprintf(fichier, "\n\n");
}
////////////////////////////////////////////////////////////////

t_voiture * recuperationListe ()
{
    FILE * fichier;

    fichier = fopen("base_donnee.txt", "r");

    while (!feof(fichier))
    {
        /* code */
    }
       
}