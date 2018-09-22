#include <iostream>

using namespace std;

int heap_size = 5; //Global Variable


void print_heap(int* max_heap){

    for(int i=0;i<heap_size;i++)
        cout << max_heap[i] << " ";
    cout << endl;
}

void max_heapify(int* max_heap,int i){
    
    if(i >= heap_size || i <0)
        return;
    
    int largest = -1;
    
    int left = 2*i+1;
    int right = 2*i+2;
    
    if((left<heap_size) && (max_heap[i] < max_heap[left]))
        largest = left;
    else
        largest = i;
    
    if((right<heap_size) && (max_heap[largest] < max_heap[right]))
        largest = right;
    
    // SWAP and call max_heapify only when largest takes a different value other than
    // what was passed in the previous iteration
    
    if(largest != -1 && largest != i ){
        swap(max_heap[i],max_heap[largest]);
        max_heapify(max_heap,largest);
    }

}

void build_heap(int* max_heap){
    
    for(int i=heap_size/2;i>=0;i--)
        max_heapify(max_heap,i);
    
}

int parent(int child){

	if(child%2 == 0)
		return child/2-1;
	else
		return child/2;
}


void insert_in_heap(int* max_heap,int new_val){

	max_heap[heap_size] = new_val;
	int insert_index = heap_size;
	heap_size = heap_size + 1;

	while(max_heap[insert_index] > max_heap[parent(insert_index)]){
		swap(max_heap[insert_index],max_heap[parent(insert_index)]);
		insert_index = parent(insert_index);
	}
}

int extract_max(int* max_heap){

	int max_val = max_heap[0];

	swap(max_heap[0],max_heap[heap_size-1]);
	heap_size = heap_size -1;

	max_heapify(max_heap,0);

	return max_val;
}

int peek(int* max_heap){
	return max_heap[0];
}


int main() {
    
    int max_heap[100] = {1,2,3,4,5};
    
    build_heap(&max_heap[0]);

    print_heap(&max_heap[0]);

    // cout << parent(3) << endl; //passing index as second param

    insert_in_heap(&max_heap[0],7);

    print_heap(&max_heap[0]);

    cout << extract_max(&max_heap[0]);

    cout << "\n";

    print_heap(&max_heap[0]);

    cout << peek(&max_heap[0]);

    cout << "\n";
    
    
}
