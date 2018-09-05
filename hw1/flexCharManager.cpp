#include <iostream>
#include <stdlib.h>
#include "flexCharManager.h"
using namespace std;


flexCharManager::flexCharManager() {
	used_memory = new Mem_Block*[2];

	free_mem = BUF_SIZE;

}

flexCharManager::~flexCharManager() {
	// go through used memory and delete each memory block 
		// and delete the array
	for(int i = 0; i < active_requests; i++) {
		delete used_memory[i];
	}
	delete[] used_memory;
	// check whether used ememory is an object
}

char* flexCharManager::alloc_chars(int n){
	// keep mem blocks sorted least to greatest

	
	char* temp = NULL;
	if (n > 100000) {
		return NULL;
	}
	// if there is nothing in there, add to the beginning
	if (active_requests == 0) {

		Mem_Block* newBlock = new Mem_Block; 
		
		used_memory[active_requests] = newBlock;

		active_requests++;
		temp = buffer;
		used_mem_size--;
		free_mem -= n;

		//return temp;
	}
	if (active_requests == 1) {
		Mem_Block* newBlock = new Mem_Block; 

		if (used_memory[0]->physical_location < newBlock->physical_location) {
			used_memory[active_requests] = newBlock;
			active_requests++;
		
			used_mem_size--;
			free_mem -= n;
			temp += n;
		}
		else if (used_memory[0]->physical_location > newBlock->physical_location) {
			Mem_Block* tempBlock = new Mem_Block;
			tempBlock = used_memory[0];

			used_memory[0] = newBlock;
			used_memory[active_requests] = tempBlock;

			active_requests++;
		
			used_mem_size--;
			free_mem -= n;
			temp += n;

		}
		// Do I have to RESIZE NOW
		//resizeMem(used_mem_size, active_requests);
		//return temp;
	}
	if (active_requests > 1 && active_requests < used_mem_size) {
			

		for (int i = 0; i < active_requests; i++) {

			if (used_memory[i]->physical_location > ) {
				
				// shift over everything to the right by 1
				for() {
					used_memory[i] = used_memory[i+1];
				}
				// place the memblock in that spot

			}
			else if () {

			}
		}
		// if (counter >= n) {
		// 	// insert memblock
		// }
	}
	if (active_requests >= used_mem_size) {
		// double array
		resizeMem(active_requests, used_mem_size);
	}
	// when to make it smaller



	return temp;
}

void flexCharManager::free_chars(char* p) {
	// do you have to figure out which memblock you are on
	char* temp = p;
	for (char* i = p; i < active_requests; i++) {
		*i = '\0';
	}

	// delete memblock
	// shift everything on the right to the left

}

void resizeMem(int &used_mem_size, int &active_requests) {

	if (active_requests >= used_mem_size) {
		int doublSize = used_mem_size * 2;
		Mem_Block* tempMem = new Mem_Block*[doublSize];
		for (int i = 0; i < used_mem_size; i++) {
			 tempMem = used_memory[i];
		}
		used_mem_size = doublSize;
		// delete old array
		delete[] used_memory;
		// set tempMem to used
		used_memory = tempMem;
	}
	
	else if () { // Too many mem blocks
		// SIZE DOWN by 1/2
		int halfSize = used_mem_size / 2;
		Mem_Block* tempMem = new Mem_Block*[halfSize];
		for (int i = 0; i < used_mem_size; i++) {
			tempMem = used_memory[i];
		}

		used_mem_size = halfSize;
		delete[] used_memory;
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