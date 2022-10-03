#pragma once

#include <vector>
#include "../include/sort.h"
/// <SelectionSort>
/// principle:
/// select the min value 
/// put it on the left side
/// the scale of the problem will reduce
/// 9->5->2->7
/// 
/// 2->5->9->7
/// 2->5->9->7
/// 2->5->7->9
/// 2->5->7->9  //this line can be optimized
/// </summary>

class BubbleSort : public Sort
{
public:
	BubbleSort(std::vector<int>& vecData)
		:Sort(vecData)
	{}

	void sort() final
	{
		int nCount = m_vecData.size();
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
					show();
				}
			}
		}
	}

public:
};