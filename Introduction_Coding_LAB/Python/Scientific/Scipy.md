This lecture is based on [Python Scientific Lecture](https://lectures.scientific-python.org/).

# `SciPy` Tutorial: Essential Methods for Scientific Computing

SciPy is a Python library built on NumPy that provides additional tools for scientific and technical computing. It includes modules for optimization, integration, interpolation, linear algebra, statistics, and more. This tutorial covers its most widely used methods and practical applications.

---

## 1. **Optimization**

### 1.1 Finding the Minimum of a Function
```python
from scipy.optimize import minimize

# Define a quadratic function
f = lambda x: (x - 3)**2

# Minimize the function
result = minimize(f, x0=0)
print("Minimum value:", result.fun)
print("At x =", result.x)
```

### 1.2 Solving Equations
```python
from scipy.optimize import root

# Define an equation: x^3 - 6x^2 + 11x - 6 = 0
f = lambda x: x**3 - 6*x**2 + 11*x - 6

# Find the root
solution = root(f, x0=2)
print("Root:", solution.x)
```

---

## 2. **Integration**

### 2.1 Definite Integrals
```python
from scipy.integrate import quad

# Define a function to integrate
f = lambda x: x**2

# Integrate from 0 to 1
result, error = quad(f, 0, 1)
print("Integral result:", result)
```

### 2.2 Solving Ordinary Differential Equations (ODEs)
```python
from scipy.integrate import solve_ivp
import numpy as np
import matplotlib.pyplot as plt

# Define a simple ODE: dy/dt = -2y
def f(t, y):
    return -2 * y

# Solve the ODE from t=0 to t=5 with initial condition y(0)=1
solution = solve_ivp(f, [0, 5], [1])

# Plot the solution
t = solution.t
y = solution.y[0]
plt.plot(t, y, label='y(t)')
plt.xlabel('Time')
plt.ylabel('y')
plt.title('Solution of dy/dt = -2y')
plt.legend()
plt.show()
```

---

## 3. **Interpolation**

### 3.1 1D Interpolation
```python
from scipy.interpolate import interp1d
import numpy as np
import matplotlib.pyplot as plt

# Define data points
x = np.array([0, 1, 2, 3, 4])
y = np.array([1, 3, 2, 5, 4])

# Create interpolation function
f = interp1d(x, y, kind='cubic')

# Generate interpolated values
x_new = np.linspace(0, 4, 100)
y_new = f(x_new)

# Plot
plt.plot(x, y, 'o', label='Data')
plt.plot(x_new, y_new, '-', label='Cubic Interpolation')
plt.legend()
plt.show()
```

---

## 4. **Linear Algebra**

### 4.1 Solving Linear Systems
```python
from scipy.linalg import solve

# Define a linear system Ax = b
A = np.array([[3, 2], [1, 4]])
b = np.array([8, 10])

# Solve for x
x = solve(A, b)
print("Solution x:", x)
```

### 4.2 Eigenvalues and Eigenvectors
```python
from scipy.linalg import eig

# Define a matrix
A = np.array([[5, 4], [2, 3]])

# Compute eigenvalues and eigenvectors
values, vectors = eig(A)
print("Eigenvalues:", values)
print("Eigenvectors:", vectors)
```

---

## 5. **Statistics**

### 5.1 Descriptive Statistics
```python
from scipy.stats import describe

# Define a dataset
data = np.array([1, 2, 2, 3, 3, 3, 4, 4, 5])

# Compute statistics
stats = describe(data)
print("Mean:", stats.mean)
print("Variance:", stats.variance)
```

### 5.2 Probability Distributions
```python
from scipy.stats import norm
import matplotlib.pyplot as plt

# Create a normal distribution
mean, std_dev = 0, 1
x = np.linspace(-4, 4, 100)

# PDF and CDF
pdf = norm.pdf(x, mean, std_dev)
cdf = norm.cdf(x, mean, std_dev)

# Plot
plt.plot(x, pdf, label='PDF')
plt.plot(x, cdf, label='CDF')
plt.legend()
plt.show()
```

---

## 6. **Exercises with Solutions**

### Exercise 1: Minimize a Function
**Task**: Minimize the function \( f(x) = (x + 2)^2 + 1 \).

**Solution**:
```python
f = lambda x: (x + 2)**2 + 1
result = minimize(f, x0=0)
print("Minimum value:", result.fun)
print("At x =", result.x)
```

### Exercise 2: Solve an ODE
**Task**: Solve \( dy/dt = 3y \) from \( t = 0 \) to \( t = 2 \), with \( y(0) = 1 \).

**Solution**:
```python
def f(t, y):
    return 3 * y
solution = solve_ivp(f, [0, 2], [1])
print("Solution:", solution.y)
```

### Exercise 3: Interpolation
**Task**: Use cubic interpolation to approximate the function values for \( x = [1.5, 2.5] \) given \( x = [0, 1, 2, 3] \) and \( y = [0, 1, 4, 9] \).

**Solution**:
```python
x = np.array([0, 1, 2, 3])
y = np.array([0, 1, 4, 9])

f = interp1d(x, y, kind='cubic')
print("Interpolated values:", f([1.5, 2.5]))
```

---

By mastering these techniques, you can solve a wide variety of scientific and mathematical problems efficiently using SciPy.



