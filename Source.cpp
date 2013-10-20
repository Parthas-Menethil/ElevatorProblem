#include <iostream>
#include "Package.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
void merge(Package*, Package*, int, int, int);
void mergeSort(Package *a, Package *b, int low, int high){
	int pivot;
	if (low < high){
		pivot = (low + high) / 2;
		mergeSort(a, b, low, pivot);
		mergeSort(a, b, pivot + 1, high);
		merge(a, b, low, pivot, high);
		
	}
}
void merge(Package *a, Package *b, int low, int pivot, int high){
	int h, i, j, k;
	h = low;
	i = low;
	j = pivot + 1;
	while((h <= pivot) && (j <= high)){
		if (a[h].weight <= a[j].weight){
			b[i] = a[h];
			h++;
		}
		else{
			b[i] = a[j];
			j++;
		}
		i++;
	}
	if (h > pivot){
		for (k = j; k <= high; k++){
			b[i] = a[k];
			i++;
		}
	}
	else{
		for (k = h; k <= pivot; k++){
			b[i] = a[k];
			i++;
		}
	}
	for (k = low; k <= high; k++)
		a[k] = b[k];
}

int main(){
	srand(time(NULL));
	int maxFloor = 0, packNumber = 0;
	vector<Package> pkgs;
	cout << "Please enter the max floor: ";
	cin >> maxFloor;
	cout << "Please enter the package number: ";
	cin >> packNumber;
	for(int i = 0; i < packNumber; i++){
		pkgs.push_back(Package(maxFloor));
		cout << "Weight:" << pkgs[i].weight << "kg To:" << pkgs[i].destFloor << endl;
	}
	Package p[packNumber];
	mergeSort(pkgs.data(), p, 0, packNumber - 1);
	for (int i = 0; i < packNumber; i++)
		cout << "Weight: " << p[i].weight << "kg To:" << p[i].destFloor << endl;
	return 0;
}
