# 26 Remove Duplicates from Sorted Array


### Method 1 : simple but wasting time

#### algo: 
> 使用iterator go through array，將重複的值erase掉

#### remind: 
> 值得注意的是，使用 vector.erase(it)時，會直接把後面的往前推一個，也就是此it會直接指向下一個值，若是使用for loop中常用的it++，就會skip掉需要檢查的值，因此只有在不需要erase的條件式下，需要it++。

* runtime: **132ms** faster than **20.65%** 
* memory : == 13.7MB == less than == 50.4% ==

``` c++
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

```




### Method 2 : C++ STL 2 lines sol

#### algo: 
> std::unique是在<algorithm>中的函式，其功能是 == 可以刪除連續序列的副本 == 


#### remind: 
> unique是將不重複的元素放到陣列的最後，因此capacity並沒有變，因此需要erase
> unique回傳的是 == 第一個重複值的it ==

runtime: == 4ms == faster than == 99.05% ==
memory : == 13.7MB == less than == 50.4% ==

```c++

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        nums.erase( unique( nums.begin(), nums.end() ), nums.end() );
        
        return nums.size();
    }
    

};


```


### Summary
