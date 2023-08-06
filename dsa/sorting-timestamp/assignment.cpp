#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
#define size 200000
using namespace std;
using namespace std::chrono; 

void write(int*);

void generate_numbers() {
	fstream write;
	write.open("rand.txt", ios::out);

	srand(time(NULL));
	long int i;

	if (!write) {
		cout << "Error while creating file\n";
	}
	else {
		for (i = 0; i < size; i++) {
			write << rand() << endl;
		}
		cout << "Numbers generated succefully!\n";
	}
}

void selection_sort(int* arr) {
	long int i, j = 0;

	for (i = 0; i < size; i++) {
		long int minIndex = i;
		for (j = i + 1; j < size; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

void write(int* arr) {
	fstream write;
	write.open("sorted.txt", ios::out);

	long int i;

	if (!write) {
		cout << "Error while creating file\n";
	}
	else {
		for (i = 0; i < size; i++) {
			write << arr[i] << endl;
		}
		write.close();
	}
	cout << "sorted\n";
}

void read(int* arr) {
	ifstream read("rand.txt");
	long int i = 0;

	if (!read) {
		cout << "File does not exist\n";
	}
	else {
		int x;
		while (read >> x) {
			arr[i] = x;
			i++;
		}
		read.close();
	}
}

int main() {
	generate_numbers();

	long int i;
	int* arr = new int[size];

	for (i = 0; i < size; i++) {
		arr[i] = 0;
	}

	read(arr);
	
	auto start = high_resolution_clock::now(); 
	selection_sort(arr);
	auto stop = high_resolution_clock::now(); 
	auto duration = duration_cast<seconds>(stop - start);

	cout<<size<<" numbers sorted in "<<duration.count()<<endl; 

	write(arr);

	return 0; 
}