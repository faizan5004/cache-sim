	
#include <cache.hh>

Cache::Cache(){
		}

Data Cache::read(const std::bitset<ADDRESS_BITS>& address) {
    std::bitset<TAG_BITS> tag = getTagBits(address);
    std::bitset<INDEX_BITS> index = getIndexBits(address);
    std::bitset<OFFSET_BITS> offset = getOffsetBits(address);

    // Check if the index exists in tag_store
    auto it = tag_store.find(index);
    if (it != tag_store.end()) {
        // Check if the entry is valid and the tags match
        if (it->second.first == 'v' && it->second.second.to_ulong() == tag.to_ulong()) {
            std::cout<< "Cache Hit : \n";
            std::cout<<"--- Tag Store ---\n";
            std::cout<<"Index: " << it->first <<" | Tag: "<<it->second.second<<std::endl;
            
            std::cout<<"--- Data Store ---\n";
            std::cout<<"Index: "<< index << " | Data: "<< data_store[index]<<std::endl;
            return data_store[index]; // Assuming data_store is also indexed by index
            
        }
    }
  
 
}

void Cache::write(const std::bitset<ADDRESS_BITS>& address, Data d){
			std::bitset<TAG_BITS> tag = getTagBits(address);
			std::bitset<INDEX_BITS> index = getIndexBits(address);
			std::bitset<OFFSET_BITS> offset = getOffsetBits(address);
			tag_store[index] = std::make_pair('v', tag);
			data_store[index] = d;
		
		}
		
// Implementation of the printStores function
void Cache::printStores() const {
    std::cout << "\n\n--------- Tag Store ----------" << std::endl;
    for (const auto& entry : tag_store) {
        std::cout << "Index: " << entry.first << " | Valid: " << entry.second.first 
                  << " | Tag: " << entry.second.second << std::endl;
    }

    std::cout << "\n\n-------- Data Store --------" << std::endl;
    for (const auto& entry : data_store) {
        std::cout << "Index: " << entry.first << " | Data Value: " << entry.second << std::endl;
    }
}
		

