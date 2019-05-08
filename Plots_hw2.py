import numpy as np
import matplotlib.pylab as plt
datos=np.genfromtxt("datoslp.dat")
plt.figure(figsize=[10,10])
plt.plot(datos[:,3],datos[:,0], c='pink', label="U1")
plt.plot(datos[:,3],datos[:,1], c='cyan', label="U2")
plt.plot(datos[:,3],datos[:,2], c='orange', label="U3")
plt.legend()
plt.xlabel("tiempo(s)")
plt.ylabel("posicion(m)")
plt.title("Grafica de tiempo vs posicion")
plt.savefig("plot1.pdf")