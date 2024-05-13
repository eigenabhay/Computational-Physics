import numpy as np
import matplotlib.pyplot as plt
import cmath

def f(x):
	return np.exp(-x**2)	


x_min=-40
x_max=40

n=2**10
x_vals=np.linspace(x_min,x_max,n)
delta=x_vals[1]-x_vals[0]
y_vals=np.array([f(x) for x in x_vals])

y_dft=np.fft.fft(y_vals,norm="ortho")
n=len(y_dft)
k_vals=np.fft.fftshift(2*np.pi*np.fft.fftfreq(n,delta))
y_dft=np.fft.fftshift(y_dft)
yt_vals=np.array([delta*np.sqrt(n/(2*np.pi))*cmath.exp(-1j*x_min*kq)*y_dft[i] for i,kq in enumerate(k_vals)])


#Using data from fftw(prob4)
data=np.loadtxt("prob4results.txt")
y_dftfftw=[complex(a[0],a[1]) for a in data]
y_dftfftw=np.fft.fftshift(y_dftfftw)
yt_valsfftw=np.array([delta*np.sqrt(n/(2*np.pi))*cmath.exp(-1j*x_min*kq)*y_dftfftw[i] for i,kq in enumerate(k_vals)])


plt.subplot(2,1,1)
plt.plot(k_vals,np.abs(yt_vals),"--c")
plt.legend(["numpy.fft.fft"])
plt.ylabel(r"$\tilde{f}(k)$")
plt.xlim(-10,10)

plt.subplot(2,1,2)
plt.plot(k_vals,np.abs(yt_valsfftw),"--c")
plt.legend(["fftw3"])
plt.ylabel(r"$\tilde{f}(k)$")
plt.xlim(-10,10)

plt.suptitle("Fourier Transform of Gaussian Function")

#plt.show()
plt.savefig("fig")

