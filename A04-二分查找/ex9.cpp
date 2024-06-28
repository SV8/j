#include <bits/stdc++.h>
using namespace std;

int a[100005];
int v[100005];

int main() {
    int n, n2, l, r;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    cin >> n2;
    for(int i = 0; i < n2; ++i) {
        cin >> v[i];
    }
    
    for(int i = 0; i < n2; ++i) {
        int lower = lower_bound(a, a + n, v[i]) - a;
        int upper = upper_bound(a, a + n, v[i]) - a;
        cout << upper-lower << endl;
    }
    
    return 0;
}
