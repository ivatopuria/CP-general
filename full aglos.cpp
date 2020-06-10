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
ll binpow(ll q, ll w ){
    if(w==0) return 1;
    // if(w==1) return q;
    result = (mypow(q,w/2)%mod);
    if(w%2==0) return  (result * result) % mod;
    else return  (((result * result) % mod) * q )% mod ;
}
//
///////trie (string algorithm)
/*
დამატების ფუნქცია აკეთებს იმას რომ ყოველ შემოტანილ სტრინგზე ნახულობს აქამდე თუ გქონდა მსგავსი სტრინგი ჩაწერილი სადმე
თუ მსგავსი სტრინგი მოინახა სადმე მაშინ აგრძელებ გადაყოლას ნუმერაციით თუ არადა რაიმე ცვლადს ზრდი , 
ეს ცვლადი იქნება განსხვავებული საბსტრინგების რაოდენობა სტრინგში .
მაგალითად გვაქვს სტრინგი : "aac " 
    go add ( c )  . sz გახდება 1 და to[0]['c']ში ჩაიწერება 1
    go add ( ac ) . to[0][a] == -1 ამიტომ  ჩაიწერება 2 და v = 2
    შემდგომ გადავა cში და to[2][c] == -1 ამიტომ ჩაიწერება 3.
    go add ( aac ) . to[0][a] გვაქვს ამიტომ sz არ გაიზრდება , 
    to[1][a] არ გვაქვს ამიტომ sz გაიზრდება და გახდება 4 , და ჩაიწერება შიგნით 4
    to[2][c] არ გვაქვს ამიტომ sz გაიზრდება .
    მის წინ რომ ეწეროს კიდევ a a c  
                            t[0][a] = 1 , t[1][a] = 2 , t[2][c] = 4 და საიზი არ გაიზრდება
    მაგრამ მის წინ რომ ეწეროს ka და სტრინგი იყოს ka aac  
                                                 +0 011        
*/
void add(string s) {
    int v = 0;
    for (int i = 0; i < (int) s.length(); i++) {
        if (to[v][s[i] - 'a'] == -1)
            to[v][s[i] - 'a'] = ++sz;
        v = to[v][s[i] - 'a'];
    }
}

 
void dfs(int v, int cnt) {   
    if (cnt <= k) mark[v] = 1;
    for (int i = 0; i < 26; i++) 
        if (to[v][i] != -1)
            dfs(to[v][i], cnt + cost[i]);
}
/*
additional 
string t = "';
for (int i = s.length() - 1; i >= 0; i--) {
        t = s[i] + t;
        add(t);
    }
dfs(0, 0);
*/
////

https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
////LIS 
o(nlogn)
  
  
d[0] = -INF;
for(int i = 1 ; i <= n + 1 ; i++) d[i] = INF;
for(int i = 1 ; i <= n ; i++){
		l = 0 , r = n;
		indx = 0;
		while(l <= r){
			mid = (l+r)/2;
			if(d[mid] > a[i]){
				indx = mid;
				r = mid - 1;
			}
			else{
				indx = mid + 1;
				l = mid + 1;
			}
		}
		if(d[indx-1] < a[i] && a[i] < d[indx+1]){
			d[indx] = a[i];
		}
	}
	for(int i = 1 ;i <= n ; i++){
		if(d[i]!=INF)ans= i ;
	}



////
Dijkstra

vector<int> ans;
set < pair <int,int > > st;


for(int i = 1 ; i<= n ; i++) d[i] = LNF;
    d[1] = 0;
    st.insert(make_pair(0,1));
while(!st.empty()){
      auto it = st.begin();
      v = it->second;
      st.erase(it);
      for(auto each : vc[v]){
         int to = each.S;
         ll len = each.F;
         if(d[v] + len < d[to]){
             st.erase(make_pair(d[to] , to));
             d[to] = d[v] + len;
             path[to] = v;
             st.insert(make_pair(d[to] , to));
      }
   }
 }
if(d[n]==LNF) cout << -1;
else{
    x = n;
    while(path[x]!=0){
        ans.pb(x);
        x = path[x];
    }
    ans.pb(1);
    reverse(ans.begin(),ans.end());
    for(auto each : ans) cout << each << " ";
}




int main(){
fcin;

}
