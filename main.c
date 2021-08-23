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
char * phraseDynamiqueRecup (char stockage [100]);

t_voiture * saisieStruct ();
t_voiture * recuperationListe ();
t_voiture * ajoutFin (t_voiture * nouvelle, t_voiture * ancre);

t_voiture * suppressionProd (t_voiture * ancre);
t_voiture * suppressionImmat (t_voiture * ancre);
t_voiture * suppressionMarque (t_voiture * ancre);
t_voiture * suppressionCarburant (t_voiture * ancre);
////////////////////////////////////////////////////////////////


//MAIN//////////////////////////////////////////////////////////
int main()
{
    //déclarations
    int choix;
    int choixSuppression;

    t_voiture * ancre = NULL;
    t_voiture * nouvelle = NULL;

    do
    {
        //affichage menu et recuparetion du choix
        choix = menu();

        if(choix == 1)
        {//saisir une nouvelle voiture
            nouvelle = saisieStruct();//saisie
            ancre = ajoutFin(nouvelle, ancre);//ajout dans la liste
        }

        if(choix == 2)
        {//affichage de la liste
            affichageListe(ancre);
        }

        if(choix == 3)
        {//suppression
            choixSuppression = menuSuppression();//affichage menu suppression et recuperation du choix

            if(choixSuppression == 1)
            {//immatriculation
                ancre = suppressionImmat(ancre);
            }
            if(choixSuppression == 2)
            {//annee de production
                ancre = suppressionProd(ancre);
            }
            if(choixSuppression == 3)
            {//marque
                ancre = suppressionMarque(ancre);
            }
            if(choixSuppression == 4)
            {//carburant
                ancre = suppressionCarburant(ancre); 
            }
        }

        if(choix == 4)
        {
            sauvegardeListe(ancre);
        }
        if(choix == 5)
        {
            ancre = recuperationListe();
        }

    } while (choix != 6);

    return 0;
}
////////////////////////////////////////////////////////////////

//SUPPRESSION IMMATRICULATION///////////////////////////////////
t_voiture * suppressionImmat (t_voiture * ancre)
{
    ///délcarations
    char * immatSupp;

    t_voiture * courant = NULL;
    t_voiture * precedent = NULL;

    int sortie = 0;

    if(ancre != NULL)
    {
        //saisie de l'immatriculation
        system("CLS");
        printf("Immatriculation a supprimer : ");
        immatSupp = phraseDynamique();

        courant = ancre;//initialisation de la variable de parcours

        while(sortie == 0 && courant->suivant!=NULL)
        {//fin de liste ou ordre de sortie
            if(strcmp(courant->immatriculation, immatSupp) == 0)
            {//test immatriculation
                if(precedent == NULL)
                {//on supprime l'ancre
                   ancre = ancre->suivant;
                   free(courant);
                }
                else
                {//maillon de la liste
                    precedent->suivant= courant->suivant;
                    free(courant);
                }

                sortie = 1;//ordre de sortie
                printf("\nVoiture trouvee et suprimee\n");
                system("pause");
            }
            precedent = courant;//parcours
            courant = courant->suivant;//parcours
        }
        if(strcmp(courant->immatriculation, immatSupp) == 0)
        {//test pour la derniere voiture
            free(courant);
            precedent->suivant =NULL;
            printf("\nVoiture trouvee et suprimee\n");
            system("pause");
        }
    }
    else
    {
        system("CLS");
        printf("Suppression impossible, liste vide\n");
        system("pause");
    }
    //rendu de l'ancre
    return ancre;
}
////////////////////////////////////////////////////////////////

//SUPPRESSION ANNEE PRODUCTION//////////////////////////////////
t_voiture * suppressionProd (t_voiture * ancre)
{
    ///délcarations
    int anneProd;

    t_voiture * courant = NULL;
    t_voiture * precedent = NULL;

    if(ancre != NULL)
    {
        //saisie de l'immatriculation
        system("CLS");
        printf("Anne de production a supprimer : ");
        fflush(stdin);
        scanf("%d", &anneProd);

        courant = ancre;//initialisation de la variable de parcours

        while(courant->suivant!=NULL)
        {//fin de liste ou ordre de sortie
            if(courant->anneeProd == anneProd)
            {//test immatriculation
                if(precedent == NULL)
                {//on supprime l'ancre
                   ancre = ancre->suivant;
                   free(courant);
                   courant = ancre;
                }
                else
                {//maillon de la liste
                    precedent->suivant= courant->suivant;
                    free(courant);
                    courant = ancre;
                }
                printf("\nVoiture trouvee et supprimee\n");
                system("pause");
            }
            precedent = courant;//parcours
            courant = courant->suivant;//parcours
        }
        if(courant->anneeProd == anneProd)
        {//test pour la derniere voiture
            free(courant);
            precedent->suivant =NULL;
            printf("\nVoiture trouvee et supprimee\n");
            system("pause");
        }
    }
    else
    {
        system("CLS");
        printf("Suppression impossible, liste vide\n");
        system("pause");
    }
    //rendu de l'ancre
    return ancre;
}
////////////////////////////////////////////////////////////////

//SUPPRESSION CARBURANT/////////////////////////////////////////
t_voiture * suppressionCarburant (t_voiture * ancre)
{
    ///délcarations
    char carbu;

    t_voiture * courant = NULL;
    t_voiture * precedent = NULL;

    if(ancre != NULL)
    {
        //saisie de l'immatriculation
        system("CLS");
        printf("Anne de production a supprimer : ");
        fflush(stdin);
        scanf("%c", &carbu);

        courant = ancre;//initialisation de la variable de parcours

        while(courant->suivant!=NULL)
        {//fin de liste ou ordre de sortie
            if(courant->essence == carbu)
            {//test immatriculation
                if(precedent == NULL)
                {//on supprime l'ancre
                   ancre = ancre->suivant;
                   free(courant);
                   courant = ancre;
                }
                else
                {//maillon de la liste
                    precedent->suivant= courant->suivant;
                    free(courant);
                    courant = ancre;
                }
                printf("\nVoiture trouvee et supprimee\n");
                system("pause");
            }
            precedent = courant;//parcours
            courant = courant->suivant;//parcours
        }
        if(courant->essence == carbu)
        {//test pour la derniere voiture
            free(courant);
            precedent->suivant =NULL;
            printf("\nVoiture trouvee et supprimee\n");
            system("pause");
        }
    }
    else
    {
        system("CLS");
        printf("Suppression impossible, liste vide\n");
        system("pause");
    }
    //rendu de l'ancre
    return ancre;
}
////////////////////////////////////////////////////////////////

//SUPPRESSION MARQUE////////////////////////////////////////////
t_voiture * suppressionMarque (t_voiture * ancre)
{
    ///délcarations
    char * marque;

    t_voiture * courant = NULL;
    t_voiture * precedent = NULL;

    if(ancre != NULL)
    {
        //saisie de l'marque
        system("CLS");
        printf("Immatriculation a supprimer : ");
        marque = phraseDynamique();

        courant = ancre;//initialisation de la variable de parcours

        while(courant->suivant!=NULL)
        {//fin de liste ou ordre de sortie
            if(strcmp(courant->marque, marque) == 0)
            {//test marque
                if(precedent == NULL)
                {//on supprime l'ancre
                   ancre = ancre->suivant;
                   free(courant);
                   courant = ancre;
                }
                else
                {//maillon de la liste
                    precedent->suivant= courant->suivant;
                    free(courant);
                    courant = ancre;
                }
                printf("\nVoiture trouvee et suprimee\n");
                system("pause");
            }
            precedent = courant;//parcours
            courant = courant->suivant;//parcours
        }
        if(strcmp(courant->marque, marque) == 0)
        {//test pour la derniere voiture
            free(courant);
            precedent->suivant =NULL;
            printf("\nVoiture trouvee et suprimee\n");
            system("pause");
        }
    }
    else
    {
        system("CLS");
        printf("Suppression impossible, liste vide\n");
        system("pause");
    }
    

    //rendu de l'ancre
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
    //déclaration
    t_voiture * courant;

    if(ancre == NULL)
    {//si la liste est vide
        ancre = nouvelle;//le nouveau maillon est l'ancre
    }
    else
    {//si la liste contiet au moins 1 voiture
        courant = ancre;//initialisation de la var de parcours

        while (courant->suivant != NULL)
        {//parcours de la liste
            courant = courant->suivant;
        }
        courant->suivant = nouvelle;//ajout en suivant du denier maillon
    }

    //confirmation
    system("CLS");
    printf("La voiture a bien ete enregistree dans la base de donnees\n");
    system("pause");

    //rendu de l'ancre
    return ancre;
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
    ///déclarations
    t_voiture * courant;

    if(ancre != NULL)
    {//si il y a au moins une voiture dans la liste
        system("CLS");
        courant = ancre;//initialisation de la var de parcours

        while(courant->suivant!=NULL)
        {//parcours
            affichageStruct(courant);//affichage
            printf("\n");
            courant = courant->suivant;//parcours de la liste
        }
        affichageStruct(courant);//affichage de la dernière voiture
        system("pause");//tempo
    }
    else
    {//message d'erreur si dtb vide
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
    ///déclarations
    FILE * fichier;
    FILE * nbsauvegarde;

    int compteur = 0;

    t_voiture * courant;

    //ouverture des fichiers
    fichier = fopen("base_donnee.txt", "w");
    nbsauvegarde = fopen("nbSauv.txt", "w");

    if(fichier != NULL && nbsauvegarde!= NULL && ancre != NULL)
    {//si les fichiers sont ouvert et au moins une voiture est enregistrée

        courant = ancre;//variable de parcours

        while(courant->suivant!=NULL)
        {
            compteur++;//compteur de voiture du système
            sauvegardeStruct(courant, fichier);//sauvegarde de la voiture
            courant = courant->suivant;//passage à la voiture suivant
        }
        sauvegardeStruct(courant, fichier);//sauvegarde de la dernière voiture
        fprintf(nbsauvegarde, "%d", (compteur+1));//sauvegarde du nb de voiture

        //messages de confirmation
        printf("La base de donnee a bien ete sauvegardee\n");
        system("pause");

        //fermeture des fichiers
        fclose(fichier);
        fclose(nbsauvegarde);
    }

    else
    {//message d'erreur su pb dans les fichiers
        system("CLS");
        printf("Sauvegarde impossible, base de donnee vide\n");
        system("pause");
    }
}
////////////////////////////////////////////////////////////////

//SAUVEGARDE DES STRUCUTRES/////////////////////////////////////
void sauvegardeStruct (t_voiture * maStruct, FILE * fichier)
{
    //ecriture fichier
    fprintf(fichier, "%s\t", maStruct->marque);
    fprintf(fichier, "%s\t", maStruct->immatriculation);
    fprintf(fichier, "%c\t", maStruct->essence);
    fprintf(fichier, "%d\n", maStruct->anneeProd);
}
////////////////////////////////////////////////////////////////

//RECUPERATION DTB//////////////////////////////////////////////
t_voiture * recuperationListe ()
{
    ///déclaration
    t_voiture * ancre = NULL;
    t_voiture * nouvelle = NULL;

    FILE * fichier;
    FILE * nbSauvegarde;

    char marque [100];
    char immatriculation [100];
    char essence;
    int anneProd;

    int nombre;

    //ouverture des fichiers
    fichier = fopen("base_donnee.txt", "r");
    nbSauvegarde = fopen("nbSauv.txt", "r");

    if(fichier != NULL && nbSauvegarde != NULL)
    {//si le fichier est ouvert

        //lecture du nombre de sauvegardes
        fscanf(nbSauvegarde, "%d", &nombre);

        for(int i=0; i<nombre; i++)
        {//pour le nombre de voitures dans le système
            //lecture des attributs
            fscanf(fichier, "%s", marque);
            fscanf(fichier, "%s", immatriculation);
            fscanf(fichier, "%c", &essence);//cette lecture lit l'espace entre l'immatriculation et l'essence
            fscanf(fichier, "%c", &essence);
            fscanf(fichier, "%d", &anneProd);

            //allocation dynamique de la structure
            nouvelle = (t_voiture *) malloc (sizeof(t_voiture));

            if(nouvelle != NULL)
            {//si alloc reussie
                //stockage des données dans la struct
                nouvelle->marque=phraseDynamiqueRecup(marque);
                nouvelle->immatriculation=phraseDynamiqueRecup(immatriculation);
                nouvelle->essence=essence;
                nouvelle->anneeProd=anneProd;
                nouvelle->suivant=NULL;

                //chainage du maillon
                ancre = ajoutFin(nouvelle, ancre);
            }
        }
    }

    //rendu du maillon ancre
    return ancre;
}
////////////////////////////////////////////////////////////////



//SAISIE PHRASE DYNA////////////////////////////////////////////
char * phraseDynamiqueRecup (char stockage [100])
{
    ///déclarations
    char * phrase;
    int longueur;

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
