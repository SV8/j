/*

char encoder[26] = {'C', 'S', 'P', 'A', 'B', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'Q', 'R', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

char decoder[26] = {'D', 'E', 'A', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'C', 'R', 'S', 'B', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


'A' 编码成 'D'
'B' 编码成 'E'
'C' 编码成 'A'
'D' 编码成 'F'
'E' 编码成 'G'
依此类推。

{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}
{'D', 'E', 'A', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'C', 'R', 'S', 'B', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

*/

#include <cstdlib>
#include <iostream>
using namespace std;

char encoder[26] = {'C','S','P',0};
char decoder[26];

string st;

int main()  {
  int k = 0;
  for (int i = 0; i < 26; ++i)
    if (encoder[i] != 0) ++k;
  for (char x ='A'; x <= 'Z'; ++x) {
    bool flag = true;
    for (int i = 0; i < 26; ++i)
      	if (encoder[i] ==x) {
        	flag = false;
        	break;
      	}
	if (flag) {
		encoder[k]= x;
    	++k;
    }
  }
  
  for (int i = 0; i < 26; ++i)
	decoder[encoder[i]- 'A'] = i + 'A';

  cin >> st;
  
  for (int i = 0; i < st.length( ); ++i)
    st[i] = decoder[st[i] -'A'];
    
  cout << st;
  
  return 0;
}
