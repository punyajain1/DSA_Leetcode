class Solution {
public:
    int suma(vector<int>& weights){
        int x=0;
        for(auto it:weights){
            x+=it;
        }
        return x;
    }
    int cdays(int mid,vector<int>& x){
        int count=1;
        int temp=0;
        for(auto it:x){
            if(temp+it>mid){
                count++;
                temp=it;
            }else{
                temp+=it;
            }
        }
        return count;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int h=suma(weights);
        while(l<h){
            int mid=(h+l)/2;
            int x=cdays(mid,weights);
            if(x<=days) h=mid;
            else l=mid+1;
        }
        return l;
    }
};