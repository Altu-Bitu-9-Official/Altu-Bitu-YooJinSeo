#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000000

using namespace std;

vector<bool> getPrimes(){
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for(int i=2; i<=sqrt(MAX); i++){
        if(!isPrime[i]) continue;
        
        for(int j=i*i; j<=MAX; j+=i){
            isPrime[j] = false;
        }
    }
    return isPrime;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<bool> isPrime = getPrimes();
    int n;
    
    while(cin >> n && n != 0){
        bool found = false;
        
        // 작은 소수부터 확인 (b-a가 가장 큰 것을 찾기 위해)
        for(int a=3; a<=n/2; a+=2){
            if(isPrime[a]){
                int b = n - a;
                if(isPrime[b]){
                    cout << n << " = " << a << " + " << b << "\n";
                    found = true;
                    break;
                }
            }
        }
        
        if(!found){
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    
    return 0;
}
