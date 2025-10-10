#include <iostream>

using namespace std;

typedef long long ll;
const int MAX = 60;

pair<int,int> getXY(ll m){
    int x, y;

    //m = 2^i
    //m = 2^(i-1) + 2^(i-1): x = y = i-1
    for(int i=1; i<MAX; i++){
        if(m == (ll)1 << i){ //2^i
            return {i-1, i-1};
        }
    }

    //x<=y
    for(x=0; x<MAX; x++){
        if(m & ((ll)1 << x)){ //2^x
            //01001 & 00001 = 1(true)
            m -= (ll)1 << x; // 2^y = m-2^x
            break;
        }
    }
    
    for(y=x+1; y<MAX; y++){
        if(m & ((ll)1 << y)){ //2^y
            break;
        }
    }
    
    return {x, y};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n;
    cin >> n;

    //입력&연산&출력
    while(n--){
        ll m;
        cin >> m;
        pair<int, int> ans = getXY(m);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}