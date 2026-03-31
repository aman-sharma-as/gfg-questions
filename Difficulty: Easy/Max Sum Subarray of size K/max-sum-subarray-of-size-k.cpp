class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int sum = 0, result = INT_MIN, low = 0, high = k - 1,
        arrSize = arr.size();
        
        for(int i = 0; i <= high; i++)
            sum += arr[i];
            
        while(high < arrSize){
            result = max(result, sum);
            low++;
            high++;
            if(high == arrSize)
                break;
            
            sum = sum - arr[low - 1];
            sum = sum + arr[high];
        }
        
        return result;
    }
};