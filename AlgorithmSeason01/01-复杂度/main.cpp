#include "main.h"


// 定义 Task 类型为接收无参数并返回 void 的函数
typedef std::function<void()> Task;

void Times::test(const std::string& title, Task task) {
	if (!task) return; // 如果 task 为空，则直接返回

	// 格式化标题
	std::string displayTitle = (title.empty()) ? "" : ("【" + title + "】");
	std::cout << displayTitle << std::endl;

	// 打印开始时间
	auto start = std::chrono::system_clock::now();
	std::cout << "开始：" << getCurrentTime() << std::endl;

	// 执行任务
	task();

	// 打印结束时间
	auto end = std::chrono::system_clock::now();
	std::cout << "结束：" << getCurrentTime() << std::endl;

	// 计算并打印耗时
	auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0;
	std::cout << "耗时：" << delta << "秒" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}

int Times::fib1(int n) {
	if (n <= 1) return n;
	return fib1(n - 1) + fib1(n - 2);
}

int Times::fib2(int n) {
	if (n <= 1) return n;

	int first = 0, second = 1;
	for (int i = 0; i < n - 1; ++i) {
		int sum = first + second;
		first = second;
		second = sum;
	}
	return second;
}

int Times::fib3(int n) {
	if (n <= 1) return n;

	int first = 0, second = 1;
	while (n-- > 1) {
		second += first;
		first = second - first;
	}
	return second;
}

void Times::test1(int n) {
	if (n > 10) {
		std::cout << "n > 10" << std::endl;
	}
	else if (n > 5) {
		std::cout << "n > 5" << std::endl;
	}
	else {
		std::cout << "n <= 5" << std::endl;
	}
	for (int i = 0; i < 4; ++i) {
		std::cout << "test" << std::endl;
	}
}

void Times::test2(int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << "test" << std::endl;
	}
}

void Times::test3(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << "test" << std::endl;
		}
	}
}

void Times::test4(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 15; ++j) {
			std::cout << "test" << std::endl;
		}
	}
}

void Times::test5(int n) {
	while ((n = n / 2) > 0) {
		std::cout << "test" << std::endl;
	}
}

void Times::test6(int n) {
	while ((n = n / 5) > 0) {
		std::cout << "test" << std::endl;
	}
}

void Times::test7(int n) {
	for (int i = 1; i < n; i = i * 2) {
		for (int j = 0; j < n; ++j) {
			std::cout << "test" << std::endl;
		}
	}
}

void Times::test10(int n) {
	int a = 10, b = 20, c = a + b;
	std::vector<int> array(n);
	for (int i = 0; i < n; ++i) {
		std::cout << array[i] + c << std::endl;
	}
}


std::string Times::getCurrentTime() {
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::tm buf;  // 创建一个 tm 结构体用于 localtime_s
	localtime_s(&buf, &in_time_t);  // 使用 localtime_s 而不是 localtime

	std::stringstream ss;
	ss << std::put_time(&buf, "%X"); // 使用 std::put_time 格式化时间

	auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
	ss << '.' << std::setfill('0') << std::setw(3) << milliseconds.count();

	return ss.str();
}

// 一个例子，测试 Times 类
int main() {
	Times times; // 创建 Times 类的对象
	times.test("fib1", [&times]() {
		// 放入你需要测试耗时的代码
		times.fib1(40);
		});
	times.test("fib2", [&times]() {
		// 放入你需要测试耗时的代码
		times.fib2(8000000);
		});
	times.test("fib3", [&times]() {
		// 放入你需要测试耗时的代码
		times.fib3(8000000);
		});
	times.test("test10", [&times]() {
		// 放入你需要测试耗时的代码
		times.test10(8);
		});
	return 0;
}


