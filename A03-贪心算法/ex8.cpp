#include <iostream>
#include <algorithm>
using namespace std;

struct Cheese {
	int a_score;
	int b_score;
};

bool compare(Cheese c1, Cheese c2) {
	return (c1.a_score - c1.b_score) > (c2.a_score - c2.b_score);
}

int main() {
	int n, k;
	cin >> n >> k;
	Cheese c[n];
	
	for(int i=0; i<n; i++) {
		cin >> c[i].a_score;
	}
	
	for(int i=0; i<n; i++)
		cin >> c[i].b_score;
		
	sort(c, c+n, compare); // sort c in descending order of (a_score-b_score)
	
	int total = 0;
	for(int i=0; i<n; i++) {
		if(i<k)
			total += c[i].a_score;	
		else
			total += c[i].b_score;
	}
		
	cout << total << endl;
	return 0;
}
