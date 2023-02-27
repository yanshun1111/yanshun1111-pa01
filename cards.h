// cards.h
// Author: Shun Ysan
// All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>

using namespace std;


struct Card{
    char face;
	string number;
    int faceidx;
    int numberidx;
    Card(char face = '\0', string number = "") : face(face), number(number){
    if (face == 'c'){faceidx = 0;}
    else if (face == 'd'){faceidx = 1;}
    else if (face == 's'){faceidx = 2;}
    else if (face == 'h'){faceidx = 3;}

    if (number == "a"){numberidx = 1;}
    else if (number == "2"){numberidx = 2;}
    else if (number == "3"){numberidx = 3;}
    else if (number == "4"){numberidx = 4;}
    else if (number == "5"){numberidx = 5;}
    else if (number == "6"){numberidx = 6;}
    else if (number == "7"){numberidx = 7;}
    else if (number == "8"){numberidx = 8;}
    else if (number == "9"){numberidx = 9;}
    else if (number == "10"){numberidx = 10;}
    else if (number == "j"){numberidx = 11;}
    else if (number == "q"){numberidx = 12;}
    else if (number == "k"){numberidx = 13;}
    }

    // Card(char f, string n) : face(f), number(n) { }

    bool operator==(Card const& o) const{
        return (face == o.face && number == o.number);
    }

    bool operator<(Card const& o) const {


        if (faceidx < o.faceidx){
        return true;
        }
        if (faceidx == o.faceidx){
        if (numberidx <= o.numberidx){
        return true;
        }
        }
        return false;
        

        // if (face == 'c' && o.face != 'c') {
        //     return true;
        // } else if (face == 'd' && (o.face == 's' || o.face == 'h')) {
        //     return true;
        // } else if (face == 's' && o.face == 'h') {
        //     return true;
        // } else if (face == o.face) {
        //     if (number == "a") {
        //         return true;
        //     } else if (o.number == "a") {
        //         return false;
        //     } else if (number == "k") {
        //         return o.number != "a" && o.number != "10";
        //     } else if (o.number == "k") {
        //         return true;
        //     } else if (number == "q") {
        //         return o.number != "a" && o.number != "10" && o.number != "k";
        //     } else if (o.number == "q") {
        //         return true;
        //     } else if (number == "j") {
        //         return o.number == "10";
        //     } else if (o.number == "j") {
        //         return true;
        //     } else {
        //         return stoi(number) < stoi(o.number);
        //     }
        // } else {
        //     return false;
        // }
    }
    bool operator>(Card const& o) const {
        return o < *this;
    }

};

class CardBST {

 public:
    // ctor, dtor, insert and one print method already done in intbst.cpp:
    CardBST();                   // constructor
    ~CardBST();                  // destructor
    bool insert(Card value);     // insert value; return false if duplicate
    bool contains(Card value) const;  // true if value is in tree

    void printInOrder() const;       // print tree data in-order to cout
    // THESE ARE HARDER! DO THESE LAST
    Card getPredecessor(Card value) const;       // returns the predecessor value of the given value or 0 if there is none
    Card getSuccessor(Card value) const;         // returns the successor value of the given value or 0 if there is none
    Card getMin() const;
    Card getMax() const;
    bool remove(Card value);                    // deletes the Node containing the given value from the tree
    Card getRoot() const;

 private:

    struct Node {
	Card info;
	Node *left, *right, *parent;
	// useful constructor:
    Node(Card value) : info(value.face, value.number), left(0), right(0), parent(0) { }
    };
    
    // just one instance variable (pointer to root node):
    Node *root;

    void printInOrder(Node *n) const;
    // recursive utility functions for use by public methods above
    Node* getNodeFor(Card value, Node* n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
    void clear(Node *n); // for destructor
    bool insert(Card value, Node *n); // note overloading names for simplicity
    // these should be used by getPredecessor and getSuccessor, and ONE of them should be used by remove
    Node* getSuccessorNode(Card value) const;   // returns the Node containing the successor of the given value
    Node* getPredecessorNode(Card value) const; // returns the Node containing the predecessor of the given value 
    Node* getRootNode() const;
    Node* getMinNode(Node *n) const;
    Node* getMaxNode(Node *n) const;
};
#endif