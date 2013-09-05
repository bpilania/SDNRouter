struct packet{
	int studentID;
	char* name;
};

struct queue{
	void* data;
	struct queue* next;
};

struct queue* enqueue(struct queue* q, void* packet);

void* dequeue(struct queue* head);
