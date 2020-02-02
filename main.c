#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include<windows.h>
#include <sys/types.h>/*creation de repertoire*/
#include <sys/stat.h>/*creation de repertoire*/
#include <io.h>

long file_size(char *text);


void print_creationdate(char *s) {
  WIN32_FILE_ATTRIBUTE_DATA attr;
  SYSTEMTIME creation;

  GetFileAttributesEx(s, GetFileExInfoStandard, &attr);
  FileTimeToSystemTime(&attr.ftCreationTime, &creation);
  printf("La Date de Creation :date : %d/%d/%d - %d h %d", creation.wDay,
         creation.wMonth, creation.wYear, creation.wHour, creation.wMinute);
}



int main(void)
{
    int reponse;
    time_t t = time(NULL);
    printf(">>>>>>>bonjour vous etes sur la machine de Jalal en mode Gestion de fichiers à %s  \n",ctime(&t));
    printf(">>>>>>> vous pouvez gerer vos fichiers et vos repertoires facilement\n");
    printf("\n");
    printf("\n\n");
    printf("VOUS ETES SUR>>> \t");
    char tampon[UCHAR_MAX];

    if (getcwd (tampon, UCHAR_MAX) == NULL) {
        return EXIT_FAILURE;
    }
    puts (tampon);
    printf("\n");
    printf("\n");
    printf("      1-lister les fichiers et repertoires du repertoire courant\n");/*Done*/
    printf("      2-creer un fichier\n");/*Done*/
    printf("      3-creer un repertoire\n");/*Done*/
    printf("      4-copier un fichier\n");/*Done*/
    printf("      5-copier un repertoire et ses fils \n");/*Done */
    printf("      6-supprimer un fichier\n");/*Done*/
    printf("      7-supprimer un repertoire recursivement\n");/*Supprimer un repertoire*/
    printf("      8-renommer un fichier\n");/*Done*/
    printf("      9-renommer un repertoire recursivement\n");/*Done*/
    printf("      10-depalcer un fichier\n");/*Done*/
    printf("      11-deplacer un repertoire recursivement\n");/*Done*/
    printf("      12-details**taille+date de creation** sur  un fichier\n");/*details*/
    printf("      13-Effacer contenu du console\n");
    printf("      14-rechercher si un fichier existe \n");/*Done*/
    printf("      15-se deplacer vers un  autre repertoire\n");/*Done*/
    printf("      16-contenu d'un fichier\n");/*Done*/
    printf("      17-Ecrire dans le fichier\n");/*Done*/
    printf("      18-comparer 2 fichiers\n");
    printf("      19-quitter\n");/*Done*/
    printf("      1998-vous avez oublie les num de commandes\n");/*Done*/
    printf("\n");
    printf("\n");
    printf(">>>>>>>ENTREZ LE NUMERO DE COMMANDE:\n");
    scanf("%d",&reponse);
    while (reponse!=19)
    {
        if(reponse==1998)
            {
                printf("\n");
                printf("\n");
    printf("   1-lister les fichiers et repertoires du repertoire courant\n");/*Done*/
    printf("   2-creer un fichier\n");/*Done*/
    printf("   3-creer un repertoire\n");/*Done*/
    printf("   4-copier un fichier\n");/*Done*/
    printf("   5-copier un repertoire et ses fils \n");
    printf("   6-supprimer un fichier\n");/*Done*/
    printf("   7-supprimer un repertoire recursivement\n");/*Supprimer un repertoire*/
    printf("   8-renommer un fichier\n");/*Done*/
    printf("   9-renommer un repertoire recursivement\n");
    printf("   10-depalcer un fichier\n");/*Done*/
    printf("   11-deplacer un repertoire recursivement\n");/*Done*/
    printf("   12-details**taille+date de creation** sur  un fichier\n");/*details*/
    printf("   13-effacer contenu du console\n");
    printf("   14-rechercher si un fichier existe \n");/*Done*/
    printf("   15-se deplacer vers un  autre repertoire\n");/*Done*/
    printf("   16-contenu d'un fichier\n");/*Done*/
    printf("   17-Ecrire dans le fichier\n");/*Done*/
    printf("   18-comparer 2 fichiers\n");/*Done*/
    printf("   19-quitter\n");/*Done*/
            printf(">>>>>>>>ENTREZ LE NUMERO DE COMMANDE:");
            scanf("%d",&reponse);
            printf("\n\n");
            }

            if (reponse==1)/*lister les fils*/
            {
                printf("VOUS ETES SUR>>> \t");
                char tampon[UCHAR_MAX];

                if (getcwd (tampon, UCHAR_MAX) == NULL)
                {return EXIT_FAILURE;}
            puts (tampon);
            struct dirent *lecture;
            DIR *rep; rep = opendir("." );
            while ((lecture = readdir(rep)))
                {printf("%s\t \t", lecture->d_name);}
            closedir(rep);
            printf("\n\n");
            printf(">>>>>>>>ENTREZ LE NUMERO DE COMMANDE:\n");
            scanf("%d",&reponse);
            }
            if (reponse==2)//Creation du fichier
                {
                    printf("*********************CREATION DU FICHIER********\n");
                    printf("\n");
                     printf("\n");
                    printf("********entrer le nom du fichier:\t");
                    char nom;
                    scanf("%s",&nom);

                    FILE * f;
                    f = fopen("hello.txt", "w");
                    fclose(f);
                    char* old = "hello.txt";
                    char* new =&nom;

                    if (rename(old,new) == -1)
                        {
                            perror("rename");
                        }


                     printf("*****Creation avec Succes");
                     printf("\n");
                    printf(">>>>>>>>>ENTREZ LE NUMERO DE COMMANDE:");
                    scanf("%d",&reponse);


                }
        if (reponse==8)//renommer
        {

                    printf("*****Modification de Nom***");
                    printf("\n");
                    char oldName[100], newName[100];


                    printf("Enter l'ancien nom: ");
                    scanf("%s", oldName);

                    printf("Entrer le nouveau nom: ");
                    scanf("%s", newName);
                if (rename(oldName, newName) == 0)
                {
                    printf("+++traitement avec succes :D .\n");
                    }
                else
                {
            printf("error.\n");
                }

                printf("\n");
                printf("\n");
                printf(">>>>>>>>>ENTREZ LE NUMERO DE COMMANDE:");
                    scanf("%d",&reponse);
        }
        if (reponse==6)//remove
        {   printf("******Suppression de fichier****\n");
            printf("entrer le nom du fichier a supprimer:\t");
            char ancien;
            scanf("%s",&ancien);
            char* olde = &ancien;
            remove(olde);
            printf("***Suppression Avec Succes");
             printf("\n");
            printf(">>>>><>>>ENTREZ LE NUMERO DE COMMANDE:");
            scanf("%d",&reponse);

        }

        if (reponse==4)// copier un fichier
        {
            printf("****la copie des fichiers");
            printf("\n");
            FILE *fp1, *fp2;
            char ch;

            char f1[100], f2[100];
            printf("Enter le nom du fichier a copier: ");
            scanf("%s",f1);
            printf("Entrer le nouveau nom avec le chemin: ");
            scanf("%s",f2);
            // ouvrir le fichier en lecture
            fp1 = fopen(f1, "r");
            // ouvrir le fichier en écriture
            fp2 = fopen(f2, "w");
            // Lire le contenu du fichier
            while((ch = getc(fp1)) != EOF)
            {putc(ch, fp2);}
            fclose(fp1);
            fclose(fp2);
            printf("\n\n");
            printf(">>>>ENTREZ LE NUMERO DE COMMANDE:");
            scanf("%d",&reponse);
        }
        if(reponse==16)/*contenu d'un fichier*/
        {

             printf("*******CONTENU DE FICHIER\n");
             printf("Quelle fichier vous voulez voir son Contenu:");
             char f1[1000];
             scanf("%s",f1);
             FILE* fichier = NULL;
            char chaine[150] = ""; // Chaîne vide de taille TAILLE_MAX

            fichier = fopen(f1,"r");

        if (fichier != NULL)
        {
            fgets(chaine, 1500, fichier); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "chaine"
            printf("%s", chaine); // On affiche la chaîne

            fclose(fichier);
             printf("\n");
             printf("\n");
            printf(">>>>>>>>ENTREZ LE NUMERO DE COMMANDE:");
            scanf("%d",&reponse);
        }


        }



        if(reponse==10)/*depalcer un fichier*/
        {


            printf("*****DEPLACEMENT DE FICHIER*****\n");
            char f1[100], f2[100];
            printf("Enter le nom du fichier a copier: ");
            scanf("%s",f1);
            printf("Entrer le nouveau nom avec le chemin: ");
            scanf("%s",f2);


            FILE * f_src = NULL;
            FILE * f_dst = NULL;
            int c;

            f_src = fopen(f1,"r");

            if (!f_src) {
            fprintf(stderr,"Cannot open the source file !\n");
                //exit(EXIT_FAILURE);
                }

            f_dst = fopen(f2,"w");

        if (!f_dst) {
            fprintf(stderr,"Cannot open the destination file !\n");
            //exit(EXIT_FAILURE);
            }

        /* Exple de traitement-copie ... */
        while( (c = fgetc(f_src)) != EOF) {
                if (!isdigit(c)) { fputc(c, f_dst); }
            }

            fclose(f_dst);
            fclose(f_src);

        if ( remove(f1) )
        {
                    fprintf(stderr,"Cannot remove the source file !\n");
            //exit(EXIT_FAILURE);
                    }
        else {
            puts("OK, job done ;-)");
                }
                 printf("\n");
                 printf("\n");
            printf(">>>>>>>>>ENTREZ LE NUMERO DE COMMANDE:");
            scanf("%d",&reponse);
                }
            if (reponse==17)//ecriture dans un fichier
            {
            printf("****ECRITURE DANS UN FICHIER*****\n");
            FILE* fichier = NULL;
            char age[100];
            char oldName[100];
            printf("Entrer le nom du fichier: ");
            scanf("%s", oldName);

            fichier = fopen(oldName,"w");

            if (fichier != NULL)
            {
            // On demande l'âge
            printf("Vas-y ecris:");
            scanf("%s",&age);

            // On l'écrit dans le fichier
            fprintf(fichier, "%s ", age);
            fclose(fichier);
            printf("*****ECRITURE AVEC SUCCES");
             printf("\n");
              printf("\n");
            printf(">>>>>>>>>ENTREZ LE NUMERO DE COMMANDE:\n");
            scanf("%d",&reponse);
                }
            }
         if (reponse==3)//creation repertoire
         {

            /*system("mkdir c:\\repertoire\\sous_repertoire");*/
            /*exemple: C:\\Users\\HP\\Desktop\\ji*/
            printf("*****CREATION DE REPERTOIRE*****\n");
            printf("Quelle est le nom du repertoire:");
            char f1[100];
            scanf("%s",f1);
            mkdir(f1);
            printf("creation avec Succes");
            printf("\n");
             printf("\n");
            printf(">>>>>>>ENTREZ LE NUMERO DE COMMANDE:");
            scanf("%d",&reponse);
         }
         if(reponse==7)/*SUppression d'un repertoire*/
         {
             printf("*****SUPPRESSION DE REPERTOIRE*****\n");
             printf("Quelle est le nom du repertoire a supprimer:");
            char f1[100];
            scanf("%s",f1);
            force_rmdir(f1);
            printf("Suppresion avec Succes");
            printf("\n");
             printf("\n");
            printf(">>>>>>>ENTREZ LE NUMERO DE COMMANDE:");
            scanf("%d",&reponse);
         }

         if(reponse==12)/*details sur un fichier */
            {
                printf("*****DETAILS D UN FICHIER*****\n");
            printf("Quelle est le nom du fichier pour details:");
            char f1[100];
            scanf("%s",f1);
            printf("Le nombre de caracteres  dans ce fichier: %ld\n", file_size(f1));
            printf("\n");
            print_creationdate(f1);
            printf("\n");
            printf(">>>>ENTREZ LE NUMERO DE COMMANDE:");
            scanf("%d",&reponse);
                }
            if(reponse==15)/*changer direction*/
                {
                    printf("**********************ChANGEMENT DE DIRECTION********");
                    printf("Quelle est votre nouveau chemin:");
                    char f1[100];
                    scanf("%s",f1);
                    SetCurrentDirectory(f1);
                    printf("\n");
                    printf(">>>>ENTREZ LE NUMERO DE COMMANDE:");
                    scanf("%d",&reponse);
                }
                if(reponse==14)/*Verification existance*/
                {
                    printf("**********************VERIFICATION EXISTANCE********");
                    printf("**********Quelle fichier vous cherchez:");
                    char f1[100];
                    scanf("%s",f1);
                    FILE * fichier = fopen(f1,"r+");

            if (fichier == NULL)
            {   printf("\n");
                printf("---le fichier N Existe Pas ----");
                printf("\n");
            printf(">>>>ENTREZ LE NUMERO DE COMMANDE:");
            scanf("%d",&reponse);
            }
            else
        {
                printf("\n");
                printf("++++le fichier Existe  +++");
                fclose(fichier);
                printf("\n");
            printf(">>>>ENTREZ LE NUMERO DE COMMANDE:");
            scanf("%d",&reponse);
        }
                }



                if (reponse==18)//Comparaison de 2 fichiers
                {
                    printf("*******COMPARAISON DE 2 FICHIERS***\n");
                    printf("\n");
                    printf("****le nom du premier fichier:");
                    char f1[100];
                    scanf("%s",f1);
                    printf("\n");
                    printf("****le nom du deuxieme fichier:");
                    char f2[100];
                    scanf("%s",f2);
                    FILE * a= fopen(f1,"r");
                    FILE * b= fopen(f2,"r");
                    int p=0;
                    int k=0;
                    char x = fgetc(a);
                    char y = fgetc(b);
                    if(((x==EOF)&&(y!=EOF))||(((y==EOF)&&(x!=EOF))))
                    {
                       printf("different");
                       k++;
                    }
                    while(x!=EOF && y!=EOF ){
                    x = fgetc(a);
                    y = fgetc(b);
                    if(x!=y)
                    p++;
                    }
                    if(p==0 &&k==0){printf("identique ");}
                    if((p>0)&&k==0){printf("different");}
                    printf("\n");
                printf(">>>>ENTREZ LE NUMERO DE COMMANDE:");
                scanf("%d",&reponse);

                }

                if (reponse==9)
                {
                   printf("*******Modification de nom du Repertoire\n");
                    printf("\n");
                    printf("****le nom du repertoire:");
                    char f1[100];
                    scanf("%s",f1);
                    printf("\n");
                    printf("****Entrez le nouveau nom:");
                    char f2[100];
                    scanf("%s",f2);
                    rename(f1,f2);
                    printf("+++traitement avec succes :D .\n");
                    printf("\n");
                printf(">>>>ENTREZ LE NUMERO DE COMMANDE:");
                scanf("%d",&reponse);
                }
                if(reponse==11)
                {
                    printf("*******Deplacement du repertoire");
                    printf("\n");
                    printf("entrez le nom du repertoire:");
                    char f1[100];
                    scanf("%s",f1);
                    printf("\n");
                    printf("Entrez le nouveau chemin:");
                    char f2[100];
                    scanf("%s",f2);
                    rename(f1,f2);
                    force_rmdir(f1);//supprimer
                    printf("+++traitement avec succes :D+++ .\n");
                    printf("\n");
                printf(">>>>>>ENTREZ LE NUMERO DE COMMANDE:");
                scanf("%d",&reponse);
                }
                if (reponse==13)
                {
                    system("cls");
                     printf("      1-lister les fichiers et repertoires du repertoire courant\n");/*Done*/
    printf("      2-creer un fichier\n");/*Done*/
    printf("      3-creer un repertoire\n");/*Done*/
    printf("      4-copier un fichier\n");/*Done*/
    printf("      5-copier un repertoire et ses fils \n");/*Done */
    printf("      6-supprimer un fichier\n");/*Done*/
    printf("      7-supprimer un repertoire recursivement\n");/*Supprimer un repertoire*/
    printf("      8-renommer un fichier\n");/*Done*/
    printf("      9-renommer un repertoire recursivement\n");/*Done*/
    printf("      10-depalcer un fichier\n");/*Done*/
    printf("      11-deplacer un repertoire recursivement\n");/*Done*/
    printf("      12-details**taille+date de creation** sur  un fichier\n");/*details*/
    printf("      13-Effacer contenu du console\n");
    printf("      14-rechercher si un fichier existe \n");/*Done*/
    printf("      15-se deplacer vers un  autre repertoire\n");/*Done*/
    printf("      16-contenu d'un fichier\n");/*Done*/
    printf("      17-Ecrire dans le fichier\n");/*Done*/
    printf("      18-comparer 2 fichiers\n");
    printf("      19-quitter\n");/*Done*/
    printf("      1998-vous avez oublie les num de commandes\n");/*Done*/
    printf(">>>>>>ENTREZ LE NUMERO DE COMMANDE:");
                scanf("%d",&reponse);

                }



            }

            system("cls");
            printf("***Good By****");





    }






















void force_rmfile(char *filename)
{
	FILE *f = fopen(filename, "r") ;
	if (! f)
		return ;
	fclose(f) ;
	chmod(filename, S_IWRITE) ;
	remove(filename) ;
}







    void force_rmdir(char *dirname)
{
	DIR *dir;
	struct dirent *ent;
	dir = opendir(dirname) ;
	if (! dir)
	{
		force_rmfile(dirname) ;
		return ;
	}
	while((ent = readdir(dir)) != NULL)
	{
		if (ent->d_name[0] == '.')
		continue ;
		char *filename = malloc(strlen(dirname) + 1
			+ strlen(ent->d_name) + 1
			+ 1) ;
		strcpy(filename, dirname) ;
		strcat(filename, "\\") ;
		strcat(filename, ent->d_name) ;
		force_rmdir(filename) ;
		free(filename) ;
	}
	rmdir(dirname) ;
}



long file_size(char *text)
{
   /*Ouverture du fichier*/
   FILE *file = fopen(text, "r");
   long ret;
   if(file == NULL)
   {
      return -1;
   }
   /*On place le curseur à la fin*/
   fseek(file, 0, SEEK_END);
   /*On récupére la position courante*/
   ret = ftell(file);
   fclose(file);
   return ret;
}










