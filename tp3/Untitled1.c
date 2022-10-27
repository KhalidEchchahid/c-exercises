#include<stdio.h>
#include<stdlib.h>
#include<string.h>
////////////////////QUESTION1//////////////////////////////////////
typedef struct {
	char nom[15];
	char prenom[15];
	char Departement[15];
	double nbreHeures;
	double Base;
	}Employee;
	
////////////////////QUESTION2//////////////////////////////////////
Employee * SaisieEmployee(Employee* T, int N){
	int i;
	T=(Employee*)malloc(sizeof(Employee));
	if(T==NULL) printf("Echec d allocation!");
	else {
		for (i=0; i<N; i++) {
			printf("\nDonner le nom de l Employee %d: ",i+1);
			scanf("%s",&(T+i)->nom);
			printf("\n Donner le prenom de l Employee %d: ",i+1);
			scanf("%s",&(T+i)->prenom);
			printf("\n Donner le departement de l Employee %d: ",i+1);
			scanf("%s",&(T+i)->Departement);
			printf("\n Donner le nombre d heures de l Employee %d: ",i+1);
			scanf("%lf",&(T+i)->nbreHeures);
			printf("\n Donner la base du salaire de l Employee %d: ",i+1);
			scanf("%lf",&(T+i)->Base);
		} 
	}
	return T; 
}
////////////////////QUESTION3//////////////////////////////////////
void AffichageEmployee(Employee* T, int N){
	int i;
	for (i=0; i<N; i++) {
		printf("Le nom: %s\n",(T+i)->nom);
		printf("Le prenom: %s\n",(T+i)->prenom);
		printf("Le Departement: %s\n",(T+i)->Departement);
		printf("Le Salaire: %2f\n",((T+i)->nbreHeures)*((T+i)->Base));
	}
}

////////////////////QUESTION4//////////////////////////////////////
float MoyenneSalaire(Employee * e, int N){
	int i;
	float som=0;
	for (i=0; i<N; i++) som+=(e[i].nbreHeures)*(e[i].Base);
	return som/N; 
}

void ListeEmployee(Employee* T, int N) {
	int i;
	for (i=0; i<N; i++) {
		if((T[i].nbreHeures)*(T[i].Base)> MoyenneSalaire((T+i),N))
			printf("%s %s\n", T[i].nom, T[i].prenom); 
	} 
}

////////////////////QUESTION5//////////////////////////////////////
void rechercheEmployeeNom (Employee * T, int N){
	int i;
	int OK=0;
	char Nom[10];
	printf("Saisir le nom a chercher : ");
	scanf("%s", Nom);
	for (i=0; i<N; i++) {
		if (strcmp(T[i].nom, Nom)==0) {
			printf("%s %s\n", T[i].nom, T[i].prenom);
	    	OK=1; 
		} 
	}
	if (!OK) printf ("Employee introuvable"); 
}
	
////////////////////QUESTION6//////////////////////////////////////
int main(){
	int N; 
	Employee * T;
	printf("Donner le nombre des Employees: ");
	scanf("%d",&N);
	T=SaisieEmployee(T, N);
	
	AffichageEmployee(T, N);
	
	printf("\n*************Liste Employees Salaire: \n");
	ListeEmployee(T, N);
	
	rechercheEmployeeNom(T,N); 
}
