#ifndef __MODEL_H__
#define __MODEL_H__

#include<bitset>
#define CACHE_SIZE 16384 //16Kb
#define WORD_SIZE 64
using std::bitset;
class cacheline;
enum kindofentry { valid = 1, invalid = 0 };

class cacheline{
	enum kindofentry validbit;
	bitset<47> tag;
	bitset<64> data;
};

bitset<64> hash( bitset<64> address){
//			     [	Tag					     | Index  |---]
	bitset<64> extractor("0000000000000000000000000000000000000000000000011111111111111000");
	return address & extractor;
}
#endif
