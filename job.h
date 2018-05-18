class Job{
private:
	int jobnum;
	int memory;
	int serial;
	int priority;
	int runtime;
	int devices;
	int location;
public:
	Job(int j, int m, int s,int p, int a, int r, int q, int d, int l);
	int get_jobnum();
	int get_memory();
	int get_priority();
	int get_runtime();
	int get_devices();
	int get_location();
};
