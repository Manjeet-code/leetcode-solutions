class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;
        if(n==1) return true;
        int x = log(n)/log(4);
        if(pow(4,x)==n) return true;
        else return false;
    }
};