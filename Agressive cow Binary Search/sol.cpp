#include <iostream>
using namespace std;

bool dis(vector<int>& v, int mid,int cow){
    int last=v[0];
    int count=1;
    for(int i=1;i<v.size();i++){
        if(v[i]-last >= mid){
            count++;
            last=v[i];
        }
        if(count>=cow) return true;
    }
    return false;
}

int main(){
    int n, ans=-1 , cows=2;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int l=0,h=v.size();
    while(l<h){
        int mid=l+(h-l)/2;
        if(dis(v,mid,cows)==true){
            ans=mid;
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    cout<<ans<<endl;
}