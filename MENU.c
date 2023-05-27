#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct date{

 	int j;
 	int m;
 	int a;

 }date;



 // structure client------------------------
 typedef struct{

 	char cin[100];
 	char nom[100];
 	char prenom[100];
 	char ville[100];
 	date dtn ;

 }client;

 // structure - comptebancaire------------------------
 typedef struct comptebancaire{

 	int numeroc;
 	date dc;
 	char loc[100];
 	client pr[100];
 	char vc[50];
 	int sa;
 	int as;
 	char dr [100];



 }comptebancaire;




//-------------------------------------------------------------------------------------------------------------------------
int searchcin(char chcin[],client tcl[],int t1)
  {

  	int i;

   for(i=0;i<t1;i++)
    {
	  if(strcmp(tcl[i].cin,chcin)==0)
        return i;
    }
        return -1;

}
//-------------------------------------------------------------------------------------------------------------------------
int searchnc(int nc, comptebancaire tcb[],int t2)
  {

  	int i;

   for(i=0;i<t2;i++)
    {
	  if(tcb[i].numeroc==nc)
        return i;
    }
    return -1;
}

//-------------------------------------------------------------------------------------------------------------------------
void  ajoutecl(client tcl[],int t1)
{

   int i;
   char chcin[8];


   puts("Donner le Cin: ");
   fflush(stdin);gets(chcin);
   if(searchcin(chcin,tcl,t1)!=-1)
   {
      do{
      	  puts("ce cin deja existant.");
   	      printf("Donner un nouveau cin:");
   	      scanf("%s",chcin);
        }while(searchcin(chcin,tcl,t1)!=-1);
        t1++;
   }
   else
   {



    for(i=0;i<7;i++)
   	(tcl+t1)->cin[i]=chcin[i];
   }
   printf("\nÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
   printf("\n³                           ³ ");
   printf("\n³         CLIENT %d          ³",t1);
   printf("\n³                           ³ ");
   printf("\nÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n ");

   puts(" Nom: ");gets((tcl+t1)->nom);
   puts(" Prenom: ");gets((tcl+t1)->prenom);
   puts(" Ville: ");gets((tcl+t1)->ville);

   printf("Saisir la date de naissance: \n");
        printf("Jour: ");scanf("%d",&(tcl+t1)->dtn.j);
        printf("Mois: ");scanf("%d",&(tcl+t1)->dtn.m);
        printf("Annee: ");scanf("%d",&(tcl+t1)->dtn.a);



}
//-------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------
void listercl(client tcl[],int t1)
{
	int i;

	for(i=0;i<t1;i++)
	{

		 printf("CIN: %s",(tcl+i)->cin);printf("\n");
		 printf("Nom: %s",(tcl+i)->nom);printf("\n");
         printf("Prenom: %s",(tcl+i)->prenom);printf("\n");
         printf("Ville: %s",(tcl+i)->ville);printf("\n");

        printf("la date de naissance: \n");
          printf("Jour: %d",(tcl+i)->dtn.j);printf("\n");
          printf("Mois: %d",(tcl+i)->dtn.m);printf("\n");
           printf("Annee: %d",(tcl+i)->dtn.a);printf("\n");
	}
}
//-------------------------------------------------------------------------------------------------------------------------
void listerc(comptebancaire tcb[],int t2)
{
	int i;

	for(i=0;i<t2;i++)
	{

		 printf("NumeroduCompte: %d",(tcb+i)->numeroc);printf("\n");
		 printf("Date de Creation: \n");
		    printf("Jour: %d",(tcb+i)->dc.j);printf("\n");
		    printf("Mois: %d",(tcb+i)->dc.m );printf("\n");
		    printf("Annee: %d",(tcb+i)->dc.a );printf("\n");
	    printf("Localisation du client: %s",(tcb+i)->loc);printf("\n");
        printf("Proprietaire: %s",(tcb+i)->pr );printf("\n");

	}
}

//-------------------------------------------------------------------------------------------------------------------------

int depot(comptebancaire tcb[],int t2){

	comptebancaire as, sa , dr;
	int i,ps;
	float mon;


	printf("donner votre position ");
	scanf("%d",&ps);
	printf("donner le montant  ");
	scanf("%f",&mon);


	tcb[ps].as=tcb[ps].sa;
	tcb[ps].sa=tcb[ps].sa+mon;



}
//-------------------------------------------------------------------------------------------------------------------------






//-------------------------------------------------------------------------------------------------------------------------
void main(){

   char chcin[20];
   int r,x,mc;
   char c[5];
   int t1=1,t2=1;


     client cl ,tcl[20];
     comptebancaire cb,tcb[20];
     //tcl=&cl;
     //tcb=&cb;


    strcpy(tcl[0].cin,"14");
    strcpy(tcl[0].nom,"ahmed");
    strcpy(tcl[0].prenom,"kilani");
    strcpy(tcl[0].ville,"tinghir");
    tcl[0].dtn.j=14;
    tcl[0].dtn.m=6;
    tcl[0].dtn.a=1995;

    tcb[0].numeroc=0001;
    tcb[0].dc.j=4;
    tcb[0].dc.m=11;
    tcb[0].dc.a=2020;
    strcpy(tcb[0].loc,"marrakech");
    strcpy(tcb[0].pr,"14");
    tcb[0].sa=0;
	tcb[0].as=0;
    strcpy(tcb[0].dr,"pas de operation");



     //test client ou non -------------------------------------
     system("pause");
     system("cls");

   textcolor(3);gotoxy(68,5);cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
   textcolor(3);gotoxy(68,6);cprintf("³                           ³ ");
   textcolor(3);gotoxy(68,7);cprintf("³ VOUS AVEZ DEJA UN COMPTE! ³ ");
   textcolor(3);gotoxy(68,8);cprintf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ");
   textcolor(3);gotoxy(68,9);cprintf("³   1-OUI     ³    0-NON    ³ ");
   textcolor(3);gotoxy(68,10);cprintf("³             ³             ³ ");
   textcolor(3);gotoxy(68,11);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ");

   textcolor(3);gotoxy(78,12);cprintf(" ÚÄÄÄÄÄ¿");
   textcolor(3);gotoxy(78,13);cprintf(" ³     ³");
   textcolor(3);gotoxy(78,14);cprintf(" ÀÄÄÄÄÄÙ");
   textcolor(3);gotoxy(82,13);cscanf("%d",&r);


   if(r==1){
   system("cls");
   textcolor(3);gotoxy(68,7);cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
   textcolor(3);gotoxy(68,8);cprintf("³                      ³ ");
   textcolor(3);gotoxy(68,9);cprintf("³   DONNER VOTRE CIN   ³ ");
   textcolor(3);gotoxy(68,10);cprintf("³                      ³ ");
   textcolor(3);gotoxy(68,11);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ");
   textcolor(3);gotoxy(75,12);cprintf(" ÚÄÄÄÄÄ¿");
   textcolor(3);gotoxy(75,13);cprintf(" ³     ³");
   textcolor(3);gotoxy(75,14);cprintf(" ÀÄÄÄÄÄÙ");
   textcolor(3);gotoxy(78,13);fflush(stdin);cscanf("%s",chcin);


     // if - 1
     if(strcmp(chcin,tcl[0].cin)==0){
     //test ----------- compte----------------------------------------
a:
   system("cls");

   textcolor(3);gotoxy(50,18);cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
   textcolor(3);gotoxy(50,19);cprintf("³                      ³ ");
   textcolor(3);gotoxy(50,20);cprintf("³    1-  RETRAIT       ³ ");
   textcolor(3);gotoxy(50,21);cprintf("³                      ³ ");
   textcolor(3);gotoxy(50,22);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ");


   textcolor(3);gotoxy(50,24);cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
   textcolor(3);gotoxy(50,25);cprintf("³                      ³ ");
   textcolor(3);gotoxy(50,26);cprintf("³    2- VIREMENT       ³ ");
   textcolor(3);gotoxy(50,27);cprintf("³                      ³ ");
   textcolor(3);gotoxy(50,28);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ");



   textcolor(3);gotoxy(50,30);cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
   textcolor(3);gotoxy(50,31);cprintf("³                      ³ ");
   textcolor(3);gotoxy(50,32);cprintf("³      3- DEPOT        ³ ");
   textcolor(3);gotoxy(50,33);cprintf("³                      ³ ");
   textcolor(3);gotoxy(50,34);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ");



   textcolor(3);gotoxy(50,36);cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
   textcolor(3);gotoxy(50,37);cprintf("³                      ³ ");
   textcolor(3);gotoxy(50,38);cprintf("³  4- LISTER CLIENTS   ³ ");
   textcolor(3);gotoxy(50,39);cprintf("³                      ³ ");
   textcolor(3);gotoxy(50,40);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ");



   textcolor(3);gotoxy(90,18);cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
   textcolor(3);gotoxy(90,19);cprintf("³                      ³ ");
   textcolor(3);gotoxy(90,20);cprintf("³  5- LISTER COMPTES   ³ ");
   textcolor(3);gotoxy(90,21);cprintf("³                      ³ ");
   textcolor(3);gotoxy(90,22);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ");


   textcolor(3);gotoxy(90,24);cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
   textcolor(3);gotoxy(90,25);cprintf("³                      ³ ");
   textcolor(3);gotoxy(90,26);cprintf("³  6- DETAIL CLIENT    ³ ");
   textcolor(3);gotoxy(90,27);cprintf("³                      ³ ");
   textcolor(3);gotoxy(90,28);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ");


   textcolor(3);gotoxy(90,30);cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
   textcolor(3);gotoxy(90,31);cprintf("³                      ³ ");
   textcolor(3);gotoxy(90,32);cprintf("³  7- DETAIL COMPTE    ³ ");
   textcolor(3);gotoxy(90,33);cprintf("³                      ³ ");
   textcolor(3);gotoxy(90,34);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ");


   textcolor(3);gotoxy(90,36);cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
   textcolor(3);gotoxy(90,37);cprintf("³                      ³ ");
   textcolor(3);gotoxy(90,38);cprintf("³  8- SUPPRIMER CLIENT ³ ");
   textcolor(3);gotoxy(90,39);cprintf("³                      ³ ");
   textcolor(3);gotoxy(90,40);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ");



   textcolor(3);gotoxy(68,5);cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
   textcolor(3);gotoxy(68,6);cprintf("³                          ³ ");
   textcolor(3);gotoxy(68,7);cprintf("³ SELECTIONNER VOTRE CHOIX ³ ");
   textcolor(3);gotoxy(68,8);cprintf("³                          ³ ");
   textcolor(3);gotoxy(68,9);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ");

   textcolor(3);gotoxy(78,10);cprintf(" ÚÄÄÄÄÄ¿");
   textcolor(3);gotoxy(78,11);cprintf(" ³     ³");
   textcolor(3);gotoxy(78,12);cprintf(" ÀÄÄÄÄÄÙ");
   textcolor(3);gotoxy(82,11);cscanf("%d",&mc);

  	 switch (mc)
{
    //-----------------------------------------
    case 1:


    break;
    //-----------------------------------------

    case 2:

    break;
    //-----------------------------------------
    case 3:

    system("cls");

   textcolor(6);gotoxy(50,18);cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
   textcolor(6);gotoxy(50,19);cprintf("³                      ³ ");
   textcolor(6);gotoxy(50,20);cprintf("³                      ³ ");
   textcolor(6);gotoxy(50,21);cprintf("³                      ³ ");
   textcolor(6);gotoxy(50,22);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ");
   textcolor(7);gotoxy(52,20);cprintf("        DEPOT       ");



    printf("\n");
    depot(tcb,t2);
    system("pause");
    goto a;


    break;
    //-----------------------------------------
    case 4:
        system("cls");


        listercl(tcl,t1);
        system("pause");
        goto a;
    break;
    //-----------------------------------------
    case 5:
        system("cls");
        listerc(tcb,t2);
        system("pause");
        goto a;
    break;
    //-----------------------------------------
    case 6:

    break;
    //-----------------------------------------
    case 7:

    break;
    //-----------------------------------------
    case 8:

    break;
    //-----------------------------------------



     }
     }
     }

     // if-1
     else if(strcmp(chcin,tcl[0].cin)!=0 || r==0){


   system("cls");

   textcolor(3);gotoxy(68,5);cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
   textcolor(3);gotoxy(68,6);cprintf("³                              ³ ");
   textcolor(3);gotoxy(68,7);cprintf("³                              ³ ");
   textcolor(3);gotoxy(68,8);cprintf("³                              ³ ");
   textcolor(3);gotoxy(68,9);cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ");

   textcolor(7);gotoxy(69,7);cprintf("  vous devrez cree un compte  ");
   printf("\n");

   ajoutecl(tcl,t1);

    }







    system("pause");
   }
