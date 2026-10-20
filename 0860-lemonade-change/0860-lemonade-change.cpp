class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        int n = bills.size();
        for(int i=0;i<n;i++){
            int money = bills[i];
            if(money==5){
                five++;
            }
            else if(money==10){
                if(five==0) return false;
                    five--;
                    ten++;
            }
            else{ //money==20
               if(ten>0){ // choice1
                    ten--;
                if(five==0) return false;
                    five--;
               }
               else{ //choice2
                  if(five<3) return false;
                   five = five-3;  
               } 
            }
        }
        return true;
    }
};