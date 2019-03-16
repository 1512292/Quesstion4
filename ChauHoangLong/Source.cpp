#include <iostream>
#include <thread>
#include <mutex>
#include "IVehicle.h"
 
typedef int semaphore;

IVehicle* bmw = new BMWCar();
IVehicle* toyota = new ToyotaCar();
mutex mtx;
semaphore mutexBMW = 2;
semaphore mutexToyota = 1;

void runBMW() {
	if (mutexBMW--) {
		bmw->run();
		mutexToyota++;
	}
}

void runToyota() {
	if (mutexToyota--) {
		toyota->run();
		mutexBMW++;
	}
}

void main() {

	

	std::thread toyotaThread(runToyota);
	std::thread bmwThread(runBMW);

	toyotaThread.join();
	bmwThread.join();

	delete bmw;
	delete toyota;
	system("pause");

}