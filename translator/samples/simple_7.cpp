#include <iostream> 
#include "../samples/Matrix.h" 
#include <math.h> 
using namespace std;
int main() {
Matrix m = *(new Matrix(10,10));
for(int i = 0; i<10;i++){ 
for(int j = 0;j<10;j++){ 
*m.access(i,j) = (float)i * j;
 } 
 } 
int i;
int j;
for ( int i = 0;i <= 9; i++ )  { 
	for ( int j = 0;j <= 9; j++ )  { 
	cout << *m.access(i , j ) ;cout << "  ";
 }
cout << "\n";
 }
for ( int i = 0;i <= 9; i++ )  { 
	for ( int j = 0;j <= 9; j++ )  { 
	*m.access(i , j) = *m.access(i , j )  + 100;

 }

 }
for ( int i = 0;i <= 9; i++ )  { 
	for ( int j = 0;j <= 9; j++ )  { 
	cout << *m.access(i , j ) ;cout << "  ";
 }
cout << "\n";
 }
 }
