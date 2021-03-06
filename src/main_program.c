#include <stdio.h>

#include "pthread.h"
#include "flowtable.h"

#include<stdint.h>



int main(){

	/*Creating temporary packets*/
	gpacket_t *in_pkt1 = (gpacket_t*)malloc(sizeof(gpacket_t));
	gpacket_t *in_pkt2 = (gpacket_t*)malloc(sizeof(gpacket_t));
	gpacket_t *in_pkt3 = (gpacket_t*)malloc(sizeof(gpacket_t));
	gpacket_t *in_pkt4 = (gpacket_t*)malloc(sizeof(gpacket_t));
	gpacket_t *in_pkt5 = (gpacket_t*)malloc(sizeof(gpacket_t));

	ip_packet_t temp_pack1;
	ip_packet_t temp_pack2;
	ip_packet_t temp_pack3;
	ip_packet_t temp_pack4;
	ip_packet_t temp_pack5;

	pkt_frame_t frame1;
	pkt_frame_t frame2;
	pkt_frame_t frame3;
	pkt_frame_t frame4;
	pkt_frame_t frame5;

	pkt_data_t temp_main_pack1;
	pkt_data_t temp_main_pack2;
	pkt_data_t temp_main_pack3;
	pkt_data_t temp_main_pack4;
	pkt_data_t temp_main_pack5;

	frame1.src_interface = 1;
	frame2.src_interface = 2;
	frame3.src_interface = 3;

	temp_pack1.ip_tos = 0;
	temp_pack1.ip_dst[0] = 192;
	temp_pack1.ip_dst[1] = 168;
	temp_pack1.ip_dst[2] = 1;
	temp_pack1.ip_dst[3] = 1;
	temp_pack1.ip_prot = 1;
	temp_pack1.ip_src[0] = 192;
	temp_pack1.ip_src[1] = 168;
	temp_pack1.ip_src[2] = 1;
	temp_pack1.ip_src[3] = 1;
	temp_main_pack1.header.dst[0] = 1;
	temp_main_pack1.header.dst[1] = 1;
	temp_main_pack1.header.dst[2] = 1;
	temp_main_pack1.header.dst[3] = 1;
	temp_main_pack1.header.dst[4] = 1;
	temp_main_pack1.header.dst[5] = 1;
	temp_main_pack1.header.src[0] = 11;
	temp_main_pack1.header.src[1] = 11;
	temp_main_pack1.header.src[2] = 11;
	temp_main_pack1.header.src[3] = 11;
	temp_main_pack1.header.src[4] = 11;
	temp_main_pack1.header.src[5] = 11;
	temp_main_pack1.header.prot = 8;
	memcpy(temp_main_pack1.data, &temp_pack1, sizeof(ip_packet_t));


	temp_pack2.ip_tos = 0;
	temp_pack2.ip_dst[0] = 192;
	temp_pack2.ip_dst[1] = 168;
	temp_pack2.ip_dst[2] = 1;
	temp_pack2.ip_dst[3] = 1;
	temp_pack2.ip_prot = 1;
	temp_pack2.ip_src[0] = 192;
	temp_pack2.ip_src[1] = 168;
	temp_pack2.ip_src[2] = 2;
	temp_pack2.ip_src[3] = 2;
	temp_main_pack2.header.dst[0] = 22;
	temp_main_pack2.header.dst[1] = 22;
	temp_main_pack2.header.dst[2] = 22;
	temp_main_pack2.header.dst[3] = 22;
	temp_main_pack2.header.dst[4] = 22;
	temp_main_pack2.header.dst[5] = 22;
	temp_main_pack2.header.src[0] = 2;
	temp_main_pack2.header.src[1] = 2;
	temp_main_pack2.header.src[2] = 2;
	temp_main_pack2.header.src[3] = 2;
	temp_main_pack2.header.src[4] = 2;
	temp_main_pack2.header.src[5] = 2;
	temp_main_pack2.header.prot = 8;
	memcpy(temp_main_pack2.data, &temp_pack2, sizeof(ip_packet_t));


	temp_pack3.ip_tos = 0;
	temp_pack3.ip_dst[0] = 192;
	temp_pack3.ip_dst[1] = 168;
	temp_pack3.ip_dst[2] = 1;
	temp_pack3.ip_dst[3] = 1;
	temp_pack3.ip_prot = 1;
	temp_pack3.ip_src[0] = 192;
	temp_pack3.ip_src[1] = 168;
	temp_pack3.ip_src[2] = 3;
	temp_pack3.ip_src[3] = 3;
	temp_main_pack3.header.dst[0] = 3;
	temp_main_pack3.header.dst[1] = 3;
	temp_main_pack3.header.dst[2] = 3;
	temp_main_pack3.header.dst[3] = 3;
	temp_main_pack3.header.dst[4] = 3;
	temp_main_pack3.header.dst[5] = 3;
	temp_main_pack3.header.src[0] = 33;
	temp_main_pack3.header.src[1] = 33;
	temp_main_pack3.header.src[2] = 33;
	temp_main_pack3.header.src[3] = 33;
	temp_main_pack3.header.src[4] = 33;
	temp_main_pack3.header.src[5] = 33;
	temp_main_pack3.header.prot = 8;
	memcpy(temp_main_pack3.data, &temp_pack3, sizeof(ip_packet_t));

	in_pkt1->frame = frame1;
	in_pkt2->frame = frame2;
	in_pkt3->frame = frame3;

	in_pkt1->data = temp_main_pack1;
	in_pkt2->data = temp_main_pack2;
	in_pkt3->data = temp_main_pack3;


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

	queue1_tail = enqueue(queue1_tail, in_pkt1);
	queue1_tail = enqueue(queue1_tail, in_pkt2);
	queue1_tail = enqueue(queue1_tail, in_pkt3);

//	struct packet* temp;

//	temp = (struct packet*)dequeue(queue1_head);
//	printf("%d, %s\n",temp->studentID,temp->name);
//	temp = (struct packet*)dequeue(queue1_head);
//	printf("%d, %s\n",temp->studentID,temp->name);
//	temp = (struct packet*)dequeue(queue1_head);
//	printf("%d, %s\n",temp->studentID,temp->name);




	pthread_t thread2;
	//test_threads(&thread1);

	process_packet_from_queue1(queue1_head, output_queue_tail, queue2_tail, &thread2, &flowtable);

	printf("\nYou can always do other work here\n");


	pthread_join( thread2, NULL);

	return 0;
}
