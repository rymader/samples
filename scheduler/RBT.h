#ifndef RBT_H
#define RBT_H

#include <stdlib.h>
#include <iostream>
#include "scheduler.h"


class Process;

/*!
    \class RBT
    \brief Contains Process nodes and methods necessary to build a
    red black tree
*/
class RBT {

    public:
        Process *root;  //! root node
        Process *nil;   //! sentinel node acting as nil

    public:

        /*! \brief Constructor No arguments taken. Creates a sentinel
           process node nil and initialized its color to black and has
           the left, right and parent pointer point to itself.  The color
           is set to black.
        */
        RBT(); //

        /*! \brief Destructor */
        ~RBT();

        /*!
            \brief Inserts node into rbt by priority
            \param z a pointer to a process node
        */
        void insertByPriority(Process *z);

        /*!
            \brief Inserts Process node into rbt by arrival
            time
            \param z a pointer to a process node
        */
        void insertByArrival(Process *z);

        /*!
            \brief balances rbt after node insert
            \param z a pointer to a process node
        */
        void insertFixup(Process *z);

        /*!
            \brief rotates parent node and right child
            \param x a pointer to a process node
        */
        void leftRotate(Process *x); //

        /*!
            \brief rotates parent node and left child
            \param x a pointer to a process node
        */
        void rightRotate(Process *x); //

        /*!
            \brief Puts one node in another's place
            \param u a pointer to a process node
            \param v a pointer to a process node
        */
        void transplant(Process *u, Process *v);

        /*!
            \brief remove node from tree
            \param z a pointer to a process node
        */
        void remove(Process *z);

        /*!
            \brief rebalances tree after node removal
            \param x a pointer to a process node
        */
        void removeFixup(Process *x);

        /*!
            \brief traveses tree inorder at specific starting node
            \param x a pointer to a process node for the starting point
        */
        void inOrderTreeWalk(Process *x);

        /*!
            \brief searches tree recursively for node with specified key
            \param x a pointer to a process node
            \param key an int holding the priority number of the process node
            \return Process matching specified key
        */
        Process* treeSearch(Process *x, long key);

        /*!
            \brief searches tree iteratively for node with specific key
            \param x a pointer to a process node
            \param key an int holding the priority number of the process node
            \return Process matching specified key
        */
        Process* iterativeTreeSearch(Process *x, long key);

        /*!
            \brief finds node with minimum priority number
            \param x a pointer to a process node
            \return Process with min value from starting process
        */
        Process* treeMin(Process *x);

        /*!
            \brief finds node with maximum priority number
            \param x a pointer to a process node
            \return Process with max value from starting process
        */
        Process* treeMax(Process *x);

        /*!
            \brief finds node with next key
            \param x a pointer to a process node
            \return Process with next largest key
        */
        Process* treeSuccessor(Process *x);

        /*!
            \brief finds node with previous key
            \param x a pointer to a process node
            \return Process with previous key
        */
        Process* treePredecessor(Process *x);
        //void treeDelete(Process z);

        /*!
            \brief Increments wait time by 1 clock tick
            for each node in arrivalTree and removes the
            node once its wait time equals arrival time.
            If the arrival time is less than or equal to zero,
            then it is removed from the tree without incrementing
            the wait time.
            \param x a pointer to a process node
            \param t a pointer to a RBT
        */
        long arrivalWaitInc(Process *p, RBT *t);

        /*!
            \brief Increments priority of all proccesses < 50 by
            10 if wait time is greater than 99
            \param x a pointer to a Process node
        */
        void priorityInc(Process *p, Process *c);

        void priorityDec(Process *p, long tq);


        //! friend classes and methods
        friend void readFile(char *f, RBT *t);

};


/*! methods for validated inputs */
long get_long();

#endif
