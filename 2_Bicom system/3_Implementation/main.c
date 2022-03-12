/**
 * @file main.c
 * @author Vivekanand B S (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "MyStm32f407xx.h"

/*
 * Declaration of functions
 */
void Init_PushButton(void);
void Init_LedPins(void);
void Window_Status(void);
void Alarm_Status(void);
void Battery_Info(void);
void Door_Status(void);
/*
 * definition of delay function
 */
 void delay(uint32_t time) // Provides Require Delay
{
	for (uint32_t i = 0; i < time * 1000000; i++){
	}
}

int main(void)
{	
	Init_PushButton();		// Initialising Push Button
	Init_LedPins(); 		// Initialising LedPins
	while(1)
	{	
		int result;  
		result = Button_Count();
		if(result==1)
    	{
			Window_Status();
			result = 0;
			Button_Count();
    	}
    	else if(result==2)
    	{
    	    Alarm_Status();
			result = 0;
			Button_Count();
    	}
		else if(result==3)
		{
			Battery_Info();
			result = 0;
			Button_Count();
		}
		else if(result==4)
		{
			Door_Status();
			result = 0;
			Button_Count();
		}
	}
}

/*
 * Defining of Pushbutton function
 */
void Init_PushButton(void)
{
	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	GpioLed.pGPIOx = GPIOD;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLed);

    GpioLed.pGPIOx = GPIOD;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLed);

    GpioLed.pGPIOx = GPIOD;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLed);
}
/*
 * Definition of Initialising ledpin function 
 */
void Init_LedPins(void)
{
	GPIO_Handle_t GpioBtn;
	GpioBtn.pGPIOx = GPIOA;
    GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
    GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioBtn.GPIO_PinConfig.GPIO_PinOPType = GPIO_NO_PUPD;
    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_Init(&GpioBtn);
}

/*
 * Defining a function that lights(Ons) all Leds
 */
void Window_Status(void)
{
	Init_PushButton();		// Initialising Push Button
	Init_LedPins(); 		// Initialising LedPins
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,1);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,1);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,1);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,1);
	delay(400);
}
/*
 * Defining a function that makes all Leds Off
 */
void Alarm_Status(void)
{
	Init_PushButton();		// Initialising Push Button
	Init_LedPins(); 		// Initialising LedPins
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0);
	delay(400);
}
/*
 * Defining a function that Make leds On in a clockwise manner
 */

void Battery_Info(void)
{
	Init_PushButton();		// Initialising Push Button
	Init_LedPins(); 		// Initialising LedPins
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,1);
	delay(100);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0);
	delay(100);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,1);
	delay(100);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0);
	delay(100);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,1);
	delay(100);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,0);
	delay(100);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,1);
	delay(100);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0);
	delay(400);
}
/*
 * Defining a function that Make leds On in a Anticlockwise manner
 */
void Door_Status(void)
{
	Init_PushButton();		// Initialising Push Button
	Init_LedPins(); 		// Initialising LedPins
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,1);
	delay(100);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0);
	delay(100);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,1);
	delay(100);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,0);
	delay(100);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,1);
	delay(100);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0);
	delay(100);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,1);
	delay(100);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0);
	delay(400);
}

// Button count function 

int Button_Count(void)    
{
	int count = 0; // button count is initialized to zero
	uint32_t *pGpiodDataReg1 = (uint32_t *)0x40020010; 
	int sec = 10000000; 
	while (sec--)
	{
		if ((*pGpiodDataReg1) & (1 << GPIO_PIN_NO_0)) // Read input from pin number 0 (Push button)
		{ 
			delay(200);
			count++; // inceremnt count
		}
	}
	return count; // Returns no of key presses
}