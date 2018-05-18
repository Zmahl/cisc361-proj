#include "system.h"
#include <iostream>
using namespace std;

System::System(int tm, int am, int td, int ad, int q){
	total_mem = tm;
	avail_mem = am;
	total_devs = td;
	avail_devs = am;
	quantum = q;
}
int System::get_total_mem(){
	return total_mem;
}
int System::get_avail_mem(){
	return avail_mem;
}
int System::get_total_devs(){
	return total_devs;
}
int System::get_avail_devs(){
	return avail_devs;
}
int System::get_quantum(){
	return quantum;
}
