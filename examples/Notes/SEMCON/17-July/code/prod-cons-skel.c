

struct stack {
  int arr[MAX];
  int top;
};
typedef struct stack stack_t;

//push
//pop

void* producer(void* pv) {
   stack_t *ps = pv;

};

void* consumer(void* pv) {
   stack_t *ps = pv;

};

int main() {
   stack_t s1;
 
   pthread_create(&pt1, NULL, producer, &s1);
   pthread_create(&pt1, NULL, consumer, &s1);
   //join

}

//define push, pop
