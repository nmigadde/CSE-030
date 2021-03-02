#include <iostream>

using namespace std;

struct ResizableArray {
    // This is the poiner to the start of our array
    int* data;
    
    // Keep track of how much memory we have allocated
    int size;
    
    // Keep track of how much memory we have used
    int counter;
    
    // A default constructor
    ResizableArray(){
        // Start off by allocating memory for 1 int
        data = new int[1];
        
        // This means we have allocated for 1
        size = 1;
        
        // And we are currently using 0
        counter = 0;
    }
    
    // Print the contents we have
    void print(){
        for (int i = 0; i < counter; i++){
            cout << data[i] << endl;
        }
    }
    
    int getValueAt(int index){
        // Provide your code here
	int p = 0;
	p = data[index];
	return p;
    }
    
    void setValueAt(int index, int value){
        // Provide your code here
	int b = 0;
	b = value;
	int c = 0;
	c = index;

	data[c] = b;
    }
    
    void insertAt(int index, int value){
        // Provide your code here
	int temp = 0;
	int temp2 = 0;
	int p = size+1;
	temp = data[index];
	data[index] = value;

	for (int i = 1; i < p-index; i++){
		int b = i + 1;
		 if(index+1 > size || index+b > size){
			int oldSize = size;
			size = size *  2;
			int* newArr = new int[size];
			for (int i = 0; i < oldSize; i++){
				newArr[i] = data[i];
			}
			delete[] data;
			data = newArr;
		} 
		
		temp2 = data[index+i];
		data[index+i] = temp;
		temp = data[index+b];
		data[index+b] = temp2;

		
	}
	
    }
    
    // Store a new value in the array
    void insert(int value){
        // The very first time this is called
        // we know we have enough storage allocated
        // because we allocated space for 1 int
        // so we store it
        data[counter] = value;
        // and increase the counter
        counter++;
        
        // If we are out of space, i.e. we have
        // stored as much as we have allocated
        // then we need to increase our storage space
        if (counter == size){
            // Just for convenience, store the old size
            int oldSize = size;
            
            // Let's double the amount of storage we have
            size = size * 2;
            
            // Allocate another chunk of memory
            // twice as big as the first
            int* newArr = new int[size];
            
            // Copy all elements from the old location
            // to the new location
            for (int i = 0; i < oldSize; i++) {
                newArr[i] = data[i];
            }
            
            // Release the old location
            delete[] data;
            
            // Make our data pointer point to the new location
            data = newArr;
            
        }
    }
};


int main(int argc, const char * argv[]) {
    // Create a resizable array
    ResizableArray array;
    
    for (int i = 0; i < 6; i++) {
        array.insert(i);
    }
    
    array.insertAt(2, 77);
    
    array.insertAt(10, 89);
    
    array.insert(101);
    
    // Print out the array
    array.print();
    
    /* Expected output of array.print()
     0
     1
     77
     2
     3
     4
     5
     0
     0
     0
     89
     101
    */
    
    cout << "count: " << array.counter << endl;
    cout << "size : " << array.size << endl;
    
    /* Expected output of 2 lines above
     
     count: 12
     
     count: 12
     size : 16
    
    */
   
   return 0;
}

