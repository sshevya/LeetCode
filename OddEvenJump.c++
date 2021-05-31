class Solution {
public:
    
    
    
    
    
    int oddEvenJumps(vector<int>& arr) {
        
        int n = arr.size();
        
        map<int, int> m;
        m[arr[n-1]] = n-1;
        vector<int> nextGr(n,-1);
        vector<int> nextSm(n,-1);
        vector<bool> oddstart(n,0);
        vector<bool> evenstart(n,0);
        
        /*lower_bound returns iterator "it" of just equal value or just greater if equal does not exist
          hence for oddjump we simply find lower bound. 
          Now in even jump for just smaller value, we decrement this "it". But if it initially points to
          an elt which is equal to current elt, then decrement is not required, hence we first increment it in this case, 
          then in next step for all values we find prev(it)
        
        */
        for(int i=n-1;i>=0;i--){
           auto o = m.lower_bound(arr[i]);
           if(o!=m.end()){
               nextGr[i] = o->second;
           }else{
               nextGr[i]=-1;
           } 
            
            if(o!=m.end() && o->first == arr[i]){
                o++;
            }
            
            if(o!=m.begin()){
                nextSm[i] = prev(o)->second;
            }else{
                nextSm[i]=-1;
            }
            
            m[arr[i]]=i;
            
            
        }
        
        int count =1;
        
        oddstart[n-1]=1;
        evenstart[n-1]=1;
        
        for(int i=n-2;i>=0;i--){
            //cout<<nextGr[i]<<" "<<nextSm[i]<<" ";
            if(nextSm[i]!=-1){
                evenstart[i]=oddstart[nextSm[i]];
            }
            
            if(nextGr[i]!=-1){
                oddstart[i]=evenstart[nextGr[i]];
            }
            
            if(oddstart[i]){
                count++;
            }
            
            
            
            
            
        }
        
        
        return count;
    }
};
