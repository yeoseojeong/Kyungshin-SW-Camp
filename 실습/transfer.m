%% 초기화
clc; clear;

%% 변수
J=2.09*10^(-5);
Kb=0.042;
Kt=0.042;
R=8.4;
L=1.16;
B=0.0003;

D1=[J*L J*R+L*B R*B+Kt*Kb]
N1=[Kt]
H=(N1(1)-D1(3))/N1(1)

%matrix
A=[0 1 0;0 -B/J Kt/J; 0 -Kb/L -R/L]
Bm=[0 0 1/L]';
C=[1 0 0];
D=0;

Ts=0.001;
%% 사인파 생성
t=linspace(Ts,10,10/Ts);
U=sin(t);
%%

x=[0;0;0]; y=0;u=0;xd=0;
theta=0;theta_noise=0;
vel=0;theta_d=0;
vel_fil=0;
vel_fil_d=0;
for k=1:10/Ts
    xd=A*x+Bm*U(k);
    x=x+xd.*Ts;
    theta(k)=C*x;
    noise=0.001*rand;
    theta_noise(k)=theta(k)+noise;
    vel(k)=(theta_noise(k)-theta_d)/Ts;
    theta_d=theta_noise(k);
    vel_fil(k)=LPF(vel_fil_d,vel(k),200,Ts);
    vel_fil_d=vel_fil(k);

end

figure
plot(t,vel,'k','LineWidth',1.5)
hold on;
plot(t,vel_fil,'r--','LineWidth',1.5)
grid on;
title('Sampling time:',Ts);
xlabel('Time');
ylabel('\omega');

function Y_fil=LPF(Y_fil_d,U,cf,Ts)

Y_fil=(1-Ts*cf)*Y_fil_d+Ts*cf*U

end

