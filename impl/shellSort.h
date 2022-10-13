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

class ShellSort : public Sort
{
public:
	ShellSort(std::vector<int>& vecData)
		:Sort(vecData)
	{}

	//void sort() final
	//{
	//	int nCount = m_vecData.size();
	//	if (nCount < 2)
	//	{
	//		return;
	//	}

	//	// define the step
	//	int nIncrease = nCount / 2;
	//	while (nIncrease >= 1)
	//	{
	//		for (int i = 0; i < nCount -nIncrease; )
	//		{
	//			if (m_vecData[i] > m_vecData[i + nIncrease])
	//			{        
	//				int tmp = m_vecData[i];
	//				m_vecData[i] = m_vecData[i + nIncrease];
	//				m_vecData[i + nIncrease] = tmp;
	//				//show();
	//				if (i > 0)
	//				{
	//					i--;
	//				}
	//			}
	//			else
	//			{
	//				i++;
	//			}
	//		}
	//		nIncrease /= 2;
	//	}
	//}

	void sort()
	{
		int nCount = m_vecData.size();
		if (nCount < 2)
		{
			return;
		}

		for (int step = nCount / 2; step >= 1; step /= 2)
		{
			for (int i = step; i < nCount; i++)
			{
				int newValue = m_vecData[i];
				int labelPos = i;

				while ((labelPos >= step) && (m_vecData[labelPos - step] > newValue))
				{
					m_vecData[labelPos] = m_vecData[labelPos - step];
					labelPos-=step;
				}

				m_vecData[labelPos] = newValue;
			}
		}
	}

public:
};