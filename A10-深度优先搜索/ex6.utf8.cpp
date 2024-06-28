/*
start = 0, k = 3, currentSum = 0
|
|-- (3) -> find()
|           |
|           |-- (7) -> find()
|           |           |
|           |           |-- (12) -> find() --> 22 不是素数
|           |           |
|           |           |-- (19) -> find() --> 29 是素数，count++
|           |
|           |-- (12) -> find()
|           |           |
|           |           |-- (19) -> find() --> 34 不是素数
|           |
|           |-- (19) -> find()
|
|-- (7) -> find()
|           |
|           |-- (12) -> find()
|           |           |
|           |           |-- (19) -> find() --> 38 不是素数
|           |
|           |-- (19) -> find()
|
|-- (12) -> find()
|           |
|           |-- (19) -> find()
|
|-- (19) -> find()

递归调用展开过程
第一层调用：

选3：递归处理[7, 12, 19]，k减1，currentSum变为3。
选7：递归处理[12, 19]，k减1，currentSum变为7。
选12：递归处理[19]，k减1，currentSum变为12。
选19：递归处理空数组，k减1，currentSum变为19。
第二层调用：

从当前选择继续，进一步递归直到选满3个数字（k=0）。
第三层调用：

达到k=0时，检查currentSum是否为素数，并根据结果更新计数count。
*/
#include <iostream>
#include <cmath>
using namespace std;

int count = 0;

// 判断一个数是否为素数
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// 递归生成组合并检查和是否为素数
void find(int nums[], int n, int k, int start, int currentSum) {
    if (k == 0) {
        if (isPrime(currentSum)) {
        	cout << currentSum << " 是素数." << endl;
            ++count;
        }
        else
        	cout << currentSum << " 不是素数." << endl;
        return;
    }
    for (int i = start; i < n; ++i) {
    	find(nums, n, k - 1, i + 1, currentSum + nums[i]);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int nums[20]; // n 的最大值是 20
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
	
	find(nums, n, k, 0, 0);

    cout << count << endl;
    return 0;
}
