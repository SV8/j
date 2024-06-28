/*

Counting Sort
https://cloud.tencent.com/developer/article/1684188

计数排序是一个广泛使用的排序方法。下面的程序使用双关键字计数排序,将 n 对 10000 以内的整数,从小到大排序。
例如有三对整数( 3 , 4 )、( 2 , 4 )、( 3 , 3 ),那么排序之后应该是( 2 , 4 ) 、( 3 , 3 ) 、( 3 , 4 ) 。
输入第一行为 n ,接下来 n 行,第 i 行有两个数 a [ i ]和 b [ i ],分别表示第 i 对整数的第一关键字和第二关键字。
从小到大排序后输出。
数据范围 1 ≤ n ≤ 10^7 , 1 ≤ a [ i ], b [ i ]≤ 10^4。
提示：应先对第二关键字排序,再对第一关键字排序。数组 ord []存储第二关键字排序的结果,数组 res []存储双关键字排序的结果。
试补全程序。

假设 n = 3
( 3 , 4 ) 、( 2 , 4 ) 、( 3 , 3 )
step 1 ->
( 3 , 3 ) 、( 3 , 4 ) 、( 2 , 4 ) 
step 2 ->
( 2 , 4 ) 、( 3 , 3 ) 、( 3 , 4 ) 

b[] = [4, 4, 3]

STEP 1.

cn[b[0]]++ = cn[4]+=1 = 1
cn[b[1]]++ = cn[4]+=1 = 2
cn[b[2]]++ = cn[3]+=1 = 1
...

cn[] = [0, 0, 0, 1, 2, ...]
这里cn的含义是每个b[i]的“等值坑位”上有多少个数

for
cnt[i + 1] += cnt[i];
cn[] = [0, 0, 0, 1, 3, ...]
迭代累加后,cn的含义变为每个b的等值“坑位”之前的所有坑位(包含自己),一共含有多少个数
即cn[i]的含义为: b中小于等于i的数有多少个
验证:
cn[0] = 0
cn[1] = 0
cn[2] = 0
b中小于等于0,1,2的都是0个;
cn[3] = 1
b中小于等于3的有1个;
cn[4] = 3
b中小于等于4的有3个

for (int i = 0; i < n; --i) {
    ord[--cnt[b[i]]] = i; // 记录初步排序结果
}
ord[--cnt[b[i]]] = i 这一步将原始数组的索引 i 放到 ord 数组中相应的位置。
--cnt[b[i]] 减少累计计数,并将索引 i 存储到 ord 数组中对应位置。
这样 ord 数组就表示了按 b 值排序后的元素的原始索引。

cn[] = [0, 0, 0, 1, 3, ...]
i = 0
b[0] = 4
cn[4] = 3
cn[4] = cn[4]-1 = 2
ord[2] = 0
i = 1
b[1] = 4
cn[4] = 2
cn[4] = cn[4]-1 = 1
ord[1] = 1
i = 2
b[2] = 3
cn[3] = 1
cn[3] = cn[3]-1 = 0
ord[0] = 2
得到初步排序
ord = [2, 0, 1]

注意：如果不进行迭代累加，那么会发生什么？演算一次：
cn[] = [0, 0, 0, 1, 2, ...]
i = 0
b[0] = 4
cn[4] = 2
cn[4] = cn[4]-1 = 1
ord[1] = 0
i = 1
b[1] = 4
cn[4] = 1
cn[4] = cn[4]-1 = 0
ord[0] = 1
i = 2
b[2] = 3
cn[3] = 1
cn[3] = cn[3]-1 = 0
ord[0] = 2
得到初步排序，索引0出现2次，显然不对
ord = [0, 0, 1]

反序遍历也可以，而且是稳定排序，正向遍历不是稳定排序 
i = 2
ord[--cn[b[2]]] = ord[--cn[3]] = ord[0] = 2  (b中小于等于3的有1个, 那么减掉1等于0, 0就是3在ord中的新排位, 3在b中的原始排位是2)
i = 1
ord[--cn[b[1]]] = ord[--cn[4]] = ord[2] = 1  (b中小于等于4的有3个, 那么减掉1等于2, 2就是4在ord中的新排位, 4在b中的原始排位是1)
i = 0
ord[--cn[b[0]]] = ord[--cn[4]] = ord[1] = 0  (b中小于等于4的还剩2个, 那么减掉1等于1, 1就是4在ord中的新排位, 4在b中的原始排位是0)

ord = [2, 0, 1]

STEP 2.

a[] = [3, 2, 3]

cn[a[0]]++ = cn[3]+=1 = 1
cn[a[1]]++ = cn[2]+=1 = 1
cn[a[2]]++ = cn[3]+=1 = 2

for
cnt[i + 1] += cnt[i];
cn[0] = 0
cn[1] = 0
cn[2] = 1
cn[3] = 3

for (int i = n - 1; i >= 0; --i) {
    res[--cnt[a[ord[i]]]]=ord[i]; // 最终排序结果
}

i = 2
res[--cnt[a[ord[2]]]] = res[--cnt[a[1]]] = res[0] = 1
res[--cnt[a[ord[1]]]] = res[--cnt[a[0]]] = res[2] = 0 
res[--cnt[a[ord[0]]]] = res[--cnt[a[2]]] = res[1] = 2

res = [1, 2, 0]

打印最终排序
print a[res[i]], b.[res[i]]

*/

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10000000;
const int maxs = 10000;


int n;
unsigned a[maxn], b[maxn], ord[maxn];
unsigned res[maxn];
unsigned cnt[maxs + 1];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &a[i], &b[i]);

    // Step 1: Count and sort by second key b
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i)
        cnt[b[i]]++; // 利用 cnt 数组统计数量

    for (int i = 0; i < maxs; ++i)
        cnt[i + 1] += cnt[i]; // 累加是为了得到索引位置。不累加只能得到个数，适合挨个输出，没有索引信息

    for (int i = 0; i < n; ++i) {
        ord[--cnt[b[i]]] = i; // 记录初步排序结果
    }

    // Step 2: Count and sort by first key a using ord
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i)
        cnt[a[ord[i]]]++; // 利用 cnt 数组统计数量

    for (int i = 0; i < maxs; ++i)
        cnt[i + 1] += cnt[i];

    for (int i = n - 1; i >= 0; --i) {
        res[--cnt[a[ord[i]]]]=ord[i]; // 记录最终排序结果
    }

    for (int i = 0; i < n; ++i)
        printf("%d %d\n", a[res[i]],b[res[i]]);

    return 0;
}
