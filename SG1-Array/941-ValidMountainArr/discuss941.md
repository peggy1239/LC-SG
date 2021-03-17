# 941 Valid Mountain Array


### Method 1 : simple

#### algo: 
> 從頭go through一次，make sure有達到標準。

* runtime: **28ms** faster than **80.48%** 
* memory : **22.3MB** less than **86.64%**

```c++
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        bool peak = false; // assume it is not a mountain arr
        for(int i=0; i< arr.size()-1 ; i++){
            
            if(arr[i+1] == arr[i]) return false;
            
            if(!peak){
                if(arr[i+1] < arr[i] && i!=0) // go down
                    peak = true;
                else if(arr[i+1] < arr[i] && i==0) // go down from start -> not mountain
                    return false;        
            }
            else{    
                if(arr[i+1] > arr[i]) return false;// already go down but go up again -> not mountain
            }
        }
        return peak;
    }
};
```

### Summary
