import numpy as np
import matplotlib.pylab as plt
datos=np.genfromtxt("datos1.dat")
plt.figure()
plt.plot(datos[:,0],datos[:,1], c='pink', label="funcion coseno")
plt.plot(datos[:,0],datos[:,2], c='cyan', label="funcion derivada")
plt.legend()
plt.xlabel("x")
plt.ylabel("f(x) y f'(x)")
plt.title("Grafica S12C2")
plt.savefig("plot1.pdf")