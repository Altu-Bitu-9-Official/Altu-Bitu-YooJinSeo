#include <iostream>
#include <cmath>  //abs() 함수를 위해 추가

using namespace std;

void calcL(int l, int& l2, int a, int t){ //기초대사량 계산
    if(abs(l-(l2+a))>t){ //abs: 절대값 함수
        l2+=(l-(l2+a))/2;
    }
}

void diet(int w0, int l0, int t, int d, int l, int a, int& w1, int& l1, int& w2, int& l2){
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
    int w0, l0, t, d, l, a;
    int w1, w2, l1, l2; 
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
            cout << " YOYO";
        }else cout << " NO";
    }

    return 0;
}