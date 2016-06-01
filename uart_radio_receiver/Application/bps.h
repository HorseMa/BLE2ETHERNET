#ifndef _BPS_H_
#define _BPS_H_

#define LED_1 21
#define LED_2 22
#define RX_PIN_NUMBER  11
#define TX_PIN_NUMBER  9
#define CTS_PIN_NUMBER 10
#define RTS_PIN_NUMBER 8
#define HWFC           false
	
void gipo_init(void);
void led_on(void);
void led_off(void);
void led_toggle(void);

#endif
