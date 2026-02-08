// Peter drew a table of size h×l
// , filled with zeros. We will number its rows from 1
//  to h
//  from top to bottom, and columns from 1
//  to l
//  from left to right. Ned came up with an array of numbers a1,a2,…,an
//  and wanted to modify the table.

// Ned can choose 2k≤n
//  numbers from his array and split them into k
//  pairs. After that, for each resulting pair x,y
// , he takes the cell located in row x
//  and column y
// , and adds 1
//  to the number in that cell. If such a cell does not exist, then this pair does nothing to the table.

// Peter supported Ned's initiative and asked him to maximize the sum of the numbers in the table. Help Ned understand what the maximum sum he can achieve is.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤500
// ). The description of the test cases follows.

// The first line of each test case contains three integers n
// , h
// , and l
//  (2≤n≤100
// , 1≤h,l≤1000
// ) — the size of the array, the height of the table, and the width of the table, respectively.

// The second line of each test case contains n
//  numbers a1
// , a2
// , …
// , an
//  (1≤ai≤1000
// ) — the array itself.

// Output
// For each test case, output the maximum possible sum of the numbers in the table.

// Example
// InputCopy
// 7
// 2 1 1
// 1 1
// 5 2 2
// 1 2 2 3 2
// 8 4 2
// 7 2 2 2 3 4 4 2
// 7 3 6
// 10 4 1 3 5 4 6
// 2 4 4
// 5 5
// 7 6 3
// 10 4 1 3 5 4 6
// 4 1 1
// 1 1 1 1
// OutputCopy
// 1
// 2
// 3
// 2
// 0
// 2
// 2
// Note
// In the first test case, Ned can take the pair (1,1)
//  and add 1
//  to the number located in row 1
//  and column 1
// .

// In the second test case, Ned can take the numbers 1,2,2,2
//  and pair them as follows: (1,2),(2,2)
// . Then, in two cells of the table, there will be a 1
// , and the sum will be equal to 2
// . It can be shown that it is not possible to achieve a higher sum.

// In the fifth test case, the only pair that Ned can take is (5,5)
// . Since such a cell does not exist in the table, the sum of the numbers in the table cannot exceed 0
// .

// In the seventh test case, Ned can pair the numbers like this: (1,1),(1,1)
// . Then the only cell in the table will contain the number 2
// , and the sum will also be 2
// . It can be shown that it is not possible to achieve a higher sum.








#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, h, l;
        cin >> n >> h >> l;

        int rowCount = 0, colCount = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x <= h) rowCount++;
            if (x <= l) colCount++;
        }

        int maxPairs = min({rowCount, colCount, n / 2});
        cout << maxPairs << "\n";
    }
}