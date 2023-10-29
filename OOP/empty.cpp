#include "empty.h"
#include <iostream>

struct TestStruct {
	void hello() {
		std::cout << "Hello World" << std::endl;
	}
};


class TestClass {
public:
	void hello() {
		std::cout << "Hello World" << std::endl;
	}
};

int main(void) {
	TestStruct a;
	TestClass b;

	a.hello();
	b.hello();

	return 0;
}