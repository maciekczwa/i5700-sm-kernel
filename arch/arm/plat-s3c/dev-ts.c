/* linux/arch/arm/plat-s3c/dev-ts.c
 *
 * Copyright (c) 2008 Simtec Electronics
 *	Ben Dooks <ben@simtec.co.uk>
 *	http://armlinux.simtec.co.uk/
 *
 * S3C series device definition for hsmmc devices
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#include <linux/kernel.h>
#include <linux/platform_device.h>

#include <mach/map.h>
#include <plat/devs.h>
#include <plat/cpu.h>
#include <plat/adcts.h>
#include <plat/ts.h>

/* Touch srcreen */
struct platform_device s3c_device_ts = {
	.name		  = "s3c-ts",
	.id		  = -1,
};

void __init s3c_ts_set_platdata(struct s3c_ts_mach_info *pd)
{
	struct s3c_ts_mach_info *npd;

	npd = kmalloc(sizeof(*npd), GFP_KERNEL);
	if (npd) {
		memcpy(npd, pd, sizeof(*npd));
		s3c_device_ts.dev.platform_data = npd;
	} else {
		printk(KERN_ERR "no memory for Touchscreen platform data\n");
	}
}


