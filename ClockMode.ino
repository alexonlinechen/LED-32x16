

/// ####  時鐘顯示模式   ####

//时钟模式一 HH:mm
void ClockMode1(){        

   if( tempH != H){
   for(int i=-12;i<4;i++){
      display.fillRect(0,0,32,3,display.color565(0,0,0));
      show15bitnumber(H,6,10,2,i,hsv2rgb(hueh, saturation, value)); 
      delay(30);
      tempH = H;    
         }
      }    
      
     show15bitnumber(H,6,10,2,3,hsv2rgb(hueh, saturation, value));  
 

  
  if ( millis() - colonTime > 1000 )
  {
    colon = !colon;
    colonTime = millis();
  }
  showColon(16,6,colon,hsv2rgb(hue, saturation, value));
  
      
 
//時間M   變化/動畫效果
 if( tempM != M){
   for(int i=-12;i<4;i++){
      display.fillRect(0,0,32,3,display.color565(0,0,0));
      show15bitnumber(M,6,10,18,i,hsv2rgb(huem, saturation, value));  
      delay(30);
      tempM = M;
           }
          }
  show15bitnumber(M,6,10,18,3,hsv2rgb(huem, saturation, value));
}




//时钟模式2  漸變HH:mm
void ClockMode2(){        
  
  if ( millis() - colonTime > 1000 )
  {
    colon = !colon;
    colonTime = millis();
  }
  showColon(16,6,colon,hsv2rgb(hue, saturation, value));

  if(randomColor)random_color();
  
    ShowColorNumber(H,6,10,2,3);   //  顯示漸變H
    ShowColorNumber(M,6,10,18,3);  //  顯示漸變M

 
}



//时钟模式3: HH:mm:ss
void ClockMode3(){
  
   if( tempH != H){
   for(int i=-8;i<2;i++){
      display.fillRect(0,0,32,1,display.color565(0,0,0));
      showbitnumber(H,5,8,3,i,hsv2rgb(hueh, saturation, value)); 
      delay(30);
      tempH = H;    
         }
      }    
      
     showbitnumber(H,5,8,3,1,hsv2rgb(hueh, saturation, value));  


  
  if ( millis() - colonTime > 1000 )
  {
    colon = !colon;
    colonTime = millis();
  }
  showColon(16,4,colon,hsv2rgb(hue, saturation, value));
  

 if( tempM != M){
   for(int i=-8;i<2;i++){
      display.fillRect(0,0,32,1,display.color565(0,0,0));
      showbitnumber(M,5,8,19,i,hsv2rgb(huem, saturation, value));  
      delay(30);
      tempM = M;
           }
          }
     showbitnumber(M,5,8,19,1,hsv2rgb(huem, saturation, value));
     show05bitnumber(S,3,5,12,11,hsv2rgb(hues, saturation, value));
}



//时钟模式4:  圖片emoji:時HH:分mm
void ClockMode4(){

  GlobalX = 0;
  GlobalY = 0;
  SetEmojiXY(pic_x, pic_y, 0 ,2);

//時間H   變化/動畫效果
   if( tempH != H){
   for(int i=-8;i<2;i++){
      display.fillRect(0,0,32,1,display.color565(0,0,0));
      showbitnumber(H,5,8,9,i,hsv2rgb(hueh, saturation, value)); 
      delay(30);
      tempH = H;    
         }
      }    
      
     showbitnumber(H,5,8,9,1,hsv2rgb(hueh, saturation, value));  


  
  if ( millis() - colonTime > 1000 )
  {
    colon = !colon;
    colonTime = millis();
  }
  showColon(20,7,colon,hsv2rgb(hue, saturation, value));
  
      
 if( tempM != M){
   for(int i=-8;i<8;i++){
      display.fillRect(21,0,11,7,display.color565(0,0,0));
      showbitnumber(M,5,8,21,i,hsv2rgb(huem, saturation, value));  
      delay(30);
      tempM = M;
           }
          }
     showbitnumber(M,5,8,21,7,hsv2rgb(huem, saturation, value));

}


//时钟模式5: GIF時鐘 + HH:mm
void ClockMode5(){
  
    time(&now);
    localtime_r(&now, &tm);
    H = tm.tm_hour;
    M = tm.tm_min;

//間隔30秒顯示時間
if ( millis() - lastTime > 30000){  

 //清空時鐘顯示區域
    for (int x = 24; x<32; x++) {
       for (int y = 0; y<16; y++) {
              display.drawPixel(x,y,display.color565(0,0,0));
                 }
                 lastTime = millis();
                }  
    
    show05bitnumber(H,3,5,24,2,hsv2rgb(hueh, saturation, value));   
     display.drawPixel(26,8,hsv2rgb(hue, saturation, value));
     display.drawPixel(28,8,hsv2rgb(hue, saturation, value));
    show05bitnumber(M,3,5,24,10,hsv2rgb(huem, saturation, value)); 
       }  



   onlyGif();  //間隔時間 播放gif

     } //end ClockMode5



 //隨機模式
void ClockMode6(){


  switch(randomMode){
      case 1:
            ClockMode1();
      break; 
      case 2:
            ClockMode2();
      break; 
      case 3:     
           ClockMode3();    
      break;
      case 4:
           ClockMode4();
       break;
      case 5:
           ClockMode5();           
      break;                      
      default:
           ClockMode1();
      } 
      
if ( millis() - randomTime > 1800000){    //間隔30分鐘顯示時間

   randomMode = random(1, 6);
   display.clearDisplay();
   randomTime = millis();
 } 
  
}







/// ####  時鐘顯示 功能   ####

//显示时间
void showTime(bool implement)
{
   if ( millis() - ColorTime > 400 | implement)  //控制漸變顏色頻率/秒速
  {
    time(&now);
    localtime_r(&now, &tm);
    H = tm.tm_hour;
    M = tm.tm_min;
    S = tm.tm_sec;
    D = tm.tm_wday;
    

       colorLoop = colorLoop+1;
      if(colorLoop>60) colorLoop = 1;
  ColorTime = millis();
  }  
  
  //時間模式
  switch(clockMode){
      case 1:
            ClockMode1();
      break; 
      case 2:
            ClockMode2();
      break; 
      case 3:     
           ClockMode3();    
      break;
      case 4:
           ClockMode4();
       break;
      case 5:
           ClockMode5();           
      break;  
      case 6:
           ClockMode6();           
      break;        
              
      default:
           ClockMode1();
      }    
    } //end showTime




//显示日期
void showMouthDay() {
 if ( millis() - lastTime > 2000)
  {
    time(&now);
    localtime_r(&now, &tm); 
    currentMonth = tm.tm_mon + 1 ;  //取得月份
    monthDay = tm.tm_mday;          //取得日期
    D = tm.tm_wday;

    lastTime = millis();
    display.clearDisplay();   
   }

  switch(dateMode){
    case 1:
      show15bitnumber(currentMonth,6,10,2,3,hsv2rgb(hueh, saturation, value));
      drawFastYLine(16,5,6,hsv2rgb(hue, saturation, value));
      show15bitnumber(monthDay,6,10,18,3,hsv2rgb(huem, saturation, value)); 
     
      //星期
      showWeek(3,14,huew,3);
      break;
    case 2:

      GlobalX = 0;
      GlobalY = 0;
      SetEmojiXY(pic_x, pic_y, 0, 2);
      showbitnumber(currentMonth,5,8,9,4,hsv2rgb(hueh, saturation, value)); 
      drawFastYLine(21,5,6,hsv2rgb(hue, saturation, value));
      showbitnumber(monthDay,5,8,21,4,hsv2rgb(huem, saturation, value));

      //星期
      showWeek(3,14,huew,3);
      break;
  }


}



//显示 星期  (顯示格子位置代表星期)
void showWeek(int x, int y, int colorhue, int len) {
  for(int i=0;i<7;i++){
    drawFastXLine(x+i*(len+1),y+1,len,hsv2rgb(hue, saturation, value));
   // drawFastXLine(x+i*(len+1),y,len,hsv2rgb(colorhue, saturation, value));
  }
  int d = D;
  if(D == 0){    //星期日 紅色
      d = 7;
      drawFastXLine(x+(d-1)*(len+1),y,len,hsv2rgb(1, saturation, value));  
     }
     
   if(D == 6){    //星期六 綠色
     drawFastXLine(x+(d-1)*(len+1),y,len,hsv2rgb(120, saturation, value));
      }
      
   drawFastXLine(x+(d-1)*(len+1),y,len,hsv2rgb(colorhue, saturation, value));
  
}


//模式2  時間+日期輪播
void showDateLoop(bool implement){ 

    if(millis() - loopTime > 30000 && !implement){
      if(++dateloopMode>2) dateloopMode=1;
      loopTime = millis();
      display.clearDisplay();
    }
    
    switch(dateloopMode){
      case 1:
      showTime(false);
      break;
      case 2:
      showMouthDay();
      break;
                       }
    
}



//显示时钟的冒号方法
void showColon(int x,int y,bool l,uint16_t colorxy){
  String pstr = "101";
  for(int j = y; j < y+3; j = j + (1)){
    if (String(pstr.charAt(j-y)).toInt() != 0) {
      if(l){
        display.drawPixel(x,j,colorxy);
     }else{
       display.drawPixel(x,j,display.color565(0, 0, 0));
     }
    } else {
      display.drawPixel(x,j,display.color565(0, 0, 0));
    }
  }
}
    
