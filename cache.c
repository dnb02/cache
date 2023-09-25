#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "model.h"


struct cacheline L1[CACHE_SIZE]; 

void get_from_memory(int address){
	block target = &L1[hash(address)];
	put_into_memory(target);
	target->address = address;
	target->value = memory[address];
}


void put_into_memory(block b){
	memory[b->address] = b->value;
}

int get_from_cache(int address){
	block b = &L1[hash(address)];
	if(b->address!=address)	get_from_memory(address);
	return b->value;
}

void put_into_cache(int address, int value){
	block b = &L1[hash(address)];
	if(b->address!=address) get_from_memory(address);
	b->value = value;
}



void initmemory() {
				//initializing memory
	srand(time(NULL));
	for (int i = 0; i < MEMORY_SIZE; i++) {
    		memory[i] = rand(); 
    	}
				//initializing cache
	for(int i = 0; i < CACHE_SIZE; i++){
		L1[i].address = 0;
		L1[i].value = 0;
	}
}



int main(){
	int address;
	initmemory();
	printf("enter an address:");
	scanf("%d",&address);
	printf("%d\n",get_from_cache(address));
	return 0;
}
