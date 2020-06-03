typedef pair<int, int> P;
const int INF = 1e9 + 1;

// 선분들을 왼쪽 끝 좌표 순으로 정렬
sort(L, L + N);

// [l, r]: 현재 합치고 있는 구간
int result = 0, l = -INF, r = -INF;
for (int i = 0; i < N; i++) {
    // 현재 구간과 이번 선분이 합쳐질 수 없음
    if (r < L[i].first) {
        result += r - l;
        l = L[i].first;
        r = L[i].second;
    }
    // 합쳐짐: 현재 구간의 r을 늘릴 수 있으면 늘림
    else r = max(r, L[i].second);
}
result += r - l; // 마지막 구간도 결과에 더해 줌