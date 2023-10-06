#include<iostream>
using namespace std;
// int unique(int arrp, int n);

int setBit(int n, int pos){
    return (n & (1<<pos)!=0);
}

void unique(int arr[], int n){

    int position =0;
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum = xorsum^arr[i];
    }

    int tempxor=xorsum;
    int setbit=0;
    while(setbit!=1){
        setbit = xorsum & 1;
        position++;
        xorsum = xorsum>>1;
    }

    int newxor=0; 

    for(int i=0; i<n;i++){
        if(setBit(arr[i],position-1)){
            newxor =newxor^arr[i];
        }
    }
    cout<<newxor;
    cout<<(tempxor^newxor);
    

}

int main(){

    int arr[]= {1,2,3,4,3,2,1,5};
    unique(arr,8);
    return 0;
}

