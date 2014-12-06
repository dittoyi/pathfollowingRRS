 
noise_roll=yout(:,1);
 noise_yaw=yout(:,2);
dlmwrite('noise_roll.txt', noise_roll);
dlmwrite('noise_yaw.txt', noise_yaw);