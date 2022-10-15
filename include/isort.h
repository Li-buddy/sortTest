#pragma once

namespace sort {

	enum class SORT_TYPE{
		SORT_UNDEFINED = -1,
		SORT_BUBBLE,
		SORT_SELECT,
		SORT_INSERT,
		SORT_SHELL,
		SORT_QUICK
	};

	class ISort
	{
	public:
		virtual ~ISort() = default;

		virtual void sort() = 0;
		virtual void show() = 0;
		virtual const char* getSortName() = 0;
	};
}