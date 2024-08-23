#include <types.hh>
#include <unordered_map>

class Cache {
	public:
		Cache();
		Data read(const std::bitset<ADDRESS_BITS>& address);
		void write(const std::bitset<ADDRESS_BITS>& address, Data d);
		void printStores() const; // Function to print the maps
		
		
	private:
		std::unordered_map<std::bitset<INDEX_BITS>, std::pair<char, std::bitset<TAG_BITS> > > tag_store;
		std::unordered_map<std::bitset<INDEX_BITS>, Data> data_store;
};
