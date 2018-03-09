extern int getNumber(int, int);

int ans_count = 0;
int left_max_index = 0, left_max_data = 0;//
int right_max_index = 0, right_max_data = 0;//
int right_temp[1000005];
bool right_visited[1000005];
int left_temp[1000005];
bool left_visited[1000005];

void set()
{
	int left = 100000, right = 1000000;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		int data = getNumber(1, mid);
		left_temp[mid] = data;
		left_visited[mid] = true;
		if (data) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	left_max_index = left;

	left = left_max_index - 1000, right = left_max_index - 100;
	while (left <= right)
	{
		mid = (left + right) / 2;
		int data = getNumber(2, mid);
		right_temp[mid] = data;
		right_visited[mid] = true;
		if (data) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	right_max_index = left;
	ans_count = left_max_index - right_max_index;

	int data = getNumber(2, 0);
	right_temp[0] = data;
	right_visited[0] = true;
}
/*
void func(int left, int right, int term)
{
	if (right - left <= term)
	{
		if (right - left == right_temp[right] - right_temp[left]){
			for (int i = left + 1; i < right; ++i)
			{
				right_temp[i] = right_temp[i - 1] + 1;
				visited[i] = true;
			}
		}
		else {
			int mid = (left + right) / 2;
			if (!visited[mid]) {
				int data = getNumber(2, mid);
				right_temp[mid] = data;
				visited[mid] = true;
			}
			func(left, mid, term / 2);
			func(mid, right, term / 2);
		}
	}
	else
	{
		int mid = (left + right) / 2;
		if (!visited[mid]) {
			int data = getNumber(2, mid);
			right_temp[mid] = data;
			visited[mid] = true;
		}
		func(left, mid, term);
		func(mid, right, term);
	}
}

void func()
{
	int mid = 50;
	for (int i = 0; i <= right_max_index; ++i)
	{
		mid = 50;
		if (i + mid > right_max_index) mid = right_max_index - i;
		while (1)
		{
			if (!visited[i + mid]) {
				int data = getNumber(2, i + mid);
				right_temp[i + mid] = data;
				visited[i + mid] = true;
			}
			if (mid == 1 || mid + i - i == right_temp[i + mid] - right_temp[i]) {
				for (int j = i + 1; j < i + mid; ++j) {
					right_temp[j] = right_temp[j - 1] + 1;
				}
				i += mid;
				if (!visited[i + 1]) {
					right_temp[i + 1] = getNumber(2, i + 1);
					visited[i + 1] = true;
				}
				break;
			}
			else {
				mid /= 2;
			}
		}
	}
}*/
void func()
{
	int mid = 100;
	for (int i = 0; i <= right_max_index; ++i)
	{
		mid = 100;
		if (i + mid > right_max_index) mid = right_max_index - i;
		while (1)
		{
			if (!visited[i + mid]) {
				int data_right = getNumber(2, i + mid);
				right_temp[i + mid] = data_right;
				visited[i + mid] = true;
			}
			if (mid == 1 || data) {
				for (int j = i + 1; j < i + mid; ++j) {
					right_temp[j] = right_temp[j - 1] + 1;
				}
				i += mid;
				if (!visited[i + 1]) {
					right_temp[i + 1] = getNumber(2, i + 1);
					visited[i + 1] = true;
				}
				break;
			}
			else {
				mid /= 2;
			}
		}
	}
}
void result(int user_ans[])
{
	for (int i = 1, j = 0, idx = 0; i <= left_max_index; ++i)
	{
		if (i != right_temp[j]) {
			user_ans[idx++] = i;
		}
		else {
			++j;
		}
	}
}
int card_find(int user_ans[]) 
{		
	set();
	func();
	result(user_ans);
	return ans_count;
}