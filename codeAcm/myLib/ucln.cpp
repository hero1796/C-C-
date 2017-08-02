#include <iostream>
#include "ucln.hpp"
using namespace std;

ucln::ucln() {

}

ucln::~ucln() {

}

int ucln::uc(int y, int z) {
	int tmp;
	while(y != 0) {
		if(y > z) {
			tmp = y;
			y = y%z;
			z = tmp;
		} else {
			tmp = y;
			y = z%y;
			z = tmp;
		}
	}
	return z;
}
