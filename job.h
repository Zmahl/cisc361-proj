class Job{
private:
	int jobnum;
	int memory;
	int priority;
	int arrtime;
	int runtime;
	int devices;
public:
	Job(int j, int m, int p, int a, int r, int d);
	int get_jobnum();
	int get_memory();
	int get_priority();
	int get_arrtime();
	int get_runtime();
	int get_devices();
};
