#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int fetch(char *argv,char *num,int a[][10]);
void decode(int ,int ,int ,int ,int [], int, int,int ,int );
void execute(int ,int ,int ,int ,int ,int ,int ,int ,int ,int[]);
void stack_mem(int ,int [],int ,int);
int main(int argc,char *argv[])
{
int x,d[1],y;
int i,in[100][10],aludata[3];
int data[2],flags;
int count=fetch(argv[1],(argv[3]),in);
for(i=0;i<count;i++)
{
if(in[i][0] == 1 || in[i][0] == 5 || (in[i][0] == 2 && in[i][7] == 1))
{
decode(in[i][0],in[i][1],in[i][2],in[i][3],data,0,0,in[i][4],in[i][5]);
execute(data[0],data[1],in[i][0],in[i][1],in[i][2],in[i][3],in[i][4],in[i][5],in[i][6],aludata);
if(in[i][5] == 1)
{
decode(in[i][0],in[i][1],in[i][2],in[i][3],data,1,aludata[2],in[i][4],in[i][5]);
}
printf("\n\nopcode=%d    data1=%d data2=%d aludata=%d count =%d",in[i][0],in[i][1],in[i][2],in[i][3],in[i][4],in[i][5],in[i][6],in[i][7],in[i][8],in[i][9],aludata[0],aludata[1],aludata[2],i);
printf("\n\n");

if(in[i][0] == 5)
{
flags = aludata[2];
}
}

else if(in[i][0] == 7 && in[i][1] == 1)
{
if(flags <= 0)
{
i = in[i][8]-1;
}
}

else if(in[i][0] == 6)
{
i = in[i][9]-1;
}

else if(in[i][0] == 4)
{
printf("count=%d\nEnter the value to compute  factorial:",i);
scanf("%d",&x);
stack_mem(2,d,1,x);
}
else if(in[i][0] == 3)
{
stack_mem(1,d,0,x);
printf("The factorial of %d is %d:,count=%d\n ",x,d[0],i);
}
else if(in[i][0] == 9 && in[i][9] == 1)
printf("The string is stored in .LCO,count=%d\n\n",i);
else if(in[i][0] == 9 && in[i][9] == 2)
printf("The string is stored in .LC1,count=%d\n",i);
else if(in[i][0] == 9 && in[i][9] == 3)
printf("The main is declared as type function,count=%d",i);
else if(in[i][0] == 10 && in[i][8] == 8)
printf("The ebp pointer is made pointed to esp,count=%d\n\n",i);
else if(in[i][0] == 10 && in[i][8] == 9)
printf("The space is allocated in the stack,count=%d\n\n",i);
else if(in[i][0] == 8)
printf("The value entered to caluclate factorial is stored in the corresponding address,count=%d\n\n",i);
else if(in[i][0] == 10)
printf("The corresponding actions are done,count=%d\n\n",i);
else 
printf("\n\nNO action is to be done,count=%d \n\n",i);
}

return 0;
}



int fetch(char *argv,char *num,int in[100][10])
{
int nu=atoi(num);
int cnt=0,i,j,power;
char inst[100][32];
char inst1[100][5];
char inst2[100][4];
char inst3[100][4];
char inst4[100][4];
char inst5[100][1];
char inst6[100][2];
char inst7[100][5];
char inst8[100][16];
char inst9[100][21];
char inst10[100][26];
int ins1[100];
int ins2[100];
int ins3[100];
int ins4[100];
int ins5[100];
int ins6[100];
int ins7[100];
int ins8[100];
int ins9[100];
int ins10[100];
printf("cpu\n");
char line[100];
FILE *file;
if((file=fopen(argv,"r") )== NULL)
printf("FIle could not be opened");
cnt=0;
while(fgets(line,100,file) && cnt<nu)
{
printf("%s",line);
for(i=0;i<=31;i++)
inst[cnt][i] = line[i];
++cnt;
}
fclose(file);


for(i=0;i<cnt;i++)
{
power=32;
for(j=0;j<6;j++)
{
inst1[i][j] =inst[i][j];
if(inst1[i][j] == '1')
ins1[i] += power ;
power/=2;
}
printf("\n");
}

for(i=0;i<cnt;i++)
{
power=16;
for(j=0;j<5;j++)
{
inst2[i][j] = inst[i][j+6];
if(inst2[i][j] == '1')
ins2[i] += power;
power/=2;
}
printf("\n");
}


for(i=0;i<cnt;i++)
{
power=16;
for(j=0;j<5;j++)
{
inst3[i][j] = inst[i][j+11];
if(inst3[i][j] == '1')
ins3[i] += power;
power/=2;
}
printf("\n");
}


for(i=0;i<cnt;i++)
{
power=16;
for(j=0;j<5;j++)
{
inst4[i][j] = inst[i][j+16];
if(inst4[i][j] == '1')
ins4[i] += power;
power/=2;
}
printf("\n");
}

for(i=0;i<cnt;i++)
{
power = pow(2,1);
for(j=0;j<2;j++)
{
inst5[i][j] =inst[i][j+21];
if(inst5[i][j] == '1')
ins5[i] += power;
power/=2;
}
printf("\n");
}


for(i=0;i<cnt;i++)
{
power = pow(2,2);
for(j=0;j<3;j++)
{
inst6[i][j] =inst[i][j+23];
if(inst6[i][j] == '1')
ins6[i] += power;
power/=2;
}
printf("\n");
}


for(i=0;i<cnt;i++)
{
power=32;
for(j=0;j<6;j++)
{
inst7[i][j] =inst[i][j+26];
if(inst7[i][j] == '1')
ins7[i] += power ;
power/=2;
}
printf("\n");
}

for(i=0;i<cnt;i++)
{
power=pow(2,14);
for(j=0;j<15;j++)
{
inst8[i][j] =inst[i][j+11];
if(inst8[i][j] == '1')
ins8[i] += power ;
power/=2;
}
printf("\n");
}


for(i=0;i<cnt;i++)
{
power=pow(2,20);
for(j=0;j<21;j++)
{
inst9[i][j] =inst[i][j+11];
if(inst9[i][j] == '1')
ins9[i] += power ;
power/=2;
}
printf("\n");
}

for(i=0;i<cnt;i++)
{
power=pow(2,25);
for(j=0;j<26;j++)
{
inst10[i][j] =inst[i][j+6];
if(inst10[i][j] == '1')
ins10[i] += power ;
power/=2;
}
printf("\n");
}




for(i=0;i<cnt;i++)
{
printf("ins1[%d]=%d\n",i,ins1[i]);
printf("ins2[%d]=%d\n",i,ins2[i]);
printf("ins3[%d]=%d\n",i,ins3[i]);
printf("ins4[%d]=%d\n",i,ins4[i]);
printf("ins5[%d]=%d\n",i,ins5[i]);
printf("ins6[%d]=%d\n",i,ins6[i]);
printf("ins7[%d]=%d\n",i,ins7[i]);
printf("ins8[%d]=%d\n",i,ins8[i]);
printf("ins9[%d]=%d\n",i,ins9[i]);
printf("ins10[%d]=%d\n",i,ins10[i]);
}
j=0;
while(j<cnt)
{
in[j][0]=ins1[j];
in[j][1]=ins2[j];
in[j][2]=ins3[j];
in[j][3]=ins4[j];
in[j][4]=ins5[j];
in[j][5]=ins6[j];
in[j][6]=ins7[j];
in[j][7]=ins8[j];
in[j][8]=ins9[j];
in[j][9]=ins10[j];
++j;
}
return cnt;

}

int regmemory[100];

void decode(int opcode,int reg1,int reg2,int regdest,int da[2],int row,int aludata,int shamt1,int shamt2)
{
static int cnt=0;
int i;
if(cnt == 0)
{
for(i=0;i<100;i++)
{
regmemory[i] = 0;
}
}
if(row == 0 )
{
if((opcode == 1 || opcode == 5) && shamt1==1 && shamt2==1)
{
da[0] = regmemory[reg1];
da[1] = regmemory[reg2];
}
else if((opcode == 1 || opcode == 5) && shamt1==1 && shamt2==2)
{
da[0] = regmemory[reg1];
}
else if((opcode == 1 || opcode == 5) && shamt1==0 && shamt2==1)
{
da[0] = reg1;
da[1] = regmemory[reg2];
}
else if((opcode == 1 || opcode == 5) && shamt1==0 && shamt2==2)
{
da[0] = reg1;
}
else if((opcode == 1 || opcode == 5) && shamt1==2 && shamt2==1)
{
da[1] = regmemory[reg2];
}
else if(opcode == 2)
{
da[0] = regmemory[reg1];
}
}
else if(row == 1)
{
regmemory[regdest] = aludata;
}
else
printf("invalid instruction");
++cnt;
}

int stackmem[100];
void stack_mem(int disp,int da[1],int reowr,int aludat)
{
int i;
static int cnt = 0;
if(cnt == 0)
{
for(i=0;i<100;i++)
stackmem[i] = 0;
}
	if(reowr == 0)
 	{
	da[0]=stackmem[disp];
	}
 if(reowr == 1)
	{
	stackmem[disp] = aludat;	
	}
++cnt;
}



void execute(int data1,int data2,int opc,int reg1,int reg2,int regdes,int sham1,int sham2,int function,int aluda[3])
{
int aludata,d[1],d1[1],d2[1],d3[1];
if((sham1 == 1 || sham1 == 0) && (sham2 == 1 || sham2 == 0))
{
if(opc == 1 || opc == 5)
{
if(function == 32)
{
aludata = data1 + data2;
//printf("%d,%d",data1,data2);
}

if(function == 33)
{
aludata = data1 & data2;
}

if(function == 34)
{
aludata = data2 - data1;
}

if(function == 35)
{
aludata = data1 * data2;
}

if(function == 36)
{
aludata = data1;
}
aluda[0] = data1;
aluda[1] = data2;
}
}
if(opc == 2)
{
printf("The data1 is written into the memory stack");
stack_mem(0,d,1,data1);
aluda[0] =data1;
}

else if(sham1 == 2 && sham2 == 2 && (opc == 1 || opc ==5))
{
stack_mem(reg1,d1,0,0);
stack_mem(reg2,d2,0,0);
if(function == 32)
{
aludata = d1[0] + d2[0];
//printf("%d,%d",data1,data2);
}

if(function == 33)
{
aludata = d1[0] & d2[0];
}

if(function == 34)
{
aludata = d2[0]-d1[0];
}

if(function == 35)
{
aludata = d1[0] * d2[0];
}

if(function == 36)
{
aludata = d1[0];
}
aluda[0] = d1[0];
aluda[1] = d2[0];
stack_mem(reg2,d2,1,aludata);
}



else if(sham1 == 2 && sham2 == 1 && (opc == 1 || opc ==5))
{
stack_mem(reg1,d3,0,0);
if(function == 32)
{
aludata = d3[0] + data2;
//printf("%d,%d",data1,data2);
}

if(function == 33)
{
aludata = d3[0] & data2;
}

if(function == 34)
{
aludata = data2-d3[0];
}

if(function == 35)
{
printf("data=%d",d3[0]);
aludata = d3[0] * data2;
printf("aludat=%d",aludata);
}

if(function == 36)
{
aludata = d3[0];
}
aluda[0] = d3[0];
aluda[1] = data2;
aluda[2] = aludata;
}

else if((sham1 == 1 || sham1 == 0) && (opc == 1 || opc == 5) && sham2 == 2)
{
stack_mem(reg2,d,0,0);
if(function == 32)
{
aludata = data1 + d[0];
//printf("%d,%d",data1,data2);
}

if(function == 33)
{
aludata = data1 & d[0];
}

if(function == 34)
{
aludata = d[0]-data1;
}

if(function == 35)
{
aludata = data1 * d[0];
}

if(function == 36)
{
aludata = data1;
}
aluda[0] = data1;
aluda[1] = d[0];
if(opc == 1)
stack_mem(reg2,d2,1,aludata);

}


aluda[2] = aludata;

}
