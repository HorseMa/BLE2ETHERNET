#ifndef __TASK_H__
#define __TASK_H__
#include <RTL.h>                      /* RTX kernel functions & defines      */


extern OS_TID t_net_init;                     /* assigned task id of task: command   */

/*----------------------------------------------------------------------------
 *        Task  'net_init': Initialize
 *---------------------------------------------------------------------------*/
__task void net_init (void);

#endif
