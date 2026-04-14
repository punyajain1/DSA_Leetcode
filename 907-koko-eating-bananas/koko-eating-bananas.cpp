class Solution {
public:
    int calc(vector<int>& piles, int x){
        int th=0;
        for(int pile:piles){
            //here we do this ceil because it gives us the round of value like it it takes 3.5 hour to eat the ile at speed x then we will takr 4 hours because in quest its given tha tthe koko wont start eating new pile in remaing hour of current end (like ager 50 min bhi bache honge to vo new pile nahi chalu kar sakta)
            th+=((long long)pile + x - 1) / x;
        }
        return th;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r=*max_element(piles.rbegin(),piles.rend());
        int l=1;
        while(l<r){
            int mid=l+(r-l)/2;
            int x=calc(piles,mid);
            if(x<=h){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return (int)l;
    }
};