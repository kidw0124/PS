//순차 자료구조를 이용한 최대 히프 프로그램

#include<stdio.h>
#include<stdlib.h>

#define MAX_ELEMENT 100005

typedef struct { //히프에 대한 1차원 배열과 히프 원소의 갯수를 구조체로 묶어 선언
	int heap[MAX_ELEMENT];
	int heap_size;
}heapType;

heapType* createHeap()//공백 히프를 생성하는 연산
{
	heapType *h = (heapType *)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}

void insertHeap(heapType *h, int item) //히프에 item을 삽입하는 연산
{
    h->heap_size++;
    int hs=h->heap_size;
    while((hs-1)&&(item>h->heap[hs/2])){h->heap[hs]=h->heap[hs/2];hs/=2;}
    h->heap[hs]=item;
}

void printHeap(heapType *h) //1차원 배열 히프의 내용을 출력하는 연산
{
	int i;
	for (i = 1; i <= h->heap_size; i++)
		printf("%d ", h->heap[i]);
}

int main()
{
	int i, n;
	heapType *heap = createHeap();

    scanf("%d",&n);
	for (i = 2; i <= n; i++)insertHeap(heap,i);
	insertHeap(heap,1);


	printHeap(heap);
	return 0;
}
