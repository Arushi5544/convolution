# convolution
Convolution in C

This C program demonstrates the implementation of a basic convolution operation on a 2D matrix using a filter/kernel. Convolution is a fundamental operation in digital image processing and deep learning for tasks like feature extraction and image filtering.

# Program Overview
The program performs the following steps:

## Initialization:
* Randomly generates the dimensions of the input matrix (n), filter/kernel (filter_size), padding size (padding), and stride (stride).
* Dynamically allocates memory for the input matrix, filter, and result matrix with appropriate sizes and padding.
## Input Matrix and Filter Generation:
* Assigns random values to the input matrix with optional padding.
* Assigns random values to the filter/kernel.
## Convolution Operation:
* Applies convolution operation on the input matrix using the filter.
* Computes the output matrix by performing element-wise multiplication and summation according to the convolution operation.
## Output:
* Prints the input matrix, filter, and the resulting output matrix.
