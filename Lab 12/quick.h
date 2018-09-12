#ifndef QUICK_H
#define QUICK_H
//Call Quick sort with size of array -1 as the end and 0 as the start

int quickSwap(int myArray[], int start, int end){
    int pivot=myArray[end];//This is the pivot point
    int index=start-1;//will store smallest element
    for(int i=start;i<=end-1;i++){
        //If the point in the array is not greater than the pivot, inc the smallest index
        if(myArray[i]<=pivot){
            index++;
            int temp=myArray[index];
            myArray[index]=myArray[i];
            myArray[i]=temp;
        }
    }
    int temp=myArray[index+1];
    myArray[index+1]=myArray[end];
    myArray[end]=temp;
    return (index+1);
}

//1st run pass function the array and last index of the array
void quickSort(int myArray[], int start, int end){
    //make sure valid indicies are given
    if(start<end){
        int pivot=quickSwap(myArray,start,end);
        quickSort(myArray,start,pivot-1);
        quickSort(myArray,pivot+1,end);
    }
    else{
        return;
    }
}
#endif
