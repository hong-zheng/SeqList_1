#define _CRT_SECURE_NO_WARININGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 4
typedef int DataType;
// 效率较低,大部分操作都是O(n),最大优点就是支持随机访问
// 插入:
// 尾插:O(1) 头插O(n) 中插O(n)
// 删除:
// 尾删O(1) 头删O(n) 中删O(n)
// 简单实现顺序表
typedef struct SeqList{
	DataType* data;
	int size;
	int capacity;
}SeqList;

// 初始化静态顺序表
void InitSeqList(SeqList* list){
	if (NULL == list){
		return;
	}
	// 申请内存空间
	list->capacity = NUM;
	list->data = (DataType*)malloc(sizeof(DataType)*list->capacity);
	list->size = 0;
}

// 在pos位置插入一个元素value
void seqListInsert(SeqList* sl ,size_t pos ,DataType value){
	if (NULL == sl){
		return;
	}
	if (pos < 0 || pos > sl->size){
		pos = sl->size;
	}
	void checkCapacity(SeqList* list);
	// 判断是否需要扩容
	checkCapacity(sl);

	// 移动时从后向前移动
	size_t cpos = sl->size;
	while (cpos>pos){
		sl->data[cpos] = sl->data[cpos-1];
		cpos--;
	}
	sl->data[pos] = value;
	sl->size++;
}

// 删除pos位置的数据
void seqListErase(SeqList* sl,size_t pos){

	if (NULL == sl){
		return;
	}
	// 删除时从前至后删除
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
// 检验容量是否超标，然后扩容
void checkCapacity(SeqList* list){
	if (NULL == list){
		return;
	}
	if (list->size == list->capacity){
		list->capacity += NUM;
		//list->data = (DataType*)realloc(list->data,sizeof(DataType)*list->capacity);
		// 以上realloc等价于以下代码功能

		DataType* data = (DataType*)malloc(sizeof(DataType)*list->capacity);
		memcpy(data,list->data,sizeof(DataType)*list->size);
		free(list->data);
		list->data = data;
		//printf(" Realloc \n");
		//Display(list);
	}
}
// 头插，不利用已写函数进行头插
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

// 尾插，不利用已写函数进行尾插
void seqListBackInsert(SeqList* list, DataType value){
	if (NULL == list){
		return;
	}
	checkCapacity(list);
	list->data[list->size++] = value;
}

// 头删
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
// 尾删
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