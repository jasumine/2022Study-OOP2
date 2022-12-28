#include "GameManager.h"

void generateMap()
{
	int numMine = 10;
	srand((unsigned)time(NULL));

	for (int i = 0; i < numMine; i++)
	{
		while (true)
		{
			int x = (int)rand() % 10;
			int y = (int)rand() % 10;

			if (map[x][y] == 0)
			{
				map[x][y] = -1; 
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] != -2)
			{
				int mineCount = 0;
				for (int ii = max(0, i - 1); ii <= min(9, i + 1); i++)
				{
					for (int jj = max(0, j - 1); jj <= min(9, j + 1; j++)
					{
						if(map[ii][jj]==-2 mineCount;)
					}
				}
			}
		}
	}
}