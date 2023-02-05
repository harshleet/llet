//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int rec(vector<vector<int>>&dp,int ind,int w,int val[],int wt[]){
 	if(ind==0){
              return (((int)(w/wt[0]))*val[0]);
 	}
 	if(dp[ind][w]!=-1){
 		return dp[ind][w];
 	}
 	int ntake=0+rec(dp,ind-1,w,val,wt);
 	
 	int take=0;
 	if(wt[ind]<=w){
 		take=val[ind]+rec(dp,ind,w-wt[ind],val,wt);
 	}
 	return dp[ind][w]=max(take,ntake);
 }
 
 int knapSack(int N, int W, int val[], int wt[])
{
     vector<vector<int>>dp(N,vector<int>(W+1,-1));
     return rec(dp,N-1,W,val,wt);
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends