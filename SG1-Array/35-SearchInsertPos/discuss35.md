# 35 Search Insert Position

### Method 1 : simple and quick!

#### algo: 
> go through if <= 則插入，到最後都沒有<= 代表要插入最後，回傳size。


* runtime: 4ms faster than **90.5 %**
* memory : 9.6MB less than **92.04%**

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        
        for(int i=0; i< nums.size() ; i++){
            
            if(target <= nums[i])
                return i;
            
            
        }
        
        return nums.size();
        
    }
};

```


### Method 2 : Binary Search

#### algo: 
> 運用low,med,high三個指標來比較，能加快搜尋時間，時間複雜度O(logN)，不過在此題效益並不明顯。


* runtime: 4ms faster than **90.5 %**
* memory : 9.7MB less than **46.69%**

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int low = 0;  
        int high = nums.size() - 1;
        int med;
        
       while(low <= high){
           
           med = (low+high)/2;
           
           if(target > nums[med]) low = med+1;
           else if(target < nums[med]) high = med-1;
           else return med;

       }
        
        return low;
    }
};

```