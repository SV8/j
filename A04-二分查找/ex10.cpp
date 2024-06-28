#include <bits/stdc++.h>
using namespace std;

int a[100005];
int low[100005];
int high[100005];

int main() {
    int n, n2, l, r;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    cin >> n2;
    for(int i = 0; i < n2; ++i) {
        cin >> low[i] >> high[i];
    }
    
    for(int i = 0; i < n2; ++i) {
        l = low[i];
        r = high[i];
        int lower = lower_bound(a, a + n, l) - a;
        int upper = upper_bound(a, a + n, r) - a;
        cout << upper-lower << endl;
    }
    
    return 0;
}


//#include<bits/stdc++.h>
//using namespace std;
//int a[1000005];
//int main(){
//	int n,n2;
//    cin >> n;
//    for(int i = 0;i < n;i ++){
//    	cin >> a[i];
//    }
//    sort(a,a + n);
//    
//    cin >> n2;
//    int begin[n2], end[n2]; // 输入多组 l和r 
//    for(int i = 0;i < n2;i ++){
//		cin >> begin[i] >> end[i];
//	}
//
//    for(int i = 0;i < n2; i++){
//    	
//    	int ub_begin = upper_bound(a, a+n, begin[i]) - a;
//    	int ub_end = upper_bound(a, a+n, end[i]) - a;
//    	int lb_begin = lower_bound(a, a+n, begin[i]) - a;
//    	int lb_end = lower_bound(a, a+n, end[i]) - a;
//    	
////    	cout << "upper_bound of " << begin[i] << ": " << ub_begin;
////    	cout << endl;
////    	cout << "upper_bound of " << end[i] << ": " << ub_end;
////    	cout << endl;
//    	
//    	if(ub_begin!=lb_begin) {
//			cout << ub_end - ub_begin + 1;
//		} else {
//			cout << ub_end - ub_begin;
//		}
//    	cout << endl;
//    }
//	return 0;
//}
