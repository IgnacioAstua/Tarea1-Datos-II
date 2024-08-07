#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int l = 2000000;

void generator () {
    int list[l];
    ofstream file;
    ofstream *pfile = &file;
    file.open("/home/nacho/Escritorio/Archivos/hola.bin");

    for (int i = 0; i < l; ++i) {
        *pfile << list[i];
    }
    file.close();
}
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already
			// in place
				for (j = 0; j < n - i - 1; j++)
					if (arr[j] > arr[j + 1])
						swap(arr[j], arr[j + 1]);
}
void insertionSort(int array[], int size) {
	for (int step = 1; step < size; step++) {
		int key = array[step];
		int j = step - 1;

		// Compare key with each element on the left of it until an element smaller than
		// it is found.
		// For descending order, change key<array[j] to key>array[j].
		while (key < array[j] && j >= 0) {
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}
}
void swap(int arr[] , int pos1, int pos2){
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot){
	int i = low;
	int j = low;
	while( i <= high){
		if(arr[i] > pivot){
			i++;
		}
		else{
			swap(arr,i,j);
			i++;
			j++;
		}
	}
	return j-1;
}

void quickSort(int arr[], int low, int high){
	if(low < high){
	int pivot = arr[high];
	int pos = partition(arr, low, high, pivot);

	quickSort(arr, low, pos-1);
	quickSort(arr, pos+1, high);
	}
}

void sorter () {
    string input, output, alg;
    cout << "Input path: ";
    cin >> input;
    cout << "Output path: ";
    cin >> output;
    cout << "Algoritm (QS, IS, BS): ";
    cin >> alg;

    char* input_char =  new char[input.length()+1];
    strcpy(input_char, input.c_str());

	char* output_char = new char[output.length()+1];
	strcpy(output_char, output.c_str());

    ifstream file;
    file.open(input_char);
    int list[2000000];
    for (int i = 0; i < 2000000; ++i) {
        file >> list[i];
    }
	file.close();
	ofstream out_file;
	out_file.open(output_char);

    if (alg == "QS") {
        quickSort(list, 0, 1999999);
    	cout << "QS";
    }
	if (alg == "IS") {
		insertionSort(list, 2000000);
		cout << "IS";
	}
	if (alg == "BS") {
		bubbleSort(list, 2000000);
		cout << "BS";
	}


	for (int i = 0; i < l; ++i) {
		out_file << list[i] << ", ";
	}
	file.close();

}

int main() {
    generator();
	sorter();
    return 0;
}
