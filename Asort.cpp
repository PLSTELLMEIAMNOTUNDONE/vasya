

#include <iostream>
using namespace std;

void PrintM(int* m,int n) {
	for (int i = 0; i < n; i++) cout << m[i] << "\t";
	cout << "\n";
}
void Merge(int arr[], int p, int q, int r) {
	int len1 = q - p+1, len2 = r - q,
	* L = new int[len1], * R = new int[len2];
	for (int k = 0; k < len1; k++)L[k] = arr[p-1+k];
	for (int k = 0; k < len2; k++)R[k] =arr[q+k];
	int i = 0, j = 0;
	for (int k = p-1; k < r; k++) {
		if (j == len2)arr[k] = L[i++];
		else if (i == len1)arr[k] = R[j++];
		else arr[k] = L[i] < R[j] ? L[i++] : R[j++]; 
	}
	
	delete[](L); delete[](R);
}
void MergeSort(int arr[], int p, int r) {
	if(p<r) {
		int q = (r+p)/2;
		
		MergeSort(arr, p, q);
		MergeSort(arr, q+1, r);
		Merge(arr, p, q, r);
		
	}
}
int main()
{
	int arr[8] ={5, 2, 4, 6, 1, 3, 2, 6};
	
	PrintM(arr,8);
	MergeSort(arr, 1,8);
	PrintM(arr, 8);
}
