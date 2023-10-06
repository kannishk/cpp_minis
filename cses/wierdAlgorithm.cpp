#include<iostream>
using namespace std;
void wierdAlgorithm(int n);

int main(){
    // cout<<"enter"<<endl;
     long long int n;
    cin>>n;
    // cout<<n;
    wierdAlgorithm(n);
}

void wierdAlgorithm(int n){
    cout<<n<<" ";
    if(n==1){
        return;
    }else if(n%2==0){
        wierdAlgorithm(n/2);
    }else{
        wierdAlgorithm((n*3)+1);
    }
}