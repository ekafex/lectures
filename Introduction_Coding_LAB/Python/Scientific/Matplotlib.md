# `Matplotlib` Tutorial: Essential Techniques for Visualization

Matplotlib is a powerful library for creating static, animated, and interactive visualizations in Python. This tutorial introduces its most commonly used methods for generating plots in scientific computing.

---

## 1. **Basic Plotting**

### 1.1 Line Plot
```python
import matplotlib.pyplot as plt

# Basic Line Plot
x = [0, 1, 2, 3, 4]
y = [0, 1, 4, 9, 16]

plt.plot(x, y, label='y = x^2')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.title('Line Plot')
plt.legend()
plt.show()
```

### 1.2 Scatter Plot
```python
import matplotlib.pyplot as plt

# Scatter Plot
plt.scatter(x, y, color='red', label='Points')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.title('Scatter Plot')
plt.legend()
plt.show()
```

---

## 2. **Customizing Plots**

### 2.1 Adding Grid and Customizing Axes
```python
import matplotlib.pyplot as plt

# Customizing Plot Appearance
plt.plot(x, y, label='y = x^2', linestyle='--', color='blue')
plt.grid(True)
plt.xlim(-1, 5)
plt.ylim(-1, 20)
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.title('Customized Line Plot')
plt.legend()
plt.show()
```

### 2.2 Subplots
```python
import matplotlib.pyplot as plt

# Creating Subplots
fig, axs = plt.subplots(2, 1, figsize=(6, 8))

# First subplot
axs[0].plot(x, y, label='y = x^2', color='green')
axs[0].set_title('Subplot 1: Line Plot')
axs[0].legend()

# Second subplot
axs[1].scatter(x, y, color='purple', label='Points')
axs[1].set_title('Subplot 2: Scatter Plot')
axs[1].legend()

plt.tight_layout()
plt.show()
```

---

## 3. **Bar and Histogram Plots**

### 3.1 Bar Plot
```python
import matplotlib.pyplot as plt

# Bar Plot
categories = ['A', 'B', 'C', 'D']
values = [5, 7, 3, 8]

plt.bar(categories, values, color='orange')
plt.xlabel('Categories')
plt.ylabel('Values')
plt.title('Bar Plot')
plt.show()
```

### 3.2 Histogram
```python
# Histogram
import numpy as np
import matplotlib.pyplot as plt

data = np.random.randn(1000)

plt.hist(data, bins=20, color='skyblue', edgecolor='black')
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('Histogram')
plt.show()
```

---

## 4. **Advanced Techniques**

### 4.1 Plot with Annotations
```python
import matplotlib.pyplot as plt

# Annotating Points on a Plot
plt.plot(x, y, marker='o', label='y = x^2')
for i, txt in enumerate(y):
    plt.annotate(txt, (x[i], y[i]))
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.title('Plot with Annotations')
plt.legend()
plt.show()
```

### 4.2 3D Plot
```python
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# 3D Line Plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

z = [0, 1, 2, 3, 4]
ax.plot(x, y, z, label='3D Line')
ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')
ax.set_zlabel('Z-axis')
plt.title('3D Line Plot')
plt.legend()
plt.show()
```

---

## 5. **Saving Plots**
```python
import matplotlib.pyplot as plt

# Save Plot to File
plt.plot(x, y, label='y = x^2')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.title('Saved Plot')
plt.legend()
plt.savefig('plot.png', dpi=300)
plt.show()
```

---

## 6. **Exercises with Solutions**

### Exercise 1: Basic Line Plot
**Task**: Plot the sine and cosine functions on the interval [0, 2π]. Label the axes and include a legend.

**Solution**:
```python
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 2 * np.pi, 100)
y_sin = np.sin(x)
y_cos = np.cos(x)

plt.plot(x, y_sin, label='sin(x)', color='blue')
plt.plot(x, y_cos, label='cos(x)', color='red')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.title('Sine and Cosine Functions')
plt.legend()
plt.show()
```

### Exercise 2: Histogram
**Task**: Create a histogram of 1000 random numbers generated from a standard normal distribution, using 30 bins.

**Solution**:
```python
import matplotlib.pyplot as plt
import numpy as np

data = np.random.randn(1000)

plt.hist(data, bins=30, color='green', edgecolor='black')
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('Histogram of Random Data')
plt.show()
```

### Exercise 3: Subplots
**Task**: Create a 1x2 grid of subplots. The first subplot should display a line plot, and the second subplot should display a scatter plot using the same data.

**Solution**:
```python
import matplotlib.pyplot as plt
import numpy as np

fig, axs = plt.subplots(1, 2, figsize=(10, 4))

# Line plot
axs[0].plot(x, y_sin, label='sin(x)', color='blue')
axs[0].set_title('Line Plot')
axs[0].legend()

# Scatter plot
axs[1].scatter(x, y_cos, color='red', label='cos(x)')
axs[1].set_title('Scatter Plot')
axs[1].legend()

plt.tight_layout()
plt.show()
```

---

By mastering these techniques, you'll be able to create a wide variety of visualizations to suit your data analysis and presentation needs.