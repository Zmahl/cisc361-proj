#include <iostream>
#include <fstream>
using namespace std;

int main(){

	ifstream inFile;

	inFile.open("");
	if (!inFile){
		cout << "Unable to open file";
		exit(1);
	}

	while (inFile >> x){

	}

	inFile.close();
}
