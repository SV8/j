#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string str;
    cin >> str;
    char cc, lc;
    int cn, ln;
    
    int n = str.size();
    int flag[n] = {0};
    
    lc = str[0];
    ln = 0;
    
    for(int i=0; i<n; i++) {
        //cn = 0;
        if(flag[i] == 1) {
            continue;
        }
        else if(flag[i] == 0) {
        	cc = str[i];
            cn = 1;
            flag[i] = 1;
        }
        for(int j=i+1; j<n; j++) {
            if(flag[j] == 1) {
                continue;
            }	
            else if(flag[j] == 0) {
                if(str[j] == cc) {
                    cn++;
                    flag[j] = 1;
                }
            }
        }
        //cout << cc << ":" << cn << " ";
        if(cn>ln || (cn==ln && cc<lc)) {
        	lc = cc;
            ln = cn;
        }
    }
    //cout << endl << lc << ":" << ln << endl;
    cout << lc << endl;
    return 0;
}
