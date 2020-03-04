#ifndef NULL
#define NULL 0
#endif // NULL

struct data {
	int r, c;
	int rotate;
	long long value;
};
int N, M;
data arr[4000000];
int i, j, r, c, k;
int cnt = 0;
unsigned long long tmp = 0LL;
void quick(int first, int last) {
	int pivot;
	int i;
	int j;
	data temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (arr[i].value <= arr[pivot].value && i < last)
			{
				i++;
			}
			while (arr[j].value > arr[pivot].value)
			{
				j--;
			}
			if (i < j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;

		quick(first, j - 1);
		quick(j + 1, last);
	}
}
void rotate(int m, int ap[][1000]) {

	if (k == 0) {// 0도
		for (i = 0; i < m; ++i) {
			for (j = 0; j < m; ++j) {
				tmp = tmp * 2 + ap[r + i][c + j];
			}
		}
	}else if (k == 1) {//90도
		for (j = 0; j < m; ++j) {
			for (i = 0; i < m; ++i) {
				tmp = tmp * 2 + ap[r + (m - 1) - i][c + j];
			}
		}
	}else if (k == 2) {//180도
		for (i = 0; i < m; ++i) {
			for (j = 0; j < m; ++j) {
				tmp = tmp * 2 + ap[r +(m - 1) - i][c +(m - 1) - j];
			}
		}
	}else if (k == 3) {//270도
		for (j = 0; j < m; ++j) {
			for (i = 0; i < m; ++i) {
				tmp = tmp * 2 + ap[r + i][c + (m - 1) - j];
			}
		}
	}
}
void init(int n, int ap[][1000], int m) {
	M = m;
	cnt = 0;
	for (r = 0; r <= n - m; ++r) {
		for (c = 0; c <= n - m; ++c) {
			for (k = 0; k < 4; ++k) {
				tmp = 0LL;
				rotate(m, ap);
				arr[cnt].r = r;
				arr[cnt].c = c;
				arr[cnt].rotate = k;
				arr[cnt].value = tmp;
				cnt++;
			}
		}
	}
	quick(0, cnt - 1);
}
int binarySearch(int low, int high, long long target)
{
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (target < arr[mid].value)
			high = mid - 1;
		else if (arr[mid].value < target)
			low = mid + 1;
		else
			return mid;
	}
}

int query(int bp[][20], int userAns[]) {
	int rotateDegree = 0;
	int x = 0, y = 0;
	tmp = 0LL;
	for (i = 0; i < M; ++i) {
		for (j = 0; j < M; ++j) {
			if (bp[i][j] == 9) {
				x = i; y = j;
			}
			tmp = tmp * 2 + (bp[i][j] == 0 ? 0 : 1);
		}
	}
	int ans = binarySearch(0, cnt - 1, tmp);
	userAns[0] = arr[ans].r;
	userAns[1] = arr[ans].c;
	userAns[2] = arr[ans].r + x;
	userAns[3] = arr[ans].c + y;
	return arr[ans].rotate;
}
