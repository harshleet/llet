//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int mod=1e9+7;
        int sum=accumulate(arr.begin(),arr.end(),0);
        int target=(sum-d)/2;
        if(sum-d <0 || (sum-d)%2 ) return 0;
        vector<vector<long long int>>dp(n,vector<long long int>(target+1,0));
        
        if(arr[0]==0){
            dp[0][arr[0]]=2;
        }else{
            dp[0][0]=1;
        }
        
        if(arr[0]!=0 && arr[0]<=target){
            dp[0][arr[0]]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int ntake=dp[i-1][j];
                int take=0;
                if(arr[i]<=j){
                    take=dp[i-1][j-arr[i]];
                }
                dp[i][j]=(ntake+take)%mod;
            }
        }
        return (dp[n-1][target])%mod;
        
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