// Today, KQ has an exam at the Grail Academy. A strict teacher gave a task that KQ could not solve. He was given two arrays a
//  and b
//  of length n
// . KQ is allowed to perform the following operations on the arrays:

// Choose an index i
//  (1≤i<n
// ) and replace ai
//  with ai+1
// .
// Choose an index i
//  (1≤i≤n
// ) and replace ai
//  with bi
// .
// Now he has q
//  queries. Each query is described by two numbers l
//  and r
// . His task is to find the maximum value of the sum (al+al+1+al+2+⋯+ar)
//  for each query, if he can perform any number of operations on any elements of the array. Since he is not skilled enough for this, he asks for your help.
// Input
// Each test consists of several test cases. The first line contains one integer t
//  (1≤t≤104
// ) — the number of test cases. The description of the test cases follows.

// The first line of each test case contains two integers n
// , q
//  (1≤n,q≤2⋅105)
// .

// The second line of each test case contains n
//  integers a1,a2,...,an
//  (1≤ai≤104)
// .

// The third line of each test case contains n
//  integers b1,b2,...,bn
//  (1≤bi≤104)
// .

// The following q
//  lines contain two integers l
//  and r
//  (1≤l≤r≤n)
// .

// It is guaranteed that the sum of the values of n
//  and the sum of the values of q
//  across all test cases do not exceed 2⋅105
// .

// Output
// For each test case, output q
//  numbers separated by spaces — the maximum values of the sums (al+al+1+al+2+⋯+ar)
// .

// Example
// InputCopy
// 4
// 3 1
// 3 2 1
// 1 2 3
// 1 3
// 1 1
// 1
// 2
// 1 1
// 3 2
// 6 7 5
// 9 6 8
// 1 2
// 2 3
// 4 3
// 4 3 2 1
// 5 1 3 1
// 1 2
// 2 4
// 3 4
// OutputCopy
// 9
// 2
// 17 16
// 8 7 4
// Note
// Consider the first test case. Replace a3
//  with b3
// , a=[3,2,3]
// . Replace a2
//  with a3
// , a=[3,3,3]
// . The sum a1+a2+a3=9
// .









// Github(Anothers code)

#include <cstdio>
#include <vector>

int main(){
    
    long t; scanf("%ld", &t);
    while(t--){
        long n, q; scanf("%ld %ld", &n, &q);
        std::vector<long> a(n), b(n);
        for(long &x : a){scanf("%ld", &x);}
        for(long &x : b){scanf("%ld", &x);}
        
        a[n - 1] = (a[n - 1] > b[n - 1] ? a[n - 1] : b[n - 1]);
        for(int p = n - 1; p >= 0; p--){
            a[p] = (a[p] > b[p] ? a[p] : b[p]);
            if(p + 1 < n && a[p] < a[p + 1]){a[p] = a[p + 1];}
        }
        
        for(int p = 1; p < n; p++){a[p] += a[p - 1];}
        
        while(q--){
            long left(0), right(0);
            scanf("%ld %ld", &left, &right);
            --left; --right;
            printf("%ld ", a[right] - (left ? a[left - 1] : 0));
        }
        puts("");
        
    }
    
}