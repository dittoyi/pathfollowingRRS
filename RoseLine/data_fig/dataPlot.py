import scipy.io as sio  
import matplotlib.pyplot as plt
# Make some fake data.



data = sio.loadmat('mydata.mat')



# Create plots with pre-defined labels.

plt.figure(1)
plt.plot(data['X'], data['Y'], 'k--', label='Model length',linewidth = 3)
plt.plot(data['ideaX'], data['ideaY'], 'r:', label='Data length', linewidth=3)
legend = plt.legend(loc='upper left', shadow=True, fontsize='x-large')
plt.title('Path-Following performance without RRS')
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
plt.title('Path-Following performance without RRS, rudder angle')
plt.xlabel('Time(s)')
plt.ylabel('Rudder angle(degree)')
plt.xlim(0,1000)

# Put a nicer background color on the legend.
legend.get_frame().set_facecolor('#0FFFFF')
plt.show()





 



plt.figure(3)

phi = data['phi']

phi = [float(a)*180.0/3.14159 for a in phi]
plt.plot(data['tt'], phi, 'k-', label='Rudder Angle',linewidth = 1.8)
legend = plt.legend(loc='upper center', shadow=True, fontsize='x-large')
plt.title('Path-Following performance without RRS, roll angle')
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
plt.title('Path-Following performance without RRS, surge velocity')
plt.xlabel('Time(s)')
plt.ylabel('Surge velocity (m/s)')
plt.xlim(0,6000)

# Put a nicer background color on the legend.
legend.get_frame().set_facecolor('#0FFFFF')
plt.show()




