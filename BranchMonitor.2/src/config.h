/* Branch Monitor
 * Marcus Botacin
 * 2017
 */

/* Headers included on all files */

#include<fltKernel.h>
#include <dontuse.h>
#include <suppress.h>
#include<intrin.h> /* MSR support */

/* The following configs apply to whole driver */

//#define DEBUG /* define if debug info will be printed */
#define DRIVER_NAME "[BRANCH-MONITOR]" /* define the driver name printed when debugging */
#define DRIVERNAME L"\\Device\\BranchMonitor" /* driver name for windows subsystem */
#define DOSDRIVERNAME L"\\DosDevices\\BranchMonitor" /* driver name for ~DOS~ subsystem */

/* BTS Core -- while muticore is not supported yet */
#define BTS_CORE 3

/* device extension */
#pragma once

/* additional driver data. This struct should be included on DriverObject */
typedef struct _de
{
	/* ISR handler, used to load/unload it */
	PVOID nmicallbackhandler;
	/* DS and BTS O.S. pages, used to alloc/free it */
	PVOID DS_BASE;
	PVOID BTS_BUFFER;
	/* APIC pointer, used to set/unset it */
	UINT32* APIC;
} device_ext,*pdevice_ext;