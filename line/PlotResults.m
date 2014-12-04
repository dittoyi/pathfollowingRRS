% figure_FontSize=14;
% 
% subplot(2,1,1)
% plot(tt,ui,'linewidth',1.5);axis([0,T_t,-0.6,0.6]);xlabel('a. Time(second)');ylabel('Rudder angle(rad)');set(get(gca,'XLabel'),'FontSize',figure_FontSize);set(get(gca,'YLabel'),'FontSize',figure_FontSize);
% 
% subplot(2,1,2)
% set(gcf,'position',[80 0 900 600]) 



figure_FontSize=14;
plot(X,Y,'-r','linewidth',2);
hold on;
m=mm;
ww=0.3;
plot(200*m,100*m,'linewidth',1.5);
%axis([0,T_t,-0.6,0.6]);
xlabel('X(m)');ylabel('Y(m)');set(get(gca,'XLabel'),'FontSize',figure_FontSize);set(get(gca,'YLabel'),'FontSize',figure_FontSize);
%axis equal;
hold on;
