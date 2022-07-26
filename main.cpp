#include<iostream>
using namespace std;

//Description of QuickSort algorithm: (from https://en.wikipedia.org/wiki/Quicksort#Algorithm)
//1.If the range has fewer than two elements, return immediately as there is nothing to do. 
//	Possibly for other very short lengths a special-purpose sorting method is applied and the remainder of these steps skipped.
//2.Otherwise pick a value, called a pivot, that occurs in the range(the precise manner of choosing depends on the partition routine,
//	and can involve randomness).
//3.Partition the range : reorder its elements, while determining a point of division, so that all elements
//	with values less than the pivot come before the division, while all elements with values greater than the pivot come after it;
//	elements that are equal to the pivot can go either way.Since at least one instance of the pivot is present,
//	most partition routines ensure that the value that ends up at the point of division is equal to the pivot, and is now in 
//	its final position(but termination of quicksort does not depend on this, as long as sub - ranges strictly
//	smaller than the original are produced).
//4.Recursively apply the quicksort to the sub - range up to the point of division and to the sub - range after it,
//	possibly excluding from both ranges the element equal to the pivot at the point of division. (If the partition
//	produces a possibly larger sub - range near the boundary where all elements are known to be equal to the pivot, 
//	these can be excluded as well.)

void swap(double array[], int n, int m) {
	double copy = array[n];
	array[n] = array[m];
	array[m] = copy;
}


int partition(double array[], int lb, int hb, double pivot) {
	
	//int i = lb;
	//int j = hb;
	int count = 0;

	//Since pivot is the first value of the array, we will count all elements which are smaller
	// and assing it the correct position
	for (int i = lb + 1; i <= hb; i++) {
		if (array[i] < pivot) {
			count++;
		}
	}
	int pivotIndex = lb + count;
	//swap pivot value to correct place
	swap(array[pivotIndex], array[lb]);

	// Sorting left and right parts of the pivot element
	int i = lb, j = hb;

	while (i < pivotIndex && j > pivotIndex) {

		while (array[i] <= pivot) {
			i++;
		}

		while (array[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(array[i++], array[j--]);
		}
	}

	return pivotIndex;
}

void QuickSort(double array[], int lb, int hb) {
	if (hb == 1 && lb == 0) {
		if (array[1] < array[0]) {
			swap(array, 0, 1);
		}
	}
	else if (lb < hb) {
		//the value at the first position (==lb) will be the pivot
		double pivot = array[lb];
		int position = partition(array, lb, hb, pivot);
		//Find position at which to partition the array

		QuickSort(array, lb, position - 1);
		QuickSort(array, position + 1, hb);
	}


}



int main() {

	int n;
	cout << "Enter size of array: (max 10) \n";
	cin >> n;

	double a[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	//double *a = new double[n];

	if (n <= 10) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
	}
	else {
		cout << "Invalid input!";
		return 0;
	}

	QuickSort(a, 0, n-1);

	cout << "Sorted array: \n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}

	return 1;
}