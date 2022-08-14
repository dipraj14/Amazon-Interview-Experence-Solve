

# include<bits/stdc++.h>
using namespace std;
string reverse_(string s){
    stack<char> st;
    for(auto it : s){
        st.push(it);
    }
    string ans = "";
    while(!st.empty()){
        ans+= st.top();
        st.pop();
    } 
    return ans;
}
int main(){
    string s;
    getline(cin, s);

    string ans = reverse_(s);

    cout << ans << endl;
}