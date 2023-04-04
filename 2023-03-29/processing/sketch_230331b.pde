import processing.serial.*;
int[] indata =   {0,0,0,0,0,0,0,0,0};
int[] indata_2 = {0,0,0,0,0,0,0,0,0,0,0};

int sum = 0;
int sum2 = 0;
int sum3 = 0;
int sum4 = 0;
int sum5 = 0;
long variable;

Serial port;

void setup()
{
  size(800, 500);
  smooth();
  background(245,245,235);
  
  fill(0,0,0);
  textSize(15);
  text("INPUT LED", 200, 95);
  
  fill(0,0,0);
  textSize(15);
  text("OUTPUT LED", 200, 198);
  

  
  String portName ;
  println(Serial.list()); //Shows your connected serial ports
  //portName = (Serial.list());
  port = new Serial(this,"COM19",115200); 
  port.bufferUntil('\n');  //Shows your connected serial ports //Shows your connected serial ports
}

void calculation(int data, int count)
{
  for(int i=0; i<count; i++)
  {
    indata[i] = data%2;
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
    //print("Data length :  ");
   // println(byte_length);
    
      for(i=0;i<byte_length;i++)
      {
          //print( (in_buff[i]);  // byte의 범위가 -127+256이므로
          //print("   ");
      }
   // println(hex(in_buff[0]));
   // println(in_buff[0]+256);
   // println(in_buff[1]+256);  
     println();

           sum2 = in_buff[0];
           sum3 = in_buff[1];
           sum4 = in_buff[2];
           sum5 = 256*(sum4+1);
           sum5 = sum5 + sum3;
           
           print(sum5);
          
           print(sum5);

           println(); println(); println();    
              
            
        }
    }


void upper_button(int x, int count)
{
    if(indata[count-1] ==1)
  {
   fill(255,0,0);
   ellipse(x+15,240,30,30);
  }
  else
  {
   fill(100,0,0);
   ellipse(x+15,240,30,30);   
  }
  for(int i=0; i<8; i++)
  {
   if(indata[i] >= 2) {indata[i] = 0;}
  }
}


void real_upper_button(int x, int xe, int count)
{
  if(mousePressed && (mouseX>x && mouseX<xe) && (mouseY>110 && mouseY <140))
  {
    indata[count]++;
    //indata_2[count]++; //button 
    if(indata[count] >=2)
    {
      indata[count] =0;
    }
    
    delay(500);
  }
/*else
  {
    indata[count]=0;
  }*/
  
    if(indata[count] == 1)
    {
        fill(255,0,0);
        ellipse(x+15,140,30,30);
    }
  
    else
    {
        fill(100,0,0);
        ellipse(x+15,140,30,30);
    }
}

/*void under_button(int x, int xe, int count)
{  
  if(mousePressed && (mouseX>x && mouseX<xe) && (mouseY>110 && mouseY <140))
  {
    fill(255,0,0);
    ellipse(x+15,140,30,30);
    indata_2[count]++; //button 
    delay(10);
  }
  
  for(int i=0; i<8; i++)
  {
    //fill(100,0,0);
    //ellipse(x+15,140,30,30);  
   if(indata_2[i] >= 2) {indata_2[i] = 0;}
  }
}  

*/
void LED_blink_box()
{
  fill(60,180,0);
  rect(200, 100, 400, 80, 15);
  fill(100,0,0);
  ellipse(225, 140, 30, 30);
  ellipse(275, 140, 30, 30);
  ellipse(325, 140, 30, 30);
  ellipse(375, 140, 30, 30);
  ellipse(425, 140, 30, 30);
  ellipse(475, 140, 30, 30);
  ellipse(525, 140, 30, 30);
  ellipse(575, 140, 30, 30);
}

void toggle_box()
{
  fill(60,180,0);
  rect(200, 200, 400, 80, 15);
  fill(100,0,0);
  ellipse(225, 240, 30, 30);
  ellipse(275, 240, 30, 30);
  ellipse(325, 240, 30, 30);
  ellipse(375, 240, 30, 30);
  ellipse(425, 240, 30, 30);
  ellipse(475, 240, 30, 30);
  ellipse(525, 240, 30, 30);
  ellipse(575, 240, 30, 30);
}

void ADC_Value_Box()
{
  
  fill(245,245,235);
  rect(200, 300, 400, 190, 10);
  
  fill(0,0,0);
  textSize(30);
  text("ADC Data", 210, 330);
  
  fill(0,0,0);
  textSize(30);
  text(sum5, 385, 480);
  
  float a=0;
  float b=300;
  float c=4095;
  fill(100, 0, 0);
  ellipse(395,385,130,130);
  a=sum5;
  fill(255, 0, 0);
  arc(395,385,130,130,radians(120),radians((b*a/c+120)));
  fill(60, 180, 0);
  arc(395,385,100,100,radians(120),radians((b*a/c+120)));
  fill(60, 180, 0);
  ellipse(395,385,100,100);
}



void bit_button()
{
 for(int i=0; i<=7; i++)
    {
        if((sum2 >>i & 1) == 1)  indata[i] = 1;
        else indata[i] = 0;
    }    
}

void draw()
{
  LED_blink_box();
  toggle_box();
  ADC_Value_Box();
  
  bit_button();
  
    /*
    for(int i=0; i<=7; i++)
    {
    if(sum2 >= 128)                        calculation(sum2,8);
    else if(sum2 >= 64 && sum2 < 128)      calculation(sum2,7);
    else if(sum2 >= 32 && sum2 < 64)       calculation(sum2,6);
    else if(sum2 >= 16 && sum2 < 32)       calculation(sum2,5);
    else if(sum2 >= 8  && sum2 < 16)       calculation(sum2,4);
    else if(sum2 >= 4  && sum2 < 8 )       calculation(sum2,3);
    else if(sum2 >= 2  && sum2 < 4 )       calculation(sum2,2);
    else if(sum2 == 1)                     indata[0] = 1;
    }
    */
    
    upper_button(210, 1);
    upper_button(260, 2);
    upper_button(310, 3);
    upper_button(360, 4);
    upper_button(410, 5);
    upper_button(460, 6);
    upper_button(510, 7);
    upper_button(560, 8);
    
    /*for(int i=0; i<=8; i++)
    {
      indata[i] = 0;
    }*/
  //print(sum2);
  /*
   under_button(210, 255, 0);
   under_button(260, 305, 1);
   under_button(310, 355, 2);
   under_button(360, 405, 3);
   under_button(410, 455, 4);
   under_button(460, 505, 5);
   under_button(510, 555, 6);
   under_button(560, 605, 7);
   */
  
   real_upper_button(210, 255, 0);
   real_upper_button(260, 305, 1);
   real_upper_button(310, 355, 2);
   real_upper_button(360, 405, 3);
   real_upper_button(410, 455, 4);
   real_upper_button(460, 505, 5);
   real_upper_button(510, 555, 6);
   real_upper_button(560, 605, 7);
  
  
   if(indata_2[0]==1) sum =   sum+1;
   if(indata_2[1]==1) sum =   sum+2;
   if(indata_2[2]==1) sum =   sum+4;
   if(indata_2[3]==1) sum =   sum+8;
   if(indata_2[4]==1) sum =  sum+16;
   if(indata_2[5]==1) sum =  sum+32; 
   if(indata_2[6]==1) sum =  sum+64;
   if(indata_2[7]==1) sum = sum+128;
    print(indata[0]);
    port.write(sum);
    /*for(int i=0; i<8; i++)
    {
    indata_2[i] = 0;
    }*/
    //sum = 0;
}
