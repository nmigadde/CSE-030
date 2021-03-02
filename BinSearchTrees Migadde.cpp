#include <iostream>

using namespace std;


struct Node {
    long data;
    Node* left;
    Node* right;
};


Node* insert(Node* root, long value){
    // If the tree I'm inserting into is empty
    if (root == NULL){
        // Make a new node and set it to be the root
        root = new Node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    }
    else{
        if (value < root->data){
            // Go left
            root->left = insert(root->left, value);
        }
        else{
            // Go right
            root->right = insert(root->right, value);
        }
    }
    
    return root;
}


void traverse(Node* root){
    if (root != NULL){
        traverse(root->left);
        cout << root->data << endl;
        traverse(root->right);
    }
}


bool search(Node* root, long value){
    if (root == NULL){
        // Tree is empty
        return false;
    }
    else{
        // Tree is not empty
        if (root->data == value){
            return true;
        }
        else if (root->data < value){
            // Go to the right
            return search(root->right, value);
        }
        else {
            // Go left
            return search(root->left, value);
        }
    }
}


// A function to display the tree graphically
void displayTree(Node* root, int level, int direction){
    // Don't worry about this function, just use it
    if (root != NULL){
        displayTree(root->right, level+1, 1);
        
        for (int i = 0; i < level-1; i++) {
            std::cout << "   ";
        }
        if (level > 0 ){
            if (direction == 1){
                std::cout << " /--";
            }
            else{
                std::cout << " \\--";
            }
        }
        std::cout << root->data;
        std::cout << std::endl;
        level++;
        
        displayTree(root->left, level, -1);
    }
}

// Call the function to display the tree and leave some space afterwards
void drawTree(Node* root){
    if (root == NULL){
        cout << "Empty tree";
    }
    displayTree(root, 0, 0);
    std::cout << std::endl << std::endl;
}


Node* findParent(Node* root, Node* node){
    if (node == root){
        return NULL;
    }
    
    // Get a pointer to the root
    Node* copy = root;
    
    bool done = false;
    
    while (!done){
        if (copy->data <= node->data){
            // Node we want is to the right of current one
            if (copy->right->data != node->data){
                copy = copy->right;
            }
            else{
                done = true;
            }
        }
        else {
            // Node we are looking for is to the left
            if (copy->left->data != node->data){
                copy = copy->left;
            }
            else{
                done = true;
            }
        }
    }
    
    // We now know that copy points to the parent of node
    return copy;
}

// A function to find the minimum value in a tree
Node* findMin(Node* root){
    // If the current node has no left
    // Then there can't be anything in
    // the tree smaller than it
    if (root->left == NULL){
        return root;
    }
    else {
        // If on the other hand it has a left,
        // then we have not seen the smallest
        // value yet, because there are still
        // unexplored nodes to the left, and
        // we know they all have smaller values
        // than the one we are currently on
        return findMin(root->left);
    }
}


// A function to find the successor of the root element
// A successor of a node Q is defined as the node with the
// smallest value that is greater than or equal to the data in Q
Node* findSucc(Node* root){
    // First, if we are asked to find the successor the
    // root element of an empty tree, just return NULL
    
    if (root == NULL){
        return NULL;
    }
    
    // Second, make sure there is something on the right of the root
    // That's the only place you will find values greater than the
    // one in the root
    
    if (root->right == NULL){
        // The root is its own successor
        return root;
    }
    else{
        // Find the smallest value to the right of you
        return findMin(root->right);
    }
}


Node* remove(Node* &root, Node* &node){
    // Provide your code here
    if (root == NULL)
    	return root;
    else {
    	Node *truRoot = root;
    	Node *temp = findSucc(root);
    	root = root->right;
    	root->left = NULL;
    	root = truRoot;
    	root->data = temp->data;
    	delete temp;
	}
    return root;
}

int main() {
    Node* root = NULL;
    
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    
    cout << "Initial" << endl;
    drawTree(root);
    
    root = remove(root, root);

    cout << "Result" << endl;
    drawTree(root);
    return 0;
}
