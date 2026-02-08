// You have n
//  cards arranged in a row. The i
// -th card has the integer ai
//  written on it. All integers are distinct.

// You must color each card either red
//  or blue
//  such that the following conditions are satisfied:

// Any two adjacent cards in the row have different colors.
// If you rearrange the cards so that the numbers on them are in increasing order, any two adjacent cards in the new row must also have different colors.
// Determine if such a coloring exists.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤200
// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
//  (2≤n≤100
// ) — the length of the array.

// The second line of each test case contains n
//  integers a1,a2,…,an
//  (1≤ai≤n
// ).

// It is guaranteed that all elements of a
//  are distinct.

// Output
// For each test case, output "YES" if you can color the cards so that the conditions are satisfied, and "NO" otherwise.

// You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

// Example
// InputCopy
// 4
// 4
// 2 3 4 1
// 3
// 2 3 1
// 5
// 3 4 1 2 5
// 5
// 3 1 4 2 5
// OutputCopy
// YES
// NO
// YES
// NO
// Note
// In the first example, the cards are colored as a=[2,3,4,1]
// . After sorting, the cards become [1,2,3,4]
// . Both sequences satisfy the condition, so the answer is YES.

// In the second example, no valid coloring exists. For instance, if we color the cards as a=[2,3,1]
// , the sorted sequence becomes [1,2,3]
// . Here, the adjacent elements 1
//  and 2
//  have the same color, so the condition is not satisfied.

// In the third example, a possible coloring is a=[3,4,1,2,5]
// . After sorting, the cards become [1,2,3,4,5]
// .










#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, char> color;

        for (int i = 0; i < n; i++) {
            cin >> a[i];

            if (i % 2 == 0)
                color[a[i]] = 'R';
            else
                color[a[i]] = 'B';
        }

        vector<int> sorted = a;
        sort(sorted.begin(), sorted.end());

        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            if (color[sorted[i]] == color[sorted[i + 1]]) {
                ok = false;
                break;
            }
        }

        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
