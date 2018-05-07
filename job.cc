using namespace std;

class Job{
public:

	Job(int j, int m, int s,int p, int a, int r, int q, int d){
		jobnum = j;
		memory = m;
		priority = p;
		arrtime = a;
		runtime = r;
		quantum = q;
		demand = d;
	}

	int get_jobnum(){
		return jobnum;
	}
	int get_memory(){
		return memory;
	}
	int get_priority(){
		return priority;
	}
	int get_arrtime(){
		return arrtime;
	}
	int get_runtime(){
		return runtime;
	}
	int get_quantum(){
		return quantum;
	}
	int get_demand(){
		return demand;
	}

private:
	int jobnum;
	int memory;
	int serial;
	int priority;
	int arrtime;
	int runtime;
	int quantum;
	int demand;
};

