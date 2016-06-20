#include <RTL.h>                      /* RTX kernel functions & defines      */

OS_TID t_net_init;                     /* assigned task id of task: command   */

/*----------------------------------------------------------------------------
 *        Task  'net_init': Initialize
 *---------------------------------------------------------------------------*/
__task void net_init (void) {
  os_tsk_delete_self ();               /* stop init task (no longer needed)  */
}
