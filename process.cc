#include "process.h"
#include <iostream>
using namespace std;

Process::Process(Job* job){
	job = job;
	alloc_devs = 0;
	req_devs = 0;
	req_met = false;
}
Job* Process::get_job(){
	return job;
}
int Process::get_alloc_devs(){
	return alloc_devs;
}
int Process::get_req_devs(){
	return req_devs;
}
bool Process::get_req_met(){
	return req_met;
}
void Process::set_req_met(bool b){
	req_met = b;
}
void Process::add_alloc_devs(int d){
	alloc_devs += d;
}
void Process::take_alloc_devs(int d){
	alloc_devs -= d;
}
void Process::add_req_devs(int r){
	req_devs += r;
}
void Process::take_req_devs(int r){
	req_devs -= r;
}
