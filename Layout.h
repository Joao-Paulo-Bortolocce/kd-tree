void LayoutMenu(int c,int l)
{
	system("cls");
	int C[3],L[3];
	C[0]=c; C[1]=C[0]+24; C[2]=C[1]+55;
	L[0]=l; L[1]=L[0]+4; L[2]=L[1]+25;
	for(c=C[0];c<C[2];c++)
	{
		l=L[0];
		gotoxy(c,l);
		printf("%c",205);
		l=L[1];
		gotoxy(c,l);
		printf("%c",205);
		l=L[2];
		gotoxy(c,l);
		printf("%c",205);
	}
	for(l=L[0];l<L[2];l++)
	{
		c=C[0];
		gotoxy(c,l);
		printf("%c",186);
		c=C[1];
		if(l>5)
		{
			gotoxy(c,l);
			printf("%c",186);
		}
		c=C[2];
		gotoxy(c,l);
		printf("%c",186);
	}
	c=C[0];
	l=L[0];
	gotoxy(c,l);
	printf("%c",201);
	l=L[1];
	gotoxy(c,l);
	printf("%c",204);
	l=L[2];
	gotoxy(c,l);
	printf("%c",200);
	
	
	c=C[1];
	l=L[0];
	gotoxy(c,l);
	printf("%c",205);
	l=L[1];
	gotoxy(c,l);
	printf("%c",203);
	l=L[2];
	gotoxy(c,l);
	printf("%c",202);
		
	c=C[2];
	l=L[0];
	gotoxy(c,l);
	printf("%c",187);	
	l=L[1];
	gotoxy(c,l);
	printf("%c",185);
	l=L[2];
	gotoxy(c,l);
	printf("%c",188);
	
	
	
	gotoxy(1,40);	
}

void Bordas(int ci, int li, int cf, int lf, int corTexto) {
	int i;
 	textcolor(corTexto);
	gotoxy(ci, li);
	printf("%c", 201);
	gotoxy(cf, li);
	printf("%c", 187);
	gotoxy(ci, lf);
	printf("%c", 200);
	gotoxy(cf, lf);
	printf("%c", 188);

	for(i=ci+1; i<cf; i++) {
		gotoxy(i, li);
		printf("%c", 205);
		gotoxy(i, lf);
		printf("%c", 205);
	}

	for(i=li+1; i<lf; i++) {
		gotoxy(ci, i);
		printf("%c", 186);
		gotoxy(cf, i);
		printf("%c", 186);
	}
	textcolor(7);
}

void Limpar(int ci, int li, int cf, int lf, int corTexto){
	int i,j;
 	textcolor(corTexto);
 	for(i=ci;i<=cf;i++){
 		for(j=li;j<=lf;j++){
 			gotoxy(i,j);
 			printf(" ");
 		}	
 	}
 	textcolor(7);	
}

void tracoH(int ci,int cf,int l){
	int i;
	for(i=ci; i<=cf; i++) {
		gotoxy(i, l);
		printf("%c", 205);

	}
	
	
}

void tracoV(int li,int lf,int c){
	int i;
	for(i=li; i<lf; i++) {
			gotoxy(c, i);
			printf("%c", 186);
	}	
}

void Moldura()
{
	int i;
	
	Bordas(2,2,141,31,6);//Principal
	gotoxy(55,3); printf("ESCOLHA UM DOS TEXTOS COMO BASE");
	textcolor(1);
	
	Bordas(4,6,140,8,1);//Mensagem
	Bordas(4,9,35,30,1);// Menu de Escolha
	Bordas(36,9,140,30,1);//Menu de Apresentar
}
