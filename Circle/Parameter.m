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
flag=0;
n_mean=0;
n_var=0.5;
K_w=0*1*2.5*10^-3;%0.8*10^-3;
xi_0=0.075;
omega_0=2*pi/10;
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
x_0=[0.1 0 0 0 1000 0.2 0 0 0 70]';
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
T_t=2500;%3500
tt=[0:h:T_t]';

%plot([0 30000],[0 60000],'-r');
%hold on;
%total simulation time
%sim('untitled')