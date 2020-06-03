int find(int n) {
	if (p[n] < 0) return n;
	return p[n] = find(p[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}