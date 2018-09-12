#ifndef MERGE_H
#define MERGE_H
//Call Quick sort with size of array -1 as the end and 0 as the start


//the array passed to this function will have each half of it sorted down the index,
//This function figures out the order
int mergeSwap(int myArray[], int start, int end, int index){
    int size1=index-start+1;
    int size2=end-index;
    int tempArr1[size1];
    int tempArr2[size2];
    for(int i=0;i<size1;i++){
        tempArr1[i]=myArray[start+i];
    }
    for(int i=0;i<size2;i++){
        tempArr2[i]=myArray[index+1+i];
    }
    //These indexes are used for parsing the 2 temp arrays and the original
    int tempArr1Index=0;
    int tempArr2Index=0;
    int tempMergeIndex=start;
    //Run until one of the arrays are "empty"
    while(tempArr1Index<size1&&tempArr2Index<size2){
        if(tempArr1[tempArr1Index]<=tempArr2[tempArr2Index]){
            myArray[tempMergeIndex]=tempArr1[tempArr1Index];
            tempArr1Index++;
        }
        else{
            myArray[tempMergeIndex]=tempArr2[tempArr2Index];
            tempArr2Index++;
        }
        tempMergeIndex++;
    }

    //For whatever array isn't empty, put the rest of its terms in the array
    while(tempArr1Index<size1){
        myArray[tempMergeIndex]=tempArr1[tempArr1Index];
        tempArr1Index++;
        tempMergeIndex++;
    }
    while(tempArr2Index<size2){
        myArray[tempMergeIndex]=tempArr2[tempArr2Index];
        tempArr2Index++;
        tempMergeIndex++;
    }


}

//1st run pass function the array,0, and last index of the array
void mergeSort(int myArray[], int start, int end){
    if(start<end){
        //get the middle index in the array
        int index=(start+end)/2;
        mergeSort(myArray,start,index);
        mergeSort(myArray,index+1,end);
        mergeSwap(myArray,start,end,index);
    }
    else{
        return;//Stop the function the recursion has reached the end
    }
}
#endif
