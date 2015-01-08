import scipy.io as sio  
import matplotlib.pyplot as plt
# Make some fake data.



data = sio.loadmat('mydata.mat')



# Create plots with pre-defined labels.

plt.figure(1)
plt.plot(data['X'], data['Y'], 'k--', label='Model length',linewidth = 3)
plt.plot(data['ideaX'], data['ideaY'], 'r:', label='Data length', linewidth=3)
legend = plt.legend(loc='best', shadow=True, fontsize='x-large')
plt.title('Path-Following performance with RRS')
plt.ylabel('Y-direction')
plt.xlabel('X-direction')

# Put a nicer background color on the legend.
legend.get_frame().set_facecolor('#0FFFFF')

plt.show()





plt.figure(2)

ui_lim = data['ui_lim']

ui_lim = [float(a)*180.0/3.14159 for a in ui_lim]
plt.plot(data['tt'], ui_lim, 'k-', label='Rudder Angle',linewidth = 1.8)
legend = plt.legend(loc='upper center', shadow=True, fontsize='x-large')
plt.title('Path-Following performance with RRS, rudder angle')
plt.xlabel('Time(s)')
plt.ylabel('Rudder angle(degree)')
plt.xlim(0,1000)

# Put a nicer background color on the legend.
legend.get_frame().set_facecolor('#0FFFFF')
plt.show()





 



plt.figure(3)

phi = data['phi']


phi_0 = data['phi_0']
phi_0 = [0.7*float(a)*180.0/3.14159 for a in phi_0]

#phi_0,'r--',label='phi_0',linewidth=2


phi = [float(a)*180.0/3.14159 for a in phi]
plt.plot(data['tt'], phi, 'k-',linewidth = 1.8,label = 'Roll angle $\phi_0$')
plt.plot(data['tt'],phi_0,'r--',label='Equilibrium point $\phi_0$',linewidth = 2.0)
legend = plt.legend(loc='best', shadow=True, fontsize='x-large')
plt.title('Path-Following performance with RRS, roll angle')
plt.xlabel('Time(s)')
plt.ylabel('Roll angle(degree)')
plt.xlim(0,1000)

# Put a nicer background color on the legend.
legend.get_frame().set_facecolor('#0FFFFF')
plt.show()




plt.figure(4)

u = data['u']

plt.plot(data['tt'], u, 'k-', label='Surge velocity',linewidth = 1.8)
legend = plt.legend(loc='center right', shadow=True, fontsize='x-large')
plt.title('Path-Following performance with RRS, surge velocity')
plt.xlabel('Time(s)')
plt.ylabel('Surge velocity (m/s)')
plt.xlim(0,2000)

# Put a nicer background color on the legend.
legend.get_frame().set_facecolor('#0FFFFF')
plt.show()








plt.figure(5)
dataT = data['Dis_PS_p']
dis_e = [a[0] for a in dataT]
dis_s = [a[1] for a in dataT]

# plt.plot(data['tt'], u, 'k-', label='Surge velocity',linewidth = 1.8)
# legend = plt.legend(loc='center right', shadow=True, fontsize='x-large')
# plt.title('Path-Following performance with RRS, surge velocity')
# plt.xlabel('Time(s)')
# plt.ylabel('Surge velocity (m/s)')
# plt.xlim(0,2000)
#print len(e)
#print dis_e

plt.subplot(2, 1, 1)
plt.plot(data['tt'], dis_e,'r-',linewidth=2,label='Distance $e$')
legend = plt.legend(loc='center right', shadow=True, fontsize='x-large')
legend.get_frame().set_facecolor('#0FFFFF')
plt.title('The Error Dynamics')
plt.ylabel('Distance $e$ (m)')

plt.subplot(2, 1, 2)
plt.plot(data['tt'], dis_s,'g-',linewidth=2,label='Distance $s$')
legend = plt.legend(loc='center right', shadow=True, fontsize='x-large')
plt.xlabel('time (s)')
plt.ylabel('Distance $s$ (m)')
legend.get_frame().set_facecolor('#0FFFFF')
plt.show()

# Put a nicer background color on the legend.



