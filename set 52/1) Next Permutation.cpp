// Given a no in string format output another string which is the biggest no formed 
//from using same digits , otherwise print -1:
// 

// https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size(), ind1, ind2;
        bool flag = 0;
        
        for(int i = n -2; i>=0; i--){   // step 1
            if(nums[i] < nums[i + 1]){
                flag = 1;
                ind1 = i;
                break;
            }
        }
        
        if( flag == 0){
            reverse(nums.begin(), nums.end());
            return ;
        }
        
        for(int i=n-1; i>=0; i--){  // step 2
            if(nums[i] > nums[ind1]){
                ind2 = i;
                break;
            }
        }
        
        // ind1 and ind2  --> find 
        
        // step3 --> swap 
        swap(nums[ind1], nums[ind2]);
        
        // step 4 ---> reverse --> ind + 1  to end;
        reverse(nums.begin() + ind1 + 1 , nums.end());
        
       
        
    }
};