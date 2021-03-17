# 33 Search in Rotated Sorted Array


### Method 1 : simple but wasting time

#### algo: 
> 先透過判斷 target >= nums[0] 決定要從哪個方向go through， 接著就go through 直到已經到臨界處(pivot)。

* runtime: **4ms** faster than **80.83%** 
* memory : **11MB** less than **79.57%**

``` c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(target >= nums[0]){ // decide which direction to go through
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

```

### Method 2 : C++ STL 

#### algo: 
> 使用內建的 std::find 可以在給定區間內找定值 

* runtime: **4ms** faster than **80.83%%**
* memory : **11.1MB** less than **51.31%**

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<int>:: iterator it=find(nums.begin(),nums.end(),target);
        if(it!=nums.end())
            return it-nums.begin();
        else{
            return -1;
        }
    }
};
```
### Method 3: binary search

#### algo: 
> 二分法，先找出pivot，用pivot的值決定要在哪一個array用二分法，O(lgN)。

* runtime: **0ms** faster than **100%%**
* memory : **11.1MB** less than **79.57%**


```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),left=0,right=n-1;
        if(n<2)
        {
            if(nums[0]==target)
                return 0;
            else
                return -1;
        }
         while (left <= right) {
            int mid = (left + right) / 2;
            // current element > first elemen: we move the window right
            if (nums[mid] >= nums[0]) left = mid + 1;
            // otherwise we move it left
            else right = mid-1;
        }
        if(left>=n) //for edge case
            left-=n;
        if(nums[left]<=target && nums.back()>=target) //If target is between left and target
        {
            right=n-1;
        }
        else {                 
            right=left-1;  // target is between 0 and left
            left=0;
        }
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left=mid+1;
            else{
                right=mid-1;
            }
        }
        return -1;
    }
};
```

### Summary
