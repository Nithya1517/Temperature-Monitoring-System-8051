#include <reg51.h>

#define lcd P2

sbit rs = P3^0;
sbit rw = P3^1;
sbit en = P3^2;

void delay()
{
    int i,j;

    for(i=0;i<300;i++)
    for(j=0;j<1275;j++);
}

void lcd_cmd(unsigned char cmd)
{
    lcd = cmd;

    rs = 0;
    rw = 0;
    en = 1;

    delay();

    en = 0;
}

void lcd_data(unsigned char dat)
{
    lcd = dat;

    rs = 1;
    rw = 0;
    en = 1;

    delay();

    en = 0;
}

void lcd_string(char *str)
{
    while(*str)
    {
        lcd_data(*str);
        str++;
    }
}

void lcd_init()
{
    lcd_cmd(0x38);
    lcd_cmd(0x0C);
    lcd_cmd(0x01);
    lcd_cmd(0x80);
}

void main()
{
    lcd_init();

    while(1)
    {
        lcd_cmd(0x80);

        lcd_string("TEMP = 30 C");

        delay();
    }
}