#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //reading from one file and outputting into another
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","r",stdout);

    // Even though the variable b is of type long long, both numbers in the expres- sion a*a are of type int and the result is also of type int

    // x=x%m | An easy way to make sure there are no negative remainders is to first calculate the remainder as usual and then add m if the result is negative:

    // double a =0.99999999989;
    // double b =0.99999999999;


    // if (abs(a-b) < 1e-9) {
    //     cout<<"true"<<endl;
    // }

    // cout<<abs(a-b)<<endl;

    //(a+b)modm = (amodm+bmodm)modm | Same for substraction and multiplication

    // typedef long long ll;
    // typedef vector<int> vi;

    //Gp = 2n − 1. AP = n(a-b)/2 sum of squares = n(n+1)(2n-1)/6
    // A quantifier connects a logical expression to the elements of a set. The most important quantifiers are ∀ (for all) and ∃ (there is).

    // int arr[] = {1,2,3,4,6,7,8,9};

    //auto k= lower_bound(arr,arr+10,5)-arr;
    // auto k= upper_bound(arr,arr+10,6)-arr;
    // auto l= lower_bound(arr,arr+10,4)-arr;
    // auto m=equal_range(arr,arr+10,5);

    //An important property of sets is that all their elements are distinct. 

    //    s.erase(s.find(5)); to remove just one instance
    // set<int> s;
    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(4);
    // s.insert(5);
    // set<int>::iterator it = s.begin();

    // for(auto i=s.begin();i!=s.end();i++){
    //     cout<<*i<<endl;
    // }

    // auto it = s.lower_bound(3);
    // cout<<it;
    // if (it == s.begin()) {
    //     cout << *it << "\n";
    // } else if (it == s.end()) {
    //     it--;
    //     cout << *it << "\n";
    // } else {
    //     int a = *it; it--;
    //     int b = *it;
    //     if (3-b < a-3) cout << b << "\n";
    //     else cout << a << "\n";
//bitset<10> s(string("0010011010")); // from right to left
    // bitset<10> bt(string("100101010"));

    // cout<<bt[5]<<endl;//1

    //By default, the elements in a C++ priority queue are sorted in decreasing order

    // If the element does not appear in the indexed set, we get the position that the element would have in the set:


    



    return 0;
}
//Binet's formula
// int fibonacci(int n) {
//     double phi = (1 + sqrt(5)) / 2;
//     double result = (pow(phi, n) - pow(-phi, -n)) / sqrt(5);
//     return round(result);
// }

// void binary_another(int arr[], int n,int target){
//     int k=0;
//     for(int i=n/2;i>=1;i/=2){
//         while(k+i<n && arr[k+i]<=target){
//             k+=i;
//         }
//     }
//     if(arr[k]==target){
//         cout<<"found<<endl";
//     }
// }

// void max_sum_subarray(){
//     vector<int> input;
//     int n;
//     cout<<"enter"<<endl;
//     for(int i=0;i<8;i++){
//         cin>>n;
//         input.push_back(n);
//     }

//     int best =0; int sum=0;

//     for(int i=0;i<8;i++){
//         sum = max(input[i], sum+input[i]);
//         best = max(sum,best);
//     }

//     cout<<best<<endl;
// }
/*
//finding peak element using binary search
int x = -1;
    for (int b = z; b >= 1; b /= 2) {
        while (f(x+b) < f(x+b+1)) x += b;
    }
int k = x+1;
*/