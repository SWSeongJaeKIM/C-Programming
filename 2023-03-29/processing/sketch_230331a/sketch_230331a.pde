    PFont font;
    PImage img;
    import processing.serial.*;
    int[] push = {0,0,0,0,0,0,0,0,0};
    int[] push_2 = {0,0,0,0,0,0,0,0};
    int[] as = {0,0,0,0,0,0,0,0,0};
    Serial port;  // Create object from Serial class
    int sum = 0;
    int event = 0;
    int sum_2 =0;
    int sum_3 = 0;
    int sum_4 = 0;
    long sum_5 = 0;
    long valu = 0;
    float q=0;
    float b=300;
    float c=4095;
    int sum_sp = 0;
    
    void setup()
    {
        font = createFont("AgencyFB-Reg-48", 30);
      //  img = loadImage("por.png");
      size(1350, 750);     //백그라운드 사이즈 1000*1000
      smooth(); 
      String portName ;
      println(Serial.list());
      port = new Serial(this,"COM19",115200); 
      port.bufferUntil('\n');
      
      
    }
    //////////////////////////////////////////////
     void calculate(int data, int count)
    {
        for(int i = 0;i < count;i++)
        {
            push[i] = data % 2;
            data /= 2;
        }
    }
     
    
    
    
    void serialEvent(Serial port)
    {
     byte[] in_buff = port.readBytesUntil('\n');  // 프로세싱을 사용하려 경우 TC275의 송신 프로토콜에 마지막에 '\n'을 반드시 추가해서 넣을 것
     int byte_length = 0;
      int[] input_io_data = new int[10];
     int i;
     
     if(in_buff != null)
      {
        byte_length = in_buff.length;
       // print("Data length :  ");
       // println(byte_length);
        
          for(i=0;i<byte_length;i++)
          {
             print( in_buff[i]);  // byte의 범위가 -127+256이므로
             print("   ");
          }
             // println(hex(in_buff[0]));
           println();
         
    
               sum_2 = in_buff[0];                                 //버튼 & LED 데이터 수신
               sum_3 = in_buff[1];                                 //ADC값을 수신
               sum_4 = in_buff[2];                                 //ADC값을 수신
               sum_5 = sum_3+((sum_4+1)*256);                          //ADC값을 하나의 변수로 변환
            }
        }
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void check4 (int a, int b, int c, int d, int count)
    {
      
      if (mousePressed && (mouseX > a && mouseX < a+b) && (mouseY > c && mouseY < c+d))
      {
          fill(500);
        rect(a, 150, 90, 50,20);
       // a[count - 1]=push_2[count - 1];
        
        push[count - 1] = 0;
        push_2[count - 1]=0;
        delay(100);
      }
      
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void check2 (int a, int b, int c, int d, int count)
    {
      
      if (mousePressed && (mouseX > a && mouseX < a+b) && (mouseY > c && mouseY < c+d))
      {
          fill(500);
        rect(a, 170, 90, 50,20);
       // a[count - 1]=push_2[count - 1];
        
        push[count - 1]=1;
        push_2[count - 1]=1;
        delay(100);
      }
      
    
     if(push_2[count-1] ==1)
      {
     //   delay(10);
        fill(#2523C1);
        rect(a, 170, 90, 50,20);  //사각형 사이즈
    
    
    //    delay(10);
      }
        else
        {
          //delay(10);
          fill(500);
          rect(a, 170, 90, 50,20);  //사각형 사이즈
              fill(300);
    
       //   delay(10);
        }
         if(push[count-1] ==1)
      {
     //   delay(10);
        fill(#2523C1);
        rect(a, 170, 90, 60,20);  //사각형 사이즈
    
    
    //    delay(10);
      }
        else
        {
          //delay(10);
          fill(500);
          rect(a, 170, 90, 50,20);  //사각형 사이즈
              fill(300);
    
       //   delay(10);
        }
        
        /*
     for (int i =0; i <= 7; i++)
    {
        if (push_2[i] >= 2) push_2[i] = 0;
    
      if (push[i] >= 2) push[i] = 0;
       }
    */
        
    }  
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    //////////////////////////////////////
    
    
    
    void drawingmode()
    {
    
      
      
       fill(#396CF5);      //fill(색깔코드)
      
      rect(100, 170, 90, 50,20);  //사각형 사이즈
      rect(250, 170, 90, 50,20);  //사각형 사이즈
      rect(400, 170, 90, 50,20);  //사각형 사이즈
      rect(550, 170, 90, 50,20);  //사각형 사이즈
      rect(700, 170, 90, 50,20);  //사각형 사이즈
      rect(850, 170, 90, 50,20);  //사각형 사이즈
      rect(1000, 170, 90,50,20);  //사각형 사이즈
      rect(1150, 170, 90, 50,20);  //사각형 사이즈
      
      
      rect(100, 320, 90, 50,20);  //사각형 사이즈
      rect(250, 320, 90, 50,20);  //사각형 사이즈
      rect(400, 320, 90, 50,20);  //사각형 사이즈
      rect(550, 320, 90, 50,20);  //사각형 사이즈
      rect(700, 320, 90, 50,20);  //사각형 사이즈
      rect(850, 320, 90, 50,20);  //사각형 사이즈
      rect(1000, 320, 90, 50,20);  //사각형 사이즈
      rect(1150, 320, 90, 50,20);  //사각형 사이즈
    }
    
    void drawingmode2()
    {
        fill(#DDDDFF);
        rect(80,100,1180,140,20);
        rect(80,250,1180,140,20);
        fill(255);
       rect(80,100,150,50,10);
       fill(0);
       textSize(45);
       text("Output", 85,137);
       
       fill(255);
       rect(80,250,150,50,10);
       fill(0);
       textSize(45);
       text("Input", 85,287);
    }
    
    void drawingmode3()
    {
       fill(#2728E3);
       rect(100,170,50,20,20);
    }
    
    void check (int a, int b, int c, int d, int event) 
    {
      if (mousePressed && (mouseX > a && mouseX < a+b) && (mouseY > c && mouseY < c+d))
      {
        event = 1;
      }
      else
      {
        event = 0;
      }
      
      if(event == 1)
      {
        fill(#ffcc33);
        rect(a, 300, 100, 50);  //사각형 사이즈
      }
       else if(event == 0)
      {
        fill(255);
        rect(a, 300, 100, 50);  //사각형 사이즈
      }
    }
    
    
    
    void draw()
    {
        if(push_2[0]==1) sum = sum + 1;
        if(push_2[1]==1) sum = sum + 2;
        if(push_2[2]==1) sum = sum + 4;
        if(push_2[3]==1) sum = sum + 8;
        if(push_2[4]==1) sum = sum + 16;
        if(push_2[5]==1) sum = sum + 32;
        if(push_2[6]==1) sum = sum + 64;
        if(push_2[7]==1) sum = sum + 128;
          
      sum_sp = sum;
        delay(50);
    
    
      if(sum > sum_sp)
      {
        
        sum = sum_sp;
        port.write(sum);
         sum = 0;
        sum_sp = 0;
      }
      else
      {
        text(sum,200,650);
        port.write(sum);
        sum=0;
       
      }
      
    
       
        delay(100);
        print(sum);
         println(sum);
    
      
      
        background(#46D881);    //백그라운드 색깔 설정  
        fill(#8FCE38);
        rect(40, 80, 1250, 570,60);  //사각형 사이즈
        
        drawingmode3();
        drawingmode2();
        drawingmode();
        textFont(font);
        textSize(40);
        text("adc_data : ",100,450);
        text(sum_5,300,450);
        //text(sum,200,650);
      sum = 0;
        sum_sp = 0;
        fill(0);
        ellipse(1050,530,200,200);
        fill(255);
        arc(1050,530,190,190,radians(120),radians((b*sum_5/c+120)));
        fill(0);
        arc(1050,530,160,160,radians(120),radians((b*sum_5/c+120)));
        fill(0);
        ellipse(1050,530,160,160);
        rect(100, 480, sum_5/8, 40);  //사각형 사이즈
    
       fill(255);
       rect(0, 0, 1350, 40);  //사각형 사이즈
       fill(#FF5A60);
       ellipse(30,20, 20, 20);
       fill(#FFD54B);
       ellipse(60,20, 20, 20);
        fill(#8DC94D);
       ellipse(90,20, 20, 20);
    
    //image(img, 100, 450);
       
        fill(#020302);
        textSize(30);
        text("Mando Track 3rd    KIM S J",950,30);
        
              for (int i = 0; i < 8; i++)
              {
                  if ((sum_2 >> i & 1) == 0x01)
                  { // 8비트를 이용한 2진수 변환
                      push[i] = 1;
                  } else
                  {
                         
                      push[i] = 0;
                  }
              }
                  
        
          /* 
        
        if(sum_2 >= 128)                     calculate(sum_2,8);
        else if(sum_2 >= 64 && sum_2 < 128)   calculate(sum_2,7);
        else if(sum_2 >= 32 && sum_2 < 64)    calculate(sum_2,6);
        else if(sum_2 >= 16 && sum_2 < 32)    calculate(sum_2,5);
        else if(sum_2 >= 8  && sum_2 < 16)    calculate(sum_2,4);
        else if(sum_2 >= 4  && sum_2 < 8 )    calculate(sum_2,3);
        else if(sum_2 >= 2  && sum_2 < 4 )    calculate(sum_2,2);
        else if(sum_2 == 1)                  push[0] = 1;
    */
    
       
       check4(100, 90, 340, 50, 1);
       check4(250, 90, 340, 50, 2);
       check4(400, 90, 340, 50, 3);
       check4(550, 90, 340, 50, 4);
       check4(700, 90, 340, 50, 5);
       check4(850, 90, 340, 50, 6);
       check4(1000, 90, 340, 50, 7);
       check4(1150, 90, 340, 50, 8);
       
       
       
       check2(100, 90, 300, 50, 1);
       check2(250, 90, 300, 50, 2);
       check2(400, 90, 300, 50, 3);
       check2(550, 90, 300, 50, 4);
       check2(700, 90, 300, 50, 5);
       check2(850, 90, 300, 50, 6);
       check2(1000, 90, 300, 50, 7);
       check2(1150, 90, 300, 50, 8);

        
        println("             ");
         println(sum);
            for(int i = 0; i <= 7; i++)
        {
         push[i] = 0; 
        }
    
       
    }
