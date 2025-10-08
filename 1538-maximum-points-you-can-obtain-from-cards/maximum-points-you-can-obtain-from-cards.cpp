class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0,msum=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        msum=lsum;
        int r=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            rsum+=cardPoints[r];
            lsum-=cardPoints[i];
            msum=max(msum,lsum+rsum);
            r--;
        }
        return msum;
    }
};