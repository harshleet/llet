//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string s;
		    map<char,int>m;
		    queue<int>q;
		   
		   char a;
		  
		    s+=A[0];
		    m[A[0]]++;
		    q.push(A[0]);
		    for(int i=1;i<A.length() ;i++){
		       
		         q.push(A[i]);
		             m[A[i]]++;
		               a=q.front();
		        if(a!=A[i]){
		              s+=a;
		        }
		       else if(a==A[i]){
		             while(!q.empty()&& m[q.front()]>1){
		                 q.pop();
		             }
		             if(q.empty()){
		                 s+='#';
		             }
		             else{
		                 s+=q.front();
		             }
		       }
		    }
		    
		    return s;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends