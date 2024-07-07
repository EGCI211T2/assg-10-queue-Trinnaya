#ifndef queue_h
#define queue_h
#include "Node.h"
#include <cstring>

class Queue{
    NodePtr headPtr,tailPtr;
    int size;

    public:
        void enqueue(int);
        int dequeue();
        Queue();
        ~Queue();

};

void Queue::enqueue(int x){
    NodePtr new_node=new NODE(x);
    if(new_node){
        if(size==0){
            headPtr=new_node;
            tailPtr=headPtr;
        }
        else{
            tailPtr->set_next(new_node);
        }
        tailPtr=new_node;
        ++size;
    }

}

int Queue::dequeue(){
    if(headPtr!=NULL){
        NodePtr t=headPtr;
        int value=t->get_value();
        headPtr=headPtr->get_next();
        if(size==1) tailPtr=NULL;
        --size;
        delete t;
        cout<<"dequeing "<<value<<endl;
        return value;
    }
    else {
        cout<<"empty queue"<<endl;
        return -1;
    }
}
Queue::Queue(){
    size=0;
    headPtr=NULL;
    tailPtr=NULL;
}
Queue::~Queue(){
    cout<<"clearing queue"<<endl;
    while(size>0) dequeue();
}
    
#endif