#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define Status int

#define SUCCESS 1
#define FAILURE 0
#define ERROR 0

// ������н��
typedef struct QNode
{
	ElemType data;
	struct QNode* next;
}QNode, * QNodePrt;

// ������ס���βָ��
typedef struct
{
	QNodePrt front, rear;
}LinkQueue;

// ��ʼ������
Status InitQueue(LinkQueue* q)
{
	// �����ڴ�ռ䣬����ͷ���
	q->front = q->rear = (QNodePrt)malloc(sizeof(QNode));
	// �жϷ����Ƿ�ɹ�
	if (!q->front) {
		printf("�ڴ����ʧ��\n");
		exit(ERROR);
	}
	// ָ����ָ���
	q->front->next = NULL;
	printf("��ʼ�����гɹ�\n");

	return SUCCESS;
}

// ���Ӳ���
Status OutQueue(LinkQueue* q, ElemType* e)
{
	QNodePrt p; // ��ʱ���
	// �ж϶����Ƿ�Ϊ��
	if (q->front == q->rear) {
		return ERROR;
	}

	// �����в���
	p = q->front->next;
	*e = p->data; // ��ȡ���ֵ

	// �������ƶ����ڶ�����㣬��һ��������
	q->front->next = p->next;

	// �ж϶����Ƿ�ֻ��һ����㣬ֻ��һ���������Ӻ���׶�βָ��ͬһ���
	if (q->rear = p) {
		q->rear = q->front;
	}
	// �ͷų��ӽ��
	free(p);
	return SUCCESS;
}

// ��ȡ���г���
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
	printf("���г���Ϊ:%d\n", length);
	return SUCCESS;
}

// ��ӡ����
Status printQueue(LinkQueue* q)
{
	// �ж϶����Ƿ�Ϊ��
	if (q->front == q->rear) {
		printf("����Ϊ��\n");
		return ERROR;
	}

	QNodePrt p;
	p = q->front->next;

	printf("\n����������Ϊ��");
	while (p)
	{
		printf("%d", p->data);
		p = p->next;

	}

	return SUCCESS;
}

// ��Ӳ���
Status InsertQueue(LinkQueue* q, ElemType e)
{
	QNodePrt p;
	p = (QNodePrt)malloc(sizeof(QNode));

	if (p == NULL) {
		printf("�ڴ����ʧ��!\n");
		exit(ERROR);
	}

	// ��ֵ���½��
	p->data = e;
	// �½���ָ����Ϊ��
	p->next = NULL;
	// βָ����ƣ�ָ���½��
	q->rear->next = p;
	q->rear = p;

	printf("%d��ӳɹ�\n", e);
	return SUCCESS;
}

int main(int argc, char const* argv[])
{
	ElemType data;

	printf("��ʼ��ʼ������\n\n");
	LinkQueue linkQ;
	InitQueue(&linkQ);

	printf("��ӿ�ʼ\n");
	int i = 0;
	for (i = 0; i < 5; i++)
		InsertQueue(&linkQ, i);

	QueueLength(&linkQ);

	OutQueue(&linkQ, &data);
	printf("\n��������Ϊ:%d\n", data);
	QueueLength(&linkQ);
	//printQueue(&linkQ);

	OutQueue(&linkQ, &data);
	printf("\n��������Ϊ:%d\n", data);

	return 0;
}