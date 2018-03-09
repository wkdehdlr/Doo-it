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

void func(int user_ans[])
{
	int cnt = 0;
	int mid = 100;
	int left = 0, right = 0;
	for (; right <= right_max_index; ++left, ++right)
	{
		mid = 100;
		if (right + mid > right_max_index)mid = right_max_index - right;
		while (1) {
			if (!left_visited[left + mid]) {
				int data = getNumber(1, left + mid);
				left_temp[left + mid] = data;
				left_visited[left + mid] = true;
			}
			if (!right_visited[right + mid]) {
				int data = getNumber(2, right + mid);
				right_temp[right + mid] = data;
				right_visited[right + mid] = true;
			}
			if (!mid) {
				if (left_temp[left + mid] != right_temp[right + mid]) {
					user_ans[cnt++] = left_temp[left + mid];
					++left;
				}
				else break;
				while (1)
				{
					if (!left_visited[left + mid]) {
						int data = getNumber(1, left + mid);
						left_temp[left + mid] = data;
						left_visited[left + mid] = true;
					}
					if (left_temp[left + mid] == right_temp[right + mid]) {
						//--left;
						//--right;
						break;
					}
					else {
						user_ans[cnt++] = left_temp[left + mid];
						++left;
					}
				}
				break;
			}

			if (left_temp[left + mid] == right_temp[right + mid]) {
				left += mid;
				right += mid;
				break;
			}
			else {
				mid /= 2;
			}
		}
	}
	for (; left <= left_max_index; ++left){
		user_ans[cnt++] = left_temp[left];
	}
}

int card_find(int user_ans[])
{
	set();
	func(user_ans);
	return ans_count;
}