// vector assignment
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> first(3, 0);
	vector<int> second(5, 0);

	
	first.push_back(3);
	first.push_back(4);
	first.push_back(5);
	first.push_back(6);

	cout << first.size() << endl;
	first.pop_back();
	first.pop_back();
	cout << first.size() << endl;


	second = first;
	first = vector<int>();

	cout << "Size of first: " << int(first.size()) << endl;
	cout << "Size of second: " << int(second.size()) << endl;
	return 0;
}