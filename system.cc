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

	this->sq = new std::list<Job*>();
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
	int elapsed = t - this->time;
	int adv_time;

	if (elapsed < this->quantum){
		this->time = t;
	}else if (elapsed == this->quantum){
		adv_time = advance();
		this->time += adv_time;
	}else{
		while (elapsed > 0){
			adv_time = advance();
			elapsed -= adv_time;
		}
		this->time = elapsed;
	}
}

int System::advance(){
	int ret;
	bool released;
	if (!(this->cpu->empty())){
		list<Process*>:: iterator j = this->cpu->begin();
		int time_left = (*j)->get_job()->get_runtime()- (*j)->get_job()->get_rantime();
		if (time_left <= this->quantum){
			ret = time_left;
			(*j)->get_job()->set_rantime((*j)->get_job()->get_runtime());
			this->add_avail_mem((*j)->get_job()->get_memory());
			this->add_avail_devs((*j)->get_job()->get_devices());
			this->cq->push_back(this->cpu->front());
			this->cpu->pop_front();
			released = true;
		}else{
			(*j)->get_job()->set_rantime((*j)->get_job()->get_rantime() + this->quantum);
			this->rq->push_back(this->cpu->front());
			this->cpu->pop_front();
		}
	}
	if (!(this->sq->empty())){
		list<Job*>:: iterator s;
		cout << "INSIDE IF" << endl;
		for (s = this->sq->begin(); s != this->sq->end(); ++s){
			cout << (*s) << endl;
			cout << "IN THE FOR LOOP" << endl;
			if ((*s)->get_priority() == 1){
				cout << "IF beginning" << endl;
				this->add_hq1(this->sq->front());
				this->sq->pop_front();
				cout << "IF end" << endl;
			}else if ((*s)->get_priority() == 2){
				cout << "ELSE IF beginning" << endl;
				this->add_hq2(this->sq->front());
				this->sq->pop_front();
				cout << "ELSE OF end" << endl;
			}
		}
	}
	if (released){
		if (!(this->wq->empty())){
			list<Process*>:: iterator w = this->wq->begin();
			if (bankers((*w), (*w)->get_req_devs()))
				this->rq->push_back(this->wq->front());
				this->wq->pop_front();
		}if (!(this->hq1->empty())){
			list<Job*>:: iterator h;
			for(h = this->hq1->begin(); h != this->hq1->end(); ++h){
				if ((*h)->get_memory() <= this->get_avail_mem() && (*h)->get_devices() <= this->get_total_devs()){
					Process* new_process = new Process(*h);
					this->take_avail_mem(new_process->get_job()->get_memory());
					this->add_rq(new_process);
				}
			}
		}if (!(this->hq2->empty())){
			list<Job*>:: iterator h2;
			for(h2 = this->hq2->begin(); h2 != this->hq2->end(); ++h2){
				if ((*h2)->get_memory() <= this->get_avail_mem() && (*h2)->get_devices() <= this->get_total_devs()){
					Process* new_process = new Process(*h2);
					this->take_avail_mem(new_process->get_job()->get_memory());
					this->add_rq(new_process);
				}
			}
		}
	}


	return ret;
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

void System::add_sq(Job* job){
	this->sq->push_back(job);
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

bool System::bankers(Process* pro, int devs){
	int bavail_devs = this->get_avail_devs();

	bavail_devs -= devs;
	int favail_devs = bavail_devs;

	while(bavail_devs != favail_devs){
		bavail_devs = favail_devs;

		list<Process*>:: iterator i;
		for (i = this->rq->begin(); i != this->rq->end(); ++i){
			int needed_devs = (*i)->get_job()->get_devices() - (*i)->get_alloc_devs();
			if(needed_devs < favail_devs){
				(*i)->set_req_met(true);
				favail_devs += (*i)->get_alloc_devs();
			}
		}
	}

	bool ret = true;

	list<Process*>:: iterator it;
	for (it = this->rq->begin(); it != this->rq->end(); ++it){
		ret = ret && (*it)->get_req_met();
		(*it)->set_req_met(false);
	}

	return ret;
}


