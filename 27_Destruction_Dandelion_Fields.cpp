// Farmer John has a lawnmower, initially turned off. He also has n
//  fields, with the i
// -th field having ai
//  dandelions. He will visit all the fields in any order he wants, and each field exactly once.

// FJ's lawnmower seems to have a mind of its own. Right before visiting a field, it checks if the field has an even or odd number of dandelions. If it has an odd number, then the lawnmower toggles its state (if it is off, it turns on; if it is on, it turns off). Then, if the lawnmower is on, it will cut all dandelions in that field. Otherwise, if the lawnmower is off, then FJ will simply visit the field and cut no dandelions.

// If FJ visits the n
//  fields in optimal order, what is the maximum total number of dandelions he can cut?

// Input
// The first line contains an integer t
//  (1≤t≤104
// ) — the number of test cases.

// The first line contains an integer n
//  (1≤n≤2⋅105
// ) — the number of fields.

// The following line contains n
//  space-separated integers a1,a2,…,an
//  (1≤ai≤109
// ) — the number of dandelions in each field.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, output an integer on a new line: maximum dandelions FJ can cut if he visits all n
//  fields in optimal order.

// Example
// InputCopy
// 3
// 3
// 2 4 6
// 4
// 4 2 1 6
// 4
// 1000000000 999999999 1000000000 999999999
// OutputCopy
// 0
// 13
// 2999999999
// Note
// For the first test case, since there is no field with an odd number of dandelions, FJ can never turn his lawnmower on. Since his lawnmower is always off, he can never cut any dandelions, so the answer is 0
// .

// For the second test case, FJ can visit the third field first; then his lawnmower will turn on. Then he can visit the other fields in any order. Since his lawnmower is always on, dandelions in every field can be cut.

// For the third test case, FJ can visit the fields in the following order: field 2
// , field 1
// , field 3
// , then field 4
// .









// My approach

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> odd, even;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            if (x % 2 == 0)
                even.push_back(x);
            else
                odd.push_back(x);
        }

        if (odd.empty()) {
            cout << 0 << "\n";
            continue;
        }

        sort(odd.begin(), odd.end(), greater<long long>());

        long long ans = 0;

        int take = (odd.size() + 1) / 2;
        for (int i = 0; i < take; i++) {
            ans += odd[i];
        }

        for (long long x : even) {
            ans += x;
        }

        cout << ans << "\n";
    }

    return 0;
}