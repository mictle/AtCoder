#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN

#include __FILE__

llg kaijou(llg n){
    llg result=1;
    if(n==0)return 1;
    FOR(i, 2, n) result *= i;
    return result;
}

int main(){
    string st, ans;
    llg k;
    pair<char, int> l1[8];
    REP(i, st.length()){
        l1[8].F = '0';
        l1[8].S = 0;
    } 
    char tmp;
    cin >> st >> k;
    int wordn=0;
    REP(i, st.length()){
        int flg = -1;
        REP(j, 8) if(l1[j].F == st[i])flg = j;
        if(flg != -1) l1[flg].S++;
        else REP(j, 8){
            if(l1[j].F == '0'){
                l1[j].F = st[i];
                l1[j].S = 1;
                wordn++;
                break;
            }
        }
        
    }
    int oldp=0;
    sort(l1, l1+wordn);
    llg pattern = 0;
    FOR(i, 0, wordn-2){
        pattern = oldp;
        int m=0;
        
        while(pattern<k){
            if(l1[m].S==0){
                m++;
                continue;
            }
            llg tmp =0, tmp2 = 1;
            REP(j, wordn) tmp +=l1[m].S;
            tmp -=l1[m].S;
            REP(j, wordn) tmp2 = tmp2 * kaijou(l1[j].S);
            tmp2 /= l1[m].S;
            oldp = pattern;
            pattern += tmp / tmp2;
            m++;
        }
        l1[m-1].S--;
        ans += l1[m-1].F;
    }
    int m=0;
    while(m < k-oldp){
        if(l1[m].S!=0)m++;
    }
    ans+=l1[m].F;
    cout << ans;
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
