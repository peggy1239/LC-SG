class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        if(arr.size() < 3) return false;
        
        bool peak = false;
        
        for(int i=0; i< arr.size()-1 ; i++){
            
            if(arr[i+1] == arr[i]) return false;
            
            if(!peak){
                if(arr[i+1] < arr[i] && i!=0) // go down
                    peak = true;
                else if(arr[i+1] < arr[i] && i==0)
                    return false;
                
            }
            else{
                
                if(arr[i+1] > arr[i]) return false;
            }
            
        }
        
        
        return peak;
        
    }
};