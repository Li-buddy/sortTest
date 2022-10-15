#pragma once

#include <vector>
#include "../include/sort.h"

class QuickSort:public Sort
{
public:
	QuickSort(std::vector<int>& vecData)
		:Sort(vecData, sort::SORT_TYPE::SORT_QUICK)
	{
	}

	int partition(int startPos, int endPos, std::vector<int>& vecData)
	{
		int pivot = vecData[endPos];
		int nLabel = startPos;
		for (int i = startPos; i < endPos; i++)
		{						
			if (vecData[i] < pivot)
			{
				std::swap(vecData[i], vecData[nLabel]);
				nLabel++;
			}
		}
		std::swap(vecData[endPos], vecData[nLabel]);
		//show();
		return nLabel;
	}

	void QSort(int startPos, int endPos, std::vector<int>& vecData)
	{
		if (startPos > endPos)
		{
			return;
		}

		int nBoundary = partition(startPos, endPos, vecData);
		QSort(startPos, nBoundary-1, vecData);
		QSort(nBoundary+1, endPos, vecData);
	}

	void sort()
	{
		int nCount = m_vecData.size();
		if (nCount < 2)
		{
			return;
		}
		//show();
		QSort(0, nCount-1, m_vecData);
	}

public:
	
};