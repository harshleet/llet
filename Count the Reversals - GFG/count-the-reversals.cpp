//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
    stack<char>st;
    vector<char>extra;
    for(int i=0;i<s.length();i++){
       int b=1;
        if(s[i]=='{'){
            st.push('{');
            b--;
        }
        else if(!st.empty() && s[i]=='}' && st.top()=='{'){
            st.pop();
            b--;
        }
        else{
            extra.push_back(s[i]);
        }
    }
    if((st.size()+extra.size())%2!=0){
        return -1;
    }
    map<char,int>m;
    int c=0;
    for(int i=0;i<extra.size();i++){
        m[extra[i]]++;
        
    }
    
    while(!st.empty()){
        m[st.top()]++;
        st.pop();
        
    }
   int ans= (m['{']/2)+(m['{']%2)+(m['}']/2)+(m['}']%2);
   return ans;
    // your code here
}