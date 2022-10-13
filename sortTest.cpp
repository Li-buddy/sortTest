// sortTest.cpp: 定义应用程序的入口点。
//

#include "sortTest.h"
#include "impl/selectionSort.h"
#include "impl/bubbleSort.h"
#include "impl/insertSort.h"
#include "impl/shellSort.h"
#include <chrono>

using namespace std;

int main()
{
	/*std::vector<int> data{7,5,9,8,6,1};
	SelectionSort sls(data);

	sls.show();
	sls.sort();

	std::vector<int> data2{ 7,5,9,8,6,1 };
	BubbleSort bb(data2);

	bb.show();
	bb.sort();*/

	std::vector<int> data3{ 9,5,4,3,2,1,8,9,5,4,3,2,1,8,9,5,4,3,2,1,8 };
	InsertSort ins(data3);

	ins.show();
	auto start = std::chrono::high_resolution_clock::now();
	ins.sort();
	auto end = std::chrono::high_resolution_clock::now();

	auto spend = end - start;
	std::cout << "spend time: " << spend.count() << std::endl;

	std::vector<int> data4{ 9,5,4,3,2,1,8,9,5,4,3,2,1,8,9,5,4,3,2,1,8 };
	ShellSort ss(data4);

	auto startt = std::chrono::high_resolution_clock::now();
	ss.sort();
	auto endt = std::chrono::high_resolution_clock::now();

	auto spendt = endt - startt;
	std::cout << "spend time: " << spendt.count() << std::endl;

	/*std::vector<int> data2{ 7,5,9,8,6,1 };
	InsertSort ins(data2);

	ins.show();
	ins.sort(); 
	ins.show();*/

	/*std::vector<int> data2{ 7,5,9,8,6,1 };
	ShellSort sst(data2);

	sst.show();
	sst.sort();
	sst.show();*/

	return 0;
}
