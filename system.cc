#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

int main(){
	string x;
	ifstream inFile;

	inFile.open("test.txt");
	if (!inFile){
		cout << "Unable to open file";
		exit(1);
	}

	while ( getline(inFile, x) ){
		cout << x << '\n';
		cout << x[0] << '\n';
	}

	inFile.close();
}
