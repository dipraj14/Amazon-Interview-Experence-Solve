// using greedy ---> 
//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 

/*
Time Complexity: O(N log N) + O(N*M).

O(N log N ) for sorting the jobs in decreasing order of profit. O(N*M) since we are iterating 
through all N jobs and for every job we are checking from the last deadline, say M deadlines 
in the worst case.

Space Complexity: O(M) for an array that keeps track on which day which job is performed if M 
is the maximum deadline available.
*/
/*
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

bool comp(Job a , Job b){
        return a.profit > b.profit;  // 70, 60  --> 70 > 60 
}
class Solution 
{
    
    public:
    //Function to find the maximum profit and the number of jobs done
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
    // step 1 sort the job array
        sort(arr, arr + n, comp);
    
    // step 2--> check maxi deadline
        int maxi = arr[0].dead;
        for(int i= 1; i<n; i++){
            maxi = max(maxi , arr[i].dead);
        }
        int slot[maxi + 1];
        
        for(int i=0; i<=maxi; i++){
            slot[i] = -1;
        }
        
        int cnt = 0;
        int maxi_profit = 0;
        
        for(int i=0; i<n; i++){
            for(int j = arr[i].dead; j> 0; j--){
                if(slot[j] == -1){
                    slot[j] = arr[i].id;
                    cnt++;
                    maxi_profit += arr[i].profit;
                    break;
                }
            }
        }
        
        vector<int> ans;
        ans.push_back(cnt);
        ans.push_back(maxi_profit);
        
        return ans;
        
    } 
};
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}
*/

// optimal solution -->

// using Dsu -->

//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
class DSU {
    private:
    vector<int> parent, size;
    public:
    DSU(int n){
        for(int i=0; i<=n; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int find_p(int n){
        if(parent[n] == n){
            return n;
        }
        return parent[n] = find_p(parent[n]);
    }
    void union_s(int u, int v){
        // int pu = find_p(u);
        // int pv = find_p(v);
        
        // if(pu == pv){
        //     return;
        // }
        // if(size[pu] < size[pv]){
        //     parent[pu] = pv;
        //     size[pv] += size[pu];
        // }
        // else{
        //     parent[pv] = pu;
        //     size[pu] += size[pv];
        // }
        parent[v] = u;
    }
};

class Solution 
{
    
    public:
    bool static comp(Job a , Job b){  // always use static key word interms to make comperator iinside the class
        return a.profit > b.profit;  // 70, 60  --> 70 > 60 
    }
    //Function to find the maximum profit and the number of jobs done
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
    // step 1 sort the job array
        sort(arr, arr + n, comp);
    
    // step 2--> check maxi deadline
        int maxi = arr[0].dead;
        for(int i= 1; i<n; i++){
            maxi = max(maxi , arr[i].dead);
        }
       DSU dsu(maxi);
       int cnt = 0;
       int maxiProfit = 0;
       for(int i=0; i<n; i++){
           int avibSlot  =  dsu.find_p(arr[i].dead);
           if(avibSlot > 0 ){
               dsu.union_s(dsu.find_p(avibSlot - 1), avibSlot);
               cnt++;
               
               maxiProfit += arr[i].profit;
           }
       }
       
       
           vector<int> ans;
        ans.push_back(cnt);
        ans.push_back(maxiProfit);
        return ans;
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends