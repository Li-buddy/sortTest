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
		for (int j = 2 * nIndex+1; j <= endPos; j *= 2)
		{
			if (j < endPos && m_vecData[j] < m_vecData[j + 1])
			{
				++j;
			}
			//����½ڵ���������ӽڵ�����Ҫ����
			if (tmp >= m_vecData[j])
				break;

			//����½ڵ�С�ڣ�����н���
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

		// �����һ����Ҷ�ӽڵ㿪ʼ  
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