#include<simplecpp>
#include<time.h>
int compmove(Rectangle R[8][8],Circle c[24],int a[12],int b[24]);
int noofkills(Rectangle R[8][8],Circle c[24],int i);
int noofkillsking(Rectangle R[8][8],Circle c[24],int i);
int movecoin(Rectangle R[8][8],int whichcoin,Circle c[24],int b[24],int a[12]);
int tieup(Rectangle R[8][8],Circle c[24],int a[12],int max1,int b[24]);
bool playmoves1(Rectangle R[8][8],Circle c[24],int a[24]);
bool playmoves1f(int initial[2],int j,Rectangle R[8][8],Circle c[24]);
bool playmoves2(Rectangle R[8][8],Circle c[24],int a[24],char name[50]);
bool playmoves2f(int initial[2],int j,Rectangle R[8][8],Circle c[24]);
bool kingmoves2(int initial[2],int j,Rectangle R[8][8],Circle c[24]);
bool checkkingplay2(int j,Circle c[24],int a[24]);
void yesking2(int j,Circle c[24]);
void onemovecoin(Rectangle R[8][8],int whichcoin,Circle c[24],int b[24],int a[12],int max);
bool checkfunc(Rectangle R[8][8],Circle c[24],int a[12],int k,int max,int b[24]);
bool compwin(Circle c[24]);


int playervscomp()
{
    int x=0,res,a[24];
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

        Line lr(720,0,720,720);
        endFrame();

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

    Rectangle r1,r2;
    r1=Rectangle(800,540,120,60);
    r2=Rectangle(800,680,120,60);
    Text t3[2];
    t3[0]=Text (800,680,"Back To Main Menu");
    t3[1]=Text (800,540,"Exit");
        for (int i=0;i<24;i++)
        {
            a[i]=0;
        }

        int b[12];
        for (int i=0;i<12;i++)
        {
            b[i]=0;
        }

        while (true)
        {
            pn:
                res=playmoves2(R,c,a," ");
                if (res==0)
                {
                    goto pn;
                }
                if (res==5)
                break;
                kn:
                res=compmove(R,c,b,a);
               if (res==0)
               {
                   goto kn;
               }
              else if (res==7)
              {
                  break;
              }
        }
        if (res==7)
        {
            t3[0].reset(800,540,"Computer WON");
            t3[1].reset(800,680,"Computer WON");
            wait(10);
            exit(0);
        }

return res;
    }


    int compmove(Rectangle R[8][8],Circle c[24],int a[12],int b[24])
    {

     int max,whichmove,m,res,maybe=0;
     for (int i=0;i<12;i++)
     {
         if (b[i]==1)
         {
             res=noofkillsking(R,c,i);

         }
         else
         {
           res=noofkills(R,c,i);
         }

         if (i==0)
         {
             max=res;
             a[0]=1;
             whichmove=0;
         }
         else if (res>max)
         {
             max=res;
             m=0;
             whichmove=i;

             for (int j=0;j<12;j++)
             {
                 if (i==j)
                    {
                        a[j]=1;
                        continue;
                    }
                 a[j]=0;

             }

         }
         else if (res==max)
         {
             m=1;
             a[i]=1;

         }
     }



     if (m==1)
     {
        whichmove = tieup(R,c,a,max,b);

     }
     if (m==1&&max==0)
     {
         onemovecoin(R,whichmove,c,b,a,max);
     }
     else{

       maybe= movecoin(R,whichmove,c,b,a);
       if (maybe==1)
       {
           return 7;
       }
        return 0;}

return 1;
    }

   int noofkills(Rectangle R[8][8],Circle c[24],int i)
   {

       int ret=0,x,y,rec1x,rec1y,rec2x,rec2y,x1,y1,xc,yc;
       x=c[i].getX();
       y=c[i].getY();

       gn:

       rec1x=x/90;
       rec1y=y/90;


           rec2x=rec1x-2;
           rec2y=rec1y+2;


           if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {
               goto fn;
           }

           xc=R[rec2x][rec2y].getX();
           yc=R[rec2x][rec2y].getY();

           for (int i=0;i<24;i++)
           {
               x=c[i].getX();
               y=c[i].getY();
               if (x==xc&&y==yc)
               {
                   goto fn;
               }

           }


           x1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
           y1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();
           for (int i=12;i<24;i++)
           {
              x=c[i].getX();
              y=c[i].getY();
              if (x==x1&&y==y1)
              {
                  ret++;
                  x=R[rec2x][rec2y].getX();
                  y=R[rec2x][rec2y].getY();
                  goto gn;
              }
           }
           fn:

            rec2x=rec1x+2;
           rec2y=rec1y+2;


           if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {
               goto pn;
           }

            xc=R[rec2x][rec2y].getX();
           yc=R[rec2x][rec2y].getY();

            for (int i=0;i<24;i++)
           {
               x=c[i].getX();
               y=c[i].getY();
               if (x==xc&&y==yc)
               {
                   goto pn;
               }

           }

           x1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
           y1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();
           for (int i=12;i<24;i++)
           {
              x=c[i].getX();
              y=c[i].getY();
              if (x==x1&&y==y1)
              {
                  ret++;
                  x=R[rec2x][rec2y].getX();
                  y=R[rec2x][rec2y].getY();
                  goto gn;
              }
           }

pn:

       return ret;
   }


    int noofkillsking(Rectangle R[8][8],Circle c[24],int i)
    {

        int ret=0,x,y,rec1x,rec1y,rec2x,rec2y,x1,y1,xc,yc,takecare[12];
        for (int j=0;j<12;j++)
        {
            takecare[j]=0;
        }
       x=c[i].getX();
       y=c[i].getY();

       gn:

       rec1x=x/90;
       rec1y=y/90;


           rec2x=rec1x-2;
           rec2y=rec1y+2;

           if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {
               goto fn;
           }

            xc=R[rec2x][rec2y].getX();
           yc=R[rec2x][rec2y].getY();

           for (int i=0;i<24;i++)
           {
               x=c[i].getX();
               y=c[i].getY();
               if (x==xc&&y==yc)
               {
                   goto fn;
               }

           }

           x1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
           y1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();
           for (int i=12;i<24;i++)
           {
               if (takecare[i-12]==1)
                continue;
              x=c[i].getX();
              y=c[i].getY();
              if (x==x1&&y==y1)
              {
                  ret++;
                  takecare[i-12]=1;
                  x=R[rec2x][rec2y].getX();
                  y=R[rec2x][rec2y].getY();
                  goto gn;
              }
           }
       fn:


            rec2x=rec1x+2;
           rec2y=rec1y+2;
           if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {
               goto ln;
           }

           xc=R[rec2x][rec2y].getX();
           yc=R[rec2x][rec2y].getY();

           for (int i=0;i<24;i++)
           {
               x=c[i].getX();
               y=c[i].getY();
               if (x==xc&&y==yc)
               {
                   goto ln;
               }

           }

           x1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
           y1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();
           for (int i=12;i<24;i++)
           {
               if (takecare[i-12]==1)
               {
                   continue;
               }
              x=c[i].getX();
              y=c[i].getY();
              if (x==x1&&y==y1)
              {
                  ret++;
                  takecare[i-12]=1;
                  x=R[rec2x][rec2y].getX();
                  y=R[rec2x][rec2y].getY();
                  goto gn;
              }
           }

ln:



           rec2x=rec1x-2;
           rec2y=rec1y-2;

           if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {
               goto yn;
           }

           xc=R[rec2x][rec2y].getX();
           yc=R[rec2x][rec2y].getY();

           for (int i=0;i<24;i++)
           {
               x=c[i].getX();
               y=c[i].getY();
               if (x==xc&&y==yc)
               {
                   goto yn;
               }

           }


           x1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
           y1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();
           for (int i=12;i<24;i++)
           {
               if (takecare[i-12]==1)
                continue;
              x=c[i].getX();
              y=c[i].getY();
              if (x==x1&&y==y1)
              {
                  ret++;
                  takecare[i-12]=1;
                  x=R[rec2x][rec2y].getX();
                  y=R[rec2x][rec2y].getY();
                  goto gn;
              }
           }
       yn:


            rec2x=rec1x+2;
           rec2y=rec1y-2;

           if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {
               goto rn;
           }

              xc=R[rec2x][rec2y].getX();
           yc=R[rec2x][rec2y].getY();

           for (int i=0;i<24;i++)
           {
               x=c[i].getX();
               y=c[i].getY();
               if (x==xc&&y==yc)
               {
                   goto rn;
               }

           }

           x1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
           y1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();
           for (int i=12;i<24;i++)
           {
               if (takecare[i-12]==1)
                continue;
              x=c[i].getX();
              y=c[i].getY();
              if (x==x1&&y==y1)
              {
                  ret++;
                  takecare[i-12]=1;
                  x=R[rec2x][rec2y].getX();
                  y=R[rec2x][rec2y].getY();
                  goto gn;
              }
           }
       rn:
       return ret;
    }


 int movecoin(Rectangle R[8][8],int whichcoin,Circle c[24],int b[24],int a[12])
 {
     int firstmove=0,x,y,rec1x,rec1y,rec2x,rec2y,x1,y1,k,flag=0,xc,yc,seeifwin;

     if (b[whichcoin]==0)
     {

       x=c[whichcoin].getX();
       y=c[whichcoin].getY();


       rec1x=x/90;
       rec1y=y/90;


           rec2x=rec1x-2;
           rec2y=rec1y+2;
            if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {

               goto tn;
           }

            xc=R[rec2x][rec2y].getX();
           yc=R[rec2x][rec2y].getY();

            for (int i=0;i<24;i++)
           {
               x=c[i].getX();
               y=c[i].getY();
               if (x==xc&&y==yc)
               {
                   goto tn;
               }

           }


           x1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
           y1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();
           for (int i=12;i<24;i++)
           {
              x=c[i].getX();
              y=c[i].getY();
              if (x==x1&&y==y1)
              {
                  k=i;
                  firstmove=1;
                  goto gn;
              }
           }

            tn:

            rec2x=rec1x+2;
           rec2y=rec1y+2;
            if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {
               flag=1;
               goto pn;
           }

            xc=R[rec2x][rec2y].getX();
           yc=R[rec2x][rec2y].getY();

            for (int i=0;i<24;i++)
           {
               x=c[i].getX();
               y=c[i].getY();
               if (x==xc&&y==yc)
               {
                   goto pn;
               }

           }

           x1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
           y1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();
           for (int i=12;i<24;i++)
           {

              x=c[i].getX();
              y=c[i].getY();
              if (x==x1&&y==y1)
              {
                  k=i;

                 firstmove=2;
              }
           }

       gn:

wait(0.3);

       if (firstmove==1)
     {
         c[whichcoin].moveTo(90*rec1x-135,225+90*rec1y);

     }
     else if (firstmove==2)
     {
         c[whichcoin].moveTo(225+90*rec1x,225+90*rec1y);

     }
     c[k].moveTo(1000,1000);
     y=c[whichcoin].getY();
     wait(0.3);

     if (y==675)
    {
        c[whichcoin].setScale(1.2);
       b[whichcoin]=1;
       return -1;
    }

    seeifwin=compwin(c);

     }

     else if (b[whichcoin]==1)
     {
          x=c[whichcoin].getX();
       y=c[whichcoin].getY();



       rec1x=x/90;
       rec1y=y/90;


           rec2x=rec1x-2;
           rec2y=rec1y+2;

           if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {
               flag=1;
               goto pdn;
           }
                      x1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
           y1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();
           for (int i=12;i<24;i++)
           {
              x=c[i].getX();
              y=c[i].getY();
              if (x==x1&&y==y1)
              {
                  k=i;
                  firstmove=1;
                  goto comehere;
              }
           }

pdn:

            rec2x=rec1x+2;
           rec2y=rec1y+2;

           if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {
               flag=1;
               goto pan;
           }
           x1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
           y1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();
           for (int i=12;i<24;i++)
           {
              x=c[i].getX();
              y=c[i].getY();
              if (x==x1&&y==y1)
              {
                  k=i;
                  firstmove=2;
                  goto comehere;
              }
           }


      pan:


           rec2x=rec1x-2;
           rec2y=rec1y-2;
           if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {
               flag=1;
               goto pqn;
           }

           x1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
           y1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();
           for (int i=12;i<24;i++)
           {
              x=c[i].getX();
              y=c[i].getY();
              if (x==x1&&y==y1)
              {
                  k=i;
                  firstmove=3;
                  goto comehere;
              }
           }
       pqn:

            rec2x=rec1x+2;
           rec2y=rec1y-2;

           if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {
               flag=1;

           }

           x1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getX();
           y1=R[(rec2x+rec1x)/2][(rec2y+rec1y)/2].getY();
           for (int i=12;i<24;i++)
           {
              x=c[i].getX();
              y=c[i].getY();
              if (x==x1&&y==y1)
              {
                  k=i;
                  firstmove=4;
                  goto comehere;
              }
           }
       comehere:

       if (firstmove==1)
     {
         c[whichcoin].moveTo(90*rec1x-135,225+90*rec1y);
         c[k].moveTo(2000,2000);
     }
     else if (firstmove==2)
     {
         c[whichcoin].moveTo(225+90*rec1x,225+90*rec1y);
         c[k].moveTo(2000,2000);
     }
     else if (firstmove==3)
     {
         c[whichcoin].moveTo(90*rec1x-135,90*rec1y-135);
         c[k].moveTo(2000,2000);
     }
     else
     {
         c[whichcoin].moveTo(90*rec1x+225,90*rec1y-135);
         c[k].moveTo(2000,2000);
     }
     seeifwin=compwin(c);
     }
     pn:

   return seeifwin;
 }




int tieup(Rectangle R[8][8],Circle c[24],int a[12],int max1,int b[24])
{
        int y,max=0,ret;int m[4],x=-1,check=0;
    for (int i=0;i<12;i++)
    {
       if (a[i]==0)
        continue;
       y=c[i].getY();
       check=checkfunc(R,c,a,i,max1,b);

        if (y==max)
       {
           m[++x]=i;
       }
       if (y>max&&check)
       {
           max=y;
           ret=i;
           x=-1;
           for (int j=0;j<4;j++)
           {
               m[j]=30;
           }

     m[++x]=i;
     if (max1>0)
     goto ghar;
       }


    }
    ghar:

    go:
    canvas::srand(time(0));
    y=rand()%4;
    if ((x)>0)
    {
        ret=m[y];
        if (ret==30)
        {
            goto go;
        }
    }
    return ret;
}

void onemovecoin(Rectangle R[8][8],int whichcoin,Circle c[24],int b[24],int a[12],int max)
{

    int x,y,rec1x,rec1y,rec2x,rec2y,x1,y1,flag=0;
    x=c[whichcoin].getX();
    y=c[whichcoin].getY();
    rec1x=x/90;
    rec1y=y/90;
    rec2y=rec1y+1;
    rec2x=rec1x-1;
    if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
    {
        goto fn;
    }

    x=R[rec2x][rec2y].getX();
    y=R[rec2x][rec2y].getY();

    for (int i=0;i<24;i++)
    {
        x1=c[i].getX();
        y1=c[i].getY();
        if (x==x1&&y==y1)
        {
            flag=1;
            goto fn;
        }
    }
    goto dn;
    fn:
         rec2y=rec1y+1;
    rec2x=rec1x+1;
    if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
    {

        tieup(R,c,a,max,b);
    }

    x=R[rec2x][rec2y].getX();
    y=R[rec2x][rec2y].getY();

    for (int i=0;i<24;i++)
    {
        x1=c[i].getX();
        y1=c[i].getY();
        if (x==x1&&y==y1)
        {
            flag=1;
        }
    }
       dn:

    if (flag==0)
    {wait(0.3);

        c[whichcoin].moveTo(45+90*rec2x,45+90*rec2y);
         y=c[whichcoin].getY();
     wait(0.3);

     if (y==675)
    {
        c[whichcoin].setScale(1.2);
       b[whichcoin]=1;
       return ;
    }
    }
}

bool checkfunc(Rectangle R[8][8],Circle c[24],int a[12],int k,int max,int b[24])
{
        int x,y,xc,yc,rec1x,rec1y,rec2x,rec2y,x1,y1,flag=0;
        if (max==0)
        {
         if (b[k]==0)
         {
              x=c[k].getX();
    y=c[k].getY();
    rec1x=x/90;
    rec1y=y/90;
    rec2y=rec1y+1;
    rec2x=rec1x-1;
    if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
    {
        goto fn;
    }

    x=R[rec2x][rec2y].getX();
    y=R[rec2x][rec2y].getY();

    for (int i=0;i<24;i++)
    {
        x1=c[i].getX();
        y1=c[i].getY();
        if (x==x1&&y==y1)
        {
            flag=1;
            goto fn;
        }
    }
    goto dn;
    fn:
         rec2y=rec1y+1;
    rec2x=rec1x+1;
    if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
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
       dn:



    if (flag==0)
    {
        return 1;

    }
   return 0;
        }

        else if (b[k]==1)
        {

             x=c[k].getX();
    y=c[k].getY();
    rec1x=x/90;
    rec1y=y/90;
    rec2y=rec1y+1;
    rec2x=rec1x-1;
    if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
    {
        goto fgn;
    }

    x=R[rec2x][rec2y].getX();
    y=R[rec2x][rec2y].getY();

    for (int i=0;i<24;i++)
    {
        x1=c[i].getX();
        y1=c[i].getY();
        if (x==x1&&y==y1)
        {
            flag=1;
            goto fgn;
        }
    }
    goto dkn;
    fgn:
         rec2y=rec1y+1;
    rec2x=rec1x+1;
    if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
    {
        flag=1;
        goto dgn;
    }

    x=R[rec2x][rec2y].getX();
    y=R[rec2x][rec2y].getY();

    for (int i=0;i<24;i++)
    {
        x1=c[i].getX();
        y1=c[i].getY();
        if (x==x1&&y==y1)
        {

            flag=1;
            goto dgn;
        }
    }
    goto dkn;
       dgn:






         x=c[k].getX();
    y=c[k].getY();
    rec1x=x/90;
    rec1y=y/90;
    rec2y=rec1y-1;
    rec2x=rec1x-1;
    if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
    {
        goto fkn;
    }

    x=R[rec2x][rec2y].getX();
    y=R[rec2x][rec2y].getY();

    for (int i=0;i<24;i++)
    {
        x1=c[i].getX();
        y1=c[i].getY();
        if (x==x1&&y==y1)
        {
            flag=1;
            goto fkn;
        }
    }
    goto dkn;
    fkn:
         rec2y=rec1y-1;
    rec2x=rec1x-1;
    if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
    {
        flag=1;
    }

    x=R[rec2x][rec2y].getX();
    y=R[rec2x][rec2y].getY();

    for (int i=0;i<24;i++)
    {
        x1=c[i].getX();
        y1=c[i].getY();
        if (x==x1&&y==y1)
        {

            flag=1;
        }
    }
       dkn:



    if (flag==0)
    {
        return 1;

    }
   return 0;
        }
         }



        else
        {
            if (b[k]==0)
            {
                 x=c[k].getX();
       y=c[k].getY();

       gn:

       rec1x=x/90;
       rec1y=y/90;


           rec2x=rec1x-2;
           rec2y=rec1y+2;


           if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {
               ;
               goto on;
           }

           xc=R[rec2x][rec2y].getX();
           yc=R[rec2x][rec2y].getY();

           for (int i=0;i<24;i++)
           {
               x=c[i].getX();
               y=c[i].getY();
               if (x==xc&&y==yc)
               {

                   flag=1;
                 goto on;
               }

           }

goto home;

           on:

            rec2x=rec1x+2;
           rec2y=rec1y+2;


           if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {

               return 0;
           }

            xc=R[rec2x][rec2y].getX();
           yc=R[rec2x][rec2y].getY();

            for (int i=0;i<24;i++)
           {
               x=c[i].getX();
               y=c[i].getY();
               if (x==xc&&y==yc)
               {

                   return 0;
               }

           }
           home:

       if (flag==1)
       {
           return 0;
       }
return 1;

        }
        else if (b[k]==1)
        {
             x=c[k].getX();
       y=c[k].getY();



       rec1x=x/90;
       rec1y=y/90;


           rec2x=rec1x-2;
           rec2y=rec1y+2;


           if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {

               goto on2;
           }

           xc=R[rec2x][rec2y].getX();
           yc=R[rec2x][rec2y].getY();

           for (int i=0;i<24;i++)
           {
               x=c[i].getX();
               y=c[i].getY();
               if (x==xc&&y==yc)
               {

                   flag=1;
                 goto on2;
               }

           }

goto home1;

           on2:

            rec2x=rec1x+2;
           rec2y=rec1y+2;


           if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {

               goto aage;
           }

            xc=R[rec2x][rec2y].getX();
           yc=R[rec2x][rec2y].getY();

            for (int i=0;i<24;i++)
           {
               x=c[i].getX();
               y=c[i].getY();
               if (x==xc&&y==yc)
               {

                   goto aage;
               }

           }
           goto home1;
           aage:





           rec2x=rec1x-2;
           rec2y=rec1y+2;


           if (rec2x<0||rec2x>7||rec2y<0||rec2y>7)
           {

               goto on1;
           }

           xc=R[rec2x][rec2y].getX();
           yc=R[rec2x][rec2y].getY();

           for (int i=0;i<24;i++)
           {
               x=c[i].getX();
               y=c[i].getY();
               if (x==xc&&y==yc)
               {

                   flag=1;
                 goto on1;
               }

           }

goto home1;

           on1:

            rec2x=rec1x+2;
           rec2y=rec1y+2;




            xc=R[rec2x][rec2y].getX();
           yc=R[rec2x][rec2y].getY();

            for (int i=0;i<24;i++)
           {
               x=c[i].getX();
               y=c[i].getY();
               if (x==xc&&y==yc)
               {


               }

           }
           home1:

       if (flag==1)
       {
           return 0;
       }
return 1;


        }
            }


}

bool compwin(Circle c[24])
{
    int x,y;
    for (int i=12;i<24;i++)
    {
     x=c[i].getX();
     if (x<800&&x>0)
     return 0;

    }
    return 1;
}
