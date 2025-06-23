#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cout<<"Enter number of elements of number : ";
    cin>>num;
    int arr[num];
    cout<<"Enter array elements  : ";
    for(int i=0;i<num;i++) cin>>arr[i];

    int prefixSum=0,minimumWages=0;
    for(auto n : arr)
    {
        prefixSum+=n;
        if(prefixSum<1)
        {
            prefixSum=-prefixSum;
            minimumWages+=prefixSum;
            prefixSum=0;
            
        }
    }
    cout<<minimumWages<<endl;
    return 0;
}



// Raman was playing a game,  he starts with x coins. Now in every step, he wins and loses and he has to get the money or pay the money as needed. He came in contact with a psychic who can see the future and the Psychic predicted the outcomes after each step. Now Raman wants to start the game with the minimum wage where he doesn’t run out of money.  Help Raman to find what money he should start with. The only rule to keep playing is not going in a credit situation.

// Input Format:

// First line with n, number of steps in the game
// Next n lines, n integers denoting outcomes of every game. Positive means winning and negative means losing that money.
// Output Format:

// One single integer denoting the minimum amount to start with
// Constraints:

// Number of steps<=10^9
// -1000<=Money needed in each step<=1000
// Sample Input:

// 4
// 2
// -9
// 15
// 2

// Sample Output:

// 7

// Explanation:

// If he starts with 7 rupees, then after steps : 7 ->9 -> 0-> 15 -> 17.

