class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0,msum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        msum=sum;
        int r=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--){
            sum=(sum-cardPoints[i])+cardPoints[r];
            msum=max(msum,sum);
            r--;
        }
        return msum;
    }
};