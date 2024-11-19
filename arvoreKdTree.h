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
