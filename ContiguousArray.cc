class Solution {
public:
    int findMaxLength(vector<int> nums) {
        if (nums.size() <= 1) return false;
        unordered_map<int, int> hashMap; 
        int n = nums.size();
        int sum = 0;
        int max_len = 0;
        int ending_index = -1; 
  
        for (int i = 0; i < n; i++) 
            nums[i] = (nums[i] == 0) ? -1 : 1; 
  
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (sum == 0) { 
                max_len = i + 1; 
                ending_index = i; 
            }
  
            if (hashMap.find(sum) != hashMap.end()) { 
                if (max_len < i - hashMap[sum]) { 
                    max_len = i - hashMap[sum]; 
                    ending_index = i; 
                } 
            } 
            else { 
                hashMap[sum] = i; 
            }
        }
        return max_len; 
    }

};