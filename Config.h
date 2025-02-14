#include <Arduino.h>
#include <Adafruit_GFX.h>

#include <ESP8266WiFi.h>
//#include <NTPClient.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>
#include <WiFiUdp.h>
#include <EEPROM.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266HTTPUpdateServer.h>
ESP8266HTTPUpdateServer httpUpdateServer;

#include <LittleFS.h>
#include <SPI.h>

#include <WiFiClient.h>
WiFiClient wifiClient;


// 64*32 顯示器設定 HUB75接口
#include <PxMatrix.h>
#include <Ticker.h>
Ticker display_ticker;
#define P_LAT 16
#define P_A 5
#define P_B 4
#define P_C 15
#define P_D 12
#define P_E 0
#define P_OE 2

#define matrix_width 32
#define matrix_height 16
PxMATRIX display(32,16,P_LAT, P_OE,P_A,P_B,P_C,P_D);




//網路時間相關設定
#include <time.h>  
#define MY_NTP_SERVER "at.pool.ntp.org"   //伺服器        
#define MY_TZ "CST-8"  //時區
time_t now;       
tm tm;  


//設定wifi 連接名稱 參數
struct dataType{
char testssid[32]; 
char testpass[32];
};

String setssid;
String setpwd;

#include "Image.h"   //圖片庫

//#define WIFI_NAME "XMatrix"
#define MDNS_NAME "matrix"
#define xres 32           //設定 繪圖模式 LED 總長
#define yres 16            //                 寬



#define TIME_MODE 1        //時鐘
#define DATE_LOOP_MODE 2   //時鐘+日期
#define WEATHER_MODE 3     //時鐘+日期+天氣
#define DRAW_MODE 4        //繪畫模式
#define GIF_MODE 5       //GIF動畫


#define Tetris_MODE 1    
#define BIG_Tetris_MODE 2 
#define Snake_MODE   3
#define Dice_MODE   4
#define Bingo_MODE   5


//模式數量不能超過9  因為只擷取參數到十位數 EX:11 會變成 1
#define MODE_MAX 8

int BTN_VALUE ;

//int LOOP_MODE_NOW = 0;
unsigned long loopTime = 0;
unsigned long modeLoopTime = 0;
unsigned long colonTime = 0;
unsigned long lastTime = 0;
unsigned long randomTime = 0;

unsigned long last_H_Time = 0;
unsigned long last_M_Time = 0;

unsigned long weatherTime = 0;
unsigned long GifTime = 0;
unsigned long ColorTime = 0;  //漸變顏色時間

unsigned int counter = 0;  //繪圖功能計算


/*******************儲存空間 FS 参数定义*********************************/
const char* fsName = "LittleFS";
FS* fileSystem = &LittleFS;
LittleFSConfig fileSystemConfig = LittleFSConfig();

static bool fsOK;
String unsupportedFiles = String();

File uploadFile;

static const char TEXT_PLAIN[] PROGMEM = "text/plain";
static const char FS_INIT_ERROR[] PROGMEM = "FS INIT ERROR";
static const char FILE_NOT_FOUND[] PROGMEM = "FileNotFound";



/*******************EEPROM定义*********************************/
#define EEPROM_SIZE 256
#define EEPROM_GAIN         0 //确定是否已存有数据
#define EEPROM_MODE         1 //模式
#define EEPROM_COLOR        2 //时钟总颜色（冒号）
#define EEPROM_COLOR_H      3 //时钟小时颜色
#define EEPROM_COLOR_M      4 //时钟分钟颜色
#define EEPROM_COLOR_S      5 //时钟秒钟颜色
#define EEPROM_COLOR_W      6 //星期颜色
#define EEPROM_BRIGHTNESS   7 //亮度
#define EEPROM_PIC_X        8 //图片X轴
#define EEPROM_PIC_Y        9 //图片Y轴
#define EEPROM_CLOCK_MODE   10 //时钟风格
#define EEPROM_DATE_MODE    11 //日期风格
#define EEPROM_LOOP_MODE    12 //切换风格
#define EEPROM_T_TOPscore  13 //俄羅斯方塊最高分
#define EEPROM_S_TOPscore  18  //貪食蛇最高分

#define EEPROM_START_H    14 //時鐘顯示時間H
#define EEPROM_START_M    15 
#define EEPROM_END_H      16 
#define EEPROM_END_M      17 

//#define EEPROM_B_FANS_MODE  13 //粉丝数风格
//#define EEPROM_COLOR_B      14 //粉丝数颜色

#define EEPROM_CONFIRM 10 //判断配置是否已保存，每次变动之后需要更改


uint8_t brightnessNow = 20;   // uint8_t 專門給顯示器用
int Mode = 1; //模式
int GameMode = 0; //遊戲模式
int ModeNow = 3 ;
int hue = 180;//总颜色
int hueh = 180;
int huem = 180;
int hues = 180;
int huew = 180;
int hueb = 180;
int pic_x = 8;
int pic_y = 7;
int clockMode = 1 ;
int randomMode = 1 ;
int dateMode = 1;
int loopMode = 1;
int bFansMode = 2;
int weatherMode = 1;
int dateloopMode = 1;  //日期輪播參數
int colorLoop = 0;
int gifcount = 3 ;

String readssid ;


//遊戲參數
int T_topscore ;
int T_PlayMode = 0 ;
byte gameStatus = 0;  // 遊戲狀態.  0:準備開始中.  1:遊戲中.
int S_topscore ;


//固定顯示 時間開始/結束參數
int start_H = 0;
int start_M = 0;
int end_H = 0;
int end_M = 0;
int end2_H;
int end2_M;

int read_start_H = 0 ;
int read_start_M = 0 ;
int read_end_H = 0 ;
int read_end_M = 0 ;



boolean runonce = true;
boolean randomColor = false;


//2個預設的漸變顏色
int rA = 255;
int gA = 255; 
int bA = 0; 
int rB = 255;
int gB = 0; 
int bB = 81; 




int GlobalX = 0;              // 全局偏移X
int GlobalY = 0;              // 全局偏移Y
//char XMatrix[] = "ALEX ";

String GIFname = "main.gif" ;  //GIF檔名參數
bool GifRandom = false ;

char InputText_str[]="geting" ;  //文字輸入參數

uint8_t saturation = 100;//饱和度
uint8_t value = 100;//明度

bool colon = true;//冒号


int  H;
int  M;
int  S;//秒
int D;//星期几 0为周日

byte tempH;
byte tempM;

int monthDay = 1;
int currentMonth = 1;
String temp_read = "00";
String hum_read = "00";
String tq_code = "00";

String location = "0";
String locationDC = "0";


//***************************定时器配置**************************
int count = 0;

 // 3x5
const char* bitdata05[10]PROGMEM={
  "111101101101111",  //0
  "010010010010010",  //1
  "111001111100111",  //2
  "111001111001111",  //3
  "101101111001001",  //4
  "111100111001111",  //5
  "111100111101111",  //6
  "111001001001001",  //7
  "111101111101111",  //8
  "111101111001001"  //9

};



// 5x8
const char* bitdata10[10]PROGMEM={
  "1111111111110111101111011110111111111111",  //0
  "0011000110001100011000110001100011000110",  //1
  "1111111111000111111111111110001111111111",  //2
  "1111111111000111111111111000111111111111",  //3
  "1101111011110111111111111000110001100011",  //4
  "1111111111110001111111111000111111111111",  //5
  "1111111111110001111111111110111111111111",  //6
  "1111111111000110001100011000110001100011",  //7
  "1111111111110111111111111110111111111111",  //8
  "1111111111110111111111111000111111111111"  //9

};  




//6x10   
const char* bitdata15[10]PROGMEM={
  "111111111111110011110011110011110011110011110011111111111111",  //0
  "001100011100001100001100001100001100001100001100111111111111",  //1
  "111111111111000011000011111111111111110000110000111111111111",  //2
  "111111111111000011000011111111111111000011000011111111111111",  //3
  "110011110011110011110011111111111111000011000011000011000011",  //4
  "111111111111110000110000111111111111000011000011111111111111",  //5
  "111111111111110000110000111111111111110011110011111111111111",  //6
  "111111111111000011000110000110001100001100011000011000110000",  //7
  "111111111111110011110011111111111111110011110011111111111111",  //8
  "111111111111110011110011111111111111000011000011111111111111"  //9

};



// 設定網路相關
ESP8266WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);

HTTPClient http;    //创建HTTPClient 实例
WiFiUDP udp;

//***************************网页配置****************************
char socketMessage[500] = { 'p', '1', '1' };
char settingMessage[500] = {0};


//**********************函数声明************************
void ShowIP();
void InitServer();
void WebServer_run();
uint16_t hsv2rgb(uint16_t hue, uint8_t saturation = 100, uint8_t value = 100);
void drawFastXLine(int16_t x, int16_t y, int16_t h, uint16_t c);
void drawFastYLine(int16_t x, int16_t y, int16_t h, int16_t c);
void configSave();
void DrawPic(const unsigned char pic[], bool BgCover = true, int pic_x = 0, int pic_y = 0, int pic_w = xres, int pic_h = yres);
void SetEmoji(int emoji_x, int emoji_y);
void switchMode(bool change, int mode);
void showWiFiConnectDone(int status, bool clear);
void showbitnumber(int number, int xlength, int ylength, int x, int y, uint16_t colorxy);
void showbitmap(String bitrgbstr, int xlength, int ylength, int x, int y, uint16_t colorxy);
void showColon(int x,int y,bool l,uint16_t colorxy);
void ClockMode1();
void ClockMode2();
void ClockMode3();
void ClockMode4();
void showWeek(int x, int y, int colorhue, int len);
void configSync(uint8_t num);
void showWeatherDay();
void ParseFans(String url);
void weatherNow(String url);
void showWeatherDay(bool implement);
void toTargetMode(int m);
//void nextMode();
void handleSettingMessage();
