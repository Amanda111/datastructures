typedef struct Node
{
	ElemType data;
	struct Node *next;
}LNode, *LinkList;

//init LinkList
void InitList_L(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));
	if(!L) exit(1);
	L->next = NULL;
}

//LinkList length
int ListLength_L(LinkList L)
{
	LinkList p;
	int k = 0;
	p = L->next;
	while(p){
		p = p->next;
		k++;
	}
	return k;
}

//查找节点
LNode * LocateElem_L(LinkList L,ElemType e){
	LinkList p;
	p= L->next;
	while(p && p->data !=e){
		p=p->next;
	}
	return p;
}
