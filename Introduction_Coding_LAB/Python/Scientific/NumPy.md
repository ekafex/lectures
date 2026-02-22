This lecture is based on [Python Scientific Lecture](https://lectures.scientific-python.org/).

# Introduction to NumPy

NumPy (Numerical Python) is a powerful library for numerical computing in Python. It is a cornerstone of the scientific Python ecosystem, enabling efficient handling and computation of large datasets.

### Key Features

- **Multi-Dimensional Arrays**: Provides the `ndarray` object for creating and manipulating arrays with arbitrary dimensions.
- **Mathematical Operations**: Includes functions for linear algebra, statistics, Fourier transforms, and more.
- **Broadcasting**: Simplifies arithmetic operations on arrays with different shapes.
- **Performance**: Optimized for speed, significantly outperforming Python lists in numerical tasks.
- **Integration**: Works seamlessly with other libraries like SciPy, Pandas, and Matplotlib.



# `NumPy` Tutorial: Essential Methods for Scientific Computing

NumPy (Numerical Python) is a core library for numerical computations in Python, providing high-performance tools for handling large multi-dimensional arrays and performing mathematical operations. This tutorial covers its most widely used methods in scientific computing.

---

## 1. **Creating Arrays**

### 1.1 Basic Arrays
```python
import numpy as np

# 1D Array
arr1 = np.array([1, 2, 3])

# 2D Array
arr2 = np.array([[1, 2], [3, 4]])

# 3D Array
arr3 = np.array([[[1, 2], [3, 4]], [[5, 6], [7, 8]]])
```

### 1.2 Predefined Arrays
```python
# Arrays of Zeros and Ones
zeros = np.zeros((2, 3))  # 2x3 array of zeros
ones = np.ones((2, 3))    # 2x3 array of ones

# Arrays with Ranges
arange = np.arange(0, 10, 2)  # [0, 2, 4, 6, 8]

# Linearly Spaced Arrays
linspace = np.linspace(0, 1, 5)  # [0. , 0.25, 0.5 , 0.75, 1. ]
```

---

## 2. **Array Operations**

### 2.1 Element-Wise Operations
```python
arr = np.array([1, 2, 3])

# Arithmetic
arr_add = arr + 5  # [6, 7, 8]
arr_mult = arr * 2  # [2, 4, 6]

# Comparison
bool_arr = arr > 2  # [False, False, True]
```

### 2.2 Linear Algebra
```python
# Matrix Multiplication
A = np.array([[1, 2], [3, 4]])
B = np.array([[5, 6], [7, 8]])
C = np.dot(A, B)

# Transpose
A_T = A.T
```

---

## 3. **Array Statistics**
```python
arr = np.array([1, 2, 3, 4, 5])

mean = np.mean(arr)  # Average: 3.0
std = np.std(arr)    # Standard Deviation: 1.414
sum_ = np.sum(arr)   # Sum: 15
```

---

## 4. **Array Indexing and Slicing**
```python
arr = np.array([[1, 2, 3], [4, 5, 6]])

# Accessing Elements
elem = arr[0, 2]  # 3

# Slicing
row = arr[1, :]   # [4, 5, 6]
col = arr[:, 1]   # [2, 5]
```

---

## 5. **Reshaping and Manipulating Arrays**
```python
arr = np.arange(6)

# Reshaping
reshaped = arr.reshape(2, 3)

# Concatenation
arr1 = np.array([1, 2])
arr2 = np.array([3, 4])
concat = np.concatenate((arr1, arr2))  # [1, 2, 3, 4]

# Splitting
split = np.array_split(arr, 3)
```

---

## 6. **Broadcasting**
Broadcasting allows operations on arrays of different shapes.
```python
arr = np.array([[1, 2], [3, 4]])
scalar = 10

result = arr + scalar  # Adds 10 to every element
```

---

## 7. **Saving and Loading Data**
```python
arr = np.array([1, 2, 3])

# Save to a file
np.save('array.npy', arr)

# Load from a file
loaded_arr = np.load('array.npy')
```

---

## 8. **Example: Solving a Linear System**
Solve the equation $Ax = b$ where:
$A = \begin{bmatrix} 3 & 1 \\ 1 & 2 \end{bmatrix}, \quad b = \begin{bmatrix} 9 \\ 8 \end{bmatrix}$

```python
A = np.array([[3, 1], [1, 2]])
b = np.array([9, 8])

# Solve Ax = b
x = np.linalg.solve(A, b)
```

---



## 9. **Exercises with Solutions**

#### Exercise 1: Create and Reshape an Array

**Task**: Create a 1D array with values from 1 to 12, then reshape it into a 3x4 array.

**Solution**:
```python
arr = np.arange(1, 13)
reshaped = arr.reshape(3, 4)
print(reshaped)
```

#### Exercise 2: Element-Wise Operations

**Task**: Given an array `arr = np.array([2, 4, 6, 8])`, add 10 to each element and compute the square of each result.

**Solution**:
```python
arr = np.array([2, 4, 6, 8])
added = arr + 10
squared = added ** 2
print(squared)
```

#### Exercise 3: Array Statistics

**Task**: Calculate the mean, sum, and standard deviation of the array `arr = np.array([10, 20, 30, 40, 50])`.

**Solution**:
```python
arr = np.array([10, 20, 30, 40, 50])
mean = np.mean(arr)
sum_ = np.sum(arr)
std = np.std(arr)
print(mean, sum_, std)
```

#### Exercise 4: Matrix Multiplication

**Task**: Multiply the matrices $A = \begin{bmatrix} 1 & 2 \\ 3 & 4 \end{bmatrix}$ and $B = \begin{bmatrix} 5 & 6 \\ 7 & 8 \end{bmatrix}$.

**Solution**:

```python
A = np.array([[1, 2], [3, 4]])
B = np.array([[5, 6], [7, 8]])
C = np.dot(A, B)
print(C)
```

#### Exercise 5: Broadcasting

**Task**: Subtract the mean of each row from the respective row of the array `arr = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])`.

**Solution**:
```python
arr = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
row_means = arr.mean(axis=1, keepdims=True)
result = arr - row_means
print(result)
```

---

By mastering these core methods in NumPy, along with practice through exercises, you’ll have the tools needed to handle a variety of scientific and data analysis tasks efficiently.

