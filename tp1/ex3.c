#include <stdio.h>
#include <stdlib.h>

int ** alloue_matrice_pascal (int** T,int n){
	int i;
	T=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		T[i]=(int*)malloc((i+1)*sizeof(int));
	}
	return T;
}


int ** remplit_matrice_pascal (int** T, int n){
	int i ,j ;
	
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			if (i==j || j==0){
				*(*(T+i)+j)=1;
			}
			else {
				*(*(T+i)+j)=*(*(T+i-1)+(j-1))+*(*(T+i-1)+j);  
			}
		}
	}

	
	return T;
}

void affiche_matrice_pascal(int** T,int n){
	int i ,j ;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			printf("%d\t",*(*(T+i)+j));
		}
		printf("\n");
	}
}

int main(){
	int n;
	int** T ;
	printf("donner la dimension : ");
	scanf("%d",&n);
	T=alloue_matrice_pascal (T,n);
	T=remplit_matrice_pascal (T,n);
	affiche_matrice_pascal(T,n);
	return 0;
}
