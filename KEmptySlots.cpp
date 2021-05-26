
/*
map days with index ;

starting with i =1, take two values days[i] & days[i+k+1] because difference between flowers should be k. Also all flowers in this range should be unbloomed
so that means all floers in this range should have greater index. traverse from days[i+1] to days[i+k] and see if index is smaller than max(days[i], days[i+k+1])
if, yes, break, if no update res;
 
*/


public int kEmptySlots(int[] flowers, int k) {
    int[] days = new int[flowers.length + 1];
    for (int i = 0; i < flowers.length; i++) {
        days[flowers[i]] = i + 1; //marking  index
    }
 
    int result = Integer.MAX_VALUE;
 
    for (int i = 1; i < days.length - k - 1; i++) {
        int l = days[i]; //index of one flower
        int r = days[i + k + 1]; //index of other flower with diff k unit
 
        int max = Math.max(l, r); //greater index, index of all other should be less than this
        int min = Math.min(l, r);
 
 
        boolean flag = true;
        for (int j = 1; j <= k; j++) {
            if (days[i + j] < max) {
              //any flower is blooming because its index is less, hence break loop and dont update res
                flag = false;
                break;
            }
        }
 
        if (flag && max < result) {
            result = max;
        }
    }
 
    return result == Integer.MAX_VALUE ? -1 : result;
}
