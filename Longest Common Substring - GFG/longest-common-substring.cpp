//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector<int>l;
  int f(string& s1,string& s2,int i,int j,vector<vector<int>>&dp){
           if(i<0 || j<0){
               return 0;
           }
           if(dp[i][j]!=-1){
               return dp[i][j];
           }
           
          
           if(s1[i]==s2[j]){
               return dp[i][j]=1+f(s1,s2,i-1,j-1,dp);
           }
           return dp[i][j]=0;

    }
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    int ans=INT_MIN;
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1]){
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                ans=max(ans,dp[ind1][ind2]);}
            else
                dp[ind1][ind2] = 0;
        }
    }
    if(ans<0){
        return 0;
    }
    return ans;
         
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends