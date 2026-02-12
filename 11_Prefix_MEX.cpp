// You are given an array of n
//  integers a1,a2,…,an
// .

// The value of an array is the sum of the maximums of each prefix of the array. More formally, the value of an array a
//  is ∑ni=1max(a1,…,ai)
// . For example, the value of the array [1,2,1
// ] is max(1)+max(1,2)+max(1,2,1)=1+2+2=5
// .

// You can choose two indices i
//  and j
//  and swap elements ai
//  and aj
// ; this operation can be applied at most one time.

// Find the maximum possible value of the array a
//  after at most one operation.

// Input
// The first line of the input contains a single integer t
//  (1≤t≤100
// ) — the number of test cases.

// The first line of each test case contains a single integer n
//  (2≤n≤50
// ) — the length of the array a
// .

// The second line contains n
//  integers a1,a2,…,an
//  (1≤ai≤104
// ) — the array a
// .

// Output
// For each test case, output the maximum possible value of the array a
//  after the swap has been performed.

// Example
// InputCopy
// 4
// 5
// 2 1 4 5 3
// 2
// 5 1
// 3
// 3 2 1
// 2
// 6 7
// OutputCopy
// 25
// 10
// 9
// 14
// Note
// For the first test case, we can swap a1
//  with a4
//  to get the array [5,1,4,2,3
// ], which has a value of max(5)+max(5,1)+max(5,1,4)+max(5,1,4,2)+max(5,1,4,2,3)=25
// .

// For the second test case, the current value of the array is max(5)+max(5,1)=10
// . If we were to swap a1
//  and a2
// , a
//  would be equal to [1,5
// ], which has a value of max(1)+max(1,5)=6
// , meaning the best option is to not perform a swap.










#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        int mx = *max_element(a.begin(), a.end());
        int idx = max_element(a.begin(), a.end()) - a.begin();

        if(idx != 0) {
            swap(a[0], a[idx]);
        }

        long long sum = 0;
        int prefixMax = 0;

        for(int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, a[i]);
            sum += prefixMax;
        }

        cout << sum << endl;
    }
}



