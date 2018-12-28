#include<cstdio>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

unordered_map<int, int> ma;
unordered_set<int> st;
int arr[100005];
int n;
int main()
{
	//freopen("input.txt", "r", stdin);
	int mx = 0, mn = 999999999;
	int mx2 = 0, mn2 = 999999999;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		st.insert(arr[i]);
		mx = max(mx, arr[i]);
		mn = min(mn, arr[i]);
		ma[arr[i]]++;
	}
	for (int i = 0; i < n; ++i) {
		if (arr[i] >= mx2 && arr[i] < mx)mx2 = arr[i];
		if (arr[i] > mn && arr[i] <= mn2)mn2 = arr[i];
	}

	if (st.size() == 1) {
		printf("0\n");
		return 0;
	}
	if (ma[mn] == 1 && ma[mx] == 1) {
		printf("%d\n", min(mx2 - mn, mx - mn2));
	}
	else if (ma[mn] == 1 && ma[mx] != 1) {
		printf("%d\n", mx - mn2);
	}
	else if (ma[mn] != 1 && ma[mx] == 1) {
		printf("%d\n", mx2 - mn);
	}
	else {
		printf("%d\n", mx - mn);
	}
}