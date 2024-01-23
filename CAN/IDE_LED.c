/*!
** Copyright 2020 NXP
** @file main.c
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */
#define EVB

#ifdef EVB
	#define PCC_CLOCK	PCC_PORTD_CLOCK
	#define LED_PORT PTD
	#define LED_BLUE   0
	#define LED_RED    15
	#define LED_GREEN  16
#endif

/* LPIT channel used */
#define LPIT_CHANNEL        0UL
#define LPIT_Channel_IRQn   LPIT0_Ch0_IRQn


/* Including necessary configuration files. */
#include "sdk_project_config.h"

volatile int exit_code = 0;
/* User includes */

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
void delay(volatile int cycles)
{
    /* Delay function - do nothing for a number of cycles */
    while(cycles--);
}

void LPIT0_Ch0_IRQHandler(void)
{
	if (LPIT_DRV_GetInterruptFlagTimerChannels(INST_LPIT_CONFIG_1,(1 << LPIT_CHANNEL)))
	{
		/* Clear LPIT channel flag */
		LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT_CONFIG_1, (1 << LPIT_CHANNEL));

		/* Toggle LED_XXX */
		//PINS_DRV_TogglePins(LED_PORT, (1 << LED_GREEN));
		PINS_DRV_TogglePins(LED_PORT, (1 << LED_BLUE));
	}
}

int main(void)
{
    /* Write your code here */
	//1.clock setting
	CLOCK_DRV_Init(&clockMan1_InitConfig0);

	//2.GPIO setting
	PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

	// 2.1 timer settibg
	/* Initialize LPIT instance 0
		 *  -   Reset and enable peripheral
		 */
		LPIT_DRV_Init(INST_LPIT_CONFIG_1, &lpit1_InitConfig);
		/* Initialize LPIT channel 0 and configure it as a periodic counter
		 * which is used to generate an interrupt every second.
		 */
		LPIT_DRV_InitChannel(INST_LPIT_CONFIG_1, LPIT_CHANNEL, &lpit1_ChnConfig0);
		//DEV_ASSERT(status == STATUS_SUCCESS);

		/* Install LPIT_ISR as LPIT interrupt handler */
		INT_SYS_InstallHandler(LPIT_Channel_IRQn, &LPIT0_Ch0_IRQHandler, NULL);

		/* Start LPIT0 channel 0 counter */
		LPIT_DRV_StartTimerChannels(INST_LPIT_CONFIG_1, (1 << LPIT_CHANNEL));


	//3.LED ALL off
		PINS_DRV_SetPins(LED_PORT, 1 << LED_RED);
		  PINS_DRV_SetPins(LED_PORT, 1 << LED_BLUE);
		  PINS_DRV_SetPins(LED_PORT, 1 << LED_GREEN);


    for(;;)
    {
    	//delay(720000);
    	/* Toggle output value LED0 & LED1 */
    	//PINS_DRV_TogglePins(LED0_PORT, 1 << LED0_PIN);
    	//PINS_DRV_TogglePins(LED1_PORT, 1 << LED1_PIN);
        if(exit_code != 0)
        {
            break;
        }
    }
    return exit_code;
}

/* END main */
/*!
** @}
*/
