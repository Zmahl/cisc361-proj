#include "process.h"
#include <iostream>
using namespace std;

Process::Process(Job* job){
	job = job;
	alloc_devs = 0;
}
Job* Process::get_job(){
	return job;
}
int Process::get_alloc_devs(){
	return alloc_devs;
}
void Process::add_alloc_devs(int d){
	alloc_devs += d;
}
void Process::take_alloc_devs(int d){
	alloc_devs -= d;
}
