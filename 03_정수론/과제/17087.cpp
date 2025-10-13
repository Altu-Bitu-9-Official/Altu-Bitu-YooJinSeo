#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, s;
    cin >> n >> s;
    
    vector<int> distances;
    
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        distances.push_back(abs(a - s));
    }
    
    int result = distances[0];
    for(int i=1; i<n; i++){
        result = gcd(result, distances[i]);
    }
    
    cout << result << "\n";
    
    return 0;
}
