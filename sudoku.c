#include <stdio.h>
#include <stdlib.h>

int n =9;
int m = 9;

void mostrar(int matriz[n][n]){
	int i, j= 0;
  	for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
      		printf("%d ",matriz[i][j]);
    	}
    printf("\n");
  	}
  	printf("\n");
}


void azar(int matriz[n][n]){
	int i, j,c;
	int mtemporal=0;
	for(c=0;c<9;c++){
		i = rand() % 10;
		j = rand() % 10;
		c = rand() % 10;
		if(matriz[i][j] == 0){
			if(c != mtemporal){
				matriz[i][j]=c;
			}
			mtemporal = matriz[i][j];
		}
	}
}

void llenar(int m[n][n]){
  int i, j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      m[i][j] = 0;
    }
  }
  azar(m);
  mostrar(m);
}

int rechace(int matriz[m][n],int x, int y){
	int numeroazar,i;
	int cont = 0;
	int j= 1;
	if(matriz[x][y] == 0){
		while(j!=0){
			int numeroazar = rand()%10;
			for(i=0;i<=9;i++){
				if(numeroazar == matriz[i][y]){
					cont++;
				}
				if(numeroazar == matriz[x][i]){
					cont++;
				}
			}
			if(cont == 0){
				printf("rechace matriz %d\n",matriz[x][y]);
				matriz[x][y]=numeroazar;
				mostrar(matriz);
				system("pause");
				j=0;
				return 1;
			}
		}
	}
	return 0;
}
int aceptar(int matriz[m][n]){
	int i,j;
	int cont = 0;
	for(i=0;i<=9;i++){
		for(j=0;j<=9;j++){
			if(matriz[i][j] == 0){
				cont++;
			}	
		}
	}
	if(cont > 0){
		return 1;
	}
	else{
		return 0;
	}
	
}
int primero(int matriz[m][n]){
	int x = 0;
	int y = 0;
	return;
}
int siguiente(int matriz[m][n]){
	if(m == 9){
		m=0;
	}
	if(n=9){
		n=0;
	}
	return matriz[m][n];
}

void backtracking(int *nodo[n][n],int x,int y){
   if(rechace(nodo,x,y) == 1){
   		return nodo;
   		printf("rechace retorna %d",nodo);
   		system("pause");
   }
   if(aceptar(nodo) == 1){
   	  	printf("acepta retorna %d",nodo);
   		system("pause");
      	mostrar(nodo); //Imprime salida
      	exit(0);
   }
   int hijo = nodo[x][y];
   while(hijo != null){
      backtracking(hijo);
      hijo = siguiente(hijo);
   }
}

/*
void backtracking(<tipo> nodo){
   if(reject(nodo) return;
   if(accept(nodo)){
      output(); //Imprime salida
      exit(0);
   }
   <tipo> hijo = first(nodo);
   while(hijo != <nulo>){
      backtracking(hijo);
      hijo = next(hijo);
   }
}
*/

int main() {
	
	int matriz [n][n];
	int m;
	llenar(&matriz);
	backtracking(matriz);
	return 0;
}



