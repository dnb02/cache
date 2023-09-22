#include "model.h"

cache L1 = initcache(); //array of size 11 of type struct cacheline

void get_from_memory(int address){
	block target = &L1[hash(address)];
	target->address = address;
	target->value = memory[address];
}


void put_into_memory(block b){
	memory[b->address] = b->value;
}

int get_from_cache(int address){
	block b = &L1[hash(address)];
	if(b->typeinfo==empty && b->address!=address)	get_from_memory(address);
	return b->value;
}

void put_into_cache(int address, int value){
	block b = &L1[hash(address)];
	if(b->typeinfo == empty && b->address!=address) get_from_memory(address);
	b->value = value;
}

