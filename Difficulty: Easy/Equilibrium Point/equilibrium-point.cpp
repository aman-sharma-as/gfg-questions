//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    // arr: input array
    int equilibriumPoint(vector<long long> &a) {
        // Your code here
        // int size = arr.size();
        // if(size == 1){
        //     return 1;
        // }
        
        // int leftPointer = 0, rightPointer = size-1;
        // long long sumLeft = arr[leftPointer], sumRight = arr[rightPointer];
        
        // while(leftPointer != rightPointer){
        //     if(sumLeft == sumRight && leftPointer == rightPointer - 2){
        //         return leftPointer + 2;
        //     }
        //     else if(sumLeft == sumRight && leftPointer == rightPointer){
        //         return leftPointer + 1;
        //     }
            
        //     else if(sumLeft < sumRight){
        //         leftPointer++;
        //         sumLeft += arr[leftPointer];
        //     }
        //     else if(sumLeft > sumRight){
        //         rightPointer--;
        //         sumRight += arr[rightPointer];
        //     }
            
        // }
        // return -1;
        
         int n=a.size();
        int i=0,j=n-1;
        long long sumf=a[i],sume=a[j];
        
        while(i!=j)
        {
            if(sumf==sume && i==j-2)
           {
               return i+2;
           }
           else if(sumf==sume && i==j)
           {
               return i+1;
           }
            else if(sume>sumf)
            {
                i++;
                sumf=sumf+a[i];
            }
            else
            {
               j--;
                sume=sume+a[j]; 
            }
        }


        if(sumf==sume && i==j)
           {
               return i+1;
           }
        return -1;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<long long> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.equilibriumPoint(arr) << endl;
    }
}
// } Driver Code Ends