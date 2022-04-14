typedef struct node{
    char* val;
    struct node* next;
}* queue;

void init_queue(queue* s);
void push(queue* s, char* d);
char* top(queue s);
bool isEmpty(queue s);
void pop(queue* s);
char* back(queue s);