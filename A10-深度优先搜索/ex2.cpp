/*
��δ�������ģ��һ������ n �μ� 1 �����У���¼���з����Ľ�λ������
���Խ� k �����һ�����ƵĻ�������ĳ��λ���ﵽ k ʱ��������λ����ֵ�� 0�����ڸ��ߵ�һλ�ϼ� 1��
��������ܵĽ�λ������


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
