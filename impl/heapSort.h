#pragma once

#include <vector>
#include "../include/sort.h"

class HeapSort:public Sort
{
public:
	HeapSort(std::vector<int>& vecData)
		:Sort(vecData, sort::SORT_TYPE::SORT_HEAP)
	{
	}

	void heapify(int nIndex)
	{
		int tmp = m_vecData[nIndex];
		int endPos = m_vecData.size() - 1;

		for (int j = 2 * nIndex+1; j <= endPos; j *= 2)
		{
			if (j < endPos && m_vecData[j] < m_vecData[j + 1])
			{
				++j;
			}
			if (tmp >= m_vecData[j])
				break;
			m_vecData[nIndex] = m_vecData[j];
			nIndex = j;
		}
		m_vecData[nIndex] = tmp;
	}

	void sort()
	{
		int nCount = m_vecData.size();
		if (nCount < 2)
		{
			return;
		}
		for (int i = nCount / 2; i >= 0; i--)
		{
			heapify(i);
		}

	}

public:
	
};