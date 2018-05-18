#include "job.h"
#include <iostream>
using namespace std;

class Hq1 {

private:
	class Node {
	public:
		Job j;
		Node(Job::Job j, Node* n=NULL);
		Node * next;
 	 };

	Node * head;

public:
	Hq1() { head = NULL; }

	bool isEmpty();

	void insert(Job j);

	void print();
};
