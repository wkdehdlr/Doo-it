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

// Ȧ���� ũ��� ó�� header�� ��ġ�� ���޹޾� �ʱ�ȭ �Ѵ�.
void init(int holder_size, int head)
{
	cnt = 1;
	fst_idx = 1;
	dir = true;//����
	size = holder_size;
	for (int i = 0; i < MAX; ++i) { hold[i] = 0; fst[i] = 0; }// 0�� ����ִ°Ű� -1�� �־��µ� ����
	fst[MAX] = 0;
	holder_head = head;
}





// CD�� holder�� ��ġ�� �����Ѵ�. HEADER�� ��ġ�� ������ �ʴ´�
// �� �� ����Ǿ��� holder���� CD�� ���� �Ǵ��� 
// �ٽ� ���� ��ġ�� �Է�(����)�Ǵ� ���� ����.
void insert(int holder)
{
	if (!hold[holder]) {
		fst[cnt] = holder;
		hold[holder] = cnt++;
	}
}




// ���� ���� ����� CD�� Ȧ������ ������ HEADER�� ��ġ�� �����Ѵ�.
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


// HEADER�� ���� ��ġ���� ���� ����� ���� CD�� ������ HEADER�� ��ġ�� �����Ѵ�.
// �Ÿ��� ���� CD�� �ִٸ� Ŀ���� ���ʿ� �ִ� CD�� �켱���� ó���Ѵ�.
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


// HEADER�� ���� ��ġ���� �ٶ󺸴� �������� ù ��° CD�� ������ HEADER�� ��ġ�� �����Ѵ�.
// �ٶ󺸴� ������ ������ CD�� �� ���� ������ �ݴ�������� ������ ������ ù ��° CD�� ������.
// HEADER�� ó������ ������ �ٶ󺸰� ������ forward() �Լ������� �ٶ󺸴� ������ �ٲ� �� �ְ� 
// �ٸ� �Լ������� ��������� �̵��ϵ� �ٶ󺸴� ������ �ٲ��� �ʴ´�.
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





// HEADER�� ���� ��ġ���� ���� �������� ù ��° CD�� ������ HEADER�� ��ġ�� �����Ѵ�.
// ���� ������ CD�� �� ���� ������ holder�� ���� ���������� �̵��� �� �ٽ� ���� �������� ù ��° CD�� ������. 
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





// HEADER�� ���� ��ġ���� ������ �������� ù ��° CD�� ������ HEADER�� ��ġ�� �����Ѵ�.
// ������ ������ CD�� �� ���� ������ holder�� ���� �������� �̵��� �� �ٽ� ������ �������� ù ��° CD�� ������. 
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