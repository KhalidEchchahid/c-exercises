#include <stdio.h>
#include <stdlib.h>

int* Allouer(int n){

	int* taille ;
	taille = (int* )malloc(n*sizeof(int*));
	return taille ;
}

void saisie(int* T , int taille){
	int i ;
	for(i=0;i<taille ; i++){
		printf("Entrer l element du tableau numero %d :\t",i);
		scanf("%d",T+i);
	}
}

void affiche(int* T ,int taille){
	int i ;
	for (i=0 ;i<taille ;i++){
		printf("T[%d]=%d \n",i,*(T+i));
	}
}

int* Reallouer(int* T ,int taille){
	
	T=(int*)realloc(T,taille*sizeof(int *));
	return T;
}

void insereValeurs(int* T , int* taille , int ind , int N){
	if (ind > *taille || ind < 0 ){
		printf("erreur");
	}else{
		int i,j;
		for (i=0 ; i<N ; i++){
			if (i%2 !=0){
				*taille+=1;
				T=Reallouer(T,*taille);
				for(j=*(taille-1) ; j>=ind-1 ; j-- ){
					*(T+j+1)=*(T+j);
				}
				*(T+ind)=j;
				ind+=1;
			}
		}
	}
}

void tribulle(int*T ,int taille){
	
	int trie , i, tmp ;
	do{
		trie=1;
		for (i=1;i<taille;i++){
			if(*(T+i-1) > *(T+i)){
				tmp = *(T+i);
				*(T+i) = *(T+i-1);
				*(T+i-1) = tmp;
				trie=0;
			}
		}
	}while(trie==0);
}

void SupprimeDuplications(int* T ,int* taille){
	int i,j ;
	tribulle(T,*taille);
	for (i=0;i<*taille ; i++){
		if (*(T+i)==*(T+i+1)){
			for(j=i; j<*taille-1 ; j++){
				*(T+j)==*(T+j+1);
			}
			i--;
			*taille+=-1;
		}
	}
	T=Reallouer(T, (*taille));
}


void compareTableaux (int *T1, int n1, int *T2, int n2) {
	int i,j, C=0;
	if (n1==n2)
	{
		for (i=0;i<n1;i++){
			if (*(T1+i)==*(T2+i)) C++; 
		}
		if(C==n1) printf("\n ************** Identiques\n");
		else if (C==0) printf("\n ************** Ne coincident pas\n");
		else printf("\n ************** Coincident\n"); 
	}
	else {
		for (i=0;i<n1;i++){
			for (j=0;j<n2;j++){
				if (*(T1+i)==*(T2+j)) C++; 
			}
		}
		if(C==0)
		printf("\n ************** Ne coincident pas\n");
		else printf("\n ************** Coincident\n"); } 
}

int main(){
	int* T;
	int taille;
	int* T1;
	int *T2;
	int taille1,taille2;
	int N,ind ;
	printf("Entrer la taille du tableau : ");
	scanf("%d",&taille);
	T=Allouer(taille);
	saisie(T,taille);
	affiche(T,taille);
	printf("\n\n");
	

	printf("Entrer la nouveau taille du tableau : ");
	scanf("%d",&taille1);
	T1=Reallouer(T,taille1);
	affiche(T1,taille1);
	
	
	
	printf("\n");
	printf("Entrer la valeur a inserer : ");
	scanf("%d",&N);
	printf("Entrer l indice : ");
	scanf("%d",&ind);
	insereValeurs(T,&taille,ind,N);
	affiche(T,taille);
	printf("\n");

	
	SupprimeDuplications(T,&taille);
	affiche(T,taille);
	printf("\n");
	
	printf("khaliiiiiiiid");
	

	
	printf("\n\n\n *********** Comparaison de deux Tableaux ************ \n");
	printf("Entrer la taille du tableau 1: ");
	scanf("%d",&taille1);
	T1=Allouer(taille1);
	saisie(T1,taille1);
	affiche(T1,taille1);
	printf("\n\n");
	
	printf("Entrer la taille du tableau 2: ");
	scanf("%d",&taille2);
	T2=Allouer(taille2);
	saisie(T2,taille2);
	affiche(T2,taille2);
	
	compareTableaux (T1, taille1, T2, taille2);
	
	return 0;
}







