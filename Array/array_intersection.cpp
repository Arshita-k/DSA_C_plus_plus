#include <iostream>
#include <vector>
using namespace std;
//brute force O(n*m)
vector<int> intersection(vector<int> &arr1,vector<int> &arr2)
{
    vector<int>ans;
    for(int i=0;i<arr1.size();i++)
    {
        for(int j=0;j<arr2.size();j++)
        {
            if(arr1[i]==arr2[j])
            {
                ans.push_back(arr2[j]);
                //update arr2 element to mark that element if accessed already
                arr2[j]=INT_MIN;
                //break the current loop 
                break;
            }
        }
    }
    return ans;
}

// optimal solution  o(max(n,m))
vector<int> intersection2(vector<int> &arr1,vector<int> &arr2)
{
    vector<int>ans;
    int i=0,j=0;
    while(i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]==arr2[j])
        {
            ans.push_back(arr2[j]);
            i++;
            j++;
            
        }
        else if(arr1[i]<arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}
int main()
{
    vector<int>arr1={1,2,3,3,4};
    vector<int>arr2={3,3,4};
    vector<int>result;
    result=intersection(arr1,arr2);
    if(result.empty())
    {
        cout<<-1;
    }
    else
    {
        for(int i=0;i<result.size();i++)
        {
            cout<<result[i]<<" ";
        }
    }
    return 0;

}
