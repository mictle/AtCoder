#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN

#include __FILE__


int main(){
    int sn, tn;
    string s,t,sOld, tOld;

    sOld = "123";
    tOld = "123";

    cin >> s >> t;

    sOld[0] = s[0];
    tOld[0] = t[0];
    sn=0;
    tn=0;
    while(sn<s.length() || tn < t.length()){
        if(tn >= t.length()){
            cout <<"No";
            return 0;
        }
        if(sOld[0] == tOld[0]){
            sn++;
            tn++;
            FORD(i,2,1) sOld[i] = sOld[i-1];
            sOld[0] = s[sn];
            FORD(i,2,1) tOld[i] = tOld[i-1];
            tOld[0] = t[tn];
        }else if(sOld[1] == sOld[2] && sOld[1] == tOld[0]){
            tn++;
            FORD(i,2,1) tOld[i] = tOld[i-1];
            tOld[0] = t[tn];
        }else{
            cout <<"No";
            return 0;
        }
    }
    if(tn < t.length()){

            cout <<"No";
            return 0;
    }
    cout << "Yes";
    return 0;
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
