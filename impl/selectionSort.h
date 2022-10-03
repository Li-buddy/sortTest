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

class SelectionSort : public Sort
{
public:
	SelectionSort(std::vector<int>& vecData)
		:Sort(vecData)
	{}

	void sort() final
	{
		int nCount = m_vecData.size();
		// the last loop for ncount can ignore
		//for (int j = 0; j < nCount ; j++)
		for (int j = 0; j < nCount-1; j++)
		{
			int small = j;
			int tmp = m_vecData[j];

			//select to the smallest element every time.
			//notice the internal loop start position
			for (int i = j; i < nCount; i++)
			{
				if (tmp > m_vecData[i])
				{
					small = i;
					tmp = m_vecData[i];
				}
			}

			//replace small and left
			int tmpValue = m_vecData[j];
			m_vecData[j] = m_vecData[small];
			m_vecData[small] = tmpValue;
			show();
		}
	}

public:
};