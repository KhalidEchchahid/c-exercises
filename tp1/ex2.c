#include <stdio.h>
#include <stdlib.h>

int** Allouer(int** M ,int dim ){
	int i ;
	M=(int**)malloc(dim*sizeof(int));
	for(i=0;i<dim ; i++){
		M[i]=(int*)malloc(dim*sizeof(int));
	}
	return M;
}

void saisie(int** M, int dim){
	int i ,j ;
	for (i=0;i<dim ; i++){
		for(j=0;j<dim;j++){
			printf("T[%d][%d]= ",i,j);
			scanf("%d",(*(M+i)+j));
		}
		printf("\n");
	}
}

void Affiche(int** M, int dim){
	int i ,j ;
	for (i=0;i<dim ; i++){
		for(j=0;j<dim;j++){
			printf("T[%d][%d]= %d \t\t",i,j,*(*(M+i)+j));
		}
		printf("\n");
	}
}

int carre_magique(int **M, int dim){
	int i , j , ok=1 ;
	int SO=0 ,SS, SD1=0,SD2=0 ;

	for(i=0;i<dim;i++) SO+=*(*(M+0)+i);
	printf("%d \n",SO);
	i=1;
	while (ok && i < dim) {
		SS=0;
		for(j=0;j<dim;j++){
			SS+=*(*(M+i)+j);
		}
		printf("%d \n",SS);
		if(SO != SS) ok=0;
		i++;
	}
	SO=0;
	for(i=0;i<dim;i++) SO+=*(*(M+i)+0);
	i=1;
	while (ok && i < dim) {
		SS=0;
		for(j=0;j<dim;j++){
			SS+=*(*(M+j)+i);
		}
		if(SO != SS) ok=0;
		i++;
	}

	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			if (i==j)   SD1+=*(*(M+i)+j);
			if (j==dim-i-1) SD2+=*(*(M+i)+j);
		}
	}
	if (SD1 != SD2) ok=0;
	
    return ok ;
}

int main(){
	int** M ;
	int dim ,ok ;
	printf ("donner dimension : ");
	scanf("%d",&dim);
	M=Allouer(M,dim);
	saisie(M,dim);
	Affiche(M,dim);
	ok=carre_magique(M,dim);
    printf(" %d\n",ok);
	if (ok) printf("carre magique\n");
	else printf("carre n'est pas magique\n");
	return 0;
}
