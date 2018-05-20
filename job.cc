#include "job.h"
#include <iostream>
using namespace std;

Job::Job(int j, int m, int p, int a, int r, int d){
	jobnum = j;
	memory = m;
	priority = p;
	arrtime = a;
	runtime = r;
	devices = d;
}
int Job::get_jobnum(){
	return jobnum;
}
int Job::get_memory(){
	return memory;
}
int Job::get_priority(){
	return priority;
}
int Job::get_arrtime(){
	return arrtime;
}
int Job::get_runtime(){
	return runtime;
}
int Job::get_devices(){
	return devices;
}
