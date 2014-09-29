#include <iostream>
#include <cstdlib>
#include <cassert>
#include "RBT.h"
#include "scheduler.h"

using namespace std;

extern int countr = 0;

RBT::RBT() {

	this->nil = new Process();
	this->nil->left = this->nil;
	this->nil->right = this->nil;
	this->nil->parent = this->nil;
	this->nil->priority = -1;
	this->nil->burst = -1;
	this->nil->color = black;
	//this->nil->arrival = -10;
	this->root = this->nil;

}

RBT::~RBT() {

    #ifdef DEBUG
    cout << "Tree is being deleted" << endl;
    #endif
    delete this->nil;
}

void RBT::insertByPriority(Process *z) {

    Process *x = root;  //pointer to the root node
    Process *y = nil;   // pointer to the nil sentinel node

    while(x != nil) {

        y = x;  // y points to same node as x before x is changed

        // if z has a lower key, traverse left
        if(z->priority < x->priority) {
            x = x->left;
        }
        // z has a key >= than x, traverse right
        else if (z->priority > x->priority) {
            x = x->right;
        }

        else if (z->arrival < x->arrival) {
            x = x->left;
        }

        else
            x = x->right;

    }

    z->parent = y;
    // if parent is nil, then z must be the root
    if (y == nil) {
        root = z;
        root->parent = nil;

    }
    // if z is left child
    else if (z->priority < y->priority) {
        y->left = z;
    }
    else if (z->priority > y->priority) {
        y->right = z;
    }
    else if (z->arrival < y->arrival){
        y->left = z;
    }
    // else z must be right child
    else
        y->right = z;

    // initialize z's children to nil, and color to red
    z->left = nil;
    z->right = nil;
    z->color = red;

    // call insertFixup to balance tree

    insertFixup(z);
}

void RBT::insertByArrival(Process *z) {

    Process *x = root;  //pointer to the root node
    Process *y = nil;   // pointer to the nil sentinel node

    while(x != nil) {

        y = x;  // y points to same node as x before x is changed

        // if z has a lower key, traverse left
        if(z->arrival < x->arrival) {
            x = x->left;
        }
        // z has a key >= than x, traverse right
        else if (z->arrival > x->arrival) {
            x = x->right;
        }

        else if (z->pid < x->pid) {
            x = x->left;
        }

        else
            x = x->right;

    }

    z->parent = y;
    // if parent is nil, then z must be the root
    if (y == nil) {
        root = z;
        root->parent = nil;

    }
    // if z is left child
    else if (z->arrival < y->arrival) {
        y->left = z;
    }
    else if (z->arrival > y->arrival) {
        y->right = z;
    }
    else if (z->pid < y->pid){
        y->left = z;
    }
    // else z must be right child
    else
        y->right = z;

    // initialize z's children to nil, and color to red
    z->left = nil;
    z->right = nil;
    z->color = red;

    // call insertFixup to balance tree

    insertFixup(z);
}

void RBT::insertFixup(Process *z) {

    Process *y;

    while(z->parent->color == red) {
        //cout << "All work and no play makes jack a dull boy" << endl;

        // If z's parent is the grandparent's left child
        if (z->parent == z->parent->parent->left) {
            y = z->parent->parent->right; // y points to z's uncle (grandparent's right child)

            // case 1
            if(y->color == red) {
                z->parent->color = black;       // change parent's color to black
                y->color = black;               // change uncle's color to black
                z->parent->parent->color = red; // change grandparent's color to red
                z = z->parent->parent;          // z become's parent's grandparent
            }

            // case 2 and 3
            else if(z == z->parent->right) {
                z = z->parent;                  // z takes place of parent (case2)
                leftRotate(z);                  // function call to swap parent and child (case 2)
            }
            else {
                z->parent->color = black;       // change parent's color to black (case 3)
                z->parent->parent->color = red; // change grandparent's color to red (case 3)
                rightRotate(z->parent->parent); // rotate z's grandparent (case 3)
            }

        }
        // symmetric with if clause: z's parent is grandparent's right child
        else {
            y = z->parent->parent->left;

            if(y->color == red) {
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }
            else if(z == z->parent->left) {
                z = z->parent;
                rightRotate(z);
            }
            else {
                z->parent->color = black;
                z->parent->parent->color = red;
                leftRotate(z->parent->parent);
            }
        }

    }
    root->color = black;


}




void RBT::leftRotate(Process *x) {

    Process *y = x->right;      // pointer to x's right child

    //if (y != nil) {

        x->right = y->left;         // x's right child become's y's left child

        // if y's left child is not nil, left child's parent is x
        if (y->left != nil) {
            y->left->parent = x;
        }


        y->parent = x->parent;      // x's parent becomes y's parent

        // if x's parent is nil, y becomes root
        if (x->parent == nil) {
            root = y;
        }
        // if x is parent's left child, y takes it's place
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        // x is parent's right child, and y takes it's place
        else
            x->parent->right = y;
        y->left = x;    // x becomes y's left child
        x->parent = y;  // y becomes x's parent
    //}

}

// symmetric with leftRotate
void RBT::rightRotate(Process *x) {

    Process *y = x->left;

    //if (y != nil) {

        x->left = y->right;
        if (y->right != nil) {
            y->right->parent = x;
        }


        y->parent = x->parent;


        if (x->parent == nil) {
            root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else
            x->parent->left = y;
        y->right = x;
        x->parent = y;
    //}
}

void RBT::inOrderTreeWalk(Process *x) {

    // recursive calls are made to traverse the tree in-order
    if (x != nil) {
        inOrderTreeWalk(x->left);
        cout << "arrival: " << x->arrival << " " << "priority: " << x->priority << endl;
        ++countr;       // extern int countr variable increments to verify the correct number of processes are on the tree
        inOrderTreeWalk(x->right);
    }

}


Process* RBT::treeMin(Process *x) {

    // loop traverse left until it reaches nil leaf, returns
    // last non-nil node
    while (x->left != nil) {

        x = x->left;
    }
    return x;
}

Process* RBT::treeMax(Process *x) {

    // While loop is symmetric with treeMin
    while (x->right != nil ) {
        x = x->right;
    }
    return x;

}

Process* RBT::treeSuccessor(Process *x) {

    if (x->right != nil) {  // if there is a right child, it is the tree successor
        return treeMin(x->right);
    }
    Process *y = x->parent;
    // while loop executes only if x is a right child of y
    while ((y != nil) && (x == y->right)) {
        x = y;      // x points to parent node
        y = y->parent;  // y points to x's grandparent
    }
    return y;

}

Process* RBT::treePredecessor(Process *x) {

    // Everything is symmetric with treeSuccessor

    if (x->left != nil) {
        return treeMax(x->left);
    }
    Process *y = x->parent;
    while((y != nil) && (x == y->left)) {
        x = y;
        y = y->parent;
    }
    return y;

}

void RBT::transplant(Process *u, Process *v) {

    // determine if u is the root
    if (u->parent == nil) {
        root = v;
    }
    // if u is left child, v replaces u
    else if (u == u->parent->left) {
        u->parent->left = v;
    }
    // u is right child, u replaces v
    else
        u->parent->right = v;
    v->parent = u->parent;

}

void RBT::remove(Process *z) {

    Process *x;
    Process *y = z;
    enum type originalColor = y->color;
    if (z->left == nil) {
        x = z->right;
        transplant(z, z->right);
    }
    else if (z->right == nil) {
        x = z->left;
        transplant(z, z->left);
    }
    else {
        y = treeMin(z->right);
        originalColor = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        }
        else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;

    }
    //delete z;
    if (originalColor == black)
       removeFixup(x);
}

void RBT::removeFixup(Process *x) {

    Process *w;

    while ((x != root) && (x->color == black)) {

        if (x == x->parent->left) {
            w = x->parent->right;

            if (w->color == red) {
                w->color = black;
                x->parent->color = red;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if ((w->left->color == black) && (w->right->color == black)) {
                w->color = red;
                x = x->parent;
            }
            else if (w->right->color == black) {
                w->left->color = black;
                w->color = red;
                rightRotate(w);
                w = x->parent->right;
            }
            else {
                w->color = x->parent->color;
                x->parent->color = black;
                w->right->color = black;
                leftRotate(x->parent);
                x = root;
            }

        }
        else {

             w = x->parent->left;

            if (w->color == red) {
                w->color = black;
                x->parent->color = red;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if ((w->right->color == black) && (w->left->color == black)) {
                w->color = red;
                x = x->parent;
            }
            else if (w->left->color == black) {
                w->right->color = black;
                w->color = red;
                leftRotate(w);
                w = x->parent->left;
            }
            else {
                w->color = x->parent->color;
                x->parent->color = black;
                w->left->color = black;
                rightRotate(x->parent);
                x = root;
            }


        }
    }
    x->color = black;
}

long RBT::arrivalWaitInc(Process *p, RBT *t) {

    Process *q;

    // used for statistics output
    extern long totalB;
    long num = 0;

    while(p != nil) {

        p->setWait(p->wait + 1); // increase wait of each process

// in case of an arrival time of 0 or for protection against negative arrivals
        if(p->arrival < 1) {

// Process is removed from arrival tree and enqueued in priority tree
            remove(p);
	    #ifdef DEBUG
            	cout << p->pid << " arrived at priority " << p->priority << endl;
	    #endif
            q = p;
            p = treeSuccessor(p);
            q->left = t->nil;
            q->right = t->nil;
            q->parent = t->nil;
            q->wait = 0;
            totalB += q->burst;
            t->insertByPriority(q);
            ++num;


        }
        else {
// works the same as in if statement

            if (p->wait == p->arrival) {
                remove(p);
                #ifdef DEBUG
                	cout << p->pid << " arrived at priority " << p->priority << endl;
            	#endif
                q = p;
                p = treeSuccessor(p);
                q->right = t->nil;
                q->left = t->nil;
                q->parent = t->nil;
                q->wait = 0;
                totalB += q->burst;
                t->insertByPriority(q);
                ++num;
            }
           else {
			p = treeSuccessor(p);

		   }
        }
    }

    return num;   // returns number of current processes
}

void RBT::priorityInc(Process *p, Process *c) {

/***********************Recursive version ****************************************************/
/*
        if ((p != nil) && (p->priority < 50)) {
            Process *q = treeSuccessor(p);
            p->setWait(p->wait +1);

            if ((p->wait > 99) && (p->priority < 39) ) {
                p->setPriority(p->priority + 10);
                p->setWait(0);
                if(p->priority > q->priority) {

                    remove(p);
 //                   #ifdef DEBUG
 //                   cout << "removing process: " << p->pid << " from tree" << endl;
 //                   #endif
                    insertByPriority(p);
 //                   #ifdef DEBUG
 //                   cout << "Rearranging process: " << p->pid << "back into tree" << endl;
 //                   #endif
                }
 //               #ifdef DEBUG
 //               cout << "Priority boost successful!." << endl;
 //               #endif
                priorityInc(q);
            }
            else if ((p->priority > 39)  && (p->priority < 49)) {
                if (p->wait > 99) {
                    p->setWait(0);
                    p->setPriority(49 - p->priority);
                    if (p->priority > q->priority) {
                        remove(p);
                        insertByPriority(p);
                    }
                }


            }
            else {
                priorityInc(q);
            }

    }

}
*/
/*********************************** Iterative version *******************************************/


    Process *q;

    // traverses all processes below 50
    while((p != nil) &&  (p->priority < 50)) {


// Boosts process up to maximum allowed value if they are starving
        p->setWait(p->wait + 1);
        if ((p != c) && (p->wait > 99) && (p->priority < 39)) {
            p->setPriority(p->priority + 10);
            p->wait = 0;
            q = p;
            p = treeSuccessor(p);  // moves to next process in tree
            // if q's priority has become greater than it's successor ]
            // it must be rearragned
            if(q->priority > p->priority) {
                remove(q);
                insertByPriority(q);
            }
        }
        else {
            p = treeSuccessor(p);  // moves on to next process
        }

    }
}

void RBT::priorityDec(Process *p, long tq) {

    Process *q = treePredecessor(p);


    if (p != nil) {
	#ifdef DEBUG
        cout << p->pid << " interrupted" << endl;
        #endif
	// decrement user level processes
        if ((p->priority < 50) && (p->priority > 0)) {
            if (p->priority - tq > 0) {  // if subtracting by tq won't bring it below 0
                p->setPriority(p->priority - tq);
	        #ifdef DEBUG
		cout << p->pid << " demoted to priority " << p->priority << endl;
	        #endif
		// If priority becomes less than predessor, it must be rearranged
                if (p->priority < q->priority) {
                    remove(p);
                    insertByPriority(p);
                }
            }
            else {
                p->setPriority(tq - p->priority);  // if tq is larger than priority
                #ifdef DEBUG
                cout << p->pid << " demoted to priority " << p->priority << endl;
                #endif
                if (p->priority < q->priority) {
                    remove(p);
                    insertByPriority(p);
                }
            }
        }
        // for kernel level processes
        else if ((p->priority > 50) && (p->priority - tq) > 50) {
            p->setPriority(p->priority - tq);
            #ifdef DEBUG
            cout << p->pid << " demoted to priority " << p->priority << endl;
            #endif
            if (p->priority < q->priority) {
                remove(p);
                insertByPriority(p);
            }
        }

    }

}


// validated long number method
long get_long()
{
  unsigned long a = 0;
  long b = 0;
  while (!(std::cin >> a))
  {
      std::cout << "Must be a positive number: " << std::endl;
      std::cin.clear();
      std::cin.ignore(1000000, '\n');
  }
  b = a;
  return b;
}

