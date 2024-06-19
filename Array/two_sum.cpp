#include <bits/stdc++.h>
using namespace std;

/* two sum problem
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice */

//brute force to compare sum of each pair and key using two loops O(N)
vector<int> TwoSum1(vector<int>&nums,int key)
{
    int size=nums.size();
    vector<int>answer;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(nums[i]+nums[j]==key)
            { 
                answer.push_back(i);
                answer.push_back(j);
                return answer;

            }
        }
    }
    answer.push_back(-1);
    return answer;
}
//hashing O(nlogn)
vector<int> TwoSum2(vector<int>&nums,int key)
{
    int size=nums.size();
    map<int,int>hash; //key = element and value = index of the array
    for(int i=0;i<size;i++)
    {
        int current=nums[i];
        int diff=key-current;
        //Returns the pointer to the given element if present, otherwise, a pointer to the end.
        if(hash.find(diff)!=hash.end())
        {
           cout<<"Yes"<<endl;
           return {i,hash[diff]};
        }
        hash[current]=i; //store the value for future use
    }
    cout<<"No";
    return {-1};
}
//two pointers O(nlogn) sorting

vector<int> TwoSum3(vector<int>&nums,int key)
{
    int size=nums.size();
    int i=0,j=size-1;
    sort(nums.begin(),nums.end());
    while(i<j)
    {
        if(nums[i]+nums[j]==key)
        {
            return {i,j};
        }
        else if(nums[i]+nums[j]<key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return {-1};
}
int main()
{
    vector<int>nums={2,7,11,15};
    int key;
    cout<<"Enter Target : ";
    cin>>key;
    vector<int>result=TwoSum3(nums,key);
    if(result.size()==1 ||result[0]==-1)
    {
        cout<<-1<<endl;
    }
    else
    {
        for(int x:result)
        {
            cout<<result[x]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
