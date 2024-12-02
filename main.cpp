#include <stdio.h>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
int current_thread = 1;

void Print(int thread_id, const std::string& message) { 
	std::unique_lock<std::mutex> lock(mtx);
	cv.wait(lock, [thread_id]() { return current_thread == thread_id; });

	std::cout << message << std::endl;

	current_thread++;
	cv.notify_all();
}

int main() {
	std::thread t1(Print, 1, "thread1");
	std::thread t2(Print, 2, "thread2");
	std::thread t3(Print, 3, "thread3");

	t1.join();
	t2.join();
	t3.join();

	return 0;
}