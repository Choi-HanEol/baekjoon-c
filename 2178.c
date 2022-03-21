#include<stdio.h>
int N, M;
int miro[101][101];
int visit[101][101] = { 0, };

typedef struct {
	int y;
	int x;
	int c;
}Node;

typedef struct {
	int head;
	int tail;
	int count;
	Node data[10300];
}Queue;

void initqueue(Queue* q) {
	q->head = 0;
	q->tail = 0;
	q->count = 0;
}
void enqueue(Queue* q, int y, int x, int c) {
	visit[y][x] = 1;
	q->data[q->tail].y = y;
	q->data[q->tail].x = x;
	q->data[q->tail].c = c;
	(q->tail)++;
}
Node dequeue(Queue* q) {
	Node result = q->data[q->head];
	q->head++;
	return result;
}
int check(Queue* q, int y, int x) {
	if (visit[y][x] == 1) {	//방문한 적이 있는경우
		return 0;
	}
	else if (y<1 || x<1 || y>N || x>M) {//범위를 벗어난 경우
		return 0;
	}
	else if (miro[y][x] == 0) {
		return 0;
	}
	else
	{
		return 1;
	}
}

int main() {
	Queue q;
	initqueue(&q);
	
	Node result;
	int count=1;
	int i, j, y=1, x=1;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%1d", &miro[i][j]);
		}
	}  
	
	enqueue(&q, y, x, count);
	while (1) {
		if (y == N && x == M) {
			printf("%d\n", count);
			break;
		}
		result = dequeue(&q);
		y = result.y;
		x = result.x;
		count = result.c;
		
		//인접한노드 넣기
		if(check(&q, y-1, x)){//상
			enqueue(&q, y-1, x, count+1);
		}
		if (check(&q, y+1, x)) {//하
			enqueue(&q, y+1, x, count + 1);
		}
		if (check(&q, y, x-1)) {//좌
			enqueue(&q, y, x-1, count + 1);
		}
		if (check(&q, y, x+1)) {//우
			enqueue(&q, y, x+1, count + 1);
		}
	}
	return 0;
}
