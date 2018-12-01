#ifndef NULL
#define NULL 0
#endif 

/*struct info {
	int music[200];
}inf[10010];
*/
struct data {
	int id;
	int mx, mn;
	int music[8];
}arr[2000010];

struct bs {
	int index;
	int st;
}ary[2000010];

int min, max;
int idx;
int first;

void initUser(int soundNum)
{
	idx = 0;
	first = 0;
}

void registerSound(int soundID, int soundLen, int soundArr[200]) 
{
	/*
	for (int i = 0; i < soundLen; ++i) {
		inf[soundID].music[i] = soundArr[i];
		if (i <= soundLen - 8) {
			arr[idx].music = &inf[soundID].music[i];
			arr[idx].id = soundID;
			ary[idx].index = idx;
			ary[idx].st = inf[soundID].music[i];
			idx++;
		}
	}
	*/

	for (int i = 0; i <= soundLen - 8; ++i) {
		int mx = -999999;
		int mn = 999999;
		arr[idx].id = soundID;

		for (int j = 0; j < 8; ++j) {
			arr[idx].music[j] = soundArr[i + j];
			if (mx < arr[idx].music[j])
				mx = arr[idx].music[j];

			if (arr[idx].music[j] < mn)
				mn = arr[idx].music[j];
		}
		arr[idx].mx = mx;
		arr[idx].mn = mn;

		ary[idx].st = arr[idx].music[0];
		ary[idx].index = idx;
		idx++;
	}

}
void quickSort(int first, int last)
{
	int pivot;
	int i;
	int j;
	bs temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (ary[i].st <= ary[pivot].st && i < last)
			{
				i++;
			}
			while (ary[j].st > ary[pivot].st)
			{
				j--;
			}
			if (i < j)
			{
				temp.index = ary[i].index;
				temp.st = ary[i].st;

				ary[i].index = ary[j].index;
				ary[i].st = ary[j].st;

				ary[j].index = temp.index;
				ary[j].st = temp.st;
			}
		}

		temp.index = ary[pivot].index;
		temp.st = ary[pivot].st;

		ary[pivot].index = ary[j].index;
		ary[pivot].st = ary[j].st;

		ary[j].index = temp.index;
		ary[j].st = temp.st;

		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}
int check(int index, int st[])
{
	if (arr[index].mx - 128 <= max && max <= arr[index].mx + 127 &&
		arr[index].mn - 128 <= min && min <= arr[index].mn + 127) {
		for (int i = 0; i < 8; ++i) {
			if (arr[index].music[i] - 128 <= st[i] && st[i] <= arr[index].music[i] + 127)continue;
			else return -1;
		}
		return arr[index].id;
	}
	else return -1;
}
int search2(int low, int high, int data, int st[])
{
	int mid,index;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (ary[mid].st < data) {
			low = mid + 1;
		}
		else if (data <= ary[mid].st) {
			high = mid - 1;
		}
	}
	while (ary[low].st - 128 <= st[0] && st[0] <= ary[low].st + 127) {
		int ret = check(ary[low].index, st);
		if (ret != -1)
			return ret;
		low++;
	}
}
int search(int st[])
{
	int low = 0, high = idx - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (ary[mid].st - 128 <= st[0] && st[0] <= ary[mid].st + 127)
		{
			//사이에 있으면 -128을 찾고 +127까지 naive탐색
			return search2(low, mid, st[0] - 127, st);
		}
		else//범위안에 없으면 low,high 재설정
		{
			if (st[0] < ary[mid].st - 128) {
				high = mid - 1;
			}
			else if (ary[mid].st + 127 <= st[0]) {
				low = mid + 1;
			}
		}
	}
}
void find_minmax(int newData[])
{
	min = 999999;
	max = -999999;
	for (int i = 0; i < 8; ++i) {
		if (max < newData[i])
			max = newData[i];

		if (newData[i] < min)
			min = newData[i];
	}
}
int plagiarismCheck(int newData[8])
{
	//ary정렬(mx를 기준으로)처음 한번만
	if (!first) {
		quickSort(0, idx - 1);
		first = 1;
	}
	find_minmax(newData);
	return search(newData);
}