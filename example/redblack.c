#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024

int main()
{
	double* m;
	int i, j, it;
	double sum = 0.0;

	m = (double*) malloc(sizeof(double)*SIZE*SIZE);
	
	// init points
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
			m[i*SIZE+j] = 0.0;
	// set left/right border
	for(i=0;i<SIZE;i++) {
		m[ i*SIZE + 0        ] = 10.0;
		m[ i*SIZE + (SIZE-1) ] = 10.0;
	}

	// run 50 iterations
	for(it=0;it<50;it++) {

		// update inner black points
		for(i=1;i<SIZE-1;i++)
			for(j=1+(i%2);j<SIZE-1;j+=2)
				m[i*SIZE+j] = ( m[(i-1)*SIZE +j] +
						m[(i+1)*SIZE +j] +
						m[ i*SIZE + j-1] +
						m[ i*SIZE + j+1] )/4.0;

                // update inner red points
                for(i=1;i<SIZE-1;i++)
                        for(j=1+((i+1)%2);j<SIZE-1;j+=2)
                                m[i*SIZE+j] = ( m[(i-1)*SIZE +j] +
                                                m[(i+1)*SIZE +j] +
                                                m[ i*SIZE + j-1] +
                                                m[ i*SIZE + j+1] )/4.0;
	}

	// print checksum
	for(i=0;i<SIZE;i++)
                for(j=0;j<SIZE;j++)
                        sum += m[i*SIZE+j];

	printf("Sum: %f\n", sum);

	return 1;
}
