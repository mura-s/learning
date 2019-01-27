import numpy as np

# 1次元
x = np.array([1.0, 2.0, 3.0])
y = np.array([2.0, 4.0, 6.0])
print(x)
print(x + y)
print(x * y)

# 2次元
a = np.array([[1, 2], [3, 4], [5, 6]])
print(a)
print(a.shape)
print(a[0])

# loop
for row in a:
    print(row)

# 要素の抜き出し
b = a.flatten()
print(b[np.array([3, 5])])

print(b > 3)
print(b[b > 3])
