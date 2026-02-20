// A game is being played which initially consists of n
//  players. On fouls, the referee is allowed to award yellow and red cards. The total number of yellow cards y
//  and red cards r
//  awarded to players is known for the game.

// There are 2
//  ways a player can be suspended:

// Receiving a red card.
// Receiving 2
//  yellow cards.
// Once a player is suspended, they are removed from the game and can't receive any more cards. Determine the maximum number of players suspended from the game possible.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤500
// ). The description of the test cases follows.

// The first line of each test case contains an integer n
//  (1≤n≤100
// ).

// The second line of each test case contains two integers y
//  and r
//  (0≤r≤n
// , 0≤y+r≤2n
// ).

// Output
// For each test case, print one line containing a single integer — denoting the maximum number of players suspended from the game possible.

// Example
// InputCopy
// 5
// 3
// 1 2
// 2
// 0 0
// 4
// 6 0
// 3
// 3 3
// 10
// 11 5
// OutputCopy
// 2
// 0
// 3
// 3
// 10
// Note
// For the first test case:

// One of the possible ways to achieve maximum: Player 2
//  receives a red card, Player 3
//  receives a yellow card followed by a red card.
// This way Player 2
//  and 3
//  are suspended.
// For the second test case:

// No cards are awarded at all, so no one is suspended.
// For the third test case:

// One of the possible ways to achieve maximum: Player 1
//  receives 2
//  yellow cards, Player 2
//  receives 2
//  yellow cards, and Player 4
//  receives 2
//  yellow cards.
// This way Player 1
// , 2
// , and 4
//  are suspended.








#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n, y, r;
        cin>>n;
        cin>>y>>r;
        
        int sus = r + y/2;
        
        if(sus > n) sus = n;
        
        cout<<sus<<"\n";
    }
    
    return 0;
}