#include <stdio.h>
#include <stdlib.h>          
#define MAX_PEOPLE 32001
 
typedef struct _node
{
    int data;
    struct _node * next;
} Node;
 
typedef struct _lQueue
{
    Node * front;   
    Node * rear;    
} Queue;
 
typedef struct vector {
 
}vector;
 
void QueueInit(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}
 
int QIsEmpty(Queue * pq)
{
    if (pq->front == NULL)
        return 1;
 
    else
        return 0;
}
 
void Enqueue(Queue * pq, int data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
 
    if (QIsEmpty(pq))
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else
    {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}
 
int Dequeue(Queue * pq)
{
    Node * delNode;
    int retData;
 
    if (QIsEmpty(pq))
    {
        printf("Queue Memory Empty!!");
        exit(-1);
    }
 
    delNode = pq->front;
    retData = delNode->data;
    pq->front = pq->front->next;
 
    free(delNode);
    return retData;
}
 
Queue q;
int inDegree[MAX_PEOPLE];
Node* Graph[MAX_PEOPLE];
 
void putvertex(int a, int to) {
    if (Graph[a] == NULL)
    {
        Graph[a] = (Node*)malloc(sizeof(Node));
        Graph[a]->data = to;
        Graph[a]->next = NULL;
        return;
    }
    Node* k = Graph[a];
    while (k->next != NULL) 
        k = k->next;
    k->next= (Node*)malloc(sizeof(Node));
    k->next->data = to;
    k->next->next = NULL;
    return;
}
 
int main() {
    QueueInit(&q);
    int m, n;
    scanf("%d %d\n", &n, &m);
    for (int i = 0;i < m;i++) {
        int k, j;
        scanf("%d %d\n", &k, &j);
        putvertex(k, j);
        inDegree[j]++;
    }
    for (int i = 1;i < n+1;i++)
    {
        if (inDegree[i] == 0) 
            Enqueue(&q, i);
    }
    
 
    while (!QIsEmpty(&q)) {
        int cur = Dequeue(&q);
        printf("%d ", cur);
            Node* k = Graph[cur];
            while (k != NULL) {
                inDegree[k->data]--;
                if (inDegree[k->data]==0)
                    Enqueue(&q, k->data);
                k = k->next;
            }
    }
}
