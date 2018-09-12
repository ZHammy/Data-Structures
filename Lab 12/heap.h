#ifndef HEAP_H
#define HEAP_H
void buildHeap(int myArray[], int size, int index){
    int largest = index;
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;

    // If left child is larger than largest
    if (leftChild < size && myArray[leftChild] > myArray[largest])
        largest = leftChild;

    // If right child is larger than largest
    if (rightChild < size && myArray[rightChild] > myArray[largest])
        largest = rightChild;

    // If largest is not the original root
    if (largest != index){
        int temp=myArray[index];
        myArray[index]=myArray[largest];
        myArray[largest]=temp;

        // Recursively build the heap
        buildHeap(myArray, size, largest);
    }
}
void heapSort(int myArray[], int size){
    for(int i=(size/2)-1;i>=0;i--){
        buildHeap(myArray,size,i);
    }
    for(int i=size-1;i>=0;i--){
        int temp=myArray[0];
        myArray[0]=myArray[i];
        myArray[i]=temp;
        buildHeap(myArray,i,0);
    }
}
#endif
