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
void Lock(void);
void Unlock(void);
void Alarm_activation(void);
void Approach_light(void);
int Button_Count(void);
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
		volatile int enc_data = encryption(result);
		if(enc_data==2)
    	{
			Lock();
			result = 0;
			Button_Count();
    	}
    	else if(enc_data==4)
    	{
    	    Unlock();
			result = 0;
			Button_Count();
    	}
		else if(enc_data==6)
		{
			Alarm_activation();
			result = 0;
			Button_Count();
		}
		else if(enc_data==8)
		{
			Approach_light();
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
void Lock(void)
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
void Unlock(void)
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

void Alarm_activation(void)
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
void Approach_light(void)
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