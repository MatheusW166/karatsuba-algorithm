#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 256

int metade(int);
char *karatsuba(char a[LEN],char b[LEN],int);
void stringOperations(char*,char*,char*,int,char*);
int igualar_tamanho(char*,char*);
void subtrair(char*,char*,char*);
void somar(char*,char*,char*);
void elevar(char*,int);

int main(void){
	int k;
	char a[LEN], b[LEN], *product;
	printf("Digite os valores de A e B: ");
	setbuf(stdin, NULL);
	scanf("%s",a);
	setbuf(stdin, NULL);
	scanf("%s",b);
	k = igualar_tamanho(a,b);
	product = karatsuba(a,b,k);
    printf("AxB = %s\n", product);
	free(product);
	return EXIT_SUCCESS;
} 

int igualar_tamanho(char *a, char *b){
    int tamA = strlen(a);
	int tamB = strlen(b);
	if (tamA==tamB){
		return tamA;
	}else if(tamA>tamB){
		for(int i=(tamB-1);i>=0;i--){
			b[i+(tamA-tamB)] = b[i];
		}
		for(int i=0;i<(tamA-tamB);i++){
			b[i] = '0';
		}
        b[tamA] = '\0';
        return tamA;
	}else{
		for(int i=(tamA-1);i>=0;i--){
			a[i+(tamB-tamA)] = a[i];
		}
		for(int i=0;i<(tamB-tamA);i++){
			a[i] = '0';
		}
        a[tamB] = '\0';
        return tamB;
	}
}

int metade(int a){
	if(a%2==0) return (a/2);
	return ((a/2)+1);
}

char *karatsuba(char a[LEN],char b[LEN],int n){
	if(n<=3){
		char *uv = (char*)malloc(sizeof(char)*10);
		sprintf(uv, "%d", (atoi(a)*atoi(b)));
 		return  uv;
	}else{
		char auxA1[LEN];
		char auxA2[LEN];
		char auxB1[LEN];
		char auxB2[LEN];

		char *pMid;
		int k=(n/2);

		strcpy(auxA1,a);
		auxA1[k] = '\0';
		pMid = &a[k];
		strcpy(auxA2,pMid);

		strcpy(auxB1,b);
		auxB1[k] = '\0';
		pMid = &b[k];
		strcpy(auxB2,pMid);

		char parteA[LEN];
		char parteB[LEN];
		char parteAB1[LEN];
		char parteAB2[LEN];
		
		strcpy(parteA,auxA1);
		strcpy(parteB,auxA2);

		somar(parteA,parteB,parteAB1);
		
		strcpy(parteA,auxB1);
		strcpy(parteB,auxB2);
		
		somar(parteA,parteB,parteAB2);
		
		char *ac = karatsuba(auxA1,auxB1,igualar_tamanho(auxA1,auxB1));
		char *bd = karatsuba(auxA2,auxB2,igualar_tamanho(auxA2,auxB2));
		char *y  = karatsuba(parteAB1,parteAB2,igualar_tamanho(parteAB1,parteAB2));	
		char *x  = (char*)malloc(LEN*sizeof(char));
		stringOperations(ac,bd,y,metade(n),x); //x = (ac*10^2k+(y-ac-bd)*10^k+bd)
		return x;
	}
}

void stringOperations(char *ac, char *bd, char *y, int k, char *x){
 	char ac_copia[LEN], bd_copia[LEN], y_copia[LEN], ac_bd_y[LEN], 
	resultado[LEN], y_ac[LEN], soma[LEN];
	strcpy(ac_copia, ac);
	strcpy(bd_copia, bd);
	strcpy(y_copia, y);
	//Subtraindo (y-ac)-bd
	subtrair(y_copia,ac_copia,y_ac);
	subtrair(y_ac, bd_copia,ac_bd_y);
	//Elevando (y-ac-bd) a k
	elevar(ac,k*2);
	elevar(ac_bd_y, k);
	somar(ac, ac_bd_y,soma);
	somar(soma,bd,resultado);
 	strcpy(x, resultado);
	free(ac);
	free(bd);
	free(y);
}

void subtrair(char *a, char *b, char *resultado){
	int i, j,aux,flag=0,pos;
	int tam = igualar_tamanho(a,b);
    char ac_y[LEN];
	int vetor[tam];
	for(i=(tam-1); i>=0; i--){
        if((flag==1)&&(i!=pos)){
            if(a[i]=='0'){ 
                a[i]='9';
            }
            else{
                aux = (a[i]-48);
				aux--;
				a[i] = (aux+48);
                flag=0;
            }
        }
        aux = ((a[i]-48)-(b[i]-48));
        if(aux<0){
            if(a[i-1]=='0'){
                a[i-1] = '9';
				pos=(i-1);
				flag=1;
            }else{
                aux = (a[i-1]-48);
            	aux--;
				a[i-1] = (aux+48); 
            }
            aux = ((a[i]-48)+10);
            ac_y[i] = ((aux-(b[i]-48))+48);  
        }else{
            ac_y[i] = (aux+48);
        }
        a[i] = '\0';
        b[i] = '\0';
        vetor[i] = ac_y[i];
    }
    for(i=0; i<tam; i++)
        ac_y[i] = vetor[i];
	ac_y[tam]='\0';
	strcpy(resultado,ac_y);
}

void elevar(char *a, int k){
	int i,j, aux;
	for(i=0; a[i]=='0'; i++);
    for(j=0;j<(strlen(a)-i);j++){
        a[j] = a[j+i];
    }
    a[j]='\0';
    aux=j;
    for(;j<(aux+k); j++){
        a[j] = '0';
    }
    a[j]='\0';
}

void somar(char *a, char *b, char *resultado){
	int tam = igualar_tamanho(a,b), aux,flag=0;
	char soma[LEN];
	for(int i=(tam-1); i>=0; i--){
		aux = ((a[i]-48)+(b[i]-48));
		if(flag){
			aux++;
		}
		if(aux>=10){
			soma[i] = ((aux-10)+48);
			flag = 1;
		}else{
			soma[i] = (aux+48);
			flag = 0;
		}
		a[i]='\0';
		b[i]='\0';
	}
	if(flag){
		for(int i=tam; i>0; i--){
			soma[i] = soma[i-1];
		}
		soma[0] = '1';
		soma[tam+1] = '\0';
	}else
		soma[tam]='\0';
	strcpy(resultado,soma);
}