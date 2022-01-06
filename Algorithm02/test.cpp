#include<iostream>
#include<cmath>
#include<vector>


int main() {

	std::vector<std::vector<int>> table = {
		{1,0,0,1},
		{1,1,0,1},
		{0,1,0,1},
		{1,0,0,1}
	};

	int len = sqrt(sizeof(table));
	std::cout << len << "aaaaa" << std::endl;

	//std::cout << Solution(table) << std::endl;


	return 0;
}