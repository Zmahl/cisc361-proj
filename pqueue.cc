#include <iostream>
#include "job.h"

using namespace std;

class PQueue{
public:
  class Tree{
  public:
    class Node{
    public:
      Job* job;
      Node* left;
      Node* right;

      //Ctor
      Node(, Node* l=NULL, Node* r=NULL){
        data = input;
        left = l;
        right = r;
      }

      //Dtor
      ~Node(){
        if (data != NULL){
          delete data;
        }
      }

      //Copy Ctor
      Node(const Node &obj){
        char* dat = new char[strlen(obj.data)];
        strcpy(dat, obj.data);
        data = dat;
        delete dat;
      }

      //Assignment
      Node& operator=(const Node &obj){
        if (this != &obj){
          delete[] data;
          char* dat = new char;
          *dat = *obj.data;
          data = dat;
          delete dat;
          return *this;
        }
        else
          return *this;
      }
    };

    Node* root;
    int depth;

    //Ctor
    Tree(){
      root = NULL;
      depth = 0;
    }

    //Dtor
    ~Tree(){
      if (root != NULL){
        deleteNode(root->left);
        deleteNode(root->right);
        delete root;
      }
    }

    //Recursive Dtor
    void deleteNode(Node* root){
      if (root != NULL){
        deleteNode(root->left);
        deleteNode(root->right);
      }
    }

    //Copy Ctor
    Tree(const Tree &obj){
      copy(root, obj.root);
    }

    //Recursive Copy Helper
    void copy(Node* n1, Node* n2){
      if (n1 != NULL)
        delete n1;
      n1 = n2;
      if (n2->left != NULL)
        copy(n1->left, n2->left);
      if (n2->right != NULL)
        copy(n1->right, n2->right);
    }

    //Assignment
    Tree& operator=(const Tree &obj){
      if (this != &obj)
        copy(root, obj.root);
      return *this;
    }

    //Dummy Insert
    void insert(char* c){
      if (root == NULL)
        root = new Node(c);
      else
        insert(c, root);
      depth = maxDepth();
    }

    //Recursive Insert
    void insert(char* c, Node* root){
      Node* temp = root;
      if(strcmp(c,(*temp).data) < 0){
        if((*temp).left == NULL)
          (*temp).left = new Node(c);
        else
          insert(c, (*temp).left);
      }
      else{
        if((*temp).right == NULL)
          (*temp).right = new Node(c);
        else
          insert(c, (*temp).right);
      }
    }

    //Dummy Tree Print
    void treePrint(){
  		print(root, 0, 6);
  	}

    //Recursive Tree Print
  	void print(Node* root, int spaces, int spaceCount){
  		if (root != NULL){
  			print((*root).right, spaces+spaceCount, spaceCount);

  			for (int i = 0; i < spaces; i++)
  				cout << " ";
        cout << (*root).data << endl;

  			print((*root).left, spaces+spaceCount, spaceCount);
  		}
  	}

    //Dummy Depth
    int maxDepth(){
      return maxDepth(root, 1);
    }

   //Recursive Depth
    int maxDepth(Node* root, int depth){
  		if (root != NULL){
  			int depth1 = maxDepth((*root).left, depth+1);
  			int depth2 = maxDepth((*root).right, depth+1);
  			if (depth1 > depth2)
  				return(depth1);
  			else
  				return(depth2);
  		}
  		else
  			return(depth-1);
  	}

    //Is Empty
    bool isEmpty(){
      return (root == NULL);
    }

    //Dummy Delete Max
    char* deleteMax(){
      return(deleteMax(root));
    }

    //Recursive Delete Max
    char* deleteMax(Node* head){
      char* tempDat;
      if (head->right != NULL){
        if(head->right->right == NULL){
          Node* temp = head->right;
          head->right = temp->left;
          tempDat = new char[strlen(temp->data)];
          strcpy(tempDat, temp->data);
          return tempDat;
        }
        else{
          return(deleteMax(head->right));
        }
      }
      else{
        root = head->left;
        tempDat = new char[strlen(head->data)];
        strcpy(tempDat, head->data);
        return tempDat;
      }
    }
  };

  Tree* tree;

  //Ctor
  PQueue(){tree = new Tree;}

  //Dtor
  ~PQueue(){delete tree;}

  //Copy Ctor
  PQueue(const PQueue &obj){
    Tree* newTree;
    newTree = obj.tree;
    tree = newTree;
    delete newTree;
  }

  //Assignment
  PQueue& operator=(const PQueue &obj){
    if (this != &obj){
      delete tree;
      Tree* newTree;
      newTree = obj.tree;
      tree = newTree;
      delete newTree;
      return *this;
    }
  }

  //Push
  void push(char* c){
    tree->insert(c);
  }

  //Pop
  char* pop(){
    return tree->deleteMax();
  }

  //Is Empty
  bool isEmpty(){
    return tree->isEmpty();
  }

};

int main(){

  //Initializing PQueue
  PQueue* pq = new PQueue();

  //Initializing chars for PQueue
  char* a = new char[9];
  a = "aardvark";
  char* b = new char[9];
  b = "benjamin";
  char* c = new char[5];
  c = "crap";
  char* d = new char[7];
  d = "donkey";
  char* e = new char[9];
  e = "elephant";

  //Pushing chars into PQueue
  pq->push(b);
  pq->push(a);
  pq->push(d);
  pq->push(c);
  pq->push(e);

  //Printing popping
  cout << "IS EMPTY?: " << pq->isEmpty() << endl;

  pq->tree->treePrint();

  cout << "WHAT DID I POP: " << pq->pop() << endl;

  pq->tree->treePrint();

  cout << "WHAT DID I POP: " << pq->pop() << endl;

  pq->tree->treePrint();

  cout << "WHAT DID I POP: " << pq->pop() << endl;

  pq->tree->treePrint();

  cout << "WHAT DID I POP: " << pq->pop() << endl;

  pq->tree->treePrint();

  cout << "WHAT DID I POP: " << pq->pop() << endl;
  cout << "IS EMPTY?: " << pq->isEmpty() << endl;
}
