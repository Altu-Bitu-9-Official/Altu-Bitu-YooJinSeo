#include <iostream>
#include <deque>

using namespace std;

int cal(int n){
    deque<int> d;

    for(int i=1; i<=n; i++){
        d.push_front(i);
    }

    while(d.size()!=1){
        d.pop_back();
        d.push_front(d.back());
        d.pop_back();
    }

    return d.front();
}

int main(){
    int n;
    cin >> n;

    cout << cal(n) << "\n";

    return 0;
}