#include "job.h"
#include <iostream>
using namespace std;

Job::Job(int j, int m, int s,int p, int r, int q, int d, int l){
	jobnum = j;
	memory = m;
	priority = p;
	runtime = r;
	devices = d;
	location = l;
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
int Job::get_runtime(){
	return runtime;
}
int Job::get_devices(){
	return devices;
}
int Job::get_location(){
	return location;
}
