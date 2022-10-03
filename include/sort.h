#pragma once
#include "isort.h"
#include <iostream>

class Sort : public ISort
{
public:
	Sort(std::vector<int>& vecData)
		:m_vecData(vecData)
	{}
	virtual ~Sort() = default;

	void show() override
	{
		std::vector<int>::const_iterator it;
		for (it = m_vecData.cbegin(); it != m_vecData.cend(); it++)
		{
			if (it != m_vecData.cend() - 1)
			{
				std::cout << *it << "->";
			}
			else
			{
				std::cout << *it << std::endl;
			}
		}
		std::cout << std::endl;
	}

protected:
	std::vector<int> m_vecData;
};