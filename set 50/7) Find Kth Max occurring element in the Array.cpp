/*
there was 3 varition of this question -->
1) Find Kth most occurring element in an Array
Input: arr[] = {1, 2, 2, 2, 4, 4, 4, 5, 5, 5, 5, 5, 7, 7, 8, 8, 8, 8}, K = 1 
Output: 5 
Explanation: 
The occurrence of the elements are as follows: 
1 – 1 
2 – 3 
4 – 3 
5 – 5 
7 – 2 
8 – 4 
Clearly, 5 is the most occurring element in the array. 

*/
// Approch 1 --> 
#include <bits/stdc++.h>

using namespace std;

vector<int> helper(vector<int> nums, int k){
    
    unordered_map<int,int> freq;
    for(auto it: nums){
        freq[it]++;
    }

     if(freq.size() < k)
        return {};
    
    vector<int> ans;
    
    map<int, vector<int>> mp;
    
    for(auto it: freq){
        if(mp.find(it.second) == mp.end()){
            mp[it.second].push_back(it.first);
        }
        else{
            mp[it.second].push_back(it.first);
        }
    }
    int cnt = 0;
    
  
    k = mp.size() - k + 1;
    for(auto it: mp){
        cnt++;
        if(cnt == k){
            ans = it.second;
            break;
        }
    }
    
    return ans;
}

int main()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int> nums(n);
    
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    
    
    vector<int> ans = helper(nums, k);
    for(auto it: ans){
        cout << it <<" ";
    }

    return 0;
}
/*
Time Complexity: O(NlogN) + o(N), where N is the size of the given array.

Auxiliary Space: O(N) + o(N), where N is the size of the given array.
*/

//Approch 2 -> optimal 

#include <bits/stdc++.h>

using namespace std;

vector<int> helper(vector<int> nums, int k){
    
    unordered_map<int,int> freq;
    for(auto it: nums){
        freq[it]++; // o(1)
    }
    
    vector<int> ans;
    
    vector<int> mp[nums.size() + 1];
    for(auto it: freq){
        mp[it.second].push_back(it.first); // o(n)
    }
    
    int cnt = 0;
    

  
    // for(int i=0; i<=nums.size(); i++){
    //     cout << i << " -> ";
    //     for(auto it: mp[i]){
    //         cout << it <<" ";
    //     }
    //     cout << endl;
    // }
    
    for(int i= nums.size() ; i>=0; i--){  // o(n)
       for(auto it: mp[i]){
           cnt++;
           break;
       }
       if(cnt == k){
           for(auto it: mp[i]){
               ans.push_back(it);
           }
           break;
       }
      //  cout << i << "->" << cnt <<" ";
    }
  
    return ans;
}

int main()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int> nums(n);
    
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    
    
    vector<int> ans = helper(nums, k);
    for(auto it: ans){
        cout << it <<" ";
    }

    return 0;
}

// tc -- > o(n) + o(1) + o(n)
// sc --> o(n) + o(n)




/*

2) Find k numbers with most occurrences in the given array

Given an array of n numbers and a positive integer k. The problem is to find k numbers with most 
occurrences, i.e., the top k numbers having the maximum frequency. If two numbers have the same
frequency then the larger number should be given preference. The numbers should be displayed in 
decreasing order of their frequencies. It is assumed that the array consists of k numbers with
 most occurrences.

Input : 
arr[] = {7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9},
k = 4
Output: 5 11 7 10
Explanation: 
Frequency of 5 = 3
Frequency of 11 = 2
Frequency of 7 = 2
Frequency of 10 = 1
These four have the maximum frequency and
5 is largest among rest.
*/
// Note -->  // NOTe : c++ sort algo accept when i swap that case return false .... 
/*
comperatot for swap --> opposite of other case
bool comp(int a , int b){   // decresing order  --> 3 2 1
    if(a > b) return true; // 3 > 2
    return false;
}

bool comp(int a , int b){ // incresing ---> 1 2 3 
    if(a < b) return true // 1 < 2 true
    return false;
}
*.

// pls check gfg artical --> https://www.geeksforgeeks.org/find-k-numbers-occurrences-given-array/
for varition 2 . 

/*

3) Top k frequent eliment -->

Given an integer array nums and an integer k, 
return the k most frequent elements. You may return the answer in any order.

https://leetcode.com/problems/top-k-frequent-elements/
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;   // tc --> o(n) + o(n * 1) + o(n) // sc --> o(n) + o(n)
        
        unordered_map<int, int> ump;
        
        for(auto it : nums){
            ump[it]++;
        }
        int n  = nums.size();
        vector<int> freq[n + 1];
        
        for(auto it: ump){
            freq[it.second].push_back(it.first);
        }
        int cnt = 0;
        
        for(int i = n; i>=0; i--){
          
            for(auto it: freq[i]){
                ans.push_back(it);
                cnt++;
            
            }
            
            if(cnt == k){
                    break;
                }
        }
        
        return ans;
        
    }
};
