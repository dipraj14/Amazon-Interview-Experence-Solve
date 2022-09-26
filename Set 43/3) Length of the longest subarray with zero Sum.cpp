//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include<bits/stdc++.h>
using namespace std;
int longestSubarryZeroSum(vector<int> &arr, int n){
    int maxi = 0 , sum = 0;
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if(sum == 0){
            maxi = i + 1;
        }
        else{
            if(mp.find(sum) != mp.end()){
                maxi = max(i - mp[sum] , maxi);
            }
            else{
                mp[sum] = i;
            }
        }
    }

    return maxi;
}
int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0 ; i<n ; i++) cin >>  arr[i];

    cout << longestSubarryZeroSum(arr, n);
}