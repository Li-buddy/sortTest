#pragma once

#include <vector>
#include "../include/sort.h"

class BubbleSort : public Sort
{
public:
	BubbleSort(std::vector<int>& vecData)
		:Sort(vecData, sort::SORT_TYPE::SORT_BUBBLE)
	{
	}

	void sort() final
	{
		int nCount = m_vecData.size();
		if (nCount < 2)
		{
			return;
		}

		for (int j = 0; j < nCount; j++)
		{
			for (int i = 1; i < nCount; i++)
			{
				int faster = i;
				int slower = faster -1;
				if (m_vecData[faster] < m_vecData[slower])
				{
					int tmpValue = m_vecData[faster];
					m_vecData[faster] = m_vecData[slower];
					m_vecData[slower] = tmpValue;
					//show();
				}
			}
		}
	}

public:
};