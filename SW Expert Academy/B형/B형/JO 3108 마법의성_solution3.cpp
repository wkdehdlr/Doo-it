extern int getNumber(int, int);

int cnt = 0;
int ans_count = 0;
int left_max_index = 0, left_max_data = 0;//
int right_max_index = 0, right_max_data = 0;//

int right_temp[1000005];
bool right_visited[1000005];
int left_temp[1000005];
bool left_visited[1000005];

void set()
{
	ans_count = 0;
	left_max_index = 0, left_max_data = 0;//
	right_max_index = 0, right_max_data = 0;//
	for (int i = 0; i < 1000005; ++i) {
		right_temp[i] = 0;
		right_visited[i] = false;
		left_temp[i] = 0;
		left_visited[i] = false;
	}

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

	int data = getNumber(1, 0);
	left_temp[0] = data;
	left_visited[0] = true;

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

	data = getNumber(2, 0);
	right_temp[0] = data;
	right_visited[0] = true;
}
int setting_youngjum(int user_ans[], int left_idx, int right_idx)
{
	while (1) {
		if (!left_visited[left_idx]) {
			int data = getNumber(1, left_idx);
			left_temp[left_idx] = data;
			left_visited[left_idx] = true;
		}
		if (!right_visited[right_idx]) {
			int data = getNumber(2, right_idx);
			right_temp[right_idx] = data;
			right_visited[right_idx] = true;
		}
		if (left_temp[left_idx] == right_temp[right_idx])break;
		else {
			user_ans[cnt++] = left_temp[left_idx++];
		}
	}
	return left_idx;
}
void func(int user_ans[])
{
	int ril = 0, rir = right_max_index;
	int lil = 0, lir = left_max_index;
	int left = 0, right = rir;
	for (; ril <= rir;) {
		left = ril; right = rir;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (!left_visited[lil + mid - ril]) {
				int data = getNumber(1, lil + mid - ril);
				left_temp[lil + mid - ril] = data;
				left_visited[lil + mid - ril] = true;
			}
			if (!right_visited[mid]) {
				int data = getNumber(2, mid);
				right_temp[mid] = data;
				right_visited[mid] = true;
			}

			if (left_temp[lil + mid - ril] != right_temp[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if (left > rir)break;
		user_ans[cnt++] = left_temp[lil + left];
		lil = setting_youngjum(user_ans, lil + left + 1, left);
		ril = left;
	}

	for (; lil <= lir; ++lil) {
		user_ans[cnt++] = left_temp[lil];
	}
}

int card_find(int user_ans[])
{
	set();
	func(user_ans);
	return ans_count;
}