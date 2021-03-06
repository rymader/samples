#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "Matrix.h"
#include "../src/readInput.cpp"


    Matrix::Matrix(int i, int j) 
	{
		this->rows = i;	
		this->cols = j;
		this->data = new float*[i];
		
		for(int k = 0; k <= i; k++) {
			data[k] = new float[j];
			for(int l = 0; l < j; l++) {
				data[k][l] = 0;
			}
		}
  		
	}


    int Matrix::numRows ( ) 
	{
		return this->rows;
	}
    int Matrix::numCols ( )
	{
		return this->cols;
	}

	int numRows (Matrix m) 
	{
		return m.numRows();
	}
    int numCols (Matrix m)
	{
		return m.numCols();
	}
	


    float * Matrix::access(const int i, const int j) const
	{
		return &(this->data[i][j]);
	}
	
    std::ostream& operator<<(std::ostream &os, Matrix &m)
    {
    	os << m.rows << " " << m.cols << std::endl;
    	int i = 0;
    	for(i = 0; i<m.rows; i++)
    	{
    		int j = 0;
    		for(j = 0; j<m.cols; j++)
    		{
    			os << m.data[i][j] << "  ";
    		}
    		os << std::endl;
    	}
    }

    Matrix Matrix::readMatrix ( std::string filename ) 

	{
		
		char * buf = readInputFromFile(filename.c_str());
		
		char * c = &buf[0];
		
		while(*c != '\0')
		{
			if(*c == '\n')
			{
				*c = ' ';
			}
			c++;
		}
		
		const char delim = ' ';
		
		c = strtok(buf, &delim);
		int rows = atoi(c);
		
		c = strtok(NULL, &delim);
		int cols = atoi(c);
		
		float ** data = (float**)malloc(sizeof(float*)*rows);
		for(int k = 0; k<rows; k++)
		{
			data[k] = (float*)malloc(sizeof(float) * cols);
		}
		
		for(int i = 0; i<rows; i++)
		{
			for(int j = 0; j<cols; j++)
			{
				c = strtok(NULL, &delim);
				data[i][j] = (float)atof(c);
			}
		}
		
		Matrix * m = new Matrix(rows, cols);
		m->data = data;
		
		return *m;
	}


