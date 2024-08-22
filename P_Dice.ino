

PROGMEM const byte big[5][3] = {
                 { 0, 1, 0 },
                 { 1, 1, 1 },
                 { 0, 1, 0 },
                 { 1, 0, 1 },
                 { 0, 0, 0 }    
               };

PROGMEM const byte small[5][3] = {
                 { 0, 1, 0 },
                 { 0, 1, 0 },
                 { 1, 1, 1 },
                 { 0, 1, 0 },
                 { 0, 0, 0 }    
               };              


PROGMEM const byte diceOne[12][12] = {
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                
               };

PROGMEM const byte diceTwo[12][12] = {
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},          
               };              

PROGMEM const byte diceThree[12][12] = {
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                
               };   

PROGMEM const byte diceFour[12][12] = {
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0},
                 { 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0},
                 { 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                  
               }; 

PROGMEM const byte diceFive[12][12] = {
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                
               }; 

PROGMEM const byte diceSix[12][12] = {
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},               
               }; 
               


int diceX = 0 ;
int diceY = 0 ;

bool bet_zone = false;

int dicePos = 1 ;
byte dicenum ;
int dice_score = 100 ;
int bet_score = 10 ;

#define MATH_ANIMATION 20






void rundice(){

 
        showDicenumber(1,3,5,1,0,display.color565(0,125,255));
        showDicenumber(2,3,5,5,0,display.color565(0,125,255));
        showDicenumber(3,3,5,9,0,display.color565(0,125,255));
        showDicenumber(4,3,5,13,0,display.color565(0,125,255));
        showDicenumber(5,3,5,17,0,display.color565(0,125,255));
        showDicenumber(6,3,5,21,0,display.color565(0,125,255));
     for(int i = 1; i<7; i++ ) {
         if(dicePos == i)showDicenumber(dicePos,3,5,(dicePos*4)-3,0,display.color565(255,0,0));
     }

  


//顯示大小圖案
 GlobalX = 25;
 GlobalY = 0;
 draw_big_small(big);
 if (dicePos== 7)draw_check_big_small(big);

 GlobalX = 29;
 draw_big_small(small);
 if (dicePos== 8)draw_check_big_small(small);


   //骰子結果
  showDiceBignumber(dicenum,5,8,2,7,display.color565(0,255,255));


  //分數
  show05bitnumber(bet_score,3,5,21,6,display.color565(0,255,0));
  if(bet_zone)show05bitnumber(bet_score,3,5,21,6,display.color565(255,0,0));
  show05bitnumber(dice_score,3,5,13,11,display.color565(0,255,0));



    //上按鍵
   if( BTN_VALUE  == 1 ){
    bet_zone = false;
    
     }

 //下按鍵
  if( BTN_VALUE  == 2 ){

    bet_zone = true;
  
   }

  //右鍵
 if( BTN_VALUE  == 4 ){
 
    display.fillRect(21,6,12,5,display.color565(0,0,0));
   
   if(!bet_zone)dicePos += 1;
   if ( dicePos > 8) dicePos = 8 ;

   if(bet_zone)bet_score+=10;
   if(bet_score>100)bet_score =100;
 }

 
  //左鍵
  if( BTN_VALUE  == 3 ){
      display.fillRect(21,6,12,5,display.color565(0,0,0));
     if(!bet_zone)dicePos -= 1;
     if ( dicePos < 1) dicePos = 1 ;
     if(bet_zone)bet_score-=10;
     if(bet_score<10)bet_score =10;
  }


 //開始鍵
 if( BTN_VALUE  == 5 && dice_score != 0 && dice_score >= bet_score){
       clearall();
       delay(500);
       diceMath();        
       Serial.print(F("抽出點數: "));
       Serial.println(dicenum);
       dice_score = dice_score - bet_score ;  //扣掉押注金額
       D_score(); 
       delay(2000); 
       display.clearDisplay();
    }


if(dice_score<=0)Dice_over();

BTN_VALUE  = 0 ;
  
} //end rundice
   


void showDicenumber(int number, int xlength, int ylength, int x, int y, uint16_t colorxy)
{
  String numStr = String(number);
    showbitmap(bitdata05[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x, y, colorxy);

     }


void showDiceBignumber(int number, int xlength, int ylength, int x, int y, uint16_t colorxy)
{
  String numStr = String(number);
    showbitmap(bitdata10[(int)((String(numStr.charAt(0)).toInt() + 1) - 1)],xlength,ylength, x, y, colorxy);
     }


 //顯示大小圖案 3x5
void draw_big_small(const byte dice[][3]){

   byte x,y;   
  for (x=0;x<5;x++){   
    for (y=0;y<3;y++){
      if (pgm_read_byte_near ( &dice[x][y]) == 1){
         display.drawPixel(y+GlobalX,x+GlobalY,display.color565(0,125,255));
      }            
      else {
         display.drawPixel(y+GlobalX,x+GlobalY,display.color565(0,0,0));
          }
         } 
        }
       }  

void draw_check_big_small(const byte dice[][3]){

   byte x,y;   
  for (x=0;x<5;x++){   
    for (y=0;y<3;y++){
      if (pgm_read_byte_near ( &dice[x][y]) == 1){
         display.drawPixel(y+GlobalX,x+GlobalY,display.color565(255,0,0));
      }            
      else {
         display.drawPixel(y+GlobalX,x+GlobalY,display.color565(0,0,0));
          }
         } 
        }
       }  

         


//顯示 隨機骰子
 void printDice(const byte dice[][12]){

  byte posx = 5 ;
  byte posy = 1 ;
  
  int x,y ;

  display.drawRect(posx-1,posy-1,14,14,display.color565(0,0,255));
  

  for (x=0;x<12;x++){   
    for (y=0;y<12;y++){
      if (pgm_read_byte_near ( &dice[x][y]) == 1){
         display.drawPixel(y+posx,x+posy,display.color565(255,255,255));
      } 
      
     else if (pgm_read_byte_near ( &dice[x][y]) == 2){
         display.drawPixel(y+posx,x+posy,display.color565(255,0,0));
      } 
      
      else {
         display.drawPixel(y+posx,x+posy,display.color565(0,0,0));
      }
    }
  }
}





void diceMath() {
     
       // Clear pixels     
      for(int i=0;i< MATH_ANIMATION;i++) {

         dicenum = random(1, 7);
         
        switch (dicenum) {
        case 1:
          printDice(diceOne);
          break;
        case 2:
          printDice(diceTwo);
          break;
        case 3:
          printDice(diceThree);
          break;
        case 4:
          printDice(diceFour);
          break;
        case 5:
          printDice(diceFive);
          break;
        case 6:
          printDice(diceSix);
          break;
        }
        delay(100);
      }     
   
    }


 void D_score(){

  //算分數
  if (dicenum == dicePos ) dice_score += bet_score*5 ;
  
  
  //算大小x2倍
  if ( dicePos >6 ) {
      if ( dicenum>=4 && dicePos ==7 )dice_score += bet_score*2 ;  //大
      if ( dicenum<=3 && dicePos ==8 )dice_score += bet_score*2 ;  //小
  }
  
  //Serial.print(F("分數: "));
  //Serial.println(dice_score);
  
}
 


void Dice_over(){

   display.clearDisplay();

   display.setCursor(5, 0);
   display.print(F("Game"));
   
   display.setCursor(5, 8);
   display.print(F("Over"));
   delay(5000); 
   display.clearDisplay();
   dice_score = 100 ;
}
       
