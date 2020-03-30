#pragma warning(disable : 4996)
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<unordered_map>
#include<functional>
using namespace std;

vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
vector<string> banner_id = { "fr*d*", "abc1**" };
bool uvisit[9] = { 0,0,0,0,0,0,0,0,0 };
bool bvisit[9] = { 0,0,0,0,0,0,0,0,0 };
int U, B, K, idx = 0;

int comp(string u, string b) {
	int ulen = u.size();
	int blen = b.size();
	if (ulen != blen)return 0;

	for (int i = 0; i < blen; ++i) {		
		if (b[i] == '*')continue;
		if (u[i] != b[i])return 0;
	}
	return 1;
}

void func(int depth) {
	if (depth == B) {
		idx++;
		return;
	}

	for (int i = 0; i < B; ++i) {
		if (!bvisit[i]) {

			for (int j = 0; j < U; ++j) {
				if (!uvisit[j]) {
					if (comp(user_id[j], banner_id[i])) {
						uvisit[j] = bvisit[i] = true;
						func(depth + 1);
						uvisit[j] = bvisit[i] = false;
					}
				}
			}

		}
	}
}
int main() {
	U = user_id.size();
	B = banner_id.size();
	func(0);


	return 0;
}


