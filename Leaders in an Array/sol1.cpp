#include <iostream>
#include <algorithm>
using namespace std;

bool check(int x ,vector<int>& v2){
    auto it=find(v2.begin(), v2.end(), x);
    int a=it-v2.begin();
    if(it == v2.end()) return false;
    for(int i=a+1;i<v2.size();i++){
        if(a<v2[i]) return false;
    }
    return true;

}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> ans;
    for(int i=0;i<v.size();i++){
        if(check(v[i],v)){
            ans.push_back(v[i]);
        }
    }for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;

}

//not optimal