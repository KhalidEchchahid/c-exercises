#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
char* Allouer (char* ADN,int n){
	
	ADN=(char*)malloc(n*sizeof(char));
	
	return ADN ;
}

char* ADN_Sequences (char* ADN ,int n){
	char T[4] ={'A','C','G','T'} ;
	int i ,a ;
	for(i=0;i<n;i++){
		a=rand()%4;

		*(ADN+i)=T[a];
	}
	return ADN;
}

void Affiche(char* ADN , int n){
	int i ;
	for(i=0;i<n;i++){
		printf("%c\t",*(ADN+i));
	}
}
void Compte_Nucleotides(char* ADN , int n){
	int i ;
	int T[4]={0,0,0,0};
	for(i=0;i<n;i++){
		if(*(ADN+i)=='A') T[0]++;
		if(*(ADN+i)=='C') T[1]++;
		if(*(ADN+i)=='G') T[2]++;
		if(*(ADN+i)=='T') T[3]++;
		}
	printf("\nA = %d \n",T[0]);
	printf("C = %d \n",T[1]);
	printf("G = %d \n",T[2]);
	printf("T = %d \n",T[3]);
}

char* Complement(char* ADN , int n){
	int i ;
	for(i=0;i<n;i++){
		if(*(ADN+i)=='A'){ *(ADN+i)='T' ; continue;}
		if(*(ADN+i)=='T'){*(ADN+i)='A' ; continue;}  
		if(*(ADN+i)=='C'){*(ADN+i)='G' ; continue;} 
		if(*(ADN+i)=='G'){*(ADN+i)='C' ; continue;} 
	}
	return ADN ;
}

char* reallouer(char* T, int N){
	T=(char*)realloc(T, N*sizeof(char));
	return T;
}
char* Codons(char* ADN , int n){
	int i ,j ,k,N=3;

	char* ADNC=Allouer (ADNC,N);
	for (i=0;i<N;i++){
		*(ADNC+i)=*(ADN+i);
	}
    for (i=1;i<n-2;i++){
        k=0;
	    for (j=i;j<i+3;j++){
		    *(ADNC+N+k)=*(ADN+j);
		    k++;
		}
		N+=k;
	    ADNC=reallouer(ADNC,N);
	}
	Affiche(ADNC,N);
    return ADNC ;
}

void codon_start(char*ADN , int n){
	int i ,c=0;
	printf("donner ADN : ");
	for (i=0 ; i<n;i++){
	  scanf("%c",ADN+i);
	}
	for (i=0 ; i<n;i++){
		if(*(ADN+i)=='A' && *(ADN+i+1)=='T' && *(ADN+i+2)=='G'){
			c=i+1;
		}
		if(c>0){
			printf("%f",c);
		}
	}
    if (c=0){
		printf("pas de codon start");
	}	
}

int main(){
	int n;
	char* ADN ;
	printf("donner la dimension : ");
	scanf("%d",&n);
	ADN=Allouer(ADN,n);
	ADN=ADN_Sequences (ADN ,n);
	Affiche(ADN,n);
	Compte_Nucleotides(ADN,n);
	ADN=Complement(ADN,n);
	Compte_Nucleotides(ADN,n);
	Affiche(ADN,n);
	printf("\n *****codons********\n");
	Codons(ADN,n);
	printf("\n");
	codon_start(ADN,n);
	
	
	
	return 0;
}






