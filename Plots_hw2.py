import numpy as np
import matplotlib.pylab as plt
datos=np.genfromtxt("datos_omega.dat", skip_header=1)
daticos=np.genfromtxt("datoslp.dat")
plt.figure(figsize=[10,10])
plt.scatter(datos[:,3],datos[:,0], c='pink', label="U1")
plt.scatter(datos[:,3],datos[:,1], c='cyan', label="U2")
plt.scatter(datos[:,3],datos[:,2], c='orange', label="U3")
plt.title("Maximas amplitudes para diferentes omegas")
plt.legend()
plt.xlabel("omega")
plt.ylabel("posicion(m)")
plt.savefig("plot_omegas.pdf")

plt.figure(figsize=[10,10])
plt.plot(daticos[:,3],daticos[:,0], c='pink', label="U1")
plt.plot(daticos[:,3],daticos[:,1], c='cyan', label="U2")
plt.plot(daticos[:,3],daticos[:,2], c='orange', label="U3")
plt.legend()
plt.title("Desplazamiento para omega=1*raiz(k/m)")
plt.xlabel("tiempo(s)")
plt.ylabel("posicion(m)")
plt.savefig("plot_omegafijo.pdf")

