class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int low = 0, high = 0, stringSize = s.size(), result = INT_MIN,
        mapSize = 0, currLength;
        unordered_map<char,int> countFrequency;
        
        for(high = 0; high < stringSize; high++){
            countFrequency[s[high]]++;
            
            while(countFrequency.size() > k){
                countFrequency[s[low]]--;
                if(countFrequency[s[low]] == 0)
                    countFrequency.erase(s[low]);
                low++;
            }
            
            if(countFrequency.size() == k){
                currLength = high - low + 1;
                result = max(result, currLength);
            }
            
        }
        return (result == INT_MIN) ? -1 : result;
    }
};