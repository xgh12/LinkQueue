#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define Status int

#define SUCCESS 1
#define FAILURE 0
#define ERROR 0

// 定义队列结点
typedef struct QNode
{
	ElemType data;
	struct QNode* next;
}QNode, * QNodePrt;

// 定义队首、队尾指针
typedef struct
{
	QNodePrt front, rear;
}LinkQueue;

// 初始化队列
Status InitQueue(LinkQueue* q)
{
	// 分配内存空间，建立头结点
	q->front = q->rear = (QNodePrt)malloc(sizeof(QNode));
	// 判断分配是否成功
	if (!q->front) {
		printf("内存分配失败\n");
		exit(ERROR);
	}
	// 指针域指向空
	q->front->next = NULL;
	printf("初始化队列成功\n");

	return SUCCESS;
}

// 出队操作
Status OutQueue(LinkQueue* q, ElemType* e)
{
	QNodePrt p; // 临时结点
	// 判断队列是否为空
	if (q->front == q->rear) {
		return ERROR;
	}

	// 出队列操作
	p = q->front->next;
	*e = p->data; // 获取结点值

	// 将队首移动到第二个结点，第一个结点出队
	q->front->next = p->next;

	// 判断队列是否只有一个结点，只有一个结点则出队后队首队尾指向同一结点
	if (q->rear = p) {
		q->rear = q->front;
	}
	// 释放出队结点
	free(p);
	return SUCCESS;
}

// 获取队列长度
Status QueueLength(LinkQueue* q)
{
	int length = 0;
	QNodePrt p;
	p = q->front->next;
	while (p)
	{
		length++;
		p = p->next;

	}
	printf("队列长度为:%d\n", length);
	return SUCCESS;
}

// 打印队列
Status printQueue(LinkQueue* q)
{
	// 判断队列是否为空
	if (q->front == q->rear) {
		printf("队列为空\n");
		return ERROR;
	}

	QNodePrt p;
	p = q->front->next;

	printf("\n队列内数据为：");
	while (p)
	{
		printf("%d", p->data);
		p = p->next;

	}

	return SUCCESS;
}

// 入队操作
Status InsertQueue(LinkQueue* q, ElemType e)
{
	QNodePrt p;
	p = (QNodePrt)malloc(sizeof(QNode));

	if (p == NULL) {
		printf("内存分配失败!\n");
		exit(ERROR);
	}

	// 赋值给新结点
	p->data = e;
	// 新结点的指针域为空
	p->next = NULL;
	// 尾指针后移，指向新结点
	q->rear->next = p;
	q->rear = p;

	printf("%d入队成功\n", e);
	return SUCCESS;
}

int main(int argc, char const* argv[])
{
	ElemType data;

	printf("开始初始化队列\n\n");
	LinkQueue linkQ;
	InitQueue(&linkQ);

	printf("入队开始\n");
	int i = 0;
	for (i = 0; i < 5; i++)
		InsertQueue(&linkQ, i);

	QueueLength(&linkQ);

	OutQueue(&linkQ, &data);
	printf("\n出队数据为:%d\n", data);
	QueueLength(&linkQ);
	//printQueue(&linkQ);

	OutQueue(&linkQ, &data);
	printf("\n出队数据为:%d\n", data);

	return 0;
}