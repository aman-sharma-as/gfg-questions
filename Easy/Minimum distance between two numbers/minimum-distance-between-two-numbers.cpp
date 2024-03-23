//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int min_distance = INT_MAX;
        int x_position = -1, y_position = -1;
        for(int i = 0; i < n; i++){
            if(a[i] == x){
                x_position = i;
            }
            if(a[i] == y){
                y_position = i;
            }
            if(x_position != -1 && y_position != -1){
                min_distance = min(min_distance, abs(x_position - y_position));
            }
        }
        if(min_distance != INT_MAX){
            return min_distance;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends