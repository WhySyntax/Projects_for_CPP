#include <utility>
#include <vector>

#ifndef GNODE_H
#define GNODE_H

template <class T>
class LNode {
 public:
  //these two are too simple, literally just give you the pointers to the corresponding values btw get certain is 0-indexing
  T getValue();
  LNode<T>* getNext();
  LNode<T>* getLast();
  int getLength();
  LNode<T>* getCertain(int pos);
  //appends a LNode to end of linked listsets stuff, or appends to end of linked list
  void setNext(LNode<T>* n);
  void setValue(T n);
  void append(LNode<T>* n);
  void append(T n);

  //initilizes LNodes with corresponding values
  LNode();
  LNode(T v);
  LNode(LNode<T>* n);
  LNode(T v, LNode<T>* n);
  ~LNode();
 private:
  T val;
  LNode<T>* next;
};

struct GNode {
  char name[20];
  std::vector<std::pair<GNode*, int>> connections;
};

class graph {
public:
  //hashmap of nodes
  LNode<GNode*>* nodes[20];
  
  std::vector<GNode*> listNodes();
  void addNode(char* a);
  void addVertex();
  void printTable();
  void printPath(GNode* a, GNode* b);
  int getHash(char* w);
  GNode* getNode(char* n);
  
  graph();
  ~graph();
};

#endif
