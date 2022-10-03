#pragma once
class ISort
{
public:
	ISort() = default;
	virtual ~ISort() = default;

	virtual void sort() = 0;
	virtual void show() = 0;
};