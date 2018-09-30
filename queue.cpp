#include <iostream>

using namespace std;

#define MAX 10

class queue {
	int arr[MAX];
	int front;
	int rear;

public:
	void push(int);
	void pop();
	int top();
	void print_queue();
	bool isFull();
	bool isEmpty();
	int peek();
	bool dequeue();
	queue();
};

queue::queue(){
	rear = -1;
	front = -1;
}

void queue::print_queue(){
	for(int i=front;i<rear;i++)
		cout << arr[i] << " ";

	cout << endl;
}

bool queue::isFull(){

	if(rear == MAX-2)
		return true;
	else
		return false;
}

bool queue::isEmpty(){

	if(front == rear)
		return true;
	else
		return false;
}

bool queue::dequeue(){

	if(isEmpty()){
		return false;
	}
	else{
		front++;
		return true;
	}
}

void queue::push(int val){

	if(isEmpty()){
		front = 0;
		rear = 0;
	}

	if(!isFull()){
		arr[rear] = val;
		rear++;
	}
	else
		cout << "Queue is Full\n";

	// cout << front << " -- " ;
}

int queue::peek(){

	return arr[front];
}



int main(){
	
	queue q;

	if(q.isEmpty())
		cout << "Empty\n";

	for(int i=0;i<10;i++){
		q.push(i+10);
	}

	q.print_queue();

	while(!q.isEmpty()){
		q.dequeue();
	}
	cout << q.peek() << endl;

	q.push(1100);

	cout << q.peek() << endl;

}