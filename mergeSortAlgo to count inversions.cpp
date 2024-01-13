#include <bits/stdc++.h>
using namespace std;

int merge(){
	vector <int> temp;
	int left = low;
	int right = mid + 1;
	while(left <= mid and right <= high){
		if(arr[left] <= arr[right]){
			temp.push_back(arr[left]);
			left++;
		}
		else{
			temp.push_back(arr[right]);
			cnt += (mid-left+1);
			right++;
		}
	}

	while(left <= mid){
		temp.push_back(arr[left]);
		left++;
	}

	while(right <= high){
		temp.push_back(arr[right]);
		right++;
	}

	return cnt;

}

int mergeSort(vector<int> &arr, int low, int high){
	if(low >= high) return;
	int cnt = 0;
	int mid = (low + high) / 2;
	mergeSort(arr, low, mid);
	mergeSort(arr, mid + 1, high);
	merge(arr, low, mid, high);
	return cnt;
}