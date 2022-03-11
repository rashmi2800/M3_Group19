#include "MyStm32f407xx.h"

/*
 * Defining Push Button 
 */
#define BTN_PRESSED ENABLE
#define BTN_PRESSED_1 DISABLE

/*
 * Declaration of functions
 */
void Init_PushButton(void);
void Init_LedPins(void);
void Lock(void);
void Unlock(void);
void Alarm_activation(void);
void Approach_light(void);

/*
 * definition of delay function
 */
void delay(void)
{
	for ( uint32_t i=0 ; i<500000 ; i++);
}

int main(void)
{	
	Init_PushButton();		// Initialising Push Button
	Init_LedPins(); 		// Initialising LedPins

	while(1)
	{	
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED)
    	{
			Lock();
    	}
    	else if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED_1)
    	{
    	    Unlock();
    	}
		else if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED)
		{
			Alarm_activation();
		}
		else if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED_1)
		{
			Approach_light();
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
	delay();
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,1);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,1);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,1);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,1);
}
/*
 * Defining a function that makes all Leds Off
 */
void Unlock(void)
{
	delay();
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0);
}
/*
 * Defining a function that Make leds On in a clockwise manner
 */

void Alarm_activation(void)
{
	delay();
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,1);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0);
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0);

	delay();
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,1);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0);

	delay();
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,1);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0);

	delay();
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,1);
}
/*
 * Defining a function that Make leds On in a Anticlockwise manner
 */
void Approach_light(void)
{
	delay();
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,1);

	delay();
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,1);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0);

	delay();
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,1);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0);

	delay();
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,1);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14,0);
    GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0);
}