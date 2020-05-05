class Solution {
public:   
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        //use kandane algorithm
        vector<int> maxSum;
        vector<int> currentSum;
        maxSum.push_back(nums[0]);
        currentSum.push_back(nums[0]);
        for (int index =1; index < nums.size(); ++index) {
            int currSum = 0;
            if (currentSum[index-1]+nums[index] > nums[index])
                currSum = currentSum[index-1]+nums[index];
            else
                currSum = nums[index];
            currentSum.push_back(currSum);
            
            if (maxSum[maxSum.size()-1] < currSum)
                maxSum.push_back(currSum);
        }
        return maxSum[maxSum.size()-1];
    }
};