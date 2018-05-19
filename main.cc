#include "system.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
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

	System* system = new System(100, 10, 2, 1);
	return system;
}
