/**
 * Threads that waste CPU cycles
 */
#include <iostream>
#include <thread>
#include <chrono>

// a simple function that wastes CPU cycles "forever"
void cpu_waster() {
    std::cout << "CPU Waster Process ID: " << _getpid() << std::endl;
    std::cout << "CPU Waster Thread ID: " << std::this_thread::get_id() << std::endl;
    while (true) continue;
}

int main() {
    std::cout << "Main Process ID: " << _getpid() << std::endl;
    std::cout << "Main Thread ID: " << std::this_thread::get_id() << std::endl;
    std::thread thread1(cpu_waster);
    std::thread thread2(cpu_waster);

    while (true) {
        // keep the main thread alive "forever"
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}