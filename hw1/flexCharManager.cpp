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
	used_mem_size = 2;
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
		resizeMem();

	}
	else if (active_requests <= (used_mem_size/4)) {
		resizeMem();
	}

	if (n > 100000) {
		return NULL;
	}

	if (active_requests == 0) {
		temp = buffer;
		used_memory[active_requests] = new Mem_Block(n, temp);

		active_requests++;
		
		used_mem_size--;
		free_mem -= n;
	}
	else {
		int start_differnce;
		int end_diff;
		int difference;

		// find space before the first
		start_differnce = &buffer[0] - used_memory[0]->physical_location;
		if (start_differnce > 0 && start_differnce <= n) {
			temp = &buffer[0];
			for (int j = 0; j < active_requests; j++) {
				// shift everything to the right and add memblock to the front
				used_memory[j] = used_memory[j+1];
			}
			used_memory[0] = new Mem_Block(start_differnce, temp);
		}

		// find space after the last
		//end_diff = used_memory[active_requests]->physical_location  //- &buffer[BUF_SIZE-1];
		if (used_memory[active_requests]->physical_location + n < &buffer[BUF_SIZE]) {
				// add memblock to the end
			temp = &buffer[BUF_SIZE-1];
			used_memory[active_requests] = new Mem_Block(end_diff, temp);
		}
		
		for (int i = 0; i < active_requests; i++) {
			// find space between the memblocks
			difference = (used_memory[i]->physical_location + used_memory[i]->size) - used_memory[i+1]->physical_location;
			if (difference <= n) {
				temp = used_memory[i]->physical_location + used_memory[i]->size + 1;
				for(int j = i+1; j < active_requests; j++) {
					// shift over 
					used_memory[j] = used_memory[j+1];
				}
				used_memory[i+1] = new Mem_Block(difference, temp);
			}
			else {
				return NULL;
			}
		}
		
	}
	return temp;
}

void flexCharManager::free_chars(char* p) {
	// char* temp = p;
	// int start;
	// int end;
	// int indx = 0;

	// //char * temp = used_memory;


	// start = used_memory[0]->physical_location + used_memory[0]->size;
	// end = used_memory[active_requests]->physical_location + 
	// for (char* i = p; i < ; i++) {
	// 	*i = '\0';
	// }

	// delete memblock
	// shift everything on the right to the left
}
	

void flexCharManager::resizeMem() {

	if (active_requests >= used_mem_size) {
		int doublSize = used_mem_size * 2;
		Mem_Block** tempMem = new Mem_Block*[doublSize];
		for (int i = 0; i < used_mem_size; i++) {
			 tempMem[i] = used_memory[i];
		}
		used_mem_size = doublSize;
		// delete old array

		delete[] used_memory;
		// set tempMem to used
		used_memory = tempMem;
	}
	
	else if (active_requests < (used_mem_size/4)) { // Too many mem blocks
		// SIZE DOWN by 1/2
		int halfSize = used_mem_size / 2;
		Mem_Block** tempMem = new Mem_Block*[halfSize];
		for (int i = 0; i < used_mem_size/2; i++) {

			tempMem[i] = used_memory[i];
		}

		delete[] used_memory;
		used_mem_size = halfSize;
		used_memory = tempMem;
	}

}