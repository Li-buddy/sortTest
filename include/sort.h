#pragma once
#include "isort.h"
#include <iostream>
#include <string>

using namespace sort;

class Sort : public ISort
{
public:
	Sort(std::vector<int>& vecData, sort::SORT_TYPE sortType)
		:m_vecData(vecData), m_typeIdentity(sortType),m_strName(sortType2String(sortType))
	{
		std::cout << getSortName() << std::endl;
	}
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

	const char* getSortName()
	{
		return m_strName.c_str();
	}

protected:
	static::std::string sortType2String(sort::SORT_TYPE& type)
	{
		switch (type)
		{
		case sort::SORT_TYPE::SORT_BUBBLE:
			return std::string("Bubble Sort");
		case sort::SORT_TYPE::SORT_SELECT:
			return std::string("Select Sort");
		case sort::SORT_TYPE::SORT_INSERT:
			return std::string("Insert Sort");
		case sort::SORT_TYPE::SORT_SHELL:
			return std::string("Shell Sort");
		case sort::SORT_TYPE::SORT_QUICK:
			return std::string("Quick Sort");
		default:
			return std::string("undefined_sort");
		}
	}

protected:
	std::vector<int> m_vecData;
	sort::SORT_TYPE  m_typeIdentity;
	std::string      m_strName{};
};