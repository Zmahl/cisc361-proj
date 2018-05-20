#include "job.h"

class Process{
private:
	Job* job;
	int alloc_devs;
	int req_devs;
	bool req_met;
public:
	Process(Job* j);
	Job* get_job();
	int get_alloc_devs();
	int get_req_devs();
	bool get_req_met();
	void set_req_met(bool b);
	void add_alloc_devs(int d);
	void take_alloc_devs(int d);
	void add_req_devs(int r);
	void take_req_devs(int r);
};
