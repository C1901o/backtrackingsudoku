#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n =9;
int m = 9;
int matriz[9][9];
int matriz2[9][9];

void posm(int *matriz[n][n]){ //crea una matriz con valores de posiciones
	int i,j,aux;
	char numero[10];
	char numero2[4];
	for(i=0;i<=9;i++){
		for(j=0;j<=9;j++){
			sprintf(numero,"%d",i);
			sprintf(numero2,"%d",j);
			strcat(numero,numero2);
			aux = strtol(numero,NULL,10);
			matriz[i][j] = aux;
		}
	}
}
void mostrar(int *matriz[n][n]){ // imprime matriz por consola
	int i, j= 0;
  	for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
      		printf(" %d ",matriz[i][j]);
    	}
    printf("\n");
  	}
  	printf("\n");
}
void azar(int *matriz[n][n]){ //agregar numeros al alzar a la matriz
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
void llenar(int *m[n][n]){ // setea la matriz con 0
  int i, j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      m[i][j] = 0;
    }
  }
  azar(m);
  mostrar(m);
  printf("\nMatriz azar\n");
}
int rechace(int nodo){
	char aux[2];
	int ayu;
	sprintf(aux,"%d",nodo);
	int numeroazar,i,auxi,h,cont,j;
	if(matriz[aux[0]][aux[1]] == 0){
		numeroazar = rand()%10;
		j=1;
		while(j == 1){
			cont = 0;
			for(i=0;i<=9;i++){
				if(numeroazar == matriz[i][aux[1]]){
					cont++;
				}
				if(numeroazar == matriz[aux[0]][i]){
					cont++;
				}
			}
			if(cont > 0){
				printf("rechace matriz %d\n",matriz[aux[0]][aux[1]]);
				auxi = numeroazar;
				h=0;
				while(h == 0){
					numeroazar = rand()%10;
					if(numeroazar != auxi){
						h = 1;
					}
				}
			}else{
				matriz[aux[0]][aux[1]] = numeroazar;
				j=0;
				return 1;
			}
		}
	}
	return 0;
}
int aceptar(int nodo){
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
		return 0;
	}
	else{
		return 1;
	}
	
}

//marcar matriz de prueba con posiciones usadas
int primero(int nodo){
	char aux[2];
	int ayu;
	sprintf(aux,"%d",nodo);
	
	if(matriz2[aux[0]][aux[1]] != "\0"){ //arreglar con respecto a nodo como var de entrada
		matriz2[aux[0]][aux[1]] = "\0";
		ayu = strtol(aux,NULL,10);
		return ayu;
	}else{
		ayu = strtol(aux,NULL,10);
		return ayu; 
	}
}
//agregar paso de poscion
int siguiente(int nodo){
	char aux[2];
	int ayu;
	sprintf(aux,"%d",nodo);
	printf("%d\n",aux);
	if(matriz2[aux[0]][aux[1]] == "\0"){
		aux[0]=+1;
		aux[1]=+1;
		if(aux[0] > 9 ){
			aux[0]=0;
			if(matriz2[aux[0]][aux[1]] != "\0"){
				matriz2[aux[0]][aux[1]]="\0";				
			}
		}
		if(aux[1] > 9){
			aux[1]=0;
			if(matriz2[aux[0]][aux[1]] !="\0"){
				matriz2[aux[0]][aux[1]]="\0";
			}
		}
		ayu = strtol(aux,NULL,10);
		return ayu;		
	}else{
		return nodo;
	}
}

// modificar funcion siguiente

void backtracking(int nodo){ //resulve la matriz por recursion
   if(rechace(nodo) == 1){
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
      
   int hijo = primero(nodo);

   while(hijo == 0){
   	  printf("\n while\n"); //areglar la funcion hijo
      system("pause");
      backtracking(hijo);
      hijo = siguiente(hijo);
	}
}

/*
void backtracking(<tipo> nodo){ //ejmplo de uso
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

int main() { // funcion inicial
	int a = 00;
	llenar(matriz);
	posm(matriz2);
	backtracking(a);
	return 0;
	
}




