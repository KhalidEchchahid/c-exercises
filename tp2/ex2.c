#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* allouer(int n){
	char* ADN;
	ADN = (char*)malloc(n*sizeof(char));
	return ADN ;
}

char* ADN_sequence(int n){
	char *ADN;
	char T[]={'A','C','T','G'};
	int i;
	ADN = allouer(n);
	for(i=0 ; i<n ;i++){
		*(ADN+i)=T[rand()%4];
	}
	return ADN;
}

void affiche(char* ADN, int n){
	int i;
	for(i=0 ; i<n ; i++){
		printf("%c", *(ADN+i));
	}
}
int* compterN(char* ADN , int n){
	int T[4]={0,0,0,0};
	int i ;
	for(i=0; i<n ; i++){
		switch(*(ADN +i)){
			case 'A':T[0]++;break;
			case 'C':T[1]++;break;
			case 'G':T[2]++;break;
			case 'T':T[3]++;break;
		}
		}
	
	return (int)T;
	
}
char* complemet(char* ADN , int n){
	char* CADN;
	int i;
	CADN=allouer(n);
	for (i=0 ;i<n ;i++){
		switch(*(CADN+i)){
			case 'A':*(CADN+i)='T';break;
			case 'C':*(CADN+i)='A';break;
			case 'G':*(CADN+i)='G';break;
			case 'T':*(CADN+i)='c';break;
		}
	}
	return CADN;
}

void codons(char* ADN , int n){
	int i ;
	for (i=0 ; i<n ; i++){
		printf("%c %c %c", *(ADN+i), *(ADN+i+1), *(ADN+i+2));
	}
}
 int* codon_start (char* ADN){
 	int N = strlen(ADN);
 	int *T, n=1 ,i ;
	 T =(int*)malloc(sizeof(int));
	 for (i=0 ;i< N-2 ;i++){
	 	if((*(ADN+i)=='A') && (*(ADN+i)=='T') && (*(ADN+i)=='G')){
	 		T[n-1]=i ;
	 		n++;
	 		T = (int*)realloc(T ,n*sizeof(int));
		 }
	 } 
 	if(n!=1) return T;
 	else return -1;
 }
 
void supprimeduplications(char * ADN,int * N) {
  	int i,j,k;
 	ADN=reallouer(ADN,(*N));
	for(i=0;i<(*N);i++){
		for(j=i+1;j<(*N);){
			if(*(ADN+i)==(*(ADN+j))){
				for(k=j;k<(*N);k++){
					*(ADN+k)=*(ADN+k+1);
				}

				(*N)--;
				}
				else
 				j++;
		}
	}
		ADN=reallouer(ADN,(*N));
}

void codon_stop(char *ADN,int i){
    int k;
    int j ;
	int N=strlen(ADN);
	for(j=i;j<N;j++){
	if(((*(ADN+j)=='T')&&(*(ADN+j+1)=='A')&&(*(ADN+j+2)=='A'))||((*(ADN+j)=='T')&&(
		*(ADN+j+1)=='A')&&(*(ADN+j+2)=='G'))||((*(ADN+j)=='T')&&(*(ADN+j+1)=='G')&&(*
	(ADN+j+2)=='A')))
 	k=j;
 	else
	 k=-1;
}
	if(k==-1)
	printf("\naucun codon STOP n'est trouve");
	else
printf("\nle codon STOP est dans la position %d ",k);
}
 
int main(){
	
}
