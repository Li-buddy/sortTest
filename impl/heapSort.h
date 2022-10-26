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
		int nLeft = 2 * nIndex + 1;
		int nright = nLeft + 1;
		for (nLeft; nLeft <= endPos; nLeft *= 2+1)  // move to child layer
		{
			if (nLeft < endPos && m_vecData[nLeft] < m_vecData[nright])
			{
				++nLeft;
			}
			//如果新节点大于两个子节点则不需要交换
			if (tmp >= m_vecData[nLeft])
				break;

			//如果新节点小于，则进行交换
			m_vecData[nIndex] = m_vecData[nLeft];
			nIndex = nLeft;
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
		for (int i = nCount / 2-1; i >= 0; i--)
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