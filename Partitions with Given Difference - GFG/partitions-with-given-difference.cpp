//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=(int)1e9+7;
int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
  
    if(ind == 0){
             if(target==0 && arr[0]==0){
                return 2;}
            if(target==0 || target == arr[0]){
                return 1;}
            return 0;
        
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = (findWaysUtil(ind-1,target,arr,dp));
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken)%mod;
}
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
           int tot=accumulate(arr.begin(),arr.end(),0);
         int k=(tot-d)/2;
         
        if((tot-d)%2==0 && tot-d>=0 ){
           vector<vector<int>> dp(n,vector<int>(k+1,-1));
           return findWaysUtil(n-1,k,arr,dp);}
        else
           return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends