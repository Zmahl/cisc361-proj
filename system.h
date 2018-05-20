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
	void set_time(int t);
	void add_hq1(Job* job);
	void add_hq2(Job* job);
	void add_rq(Process* pro);
	void add_wq(Process* pro);
	void add_cq(Process* pro);
	bool bankers(Process* pro, int devs);

	std::list<Job*> *hq1;
	std::list<Job*> *hq2;
	std::list<Process*> *rq;
	std::list<Process*> *wq;
	std::list<Process*> *cpu;
	std::list<Process*> *cq;
};
