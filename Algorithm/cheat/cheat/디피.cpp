vector<int> dp;

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    dp[n] = fibonacci(n - 2) + fibonacci(n - 1);
    return dp[n];
}

int main() {
    int N;
    scanf("%d", &N);
    dp.resize(N + 1, -1); // 초기값 -1은 fibonacci 결과로 절대 나올 수 없는 값
    printf("%d\n", fibonacci(N));
}