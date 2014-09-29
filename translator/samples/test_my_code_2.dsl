/* Find the inverse of a 2x2 matrix */

main () { 
	Matrix m = readMatrix("../samples/test_my_code2.dat");
	
	print("Original Matrix\n");
	print(m);
	
	Float determinant;
	determinant = (1 / ((m[0,0] * m[1,1]) - (m[1,0] * m[0,1])));
	
	Matrix m2 [ 2, 2 ] i, j = 0 ;
	m2[0,0] = m[1,1];
	m2[0,1] = (0 - 1) * m[0,1];
	m2[1,0] = (0 - 1) * m[1,0];
	m2[1,1] = m[0,0];
	
	for(i = 0 to 1) {
		for(j = 0 to 1) {
			m2[i,j] = m2[i,j] * determinant;
		}
	}
	
	print("Inverse Matrix\n");
	print(m2);
}



