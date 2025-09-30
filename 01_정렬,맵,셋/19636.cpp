#include <iostream>
#include <cmath>  //abs() 함수를 위해 추가

using namespace std;

void calcL(long long l, long long& l2, long long a, long long t){ //기초대사량 계산
    long long diff = l - (l2 + a);
    if(abs(diff) > t){ 
        // 바닥함수 구현: 음수일 때 주의
        if(diff >= 0) {
            l2 += diff / 2;
        } else {
            l2 += (diff - 1) / 2;  // 음수의 바닥함수
        }
    }
}

void diet(long long w0, long long l0, long long t, long long d, long long l, long long a, long long& w1, long long& l1, long long& w2, long long& l2){
    w1=w0;
    w2=w0;
    l1=l0;
    l2=l0;

    for(int i=0; i<d; i++){
        // 체중 변화 계산
        w1+=(l-(l0+a));
        w2+=(l-(l2+a));
        
        //기초대사량 계산
        calcL(l, l2, a, t);
    }
}

int main(){    
    long long w0, l0, t, d, l, a;
    long long w1, w2, l1, l2; 
    //기초대사량 고려X: w1, l1
    //기초대사량 고려O: w2, l2

    cin >> w0 >> l0 >> t >> d >> l >> a;

    diet(w0, l0, t, d, l, a, w1, l1, w2, l2);

    if(w1<=0 || l1<=0){
        cout << "Danger Diet" << '\n';
    } else{
        cout << w1 << ' ' << l1 << '\n';
    }

    if(w2<=0 || l2<=0){
        cout << "Danger Diet" << '\n';
    } else{
        cout << w2 << ' ' << l2;
        if((l0-l2)>0) {
            cout << " YOYO\n";
        }else cout << " NO\n";
    }

    return 0;
}