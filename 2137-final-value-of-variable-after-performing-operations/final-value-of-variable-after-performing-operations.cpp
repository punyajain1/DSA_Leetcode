class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto it:operations){
            if(it=="X++") x++;
            if(it=="++X") ++x;
            if(it=="X--") x--;
            if(it=="--X") --x;
        }
        return x;
    }
};