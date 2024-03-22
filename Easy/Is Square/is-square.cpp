//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string isSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        // code here
        if(x1 == x2 && x3 == x4 && y1 == y2 && y3 == y4){
            return "No";
        }
        float d1 = sqrt(pow((y2 - y1),2) + pow((x2 - x1),2));
        float d2 = sqrt(pow((y4 - y3),2) + pow((x4 - x3),2));
        
        if(d2 == d1){
            return "Yes";
        }
        else{
            return "No";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

        Solution ob;
        cout << ob.isSquare(x1,y1,x2,y2,x3,y3,x4,y4) << endl;
    }
    return 0;
}
// } Driver Code Ends