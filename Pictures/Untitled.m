A=dlmread('temp.txt')

x=A(:,1);
y1=A(:,2);
y2=A(:,3);
y3=A(:,4);

plot(x,y1,x,y2,x,y3)
