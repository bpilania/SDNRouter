#include "simplequeue.h"

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

/*void test_threads(pthread_t *thread1){
	int  iret1;
	char *message1 = "Bhaskar";
	 Create independent threads each of which will execute function
	iret1 = pthread_create(thread1, NULL, helper_test_threads, (void*) message1);

	printf("\nThis should not come\n");
}

void* helper_test_threads(void* message){
	printf("\nMr. %s Going in infinite loop\n", (char*)message);
	while(1){

	}
	return 0;
}*/
