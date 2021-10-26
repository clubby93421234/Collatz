// Collatz.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Collatz.h"
#include <map>			//std::map
#include <vector>		//std::vector	
#include <algorithm>  //std::sort
#include <iostream>		//std::cout

bool mysortfkt(std::pair<int, int> i, std::pair<int, int> j) {
	return(i.first < j.first);
}
void printCollatz(const int n, const std::map<int, int> mymap)
{
	std::cout << "The Collatz-Row for " << n << " is:" << std::endl;
	std::vector<std::pair<int, int>> myvector;
	
	for (auto& it = mymap.begin(); it != mymap.end(); ++it)//map to vector
		myvector.emplace_back(std::pair<int, int>(it->first, it->second));

	std::sort(myvector.begin(), myvector.end(), mysortfkt);
}

void collatz(const int n) {
	int c = n;
	std::map<int, int> v;
	std::map<int, int>::iterator it;
	while (c != 1) {
		it = v.find(c);//check if value c is already stored in map v
		if (it != v.end()) {//if it is stored
			c = it->second;//set c to the value if the c key
		}
		else {//if c is not in map v
			int c_old = c;
			if (c % 2 == 0) {//Collatz row
				c = c / 2;
			}
			else {
				c = c * 3 + 1;
			}
			v.insert(std::pair<int,int>(c_old,c));
		}

	}//end of while
	printCollatz(n, v);
}

int main()
{
	std::cout << "Hello CMake." << std::endl;
	collatz(44);
	return 0;
}
