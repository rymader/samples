
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "scheduler.h"
#include "RBT.h"
#include <limits>
#define DEBUG

using namespace std;

extern long numP = 0;     // total processes scheduled
extern long totalB = 0;   // total number of ticks utilized

int main(int argc, char *argv[]) {

	extern int countr;
    	int c = 0;
	long numCurrP = 0;          // total processes currently waiting/running
        long totalWT = 0;           // total waiting time

	RBT *arrivalTree = new RBT();

	// check for input file
	if (argc == 2) {
		readFile(argv[1], arrivalTree);
	}

	promptUser(arrivalTree); // for processes

	#ifdef DEBUG
	//treeTests(arrivalTree);  // test arrival tree is set up correct
	cout << "Starting in-order tree walk on arrival tree"<< endl;
	arrivalTree->inOrderTreeWalk(arrivalTree->root);
	cout << countr << endl;
	#endif

	cout << "Arrival tree built" << endl;

	RBT *priorityTree = new RBT();

	std::cout << "Please specify a time quantum: ";
	long tq = get_long();

	long clock = 0;

	Process *current = priorityTree->treeMax(priorityTree->root);

	cout << "\nNow beginning to run processes" << endl;

	// Main Loop: every loop is a clock tick
	while((arrivalTree->root != arrivalTree->nil) || (priorityTree->root != priorityTree->nil)) {


		#ifdef DEBUG
		cout << "\n\n\n\n-----TIME-----" << clock << "-----" << endl;
		#endif

                if(numCurrP-1 > 0) {
			totalWT += numCurrP-1; // update total waiting time
		}

		//// STEP 1: decrement current process burst by one
		if (current != priorityTree->nil){
			current->setBurst(current->burst - 1);
		}


		//// STEP 2: remove process completed process
		if ((current != priorityTree->nil) && (current->burst <= 0)) {
			priorityTree->remove(current);
            		if ((current != priorityTree->nil) && (current->burst <= 0)) {
				numCurrP--;
                		#ifdef DEBUG
                		cout << current->pid << " completed" << endl;
                		#endif
                		delete current;
                		current = priorityTree->nil;
                		++c;
            		}
		}


		//// STEP 3: boost starving processes
                if(!(clock % 100)){
                    	priorityTree->priorityInc(priorityTree->treeMin(priorityTree->root), current);
                }


		//// STEP 4: clock interrupt a running process if at the end of a time quantum
		////		and decrement its priority
		if(!(clock % tq)){
            		priorityTree->priorityDec(current, tq);
		}


		//// STEP 5: processes arrive and are added to the priority queue
	        numCurrP += arrivalTree->arrivalWaitInc(arrivalTree->treeMin(arrivalTree->root), priorityTree);


		//// STEP 6: start running new process
                if((current->burst <= 0) || !(clock % tq) ) {
                    current = priorityTree->treeMax(priorityTree->root);
                    #ifdef DEBUG
                    cout << current->pid << " started" << endl;
                    #endif
                }

                #ifdef DEBUG
		//printf("%u\n is running", current->pid);
                cout << current->pid << " is running" << endl;
                #endif

		//// STEP 7: increment clock
		clock ++;
	}

	cout << c << " Processes have finished processing" << endl;
	#ifdef DEBUG
	cout << c << " Processes have been removed." << endl;
	cout << countr << "\n" << "Starting in-order tree walk on priority tree" << endl;
	priorityTree->inOrderTreeWalk(priorityTree->root);
	cout << countr << endl;
	#endif

	delete arrivalTree;
	delete priorityTree;

	printf("RUN STATISTICS: \n");
	cout << "Total Processes Scheduled: " << numP << endl;
	long aveWT = totalWT / numP;
	cout << "Average Waiting Time: " << aveWT << endl;
	long aveTT = (totalWT+totalB) / numP;
	cout << "Average Turnaround Time: " << aveTT << endl;

	return 0;
}

