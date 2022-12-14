/*
Given an array of 0’s and 1’s again and a variable k, 
print the size of the smallest window which contains exact k 0’s.
*/

// 12 3
// 1 0 1 0 1 0 0 1 1 0 1 0
// explanation --> [0 1 0 0] --> [3  - 6] ---> gives window size 4

//BUT below the code output will be ---> 5

// RESONE OF FAILURE

// This sloution faild because its does't check intermidite zeros of eversy window

/*
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    
    for(int i=0; i<n; i++) cin >> nums[i];
    
    int curr0 = 0;
    int mini = INT_MAX;
    int fast0 = - 1;
    int last0 = -1;
    for(int i=0; i<n; i++){
        
        if(nums[i] == 0){
            if(curr0 == 0){
                 fast0 = i;
            }
            curr0++;
        }
        
        if(curr0 == k){
            last0 = i;
            mini = min(last0 - fast0, mini);
            fast0 = -1;
            
            curr0 = 0;
        }
    }
    
    cout << curr0 << " " << fast0 <<" "<< last0<<endl;
     if(fast0 != -1 && (curr0 + 1) == k){   // for --> 0 1 0 0 1 test case when k's value 2 then fast window 0 1 0 itration count0 --> 0 and fasti-> 3
    // and lasti --> 2 indicate there was another 0 in fasti index and lasti indicate last zero of last window. and mini --> 2
         mini = min(fast0 - last0, mini);
     }
    
    cout << mini + 1 << endl;

    return 0;
}
*/

// optimal solution till now 


#include <bits/stdc++.h>
using namespace std;
int helper(int nums[], int n, int k)
{
    int curr0 = 0;
    int mini = INT_MAX;
    int fast0 = -1;
    int flag = 1;
    int interMideat0 = -1;
    int flg1 = 1;
    
    for(int i=0; i<n; i++){
        if(nums[i] == 0){
            if(flag == 1){
                fast0 = i;
                flag = 0;
            }
            
            curr0++;
            if(curr0 == 2){
                interMideat0 = i;
            }
        }
        
        if(curr0 == k){
            mini = min(i - fast0 + 1, mini);
           // cout << interMideat0 <<" ";
            
            
            if(interMideat0 > fast0 && interMideat0 < i){
                curr0 = 2;
            }else{
                curr0 = 1;
            }
            fast0 = interMideat0;
            if(curr0 == k){
                mini = min(i - fast0 + 1, mini);
            }
            if(curr0 == 2){
                interMideat0 = i;
            }
        }
        
    }
    
    return mini;
   
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    
	cout <<  helper(arr, n, k);
	
	return 0;
}

// 12 3
// 1 0 1 0 1 1 0 1 0 1 0 0
