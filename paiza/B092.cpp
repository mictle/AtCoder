#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN

#include __FILE__


int main(){
    pair<int, int> pPos;
    pair<int, pair<int, int>> *savePoints;
    int h, w, k;
    cin >> h >> w >> k;
    savePoints = new pair<int, pair<int, int>>[k];
    string line;
    int count = 0;
    REP(i, h){
        cin >> line;
        REP(j, w){
            if(line[j] == 'N'){
                pPos.F = i;
                pPos.S = j;
            }else if(line[j] != '#'){
                int num = line[j] - '0';
                savePoints[count].F = num;
                savePoints[count].S.F = i;
                savePoints[count].S.S = j;
                count++;
            }
        }
    }
    count = 0;
    int minDif = 100000;
    priority_queue<pair<int, int>> saveDifs;
    
    REP(i, k){
        int dif = abs(savePoints[i].S.F - pPos.F) + abs(savePoints[i].S.S - pPos.S);
        if(dif < minDif){
            minDif = dif;
            count = 1;
        }else if(dif == minDif){
            count++;
        }
        pair<int, int> tmp;
        tmp.S = -savePoints[i].F; tmp.F = -dif;
        saveDifs.push(tmp);
    }
    cout << count << endl;
    REP(i, count){
        cout << -saveDifs.top().S << endl;
        saveDifs.pop();
    }
    delete[] savePoints;
    
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
