class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0){
            return 0;
        }
        vector<int>::iterator it = nums.begin();
        int prev = *it;
        
        
        
        for( it = nums.begin()+1; it != nums.end();  ){
            
            if(prev ==  *it) {
                //prev = *it;
                nums.erase(it);
            }
            else {
                prev = *it;
                it++;
            }
            
            
        }
        
        return nums.size();
    }
};