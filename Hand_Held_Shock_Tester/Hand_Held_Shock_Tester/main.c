/*
 * Hand_Held_Shock_Tester.c
 *
 * Created: 19-02-2020 13:58:15
 * Author : mikke
 */ 
#define F_CPU 16000000UL


//include standard libraries
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "i2cmaster.h"
#include "lcd.h"
#include "usart.h"


#define vref 4.8
#define F_CPU 16000000UL


int main(void)
{
    int roll=0;
float x=0;
float y=0;
float z=0;
double voltage_x=0;
double voltage_y=0;
double voltage_z=0;
    while (1) 
    {
        adc_result=adc_read(0);
voltage_x=(double)(adc_result*(0.005057));
adc_result1=adc_read(1);
voltage_y=(double)(adc_result1*(0.005057));
adc_result2=adc_read(2);
voltage_z=(double)(adc_result2*(0.005057));
x=(voltage_x-1.65)/0.33;
y=(voltage_y-1.65)/0.33;
z=(voltage_z-1.70)/0.33;
int angle_z =atan2(-y,-x)*57.2957795+180;
int angle_x =atan2(-y,-z)*57.2957795+180;
int angle_y =atan2(-x,-z)*57.2957795+180;
 roll =(((atan2(y,z) * 180)/3.14) +180);
LCD_set_cursor(0,0);
printf("X:%.2f|%d",x,angle_x);
LCD_set_cursor(0,1);
printf("Y:%.2f|%d",y,angle_y);
LCD_set_cursor(0,2);
printf("Z:%.2f|%d",z,angle_z);
LCD_set_cursor(0,3);
printf("Roll:%d",roll);
_delay_ms(500);
LCD_clear();
    }
}

