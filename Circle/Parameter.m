clc;clear;
%global U0 h gama Delta_e c1 c2 c3 T_t x_0;
% x = [ u v r x y psi delta]' 
% u     = pertubed surge velocity about Uo (m/s)
% v     = pertubed sway velocity about zero (m/s)
% r     = pertubed yaw velocity about zero (rad/s)
% x     = position in x-direction (m)
% y     = position in y-direction (m)
% psi   = pertubed yaw angle about zero (rad)
% delta = actual rudder angle (rad)
%NOISE PARAMETER

e=-20;


flag=0;
n_mean=0;
n_var=0.5;
K_w_roll=0.4*10^-3;
K_w_yaw=9*10^-6;
xi_0=0.075;
omega_0=0.22;
Ampli_psi2phi=4;
Delta_t=0.1;
% % % % % % U0=7.7175;
% % % % % % beta=0.2*pi/180;
% % % % % % x_0=[0 0 0 0 0 0 0]';
% % % % % % x=x_0;
% % % % % % h=0.1;
% % % % % % Tao=10;
% % % % % % mmm=0.1;
% % % % % % gama=0.1;
% % % % % % Delta_e=1200;
% % % % % % Theta_wp_c_last=0;
% % % % % % Theta_po_last=0;
% % % % % % c1=20*beta;
% % % % % % c2=200;k1=1000*beta;
% % % % % % ui=0;
% % % % % % T_t=300;
% % % % % % tt=[0:h:T_t]';
U0=7.7175;
beta=0.2*pi/180;
x_0=[0.1 0 0 0 4500 0.2 0 0 0 70]';
x=x_0;
h=0.1;
Tao=10;
mmm=0.1;
m_delay=0;% the m delay parameter, in the m_update subsystem
gama=0.3;
Filter_f=1;%0.20;%0.1;
Filter_yes_no=0;
Delta_e=500;
Theta_wp_c_last=0;
Theta_po_last=0;
% c1=10*beta;
% c2=400;k1=1*180*beta;
c1=1*beta;
c2=400;k1=1*0.5*180*beta;
gainf=0.3;%0.3;

ui=0;
T_t=3500;%3500
tt=[0:h:T_t]';






sim untitled2.slx

ww=0.3;
m = mm
ideaX = 5000*sin(0.01*m);
ideaY = 5000*cos(0.01*m);

save data_fig/mydata X Y phi psi r_desire roll_noise ui ui_lim Dis_Path_o Dis_PS_p ideaX ideaY tt u phi_0



%plot([0 30000],[0 60000],'-r');
%hold on;
%total simulation time
%sim('untitled')