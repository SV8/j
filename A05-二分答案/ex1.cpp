#include <bits/stdc++.h>
using namespace std;
char chg(char c) {
	char pre=c;
	if(c=='a')pre='e';
	else if(c=='e')pre='i';
	else if(c=='i')pre='o';
	else if(c=='o')pre='u';
	return pre;
}
int main() {
	string word;
	cin>>word;
	int n=word.size();
	int mx=0;
	int i=0;
	while(i<n) {
		if(word[i]!='a') {
			i++;
			continue;
		}
		int start=i;
		i++;
		char c='a';
		while(i<n&&(word[i]==word[i-1]||chg(word[i-1])==word[i])) {
			if(chg(word[i-1])==word[i]) {
				c=word[i];
			}
			i++;
		}
		if(c=='u')mx=max(mx,i-start);
	}
	cout<<mx;
	return 0;
}
