#include <list>
#include "process.h"

class System{
private:
	int time;
	int total_mem;
	int avail_mem;
	int total_devs;
	int avail_devs;
	int quantum;

	std::list<Job*> *hq1;
	std::list<Job*> *hq2;
	std::list<Process*> *rq;
	std::list<Process*> *wq;
	std::list<Process*> *cpu;
	std::list<Process*> *cq;
public:
	System(int tm, int td, int q, int t);
	int get_total_mem();
	int get_avail_mem();
	int get_total_devs();
	int get_avail_devs();
	int get_quantum();
	int get_time();
	void add_avail_mem(int m);
	void take_avail_mem(int m);
	void add_avail_devs(int d);
	void take_avail_devs(int d);
	void add_time(int t);
};
