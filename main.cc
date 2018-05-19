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

		while(getline(my_file, line)){
			if (line[0] == 'A'){
				Job* new_job = make_job(line);
				if (new_job->get_memory() < system->get_total_mem()){
					system->set_time(new_job->get_arrtime());
					if (new_job->get_memory() < system->get_avail_mem()){
						new_job->set_location(3);
						Process* new_process = new Process(new_job);
						new_process->add_alloc_devs(2);
						system->add_rq(new_process);
					}else{
						if (new_job->get_priority() == 1){
							new_job->set_location(1);
							system->add_hq1(new_job);
						}else if (new_job->get_priority() == 2){
							new_job->set_location(2);
							system->add_hq2(new_job);
						}
					}
				}else{
					cout << "Not enough system memory." << endl;
				}
			}else if (line[0] == 'Q'){
				
			}
		}
	}
	else{
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

	Job* job = new Job(jobnum, mem, priority, arrtime, runtime, devs, 0);
	return job;
}

