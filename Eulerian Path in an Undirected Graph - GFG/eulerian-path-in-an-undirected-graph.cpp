//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int eulerPath(int N, vector<vector<int>> graph){
        // code here
        int odd=0;
        for(int i=0;i<graph.size();i++){
            int cnt=0;
            for(int j=0;j<graph[0].size();j++){
                if(graph[i][j]%2!=0){
                    cnt++;
                }
            }
            if(cnt%2!=0){
                odd++;
            }
        }
        if(odd==2){
            return 1;
        }else{
            return 0;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j = 0;j < N;j++)
                cin>>graph[i][j];
        
        Solution ob;
        cout<<ob.eulerPath(N, graph)<<"\n";
    }
    return 0;
}
// } Driver Code Ends