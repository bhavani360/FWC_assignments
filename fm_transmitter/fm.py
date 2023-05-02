import matplotlib.pyplot as plt
import numpy as np

from scipy.io.wavfile import read
from scipy.io.wavfile import write

Fs,audio_data= read("test.wav")

#plt.plot(audio_data[0:870191])
#plt.savefig("/home/bhavani/Downloads/fm_transmitter/audio_sig.png")
print(audio_data.shape)

#N = 870191
N = len(audio_data)
#print(N)
dt = 1e-6/N
t = np.arange(N)    # time span 1micro sec
t = t*dt

df = 1/(N*dt);     # df = 1 MHz
f = np.arange(N) *df;    # freq span 1 MHz    
fc = 10e6;
#fm=100;

ym = np.array(audio_data[:,0] + audio_data[:,1]) # Audio data
print("ym",ym)
#t = np.arange(ym.size) / Fs

kf = 1     # Frequency deviation
cumsum = np.cumsum(ym)  # Discrete summation
print("cumsum(ym) = ",cumsum)

# FM signal
c = np.cos(2*np.pi*fc*t)  # Carrier wave
 
y_fm = np.cos(2*np.pi*fc*t + 2*np.pi*kf*cumsum*(1/N)) #FM signal

write('FM_signal_out.wav', Fs, y_fm)
