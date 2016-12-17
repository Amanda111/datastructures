typedef struct DuNode{
	ElemType data;
	struct DuNode *prior;
	struct DuNode *next;
}DuLNode, *DuLinkList;

void InitList_DuL(DuLinkList &L){
	L = (DuLNode *)malloc(sizeof(DuLNode));
	if(!L) exit(1);
	L->next = NULL;
	L->prior = NULL;
}

bool ListInsert_DUL(DuLinkList &L,int i,ElemType e){
	DuLinkList p,s,q;
	
}