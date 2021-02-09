#include<cstdio>
#include<string>
#include<vector>
#include<utility>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<functional>
#include<sstream>
using namespace std;
typedef long long ll;

struct info {
    int a,b,c;
    info(int a1, int b1, int c1){
        a=a1;
        b=b1;
        c=c1;
    }
};

bool compare(info f, info g){
    return f.a > g.a;
}
vector<info> vec;

vec.push_back(info(1,10,100));
vec.push_back(info(2,20,200));
vec.push_back(info(3,30,300));

sort(vec.begin(), vec.end(), compare);
//vec[0] = (3,30,300)
//vec[1] = (2,20,200)
//vec[2] = (1,10,100)


bool compare(pair<int, int> f, pair<int, int> g){
    return f.first > g.first;
}

vector<pair<int, int> > vec;

vec.push_back(make_pair(1,10));
vec.push_back(make_pair(2,20));

sort(vec.begin(), vec.end(), compare);
//vec[0] = (2, 20)
//vec[1] = (1, 10)
//pq처럼 쓰려면 deque로

//char to string
string(1, 'a')
string(2, 'aa')

std::set<int>::iterator it = it.begin();


#include<algorithm>

string new_id="ABC";
transform(new_id.begin(), new_id.end(),new_id.begin(), ::tolower);
//abc

#include<algorithm>
vertor<pair<int, int> > arr;
bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first < b.first;
}
sort(arr.begin(), arr.end());

for (int i = 0; i < n; i++)
    cout << "i :: " << i << " x :: " << arr[i].first << " y :: " << arr[i].second << endl;

// x가 5이상인 값이 있는 첫 index를 찾는 과정이다. 
auto lo_it = lower_bound(arr.begin(), arr.end(), pair<int,int>(5, 0), comp) - arr.begin();

// x가 5초과인 값이 있는 첫 index를 찾는 과정이다. 
auto up_it = upper_bound(arr.begin(), arr.end(), pair<int,int>(5, 0), comp) - arr.begin();
