struct kdtree{
	int pontos[TD];
	struct kdtree *dir,*esq;
};
typedef struct kdtree KdTree;

void init(KdTree **raiz){
	*raiz=NULL;
}

void novoNo(KdTree **raiz, int pontos[TD]){
	int i;
	*raiz=(KdTree*)malloc(sizeof(KdTree));
	(*raiz)->dir=(*raiz)->esq=NULL;
	for(i=0;i<TD;i++)
		(*raiz)->pontos[i]=pontos[i];
}

void inserirR(KdTree **raiz,int pontos[TD],int n){
	if(*raiz!=NULL){
		if(pontos[n]<(*raiz)->pontos[n])
			inserirR(&(*raiz)->esq,pontos,(n+1)%2);
		else
			inserirR(&(*raiz)->dir,pontos,(n+1)%2);
	}
	else
		novoNo(&*raiz,pontos);
}

void exibeArvore(KdTree *raiz, int n){
	int i;
	if(raiz!=NULL){
		n++;
		exibeArvore(raiz->dir,n);
		for(i=0;i<5*n;i++)
			printf(" ");
		printf("(%d, %d)\n",raiz->pontos[0],raiz->pontos[1]);
		exibeArvore(raiz->esq,n);
	}
}

void mataArvore(KdTree **raiz){
	if(*raiz!=NULL){
		mataArvore(&(*raiz)->esq);
		mataArvore(&(*raiz)->dir);
		free(*raiz);
	}
}
