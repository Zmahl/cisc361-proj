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

int main(){
	string line;
	string input;
	System* system;
	ifstream my_file ("test.txt");

	if (my_file.is_open()){
		getline(my_file, line);
		system = make_system(line);
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
			time = (*i)[0];
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
