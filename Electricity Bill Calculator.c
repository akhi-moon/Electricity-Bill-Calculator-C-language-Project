#include<stdio.h>
float h,m;
float spti(float h,float m);
struct e_billcal
{
char product[20];
float h,m,whole_time;
double p_kwh;
double t_kwh;
};
int main()
{
int i,j=0,n,m_n,d,y,day,p_tk;
float s=0.00,x=0.00,pm_unit,total_cost,pay;
char m[10];
printf("Number of products in your house:");
scanf("%d",&n);
printf("Current date:");
scanf("%d%d%d",&day,&m_n,&y);
struct e_billcal e_p[n];

for(i=0;i<n;i++)
{
scanf("%s",e_p[i].product);
scanf("%f",&e_p[i].h);
scanf("%f",&e_p[i].m);
scanf("%lf",&e_p[i].p_kwh);
}
printf("\n\nProducts' Name\t Running Time\t\tTaka Per Kwh\t\tUnit per Product");
for(i=0;i<n;i++)
{
printf("\n%s",e_p[i].product);
e_p[i].whole_time=spti(e_p[i].h,e_p[i].m);
printf("\t\t\t\t %2.2f",e_p[i].whole_time);
printf("\t\t\t %lf",e_p[i].p_kwh);
e_p[i].t_kwh=e_p[i].whole_time*e_p[i].p_kwh;
printf("\t\t\t %lf",e_p[i].t_kwh);
s+=e_p[i].t_kwh;
}
for(i=0;i<n;i++)
{
if(x<e_p[i].t_kwh)
{
x=e_p[i].t_kwh;
j=i;
}
}
printf("\n\n\nTotal spent in a day=%.2lf",s);
printf("\n\nMost costing Product=%s",e_p[j].product);
if(m_n==12)
{
m_n=0;
y=y+1;
}
switch(m_n+1)
{
case 1:
case 3:
case 5:
case 7:
case 8:
case 10:
case 12:
d=31;
break;
case 4:
case 6:
case 9:
case 11:
d=30;
break;
}
if(m_n+1==2)
{
if(y%4==0)
d=29;
else if(y%400==0)
d=29;
else if(y%100!=0)
d=28;
else
d=28;
}
pm_unit=s*d;
printf("\n\nTotal Unit per month=%.2f",pm_unit);
if(pm_unit<=75)
{
total_cost=(pm_unit*4.072);
}
else if(pm_unit>75 && pm_unit<=200)
{
total_cost=(pm_unit-75)*5.19+(75*4.072);
}
else if(pm_unit>200 && pm_unit<=300)
{
total_cost=(pm_unit-200)*5.36+(200*5.19)+(75*4.072);
}
else if(pm_unit>300 && pm_unit<=400)
{
total_cost=(pm_unit-300)*5.63+(300*5.36)+(200*5.19)+(75*4.072);
}
else if(pm_unit>400 && pm_unit<=600)
{
total_cost=(pm_unit-400)*6.55+(400*5.63)+(300*5.36)+(200*5.19)+(75*4.072);
}
else if(pm_unit>600)
{
total_cost=(pm_unit-600)*9.98+(600*6.55)+(400*5.63)+(300*5.36)+(200*5.19)+(75*4.072)+15;
}
printf("\n\nTotal Cost=%.3lf",total_cost);
pay=(total_cost*0.05)+total_cost;
p_tk=ceil(pay)+30;/*vat-charge=30//=*/
printf("\n\nTaka need to be paid=%d",p_tk);
return (0);
}
float spti(float h,float m)
{
h=h+(m/60);
return (h);
}
