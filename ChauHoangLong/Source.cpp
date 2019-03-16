#include <iostream>
#include <thread>
#include <mutex>
#include "IVehicle.h"
 
typedef int semaphore;

IVehicle* bmw = new BMWCar();
IVehicle* toyota = new ToyotaCar();
mutex mtx;
semaphore mutexBMW = 1;
semaphore mutexToyota = 0;

void runBMW() {
	std::mutex
}


void main() {

	

	std::thread toyotaThread(run, toyota);
	std::thread bmwThread(run, bmw);

	toyotaThread.join();
	bmwThread.join();

	delete bmw;
	delete toyota;
	system("pause");

}