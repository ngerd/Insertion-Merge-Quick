#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

#define n 100
#define N 1000


void generateArray(int array[], int length) {
    for(int i=0; i<length; i++) {
        array[i] = rand()%100;
    }
}
 
void insertionSort(int array[], int length) {
    int key, j;
    for(int i=1; i<length; i++) {
        key = array[i];
        j = i-1;

        while (j>=0 && array[j] > key)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void printArray(int array[], int length) {
    for(int i=0; i<length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[1000000];
    clock_t start, end;
    double ExecutionTime;

    //generating value for array of length 100
    generateArray(array, n);

    start = clock();
    insertionSort(array, n);
    end = clock();
    ExecutionTime = double(end-start)/(double)CLOCKS_PER_SEC;
    cout << "Executiong time: " << fixed << ExecutionTime << " seconds" << endl;

    //generating value for array of length 1000
    generateArray(array, N);
    
    start = clock();
    insertionSort(array, N);
    end = clock();
    ExecutionTime = double(end-start)/(double)CLOCKS_PER_SEC;
    cout << "Executiong time: " << fixed << ExecutionTime << " seconds" << endl;

    return 0;
}