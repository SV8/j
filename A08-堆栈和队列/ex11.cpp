#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	deque<int> shelf;
	int happy = 0;
	
	for(int i=0; i<n; i++) {
		int gift;
		cin >> gift;
		
		// first search the shelf for duplicated gift.
		if(find(shelf.begin(), shelf.end(), gift) == shelf.end())  { // not found
			if(shelf.size() >= m) {
				shelf.pop_front();
			}
			shelf.push_back(gift);
			happy++;
		}
	}
	
	cout << happy << endl;
	
	return 0;
}
