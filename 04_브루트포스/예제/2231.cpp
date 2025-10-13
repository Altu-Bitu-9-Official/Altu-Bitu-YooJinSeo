#include <iostream>

using namespace std;

int bruteforce(int n){
    for(int i=1; i<n; i++){
        int sum = i; //분해합
        int temp = i; //몫

        while(temp){
            sum+=temp%10; //245%10=5
            temp /=10; //24
        }

        if(n==sum){
            return i;
        }
    }

    return 0; //생성자 없음
}

int main(){
    //입력
    int n;
    cin >> n;

    //연산
    int ans = bruteforce(n);

    //출력
    cout << ans << "\n";

    return 0;
}