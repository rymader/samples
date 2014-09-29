#include <iostream> 
#include "../samples/Matrix.h" 
#include <math.h> 
using namespace std;
int main() {
Matrix m = m.readMatrix ( "../samples/test_my_code2.dat" );
cout << "Original Matrix\n";cout << m;float determinant;
determinant =  ( 1 /  (  ( *m.access(0 , 0 )  * *m.access(1 , 1 )  )  -  ( *m.access(1 , 0 )  * *m.access(0 , 1 )  )  )  ) ;
Matrix m2 = *(new Matrix(2,2));
for(int i = 0; i<2;i++){ 
for(int j = 0;j<2;j++){ 
*m2.access(i,j) = (float)0;
 } 
 } 
*m2.access(0 , 0) = *m.access(1 , 1 ) ;
*m2.access(0 , 1) =  ( 0 - 1 )  * *m.access(0 , 1 ) ;
*m2.access(1 , 0) =  ( 0 - 1 )  * *m.access(1 , 0 ) ;
*m2.access(1 , 1) = *m.access(0 , 0 ) ;
for ( int i = 0;i <= 1; i++ )  { 
	for ( int j = 0;j <= 1; j++ )  { 
	*m2.access(i , j) = *m2.access(i , j )  * determinant;

 }

 }
cout << "Inverse Matrix\n";cout << m2; }
