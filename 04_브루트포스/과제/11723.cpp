#include <iostream>

using namespace std;

int s = 0; // 전역변수

void funcS(string input, int x){
    if(input=="add") s |= (1<<x);
    if(input=="remove") s &= ~(1<<x);
    if(input=="check") cout << ((s&(1<<x)) ? 1 : 0) << "\n";
    if(input=="toggle") s^=(1<<x);
    if(input=="all") s=(1<<21)-2;
    if(input=="empty") s=0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, x=0;
    string input;

    cin >> m;

    while(m--){
        cin >> input;
        if(input!="all" && input!="empty") cin >> x;
        funcS(input, x);
    }

    return 0;
}