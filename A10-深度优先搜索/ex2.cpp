/*
这段代码用于模拟一个数在 n 次加 1 操作中，记录所有发生的进位次数。
可以将 k 类比于一个进制的基数，当某个位数达到 k 时，发生进位，数值置 0，并在更高的一位上加 1。
最终输出总的进位次数。


def calculate(n, k):
    ans = 0
    power = k
    while power <= n:
        ans += n // power
        power *= k
    return ans

n = 27
k = 3

ans = calculate(n, k)
ans
13


100010002000090
 10001000200009
  1000100020000
   100010002000
    10001000200
     1000100020
      100010002
       10001000
        1000100
         100010
          10001
           1000
            100
             10
              1
11112222444453

*/

#include <iostream>
using namespace std;

long long n, ans;
int k, len;
long long d[1000000];

int main() {
  cin >> n >> k;
  d[0] = 0;
  len= 1;
  ans = 0;
  for (long long i = 0; i <n; ++i) {
    ++d[0];
    for (int j = 0; j + 1<len; ++j) {
      if (d[j] == k) {
        d[j] = 0;
        d[j + 1] += 1;
        ++ans;
      }
    }
    if (d[len- 1] == k) {
      d[len - 1] = 0;
      d[len] =1;
      ++len;
      ++ans;
    }
  }
  cout << ans << endl;
  cout << len << endl;
  return 0;
}
