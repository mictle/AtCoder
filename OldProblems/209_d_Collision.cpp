#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN

#include __FILE__

//Union-Find木struct
struct myTree{
    vector<int> par; //自分の親を保存する配列

    myTree(int n, int rootN) : par(n){ //0 ~ N-1までの要素を自分を根にして初期化
        REP(i, n) par[i] = i;
        par[rootN] = -1;
    }

    int root(int x){ //根の値を確かめる関数
        if(par[x] == x || par[x] == -1)return x;
        else{
            return root(par[x]);
        }
    }

    void connect(int x, int y){
        if(par[y] == y){
            par[y] = x;
        }else if(par[x] == x){
            par[x] = y;
        }else if(par[x] == -1){
            par[x] = y;
            par[root(y)] = -1;
        }else if(par[y] == -1){
            par[y] = x;
            par[root(x)] = -1;
        }
    }

    int depth(int x){
        if(par[x] == -1) return 0;
        else return depth(par[x]) + 1;
    }
};

int main(){
    int N, Q, a, b, total;
    cin >> N >> Q;
    myTree mt(N, N/2);
    REP(i, N-1){
        cin >> a >> b;
        mt.connect(a-1, b-1);
    }

    REP(i, Q){
        cout << "loop" << endl;
        cin >> a >> b;
        total = mt.depth(a-1);
        total += mt.depth(b-1);
        if(total%2 == 0){
            cout << "Town" << endl;
        }else{
            cout << "Road" << endl;
        }
    }
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
