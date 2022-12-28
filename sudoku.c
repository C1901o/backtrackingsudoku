#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<string.h>

int n =9;
int m = 9;
int matriz[9][9];
int matriz2[9][9];

void posm(){ //crea una matriz con valores de posiciones
	int i,j,aux;
	char numero[10];
	char numero2[4];
	for(i=0;i<=9;i++){
		for(j=0;j<=9;j++){
			sprintf(numero,"%d",i);
			sprintf(numero2,"%d",j);
			strcat(numero,numero2);
			aux = strtol(numero,NULL,10);
			matriz2[i][j] = aux;
		}
	}
}
void mostrar(int v[9][9]){ // imprime matriz por consola
	int i, j= 0;
  	for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
      		printf(" %d ",v[i][j]);
    	}
    printf("\n");
  	}
  	printf("\n");
}
void azar(){ //agregar numeros al alzar a la matriz
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
void llenar(){ // setea la matriz con 0
  int i, j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      matriz[i][j] = 0;
    }
  }
  azar();
  mostrar(matriz);
  printf("\nMatriz azar\n");
}
int rechace(int nodo){
	int aux[2];
	char aux2[2];
	int ayu,numeroazar,i,auxi,h,cont,j;
	sprintf(aux2,"%d",nodo);
	charaint(aux2,aux,1);
	printf("matriz es %d en la posiciones %d y %d",matriz[aux[0]][aux[1]],aux[0],aux[1]);
	system("pause");
	if(matriz[aux[0]][aux[1]] == 0 || (aux[0] && aux[1] == 0)){
		printf("if m es %d",matriz[aux[0]][aux[1]]);
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
				printf("%matriz %d %d es %d\n",aux[0],aux[1],matriz[aux[0]][aux[1]]);
				system("pause");
				return 1;
			}
		}
	}
	return 0;
}
int aceptar(int nodo){
	int i,j,cont;
	cont = 0;
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
	int aux[2];
	char aux1[2];
	sprintf(aux1,"%d",nodo);
	charaint(aux1,aux,1);
	if(matriz2[aux[0]][aux[1]] != 0){ //arreglar con respecto a nodo como var de entrada
		matriz2[aux[0]][aux[1]] = 0;
		//tranformar arreglo int en un int
		charaint(aux1,aux,2);
		return atoi(aux1);
	}else{
		return nodo;
	}
}
//agregar paso de poscion
int siguiente(int nodo){
	int aux[2];
	char aux1[2];
	int ayu;
	sprintf(aux1,"%d",nodo);
	charaint(aux1,aux);
	printf("%d\n",aux);
	if(matriz2[aux[0]][aux[1]] == 0){
		aux[0]=+1;
		aux[1]=+1;
		if(aux[0] > 9 ){
			aux[0]=0;
			if(matriz2[aux[0]][aux[1]] != 0){
				matriz2[aux[0]][aux[1]]= 0;				
			}
		}
		if(aux[1] > 9){
			aux[1]=0;
			if(matriz2[aux[0]][aux[1]] !=0){
				matriz2[aux[0]][aux[1]]=0;
			}
		}
		charaint(aux1,aux,2);
		return atoi(aux1);	
	}else{
		return nodo;
	}
}

// modificar funcion siguiente

void backtracking(int nodo){ //resulve la matriz por recursion

   if(rechace(nodo) == 1){
   		printf("rechace retorna %d",nodo);
   		system("pause");
   		return nodo;
   }
   if(aceptar(nodo) == 1){
   	  	printf("acepta retorna %d",nodo);
   		system("pause");
      	mostrar(matriz); //Imprime salida
      	exit(0);
   }
   
   int hijo = primero(nodo);

   while(hijo != 0){
   	  printf("antes de back %d\n",hijo);
      backtracking(hijo);
      printf("sali back %d\n",hijo);
		system("pause");
      hijo = siguiente(hijo);
	}
}

void charaint(char cadena[2], int entero[2],int condicion){
	int i;
	if(condicion == 1){
		for(i=0;i<strlen(cadena);i++){
		entero[i]= cadena[i]-'0';
		}
	}
	if(condicion == 2){
		for(i=0;i<2;i++){
			cadena[i]= entero[i] +'0';
		}
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
	llenar();
	posm();
	backtracking(null);
	printf("\n sali\n matriz normal\n");
	mostrar(matriz);
	printf("matriz de posicion\n");
	mostrar(matriz2);
	//system("pause");*/
	
	return 0;
	
}




