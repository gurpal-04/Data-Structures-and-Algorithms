

typedef struct {
    int *queue;
    int front;
    int last;
    int size;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *obj = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
    obj -> queue = (int*) malloc(sizeof(int)*k);
    obj -> front = -1;
    obj -> last = -1;
    obj -> size = k;

    return obj;
}
 bool full, empty;
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsEmpty(obj)){
        obj -> queue[++obj->last] = value;
        obj -> front ++;
        obj -> last ++;
        if(obj->last == obj->size){
            obj->last=0;
        }
        
        return true;
    }
    if(!myCircularQueueIsFull(obj)){
        obj -> queue[obj->last++] = value;
        
        if(obj->last == obj->size){
            obj->last=0;
        }
        if(obj->front==obj->last){
            full=true;
            empty=false;
        }
        else{
            full=false;
            empty=true;
        }
        return true;
    }
    
    return false;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(!myCircularQueueIsEmpty(obj)){
        obj -> front++;
        if(obj->front == obj->size){
            obj->front=0;
        }
        if(obj->front==obj->last){
            obj->front=obj->last=-1;
        }
        return true;
    }
    return false;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    
    return obj->queue[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    printf("rear last: %d\n", obj->last);
    if(obj->last==0){
        printf("rear if: \n");
        return obj->queue[obj->size - 1];
    }
    return obj->queue[obj->last-1];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front==-1 && obj->last==-1;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->front == obj->last && !myCircularQueueIsEmpty(obj);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/