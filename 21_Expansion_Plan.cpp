// You are analyzing an infinite grid with coordinates (X,Y)
//  (specifically, the cell immediately above (0,0)
//  is (0,1)
// , and the cell immediately on the right of (0,0)
//  is (1,0)
// ). Initially, only the cell at (0,0)
//  is black.

// You are given a string a1a2…an
//  of length n
//  consisting of characters "4"
//  and "8"
// , which describes n
//  expansion operations. For each i
//  from 1
//  to n
// , the following happens for all cells simultaneously:

// if si="4"
// : for each cell, if it is orthogonally adjacent to a black cell (i.e., it shares a side), it becomes black; otherwise, its state remains the same;
// if si="8"
// : for each cell, if it is orthogonally or diagonally adjacent to a black cell (i.e, it shares a side or a corner), it becomes black; otherwise, its state remains the same.
// Is the cell (x,y)
//  black at the end of the process?

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤104
// ). The description of the test cases follows.

// The first line of each test case contains three integers n
// , x
// , y
//  (1≤n≤2⋅105,−109≤x,y≤109
// ) — the number of expansion operations, and the x
//  and y
//  coordinates of the cell you are interested in, respectively.

// The second line of each test case contains a string s
//  of length n
//  consisting of characters "4"
//  and "8"
//  — the types of expansion operations.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, output YES
//  if the cell (x,y)
//  is black after the expansion operations described by the string s
// , and NO
//  otherwise.

// The judge is case-insensitive (for example, YES
// , Yes
// , yes
// , yEs
//  will all be recognized as positive answers).

// Example
// InputCopy
// 6
// 3 3 3
// 888
// 4 5 1
// 4884
// 4 3 -3
// 4884
// 7 -7 -5
// 4884884
// 10 0 0
// 4884884888
// 1 1 1
// 4
// OutputCopy
// YES
// NO
// YES
// NO
// YES
// NO
// Note
// The first three test cases are illustrated below:


// In the first test case, after the expansion operations in the string "888"
// , cell (3,3)
//  is black, so the answer is YES
// .

// In the second test case, cell (5,1)
//  is white after the expansion operations in the string "4884"
// .







// Purely Clauded coded as i don't know how to solve this 

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        long long n, x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        
        // Count how many '8' (diagonal) expansion steps exist
        long long e = count(s.begin(), s.end(), '8');
        long long ax = abs(x), ay = abs(y);
        
        /*
         * CORE IDEA:
         * We start at (0,0) and expand outward step by step.
         * A cell turns black once it's "reached", and stays black forever.
         * So we just need to check if (x,y) is reachable after ALL n steps.
         * (Checking only at the end works because both conditions below
         *  only get easier to satisfy as n grows — monotonic.)
         *
         * Each step, we move the "frontier" outward by 1.
         * Think of it as: we have n total steps, and we want to reach (x,y).
         *
         * TWO CONSTRAINTS must both be satisfied:
         *
         * --- CONSTRAINT 1: Chebyshev distance ---
         * Chebyshev distance = max(|x|, |y|)
         * Every single step (whether '4' or '8') expands the frontier by
         * at most 1 in Chebyshev distance (i.e., in both x and y direction).
         * So after n steps, the furthest we can be in any axis is n.
         * => max(|x|, |y|) <= n
         *
         * --- CONSTRAINT 2: Manhattan distance ---
         * Manhattan distance = |x| + |y|
         * A '4' step can only move orthogonally, so it contributes at most
         * 1 to Manhattan distance.
         * An '8' step can move diagonally, so it contributes at most 2 to
         * Manhattan distance (e.g., moving from (0,0) to (1,1) in one step).
         *
         * If there are 'e' eights and 'f = n - e' fours:
         *   max Manhattan reachable = 2*e + f = 2*e + (n-e) = n + e
         * => |x| + |y| <= n + e
         *
         * BOTH constraints are necessary and together they are sufficient.
         * If both hold, (x,y) is reachable; otherwise it's not.
         */
        
        if(max(ax, ay) <= n && ax + ay <= n + e)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}