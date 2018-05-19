#include "system.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

System::System(int tm, int td, int q, int t){
	this->total_mem = tm;
	this->avail_mem = tm;
	this->total_devs = td;
	this->avail_devs = td;
	this->quantum = q;
	this->time = t;

	this->hq1 = new std::list<Job*>();
	this->hq2 = new std::list<Job*>();
	this->rq = new std::list<Process*>();
	this->wq = new std::list<Process*>();
	this->cpu = new std::list<Process*>();
	this->cq = new std::list<Process*>();
}
int System::get_total_mem(){
	return this->total_mem;
}
int System::get_avail_mem(){
	return this->avail_mem;
}
int System::get_total_devs(){
	return this->total_devs;
}
int System::get_avail_devs(){
	return this->avail_devs;
}
int System::get_quantum(){
	return this->quantum;
}
int System::get_time(){
	return this->time;
}
void System::add_avail_mem(int m){
	this->avail_mem = this->avail_mem + m;
}
void System::take_avail_mem(int m){
	this->avail_mem = this->avail_mem - m;
}
void System::add_avail_devs(int d){
	this->avail_devs = this->avail_devs + d;
}
void System::take_avail_devs(int d){
	this->avail_devs = this->avail_devs - d;
}
void System::set_time(int t){
	this->time = t;
}

bool hq1_sort(Job* j1, Job* j2){
	if (j1->get_runtime() == j2->get_runtime()){
		return j1->get_arrtime() < j2->get_arrtime();
	}
	else{
		return j1->get_runtime() < j2->get_runtime();
	}
}

bool hq2_sort(Job* j1, Job* j2){
	return j1->get_arrtime() < j2->get_arrtime();
}

void System::add_hq1(Job* job){
	this->hq1->push_back(job);
	this->hq1->sort(hq1_sort);
}
void System::add_hq2(Job* job){
	this->hq2->push_back(job);
	this->hq2->sort(hq2_sort);
}
void System::add_rq(Process* pro){
	this->rq->push_back(pro);
}
void System::add_wq(Process* pro){
	this->wq->push_back(pro);
}
void System::add_cq(Process* pro){
	this->cq->push_back(pro);
}
