P = tf(3,[1 3 2 0]);


KP = 0.7;
KI = 0.1;
KD = 0.5;

Ppid = tf([KD KP KI],[1 0]);

G = Ppid*P/(1+Ppid*P)
G1 = feedback(Ppid*P,1)
zero(G1)
pole(G1)
step(G1)

sim("PID_1");