#include "job.h"

class Process{
private:
	Job* job;
	int alloc_devs;
public:
	Process(Job* j);
	Job* get_job();
	int get_alloc_devs();
	void add_alloc_devs(int d);
	void take_alloc_devs(int d);
};
