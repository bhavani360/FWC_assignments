#Code by GVV Sharma
#November 18, 2019
#released under GNU GPL
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np
from cvxpy import *
#from coeffs import *

#if using termux
import subprocess
import shlex
#end if

#creating x,y for 3D plotting
xx, yy = np.meshgrid(range(10), range(10))
#setting up plot
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')


def line_dir_pt(m,A,k1,k2):
  len = 10
  dim = A.shape[0]
  x_AB = np.zeros((dim,len))
  lam_1 = np.linspace(k1,k2,len)
  for i in range(len):
    temp1 = A + lam_1[i]*m
    x_AB[:,i]= temp1.T
  return x_AB

#Plane points
A1 = np.array([3,5,7])
A2 = np.array([-1,-1,-1])
m1 =np.array([1,-2,1])
m2 =np.array([7,-6,1])
k1 = -4
k2=4
x2_dist_skew = line_dir_pt(m2,A2,k1,k2)
x1_dist_skew = line_dir_pt(m1,A1,k1,k2)

# To find the shortest distance between two given lines
V = np.array([[6,-20],[-20,86]])
u = np.array([0,0]).reshape(2,1)
f1=116
x = Variable((2,1))

#Cost function
f =  (quad_form(x,V)+116)
obj = Minimize(f)

#Constraints
B=np.array([[1,0],[0,1]])
b_b=np.array([0,0]).reshape(2,1)
constraints = [  B@x>= b_b]

#solution
Problem(obj, constraints).solve()
#print(constraints)
print(np.sqrt(f.value),x.value)

#Plotting all lines
plt.plot(x1_dist_skew[0,:],x1_dist_skew[1,:], x1_dist_skew[2,:],label='$L_1$')
plt.plot(x2_dist_skew[0,:],x2_dist_skew[1,:], x2_dist_skew[2,:], label='$L_2$')
#plotting points
ax.scatter(A1[0],A1[1],A1[2],'o')
ax.scatter(A2[0],A2[1],A2[2],'o')
ax.text(3,5,7, "A1")
ax.text(-1,-1,-1, "A2")
print("Distance between two lines = ",np.sqrt(f.value))


plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid() # minor
#plt.axis('equal')
#if using termux
plt.savefig('/home/bhavani/Documents/optimization/opt_02/opt_2.pdf')
#subprocess.run(shlex.split("termux-open ' /home/bhavani/Documents/optimization/opt_02/opt_2.pdf'"))
#else
plt.show()
