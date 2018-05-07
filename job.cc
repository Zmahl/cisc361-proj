using namespace std;

class Job (

private:
	int jobnum;
	int memory;
	int serial;
	int priority;
	int arrtime;
	int runtime;
	int quantum;
	int demand;
public:

	Job(int j, int m, int s,int p, int a, int r, int q, int d){
		this->jobnum = j;
		this->memory = m;
		this->priority = p;
		this->arrtime = a;
		this->runtime = r;
		this->quantum = q;
		this->demand = d;
	}

	int get_jobnum(){
		return this->jobnum;
	}
	int get_memory(){
		return this->memory;
	}
	int get_priority(){
		return this->priority;
	}
	int get_arrtime(){
		return this->arrtime;
	}
	int get_runtime(){
		return this->runtime;
	}
	int get_quantum(){
		return this->quantum;
	}
	int get_demand(){
		return this->demand;
	}
};

