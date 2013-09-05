#include "simplequeue.h"
#include <stdlib.h>

struct queue* enqueue(struct queue* q, void* packet){
	q->next = (struct queue*)malloc(sizeof(struct queue));
	q->next->data = packet;
	q->next->next = NULL;
	return q->next;
}

void* dequeue(struct queue* head){
	if(head->next == NULL)
		return NULL;

	struct queue* node = head->next;
	void* data = node->data;
	free(node);
	head->next = head->next->next;
	return data;
}

