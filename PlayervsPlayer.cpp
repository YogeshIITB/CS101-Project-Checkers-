#include<simplecpp>
#include<process.h>
#include<time.h>
int playmoves1(Rectangle R[8][8],Circle c[24],int a[24],char name[50]);
int playmoves1f(int initial[2],int j,Rectangle R[8][8],Circle c[24],char name[50]);
int playmoves2(Rectangle R[8][8],Circle c[24],int a[24],char name[50]);
int playmoves2f(int initial[2],int j,Rectangle R[8][8],Circle c[24],char name[50]);
int kingmoves1(int initial[2],int j,Rectangle R[8][8],Circle c[24],char name[50]);
bool checkkingplay1(int j,Circle c[24],int a[24]);
void yesking1(int j,Circle c[24]);
int kingmoves2(int initial[2],int j,Rectangle R[8][8],Circle c[24],char name[50]);
bool checkkingplay2(int j,Circle c[24],int a[24]);
void yesking2(int j,Circle c[24]);
bool checkwin1(Circle c[24]);
bool checkwin2(Circle c[24]);
int mainmenu();
void intrfcgm(int a);
int playervsplayer();
bool compmove(Circle c[24],int &m,int a[12],int b[24]);
int noofkills(Circle c[24],int i);
int noofkillsking(Circle c[24],int i);
void movecoin(int whichcoin,Circle c[24],int b[24]);
int tieup(Circle c[24],int a[12]);
void playervscomp();




main_program
{
    int x;
    initCanvas("Checker",880,720);
   x= mainmenu();
  intrfcgm(x);
    }






int playervsplayer()
{
    char name[2][50],decode;Circle stick;Circle eye[2];
    Line l2[5];Rectangle r1,r2;
    name[0]={ };
    name[1]={ };
    int l=0,h,x,y,flag,animat[7][4]={{354,350,546,400},{364,325,536,425},{375,300,525,450},{354,400,507,350},{364,425,514,325},{375,450,525,300},{344,375,556,375}};
    Text t(430,100,"Enter The Name Of Player 1  :");
    Text t1(610,100,name[0]);
    Text t98(440,360,"Please Wait While Board Is Loading ....");
    t98.hide();
    Text t9,t7,t23;
    XEvent takename[2];
    for (int j=0;j<2;j++)
    {
        l=0;
        flag=0;

        stick=Circle (450,250,50);
        stick.setFill(false);
        stick.setColor(BLUE);



         l2[0]=Line(450,300,450,450);
         l2[1]=Line(450,450,375,525);
         l2[2]=Line(450,450,525,525);
         l2[3]=Line(450,375,375,300);
         l2[4]=Line(450,375,525,300);
         for(int m=0;m<5;m++)
         {

             l2[m].setColor(BLUE);
         }
         int op=1,dc,x1,y1;

    r1=Rectangle(450,575,150,50);
    r2=Rectangle (450,650,200,80);
    t7=Text(450,630,"Enjoy Playing");
    t23=Text(450,670,"Ignore The Stick Fig :)");
    r1.setFill(false);
    r1.setColor(BLUE);
    r2.setFill(false);
    r2.setColor(BLUE);
    if (j==0)
     t9=Text(450,575,"PLAYER 1");


        if (j==1)
        {
            t.reset(430,100,"Enter The Name Of Player 2 :");
            t1.reset(610,100,name[j]);
            stick.setColor(COLOR(200,0,0));
            for(int m=0;m<5;m++){l2[m].setColor(COLOR(200,0,0));}
            r1.setColor(COLOR(200,0,0));
            r2.setColor(COLOR(200,0,0));
            t9.reset(450,575,"PLAYER 2");

        }
      while (true)
    {
        if (op>100000)
            op=1;
        op=op*2;

            canvas::srand(time(0));
    h=rand()%6 + 1;
    if (h==3)
    {
        stick.reset(425,257,50);
    }
    dc=op%h;
        x=animat[dc][0];
        y=animat[dc][1];
        x1=animat[dc][2];
        y1=animat[dc][3];
        l2[3].reset(450,375,x,y);
        l2[4].reset(450,375,x1,y1);
        wait(0.001);
        stick.reset(450,250,50);

        if (flag==1)
        {
            break;
        }
      if (checkEvent(takename[j])&&keyPressEvent(takename[j]))
      {
        decode=charFromEvent(takename[j]);

        if (decode==13)
        {

            name[j][l]='\0';
            flag=1;


        }
        else if (decode==8)
            {name[j][--l]='\0';
            t1.reset(610,100,name[j]);}
        else
        {
            name[j][l++]=decode;
            name[j][l]='\0';
            t1.reset(610,100,name[j]);
        }
      }
    }
    }
    t98.show();
    t1.reset(1000,1000,"");
            t.reset(1000,1000,"");

            for (int i=0;i<2;i++)
            {
                stick.moveTo(-1000,-1000);
            }
            for (int i=0;i<5;i++)
            {
                l2[i].hide();
            }
            r1.moveTo(-1000,-1000);
            t9.reset(-1000,-1000,"");
            r2.reset(-1000,-1000,0,0);
            t7.reset(-100,-1000," ");
            t23.reset(-100,-1000," ");

     x=0;
     int res,a[24];
       Rectangle R[8][8];


    int i,j;
    beginFrame();
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            R[i][j]=Rectangle((45+90*i),(45+90*j),90,90);
            R[i][j].setFill(true);

            if((i+j)%2==0)
            {
                R[i][j].setColor(BLACK);}
                else{
                R[i][j].setColor(WHITE);}
            }
        }

        Line l3(720,0,720,720);
        endFrame();
        t98.reset(-1000,-1000," ");
        Circle c[24];
        for (int i=0;i<8;i++)
    {
        for (int j=0;j<4;j++)
        {
          if (i==0)
        {
            c[x]=Circle (45+180*j,45,30);


           c[x].setFill(true);
           c[x++].setColor(COLOR(200,0,0));
        }

   if (i==1)
        {
            c[x]=Circle (135+180*j,135,30);

            c[x].setFill(true);
            c[x++].setColor(COLOR(200,0,0));
        }
        if (i==2)
        {
            c[x]=Circle (45+180*j,225,30);


            c[x].setFill(true);
            c[x++].setColor(COLOR(200,0,0));
        }
        if (i==5)
        {
            c[x]=Circle (135+180*j,495,30);


            c[x].setFill(true);
            c[x++].setColor(BLUE);
        }
        if (i==6)
        {
          c[x]=Circle (45+180*j,585,30);

            c[x].setFill(true);
            c[x++].setColor(BLUE);
        }
        if (i==7)
        {
            c[x]=Circle (135+180*j,675,30);

            c[x].setFill(true);
            c[x++].setColor(BLUE);
        }
        }

    }

    Rectangle newrec[5];
    newrec[0]=Rectangle (800,260,120,60);
    newrec[1]=Rectangle (800,120,120,60);
    newrec[2]=Rectangle (800,400,120,60);
    newrec[3]=Rectangle (800,540,120,60);
    newrec[4]=Rectangle (800,680,120,60);

    Text t5(800,200,"Next Move");
    Text t6(800,540,"Exit :(");
    Text t12(800,680,"Back To Main Menu");



     for (int i=0;i<24;i++)
    {
        a[i]=0;
    }

    while (true)
    {
        pl:
        res=playmoves2(R,c,a,name[0]);
        if (res==0)
            {goto pl;}
            else if (res==5)
            {
                break;
            }

        gn:
        res=playmoves1(R,c,a,name[1]);
        if (res==0)

            {goto gn;}
         else if (res==5)
            {
                break;
            }
    }

if (res==5)
    return 5;
return 0;

}

int playmoves1(Rectangle R[8][8],Circle c[24],int a[24],char name[50])
{
    int initial[2],flag=0,x,y,j,res;



    Text t2(800,260,name);
    wait(1);
    x=getClick();
    initial[0]=x/65536;
    initial[1]=x%65536;

    if ((initial[0]>740)&&(initial[0]<860)&&(initial[1]>510)&&(initial[1]<570))
        {exit(0);}

        if ((initial[0]>740)&&(initial[0]<860)&&(initial[1]>650)&&(initial[1]<710))
        {return 5;}


     for (int i=0;i<12;i++)
    {
        x=c[i].getX();
        y=c[i].getY();
        if ((initial[0]>x-45)&&(initial[0]<x+45)&&(initial[1]>y-45)&&(initial[1]<y+45))
        {
            j=i;
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        Text t(800,120,"Invalid");
        wait(0.8);
        return 0;
    }
    Text t1(800,120,"Selected");
    wait(0.1);



    if (a[j]==1)
    {
        Text t1(800,120,"King Selected");
        res=kingmoves1(initial,j,R,c,name);
    }
    else {

        res=playmoves1f(initial,j,R,c,name);
        checkkingplay1(j,c,a);
        }


    if (res==0)
        {
            Text t7(800,120,"Select Again");
            return 0;}
    if (res==5)
    {
        return 5;
    }
        return 1;


}

int playmoves1f(int initial[2],int j,Rectangle R[8][8],Circle c[24],char name[50])
{
    int final[2],x,y,rec1x,rec1y,rec2x,rec2y,flag1=0,flag2=0,flag3=0,x1,y1,xc,yc,k,win;char chalaki[55];
    x=getClick();
    final[0]=x/65536;
    final[1]=x%65536;
      if ((final[0]>740)&&(final[0]<860)&&(final[1]>510)&&(final[1]<570))
        {exit(0);}
        else if ((final[0]>740)&&(final[0]<860)&&(final[1]>650)&&(final[1]<710))
        {exit(0);}
    x=c[j].getX();
    y=c[j].getY();
    rec1x=x/90;
    rec1y=y/90;
    rec2x=final[0]/90;
    rec2y=final[1]/90;
    if((rec2y-rec1y)==1)
    {
      flag1=1;
    if((rec2x-rec1x)==1)
        {flag2=1;}
    if((rec2x-rec1x)==-1)
        {flag3=1;}
    if((flag2==0&&flag3==0))
       {

        return 0;}


       x= R[rec2x][rec2y].getX();
       y= R[rec2x][rec2y].getY();
       for (int i=0;i<24;i++)
       {
           x1=c[i].getX();
           y1=c[i].getY();
           if ((x==x1)&&(y==y1))
            return 0;
       }
       Text t7(800,400,"Right Move");
       wait(0.8);
   c[j].moveTo(45+rec2x*90,45+rec2y*90);
    }

    if (rec2y-rec1y==2)
    {
        if (rec2x-rec1x==2)
            flag2=1;
        if (rec2x-rec1x==-2)
            flag3=1;
        if (flag2==0&&flag3==0)
            return 0;

        xc=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
        yc=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();

        for (int i=12;i<24;i++)
        {
            x1=c[i].getX();
            y1=c[i].getY();
            if (xc==x1&&yc==y1)
            {
                flag1=1;
                k=i;
                break;
            }

        }
         x=R[rec2x][rec2y].getX();
        y=R[rec2x][rec2y].getY();
        for (int i=0;i<24;i++)
        {
            x1=c[i].getX();
            y1=c[i].getY();
            if (x1==x&&y1==y)
            {
                return 0;
            }
        }
       Text t6(800,400,"Fine");
       wait(0.8);

       if (flag1==0)
    {
        return 0;
    }


       c[j].moveTo(45+rec2x*90,45+rec2y*90);
       c[k].moveTo(1000,1000);

        win = checkwin1(c);
          if (win==1)
          {
              for (int i=0;i<50;i++)
              {
                  if (name[i]=='\0')
                  {
                      chalaki[i]=' ';
                      chalaki[++i]='W';
                      chalaki[++i]='O';
                      chalaki[++i]='N';
                      chalaki[++i]='\0';
                      break;
                  }
                  else
                  {
                      chalaki[i]=name[i];
                  }
              }
              Text t12(800,120,chalaki);
              Text t89(800,260,chalaki);
              Text t90(800,400,chalaki);
              wait(10);
              exit(0);
          }

          return 0;
    }
    if (flag1==0)
    {
        return 0;
    }

return 1;
}

int kingmoves1(int initial[2],int j,Rectangle R[8][8],Circle c[24],char name[50])
{
     int final[2],x,y,rec1x,rec1y,rec2x,rec2y,flag1=0,flag2=0,x1,y1,xc,yc,k,win;
     char chalaki[50];
    x=getClick();
    final[0]=x/65536;
    final[1]=x%65536;
      if ((final[0]>740)&&(final[0]<860)&&(final[1]>510)&&(final[1]<570))
        {exit(0);}
        if ((final[0]>740)&&(final[0]<860)&&(final[1]>650)&&(final[1]<710))
        {return 5;}
    x=c[j].getX();
    y=c[j].getY();
    rec1x=x/90;
    rec1y=y/90;
    rec2x=final[0]/90;
    rec2y=final[1]/90;
    if ((rec2y-rec1y)==1||(rec2y-rec1y)==-1)
    {
        flag1=1;
        if ((rec2x-rec1x)==1||(rec2x-rec1x)==-1)
        {flag2=1;}
        if (flag2==0)
        {
            return 0;
        }
        x=R[rec2x][rec2y].getX();
        y=R[rec2x][rec2y].getY();
        for (int i=0;i<24;i++)
        {
            x1=c[i].getX();
            y1=c[i].getY();
            if (x==x1&&y==y1)
            {
                return 0;
            }
        }
        Text t5(800,400,"Good");

        c[j].moveTo(45+90*rec2x,45+90*rec2y);

    }
    if ((rec2y-rec1y)==2||(rec2y-rec1y)==-2)
    {
        flag1=1;
        if ((rec2x-rec1x)==2||(rec2x-rec1x)==-2)
        {
            flag2=1;
        }
        if (flag2==0)
        {
            return 0;
        }

        xc=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
        yc=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();
         for (int i=12;i<24;i++)
        {
            x1=c[i].getX();
            y1=c[i].getY();
            if (xc==x1&&yc==y1)
            {
                flag1=1;
                k=i;
                break;
            }

        }
        x=R[rec2x][rec2y].getX();
        y=R[rec2x][rec2y].getY();
        for (int i=0;i<24;i++)
        {
            x1=c[i].getX();
            y1=c[i].getY();
            if (x1==x&&y1==y)
            {
                return 0;
            }
        }

           Text t8(800,400,"Fine");
           wait(1);
           c[j].moveTo(45+90*rec2x,45+rec2y*90);
           c[k].moveTo(1000,-1000);

           win = checkwin1(c);
          if (win==1)
          {
              for (int i=0;i<50;i++)
              {
                  if (name[i]=='\0')
                  {
                      chalaki[i]=' ';
                      chalaki[++i]='W';
                      chalaki[++i]='O';
                      chalaki[++i]='N';
                      chalaki[++i]='\0';
                      break;
                  }
                  else
                  {
                      chalaki[i]=name[i];
                  }
              }
              Text t12(800,120,chalaki);
              Text t89(800,260,chalaki);
              Text t90(800,400,chalaki);
              wait(10);
              exit(0);
          }

          return 0;
    }
     if (flag1==0)
           {
             return 0;
           }

}
bool checkkingplay1(int j,Circle c[24],int a[24])
{
    int x;
    x=c[j].getY();
    if (x==675)
    {
        a[j]=1;

        yesking1(j,c);
        return 1;
    }
    else
    {
        return 0;
    }
}

void yesking1(int j,Circle c[24])
{
    c[j].setScale(1.2);
    return;
}

bool checkwin1(Circle c[24])
{
    int x,flag=0;
    for (int i=12;i<24;i++)
    {
        x=c[i].getX();
        if (x<800)
        {
            flag=1;
            return 0;
        }
    }
    return 1;
}

int playmoves2(Rectangle R[8][8],Circle c[24],int a[24],char name[50])
{
    int initial[2],x,y,j,flag=0,res;
    Text t1(800,260,name);
    wait(1);
    x=getClick();
    initial[0]=x/65536;
    initial[1]=x%65536;
      if ((initial[0]>740)&&(initial[0]<860)&&(initial[1]>510)&&(initial[1]<570))
        {exit(0);}
        if ((initial[0]>740)&&(initial[0]<860)&&(initial[1]>650)&&(initial[1]<710))
        {return 5;}
    for (int i=12;i<24;i++)
    {
        x=c[i].getX();
        y=c[i].getY();
        if ((initial[0]>x-45)&&(initial[0]<x+45)&&(initial[1]>y-45)&&(initial[1]<y+45))
        {
            j=i;
            flag=1;
            break;
        }
    }
    if (flag==0)
        return 0;
        Text t2(800,120,"Selected");
        wait(1);
        if (a[j]==1)
    {
        Text t(800,120,"King Selected");
        res=kingmoves2(initial,j,R,c,name);
    }
    else {

        res=playmoves2f(initial,j,R,c,name);
        checkkingplay2(j,c,a);
        }

        if (res==0)
        {
            Text t(800,120,"Again");
             return 0;
        }
        if (res==5)
        {
            return 5;
        }

        return 1;

}

int playmoves2f(int initial[2],int j,Rectangle R[8][8],Circle c[24],char name[50])
{
    int final[2],x,y,rec1x,rec1y,rec2x,rec2y,flag1=0,flag2=0,flag3=0,x1,y1,xc,yc,k,win;char chalaki[50];

    x=getClick();
    final[0]=x/65536;
    final[1]=x%65536;
    if ((final[0]>740)&&(final[0]<860)&&(final[1]>510)&&(final[1]<570))
        {exit(0);}
        if ((final[0]>740)&&(final[0]<860)&&(final[1]>650)&&(final[1]<710))
        {return 5;}
    x=c[j].getX();
    y=c[j].getY();
    rec1x=x/90;
    rec1y=y/90;
    rec2x=final[0]/90;
    rec2y=final[1]/90;
    if(rec2y-rec1y==-1)
    {
      flag1=1;
    if(rec2x-rec1x==1)
        flag2=1;
    if(rec2x-rec1x==-1)
        flag3=1;
    if(flag2==0&&flag3==0)
        return 0;


       x= R[rec2x][rec2y].getX();
       y= R[rec2x][rec2y].getY();
       for (int i=0;i<24;i++)
       {
           x1=c[i].getX();
           y1=c[i].getY();
           if ((x==x1)&&(y==y1))
            return 0;
       }
       Text t4(800,400,"Right Move");
       wait(1);
   c[j].moveTo(45+rec2x*90,45+rec2y*90);
    }

    if (rec2y-rec1y==-2)
    {
        if (rec2x-rec1x==2)
            flag2=1;
        if (rec2x-rec1x==-2)
            flag3=1;
        if (flag2==0&&flag3==0)
            return 0;

        xc=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
        yc=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();

        for (int i=0;i<12;i++)
        {
            x1=c[i].getX();
            y1=c[i].getY();
            if (xc==x1&&yc==y1)
            {
                flag1=1;
                k=i;
                break;
            }

        }
         x=R[rec2x][rec2y].getX();
        y=R[rec2x][rec2y].getY();
        for (int i=0;i<24;i++)
        {
            x1=c[i].getX();
            y1=c[i].getY();
            if (x1==x&&y1==y)
            {
                return 0;
            }
        }
        if (flag1==0)
            return 0;
            Text t5(800,400,"Right Move");
       wait(1);
       c[j].moveTo(45+rec2x*90,45+rec2y*90);
       c[k].moveTo(1000,-1000);

        win = checkwin2(c);
          if (win==1)
          {
             for (int i=0;i<50;i++)
              {
                  if (name[i]=='\0')
                  {
                      chalaki[i]=' ';
                      chalaki[++i]='W';
                      chalaki[++i]='O';
                      chalaki[++i]='N';
                      chalaki[++i]='\0';
                      break;
                  }
                  else
                  {
                      chalaki[i]=name[i];
                  }
              }
              Text t12(800,120,chalaki);
              Text t89(800,260,chalaki);
              Text t90(800,400,chalaki);
              wait(10);
              exit(0);
          }

     return 0;
    }

      if (flag1==0)
    {
        return 0;
    }
    return 1;
}

int kingmoves2(int initial[2],int j,Rectangle R[8][8],Circle c[24],char name[50])
{
     int final[2],x,y,rec1x,rec1y,rec2x,rec2y,flag1=0,flag2=0,flag3=0,x1,y1,xc,yc,k,win;
     char chalaki[50];
    x=getClick();
    final[0]=x/65536;
    final[1]=x%65536;
    if ((final[0]>740)&&(final[0]<860)&&(final[1]>510)&&(final[1]<570))
        {exit(0);}
        if ((final[0]>740)&&(final[0]<860)&&(final[1]>650)&&(final[1]<710))
        {return 5;}
    x=c[j].getX();
    y=c[j].getY();
    rec1x=x/90;
    rec1y=y/90;
    rec2x=final[0]/90;
    rec2y=final[1]/90;
    if ((rec2y-rec1y)==1||(rec2y-rec1y)==-1)
    {
        flag1=1;
        if ((rec2x-rec1x)==1||(rec2x-rec1x)==-1)
        {flag2=1;}
        if (flag2==0)
        {
            return 0;
        }
        x=R[rec2x][rec2y].getX();
        y=R[rec2x][rec2y].getY();
        for (int i=0;i<24;i++)
        {
            x1=c[i].getX();
            y1=c[i].getY();
            if (x==x1&&y==y1)
            {
                return 0;
            }
        }
        Text t5(800,400,"Good");

        c[j].moveTo(45+90*rec2x,45+90*rec2y);

    }
    if ((rec2y-rec1y)==2||(rec2y-rec1y)==-2)
    {
        flag1=1;
        if ((rec2x-rec1x)==2||(rec2x-rec1x)==-2)
        {
            flag2=1;
        }
        if (flag2==0)
        {
            return 0;
        }

        xc=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
        yc=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();
         for (int i=0;i<12;i++)
        {
            x1=c[i].getX();
            y1=c[i].getY();
            if (xc==x1&&yc==y1)
            {
                flag1=1;
                k=i;
                break;
            }

        }

        x=R[rec2x][rec2y].getX();
        y=R[rec2x][rec2y].getY();
        for (int i=0;i<24;i++)
        {
            x1=c[i].getX();
            y1=c[i].getY();
            if (x1==x&&y1==y)
            {
                return 0;
            }
        }
        Text t8(800,400,"Fine");
           wait(0.5);
           c[j].moveTo(45+90*rec2x,45+rec2y*90);
           c[k].moveTo(1000,1000);
          win = checkwin2(c);
          if (win==1)
          {
              for (int i=0;i<50;i++)
              {
                  if (name[i]=='\0')
                  {
                      chalaki[i]=' ';
                      chalaki[++i]='W';
                      chalaki[++i]='O';
                      chalaki[++i]='N';
                      chalaki[++i]='\0';
                      break;
                  }
                  else
                  {
                      chalaki[i]=name[i];
                  }
              }
              Text t12(800,120,chalaki);
              Text t89(800,260,chalaki);
              Text t90(800,400,chalaki);
              wait(10);
              exit(0);
          }
     return 0;

    }
     if (flag1==0)
           {
             return 0;
           }

}


bool checkkingplay2(int j,Circle c[24],int a[24])
{
    int x;
    x=c[j].getY();
    if (x==45)
    {
        a[j]=1;
        yesking2(j,c);
        return 1;
    }
    else
    {
        return 0;
    }
}

void yesking2(int j,Circle c[24])
{
    c[j].setScale(1.2);
}


bool checkwin2(Circle c[24])
{
    int x,flag=0;
    for (int i=0;i<12;i++)
    {
        x=c[i].getX();
        if (x<800)
        {
            flag=1;
            return 0;
        }
    }
    return 1;
}







