#include <iostream>
#include <stdlib.h> //needed for rand
#include <time.h>
#include "List_Task1.cpp"
#include "List_Task2.cpp"
#include "List_Task3.cpp"
using namespace std;

int main () {
    int list1OpCount=0;
    int list2OpCount=0;
    int list3OpCount=0;
    int errorHelper;
    //need to run the test 100 times
    for(int i=0;i<100;i++){
        List1 firstList;
        List2 secondList;
        List3 thirdList;
        srand(time(NULL));
        int adds=0;
        int removes=0;
        int random;//Stores the random number to be put in our lists
        int pickOp;//either one or zero and chooses which operation
        while(adds<30&&removes<25){
            random=rand()%10;//Create random number between 0 and 9

            //If we can't add anymore, set to remove operation
            if(adds>=30||firstList.getLength()>=MAX_LENGTH){
                pickOp=0;
            }
            //If we can't remove anymore, set to add operation
            else if(removes>=25||firstList.getLength()<=0){
                pickOp=1;
            }
            //If we could do either, make it random
            else {
                pickOp=rand()%2;
            }

            //If an error happens, just continue and dont count it
            try{
                //Add items to the lists
                if(pickOp){
                    firstList.addItem(random);
                    secondList.addItem(random);
                    thirdList.addItem(random);
                    list1OpCount+=firstList.getOpCount();
                    list2OpCount+=secondList.getOpCount();
                    list3OpCount+=thirdList.getOpCount();
                    adds++;
                }
                //removes an item
                else {
                    firstList.removeItem(random);
                    secondList.removeItem(random);
                    thirdList.removeItem(random);
                    list1OpCount+=firstList.getOpCount();
                    list2OpCount+=secondList.getOpCount();
                    list3OpCount+=thirdList.getOpCount();
                    removes++;
                }
            }

            //Since the items are random, they may not be found in a list or an overflow may happen,
            //just continue on and dont count the adds or removes
            catch(List1::ListUnderflow){
            }
            catch(List1::ListOverflow){
            }
            catch(List1::ListItemNotFound){
            }
            catch(List1::ListNull){
            }
            catch(List1::ListUnsorted){
            }
            catch(...){
            }
        }
    }
    cout<<"Operation counts after 100 tests for size "<<MAX_LENGTH<<endl;
    cout<<"List 1:  "<<list1OpCount<<endl;
    cout<<"List 2:  "<<list2OpCount<<endl;
    cout<<"List 3:  "<<list3OpCount<<endl;
    return 0;
}
