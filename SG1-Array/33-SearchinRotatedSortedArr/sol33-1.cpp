class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(target >= nums[0]){
            for(int i=0;i<nums.size();i++){
                if(target == nums[i]) return i;
                else if(nums[i] < nums[0]) return -1;
            }  
        }
        else{
            for(int i=nums.size() - 1;i >= 0;i--){
                if(target == nums[i]) return i;
                else if(nums[i] > nums[0]) return -1;
            } 
        }
        return -1;
    }
};