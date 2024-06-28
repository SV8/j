#include <iostream>
#include <algorithm>
using namespace std;
#define DEBUG 0

void print_wallet(int wallet[]) {
	cout << "wallet[20]=" << wallet[20] << "|wallet[10]=" << wallet[10] << "|wallet[5]=" << wallet[5] << endl;
}

bool change(int wallet[], int amount) {
	//cout << "subtract 5 ..." << endl;
	int r = amount - 5;
	if(r == 0) {
		if(DEBUG) cout << "no need to change." << endl;
		return true;
	}		
	else {
		while(wallet[10]>0) {
			if(r-10>=0) {
				r-=10;
				wallet[10]--;
				if(DEBUG) cout << "give out 10." << endl;
				if(DEBUG) print_wallet(wallet);
			} else
				break;
		}
		while(wallet[5]>0) {
			if(r-5>=0) {
				r-=5;
				wallet[5]--;
				if(DEBUG) cout << "give out 5." << endl;
				if(DEBUG) print_wallet(wallet);
			} else
				break;
		}
		if(r==0)
			return true;
		else 
			return false;
	}
}

int main() {
	int wallet[21]; // only using wallet[5], wallet[10], wallet[20]
	std::fill(wallet, wallet+21, 0);
	
	int n;
	cin >> n;
	int amount = 0;
	int i = 0;
	for(; i<n; i++) {
		cin >> amount;
		if(DEBUG) cout << "Receiving " << amount << endl;
		wallet[amount]++;
		if(DEBUG) print_wallet(wallet);
		if(!change(wallet, amount)) {
			cout << "false" << endl;
			return 0;
		}
	}
	cout << "true" << endl;
	return 0;
}


