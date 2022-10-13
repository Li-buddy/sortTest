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

class InsertSort:public Sort
{
public:
	InsertSort(std::vector<int>& vecData)
		:Sort(vecData)
	{}

	//void sort() final
	//{
	//	int nCount = m_vecData.size();

	//	//judge first 2
	//	if (nCount < 2)
	//		return;
	//	if (m_vecData[0] > m_vecData[1])
	//	{
	//		int tmp = m_vecData[0];
	//		m_vecData[0] = m_vecData[1];
	//		m_vecData[1] = tmp;
	//		//show();
	//	}

	//	// the last loop for ncount can ignore
	//	int rangeLeft = 0;
	//	int rangeRight = 1;

	//	for (int needJudge = 2; needJudge < nCount; needJudge++)
	//	{
	//		//less than left side
	//		if ((m_vecData[needJudge] < m_vecData[rangeLeft]))
	//		{
	//			int tmpNew = m_vecData[needJudge];
	//			for (int i = needJudge; i > 0; i--)
	//			{
	//				m_vecData[i] = m_vecData[i - 1];
	//			}
	//			m_vecData[0] = tmpNew;
	//			rangeRight++;
	//			//show();
	//			continue;
	//		}

	//		// if less than right side ; greater than left; loop from right
	//		int tmpLocate = rangeRight;
	//		if ((m_vecData[needJudge] < m_vecData[tmpLocate]) && (m_vecData[needJudge] > m_vecData[rangeLeft]))
	//		{
	//			while ((m_vecData[needJudge] < m_vecData[tmpLocate]) &&
	//				(m_vecData[needJudge] > m_vecData[rangeLeft]))
	//			{
	//				tmpLocate--;
	//			}
	//			//right side move to right
	//			int tmpNew = m_vecData[needJudge];
	//			for (int i = needJudge; i > tmpLocate; i--)
	//			{
	//				m_vecData[i] = m_vecData[i - 1];
	//			}
	//			m_vecData[tmpLocate+1] = tmpNew;
	//			rangeRight++;
	//			//show();
	//			continue;
	//		}

	//		// if greater than right side
	//		// just place it right here. skip
	//		if (m_vecData[needJudge] >= m_vecData[rangeRight])
	//		{
	//			// range increase 1
	//			rangeRight++;
	//			//show();
	//		}
	//	}

	//	//show();
	//}

	void sort()
	{
		int nCount = m_vecData.size();
		if (nCount < 2)
		{
			return;
		}

		for (int i = 1; i < nCount; i++)
		{
			int newValue = m_vecData[i];
			int labelPos = i;

			//handle move
			while ((labelPos > 0)&&(m_vecData[labelPos-1]>newValue))
			{
				// move to right
				m_vecData[labelPos] = m_vecData[labelPos - 1];
				//move signal pos
				labelPos--;
			}

			//insert
			m_vecData[labelPos] = newValue;
		}
	}

public:
	
};