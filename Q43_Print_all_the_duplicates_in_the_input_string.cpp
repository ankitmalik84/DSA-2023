// Q43
//no. 58
// from string using maps
#include <bits/stdc++.h>
using namespace std;
void printDups(string str)
{
	map<char, int> count;
	for (int i = 0; i < str.length(); i++) {
		count[str[i]]++;
	}
	for (auto it : count) {
		if (it.second > 1)
			cout << it.first << ", count = " << it.second
				<< "\n";
	}
}

int main()
{
	string str = "test string";
	printDups(str);
	return 0;
}

