#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
#define size 7000000
using namespace std;
using namespace std::chrono; 

void generate_numbers() {
	ofstream write; 
	write.open("rand.txt", ios::out); 

	srand(time(100)); 
	long int i; 

	if (!write) {
		cout << "Error while creating file\n"; 
	}
	else {
		for (i = 0; i < size; i++) {
			write << rand() << endl;
		}
		write.close();
		cout << "Numbers generated succesfully\n"; 
	}
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

void write(int* arr) {
	fstream write; 
	write.open("m_sort.txt", ios::out);
	long int i; 

	if (!write) {
		cout << "Error while creating file\n";
	}
	else {
		for (i = 0; i < size; i++) {
			write << arr[i] << endl;
		}
		write.close();
		cout << "Sorted\n";
	}
}

void Merge(int* a, int low, int high, int mid)
{
	int *temp = new int[high - low + 1];
	int i, j, k;
	i = low;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}

	for (i = low; i <= high; i++)
	{
		a[i] = temp[i - low];
	}
}

void MergeSort(int* arr, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		
		MergeSort(arr, low, mid);
		MergeSort(arr, mid + 1, high);
		Merge(arr, low, high, mid);
	}
}

int main() {
	generate_numbers();

	int* arr = new int[size];
	long int i;

	for (i = 0; i < size; i++) {
		arr[i] = 0; 
	}

	read(arr); 
	auto start = high_resolution_clock::now();
	MergeSort(arr, 0, size - 1);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);
	auto d = duration_cast<microseconds>(stop - start);
	cout << size << " numbers sorted in " << duration.count() << " seconds" << endl;
	cout << size << " numbers sorted in " << d.count() << " microseconds" << endl;

	write(arr);

	return 0; 
}