#include <RTL.h>                      /* RTX kernel functions & defines      */
#include "spi_master.h"
#include "device.h"
#include "dhcp.h"
#include "config.h"
#include "sockutil.h"

OS_TID t_net_init;                     /* assigned task id of task: command   */

/*----------------------------------------------------------------------------
 *        Task  'net_init': Initialize
 *---------------------------------------------------------------------------*/
extern void spi_w5500_init(void);

__task void net_init (void) {
	spi_w5500_init();
	Reset_W5500();
  set_default(); 
	GetNetConfig();
	init_dhcp_client();
	while(1)
  {
		
		uint8 dhcpret=0;
    dhcpret = check_DHCP_state(SOCK_DHCP);
    switch(dhcpret)
    {
      case DHCP_RET_NONE:
        break;
      case DHCP_RET_TIMEOUT:
        break;
      case DHCP_RET_UPDATE:
        break;
      case DHCP_RET_CONFLICT:
        while(1);
      default:
        break;
    }
  }
  os_tsk_delete_self ();               /* stop init task (no longer needed)  */
}
