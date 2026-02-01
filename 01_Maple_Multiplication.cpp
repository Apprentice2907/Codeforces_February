// Maple has two positive integers a
//  and b
// . She may perform the following operation any number of times (possibly zero) to make a
//  equal to b
// :

// Choose any positive integer x
// , and multiply either a
//  or b
//  by x
// .
// Your task is to determine the minimum number of operations required to make a
//  equal to b
// . It can be proven that this is always possible.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤100
// ). The description of the test cases follows.

// The first and only line of each test case contains two positive integers a
//  and b
//  (1≤a,b≤1000
// ) — the numbers Maple currently has.

// Output
// For each test case, output a single integer representing the minimum number of operations Maple needs to make a
//  equal to b
// .

// Example
// InputCopy
// 3
// 1 2
// 10 3
// 1000 1000
// OutputCopy
// 1
// 2
// 0
// Note
// In the first test case, you can multiply a=1
//  by 2
//  to obtain a=b=2
// . This requires one operation.

// In the second test case, you can multiply a=10
//  by 300
//  to get a=3000
// , then multiply b=3
//  by 1000
//  to get b=3000
// . This requires two operations. Note that the numbers may exceed 1000
//  after the operations.

// In the third test case, a
//  and b
//  are already equal, so no operations are required.









#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        if (a == b) {
            cout << 0 << "\n";
        }
        else if (a % b == 0 || b % a == 0) {
            cout << 1 << "\n";
        }
        else {
            cout << 2 << "\n";
        }
    }

    return 0;
}
