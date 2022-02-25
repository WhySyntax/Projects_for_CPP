#include "BNode.h"
#include "LNode.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include "patterns.hpp"
using namespace std;
using namespace mpark::patterns;

void shuntInput(LNode<char>* &output, char parser);
LNode<char>* pop(LNode<char>* n);
//will usually use append method as its simpler and gives problems less often
void push(LNode<char>* n, LNode<char>* p);
char peek(LNode<char>* n);
//enqueue
void backAdd();
//dequeue
void frontRemove();
void printr(LNode<char>* n);
bool isHigher(char a, char b);

const bool testing = true;

int main() {
  LNode<char>* output = NULL;
  cout << "input equation:\n";
  char parser;
  cin.get(parser);
  shuntInput(output, parser);
  printr(output);
  cout << "AAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHH";
  return 0;
}

void shuntInput(LNode<char>* &output, char parser) {
  LNode<char>* ops = NULL;
  while (parser != 0 && parser != 10 && parser != '\n' && parser != '\0' && parser != ')') {
    if (testing)
      cout << parser << endl;
    if (parser == '(') {
      cin.get(parser);
      shuntInput(output,parser);
    } else if (parser >= '0' && parser <= '9') {
      if (output != NULL) {
	output->append(new LNode(parser));
      } else {
	output = new LNode<char>(parser);
      }
    } else if (parser != ' ') {
      if (ops != NULL) {
	if (isHigher(peek(ops),parser)) {
	  output->append(ops->getLast());
	  ops = pop(ops);
	}
	if (ops!=NULL) {
	  ops->append(parser);
	} else {
	  ops = new LNode(parser);
	}
      } else {
	ops = new LNode(parser);
      }
    }
    cin.get(parser);
  }
  printr(ops);
  while (ops!=NULL) {
    output->append(ops->getLast());
    ops = pop(ops);
  }
  if (testing) {
    printr(output);
  }
}

LNode<char>* pop(LNode<char>* n) {
  if ((n==NULL)||(n->getNext()==NULL)) {return NULL;}
  n->setNext(pop(n->getNext()));
  return n;
}

void push(LNode<char>* n, LNode<char>* p) {
  n->append(p);
}

char peek(LNode<char>* n) {
  return n->getLast()->getValue();
}

void printr(LNode<char>* n) {
  if (n==NULL) {
    cout << "passed NULL Node\n";
    return;
  }
  char a = n->getValue();
  cout << a;
  if (n->getNext()==NULL) {
    cout << endl;
  } else {
    cout << ' ';
    printr(n->getNext());
  }
}

bool isHigher(char a, char b) {
  if ((a == b) && (a != '^')) {
    return true;
  }
  if ((a == '^') && (b != '^')) {
    return true;
  }
  if (((a == '*') || (a == '/')) && (b != '^')) {
    return true;
  }
  if (((a == '+') || (a == '-')) && ((b == '+') || (b == '-'))) {
    return true;
  }
  return false;    
}
    