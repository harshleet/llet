//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
int first(vector<int>&arr, int low, int high, int x)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), high, x);
        else
            return first(arr, low, (mid - 1), x);
    }
    return INT_MIN;
}
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int maxi=-1e7;
	    int ans=-1;
	    for(int i=0;i<n;i++){
	        int a=first(arr[i],0,m-1,1);
	        int t=m-a;
	        if(maxi<t){
	            maxi=t;
	            ans=i;
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends