#include <iostream>
#include <stdlib.h>
#include "flexCharManager.h"
using namespace std;


flexCharManager::flexCharManager() {
	//used_memory = Mem_Block*[2];
}

flexCharManager::~flexCharManager() {
	// go through used memory and delete each memory block 
		// and delete the array
	for(int i = 0; i < used_mem_size; i++) {
		delete used_memory[i];
	}
	delete[] used_memory;
	// check whether used ememory is an object
}

char* flexCharManager::alloc_chars(int n){
	// keep mem blocks sorted least to greatest

	
	char* temp = NULL;
	// if there is nothing in there, add to the beginning
	if (active_requests == 0) {

		Mem_Block* newBlock = new Mem_Block; 
		
		used_memory[active_requests] = newBlock;

		active_requests++;
		temp = buffer;
		used_mem_size--;
		free_mem -= n;

		return temp;
	}
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
	// 	// DO I HAVE TO RESIZE NOW
	// 	return temp;
	// }

	// if (active_requests > 1) {

	// 	for (int i = 0; i < active_requests; i++) {
	// 		if (used_memory[]->physical_location > 6) {
				
	// 		}
	// 	}
	// 	// if (counter >= n) {
	// 	// 	// insert memblock
	// 	// }
	// }
	// if (active_requests == used_mem_size) {} double array
	// when to make it smaller

	//if there are gaps in used memory 
	// make sure n < ten thousand
	// if thee is no gap enough then look at the last place
	// in used memory (assuming there is enough space) 
	// and then add to the end
	// if there is no space at the end, resize it
		// declare a new giant memblock and copy over everything


	return temp;
}

void flexCharManager::free_chars(char* p) {
	// do you have to figure out which memblock you are on
	char* temp = p;
	for (char* i = p; ; i++) {
		*i = '\0';
	}

	// delete memblock
	// shift everything on the right to the left

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