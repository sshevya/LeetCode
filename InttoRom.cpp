class Solution {
public:
    string intToRoman(int num) {
     
        
        vector<string> m={"","M", "MM", "MMM", "MMMM"};
        vector<string> c={"","C", "CC", "CCC", "CD", "D", "DC", "DCC","DCCC", "CM"};
        vector<string> t={"","X", "XX", "XXX", "XL", "L", "LX", "LXX" ,"LXXX", "XC"};
        vector<string> u={"","I","II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string th=m[num/1000];
        string h=c[(num%1000)/100];
        string tn=t[(num%100)/10];
        string un=u[num%10];
        string s=th+h+tn+un;
        
        return s;
        
        
        
    }
};
