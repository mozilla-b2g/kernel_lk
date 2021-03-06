/*
 * * Copyright (c) 2011, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of The Linux Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _DEVINFO_H_
#define _DEVINFO_H_

typedef struct device_info device_info;

#define DEVICE_MAGIC "ANDROID-BOOT!"
#define DEVICE_MAGIC_SIZE 13

#define DEVICE_MEM_AUTO	  0
#define DEVICE_MEM_MIN	  256
#define DEVICE_MEM_MAX    1024

/* The AUTO value default to the CONFIG_NR_CPUS value used while configuring
 * the kernel. The MAX value is just a generous value which includes the number
 * of cores of the device. Note that the AUTO value does not do the same as
 * setting the maxcpus to command line argument to 0, as this would disable
 * SMP, and we do not want to do that. */
#define DEVICE_MAXCPUS_AUTO 0
#define DEVICE_MAXCPUS_MIN  1
#define DEVICE_MAXCPUS_MAX  256
 
struct device_info
{
	unsigned char magic[DEVICE_MAGIC_SIZE];
	bool is_unlocked;
	bool is_tampered;
	bool charger_screen_enabled;
	unsigned short mem_capacity;   // ram adjustment by jinzhang@t2mobile.com
	unsigned short maxcpus;
};

#endif
