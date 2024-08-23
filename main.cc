
#include <cache.hh>
#include <random>
#include <chrono>

std::bitset<32> generateRandomAddress() {
    // Use a random device to seed the generator
    static std::random_device rd;
    // Use the Mersenne Twister engine
    static std::mt19937 gen(rd());
    // Define a uniform distribution for 32-bit unsigned integers
    static std::uniform_int_distribution<uint32_t> dis(0, UINT32_MAX);

    // Generate a random 32-bit number and convert it to a bitset
    return std::bitset<32>(dis(gen));
}


int main(){
	
	Cache c;
	
	for (int i = 0; i < 1000; ++i) {
        std::bitset<32> address = generateRandomAddress();
        std::string data = std::to_string(i);
        std::cout << "Address " << i + 1 << ": " << address << std::endl;
        c.write(address, data);
    	}
    	
    	//print the cache values.
    	//c.printStores();
    	for (int i = 0; i<1000000;i++ ) {
        std::bitset<32> address = generateRandomAddress();
        c.read(address);
        //td::cout << "Reading at Address " << i + 1 << ": " << address << std::endl;
        //std::cout << "Data at address " << address <<" is "<< c.read(address) <<std::endl;
    	}
    	//std::cout << "Data at address " << temp <<" is "<< c.read(temp) <<std::endl;
    	return 0;
}
