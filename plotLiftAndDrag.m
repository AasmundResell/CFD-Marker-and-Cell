clear all
close all
clc

drag = readmatrix('drag.txt');
lift = readmatrix('lift.txt');

td = linspace(0,3,length(drag));
tl = linspace(0,3,length(lift));

figure(1)
plot(td,drag);
ylim([100,140]);
xlabel('t[s]');
ylabel('force');
title('Drag forces');

figure(2)
plot(tl,lift);
ylim([-4,2]);

xlabel('t[s]');
ylabel('force');
title('Lift forces');