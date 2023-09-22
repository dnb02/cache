#ifndef __MODEL_H__
#define __MODEL_H__

#define MEMORY_SIZE 1000
#define CACHE_SIZE 11	//prime to ensure good distribution
struct cacheline;
typedef struct cacheline* cache;
typedef struct cacheline* block;
int memory[MEMORY_SIZE];
enum kindofentry { good, empty, dirty };

struct cacheline{
	int address;
	int value;
};


int hash(int address);
void get_from_memory(int address);
void put_into_memory(block b);
int get_from_cache(int address);
void put_into_cache(int address, int value);

int hash(int address){
	return address % CACHE_SIZE;
}

#endif
