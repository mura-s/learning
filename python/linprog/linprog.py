# https://siguniang.wordpress.com/2016/01/11/solve-linear-programming-with-scipy/

# minimize
#   z = -x_1 - 2x_2
#   (右辺に-1をかけて、目的関数の最小化問題に変えている)
#
# subject to
#    x_1 + 3x_2 <= 24
#   4x_1 + 4x_2 <= 48
#   2x_1 +  x_2 <= 22
#   x1, x2 >= 0

c = [-1, -2]
A = [[1, 3], [4, 4], [2, 1]]
b = [24, 48, 22]

x0_bounds = (0, None)
x1_bounds = (0, None)

from scipy.optimize import linprog

res = linprog(c, A_ub=A, b_ub=b, bounds=(x0_bounds, x1_bounds))
print(res)

