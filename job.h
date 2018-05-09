class Job{
private:
	int jobnum;
	int memory;
	int serial;
	int priority;
	int arrtime;
	int runtime;
	int demand;
public:
	Job(int j, int m, int s,int p, int a, int r, int q, int d);
	int get_jobnum();
	int get_memory();
	int get_priority();
	int get_arrtime();
	int get_runtime();
	int get_demand();
};
