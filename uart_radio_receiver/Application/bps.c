#include <stdbool.h>
#include <stdint.h>
#include "nrf_gpio.h"
#include "bps.h"

void gipo_init(void)
{
	nrf_gpio_cfg_output(W5500_CS);
	nrf_gpio_pin_set(W5500_CS);
	nrf_gpio_cfg_output(W5500_RST);
	nrf_gpio_pin_set(W5500_RST);
	nrf_gpio_cfg_output(W5500_CS);
	nrf_gpio_pin_set(W5500_CS);
	nrf_gpio_cfg_output(W5500_RST);
	nrf_gpio_pin_set(W5500_RST);

}

void led_on(void)
{
	//nrf_gpio_pin_clear(LED_1);
}

void led_off(void)
{
	//nrf_gpio_pin_set(LED_1);
}

void led_toggle(void)
{
	//nrf_gpio_pin_toggle(LED_1);
}
