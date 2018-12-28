#pragma warning(disable : 4996)
#include<cstdio>
#include<map>
using namespace std;
map<int, int> ma;
map<int, int>::iterator fir, sec;
int  T, N, M, B, once;
int go()
{
	int ans = 0;
	while (N--) {
		if (ma.empty())return -1;
		int ok = 0;
		//미사일 1방으로 만들 수 있는 값
		auto itr = ma.lower_bound(B);
		if (itr == ma.end())once = 0;//한방으로는 쉴드를 못 뿌실때
		else once = itr->first;//한방으로 뿌실 수 있을 때
		

		auto it = ma.begin();
		if (B <= it->first) {
			ans += it->first;
			it->second--;
			if (it->second == 0)ma.erase(it);
			continue;
		}
		//반띵구함
		int mn = 999999999;
		int mx = B / 2;
		//int mx = (ma.rbegin()->first) / 2;
		for (auto i = ma.begin(); i != ma.end() && i->first <= mx; ++i) {
			int n1 = i->first;
			/*if (B <= n1) {
				ans += i->first;
				i->second--;
				if (i->second == 0)ma.erase(i);
				ok = 1;
				break;
			}*/
			int n2 = B - n1;
			auto j = ma.lower_bound(n2);
			if (j == ma.end())continue;//2발을 합쳐도 못뿌시는경우
			if (n1 == j->first && j->second == 1)++j;
			if (j == ma.end())continue;//2발을 합쳐도 못뿌시는경우
			if (n2 == j->first) {//2발을 합쳤을 때 정확히 뿌시는 경우
				ans += (i->first + j->first);
				i->second--;
				j->second--;
				if (i->second == 0)ma.erase(i);
				if (j->second == 0)ma.erase(j);
				ok = 1;
				break;
			}
			else if (n2 < j->first) {//2발을 합쳤을 때 오버되는 경우
				if (n1 + j->first < mn) {
					ok = 2;
					mn = n1 + j->first;
					fir = i;
					sec = j;
				}
			}	
		}		
		if (ok == 1)continue;
		if (!once && !ok)return -1;
		if (ok == 2) {
			if (once && mn > once) {//한발사용
				ans += once;
				itr->second--;
				if (itr->second == 0)ma.erase(itr);
			}
			else{//두발사용
				ans += (fir->first + sec->first);
				fir->second--;
				sec->second--;
				if (fir->second == 0)ma.erase(fir);
				if (sec->second == 0)ma.erase(sec);
			}
		}	
	}		
	return ans;
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		ma.clear();
		scanf("%d %d %d", &N, &M, &B);
		for (int i = 0; i < M; ++i) {
			int power, cnt;
			scanf("%d %d", &power, &cnt);
			ma[power] = cnt;
		}
		printf("#%d %d\n", tc+1, go());
	}
}