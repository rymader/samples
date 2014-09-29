/* Square a 2x2 Matrix */

	
main () { 
Matrix M = readMatrix("../samples/squared.dat");


Matrix N[2,2] i, j = 0;
N[0,0] = M[0,0]*M[0,0]+M[0,1]*M[1,0];
N[1,0] = M[0,0]*M[1,0]+M[1,1]*M[1,0];
N[0,1] = M[0,0]*M[0,1]+M[0,1]*M[1,1];
N[1,1] = M[1,0] *M[0,1]+M[1,1]*M[1,1];

  
print(N);





}

	
	

     

	

 		




