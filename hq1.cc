#include "job.h"
#include <iostream>
using namespace std;


class Hq1 {

private:
	class Node {
	public:
		Job j;
		Node(Job j, Node* n=NULL{ j(j), next(n){}
		Node * next;
	};

	Node * head;

public:
	Hq1() { head = NULL; }

	boolean isEmpty();

	void insert(Job j);

	void print();
};

boolean Hq1::isEmpty(){
	return (head == NULL);
}

void Hq1::insert(Job j){
	Node* temp = head;
	if (head != NULL && (*(*head).j).runtime < j.runtime){
		while((*temp).next != NULL){
			if ((*(*temp).next).data < j.runtime)
				temp = (*temp).next;
			else
				break;
		}
	(*temp).next = new Node(j, (*temp).next);
	}
	else
		head = new Node(j, head);
}

void Hq1:: print(){
	if (head != NULL){
		Node* temp = head;
		while (temp != NULL){
        		cout << (*temp).j.runtime << " ";
        		temp = (*temp).next;
      		}
	}
	cout << endl;
}

int main(){
	Hq1 h = new Hq1();

	Job j1 = new Job(1, 0, 1, 0, 5, 0, 0);
	Job j2 = new Job(2, 0, 1, 0, 8, 0, 0);
	Job j3 = new Job(3, 0, 1, 0, 1, 0, 0);

	h.print();
	h.insert(j1);
	h.print();
	h.insert(j2);
	h.print();
	h.insert(j3);
	h.print();

}
