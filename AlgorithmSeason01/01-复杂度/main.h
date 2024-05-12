#pragma once
#include <iostream>
#include <chrono>
#include <functional>
#include <windows.h>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cmath>

class Times
{
public:
	typedef std::function<void()> Task;
	void test(const std::string& title, Task task);
	int fib1(int n);
	int fib2(int n);
	int fib3(int n);
	void test1(int n);
	void test2(int n);
	void test3(int n);
	void test4(int n);
	void test5(int n);
	void test6(int n);
	void test7(int n);
	void test10(int n);
private:
	std::string getCurrentTime();
};



