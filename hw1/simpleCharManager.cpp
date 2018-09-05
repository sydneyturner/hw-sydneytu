#include <cstddef>
#include "simpleCharManager.h"



simpleCharManager::simpleCharManager(){
	for (int i = 0; i < BUF_SIZE; i++) {
		buffer[i] = '\0';
	}
	free_place = buffer;
}

simpleCharManager::~simpleCharManager(){}
             
char* simpleCharManager::alloc_chars(int n){
	
	char* temp;
	// temp ptr point to the freesapce
	// advance freespace n times 
	temp = free_place;

	// if freeplace + n < bufferSize
	if (n < counter) {
		for (int i = 0; i < n; i++){
	
		free_place++;
		counter -= n;
		}

    	return temp;
	}
	else {
		return NULL;
	}
	
}

void simpleCharManager::free_chars(char* p){
	free_place = p;

	for (char* i = p; i != buffer+BUF_SIZE; i++) {
		*i = '\0';

	}

}  