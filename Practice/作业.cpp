#include<bits/stdc++.h>
using namespace std;
class crQueue{
	int *que;
	int front,rear;
	int max;
	public :
		crQueue(int n);
		~crQueue() ;
		int enQueue(int e);
		int deQueue(int& e);
		void print();
		int getLength();
		int isEmpty();
};
crQueue::~crQueue(){
	free(que);
}

crQueue::crQueue(int n){
	que=(int*)malloc(sizeof(int)*n);
	front = 0;
	rear = 0;
	max = n-1;
}
int crQueue::getLength(){
	return (rear-front+max)%max;
}
int crQueue::isEmpty(){
	if(front == rear)return 1;
	return 0;
}
int crQueue::enQueue(int e){
	if(getLength() == max){
		return 0;
	}
	que[rear] = e;
	rear = (rear+1)%max;
	return 1;
}
int crQueue::deQueue(int &e){
	if(isEmpty()){
		return 0;
	}
	e = que[front];
	front = (front+1)%max;
	return 1;
}
void crQueue::print(){
	int t = front;
	while(t != rear){
		cout << que[t] << "  ";
		t = (t+1)%max;
	}
}

int main(){
	crQueue q(10)  ;
	for(int i = 0;i < 10;i++){
		q.enQueue(i);
	}
	q.print();
	
	return 0;
}
