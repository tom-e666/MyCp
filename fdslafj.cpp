#include <iostream>
#include <stdexcept>

void riskyOperation() {
    throw "check message";
}

int main() {
    
	try{
		riskyOperation();
 } catch (const std::runtime_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    
    
}
