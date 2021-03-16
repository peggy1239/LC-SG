class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        
        int NumOfZero = 0;
        int idx;
        
        for( vector<int>::iterator it = nums.begin(); it != nums.end(); ){
            
            if(idx == nums.size()) break;
            if(*it == 0) {
                //prev = *it;
                nums.erase(it);
                nums.push_back(0);
                NumOfZero++;
            }
            else it++;
            
            idx++;
            
            
        }
        
        
    }
};

