class Solution {
public:
    
bool canJump(vector<int> nums) {
        //if we have no zeros then we can go to last
        //else we have to see previous indices of continuous k zeros,
        //i.e. if previous values are greater that k+1, k+2 etc till start index

        bool isValid = true;
        if (nums.size()==1) return isValid;
        for (int index =0; index < nums.size(); ++index) {
            int count0fromhere = 0;
            int preserve_index = index;
            if (nums[index] == 0) {
                
                int temp_index = index;
                while(temp_index < nums.size() && nums[temp_index] == 0) {
                    ++count0fromhere;
                    ++temp_index;
                }
                if (index != temp_index)
                    index = temp_index -1;

                //go from here till you get a required value
                temp_index = preserve_index -1;
                int count_back = 1;
                int count_back_when_last0 = 0;
                while(temp_index >= 0) {
                  
                    if (nums[temp_index] >= count0fromhere+count_back) {
                        isValid &= true;
                        break;
                    }
                    if (nums[nums.size()-1] == 0 && (temp_index + count0fromhere+count_back >= nums.size())) {
                       //temp_index + count0fromhere+count_back >= nums.size()) 
                       if (nums[temp_index] >= count0fromhere+count_back_when_last0) {
                          isValid &= true;
                          break; 
                       }
                       count_back_when_last0++;
                   }
                   ++count_back;
                   --temp_index;
                }
                if (temp_index == -1) {
                    isValid &= false;
                }
            }
        }
        
        return isValid;
    }

};