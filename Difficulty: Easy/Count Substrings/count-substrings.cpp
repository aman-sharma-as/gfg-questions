// User function template for C++
class Solution {
  public:

    int countSubstr(string S) {
        int count = 0;
        int onesInWindow = 0;
        
        for(int right = 0; right < S.size(); right++) {
            if(S[right] == '1') {
                count += onesInWindow;
                onesInWindow++;
            }
        }
        
        return count;
    }
};