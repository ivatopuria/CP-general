//#include <fsociety>
#include <cmath>
#include <deque>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdio.h>
//end of libraries ;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
// ll lmax(ll o , ll w) {if(o>w)return o; return w;}
// ll lmin(ll o , ll w) {if(o<w)return o; return w;}
#define INF 3999999999999999999
#define N 3000003
#define PI 3.14159265359
#define F first
#define S second
#define pb push_back
#define ll long long
#define fcin ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
////// GCD

int gcd(int x , int y){       
  if(x==0) return y;
  if(x>y) swap(x,y);
  return gcd(y%x , x);
}

////////sieve of erathostenes
  int p[N];
  for(int i = 2 ; i*i < 10e5 ; i++){
     for(int j = i ; j * i <= 10e5 ; j++){
        p[j*i] = 1;
     }
  }
////////fenwick
      int tree[N];
      
      void update(int idx, int val) {
        while (idx <= MaxIdx) {
          tree[idx] += val;
          idx += (idx & -idx);
        }
      }
      int read(int idx) {
        int sum = 0;
        while (idx > 0) {
          sum += tree[idx];
          idx -= (idx & -idx);
        }
        return sum;
      }
/////////binary power
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
//
int main(){
fcin;

}
