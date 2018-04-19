import numpy as np

import matplotlib.pyplot as plt


x = np.loadtxt("datos.txt")[:, 0]

y = np.loadtxt("datos.txt")[:, 1]

ori = np.loadtxt("datos.txt")[:, 2]

plt.plot(x, y, label="respuesta")

plt.plot(x, ori, label ="original")

plt.ylim(0.0, 1.1)

plt.legend(loc=0)

plt.savefig("back.png")
