#include "limits.h"
#include "Stack_Task3.cpp"
using namespace std;

int checkInt(string,int,int); // Prompt for ints within a range of two numbers

// Minimum and maximum number of blocks allowed in one stack
const int minBlocks=2;
const int maxBlocks=INT_MAX;

int main(){
    int blockCount = checkInt("Enter an amount of blocks to play with on each tower:  ",minBlocks,maxBlocks);
    int maxBlockCount = blockCount * 2; // Allow each stack to contain every single block of each stack

    // Stack initializations
    Stack<Block> stack1(maxBlockCount);
    Stack<Block> stack2(maxBlockCount);
    Stack<Block> stack3(maxBlockCount);
    Stack<Block> stack4(maxBlockCount);
    Stack<Block> stack5(maxBlockCount);

    // Give instructions
    cout << "Player 1, your blocks are represented by the '1' character" << endl;
    cout << "Player 2, your blocks are represented by the '2' character" << endl;
    cout << "Get your stack to a new stack! You can move any piece as desired" << endl << endl;

    // Initialize each player's block with its symbol and player number
    Block player1Block('1', 1);
    Block player2Block('2', 2);

    //Loop through and add smaller blocks to the bottom of left and right stacks
    for(int i=blockCount;i>0;i--){
        player1Block.data = i;
        player2Block.data = i;

        stack1.push(player1Block);
        stack5.push(player2Block);
    }

    // Display initial contents
    displayContents(stack1, stack2, stack3, stack4, stack5, blockCount);

    // Create a current player variable for reference
    // Made string for easy input to text
    string currentPlayer = "1";

    // Continue loop until someone has won
    while(!checkWin(stack1, blockCount, 1) &&
          !checkWin(stack2, blockCount, 2) &&
          !checkWin(stack3, blockCount, 3) &&
          !checkWin(stack4, blockCount, 4) &&
          !checkWin(stack5, blockCount, 5)) {

        // Reference of the block to be moved
        Block *curBlock=nullptr;

        // Reference of the current stacks selected
        Stack<Block> *pickUpStack = nullptr;
        Stack<Block> *putDownStack = nullptr;

        try {
            // Select which stack your picking up from and moving to
            int pickUpSelect=checkInt("Player " + currentPlayer + ", enter the stack to move from:  ",1,5);
            int putDownSelect=checkInt("Player " + currentPlayer + ", enter the stack to move the block to:  ",1,5);

            // Assign the stacks based on the selections made
            // NOTE: Had in function, but compiler complained about returning local variable address
            switch (pickUpSelect){
                case 1:
                    pickUpStack = &stack1;
                    break;
                case 2:
                    pickUpStack = &stack2;
                    break;
                case 3:
                    pickUpStack = &stack3;
                    break;
                case 4:
                    pickUpStack = &stack4;
                    break;
                case 5:
                    pickUpStack = &stack5;
                    break;
                default:
                    break;
            }
            switch (putDownSelect){
                case 1:
                    putDownStack = &stack1;
                    break;
                case 2:
                    putDownStack = &stack2;
                    break;
                case 3:
                    putDownStack = &stack3;
                    break;
                case 4:
                    putDownStack = &stack4;
                    break;
                case 5:
                    putDownStack = &stack5;
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

            // Cycle the current player after a successful turn was made
            currentPlayer = currentPlayer == "2" ? "1" : "2";
        }
        catch(Stack<Block>::StackUnderflow){
            cout<<"Error, that pick-up stack has no blocks, try again"<<endl<<endl;
        }
        catch(Stack<Block>::StackOverflow){
            cout<<"Error, that stack is full, try again"<<endl<<endl;
        }
        catch(Stack<Block>::InvalidMove){
            cout<<"Invalid move! Pieces cannot be placed on smaller pieces"<<endl<<endl;
        }
        // Display contents of the stacks after each turn
        displayContents(stack1, stack2, stack3, stack4, stack5, blockCount);
    }

    // Can only reach this point once a player has won
    cout<<"You Win!"<<endl;
    return 0;
}

// Check for a valid int
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
