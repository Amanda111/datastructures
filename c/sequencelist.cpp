#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
	int incrementsize;
}SqList;



void InitList_Sq(SqList &L,int maxsize = LIST_INIT_SIZE,int incresize = LISTINCREMENT){
	L.elem = (ElemType *)malloc(maxsize *sizeof(ElemType));
	if(!L.elem) exit(1);
	L.length = 0;
	L.listsize = maxsize;
	L.incrementsize = incresize;
}


int LIstLength_Sq(SqList L){
	return L.length;
}

int LocateElem_Sq(SqList L,ElemType e){
	for(int i = 0;i<L.length;i++){
		if(L.elem[i]==e) return	i;
	}
	return -1;
}
