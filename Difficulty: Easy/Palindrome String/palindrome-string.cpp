//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    
    int isPalindrome(string s)
	{
	    int length = s.length();
	    
	    if(length == 1)
	        return 1;
	    
	    int leftP = 0, rightP = length-1;
	    
	    while(leftP < rightP){
    	    if(s[leftP] != s[rightP]){
    	        return 0;
    	    }
    	    leftP++;
    	    rightP--;
	    }
	    return 1;
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends