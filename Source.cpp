#include <iostream>
#include "Package.h"
#include <vector>
#include <ctime>
#include <cstdlib>

#define __DESC(show, msg) {if (show == true) cout << msg << endl;}; 
#define __SWITCH_OUTPUT__ true
using namespace std;
/* Merge Sort Function
 * @Source: http://simplestcodings.blogspot.ca/2010/08/merge-sort-implementation-in-c.html
 * @Author: Varun Gupta
 * @Date: 2010-08-03
 * @Modified by: Luke
 * */
void merge(Package*, Package*, int, int, int);
void mergeSort(Package *a, Package *b, int low, int high){
	int pivot;
	if (low < high){
		pivot = (low + high) / 2;
		mergeSort(a, b, low, pivot);
		mergeSort(a, b, pivot + 1, high);
		merge(a, b, low, pivot, high);
	}
	else{
		if (b && a)
			b[0] = a[0];
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
// Greedy Loading
int greedyLoading(Package *pkgs, const int num){
	int totTime = 0;
	Package p[num];
	mergeSort(pkgs, p, 0, num - 1);
	int processedPackages = 0;
	while (processedPackages < num){
		__DESC (__SWITCH_OUTPUT__, "Elevator start loading...");
		float tWeight = 0, loadCapacity = 10, maxFloor = 0;
		for (; processedPackages < num && p[processedPackages].weight <= loadCapacity; processedPackages++){
			__DESC (__SWITCH_OUTPUT__, "->Load " << p[processedPackages].weight << " kgs");
			p[processedPackages].loaded = true;
			if (p[processedPackages].destFloor > maxFloor)
				maxFloor = p[processedPackages].destFloor;
			tWeight += p[processedPackages].weight;
			loadCapacity -= p[processedPackages].weight;
		}
		totTime += maxFloor * 2;
		__DESC (__SWITCH_OUTPUT__, "->To floor " << maxFloor);
		__DESC (__SWITCH_OUTPUT__, "->Time span: " << maxFloor * 2);
	}
	return totTime;
}
int main(){
	srand(time(NULL));
	int maxFloor = 0, packNumber = 0;
	vector<Package> pkgs;
	cout << "Please enter the max floor: ";
	cin >> maxFloor;
	cout << "Please enter the package number: ";
	cin >> packNumber;
	cout <<"====== Generating Packages ======" << endl;
	for(int i = 0; i < packNumber; i++){
		pkgs.push_back(Package(maxFloor));
		cout << "Weight:" << pkgs[i].weight << "kg To:" << pkgs[i].destFloor << endl;
	}
	cout <<"=================================" << endl;
	cout << "Greedy Elevator Total Time:" << greedyLoading(pkgs.data(), packNumber) << endl;
	
	return 0;
}
