//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<pair<int,int>>s;
       s.push(make_pair(price[0],1));
       vector<int>v;
       map<int,int>m;
       v.push_back(1);
       for(int i=1;i<n;i++){
           int c=1;
           while(s.empty()==false && s.top().first<=price[i] ){
               c+=s.top().second;
               s.pop();
           }
           v.push_back(c);
           s.push(make_pair(price[i],c));
           c=0;
       }
       return v;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends