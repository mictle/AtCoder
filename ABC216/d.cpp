#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN

#include __FILE__


int main(){
    int n,m,k;
    cin >> n >> m;
    bool **rideMat;
    rideMat = new bool*[n];
    
    REP(i, n){
        rideMat[i] = new bool[n];
        REP(j, n) rideMat[i][j] = false;
    }

    REP(i, m){
        cin >> k;
        int *tmp = new int[k];
        REP(j, k){
            cin >> tmp[j];
            REP(l, j) rideMat[tmp[j]-1][tmp[l]-1] = true;
        }
    }

    REP(i, n){
        stack<int> s;
        bool *judgeMat = new bool[n];
        REP(j, n) {
            if(rideMat[i][j]){
                judgeMat[j] = true;
                s.push(j);
            }
            else judgeMat[j] = false;
        }
        while(!s.empty()){
            int tmp = s.top();
            s.pop();

            REP(j, n) {
                if(!judgeMat[j] && rideMat[tmp][j]){
                    judgeMat[j] = true;
                    s.push(j);
                }
            }
        }
        if(judgeMat[i]){
            cout << "No" << endl;
            return 0;
        }
        delete[] judgeMat;
    }
    cout << "Yes" << endl;

    
}

#else //INCLUDED_MAIN

//templete

#include <bits/stdc++.h>
using namespace std;

//総数を素数で割ったあまり
const long long mod = 1e9 + 7;

using llg = long long;
using pll = pair<long, long>;
using pllg = pair<llg, llg>;

//イテレーション
#define REP(i,n) for(llg i=0;i<llg(n);i++)
#define REPD(i,n) for(llg i=n-1;i>=0;i--)
#define FOR(i,a,b) for(llg i=a;i<=llg(b);i++)
#define FORD(i,a,b) for(llg i=a;i>=llg(b);i--)
#define FORA(i,I) for(const auto& i:I)

//x:コンテナ
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) llg(x.size()) 
//定数
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 //9.223372036854775807×10^{18}:64bit整数のinf
#define MOD 1000000007 //問題による

//略記
#define F first
#define S second

//出力(空白区切りで昇順に)
#define coutALL(x) for(auto i=x.begin();i!=--x.end();i++)cout<<*i<<" ";cout<<*--x.end()<<endl;

//aをbで割る時の繰上げ,繰り下げ
llg myceil(llg a,llg b){return (a+(b-1))/b;}
llg myfloor(llg a,llg b){return a/b;}

#endif // INCLUDED_MAIN
