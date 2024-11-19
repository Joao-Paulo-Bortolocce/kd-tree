#include<time.h>
#include<stdio.h>
#include<windows.h>

#define TD 2 //nº de dimensões
#define TF 50 //nº maximo de pontos;

#include"Layout.h"
#include"arvoreKdTree.h"


int sorteia(int n)
{
	return rand() % n +1;
}

int qtdPontos(){
	Bordas(5, 2, 115, 15,3);
	int i;
	gotoxy(7,4);
	printf("Informe a quantidade de pontos que deseja gerar automaticamente [1 - 50]:");
	scanf("%d",&i);
	while(i<0 || i>50){
		Limpar(7,4,114,4,0);
		gotoxy(7,4);
		printf("Quantidade digitada eh invalida, Informe a quantidade de pontos que deseja gerar ENTRE [1 - 50]:");
		scanf("%d",&i);
	}
	system("cls");
	return i;
}

void gerarPontos(int pontos[TF][TD],int tl){
	int l;
	Bordas(5, 2, 37, 10,3);
	gotoxy(9,6);
	printf("Gerando pontos aleatorios");
	for(l=0;l<tl;l++){
		gotoxy(7,6);
		printf("%c",l%2);
		gotoxy(35,6);
		printf("%c",l%2);
		pontos[l][0]=sorteia(100);
		pontos[l][1]=sorteia(30);
		gotoxy(17,7);
		//Sleep(500);
	}
}

void printarCoordenadas(int pontos[TF][TD],int inicio, int fim, int n){
	system("cls");
	int c=4,l=2,i;
	gotoxy(c,l);
	printf("X");
	gotoxy(c,l+1);
	printf("Y");
	c+=2;
	for(i=inicio;i<=fim;i++,c+=3){
		gotoxy(c,l);
		printf("%d",pontos[i][0]);
		gotoxy(c,l+1);
		printf("%d",pontos[i][1]);
	}
}

void ordenar(int pontos[TF][TD],int inicio, int fim, int n){
	int x,y,i,pos,maior;
	while(fim>inicio){
		maior=pontos[0][n];
		pos=0;
		for(i=0;i<=fim;i++)
			if(pontos[i][n]>maior){
				maior=pontos[i][n];
				pos=i;
			}
		x=pontos[pos][0];
		y=pontos[pos][1];
		pontos[pos][0]=pontos[fim][0];
		pontos[pos][1]=pontos[fim][1];
		pontos[fim][0]=x;
		pontos[fim][1]=y;
		fim--;
	}
}

void montarArvore(int pontos[TF][TD],int inicio, int fim, int n, KdTree **raiz){
	int meio=(inicio+fim)/2;
	if(inicio<=fim){
		ordenar(pontos,inicio,fim,n);
		printarCoordenadas(pontos,inicio,fim,n);
		printf("\n\nO que sera inserido: (%d, %d)\n",pontos[meio][0],pontos[meio][1]);
		fflush(stdin);
		getch();
		inserirR(&*raiz,pontos[meio],0);
		montarArvore(pontos,inicio,meio-1,(n+1)%2,&*raiz);
		montarArvore(pontos,meio+1,fim,(n+1)%2,&*raiz);
	}
	
	//printarCoordenadas(pontos,inicio,fim,n);
}

void constroiGrafico(KdTree *raiz){
	system("cls");
	bordas(1,1,101,31)
	fflush(stdin);
	getch();
}

void executar(){
	int tl, pontos[TF][TD];
	KdTree *raiz;
	init(&raiz);
	tl=qtdPontos();
	gerarPontos(pontos,tl);
	montarArvore(pontos,0,tl-1,0,&raiz);
	system("cls");
	exibeArvore(raiz,-1);
	fflush(stdin);
	getch();
	constroiGrafico(raiz);
}

int main(){
	//srand(time(NULL));
	executar();
	return 0;
}
