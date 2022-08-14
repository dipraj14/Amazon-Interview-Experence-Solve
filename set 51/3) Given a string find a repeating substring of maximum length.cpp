/*
This Question have 2 variation  ->>

1) Longest repeating and non-overlapping substring -> https://www.geeksforgeeks.org/longest-repeating-and-non-overlapping-substring/

Input : str = "banana"   // anana  -> a is common b/w two substring --> ana , ana so remove a 
Output : an 
         or na

2) Longest Duplicate Substring -> https://leetcode.com/problems/longest-duplicate-substring/ 
Input: s = "banana"   // overlapping also include 
Output: "ana"

*/

// Longest Duplicate Substring
// more help -> check this -> https://www.youtube.com/watch?v=FQ8hcOOzQMU

// LCS approch but it gives TLE
/*
class Solution {
public:
    string longestDupSubstring(string s) {
        
           int n=s.size();
          vector<vector<int>> mem(n+1,vector<int>(n+1,0));
          int x=0;
          int y=0;
          for(int i=1;i<n+1;i++)
          {
              for(int j=1;j<n+1;j++)
              {
                  if(s[i-1]==s[j-1] && i!=j)
                  {
                      mem[i][j]=1+mem[i-1][j-1];
                      if(mem[x][y]<mem[i][j]) //To get the last index of longest substring
                      {
                          x=i;
                          y=j;
                      }
                      
                  }
                  else
                  {
                      mem[i][j]=0;
                  }
              }
          }
          string s2;
          int i=x;
          int j=y;
          while(i>0 && j>0)
          {
              if((mem[i-1][j-1]+1)==mem[i][j] && mem[i][j] !=0)
              {
                  s2.push_back(s[i-1]);
                  i--;
                  j--;
              }
              else
              {
                  break;
              }
          }
          reverse(s2.begin(),s2.end());
          return s2;
        
    }
};
*/
// optimal one 
#define p 10000007   // binary search + rolling hash  ---> tc -> log n * n * log n 
class Solution {
    vector<int> roll;
public:
    bool match(string s, int len, int size, string &ans){
        unordered_map<int, vector<int> > mp;
        
        int hash = 0;
        for(int i=0; i< size; i++){
            hash = (hash * 26 + (s[i] - 'a'))%p; 
        }
        mp[hash].push_back(0);
        
        for(int j = size; j<len; j++){
            hash =((hash - roll[size - 1] * (s[j - size] - 'a'))%p + p)%p;
            hash = (hash * 26 + (s[j] - 'a'))%p;
            
            if(mp.find(hash) != mp.end()){
                for(auto it: mp[hash]){
                    string temp = s.substr(it, size);
                    string curr = s.substr(j - size + 1, size);
                    if(temp.compare(curr) == 0){
                        ans = temp;
                        return true;
                    }
                }
            }
            mp[hash].push_back(j - size + 1);
        }
        
        return false;
    }
    string longestDupSubstring(string s) {
       int n = s.size();
        if(n == 0){
            return "";
        }
        
        roll.resize(n);
        roll[0] = 1;
        for(int i=1; i<n; i++){
            roll[i] = (26 * roll[i - 1])%p;
        }
        int low = 1;
        int high = n;
        string ans = "",temp;
        int mid;
        while(low <= high){
            temp = "";
            
             mid = low + (high - low) / 2;
            
            bool flag = match(s, n, mid, temp);
            if(flag){
                if(temp.size() > ans.size()){
                    ans = temp;
                }
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return ans;
        
    }
};