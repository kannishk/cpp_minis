#include<iostream>
using namespace std;
long long binpow(long long a, long long b);
int binarygcd(int a , int b);
int extendedgcd(int a, int b, int &x, int &y);




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x,y;
    long long a,b;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;
    cout<<extendedgcd(a,b,x,y);
    return 0;
}

long long binpow(long long a, long long b){
    if(b==0)
        return 1;
    long long res = binpow(a, b/2);
    if(b%2)
        return res * res * a;
    else    
        return res * res;
/*
long long res=1;
while(b>0){
    if(b&1){
        res = res*a;
    }
    a=a*a;
    b>>=1;
}

return res;

b=13 // 27*27
b=6 // 27*27
b=3 // 3*3*3
b=1 // 3
b=0 // 1
*/
}

//Sequence of length n. Apply to it a given permutation k times;



// Binary GCD
int binarygcd(int a , int b){
    if(!a||!b){
        return a|b;
    }
    unsigned shift = __builtin_ctz(a|b);
    a>>=__builtin_ctz(a);
    do{
        b>>=__builtin_ctz(b);
        if(a>b){
            swap(a,b);
        }
        b-=a;
    }while(b);
    return a<<shift;
}
/*
int lcm(int a,int b){
    return a/gcdbinary(a,b) * ; // Divided first to avoid integer overflow
}
*/
//Extended Euclidean Algo
int extendedgcd(int a, int b, int &x, int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d=extendedgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1 * (a/b);
    return d;
}

/* //Iterantive version of extendedgcd
int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
*/

