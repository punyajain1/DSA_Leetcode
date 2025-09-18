class Solution {
public:
vector<vector<string>>ans;
vector<int>car;
int n;
bool issafe(int r,int c){
    for(int pr=0;pr<r;pr++){
        int pc=car[pr];
        if(pc==c)
        return false;
        if(abs(pc-c)==abs(pr-r))
        return false;

    }
    return true;
}

void backtrack(int r){
    if(r==n){
             vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n;i++)
             board[i][car[i]] = 'Q';
            ans.push_back(board);
            return;
    }
    for(int c=0;c<n;c++){
        if(issafe(r,c)){
            car[r]=c;
            backtrack(r+1);
        }
    }
}
    vector<vector<string>> solveNQueens(int N) {
        n=N;
        ans.clear();
        car.assign(n,-1);
        backtrack(0);
        return ans;
    }
};