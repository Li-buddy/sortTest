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
		//�����ǽڵ��������ӽڵ�Ƚϴ�С���������Ϊ���ڵ�
		int tmp = m_vecData[nIndex];
		//�Ըýڵ�����ҽڵ�����ж�
		int nLeft = 2 * nIndex + 1;
		int nright = nLeft + 1;
		for (nLeft; nLeft <= endPos; nLeft *= 2+1)  // move to child layer
		{
			if (nLeft < endPos && m_vecData[nLeft] < m_vecData[nright])
			{
				++nLeft;
			}
			//����½ڵ���������ӽڵ�����Ҫ����
			if (tmp >= m_vecData[nLeft])
				break;

			//����½ڵ�С�ڣ�����н���
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

		// �����һ����Ҷ�ӽڵ㿪ʼ  
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