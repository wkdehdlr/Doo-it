#ifndef _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 
#endif 

#include<stdio.h> 

#define SOUND_MAX_LENGTH (200) 
#define NEW_SOUND_LENGTH (8) 

static int randomSeed, soundNum, lengthLimit, queryCount;
static int soundData[10005][SOUND_MAX_LENGTH];
static int newData[10005];

extern void initUser(int soundNum);
extern void registerSound(int soundID, int soundLen, int soundArr[SOUND_MAX_LENGTH]);
extern int  plagiarismCheck(int newData[NEW_SOUND_LENGTH]);


static int getRand(void)
{
	randomSeed = randomSeed * 0x343FD + 0x296EC3;
	return (randomSeed >> 16) & 0x7FFF;
}

static void generateSoundData()
{
	int param[SOUND_MAX_LENGTH];
	int music_len_param;
	for (int id = 1; id <= soundNum; id++)
	{
		music_len_param = newData[id] = getRand() % lengthLimit + 1;

		if (newData[id] < NEW_SOUND_LENGTH)
			music_len_param = newData[id] = NEW_SOUND_LENGTH;

		for (int i = 0; i < newData[id]; i++)
		{
			param[i] = soundData[id][i] = getRand() - 16384;
		}

		registerSound(id, music_len_param, param);
	}
}

static bool generateNewData()
{
	int param[NEW_SOUND_LENGTH];

	int soundID = getRand() % soundNum + 1;
	int stIdx = getRand() % newData[soundID];

	if (stIdx + NEW_SOUND_LENGTH >= newData[soundID])
	{
		stIdx = newData[soundID] - NEW_SOUND_LENGTH;
	}

	for (int i = 0; i < NEW_SOUND_LENGTH; i++)
	{
		param[i] = soundData[soundID][i + stIdx] + getRand() % 256 - 128;
	}


	int return_val = plagiarismCheck(param);

	return return_val == soundID;
}

int main()
{
	setbuf(stdout, NULL);
	int testCase, totalScore = 0;

	// freopen("input.txt", "r", stdin); 

	scanf("%d", &testCase);

	for (int tc = 1; tc <= testCase; tc++)
	{
		scanf("%d%d%d%d", &randomSeed, &soundNum, &lengthLimit, &queryCount);

		int correctCount = 0;

		initUser(soundNum);
		generateSoundData();

		for (int query = 0; query < queryCount; query++)
		{
			if (generateNewData())
				correctCount++;
		}
		if (correctCount == queryCount)
		{
			printf("#%d 100\n", tc);
			totalScore += 100;
		}
		else
		{
			printf("#%d 0\n", tc);
		}
	}
	printf("Total Score : %d\n", totalScore / testCase);

	return 0;
}