class Solution {
  public:
    // Function to find the length of longest increasing subarray
    int lenOfLongIncSubArr(vector<int> &arr) {
        int left = 0, right = 1, arrSize = arr.size(),
        length = 0, result = 0;
        
        if(arrSize == 1){
            return 1;
        }
        
        for(right = 1; right < arrSize; right++){
            length = right - left;
            result = max(length, result);
            if(arr[right] <= arr[right-1]){
                left = right;
            }
            length = right - left + 1;
            result = max(length, result);
        }
        return result;
    }
};