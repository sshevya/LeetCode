class Solution {
public:
   
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int total_xor=0;
        int count =0;

        total_xor = 0;

        for(int i=0;i<n;i++){
            int txor=arr[i];
            //cout<<total_xor<<" hgj ";
            for(int j = i+1;j<n;j++){
                    txor^=arr[j];

                if(txor==0){
                    count+=(j-i);
                }
            }
        }


        

        return count;
    }
};
