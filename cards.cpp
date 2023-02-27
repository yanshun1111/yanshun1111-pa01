// cards.cpp
// Author: Shun Yan
// Implementation of the classes defined in cards.h


#include <iostream>
#include "cards.h"
using std::cout;

// constructor sets up empty tree
CardBST::CardBST() { 
    root = NULL;
}

// destructor deletes all nodes
CardBST::~CardBST() {
    clear(root);
}

// recursive helper for destructor
void CardBST::clear(Node *n) {
    if (n == NULL) return;
    clear(n->left);
    clear(n->right);
    delete n;
}

// insert value in tree; return false if duplicate
bool CardBST::insert(Card value) {
    if (root == NULL){
        root = new Node(value);
        return true;
    }
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool CardBST::insert(Card value, Node *n) {

    if (n->info == value) return false;

    else if (value < n->info){
        if (n->left == NULL){
            n->left = new Node(value);
            n->left->parent = n;
            return true;
        }
        else{
            return insert(value, n->left);
        }
    }

    else{
        if (n->right == NULL){
            n->right = new Node(value);
            n->right->parent = n;
            return true;
        }
        else{
            return insert(value, n->right);
        }
    }
    
}




// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
CardBST::Node* CardBST::getNodeFor(Card value, Node* n) const{
    
    if (n == NULL) return NULL;
    if (n->info == value) return n;

    else if (value < n->info){
        return getNodeFor(value, n->left);
    }
    else{
        return getNodeFor(value, n->right);
    }
    
}

// returns true if value is in the tree; false if not
bool CardBST::contains(Card value) const {
    if (getNodeFor(value, root)) return true;
    return false;
}

// print tree data in-order, with helper
void CardBST::printInOrder() const {
    printInOrder(root);
}
void CardBST::printInOrder(Node *n) const {
    if (!n) return;
    printInOrder(n->left);
    cout << n->info.face << " " << n->info.number << endl;
    printInOrder(n->right);
}
//
CardBST::Node* CardBST::getMaxNode(Node *n) const{ 
    Node *current = n;
    while(current->right){
        current = current->right;
    }
    return current;
}
Card CardBST::getMax() const{
    return getMaxNode(root)->info;
}

CardBST::Node* CardBST::getMinNode(Node *n) const{ 
    Node *current = n;
    while(current->left){
        current = current->left;
    }
    return current;
}
Card CardBST::getMin() const{
    return getMinNode(root)->info;
}

// returns the Node containing the predecessor of the given value
CardBST::Node* CardBST::getPredecessorNode(Card value) const{ 
    // Node *current = root;
    // Node *predecessor = NULL;
    
    // if (contains(value)){
    // while (current != NULL) {
    //     if (current->info < value) {
    //         predecessor = current;
    //         current = current->right;
    //     }
    //     else {
    //         current = current->left;
    //     }
    // }
   
    // return predecessor; 
    // }
    // else return NULL;

Node* n = getNodeFor(value, root);

if (n == nullptr) {
return NULL; //value not in tree
}

if (n->left != nullptr) {
//if left subtree, predecessor is rightmost node in subtree
n = n->left;
while (n->right != nullptr) {
n = n->right;
}
return n;
}

//if no left subtree, return first ancestor that is right child
Node* par = n->parent;
while (par != nullptr && n == par->left) {
n = par;
par = par->parent;
}

if (par == nullptr) {
return nullptr; 
} else {
return par;
}
}

// returns the predecessor value of the given value or 0 if there is none
Card CardBST::getPredecessor(Card value) const{
    if (getPredecessorNode(value) == NULL) return Card('\0',"");
    else return getPredecessorNode(value)->info;
}

// returns the Node containing the successor of the given value
CardBST::Node* CardBST::getSuccessorNode(Card value) const{
    // Node *current = root;
    // Node *successor = NULL;

    // if (contains(value)){

    // while (current != NULL) {
    //     if (current->info > value) {
    //         successor = current;
    //         current = current->left;
    //     }
    //     else {
    //         current = current->right;
    //     }
    // }

    // return successor;

    // }
    // else return NULL;

Node* n = getNodeFor(value, root);

if (n == nullptr) {
return NULL; // value not found in tree
}

if (n->right != nullptr) {
// if there is a right subtree, successor is leftmost node in the subtree
n = n->right;
while (n->left != nullptr) {
n = n->left;
}
return n;
}

// if there is no right subtree, find first ancestor that is a left child
Node* par = n->parent;
while (par != nullptr && n == par->right) {
n = par;
par = par->parent;
}

if (par == nullptr) {
return nullptr; // current node was the maximum value in the tree
} else {
return par;
}
}

// returns the successor value of the given value or 0 if there is none
Card CardBST::getSuccessor(Card value) const{
    if (getSuccessorNode(value) == NULL) return Card('\0',"");
    else return getSuccessorNode(value)->info;
}

CardBST::Node* CardBST::getRootNode() const {
    return root;
}
Card CardBST::getRoot() const{
    if (getRootNode() == NULL) return Card('\0',"");
    return getRootNode()->info;
}
// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool CardBST::remove(Card value) {
    // First, find the node containing the value to be removed
    Node* nodeToRemove = getNodeFor(value, root);
    if (nodeToRemove == NULL) {
        // The value is not in the tree, return false
        return false;
    }

    // If the node has no children, simply remove it
    if (nodeToRemove->left == NULL && nodeToRemove->right == NULL) {
        if (nodeToRemove->parent == NULL){
            root = NULL;
        }
        else if (nodeToRemove->parent->left == nodeToRemove) {
            nodeToRemove->parent->left = NULL;
        } 
        else if (nodeToRemove->parent->right == nodeToRemove) {
            nodeToRemove->parent->right = NULL;
        }
        delete nodeToRemove;
        return true;
    }

    // If the node has one child, remove it and replace it with its child
    if (nodeToRemove->left == NULL || nodeToRemove->right == NULL) {
        Node* child = (nodeToRemove->left == NULL) ? nodeToRemove->right : nodeToRemove->left;
        if (nodeToRemove->parent == NULL){
            root = child;
        }
        else if (nodeToRemove->parent->left == nodeToRemove) {
            nodeToRemove->parent->left = child;
        } 
        else if (nodeToRemove->parent->right == nodeToRemove){
            nodeToRemove->parent->right = child;
        }
        child->parent = nodeToRemove->parent;
        delete nodeToRemove;
        return true;
    }

    // If the node has two children, find its predecessor and copy the predecessor data into the node, and then delete the predecessor
    Node* predecessor = getPredecessorNode(nodeToRemove->info);
    Card temp = predecessor->info;
    remove(predecessor->info);
    nodeToRemove->info = temp;
    return true;
    // if (predecessor->parent->left == predecessor) {
    //     predecessor->parent->left = NULL;
    // } 
    // else if (predecessor->parent->right == predecessor) {
    //     predecessor->parent->right = NULL;
    // }
    // delete predecessor;
    // return true;
}