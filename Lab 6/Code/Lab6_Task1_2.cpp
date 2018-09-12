#include "limits.h"
#include "Stack_Task1_2.cpp"
using namespace std;

int checkInt(string,int,int); // Prompt for ints within a range of two numbers
bool checkWin(Stack<int>);    // Checks if the user has won yet.

// Minimum and maximum number of blocks allowed in one stack
const int minBlocks=2;
const int maxBlocks=INT_MAX;

int main(){
    int blockCount = checkInt("Enter an amount of blocks to play with:  ",minBlocks,maxBlocks);

    // Stack initializations
    Stack<int> leftStack(blockCount);
    Stack<int> middleStack(blockCount);
    Stack<int> rightStack(blockCount);

    //Loop through and add smaller blocks to the bottom of leftStack
    for(int i=blockCount;i>0;i--){
        leftStack.push(i);
    }

    // Display initial contents
    displayContents(leftStack, middleStack, rightStack);

    while(!checkWin(middleStack) && !checkWin(rightStack)){
        // Reference for the the block that to be moved
        int *curBlock=nullptr;

        // Reference of the current stacks selected
        Stack <int> *pickUpStack = nullptr;
        Stack <int> *putDownStack = nullptr;

        try {
            // Select which stack your picking up from and moving to
            int pickUpSelect=checkInt("Enter the stack to move from:  ",1,3);
            int putDownSelect=checkInt("Enter the stack to move the block to:  ",1,3);

            // Assign the stacks based on the selections made
            // NOTE: Had in function, but compiler complained about returning local variable address
            switch (pickUpSelect){
                case 1:
                    pickUpStack = &leftStack;
                    break;
                case 2:
                    pickUpStack = &middleStack;
                    break;
                case 3:
                    pickUpStack = &rightStack;
                    break;
                default:
                    break;
            }
            switch (putDownSelect){
                case 1:
                    putDownStack = &leftStack;
                    break;
                case 2:
                    putDownStack = &middleStack;
                    break;
                case 3:
                    putDownStack = &rightStack;
                    break;
                default:
                    break;
            }

            // Assign the block to the top of the pick up stack and move to put down stack
            // Attempt to put the block down first in order to validate the move
            // before removing the value from the other stack.
            curBlock = pickUpStack->top();
            putDownStack->push(*curBlock);
            pickUpStack->pop();
        }
        catch(Stack<int>::StackUnderflow){
            cout<<"Error, that pick-up stack has no blocks, try again"<<endl<<endl;
        }
        catch(Stack<int>::StackOverflow){
            cout<<"Error, that stack is full, try again"<<endl<<endl;
        }
        catch(Stack<int>::InvalidMove){
            cout<<"Invalid move! Pieces cannot be placed on smaller pieces"<<endl<<endl;

        }

        // Display contents of the stacks after each turn
        displayContents(leftStack, middleStack, rightStack);
    }

    // Can only reach this point once the user has won
    cout<<"You Win!"<<endl;
    return 0;
}

//Check for a valid int
int checkInt(string text, int min, int max){
    int val;
    bool badVal = true;
    while(badVal){
        cout << text;
        cin >> val;
        badVal = cin.fail();
        if(badVal||(val>max)||val<min){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid entry, please enter again" <<endl;
            badVal=true;
        }
        cout << endl; // Print blank line for readability
    }
    return val;
}
