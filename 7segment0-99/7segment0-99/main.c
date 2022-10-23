#include <16f877a.h>
#fuses HS,NOWDT
#use delay(clock=20000000)

int i;
int sayi = 0;
int birler,onlar;
const int digit[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x6F};

void main()
{
set_tris_c(0x00);
set_tris_a(0x00);
output_c(0x00);
output_a(0x00);

while(1)
{
   for(i=0;i<100;i++)
   {
      birler = sayi%10;
      onlar = sayi/10;
      output_high(pin_a0);
      output_c(digit[birler]);
      delay_ms(50);
      output_low(pin_a0);
      
      output_high(pin_a1);
      output_c(digit[onlar]);
      delay_ms(50);
      output_low(pin_a1);
      sayi++;
      
      if(sayi == 100)
      {
      sayi = 0;
      }
   }
   
}
}


