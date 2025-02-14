
//切换模式
   void switchMode(bool change, int mode){
       switch (mode)
        {
          case TIME_MODE:
             showTime(change);
          break;
           
          case DATE_LOOP_MODE:   //時間 日期輪播模式
             showDateLoop(change);
          break;
      
          case WEATHER_MODE:    //時間 天氣  日期 輪播        
            showWeather(change);
          break;
      
          case DRAW_MODE:
             showDrawingBoard(change);
          break;
          
         case GIF_MODE:
              onlyGif();
         break;                          
        }
     }

//切换模式
   void switchGameMode(int mode){
       switch (mode)
        {           
         case Tetris_MODE:   
               
         break;
         
         case BIG_Tetris_MODE:   
           
         break; 
         
         case Snake_MODE:   
              runSnake();  
         break;    

         case Dice_MODE:   
              rundice();   
         break;  
         
         case Bingo_MODE:   
              runBingo(); 
         break;  
         
         case 99:  
          
          //暫停模式
          display.setCursor(2, 4);
          display.print(F("PAUSE"));
          
         break; 
        }
     }

//切换至指定模式
void toTargetMode(int m){
     if(m<MODE_MAX+1 && m>0){
        //int oldMode = Mode;
        Mode = m;
        Serial.print(F("web切换模式："));
        Serial.println(m);
        //modeChange(oldMode, Mode);//模式切换
       }
      }

//切换至指定模式
void toTargetGameMode(int m){
        GameMode = m;
        Serial.print(F("web切换GAME模式："));
        Serial.println(m);

      }



void onlyGif(){

    if ( millis() - GifTime > 15000){ 

          if ( GifRandom == true ){  
             String numStr = String (random(1, 21));     //隨機數量  20 
                   GIFname = numStr + ".gif";
              }
               
            //清除gif區域避免疊到下一個圖
            for (int x = 0; x<24; x++) {
               for (int y = 0; y<16; y++) {
              display.drawPixel(x,y,display.color565(0,0,0));
                 }
                }   
                
            playGif();    
        GifTime = millis();
        }  
  
}
