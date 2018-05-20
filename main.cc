#include "system.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

System* make_system(string line);
Job* make_job(string line);

int main(){
	string line;
	string input;
	System* system;
	ifstream my_file ("test.txt");

	if (my_file.is_open()){
		getline(my_file, line);
		system = make_system(line);
		while(true){
			getline(my_file, line);
			if (line[0] == 'A'){
				Job* new_job = make_job(line);
				if (new_job->get_memory() < system->get_total_mem() && new_job->get_devices() < system->get_total_devs()){
					system->add_sq(new_job);
				}
			}else if (line[0] == 'Q'){
				vector<string> array;
				std::size_t pos = 0, found;
				while((found = line.find_first_of(' ', pos)) != std::string::npos){
					array.push_back(line.substr(pos, found-pos));
					pos = found+1;
				}
				array.push_back(line.substr(pos));

				vector<string>:: iterator i;
				int y = 0;
				int arrtime;
				int job_num;
				int devs;
				for(i = array.begin(); i!=array.end(); ++i){
					if (y == 1){
						istringstream buffer(*i);
						buffer >> arrtime;
					}else if (y == 2){
						istringstream buffer((*i).substr(2));
						buffer >> job_num;
					}else if (y ==3){
						istringstream buffer((*i).substr(2));
						buffer >> devs;
					}
					y++;
				}
				list<Process*>:: iterator j = system->cpu->begin();
				system->set_time(arrtime);
				if (job_num == (*j)->get_job()->get_jobnum()){
					if (system->bankers((*j), devs)){
						(*j)->add_alloc_devs(devs);
						system->take_avail_devs(devs);
						system->rq->push_back(system->cpu->front());
						system->cpu->pop_front();
					}else{
						(*j)->add_req_devs(devs);
						system->wq->push_back(system->cpu->front());
						system->cpu->pop_front();
					}
					system->advance();
				}
			}else if(line[0] == 'L'){
				vector<string> array;
				std::size_t pos = 0, found;
				while((found = line.find_first_of(' ', pos)) != std::string::npos){
					array.push_back(line.substr(pos, found-pos));
					pos = found+1;
				}
				array.push_back(line.substr(pos));

				vector<string>:: iterator i;
				int y = 0;
				int arrtime;
				int job_num;
				int devs;
				for(i = array.begin(); i!=array.end(); ++i){
					if (y == 1){
						istringstream buffer(*i);
						buffer >> arrtime;
					}else if (y == 2){
						istringstream buffer((*i).substr(2));
						buffer >> job_num;
					}else if (y ==3){
						istringstream buffer((*i).substr(2));
						buffer >> devs;
					}
					y++;
				}
				list<Process*>:: iterator j = system->cpu->begin();
				if (job_num == (*j)->get_job()->get_jobnum()){
					system->set_time(arrtime);
					system->add_avail_devs(devs);
				}
			}

		}
	}else{
		cout << "no file" << endl;
	}
}

System* make_system(string line){
	cout << line << endl;

	vector<string> array;
	std::size_t pos = 0, found;
	while((found = line.find_first_of(' ', pos)) != std::string::npos){
		array.push_back(line.substr(pos, found-pos));
		pos = found+1;
	}
	array.push_back(line.substr(pos));

	vector<string>:: iterator i;
	int y = 0;
	int time;
	int mem;
	int devs;
	int q;
	for(i = array.begin(); i!=array.end(); ++i){
		if (y == 1){
			istringstream buffer(*i);
			buffer >> time;
		}else if (y == 2){
			istringstream buffer((*i).substr(2));
			buffer >> mem;
		}else if (y ==3){
			istringstream buffer((*i).substr(2));
			buffer >> devs;
		}else if (y == 4){
			istringstream buffer((*i).substr(2));
			buffer >> q;
		}
		y++;
	}

	System* system = new System(mem, devs, q, time);
	return system;
}

Job* make_job(string line){
	cout << line << endl;

	vector<string> array;
	std::size_t pos = 0, found;
	while((found = line.find_first_of(' ', pos)) != std::string::npos){
		array.push_back(line.substr(pos, found-pos));
		pos = found+1;
	}
	array.push_back(line.substr(pos));

	vector<string>:: iterator i;
	int y = 0;
	int jobnum;
	int mem;
	int devs;
	int arrtime;
	int runtime;
	int priority;

	for(i = array.begin(); i!=array.end(); ++i){
		if (y == 1){
			istringstream buffer(*i);
			buffer >> arrtime;
		}else if (y == 2){
			istringstream buffer((*i).substr(2));
			buffer >> jobnum;
		}else if (y ==3){
			istringstream buffer((*i).substr(2));
			buffer >> mem;
		}else if (y == 4){
			istringstream buffer((*i).substr(2));
			buffer >> devs;
		}else if (y == 5){
			istringstream buffer((*i).substr(2));
			buffer >> runtime;
		}else if (y == 6){
			istringstream buffer((*i).substr(2));
			buffer >> priority;
		}
		y++;
	}

	Job* job = new Job(jobnum, mem, priority, arrtime, runtime, devs);
	return job;
}

