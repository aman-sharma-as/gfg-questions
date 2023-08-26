//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    private:
    bool isKnows(vector<vector<int> >& M, int a, int b){
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        // Step 1: Creating and pushing values to stack
        for(int i = 0; i < n; i++){
            s.push(i);
        }
        
        // Step 2: Checking for the potential candidate
        // and pushing again back to stack
        int a , b;
        while(s.size() != 1){
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            
            if(isKnows(M, a, b))
                s.push(b);
                
            else
                s.push(a);
        }
        
        
        // Step 3: Final Check is the candidate is celebrity or not
        // and returning the value accordingly
        int ans = s.top();
        int zeroCount = 0;
        for(int i = 0; i < n; i++){
            if(M[ans][i] == 0)
                zeroCount++;
        }
        if(zeroCount != n)
            return -1;
        
        int oneCount = 0;
        for(int i = 0; i < n; i++){
            if(M[i][ans] == 1)
                oneCount++;
        }
        if(oneCount != n-1)
            return -1;
            
        return ans;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends