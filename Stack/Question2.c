typedef struct {
    int queue[101];
    int top;
    int start;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*) malloc(sizeof(MyQueue));
    obj->top = -1;
    obj->start = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->queue[++obj->top] = x;
}

int myQueuePop(MyQueue* obj) {
    return obj->queue[++obj->start];
}

int myQueuePeek(MyQueue* obj) {
    return obj->queue[obj->start+1];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top == obj->start;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/