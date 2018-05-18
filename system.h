class System{
private:
	int total_mem;
	int avail_mem;
	int total_devs;
	int avail_devs;
	int quantum;
public:
	Job(int tm, int am, int td, int ad, int q);
	int get_total_mem();
	int get_avail_mem();
	int get_total_devs();
	int get_avail_devs();
	int get_quantum();
};
