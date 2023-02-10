#include <iostream>
#include <thread> //библиотека потоков
#include <chrono> //время
const auto x = [](int a) {
	const auto  y = [a](int b) {
		return a + b + 5;
	};
	return y(10);
};
void work(int x) {
	std::cout << "Work started\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "work thread " << std::this_thread::get_id() << '\n';
	std::cout << "work ended\n";
}
int main() {
	setlocale(LC_ALL, "Russian");
	//std::cout << x(6) << '\n';
	std::cout<<"main thread " << std::this_thread::get_id() << '\n';
	std::thread t1(work,2000);
	std::cout << "hello!\n";
	std::thread t2(work,3000);
	t1.join();//после создание потока обязательно подцеплять его обратно 
	t2.join();
	return 0;
}