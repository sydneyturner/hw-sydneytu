#include <iostream>
#include <fstream>
#include <sstream>

void reverse(std::ifstream& stream, int numWords){
	std::string temp;
	
	// base case : numWords = 0
	if (numWords == 0) {
		return;
	}
	else {
		stream >> temp;
		reverse(stream, numWords-1);
	}
	std::cout << temp << std::endl;
}



int main(int argc, char* argv[]) {
	std::ifstream myfile;
	myfile.open(argv[1]);

	int numWords = 0;
	std::string line;
	
	myfile >> numWords;

	reverse(myfile, numWords);

    return 0;
 }
	



