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
	cnt = 0;
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
		if (!left_visited[mid]) {
			int data = getNumber(1, mid);
			left_temp[mid] = data;
			left_visited[mid] = true;
		}
		if (left_temp[mid]) {
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
		if (!right_temp[mid]) {
			int data = getNumber(2, mid);
			right_temp[mid] = data;
			right_visited[mid] = true;
		}
		if (right_temp[mid]) {
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
void go(int floor, int top, int lost, int user_ans[])
{
	if (lost == 1)//잃어버린카드가 1개일경우->이분탐색
	{
		int left = floor, right = top;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (!left_visited[mid]) {
				int data = getNumber(1, mid);
				left_temp[mid] = data;
				left_visited[mid] = true;
			}

			if (!right_temp[mid]) {
				int data = getNumber(2, mid);
				right_temp[mid] = data;
				right_visited[mid] = true;
			}

			if (left_temp[mid] == right_temp[mid]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		user_ans[cnt++] = left_temp[left];
	}
	else
	{
		int term = (top - floor) / lost;
		for (int i = floor + term; i <= top; i += term) {
			int yj = -1;//left_index에 처리해줄 영점
			do {
				yj++;
				if (!left_visited[i + yj]) {
					int data = getNumber(1, i + yj);
					left_temp[i + yj] = data;
					left_visited[i + yj] = true;
				}

				if (!right_temp[i]) {
					int data = getNumber(2, i);
					right_temp[i] = data;
					right_visited[i] = true;
				}
			} while (left_temp[i + yj] != right_temp[i]);
			if (yj) {
				go(i - term,  i + yj, yj, user_ans);
				floor = i + yj + 1;
				i = floor;
				term = (top - floor) / (lost - yj);
			}
		}
	}
}
void func(int user_ans[])
{
	go(0, left_max_index, ans_count,user_ans);
}

int card_find(int user_ans[])
{
	set();
	func(user_ans);
	return ans_count;
}