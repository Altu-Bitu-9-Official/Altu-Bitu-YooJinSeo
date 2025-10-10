#include <iostream>

using namespace std;

// O(n): 두 수가 주어졌을 때 가장 작은 수를 기준으로 최대공약수 구하기
int getGcdBad(int a, int b){
    for (int i = min(a,b); i>0; i--){
        if(a%i == 0 && b %i==0){
            return i;
        }
    }
    return 1;
}

int getGcd(int a, int b){
    while(b != 0){
        a%=b;
        swap(a,b);
    }
    return a;
}

int getGcdRecur(int a, int b){
    if(b==0) {// 종료조건
        return a;
    }
    return getGcdRecur(b, a%b);
}

int main(){
    int a, b;
    cin >> a >> b;
    int gcd = getGcd(a,b);
    int lcm = a*b/gcd;

    cout << gcd << '\n';
    cout << lcm << '\n';

    return 0;
}