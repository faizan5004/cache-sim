#include <iostream>
#include <cmath>
#include <bitset>
#include <string>

#ifndef TYPES_HH
#define TYPES_HH


typedef std::string Data;
const int ADDRESS_BITS = 32;
const int INDEX_BITS = 8;
const int OFFSET_BITS = 6;
const int TAG_BITS = 18;

extern int latency;
extern int cache_size;
extern int num_of_blocks;
extern int associativity;
extern int block_size;
extern int num_of_sets;

#endif // TYPES_HH

int getNumOfSets();
int getNumOfBlocks();
void calculate();


inline int calculateBits(int value) {
    return static_cast<int>(log2(value));
} 

inline int getBytes(int size){
	return size * 1024;
}	

inline int getNumOfSets(){
	return getNumOfBlocks() / associativity;
}

// Function to create a mask of 'n' 1's
inline std::bitset<ADDRESS_BITS> createMask(const int n) {
    return std::bitset<ADDRESS_BITS>((1ull << n) - 1);
}

// Function to extract tag bits
inline std::bitset<TAG_BITS> extractTag(const std::bitset<ADDRESS_BITS>& address) {
    std::bitset<ADDRESS_BITS> extractedTag = (address >> (INDEX_BITS + OFFSET_BITS)) & createMask(TAG_BITS);
    
    return std::bitset<TAG_BITS>(extractedTag.to_ullong());
}


// Function to extract index bits
inline std::bitset<INDEX_BITS> extractIndex(const std::bitset<ADDRESS_BITS>& address) {
    // Create a mask for the index bits
    std::bitset<ADDRESS_BITS> indexMask = createMask(INDEX_BITS);
    
    // Shift the address to align the index bits with the least significant bits
    std::bitset<ADDRESS_BITS> extractedIndex = (address >> OFFSET_BITS) & indexMask;

    // Convert to INDEX_BITS size
    return std::bitset<INDEX_BITS>(extractedIndex.to_ullong());
}

// Function to extract offset bits
inline std::bitset<OFFSET_BITS> extractOffset(const std::bitset<ADDRESS_BITS>& address) {
    // Create a mask for the offset bits
    std::bitset<ADDRESS_BITS> offsetMask = createMask(OFFSET_BITS);
    
    // Extract the offset bits directly
    std::bitset<ADDRESS_BITS> extractedOffset = address & offsetMask;

    // Convert to OFFSET_BITS size
    return std::bitset<OFFSET_BITS>(extractedOffset.to_ullong());
}

inline int getNumOfBlocks(){
	return getBytes(cache_size) / block_size;
}

inline std::bitset<INDEX_BITS> getIndexBits(const std::bitset<ADDRESS_BITS>& address){
	return extractIndex(address);
}

inline std::bitset<TAG_BITS> getTagBits(const std::bitset<ADDRESS_BITS>& address){
	return extractTag(address);
}

inline std::bitset<OFFSET_BITS> getOffsetBits(const std::bitset<ADDRESS_BITS>& address){
	return extractOffset(address);
}
