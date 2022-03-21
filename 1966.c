#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int arr_pri[10];
int n, m;
int count;

typedef struct Node {
    int priority;
    int select;
}Node;
typedef struct Queue {
    Node* data;
    int head;
    int tail;
}Queue;
void initArray() {
    int i;
    for (i = 0; i < 10; i++) {
        arr_pri[i] = 0;
    }
}
int checkExistPrior(int pri) {
    int i;
    for (i = pri + 1; i < 10; i++) {
        if (arr_pri[i] != 0) {
            return 1;   //우선순위가 자신보다 높은게 있다면 1 반환 
        }
    }
    return 0;
}
void initQueue(Queue* q, int n) {
    q->data = (Node*)malloc(sizeof(Node) * n);
    q->head = 0;
    q->tail = 0;
}
int fullQueue(Queue* q) {
    if (q->tail == n) {
        return 1;
    }
    return 0;
}
void push(Queue* q, Node pri) {
    if (fullQueue(q)) {
        q->head--;
        int i;
        for (i = q->head; i < n-1; i++) {
            q->data[i] = q->data[i+1];
        }
        q->tail--;
    }
    q->data[q->tail] = pri;
    arr_pri[pri.priority]++;
    q->tail++;
}
Node pop(Queue* q) {
    Node result;
    result = q->data[q->head];
    count++;
    arr_pri[result.priority]--;
    q->head++;
    return result;
}
int main() {
    int test_case;
    int i, j, pri;
    Node result, input;
    Queue q;
    scanf("%d", &test_case);
    for (i = 0; i < test_case; i++) {
        scanf("%d %d", &n, &m);
        initQueue(&q,n);
        initArray();
        count = 0;

        for (j = 0; j < n; j++) {
            scanf("%d%*c", &pri);
            input.priority = pri;
            push(&q, input);    
        }
        q.data[m].select = 1;
        while (1) {
            result = pop(&q);
            if (q.data[q.head-1].select == 1 && !checkExistPrior(result.priority))  break;
            else if (!checkExistPrior(result.priority)) {
                continue;
            }
            else
            {
                push(&q, result);
                count--;
            }
        }
        printf("%d\n", count);
    }
    free(q.data);
}
