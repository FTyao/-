#include <Adafruit_NeoPixel.h>//引用头文件
#define PIN 6   /*定义了控制LED的引脚，6表示Microduino的D6引脚，可通过Hub转接出来，用户可以更改 */
#define PIN_NUM 2 //定义允许接的led灯的个数

#define voice 400//声音的小的预设值，大于这个声音将被认为是噪音

#define mic_pin A0

int voice_data;


Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIN_NUM, PIN, NEO_GRB + NEO_KHZ800); //该函数第一个参数控制串联灯的个数，第二个是控制用哪个pin脚输出，第三个显示颜色和变化闪烁频率

//该函数第一个参数控制串联灯的个数，第二个是控制用哪个pin脚输出，第三个显示颜色和变化闪烁频率

void setup() //创建无返回值函数
{
  strip.begin();   //准备对灯珠进行数据发送
}
void loop() {

  voice_data = analogRead(mic_pin);//analogRead()函数在引脚设置为输入的情况下，可以获取引脚的电压情况HIGH（高电平）或者LOW第电平
  Serial.println(voice_data);//将数据从Arduino传递到PC，
//且单独占据一行，此数据可在串口监视器中看到
  if (voice_data > voice)
  {
  strip.setPixelColor(0, strip.Color(255, 255, 255));//白光
  strip.show();   //LED显示
  delay(10000);  //延迟10秒输出
  strip.setPixelColor(0, strip.Color(0, 0, 0));//灭
  strip.show();  //LED显示
  delay(1000);  //延迟1秒输出
   }else{
       noTone;
   }
}
