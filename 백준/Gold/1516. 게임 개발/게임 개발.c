#include <stdio.h>
#include <stdlib.h>

int cost[502];
int indegree[502];
int ans[502];

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
    else{
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
Node* adj[502];
 
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1;i <= n;i++) {
        scanf("%d", &cost[i]);
        int input;
        while (1) {
            scanf("%d", &input);
            if (input == -1)
                break;
            if (adj[input] == NULL) {
                adj[input] = (Node*)malloc(sizeof(Node));
                adj[input]->data = i;
                adj[input]->next = NULL;
            }
            else {
                Node* k = adj[input];
                while (k->next != NULL)
                    k = k->next;
                k->next = (Node*)malloc(sizeof(Node));
                k->next->data = i;
                k->next->next = NULL;
            }
            indegree[i]++;
        }
    }
    for (int i = 1;i <= n;i++) {
        if (indegree[i] == 0) {
            Enqueue(&q, i);
        ans[i] = cost[i];
        }
    }
    
    while (!QIsEmpty(&q)) {
        int k = Dequeue(&q);
        Node* st = adj[k];
        while (st != NULL) {
            int u = st->data;
            if (ans[u] < ans[k] + cost[u]) {
                ans[u] = ans[k] + cost[u];
            }
            indegree[u]--;
            if (!indegree[u])
                Enqueue(&q, u);
            st = st->next;
        }
    }
    printf("%d", ans[1]);
    for (int i = 2;i <= n;i++)
        printf("\n%d", ans[i]);
}