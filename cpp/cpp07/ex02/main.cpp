#include "Array.hpp"
#include <limits>

int main(void) {
	Array<int> nothing;
	Array<float> a(10);

	Array<float> b = a;
	std::cout << nothing.size() << std::endl;
	std::cout << b.size() << std::endl;
	try {
		for (int i = 0; i < std::numeric_limits<int>::max(); i++) {
			std::cout << "a: " << a[i] << "; b: " << b[i] << ";" << std::endl;
		}
	} catch (std::exception& exception) {
		std::cout << "exception detected" << std::endl;
	}
	a[0] = 10.5f;
	b[9] = 111.f;
	std::cout << "a: " << a[0] << "; b: " << b[0] << ";" << std::endl;
	std::cout << "a: " << a[9] << "; b: " << b[9] << ";" << std::endl;
	try {
		a[10] = 99.01f;
	} catch (std::exception& exception) {
		std::cout << "exception detected" << std::endl;
	}
	return 0;
}
