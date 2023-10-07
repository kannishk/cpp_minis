//credit card validator {luhn algo}
#include<iostream>
#include<string>
using namespace std;

bool isNumber(string s){
    int len = s.length();
    for(int i=0;i<len;i++){
        if(s[i]<'0'||s[i]>'9'){
            return false;
        }
    }
    return true;
}

int main(){
    string ccNumber;

    cout<<"Enter exit anytime to quit"<<endl;

    while(true){
        cout<<"enter the cc number"<<endl;
        cin>>ccNumber;

        if(ccNumber=="exit"){
            break;
        }
        else if(!isNumber(ccNumber)){
            cout<<"Bad Input";
            continue;
        }

        int len=ccNumber.length();
        int doubleEvenSum = 0;

        for(int i=len-2;i>=0;i-=2){
            int dbl=((ccNumber[i]-48)*2);
            if(dbl>9){
                dbl=(dbl/10)+(dbl%10);
            }
            doubleEvenSum+=dbl;
        }

        for(int i=len-1;i>=0;i-=2){
            doubleEvenSum+=(ccNumber[i]-48);
        }

        cout<<(doubleEvenSum%10==0?"Valid":"Invalid")<<endl;
    }
    return 0;
}