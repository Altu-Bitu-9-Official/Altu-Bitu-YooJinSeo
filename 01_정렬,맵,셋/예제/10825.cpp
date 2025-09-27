#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
    string name;
    int kor, eng, math;
};

//국어 점수가 감소하는 순서
//국어 점수가 같다면 영어 점수가 증가하는 순서
//국어 점수와 영어 점수가 같다면 수학 점수가 감소하는 순서
//모든 점수가 같으면 이름이 사전 순으로 증가하는 순서
bool comp(const student& s1, const student& s2) { //false면 swap
    if(s1.kor!=s2.kor){
        return s1.kor > s2.kor;
    }
    if(s1.eng!=s2.eng){
        return s1.eng < s2.eng;
    }
    if(s1.math!=s2.math){
        return s1.math > s2.math;
    }
    return s1.name < s2.name;
}

int main(){
    int n;
    cin >> n;

    vector<student> my_class(n);

    for(int i=0; i<n; i++){
        cin >> my_class[i].name >> my_class[i].kor >> my_class[i].eng >> my_class[i].math;
    }

    sort(my_class.begin(), my_class.end(), comp);
    
    for(int i=0; i<n; i++){
        cout << my_class[i].name << '\n';
    }

    return 0;
}
