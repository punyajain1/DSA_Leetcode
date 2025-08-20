#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> ans;
    reverse(v.begin(),v.end());
    int maxi=v[0];
    ans.push_back(maxi);
    for(int i=1;i<n;i++){
        if(v[i]>maxi){
            ans.push_back(v[i]);
            maxi=v[i];
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;

}