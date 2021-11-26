#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Compte{
    char CIN[10];
    char nom[20];
    char prenom[20];
    float montant;
}Compte;
int indextablegen=0;


Compte T[20];

int num = 0;
/*fonction un seul ajout ***/
void ajout_client(Compte T[])
{
        int i= num;
        printf("CIN     :");
        scanf("%s",T[i].CIN);
        printf("Nom     :");
        scanf("%s",T[i].nom);
        printf("Prenom  :");
        scanf("%s",T[i].prenom);
        printf("Montant :");
        scanf("%f",&T[i].montant);
        indextablegen++;
     
}
/*fonction plusieur Ajout ***/
void ajout_plusieurs_clients(Compte T[],int nb)
{
    int i;
        printf("entrez le nombre de compte bancaire que vous souhaitez creer: \n");
        scanf("%d",&nb);
        int c=1;
        for(i=num;i<nb+num;i++)
    {
        printf("Copmte N%d: \n",c);c++;
        printf("CIN     :");
        scanf("%s",T[i].CIN);
        printf("Nom     :");
        scanf("%s",T[i].nom);
        printf("Prenom  :");
        scanf("%s",T[i].prenom);
        printf("Montant :");
        scanf("%f",&T[i].montant);
    }
    num = num + nb;
}
//fct de recherche//
int recherche(Compte T[],int n)
{
    char temp[10];
    printf("veuillez entrer voutre numero de cin: \n");
    scanf("%s",temp);
    for(int i =0;i<n;i++)
    {
        int c = strcmp(temp,T[i].CIN);
        if (c==0)
    {
        printf("BIEVENUE A VOTRE COMPTE: \n");
        return i;
    }
    }
    printf("le compte demande est inexistant: \n");
    return -1;
     
}
//*fct retrait*//
void retrait (Compte T[],int i)
{
     float somme;
    if (i>=0)
    {
    printf("COMBIEN VOULIEZ VOUS RETIRER DE CE COMPTE:");
    scanf("%f",&somme);
    }
    if(somme >=0)
    {
     T[i].montant = T[i].montant - somme;
     printf("votre solde apres le retrait est:%f. votre banque vous remercie\n",T[i].montant);  
    }
    else 
        printf("vous pouvez pas rentrer un montant preceder d un moins");
     
}
//*fct depot*//
void depot (Compte T[],int i)
{
     float somme;
    if (i>=0)
    {
    printf("COMBIEN VOULIEZ VOUS DEPOSEZ SUR CE COMPTE:");
    scanf("%f",&somme);
    }
    if(somme >=0)
    {
     T[i].montant = T[i].montant + somme;
     printf("votre solde apres le depot est:%.2f votre banque vous remercie\n",T[i].montant);  
    }
    else 
        printf("vous pouvez pas rentrer un montant preceder d un moins");
     
}
//* fct d affichage**//
void affichage ()
{
    int i;
    for(i=0;i<num;i++)
    {
    printf("\n\nle numero de la cin est:                %s\n",   T[i].CIN);
    printf("le nom du titulaire du Compte est:      %s\n",  T[i].nom);
    printf("le prenom du titulaire du Compte est:   %s\n",   T[i].prenom);
    printf("le montant au compte s'eleve a:         %f\n\n",   T[i].montant);  
    }
}



//* fct de tri ascendant*//
void triA(Compte T[],int n)
{
    
    Compte tat;
   
    int i,j;
    for( i=0 ;i<n;i++)
        for( j=0 ;j<n ;j++)
        {
          if(T[i].montant<T[j].montant)
            {
                tat=T[i];
                T[i]=T[j];
                T[j]=tat;
            }  
        }
}
//* fct de tri descendant*//
void triD(Compte T[],int n)
{
    Compte tat;
   
    int i,j;
    for( i=0 ;i<n;i++)
        for( j=0 ;j<n ;j++)
          if(T[i].montant>T[j].montant)
            {
                tat=T[i];
                T[i]=T[j];
                T[j]=tat;
            }  
}

int main()
{
    int n,f ;
    int a=1;
    int i=1;
    int choix;
    int choisir;
    int chiffre_tri;
    while(a)
    {
        printf("BIENVENUE AU MENU PRINCIPALE\n");
        printf("1: creation de un seul compte.\n");
        printf("2: creer plusieurs compte appartenant a un ou plusieurs utilisateurs.\n");
        printf("3: Operations de rerait et de depot.\n");
        printf("4: decouvrez nos options de tri selon vos criteres :\n ");
        printf("5: afficher :\n ");
        printf("faites votre choix en choisissant un numero: \n");
        scanf("%d",&f);
        switch(f)
        {
            case 1:
            ajout_client(T);
            break;
           
            case 2:
            ajout_plusieurs_clients(T,n);
            break;
                case 3:
                printf("1)retrait\n");
                printf("2)depot\n");
                printf("faites votre choix en choisissant un numero: \n");
                scanf("%d",&choix);
                 switch(choix)
                {
                    case 1:
                    i = recherche(T,n);
                    retrait(T,i);
                    break;
                   
                    case 2:
                    i = recherche(T,n);
                    depot(T,i);
                    break;
                   
                }
                break;
            case 4:
                printf("1)tri de maniere ascendante\n");
                printf("2)tri de maniere descendante\n");
                printf("faites votre choix en choisissant un numero: \n");
                scanf("%d",&choisir);

            switch(choisir)
               {
                 case 1  :
               triA(T,num);
               affichage(T,num);
                break;
             
                 case 2:
               triD(T,num);
               affichage(T,num);
               break;
               }
               
            break;

            case 5:
            affichage();
                break;
            
               
        }
    }
    return 0;
}
