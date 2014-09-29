#include <iostream> 
#include "../samples/Matrix.h" 
#include <math.h> 
using namespace std;
int main() {
Matrix M = M.readMatrix ( "../samples/squared.dat" );
Matrix N = *(new Matrix(2,2));
for(int i = 0; i<2;i++){ 
for(int j = 0;j<2;j++){ 
*N.access(i,j) = (float)0;
 } 
 } 
*N.access(0 , 0) = *M.access(0 , 0 )  * *M.access(0 , 0 )  + *M.access(0 , 1 )  * *M.access(1 , 0 ) ;
*N.access(1 , 0) = *M.access(0 , 0 )  * *M.access(1 , 0 )  + *M.access(1 , 1 )  * *M.access(1 , 0 ) ;
*N.access(0 , 1) = *M.access(0 , 0 )  * *M.access(0 , 1 )  + *M.access(0 , 1 )  * *M.access(1 , 1 ) ;
*N.access(1 , 1) = *M.access(1 , 0 )  * *M.access(0 , 1 )  + *M.access(1 , 1 )  * *M.access(1 , 1 ) ;
cout << N; }
