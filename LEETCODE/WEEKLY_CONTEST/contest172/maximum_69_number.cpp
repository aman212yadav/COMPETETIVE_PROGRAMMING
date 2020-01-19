// problem link - https://leetcode.com/contest/weekly-contest-172/problems/maximum-69-number
// time complexity - O(no of digits)
class Solution {
public:
    int maximum69Number (int num) {
        int p=log10(num),sum=0;
        long long po=pow(10,p);
        while(num>0){
            int k=num/po;
            if(k==6){
                sum+=9*po;
                num=num%po;
                po=po/10;
                break;
            }
               sum+=9*po;
                num=num%po;
                po=po/10;

        }
        sum+=num;
        return sum;

    }
};
