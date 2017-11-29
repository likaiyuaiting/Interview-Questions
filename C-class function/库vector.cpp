#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
#if 0
	vector<int> first;                                // empty vector of ints
	vector<int> second(4, 100);                       // four ints with value 100
	vector<int> third(second.begin(), second.end());  // iterating through second
	vector<int> fourth(third);
#endif
#if 1
	std::vector<int>first;
	std::vector<int>second;
	std::vector<int>third;
	first.assign(7, 100);
	std::vector<int>::iterator it;
	it = first.begin() + 1;
	second.assign(it, first.end() - 1);
	int myints[] = { 1776, 7, 4 };
	third.assign(myints, myints + 3);
	std::cout << int(first.size()) << "  " << int(second.size()) << "  " << int(third.size()) << endl;
#endif
}