/* Copyright (c) 2014 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

/** @file
*
* @defgroup nrf_dev_radio_rx_example_main main.c
* @{
* @ingroup nrf_dev_radio_rx_example
* @brief Radio Receiver example Application main file.
*
* This file contains the source code for a sample application using the NRF_RADIO peripheral. 
*
*/
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "nrf.h"
#include "radio_config.h"
#include "nrf_gpio.h"
#include "nrf_error.h"
#include "nrf_delay.h"
#include "bps.h"
#include "simple_uart.h"
#include <RTL.h>                      /* RTX kernel functions & defines      */
#include "tasks.h"

static uint32_t                   packet;              /**< Packet to transmit. */


/**@brief Function for initialization oscillators.
 */
void clock_initialization()
{
    /* Start 16 MHz crystal oscillator */
    NRF_CLOCK->EVENTS_HFCLKSTARTED = 0;
    NRF_CLOCK->TASKS_HFCLKSTART    = 1;

    /* Wait for the external oscillator to start up */
    while (NRF_CLOCK->EVENTS_HFCLKSTARTED == 0)
    {
        // Do nothing.
    }

    /* Start low frequency crystal oscillator for app_timer(used by bsp)*/
    NRF_CLOCK->LFCLKSRC            = (CLOCK_LFCLKSRC_SRC_Xtal << CLOCK_LFCLKSRC_SRC_Pos);
    NRF_CLOCK->EVENTS_LFCLKSTARTED = 0;
    NRF_CLOCK->TASKS_LFCLKSTART    = 1;

    while (NRF_CLOCK->EVENTS_LFCLKSTARTED == 0)
    {
        // Do nothing.
    }
}


void tx_packet(void)
{
	packet = 0x01;
	NRF_RADIO->PACKETPTR = (uint32_t)&packet; // Set payload pointer	
	while (NRF_CLOCK->EVENTS_HFCLKSTARTED == 0);/* Wait for the external oscillator to start up */
	app_tx_data();
	nrf_delay_ms(500);
	nrf_gpio_pin_toggle(LED_1);
	
	packet = 0x00;
	NRF_RADIO->PACKETPTR = (uint32_t)&packet; // Set payload pointer	
	while (NRF_CLOCK->EVENTS_HFCLKSTARTED == 0);/* Wait for the external oscillator to start up */
	app_tx_data();
	nrf_delay_ms(500);
	nrf_gpio_pin_toggle(LED_2);
}

/*----------------------------------------------------------------------------
 *        Task 1 'init': Initialize
 *---------------------------------------------------------------------------*/
__task void init (void) {
		t_net_init   = os_tsk_create (net_init,  0); /* start clock task                 */

		os_tsk_delete_self ();               /* stop init task (no longer needed)  */
}

/**
 * @brief Function for application main entry.
 * @return 0. int return type required by ANSI/ISO standard.
 */
int main(void)
{
	  os_sys_init (init);                 /* init and start with task 'INIT'     */
#if 0
    clock_initialization();
    radio_configure();
	gipo_init();
	simple_uart_config(RTS_PIN_NUMBER, TX_PIN_NUMBER, CTS_PIN_NUMBER, RX_PIN_NUMBER, HWFC);

	NRF_RADIO->PACKETPTR = (uint32_t)&packet; // Set payload pointer
    while (true)
    {
		
		if(app_rx_data() == 1)
		{
			if(packet == 1)
			{
				led_on();
				simple_uart_put(packet);
			}
			else
			{
				led_off();
				simple_uart_put(packet);
			}
		}
    }
		#endif
}

/**
 *@}
 **/
