#include "simplequeue.h"


int main(){

	/*Creating temporary packets*/
	struct packet p1 = {123,"Bhaskar"};
	struct packet p2 = {123,"Monica"};
	struct packet p3 = {123,"Shonar"};
	struct packet p4 = {123,"Mridu"};
	/*Created temporary packets*/

	/*Creating Queue1 for holding packets coming from GNET*/
	struct queue* queue1_head = (struct queue*)malloc(sizeof(struct queue));
	queue1_head->next = NULL;
	struct queue* queue1_tail = queue1_head;
	/*Created Queue1 for holding packets coming from GNET*/


	/*Creating Queue1 for holding packets coming from GNET*/
	struct queue* queue2_head = (struct queue*)malloc(sizeof(struct queue));
	queue2_head->next = NULL;
	struct queue* queue2_tail = queue2_head;
	/*Created Queue1 for holding packets coming from GNET*/


	/*Creating Queue1 for holding packets coming from GNET*/
	struct queue* output_queue_head = (struct queue*)malloc(sizeof(struct queue));
	output_queue_head->next = NULL;
	struct queue* output_queue_tail = output_queue_head;
	/*Created Queue1 for holding packets coming from GNET*/

	queue1_tail = enqueue(queue1_tail, &p1);
	queue1_tail = enqueue(queue1_tail, &p2);
	queue1_tail = enqueue(queue1_tail, &p3);
	queue1_tail = enqueue(queue1_tail, &p4);

	struct packet* temp;

	temp = (struct packet*)dequeue(queue1_head);
	printf("%d, %s\n",temp->studentID,temp->name);
	temp = (struct packet*)dequeue(queue1_head);
	printf("%d, %s\n",temp->studentID,temp->name);
	temp = (struct packet*)dequeue(queue1_head);
	printf("%d, %s\n",temp->studentID,temp->name);
	/*temp = (struct packet*)dequeue(queue1_head);
	printf("%d, %s\n",temp->studentID,temp->name);
	temp = (struct packet*)dequeue(queue1_head);
	if(temp != NULL)
		printf("%d, %s\n",temp->studentID,temp->name);*/

	pthread_t thread1;
	//test_threads(&thread1);

	process_packet_from_queue1(queue1_head, output_queue_tail, queue2_tail, &thread1);

	printf("\nYou can always do other work here\n");


	pthread_join( thread1, NULL);

	return 0;
}
