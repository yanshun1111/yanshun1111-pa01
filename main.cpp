#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;
 
  CardBST Bob;
  CardBST Alice;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
      char face = line.at(0);
      string number = line.substr(2);
      Card newcard = Card(face, number);
      Alice.insert(newcard);  
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
      char face = line.at(0);
      string number = line.substr(2);
      Card newcard = Card(face, number);
      Bob.insert(newcard); 
  }
  cardFile2.close();

Card check('\0',"");

cout << "Starting the game" << endl;

while (!(Alice.getRoot() == check) || !(Bob.getRoot() == check)){

  Card t = Alice.getMin();
  while(Alice.contains(t)){
    if (Bob.contains(t)){
      cout << "Alice picked matching card " << t.face << " " << t.number << endl;
      Alice.remove(t);
      Bob.remove(t);
      break;
    }
    t = Alice.getSuccessor(t);
  }

  Card c = Bob.getMax();
  while(Bob.contains(c)){
    if (Alice.contains(c)){
      cout << "Bob picked matching card " << c.face << " " << c.number << endl;
      Bob.remove(c);
      Alice.remove(c);
      break;
    }
    c = Bob.getPredecessor(c);
  }

  if ((t == check) || (c == check)) break;
  
}

cout << endl;

cout << "Alice's cards:" << endl;

Alice.printInOrder();

cout << endl;

cout << "Bob's cards:" << endl;

Bob.printInOrder();

cout << endl;
return 0;
}
