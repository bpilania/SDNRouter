#include "flowtable.h"

void process_packet_from_queue1(struct queue* queue1_head,	struct queue* output_queue_tail,
		struct queue* queue2_tail, pthread_t *thread2, struct flowentry* flowtable) {

	int iret1;
	/* Create independent threads each of which will execute function */

	struct arguments *args = (struct arguments*)malloc(sizeof(struct arguments)); //WILL THIS BE A PROBLEM?? SHOULD I DO MALLOC??
	args->queue1_head = queue1_head;
	args->queue2_tail = queue2_tail;
	args->output_queue_tail = output_queue_tail;
	args->flowtable = flowtable;

	iret1 = pthread_create(thread2, NULL, process_packet, (void*)args);
}

void* process_packet(void * args) {
	struct arguments *args_ptr = (struct arguments *)args;
	struct queue* queue1_head = (struct queue*) args_ptr->queue1_head;
	struct queue* output_queue_tail = (struct queue*) args_ptr->output_queue_tail;
	struct queue* queue2_tail = (struct queue*) args_ptr->queue2_tail;
	struct flowentry* flowtable = (struct flowentry*)args_ptr->flowtable;


	printf("\nIt's going in infinite loop\n");

	while (1) {
		int count = -1;
		if(queue1_head->next != NULL){
				pkt_data_t *temp = (pkt_data_t *)dequeue(queue1_head);
				ip_packet_t *ip_pkt;
				ip_pkt = (ip_packet_t *) temp->data;
				//Comparision logic
				while(++count < FLOWTABLE_SIZE && flowtable[count].match.protocol != 0
						&& flowtable[count].match.ip_addr_src[0] != 0){ // Check for end of flowtable entries

					if(flowtable[count].match.protocol != temp->header.prot)
						continue;

					if(flowtable[count].match.hw_addr_src[0] != temp->header.src[0])
						continue;

					if(flowtable[count].match.hw_addr_src[1] != temp->header.src[1])
						continue;

					if(flowtable[count].match.hw_addr_src[2] != temp->header.src[2])
						continue;

					if(flowtable[count].match.hw_addr_src[3] != temp->header.src[3])
						continue;

					if(flowtable[count].match.hw_addr_src[4] != temp->header.src[4])
						continue;

					if(flowtable[count].match.hw_addr_src[5] != temp->header.src[5])
						continue;

					if(flowtable[count].match.hw_addr_dest[0] != temp->header.dst[0])
						continue;

					if(flowtable[count].match.hw_addr_dest[1] != temp->header.dst[1])
						continue;

					if(flowtable[count].match.hw_addr_dest[2] != temp->header.dst[2])
						continue;

					if(flowtable[count].match.hw_addr_dest[3] != temp->header.dst[3])
						continue;

					if(flowtable[count].match.hw_addr_dest[4] != temp->header.dst[4])
						continue;

					if(flowtable[count].match.hw_addr_dest[5] != temp->header.dst[5])
						continue;

					//if(flowtable[count].match.ingress_port != ) Discuss how to identify ingress port

					if(flowtable[count].match.ip_protocol != ip_pkt->ip_prot)
						continue;

					if(flowtable[count].match.ip_tos != ip_pkt->ip_tos)
						continue;

					if(flowtable[count].match.ip_addr_src[0] != ip_pkt->ip_src[0])
						continue;

					if(flowtable[count].match.ip_addr_src[1] != ip_pkt->ip_src[1])
						continue;

					if(flowtable[count].match.ip_addr_src[2] != ip_pkt->ip_src[2])
						continue;

					if(flowtable[count].match.ip_addr_src[3] != ip_pkt->ip_src[3])
						continue;

					if(flowtable[count].match.ip_addr_dest[0] != ip_pkt->ip_dst[0])
						continue;

					if(flowtable[count].match.ip_addr_dest[1] != ip_pkt->ip_dst[1])
						continue;

					if(flowtable[count].match.ip_addr_dest[2] != ip_pkt->ip_dst[2])
						continue;

					if(flowtable[count].match.ip_addr_dest[3] != ip_pkt->ip_dst[3])
						continue;

					//apply actions and place packet in output queue if required
					//update counters


				}
				//Comparision logic
				//logic for placing packet in queue2
		}

	}
	return 0;
}
