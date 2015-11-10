#include<simplecpp>
#include<time.h>

int playervsplayer();
int  playervscomp();
int howtoplay();
int creditsnow();



int mainmenu()
{

    int mousepos,clicktak[2],choice;
    int algo[5][15][2];
    algo[0]={{13,9},{9,1},{13,7},{10,11},{10,3},{18,77},{22,7},{9,33},{9,33},{6,1},{14,9},{8,3},{12,7},{5,3},{12,99}};
    algo[1]={{12,9},{8,3},{13,9},{8,33},{10,3},{13,7},{6,1},{13,99},{16,9},{3,11},{9,1},{18,77},{14,9},{11,3},{11,11}};
    algo[2]={{10,3},{14,7},{11,3},{14,99},{13,7},{8,3},{13,77},{18,7},{7,11},{7,1},{12,9},{6,3},{22,7},{11,1},{16,9}};
    algo[3]={{14,9},{10,3},{14,77},{13,7},{9,1},{15,7},{9,33},{5,33},{5,3},{15,77},{15,7},{11,3},{15,7},{1,33},{1,3}};
    algo[4]={{9,3},{12,7},{10,3},{13,7},{9,11},{11,3},{16,99},{16,9},{10,1},{16,9},{6,3},{14,9},{11,11},{5,33},{5,3}};

    beginFrame();
    Rectangle r(440,135,150,60);
    Text t(440,135,"CHECKERS");
    t.setScale(4);
    t.setColor(COLOR(50,150,20));
    Rectangle r1[5];
    for (int i=0;i<5;i++)
    {
        r1[i]= Rectangle (680,360 + 70*i,140,60);
    }
    Text t2[5];
    t2[0]=Text (680,360,"Player Vs Player");
    t2[1]=Text (680,430,"Player Vs Computer");
    t2[2]=Text (680,500,"How To Play");
    t2[3]=Text (680,570,"Credits");
    t2[4]=Text (680,640,"Exit");

    Rectangle R[8][8];
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            R[i][j]=Rectangle(200+40*i,300+40*j,40,40);
            R[i][j].setFill(true);
            if ((i+j)%2==0)
                R[i][j].setColor(BLACK);
            else
            {
                R[i][j].setColor(WHITE);
            }
        }
    }
    Line l3[4];
    l3[0]=Line(180,280,500,280);
    l3[1]=Line(500,280,500,600);
    l3[2]=Line(500,600,180,600);
    l3[3]=Line(180,600,180,280);
    endFrame();

     Circle c[24];
     int x=0;
        for (int i=0;i<8;i++)
    {
        for (int j=0;j<4;j++)
        {
          if (i==0)
        {
            c[x]=Circle (200+80*j,300,15);


           c[x].setFill(true);
           c[x++].setColor(COLOR(150,20,100));
        }

   if (i==1)
        {
            c[x]=Circle (240+80*j,340,15);

            c[x].setFill(true);
            c[x++].setColor(COLOR(150,20,100));
        }
        if (i==2)
        {
            c[x]=Circle (200+80*j,380,15);


            c[x].setFill(true);
            c[x++].setColor(COLOR(150,20,100));
        }
        if (i==5)
        {
            c[x]=Circle (240+80*j,500,15);


            c[x].setFill(true);
            c[x++].setColor(COLOR(20,200,30));
        }
        if (i==6)
        {
          c[x]=Circle (200+80*j,540,15);

            c[x].setFill(true);
            c[x++].setColor(COLOR(20,200,30));
        }
        if (i==7)
        {
            c[x]=Circle (240+80*j,580,15);

            c[x].setFill(true);
            c[x++].setColor(COLOR(20,200,30));
        }
        }
    }
    wait(0.8);
int dimag=1,index=0,whichtomove,whattodo,dothis,y,x1,y1,k,i;
     XEvent e;

     canvas::srand(time(0));
     i=rand()%5;

    while (true)
    {
 dimag=1;
 if (index==14)
    dimag=0;

if (checkEvent(e)&&mouseButtonPressEvent(e))
                  {
                      goto hn;
                  }
        if (dimag==1)
        {
            if (checkEvent(e)&&mouseButtonPressEvent(e))
                  {
                      goto hn;
                  }
            whichtomove=algo[i][index][0];
            whattodo=algo[i][index++][1];
            if (whattodo==1)
            {
                if (checkEvent(e)&&mouseButtonPressEvent(e))
                  {
                      goto hn;
                  }
             c[whichtomove].move(-40,40);
            }
            else if (whattodo==3)
            {
                if (checkEvent(e)&&mouseButtonPressEvent(e))
                  {
                      goto hn;
                  }
                c[whichtomove].move(40,40);
            }
            else if (whattodo==7)
            {
                if (checkEvent(e)&&mouseButtonPressEvent(e))
                  {
                      goto hn;
                  }
                c[whichtomove].move(-40,-40);
            }
            else if (whattodo==9)
            {
                if (checkEvent(e)&&mouseButtonPressEvent(e))
                  {
                      goto hn;
                  }
                c[whichtomove].move(40,-40);
            }
            else if (whattodo==11)
            {
                if (checkEvent(e)&&mouseButtonPressEvent(e))
                  {
                      goto hn;
                  }

                x=c[whichtomove].getX()-40;
                y=c[whichtomove].getY()+40;
                c[whichtomove].move(-80,80);
                for (int i=12;i<24;i++)
                {
                    x1=c[i].getX();
                    y1=c[i].getY();
                    if (x==x1&&y==y1)
                    {
                        k=i;
                        break;
                    }

                }
                c[k].hide();
            }
            else if (whattodo==33)
            {
if (checkEvent(e)&&mouseButtonPressEvent(e))
                  {
                      goto hn;
                  }
                x=c[whichtomove].getX()+40;
                y=c[whichtomove].getY()+40;
                c[whichtomove].move(80,80);
                for (int i=12;i<24;i++)
                {
                    x1=c[i].getX();
                    y1=c[i].getY();
                    if (x==x1&&y==y1)
                    {
                        k=i;
                        break;
                    }

                }
                c[k].hide();
            }
            else if (whattodo==77)
            {
if (checkEvent(e)&&mouseButtonPressEvent(e))
                  {
                      goto hn;
                  }
                x=c[whichtomove].getX()-40;
                y=c[whichtomove].getY()-40;
                c[whichtomove].move(-80,-80);
                for (int i=0;i<12;i++)
                {
                    x1=c[i].getX();
                    y1=c[i].getY();
                    if (x==x1&&y==y1)
                    {
                        k=i;
                        break;
                    }

                }
                c[k].hide();
            }
            else if (whattodo==99)
            {
                  if (checkEvent(e)&&mouseButtonPressEvent(e))
                  {
                      goto hn;
                  }

                x=c[whichtomove].getX()+40;
                y=c[whichtomove].getY()-40;
                c[whichtomove].move(80,-80);
                for (int i=0;i<12;i++)
                {
                    x1=c[i].getX();
                    y1=c[i].getY();
                    if (x==x1&&y==y1)
                    {
                        k=i;
                        break;
                    }

                }
                c[k].hide();
            }
        for (int h=0;h<100;h++)
        {
            for (int p=0;p<100;p++)
            {
                for (int g=0;g<1000;g++)
                {
                    if (checkEvent(e)&&mouseButtonPressEvent(e))
                  {
                      goto hn;
                  }
                }
            }
        }
        }


         if (checkEvent(e)&&mouseButtonPressEvent(e))
         {
             hn:
             clicktak[0]=e.xbutton.x;
             clicktak[1]=e.xbutton.y;
              if ((clicktak[0]>635)&&(clicktak[0]<725)&&(clicktak[1]>330)&&clicktak[1]<390)
    {
        return 1;
    }

    if ((clicktak[0]>635)&&(clicktak[0]<725)&&(clicktak[1]>400)&&clicktak[1]<460)
    {
        return 2;
    }
     if ((clicktak[0]>635)&&(clicktak[0]<725)&&(clicktak[1]>470)&&clicktak[1]<530)
    {
        return 3;
    }
     if ((clicktak[0]>635)&&(clicktak[0]<725)&&(clicktak[1]>540)&&clicktak[1]<600)
    {
        return 4;
    }
     if ((clicktak[0]>635)&&(clicktak[0]<725)&&(clicktak[1]>610)&&clicktak[1]<670)
    {
        return 5;
    }

         }


    }


}

void intrfcgm(int a)
{
    int res;
    if (a==1)
    {

        res=playervsplayer();
    }
    if (a==2)
    {
        Text t98(440,360,"Please Wait While Board Is Loading");
      res =playervscomp();
    }
    if (a==3)
    {
res=howtoplay();
    }
    if (a==4)
    {
   res=creditsnow();
    }
    if (a==5)
    {
        exit(0);
    }
    if (res==5)
      {
         intrfcgm(mainmenu());
      }
    return ;
}

int howtoplay()
{
    int pos,x,y;
    Text t[10];
    string printthisshit[10];
    printthisshit[0]= "Click on the coin you want to move ";
    printthisshit[1]={"Once the coin is selected,\0 "};
    printthisshit[2]={"a message containing “Selected”"};
    printthisshit[3]={"will be shown on the right hand side."};
    printthisshit[4]={"Now click on the block you want to move your coin into"};
    printthisshit[5]={" If it is a valid move, then a message containing “Right Move” "};
    printthisshit[6]={"will be shown on the lower right hand side."};
    printthisshit[7]={"Continue playing in the same "};
    printthisshit[8]={"way until a winner is decided"};
    printthisshit[9]={"ENJOY PLAYING :)"};
    for (int i=0;i<9;i++)
    {
        t[i]=Text (440,100+30*i,printthisshit[i]);
    }
    t[9]=Text (440,400,printthisshit[9]);
    Rectangle r(440,500,150,80);
    Text t2(440,500,"Back To Main Menu");
    Rectangle r1(440,580,150,80);
    Text t3(440,580,"Exit");
    pos=getClick();
    x=pos/65536;
    y=pos%65536;
    if ((x>365)&&(x<515)&&(y>460)&&(y<540))
    {
        return 5;
    }
    if ((x>365)&&(x<515)&&(y>540)&&(y<620))
    {
        exit(0);
    }

}


int creditsnow()
{
    Text t[7];int x,y,pos;
    t[0]=Text (440,200,"This Project Is A Result Of Hardwork And Hours Of Programming");
    t[1]=Text (440,230,"Under The Guidance Of Dr. Supratik Chakraborty");
    t[2]=Text (440,260,"And With The Help Of Prashant (T.A.)");
    t[3]=Text (440,290,"Members :");
    t[4]=Text (440,320,"1. Yogesh");
    t[5]=Text (440,350,"2. Shalin");
    t[6]=Text (440,380,"3. Ravi");
    Rectangle r(440,500,150,80);
    Text t2(440,500,"Back To Main Menu");
    Rectangle r1(440,580,150,80);
    Text t3(440,580,"Exit");
    pos=getClick();
    x=pos/65536;
    y=pos%65536;
    if ((x>365)&&(x<515)&&(y>460)&&(y<540))
    {
        return 5;
    }
    if ((x>365)&&(x<515)&&(y>540)&&(y<620))
    {
        exit(0);
    }

}
