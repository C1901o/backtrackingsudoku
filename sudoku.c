#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<string.h>

int n =8;
int m = 8;
int k;
int nodo[1];
int matriz[8][8];
int matriz2[8][8];

void charaint(char cadena[2], int entero[2],int condicion);

void posm(){ //crea una matriz con valores de posiciones
	int i,j,aux;
	char numero[10];
	char numero2[4];
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			sprintf(numero,"%d",i);
			sprintf(numero2,"%d",j);
			strcat(numero,numero2);
			aux = strtol(numero,NULL,10);
			matriz2[i][j] = aux;
			//printf(" %d ",matriz2[i][j]);
		}
		//printf("\n");
	}
}
void mostrar(int v[8][8]){ // imprime matriz por consola
	int i, j= 0;
  	for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
      		printf(" %d ",v[i][j]);
    	}
    printf("\n");
  	}
  	printf("\n");
}

void mostrarnodo(){
	printf("\nvalor nodo\n");
	for(k=0;k<2;k++){
		printf(" nodo[%d] es %d ",k,nodo[k]);
	}
	printf("\n");
}
void azar(){ //agregar numeros al alzar a la matriz
	int i, j,c;
	int mtemporal=0;
	for(c=0;c<8;c++){
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
  //printf("\nMatriz azar\n");
}
int rechace(int nodo[]){
	int ayu,numeroazar,i,auxi,h,cont,j;
	j=1;
	while(j == 1){
		numeroazar = rand()%10;
		if(matriz2[nodo[0]][nodo[1]] == 99){
			cont = 0;
			for(i=0;i<9;i++){
				if(numeroazar == matriz[i][nodo[1]]){
					//printf("matriz %d es igual a %d",matriz[i][nodo[1]],numeroazar);
					cont++;
				}
				if(numeroazar == matriz[nodo[0]][i]){
					//printf("matriz %d %d es %d es igual a %d",nodo[0],i,matriz[nodo[0]][i],numeroazar);
					cont++;
				}
			}
			//printf("\nmatriz valor %d / numero %d count %d\n",matriz[nodo[0]][nodo[1]],numeroazar,cont);
			//system("pause");
			if(cont > 0){
				//printf("\nrechace matriz %d\n",matriz[nodo[0]][nodo[1]]);
				auxi = numeroazar;
				h=0;
				while(h == 0){
					numeroazar = rand()%10;
					if(numeroazar != auxi){
						h = 1;
					}
				}
			}else{
				matriz[nodo[0]][nodo[1]] = numeroazar;
				printf("numero actualizad nodo %d %d es %d",nodo[0],nodo[1],numeroazar);
				//if(nodo[0] != 7 && nodo[1] !=7){
				//	matriz2[nodo[0]][nodo[1]] = 99;	
				//}
				j=0;
				//printf("%matriz %d %d es %d\n",aux[0],aux[1],matriz[aux[0]][aux[1]]);
				//system("pause");
				return 1;
			}
		}else{
			return 0;
		}	
		//printf("\nwhile\n");
	}
	return 0;
}
int aceptar(int nodo[]){
	int i,j,cont;
	cont = 0;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(matriz[i][j] == 0){
				cont++;
			}	
		}
	}
	if(cont > 0){
		printf("\nno acepta\n");
		return 0;
	}
	else{
		printf("\nacepta\n");
		return 1;
	}
	
}

//marcar matriz de prueba con posiciones usadas
int primero(int nodo[]){
	
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			//printf("nodo.-%d %d matriz %d\n",i,j,matriz2[i][j]);
			//system("pause");
			if(matriz2[i][j] != 99){
				nodo[0]=i;
				nodo[1]=j;
				matriz2[nodo[0]][nodo[1]] = 99;
				//printf("\nnodos %d %d primero\n",nodo[0],nodo[1]);
   				//system("pause");
				return nodo;
			}
		}
	}
	/*
	if(matriz2[nodo[0]][nodo[1]] == 99){
		return nodo;
	}else{
		if(matriz[nodo[0]][nodo[1]] == 0){
			return nodo;
		}else{
			matriz2[nodo[0]][nodo[1]] = 99;
			return 99;
		}
	}
	/*
	if(matriz2[nodo[0]][nodo[1]] == 99){
		if(nodo[1]< 7){
			nodo[1]=nodo[1]+1;	
		}else{
			nodo[1]=0;
			nodo[0]=nodo[0]+1;
		}
		//printf("\n----valor nodo es %d%d----\n",nodo[0],nodo[1]);
		//system("pause");
		return 1;
	}else{
		return 2;
	}*/
}
//agregar paso de poscion
int siguiente(int nodo[]){
	//printf("\nback nodo-. %d %d",nodo[0],nodo[1]);
	//system("pause");
	int i,j;
	if(matriz2[nodo[0]][nodo[1]] == 99){
		if(nodo[1]< 7){
			nodo[1]=nodo[1]+1;	
		}else{
			nodo[1]=0;
			nodo[0]=nodo[0]+1;
		}
		matriz2[nodo[0]][nodo[1]] = 99;
		return nodo;
	}else{
		//for(i=0;i<9;i++){
		//	for(j=0;j<9;j++){
		//		if(matriz2[nodo[i]][nodo[j]] != 99){
		//			nodo[0]=i;
		//			nodo[1]=j;
		//			return nodo;
		//		}
		//	}
		//}
		return nodo;
	}
}

void charaint(char cadena[1], int entero[1],int condicion){
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


// modificar funcion siguiente

void backtracking(int nodo[]){ //resulve la matriz por recursion
	printf("\nentro al back el nodo es = %d %d\n",nodo[0] ,nodo[1]);
	mostrar(matriz);
	mostrar(matriz2);
   if(rechace(nodo) == 1){
   		//printf("metriz8*8= %d\n",matriz[7][7]);
   		//if(matriz2[7][7] != 77){
   		//	return;
		//}
   		return nodo;
   }
   if(aceptar(nodo) == 1){
   	  	//printf("\nacepta retorna %d\n",nodo);
   		//system("pause");
      	mostrar(matriz); //Imprime salida
      	exit(0);
   }
   int *hijo = primero(nodo);
   //printf("hijo= %d %d\n",hijo[0] ,hijo[1]);
   //system("pause");
   // mostrar(matriz);
   //mostrar(matriz2);
   // system("pause");
   while(hijo[0] != 8 && hijo[1]!=8){
   	  //printf("\n---- antes de back----");
   	  //printf("\nantes de back el hijo es = %d %d\n",hijo[0] ,hijo[1]);
   	  //system("pause");
      backtracking(hijo);
      //printf("\n---- sali back ----\n");
	  //printf("\n---- siguiente ----\n");
      hijo = siguiente(hijo);
      printf("\nsiguiente devulve el hijo= %d %d\n",hijo[0] ,hijo[1]);
   	  system("pause");
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
	int i;
	llenar();
	posm();
	k=1;
	for(i=0;i<2;i++){
		nodo[i]=0;
	}
	backtracking(&nodo);
	printf("\n sali\n matriz normal\n");
	mostrar(matriz);
	printf("matriz de posicion\n");
	mostrar(matriz2);
	//system("pause");*/
	
	return 0;
	
}




