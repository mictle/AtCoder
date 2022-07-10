#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN

#include __FILE__


int main(){
    int n;
    cin >> n;
    pll* poses = new pll[n];
    long* rs = new long[n];
    bool* sFlag = new bool[n];
    bool* tFlag = new bool[n];
    bool* sFlagTmp = new bool[n];
    bool* tFlagTmp = new bool[n];
    pll s,t;
    cin >> s.F >> s.S >> t.F >> t.S;
    REP(i,n)cin >> poses[i].F >> poses[i].S >> rs[i];
    REP(i,n){
        if((s.F-poses[i].F)*(s.F-poses[i].F) + (s.S-poses[i].S)*(s.S-poses[i].S) == rs[i] * rs[i]) sFlag[i] = true;
        else sFlag[i] = false;
        sFlagTmp[i] = sFlag[i];
    }

    REP(i,n){
        if((t.F-poses[i].F)*(t.F-poses[i].F) + (t.S-poses[i].S)*(t.S-poses[i].S) == rs[i] * rs[i]) tFlag[i] = true;
        else tFlag[i] = false;
        tFlagTmp[i] = tFlag[i];
    }

    while(true){
        REP(i,n){
            if(sFlag[i] && tFlag[i]){
                cout << "Yes";
                return 0;
            }
        }

        bool flg = false;
        REP(i,n){
            if(sFlagTmp[i] || tFlagTmp[i]){
                flg = true;
                break;
            }
        }
        if(!flg){
            cout << "No";
            return 0;
        }

        REP(i,n){
            if(!sFlagTmp[i])continue;
            sFlagTmp[i] = false;
            REP(j,n){
                if(sFlag[j])continue;
                if(i==j)continue;
                float distance = (poses[i].F-poses[j].F)*(poses[i].F-poses[j].F) + (poses[i].S-poses[j].S)*(poses[i].S-poses[j].S);
                if(sqrt(distance) < max(rs[i], rs[j])){
                    if(max(rs[i], rs[j]) <= sqrt(distance) + min(rs[i], rs[j])){
                        sFlag[j] = true;
                        sFlagTmp[j] = true;
                    }
                }
                else if(distance <= (rs[i]+rs[j]) * (rs[i] + rs[j])){
                    sFlag[j] = true;
                    sFlagTmp[j] = true;
                }
            }
        }

        REP(i,n){
            if(!tFlagTmp[i])continue;
            tFlagTmp[i] = false;
            REP(j,n){
                if(tFlag[j])continue;
                if(i==j)continue;
                float distance = (poses[i].F-poses[j].F)*(poses[i].F-poses[j].F) + (poses[i].S-poses[j].S)*(poses[i].S-poses[j].S);
                if(sqrt(distance) < max(rs[i], rs[j])){
                    if(max(rs[i], rs[j]) <= sqrt(distance) + min(rs[i], rs[j])){
                        tFlag[j] = true;
                        tFlagTmp[j] = true;
                    }
                }
                else if(distance <= (rs[i] + rs[j]) * (rs[i] + rs[j])){
                    tFlag[j] = true;
                    tFlagTmp[j] = true;
                }
            }
        }
    }

}



#else //INCLUDED_MAIN

//templete

#include <bits/stdc++.h>
#include <atcoder/all>
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
