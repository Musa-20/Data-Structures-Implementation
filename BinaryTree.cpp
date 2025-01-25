#include <iostream>

class BinaryTree {
private:
    struct Node {
        int value; // node value
        Node* left; // left child
        Node* right; // right child

        // constructor with no arguments
        Node(){
            value = 0;
            left = nullptr;
            right = nullptr;
        };

        // constructor with value
        Node(int val){
            value = val;
            left = nullptr;
            right = nullptr;
        };
    };

    // delete the tree
    void deleteTree(Node* node){
        if(node != nullptr){
            deleteTree(node->left); // delete left child
            deleteTree(node->right); // delete right child
            delete node; // delete the node
        }
    };

    // print the tree: inorder traversal
    void inOrderTraversal(Node* node){
        if(node == nullptr){
            return; // the node is empty
        } 
        else{
            inOrderTraversal(node->left); // print left child
            std::cout << node->value << " ";
            inOrderTraversal(node->right); // print right child
        }
    };

    // print the tree: preorder traversal
    void preOrderTraversal(Node* node){
        if(node == nullptr){
            return; // the node is empty
        } 
        else{
            std::cout << node->value << " "; // print the node value
            preOrderTraversal(node->left); // print left child
            preOrderTraversal(node->right); // print right child
        }
    };

    // print the tree: postorder traversal
    void postOrderTraversal(Node* node) {
        if (node == nullptr) {
            return; // the node is empty
        } else {
            postOrderTraversal(node->left); // print left child
            postOrderTraversal(node->right); // print right child
            std::cout << node->value << " "; // print the node value
        }
    } 

    Node* root; // root node

public:

    // constructor with no arguments
    BinaryTree(){
        root = nullptr;
    };

    // constructor with key and value
    BinaryTree(int val){
        root = new Node(val);
    };

    // destructor
    ~BinaryTree(){
        deleteTree(root);
    };

    // insert a new node
    Node* insert(Node* node, int val){

        if(node == nullptr){
            return new Node(val);// create a new node if the node is null
        }
        if(val < node->value){ // insert to left if value is less than node value
            node->left = insert(node->left, val);
        }
        else if(val > node->value){ // insert to right if value is greater than node value
            node->right = insert(node->right, val);
        }
        return node;
    };

    // insert a new node
    void insert(int val){
        root = insert(root, val);
    };
    
    // public method for inorder traversal
    void inOrderTraversal() {
        inOrderTraversal(root);
    }

    // public method for preorder traversal
    void preOrderTraversal() {
        preOrderTraversal(root);
    }

    // public method for postorder traversal
    void postOrderTraversal() {
        postOrderTraversal(root);
    }

}; 

//In the above code, we have a binary tree class with a nested node class. The node class has a value, left, and right child. 
//The binary tree class has a root node and the following methods:
//1. insert: insert a new node to the tree
//2. inOrderTraversal: print the tree in inorder traversal
//3. inOrderPrint: simply call the inOrderTraversal method to print the tree
//4. deleteTree: delete the tree
//5. destructor: call the deleteTree method to delete the tree

int main(){
    BinaryTree tree;
    tree.insert(10); // create a tree with root node value 10
    tree.insert(5); 
    tree.insert(15); 
    tree.insert(3); 
    tree.insert(7); 
    tree.insert(12); 
    tree.insert(18); 

    std::cout << "Inorder Traversal: ";
    tree.inOrderTraversal(); // print the tree in inorder traversal
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    tree.preOrderTraversal(); // print the tree in preorder traversal
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    tree.postOrderTraversal(); // print the tree in postorder traversal
    std::cout << std::endl;

    tree.insert(2); // insert a new node with value 2
    std::cout << "Inorder Traversal: ";
    tree.inOrderTraversal(); 
    std::cout << std::endl;

    return 0;
};