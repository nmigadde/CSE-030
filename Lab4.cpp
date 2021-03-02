#include <iostream>
#include <stdlib.h>


using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(){
        data = 0;
        next = NULL;
    }
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


struct LinkedList {
    Node* head;
    
    LinkedList(){
        head = NULL;
    }
    
    void append(int value){
        
        if (head == NULL){
            head = new Node(value);
        }
        else{
            // Allocate a new node with value
            // Go to the last element of the list
            // Make the next of the last element point to the new node
            
            Node* newNode = new Node(value);
            
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            // At this point, temp is pointing to the last existing element of list
            
            temp->next = newNode;
        }
    }
    
    void insertAt(int index, int value) {
        // Provide your code here
        Node* temp;
        Node* head2 = head;
        int counter = 0;
        temp->data = value; 

        while(head2 != NULL){

            if(counter == index){
                temp->next = head2;
            }

            if(counter == index-1){
                head2->next = temp;
            }
            counter++;
            head2 = head2->next;
        }

        while(index>counter){
            Node* newNode = new Node();

            
            head2->next = newNode;
            counter++;
        }

    }
    
    int getValue(int index){
        // Provide your code here
        Node* head2 = head;
        int counter = 0;
        int value = 0;

        while(head2 != NULL){

            if(counter == index){
                value = head2->data;
            }


            counter++;
            head2 = head2->next;
        }

        return value;
    }
    
    void setValue(int index, int value){
        // Provide your code here
        Node* head2 = head;
        int counter = 0;

        while(head2 != NULL){

            if (counter == index){
                head2->data = value;
            }

            counter++;
            head2 = head2->next;
        }
    }
    
    void print (){
        Node* temp = head;
        
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    
    ~LinkedList(){
        Node* temp = head;
        
        while(temp != NULL){
            temp = temp->next;
            delete head;
            head = temp;
        }
    }
};


int main(int argc, const char * argv[]) {
    
    LinkedList myList;
    
    
    for (int i = 0; i < 6; i++) {
        myList.append(i);
    }
    
    myList.insertAt(2, 77);
    
    myList.insertAt(10, 89);
    
    myList.append(101);
    
    myList.setValue(0, 11);
    
    cout << myList.getValue(2) << endl << endl;
    
    myList.print();
    
    cout << "HI" << endl;
    cout << "do something" << endl;


    //    Expected output:
    //    77
    //
    //    11
    //    1
    //    77
    //    2
    //    3
    //    4
    //    5
    //    0
    //    0
    //    0
    //    89
    //    101
    
    system("PAUSE");
    return 0;
}















