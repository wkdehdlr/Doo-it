#ifndef NULL

#define NULL 0

#endif

#define MAX 100000
bool dir;
int cnt = 1;
int fst_idx = 1;
int fst[100001];
int hold[MAX];
int size;
int holder_head;

// 홀더의 크기와 처음 header의 위치를 전달받아 초기화 한다.
void init(int holder_size, int head)
{
	cnt = 1;
	fst_idx = 1;
	dir = true;//왼쪽
	size = holder_size;
	for (int i = 0; i < MAX; ++i) { hold[i] = 0; fst[i] = 0; }// 0은 비어있는거고 -1은 있었는데 뺀거
	fst[MAX] = 0;
	holder_head = head;
}





// CD를 holder의 위치에 저장한다. HEADER의 위치는 변하지 않는다
// 한 번 저장되었던 holder에는 CD가 제거 되더라도 
// 다시 같은 위치에 입력(저장)되는 경우는 없다.
void insert(int holder)
{
	if (!hold[holder]) {
		fst[cnt] = holder;
		hold[holder] = cnt++;
	}
}




// 가장 먼저 저장된 CD를 홀더에서 꺼내고 HEADER의 위치를 리턴한다.
int first()
{
	for (; fst_idx < cnt; ++fst_idx)
	{
		if (fst[fst_idx]) {
			holder_head = fst[fst_idx];
			hold[holder_head] = -1;
			fst[fst_idx] = 0;
			//fst_idx++;
			return holder_head;
		}
	}
}


// HEADER의 현재 위치에서 가장 가까운 곳의 CD를 꺼내고 HEADER의 위치를 리턴한다.
// 거리가 같은 CD가 있다면 커서의 왼쪽에 있는 CD를 우선으로 처리한다.
int near()
{
	int L = holder_head;
	int R = holder_head;
	for (; 0 <= L || R < size; --L, ++R) {
		if (0 <= L)
		{
			if (hold[L] != 0 && hold[L] != -1)
			{
				fst[hold[L]] = 0;
				hold[L] = -1;
				holder_head = L;
				return L;
			}
		}
		if (R < size)
		{
			if (hold[R] != 0 && hold[R] != -1)
			{
				fst[hold[R]] = 0;
				hold[R] = -1;
				holder_head = R;
				return R;
			}
		}
	}
}


// HEADER의 현재 위치에서 바라보던 방향으로 첫 번째 CD를 꺼내고 HEADER의 위치를 리턴한다.
// 바라보던 방향의 끝까지 CD가 한 개도 없으면 반대방향으로 방향을 돌려서 첫 번째 CD를 꺼낸다.
// HEADER는 처음에는 왼쪽을 바라보고 있으며 forward() 함수에서만 바라보는 방향이 바뀔 수 있고 
// 다른 함수에서는 어느쪽으로 이동하든 바라보는 방향은 바뀌지 않는다.
int forward()
{
	 
	if (dir)
	{
		int L = holder_head;
		int R = holder_head;
		for (; 0 <= L; --L) {
			if (hold[L] != 0 && hold[L] != -1)
			{
				fst[hold[L]] = 0;
				hold[L] = -1;
				holder_head = L;
				return L;
			}
		}
		for (; R < size; ++R) {
			if (hold[R] != 0 && hold[R] != -1)
			{
				fst[hold[R]] = 0;
				dir = false;
				hold[R] = -1;
				holder_head = R;
				return R;
			}
		}
	}
	else
	{
		int L = holder_head;
		int R = holder_head;
		for (; R < size; ++R) {
			if (hold[R] != 0 && hold[R] != -1)
			{
				fst[hold[R]] = 0;
				hold[R] = -1;
				holder_head = R;
				return R;
			}
		}
		for (; 0 <= L; --L) {
			if (hold[L] != 0 && hold[L] != -1)
			{
				fst[hold[L]] = 0;
				dir = true;
				hold[L] = -1;
				holder_head = L;
				return L;
			}
		}
	}
}





// HEADER의 현재 위치에서 왼쪽 방향으로 첫 번째 CD를 꺼내고 HEADER의 위치를 리턴한다.
// 왼쪽 끝까지 CD가 한 개도 없으면 holder의 가장 오른쪽으로 이동한 후 다시 왼쪽 방향으로 첫 번째 CD를 꺼낸다. 
int left()
{
	 
	int L = holder_head;
	for (; 0 <= L; --L) {
		if (hold[L] != 0 && hold[L] != -1)
		{
			fst[hold[L]] = 0;
			hold[L] = -1;
			holder_head = L;
			return L;
		}
	}
	L = size - 1;
	for (; 0 <= L; --L) {
		if (hold[L] != 0 && hold[L] != -1)
		{
			fst[hold[L]] = 0;
			hold[L] = -1;
			holder_head = L;
			return L;
		}
	}
}





// HEADER의 현재 위치에서 오른쪽 방향으로 첫 번째 CD를 꺼내고 HEADER의 위치를 리턴한다.
// 오른쪽 끝까지 CD가 한 개도 없으면 holder의 가장 왼쪽으로 이동한 후 다시 오른쪽 방향으로 첫 번째 CD를 꺼낸다. 
int right()
{
	 
	int R = holder_head;
	for (; R < size; ++R) {
		if (hold[R] != 0 && hold[R] != -1)
		{
			fst[hold[R]] = 0;
			hold[R] = -1;
			holder_head = R;
			return R;
		}
	}
	R = 0;
	for (; R < size; ++R) {
		if (hold[R] != 0 && hold[R] != -1)
		{
			fst[hold[R]] = 0;
			hold[R] = -1;
			holder_head = R;
			return R;
		}
	}
}