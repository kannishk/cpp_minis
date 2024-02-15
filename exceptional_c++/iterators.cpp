#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<Date> e;
    copy(istream_iterator<Date>(cin), istreambuf_iterator<Date>(), back_inserter(e));
    
    return 0;
}