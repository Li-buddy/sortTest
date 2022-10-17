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

	void heapify(int nIndex,int endPos)
	{
		//本质是节点与两个子节点比较大小，最大者作为父节点
		int tmp = m_vecData[nIndex];

		//对该节点的左右节点进行判断
		for (int j = 2 * nIndex+1; j <= endPos; j *= 2)
		{
			if (j < endPos && m_vecData[j] < m_vecData[j + 1])
			{
				++j;
			}
			//如果新节点大于两个子节点则不需要交换
			if (tmp >= m_vecData[j])
				break;

			//如果新节点小于，则进行交换
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

		// 从最后一个非叶子节点开始  
		for (int i = nCount / 2; i >= 0; i--)
		{
			heapify(i, nCount-1);
		}

		for (int i = nCount-1; i > 0; i--)
		{
			std::swap(m_vecData[i], m_vecData[0]);
			heapify(0, i-1);
		}
	}

public:
	
};