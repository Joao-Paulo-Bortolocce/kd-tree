#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<math.h>

#define TD 2 //nº de dimensões
#define TF 25 //nº maximo de pontos;

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
	printf("Informe a quantidade de pontos que deseja gerar automaticamente [1 - %d]:",TF);
	scanf("%d",&i);
	while(i<1 || i>TF){
		Limpar(7,4,114,4,0);
		gotoxy(7,4);
		printf("Quantidade digitada eh invalida, Informe a quantidade de pontos que deseja gerar ENTRE [1 - %d]:",TF);
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

void printarCoordenadas(int pontos[TF][TD],int inicio, int fim){
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
		maior=pontos[inicio][n];
		pos=inicio;
		for(i=inicio;i<=fim;i++)
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
		//printarCoordenadas(pontos,inicio,fim);
		printf("\n\nO que sera inserido: (%d, %d)\n",pontos[meio][0],pontos[meio][1]);
		inserirR(&*raiz,pontos[meio],0);
		montarArvore(pontos,inicio,meio-1,(n+1)%2,&*raiz);
		montarArvore(pontos,meio+1,fim,(n+1)%2,&*raiz);
	}
}

void printaPonto(KdTree *pai,KdTree *atual,int n, int ci, int li,KdTree *raiz){
	int c,l,cf,lf;
	if(atual!=NULL){
		printaPonto(atual,atual->esq,(n+1)%2,ci,li,raiz);
		if (n) { // Corta eixo Y
		    if (atual->pontos[(n + 1) % 2] < pai->pontos[(n + 1) % 2]) {
		        c = ci;
		        l = (li + 30) - atual->pontos[n];
		        if(atual->pontos[(n + 1) % 2]>raiz->pontos[(n + 1) % 2])
		        	c = ci+raiz->pontos[(n + 1) % 2];
		        cf = pai->pontos[(n + 1) % 2]+ci;
		        //lf = li + 30;
		        //Bordas(c, l, cf, lf, 7);
		        tracoH(c,cf,l);
		    } else {
		        c = pai->pontos[(n + 1) % 2]+ci;
		        l = (li + 30) - atual->pontos[n];
		        cf = ci + 100;
		         if(atual->pontos[(n + 1) % 2]<raiz->pontos[(n + 1) % 2])
		        	cf =ci+raiz->pontos[(n + 1) % 2];
		        //lf = li + 30;
		        //Bordas(c, l, cf, lf, 7);
		         tracoH(c,cf,l);
		    }
		} 
		else { // Corta eixo X
		    if (atual == pai) {
		        c = atual->pontos[n]+ci;
		        l = li;
		        //cf = ci + 100;
		        lf = li + 30;
		        //Bordas(c, l, cf, lf, 7);
		        tracoV(l,lf,c);
		    } 
			else {
		        if (atual->pontos[(n + 1) % 2] < pai->pontos[(n + 1) % 2]) {
		            c = atual->pontos[n]+ci;
		            l = (li + 30) - pai->pontos[(n + 1) % 2];
		            //cf = ci + 100;
		            lf = li + 30;
		            //Bordas(c, l, cf, lf, 7);
		            tracoV(l,lf,c);
		        } 
				else {
		            c = atual->pontos[n]+ci;
		            l = li;
		            //cf = ci + 100;
		            lf = (li + 30) - pai->pontos[(n + 1) % 2];
		            //Bordas(c, l, cf, lf, 7);
		            tracoV(l,lf,c);
		        }
		    }
		}
		//Limpar(c+1, l+1, cf-1, lf-1,0);
		gotoxy(atual->pontos[0]+ci-3,(li+30)-atual->pontos[1]);
		printf("(%d,%d)",atual->pontos[0],atual->pontos[1]);
		printaPonto(atual,atual->dir,(n+1)%2,ci,li,raiz);
	}
}

void constroiGrafico(KdTree *raiz){
	int ci=5,li=2,cf=ci+100,lf=li+30;
	system("cls");
	gotoxy(ci-1,lf+1);
	printf("0");
	gotoxy(ci-2,li);
	printf("30");
	gotoxy(cf+1,lf+1);
	printf("100");
	printaPonto(raiz,raiz,0,ci,li,raiz);
	Bordas(ci,li,cf,lf,3);
}

int distancia(int ponto[TD]){
	int raio;
	Bordas(5, 2, 115, 15,3);
	gotoxy(7,4);
	printf("Digite a coordenada X que deseja para o ponto [1-100]: ");
	scanf("%d",&ponto[0]);
	while(ponto[0]<1 || ponto[0]>100){
		Limpar(7,4,114,4,0);
		gotoxy(7,4);
		printf("Coordenada invalida,Digite a coordenada X que deseja para o ponto [1-100]: ");
		scanf("%d",&ponto[0]);
	} 
	gotoxy(7,5);
	printf("Digite a coordenada Y que deseja para o ponto [1-30]: ");
	scanf("%d",&ponto[1]);
	while(ponto[1]<1 || ponto[1]>30){
		Limpar(7,5,114,5,0);
		gotoxy(7,5);
		printf("Coordenada invalida,Digite a coordenada Y que deseja para o ponto [1-30]: ");
		scanf("%d",&ponto[1]);
	} 
	gotoxy(7,6);
	printf("Coordenada : (%d,%d)",ponto[0],ponto[1]);
	gotoxy(7,7);
	printf("Digite o raio de distancia desejado [1 - 20]: ");
	scanf("%d",&raio);
	while(raio<1 || raio>20){
		Limpar(7,7,114,7,0);
		gotoxy(7,7);
		printf("Raio invalido, informe um entre  [1 - 20]: ");
		scanf("%d",&raio);
	} 
	system("cls");
	return raio;
}

void calculaDistancia(KdTree *raiz,int ponto[TD],int raio){
	if(raiz!=NULL){
		calculaDistancia(raiz->esq,ponto,raio);
		if(sqrt(pow(ponto[0]-(raiz->pontos[0]),2)+pow(ponto[1]-(raiz->pontos[1]),2))<=raio){
			printf("Ponto (%d, %d)\n",raiz->pontos[0],raiz->pontos[1]);
		}
		calculaDistancia(raiz->dir,ponto,raio);
	}
}

void executar(){
	int tl, pontos[TF][TD], ponto[TD],raio;
	KdTree *raiz;
	init(&raiz);
	tl=qtdPontos();
	gerarPontos(pontos,tl);
	printarCoordenadas(pontos,0,tl-1);
	fflush(stdin);
	getch();
	montarArvore(pontos,0,tl-1,0,&raiz);
	system("cls");
	constroiGrafico(raiz);
	printaEmPe(raiz,36,10);
	textcolor(7);
	fflush(stdin);
	getch();
	system("cls");
	raio=distancia(ponto);
	printf("PONTOS PROXIMOS A COORDENADA (%d,%d) EM ATE %d DE DISTANCIA:\n",ponto[0],ponto[1],raio);
	calculaDistancia(raiz,ponto,raio);
	fflush(stdin);
	getch();
}

int main(){
	srand(time(NULL));
	executar();
	return 0;
}
