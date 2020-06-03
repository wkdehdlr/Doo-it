typedef pair<int, int> P;
const int INF = 1e9 + 1;

// ���е��� ���� �� ��ǥ ������ ����
sort(L, L + N);

// [l, r]: ���� ��ġ�� �ִ� ����
int result = 0, l = -INF, r = -INF;
for (int i = 0; i < N; i++) {
    // ���� ������ �̹� ������ ������ �� ����
    if (r < L[i].first) {
        result += r - l;
        l = L[i].first;
        r = L[i].second;
    }
    // ������: ���� ������ r�� �ø� �� ������ �ø�
    else r = max(r, L[i].second);
}
result += r - l; // ������ ������ ����� ���� ��