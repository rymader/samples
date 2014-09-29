
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdlib.h>
#include "RBT.h"

//#define DEBUG


//! red black value types.  None may or may not be needed.
enum type {red, black};

class RBT;

/*!
    \class Process
    \brief This class will create a new process object.
    It's details are explained in comments below
*/
class Process {

	private:

		long pid;		//! Process id
		long burst;		//! Time needed to complete
		long arrival;	//! arrival time
		long priority;	//! Priority rank
		long wait;       //! time spent in arrival queue

        Process *left;      //! pointer to left child node
        Process *right;     //! pointer to right child node
        Process *parent;    //! pointer to parent node
        enum type color;    //! red or black type

	public:

		/*! \brief The constructor takes 4 arguments:
		 *  \param id Process id
		 *  \param bur Time needed to complete
		 *  \param arr Time process arrived
		 *  \param pri Order of priority
		*/
		Process(long id, long bur, long arr, long pri) : pid(id), burst(bur),
			arrival(arr), priority(pri), wait(0) {}


        /*! No arg constructor */
        Process(void) {}

        /*! copy constructor */
        Process(const Process&) {};

		// getter methods

		/*!	\return the process id */
		long getPid(){ return pid; }
		/*! \return the burst time */
		long getBurst() { return burst; }
		/*! \return the arrival time */
		long getArrival() { return arrival; }
		/*! \return the priority number */
		long getPriority() { return priority; }
		/*! \return the time spent waiting */
		long getWait() {return wait; }

		// setter methods

		/*! \param id the process id */
		void setPid(long id) { pid = id; }
		/*! \param bur the burst time */
		void setBurst(long bur) { burst = bur; }
		/*! \param arr the arrival time */
		void setArrival(long arr) { arrival = arr; }
		/*! \param pri the priority number */
		void setPriority(long pri) { priority = pri; }
		/*! \param wt the wait time */
		void setWait(long wt) { wait = wt; }

		//! friend functions and classes for private data access
		friend Process* addProcess(long data[]);
		friend void addInput(RBT *t);
		friend void readFile(char *f, RBT* tree);
                friend void treeTests(RBT *t);
		friend class RBT;
		friend class CPU;
		friend int main(int argc, char *argv[]);

};

/*!
    \brief Reads a file one line at a time and puts data into an
    array before passing it to addProcess
    \param f a char pointer to the file descriptor
    \param tree a pointer to a RBT
*/
void readFile(char *f, RBT *tree);

/*!
    \brief Creates a new process using the data from the array.
    \param data an int array of values to initialize the process with
*/
Process* addProcess(long data[]);

/*!
    \brief Asks user if any additional input is needed.  It call getReply to
    determine response
    \param t A pointer to a RBT
*/
void promptUser(RBT *t);

/*!
    \brief Determines if an additional file will be input or if the process
    will be entered manually by the user
    \param t a pointer to a RBT
*/
void addInput(RBT *t);

/*!
    \brief Takes in a char and determines the appropriate response
    \param answer a character pointer
    \return a boolean expression (true/false)
*/
bool getReply(char *answer);

/*!
    \brief Runs various tests on the RBT if DEBUG is defined
    \param t a pointer to a RBT
*/
void treeTests(RBT *t);



#endif



