# 283 Move Zeroes


### Method 1 : simple but wasting time

#### algo: 
> 使用iterator go through array，遇到0就把他erase掉，再從最後的地方插入。

#### remind: 
> 值得注意的是，使用 vector.erase(it)時，會直接把後面的往前推一個，也就是此it會直接指向下一個值，若是使用for loop中常用的it++，就會skip掉需要檢查的值，因此只有在非零的條件式下，需要it++。

* runtime: 20ms 
* memory : 8.8MB

``` c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        //int NumOfZero = 0;
        int idx = 0;
        
        for( vector<int>::iterator it = nums.begin(); it != nums.end(); ){ 
            
            if(idx == nums.size()) break;
            if(*it == 0) {
                //prev = *it;
                nums.erase(it);
                nums.push_back(0);
                //NumOfZero++;
            }
            else it++;
            
            idx++;
        }
        
    }
};

```

### Method 2 : faster with two pointer 

#### algo: 
> 使用快慢雙指針，其中一個（快）遇到零就往前，遇到非零則和另一個指針swap，另外一個（慢）只在swap過後往後移，把非零的數值往前swap以達到目的。


#### remind: 
> 雙指針是一個很實用的演算法。

* runtime: 4ms faster than **94.12%**
* memory : 8.8MB

```c++

void moveZeroes(vector<int>& nums) {

        if (nums.size()==0 || nums.size()==1) return;
        int i = 0;
        int j = 0;
        
        while(j < nums.size()){
           if(nums[j]==0) j++;
           else{
                swap(nums[i],nums[j]);
                i++;j++;
            }
        }

    }

```



### Summary