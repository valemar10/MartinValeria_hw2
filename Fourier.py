#Ejercicio 2:Transformada de FOURIER
import numpy as np
import matplotlib.pylab as plt
import sys
#1) almacene los datos de signal.dat. La columna 1 es el tiempo y la columna 2 es su senial f(t). Grafique su senial en funcion del tiempo y guarde dicha grafica sin mostrarla en signal.pdf.

datos= np.genfromtxt('signal.dat')
datos1= np.genfromtxt('signalSuma.dat')
t=datos[:,0]
f=datos[:,1]
t1=datos1[:,0]
f1=datos1[:,1]
plt.figure(figsize=[15,15])
plt.subplot(1,2,1)
plt.plot(t,f, c='pink')
plt.xlabel("tiempo(s)")
plt.ylabel("f(t)")
plt.title("Ondas separadas")
# 2)almacene los datos de signalSuma.dat. Grafique su senial en funcion del tiempo y guarde dicha grafica sin mostrarla en signalSuma.pdf.
plt.subplot(1,2,2)
plt.plot(t1,f1, c='pink')
plt.xlabel("tiempo(s)")
plt.ylabel("f(t)")
plt.title("Suma de las ondas")
plt.savefig('signals.pdf')
# 3)Transformada de fourier de signal.dat
from scipy.fftpack import fft, fftfreq, ifft
x= fft(f) 
def fourier(numero,datos):
    listica=np.empty(0)
    for i in range(numero):
        zsum=0
        for j in range(numero):
            z=complex(0,2*np.pi*j*i/numero)
            zsum+=datos[j]*np.exp(-z)
            c=(abs(zsum)/numero)
        listica=np.append(listica, c)
    return listica
frecuencias= fftfreq(len(t))
s=fourier(len(f), f)
#4) Transformada de fourier de signalSuma.dat
frecuencias1= fftfreq(len(t1))
s1=fourier(len(f1), f1)
#5) Grafica en funcion de las frecuencias para ambas seniales

plt.figure(figsize=[15,15])
plt.subplot(1,2,1)
plt.plot(frecuencias, s, c='pink')
plt.xlabel("frecuencias")
plt.ylabel("f(t)")
plt.title("Grafica de la transformada de fourier para signal.dat")
plt.subplot(1,2,2)
plt.plot(frecuencias1, s1, c='magenta')
plt.xlabel("Frecuencias")
plt.ylabel("f(t)")
plt.title("Grafica de la transformada de fourier para signalSuma.dat")
plt.savefig('Fourier_trans.pdf')
#6)Creacion del espectograma

#7 importacion de los datos de temblor.txt
datos2=np.genfromtxt('temblor.txt', skip_header=4)

#Como la frecuencia es 100HZ se asume que los datos se toman cada 0.1 segundos
periodo=0.0
lista_x=[]
for i in range(len(datos2)):
    periodo+= 0.10
    lista_x.append(periodo)
#grafica de los datos de temblor.txt
plt.figure(figszize=[7,7])
plt.plot(lista_x,datos2, c='orange')
plt.xlabel('tiempo(s)')
plt.ylabel('f(t)')
plt.title('Grafica de los datos de temblor.txt')
plt.savefig('Temblor.pdf')
#grafica de la transformada de fourier de temblor.txt
frecuencias2= fftfreq(len(lista_x))
s2=fourier(len(datos2), datos2)
plt.figure(figsize=[8,8])
plt.plot(frecuencias2, s2, c='pink')
plt.xlabel("frecuencias")
plt.ylabel("f(t)")
plt.title("Grafica de la transformada de fourier para temblor.txt")
plt.savefig('Fourier_temblor.pdf')