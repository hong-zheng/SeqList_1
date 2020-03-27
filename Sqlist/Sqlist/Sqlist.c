#define _CRT_SECURE_NO_WARININGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 4
typedef int DataType;
// Ч�ʽϵ�,�󲿷ֲ�������O(n),����ŵ����֧���������
// ����:
// β��:O(1) ͷ��O(n) �в�O(n)
// ɾ��:
// βɾO(1) ͷɾO(n) ��ɾO(n)
// ��ʵ��˳���
typedef struct SeqList{
	DataType* data;
	int size;
	int capacity;
}SeqList;

// ��ʼ����̬˳���
void InitSeqList(SeqList* list){
	if (NULL == list){
		return;
	}
	// �����ڴ�ռ�
	list->capacity = NUM;
	list->data = (DataType*)malloc(sizeof(DataType)*list->capacity);
	list->size = 0;
}

// ��posλ�ò���һ��Ԫ��value
void seqListInsert(SeqList* sl ,size_t pos ,DataType value){
	if (NULL == sl){
		return;
	}
	if (pos < 0 || pos > sl->size){
		pos = sl->size;
	}
	void checkCapacity(SeqList* list);
	// �ж��Ƿ���Ҫ����
	checkCapacity(sl);

	// �ƶ�ʱ�Ӻ���ǰ�ƶ�
	size_t cpos = sl->size;
	while (cpos>pos){
		sl->data[cpos] = sl->data[cpos-1];
		cpos--;
	}
	sl->data[pos] = value;
	sl->size++;
}

// ɾ��posλ�õ�����
void seqListErase(SeqList* sl,size_t pos){

	if (NULL == sl){
		return;
	}
	// ɾ��ʱ��ǰ����ɾ��
	if (pos < sl->size){
		while (pos < sl->size-1){
			sl->data[pos] = sl->data[pos+1];
			++pos;
		}
		--sl->size;
	}
}
void Display(SeqList* sl){
	if (NULL == sl){
		return;
	}
	for (size_t i = 0; i < sl->size;i++){
		printf("%d ",sl->data[i]);
	}
	printf("\n");
}
// ���������Ƿ񳬱꣬Ȼ������
void checkCapacity(SeqList* list){
	if (NULL == list){
		return;
	}
	if (list->size == list->capacity){
		list->capacity += NUM;
		//list->data = (DataType*)realloc(list->data,sizeof(DataType)*list->capacity);
		// ����realloc�ȼ������´��빦��

		DataType* data = (DataType*)malloc(sizeof(DataType)*list->capacity);
		memcpy(data,list->data,sizeof(DataType)*list->size);
		free(list->data);
		list->data = data;
		//printf(" Realloc \n");
		//Display(list);
	}
}
// ͷ�壬��������д��������ͷ��
void seqListFrontInsert(SeqList* list, DataType value){
	if (NULL == list){
		return;
	}
	checkCapacity(list);
	size_t pos = list->size;
	while (pos > 0){
		list->data[pos] = list->data[pos - 1];
		pos--;
	}
	list->data[0] = value;
	list->size++;
}

// β�壬��������д��������β��
void seqListBackInsert(SeqList* list, DataType value){
	if (NULL == list){
		return;
	}
	checkCapacity(list);
	list->data[list->size++] = value;
}

// ͷɾ
void seqListFrontDele(SeqList* list){
	if (NULL == list){
		return;
	}
	size_t npos = 0;
	while (npos < list->size-1){
		list->data[npos] = list->data[npos+1];
		npos++;
	}
	list->size--;
}
// βɾ
void seqListBackDele(SeqList* list){
	if (NULL == list){
		return;
	}
	list->size--;
}
void test1(){
	SeqList sl;
	InitSeqList(&sl);
	seqListInsert(&sl, 2, 2);
	Display(&sl);

	seqListInsert(&sl, 1, 1);
	Display(&sl);
	seqListInsert(&sl, 0, 0);
	Display(&sl);
	seqListErase(&sl, 2);
	Display(&sl);
	seqListInsert(&sl, 4, 4);
	Display(&sl);

	seqListInsert(&sl, 5, 5);
	Display(&sl);

	seqListInsert(&sl, 0, 0);
	Display(&sl);
	seqListErase(&sl,0);
	Display(&sl);
	seqListInsert(&sl, 3, 3);
	Display(&sl);
	seqListFrontInsert(&sl,34);
	Display(&sl);
	seqListFrontInsert(&sl, 132);
	Display(&sl);
	seqListBackInsert(&sl, 89);
	Display(&sl);
	seqListFrontDele(&sl);
	Display(&sl);
	seqListErase(&sl,1);
	Display(&sl);
	seqListErase(&sl, 0);
	Display(&sl);
	seqListBackDele(&sl);
	Display(&sl);
	seqListBackDele(&sl);
	Display(&sl);

}
int main(){
	test1();
	system("pause");
	return 0;
}