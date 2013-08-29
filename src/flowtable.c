#include "flowtable.h"
#include <pthread.h>



void process_packet_from_queue1(struct queue* queue1_head,	struct queue* output_queue_tail, struct queue* queue2_tail, pthread_t *thread1) {

	int iret1;
	char *message1 = "Bhaskar";
	/* Create independent threads each of which will execute function */

	struct arguments *args = (struct arguments*)malloc(sizeof(struct arguments)); //WILL THIS BE A PROBLEM?? SHOULD I DO MALLOC??
	args->queue1_head = queue1_head;
	args->queue2_tail = queue2_tail;
	args->output_queue_tail = output_queue_tail;

	iret1 = pthread_create(thread1, NULL, process_packet, (void*)args);
}

void* process_packet(void * args) {
	struct arguments *args_ptr = (struct arguments *)args;
	struct queue* queue1_head = (struct queue*) args_ptr->queue1_head;
	struct queue* output_queue_tail = (struct queue*) args_ptr->output_queue_tail;
	struct queue* queue2_tail = (struct queue*) args_ptr->queue2_tail;

	if(queue1_head->next != NULL){
		printf("\nIn if block\n");
		struct packet *temp = (struct packet *)queue1_head->next->data;
		printf("\n Values are: %s",temp->name);
	}

	printf("\nIt's going in infinite loop\n");

	while (1) {

	}
	return 0;
}
