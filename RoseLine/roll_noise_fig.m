clc;clear;
load('noise_roll.mat')
figure_FontSize=14;

subplot(2,1,1)
plot(noise_roll(1,:),noise_roll(2,:),'linewidth',1.5);axis([0,1000,-3*10^-3,3*10^-3]);xlabel('a. Time(second)');ylabel('Disturbance(rad/s^2)');set(get(gca,'XLabel'),'FontSize',figure_FontSize);set(get(gca,'YLabel'),'FontSize',figure_FontSize);

subplot(2,1,2)
plot(noise_roll(1,:),noise_roll(2,:),'linewidth',1.5);axis([400,500,-2*10^-3,2*10^-3]);xlabel('a. Time(second)');ylabel('Disturbance(rad/s^2)');set(get(gca,'XLabel'),'FontSize',figure_FontSize);set(get(gca,'YLabel'),'FontSize',figure_FontSize);
%plot(noise_roll(1,1000:4000),noise_roll(2,1000:4000));axis([200,500,-2*10^-3,-2*10^-3])

set(gcf,'position',[80 0 900 600]) 

figure_FontSize=14;




