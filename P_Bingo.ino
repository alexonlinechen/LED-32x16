byte n[25]={};
byte bingo_count = 0 ;
byte bingo_no ;
bool bingo = false;



//主程式
void runBingo(){


display.drawRect(0,0,17,16,display.color565(0,0,255));

 //開始鍵
if( BTN_VALUE  == 5 ){

         if (!bingo){
                  bingo_get();
                  bingo = true;
         }

  
     if (bingo){
         // 再範圍內
         if (bingo_count < 26){

 
             bingo_no = n[bingo_count];//設定隨機取號後的順序           
             Serial.print(F("按鍵次數 ")); 
             Serial.println(bingo_count);
             Serial.print(F("賓果號碼:")); 
             Serial.println(bingo_no);
             bingo_count ++ ;  //放最後+1

             bingoAnimation(); 

             
                            } 

          //超過取號範圍  遊戲結束
          if (bingo_count >= 26){

                     delay(5000);
                     display.clearDisplay();
                     display.setCursor(5, 0);
                     display.print(F("Game"));
   
                     display.setCursor(5, 8);
                     display.print(F("Over"));
   

                                 delay(5000);
                                 Serial.println("遊戲結束"); 
                                 //歸零/初始設定
                                 bingo_count =0;
                                 bingo_no = 0;  
                                 bingo = false;   
                                 clearall();
                                }
                          } 
                   BTN_VALUE  = 0 ;
                }  //end BTN start

  showBingo(); //顯示賓果號碼
  
} //end runBingo




 void bingo_get(){

     //Serial.print("產生隨機順序 不重複 ");

        for(int i=0; i<25; i++){
                       n[i]=random(1, 26);
      
            for (int j = 0; j < i; j++) { 
                       
                   if (n[j] == n[i]){  i--; 
                                       break;
                                    }
                                        } 
                               }                 
                    }//end bingo_get


void showBingo(){

show15bitnumber(bingo_no,6,10,2,3,display.color565(0,125,255));
  
}   //end showbingo


//賓果動畫
void bingoAnimation() {
          
 for(int i=0;i< 20;i++) {
       byte  num = random(1, 20);
       showbitnumber(num,5,8,20,3,display.color565(0,255,0));
       delay(100);     
               }
               
      showbitnumber(bingo_no,5,8,20,3,display.color565(0,255,0));     
      }
