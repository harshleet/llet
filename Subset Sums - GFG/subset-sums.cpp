//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
 vector<int>ans;
void rec(int ind,vector<int>&arr,int n,int sum){
        if(n==ind)
           {
                   ans.push_back(sum);
                   sum=0;
                   return;
           }
         
  
  
      rec(ind+1,arr,n,sum+arr[ind]);
   
      rec(ind+1,arr,n,sum);
       

}
 
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        rec(0,arr,N,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends