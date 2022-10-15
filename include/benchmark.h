#pragma once

#include <chrono>
#include "isort.h"
#include <iostream>
#include <string>

struct PerformanceResult
{
	std::chrono::high_resolution_clock::time_point m_start{};
	std::chrono::high_resolution_clock::time_point m_end{};
	std::chrono::high_resolution_clock::duration m_duration;
	void beginMeasure()
	{
		m_start = std::chrono::high_resolution_clock::now();
	}

	void finish()
	{
		m_end = std::chrono::high_resolution_clock::now();
		m_duration = m_end - m_start;
	}
};

class BenchMark
{
public:
	BenchMark( ISort* const pSort)
		:m_pSort(pSort)
	{
		std::cout << "benchmark for : " << (m_pSort->getSortName()) << std::endl;
	}
	void measure()
	{
		m_performance.beginMeasure();
		m_pSort->sort();
		m_performance.finish();
		result();
	}

	void result()
	{
		std::cout << m_pSort->getSortName() << " cost : " << m_performance.m_duration.count() << std::endl;
	}

private:
	ISort* const      m_pSort = nullptr;   // pointer to sort algorithm
	PerformanceResult m_performance;
};