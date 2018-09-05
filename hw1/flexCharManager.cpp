#include <iostream>
#include <stdlib.h>
#include "flexCharManager.h"
//using namespace std;


flexCharManager::flexCharManager() {
	used_memory = new Mem_Block*[2];

	for (int i = 0; i < BUF_SIZE; i++) {
		buffer[i] = '\0';
	}

	free_mem = BUF_SIZE;
	active_requests= 0;

}

flexCharManager::~flexCharManager() {
	for(int i = 0; i < active_requests; i++) {
		delete used_memory[i];
	}
	delete[] used_memory;
}

char* flexCharManager::alloc_chars(int n){
	char* temp = NULL;

	if (active_requests >= used_mem_size) {
		std::cout << "doubling size" << std::endl;
		resizeMem();
		std::cout << "I doubled the size" << sstd::endl;
	}
	else if (active_requests <= (used_mem_size/4)) {
		std::cout << "halving size" << std::endl;
		resizeMem();
		std::cout << "I halved the size" << std::endl;
	}
	if (n > 100000) {
		return NULL;
	}

	if (active_requests == 0) {
		Mem_Block* newBlock = new Mem_Block; 
		used_memory[active_requests] = newBlock;
		active_requests++;
		temp = buffer;
		used_mem_size--;
		free_mem -= n;
		//return temp;
	}
	else {
		// int counter = 0;
		// //int start;
		// for (int i = 0; i < BUF_SIZE; i++) {
		// 	if (buffer[i] == '\0') {
		// 		temp = buffer + i;
		// 		for (int j = 0; j < n; j++) {
		// 			if (buffer[i] + j == '\0') { 
		// 				counter++;
		// 			}
		// 		}
		// 		if (counter <= n) {
		// 			//for (int k = 0; k < active_requests; k++) {
		// 				used_memory[active_requests] = new Mem_Block(counter, temp);
		// 			//}
		// 			//return temp;
		// 		}
		// 		else {
		// 			return NULL;
		// 		}
		// 	}
		// }
		int start_difference;
		// check beginning
		start_differnce = &buffer[0] - used_memory[0]->physical_location;


		
		
		//int start;
		for (int i = 0; i < active_requests; i++) {
			difference = (used_memory[i]->physical_location + used_memory[i]->size) - used_memory[i+1]->physical_location;
			if (difference <= n) {
				temp = used_memory[i]->physical_location + used_memory[i]->size + 1;

				if (used_memory[i]->physical_location < used_memory[0]->physical_location){

				}
				used_memory[active_requests] = new Mem_Block(difference, temp);
			}
			else {
				return NULL;
				// break;
			}
		}
	}
	return temp;
}

void flexCharManager::free_chars(char* p) {
	char* temp = p;
	int start = 0;
	int end = 0;
	int indx = 0;

	//char * temp = used_memory;

	for (int i < 0; i < BUF_SIZE; i++){
		// get the Memblock
		// if (temp == &used_memory[i]) {
		// 	indx = i;
		// 	break;
		// }
	}

	start = 
	// for (char* i = p; i < ; i++) {
	// 	*i = '\0';
	// }
}
	// delete memblock
	// shift everything on the right to the left

void flexCharManager::resizeMem() {

	if (active_requests >= used_mem_size) {
		int doublSize = used_mem_size * 2;
		Mem_Block** tempMem = new Mem_Block*[doublSize];
		for (int i = 0; i < used_mem_size; i++) {
			 tempMem[i] = used_memory[i];
		}
		used_mem_size = doublSize;
		// delete old array
		for(int i = 0; i < used_mem_size; i++) {
			delete used_memory[i];
		}
		delete[] used_memory;
		// set tempMem to used
		used_memory = tempMem;
	}
	
	else if (active_requests < (used_mem_size/4)) { // Too many mem blocks
		// SIZE DOWN by 1/2
		int halfSize = used_mem_size / 2;
		Mem_Block** tempMem = new Mem_Block*[halfSize];
		for (int i = 0; i < used_mem_size; i++) {
			tempMem[i] = used_memory[i];
		}

		

		for (int i = 0; i < used_mem_size; i++) {
			delete used_memory[i];
		}
		delete[] used_memory;
		used_mem_size = halfSize;
		used_memory = tempMem;
	}

}

// int main(int argc, char *argv[])
// {
//   flexCharManager simplest_mem_manager;

// replace with driver code as specificed in the assignment
//   std::cout << "Hello world!\n";
  
//   return 0;
// }


		// int counter = 0;
		// for (int i = 0; i < BUF_SIZE; i++) {
		// 	if (buffer[i] == '\0') {
		// 		for (int j = 0; j < n; j++) {
		// 			if (buffer[i] + j == '\0') { // if there are n-1 \0 after i
		// 				// how to stop until it reaches a new character
		// 				counter++;

						
		// 			}
		// 		}
		// 	}
			
		// }

	// if (active_requests == 1) {
	// 	Mem_Block* newBlock = new Mem_Block; 

	// 	if (used_memory[0]->physical_location < newBlock->physical_location) {
	// 		used_memory[active_requests] = newBlock;
	// 		active_requests++;
		
	// 		used_mem_size--;
	// 		free_mem -= n;
	// 		temp += n;
	// 	}
	// 	else if (used_memory[0]->physical_location > newBlock->physical_location) {
	// 		Mem_Block* tempBlock = new Mem_Block;
	// 		tempBlock = used_memory[0];

	// 		used_memory[0] = newBlock;
	// 		used_memory[active_requests] = tempBlock;

	// 		active_requests++;
		
	// 		used_mem_size--;
	// 		free_mem -= n;
	// 		temp += n;

	// 	}
	// 	// Do I have to RESIZE NOW
	// 	//resizeMem(used_mem_size, active_requests);
	// 	//return temp;
	// }


		// for (int i = 0; i < active_requests; i++) {
		// 	if ((start - used_memory[i]->start+size) <= n) {
				
		// 		// shift over everything to the right by 1
		// 		for() {
		// 			used_memory[i] = used_memory[i+1];
		// 		}
		// 		// place the memblock in that spot

		// 	}
		// 	else if () {

		// 	}
		// }


// difference = used_memory[0]->physical_location - &buffer[0];

// if (difference < n) {

// }

// if (difference < n && active_requests != 1) {
// 	for ( i < active requests) {
// 		difference - used_memory[i+1]-physical_location = used_memory[i]->physical_location + used_memory[i]->size
// 		if (difference >= 0) {
// 			temp = used_memory[i]->physical_location + used_memory[i]->size + 1;
			//  break;
// 		}
// 	}
// }

// else {
// 	return temp = buffer;
// }

// if (active_requests )

