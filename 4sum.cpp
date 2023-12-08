/****** first sol ************/
/******static cast into long long ******/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int,vector<pair<int,int>>> m;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int p = j+1;
                int q = n-1;
                while(p<q){
                    long long sum = static_cast<long long>(nums[i])+nums[j]+nums[p]+nums[q];
                    if(target==sum){
                        if(i!=p && i!=q && j!=p && j!=q){
                            vector<int> v;

                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[p]);
                            v.push_back(nums[q]);
                            sort(v.begin(), v.end());
                            if(find(ans.begin(),ans.end(),v)==ans.end()){
                                    ans.push_back(v);
                            }
                            p++;
                            q--;
                        }
                        
                    }else if(target>sum){
                        p++;
                    }else{
                        q--;
                    }
                }
                
            }
        }

        return ans;
    }
};







/****** Second sol, this sol gives TLE *******/
class Solution {
public:
   
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        if(nums.size()<4){
            return res;
        }
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<pair<int,int>>> m;
        int sum=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                sum=nums[i]+nums[j];
                if(m.find(target-sum)!= m.end()){
                 for(int k=0;k<m[target-sum].size();k++){

                    int a=m[target-sum][k].first;
                    int b=m[target-sum][k].second;
                    
                    if(a!=i && a!=j && b!=i && b!=j){
                    vector<int> v;
                    v.push_back(nums[a]);
                    v.push_back(nums[b]);
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    sort(v.begin(),v.end());
                    if(find(res.begin(), res.end(), v)==res.end()){
                        res.push_back(v);
                    }
                    }
                    
                }  
                }
                m[sum].push_back(make_pair(i,j));
                
                
                
                
                
            }
           
        }
         return res;
        
        
    }
};
