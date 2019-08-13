#include<iostream.h>
#include<conio.h>
#include<limits.h>
void output();

void sjf();

int n,at[100],bt[100],ct[100],wt[100],tat[100],t,twt,ttat;
float avwt,avtat;

void main()
{
 clrscr();
 cout<<"enter no. of process ";
 cin>>n;
 cout<<"enter the AT of processes\n";
 for(int i=0;i<n;i++)

    cin>>at[i];
  cout<<"enter the BT of processes\n";
 for(i=0;i<n;i++)
	cin>>bt[i];


sjf();
output();
 getch();

}
void sjf()
{ int min=INT_MAX,copy[1000]={0},t=0,c=0,l;
 for(int i=0;i<n;i++)
     copy[i]=bt[i];
int complete=0;
while(complete!=n){
for(int i=n-1;i>=0;i--)
{ if(at[i]<=t && min>=copy[i] && copy[i]!=0 )
{
l=i;
min=copy[i];
c=1;
}

}
if(c==0)
  {
t++;
continue;
}

copy[l]--;
min=copy[l];

if(min==0)
   min=INT_MAX;

if(copy[l]==0)

{
complete++;
c=0;

ct[l]=t+1;
tat[l]=ct[l]-at[l];
wt[l]=tat[l]-bt[l];
}
t++;
}


twt=0;
ttat=0;
for( i=0;i<n;i++)
{

 twt=twt+wt[i];
 ttat=ttat+tat[i];

}
 cout<<ttat<<'\t'<<twt<<'\n';
avwt=(float)twt/(float)n;
avtat=(float)ttat/(float)n;


  }

void output()
{  for(int i=0;i<n;i++)
cout<<at[i]<<'\t'<<bt[i]<<'\t'<<ct[i]<<'\t'<<tat[i]<<'\t'<<wt[i]<<'\n';
cout<<"average WT = "<<avwt<<'\n'<<"average TAT = "<<avtat;
}