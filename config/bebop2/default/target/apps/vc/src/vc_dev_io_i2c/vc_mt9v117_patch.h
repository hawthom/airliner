/****************************************************************************
*
*   Copyright (c) 2017 Windhover Labs, L.L.C. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
* 3. Neither the name Windhover Labs nor the names of its
*    contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*****************************************************************************/

#ifndef VC_MT9V117_PATCH_H
#define VC_MT9V117_PATCH_H



/************************************************************************
** Pragmas
*************************************************************************/

/************************************************************************
** Includes
*************************************************************************/
#include "cfe.h"
#include "px4_msgs.h"
#include "px4lib.h"

/************************************************************************
** Local Defines
*************************************************************************/
/**
 * General
 */
#define nullptr ((void*)0)

/**
 * Device A specs
 */
#define DEVICE_NAME_A "MT9V117"
#define DEVICE_I2C_PATH_A "/dev/i2c-mt9v117"
#define DEVICE_PATH_A "/dev/v4l-subdev0"
#define MT9V117_SLAVE_ADDRESS 0x5D

/**
 * Device B specs
 */
#define DEVICE_NAME_B "MT9F002"

/**
 * Patch Defines
 */
#define MT9V117_PATCH_LINE_NUM     13
#define MT9V117_PATCH_SECTION_SIZE 50
#define MAX_LEN_TRANSMIT_BUFFER_IN_BYTES 128
/************************************************************************
 ** Local Structure Definitions
 *************************************************************************/

/**
 * I2C file descriptor
 */
int I2C_FD;

/**
 * MT9V117 patch section structure
 */
struct MT9V117_patch_section {
	const uint8 *data;
	const uint8 size;
};

const static uint8 section1[] = {
	0xf0, 0x00, 0x72, 0xcf, 0xff, 0x00, 0x3e, 0xd0, 0x92, 0x00, 0x71, 0xcf, 0xff, 0xff, 0xf2, 0x18,
	0xb1, 0x10, 0x92, 0x05, 0xb1, 0x11, 0x92, 0x04, 0xb1, 0x12, 0x70, 0xcf, 0xff, 0x00, 0x30, 0xc0,
	0x90, 0x00, 0x7f, 0xe0, 0xb1, 0x13, 0x70, 0xcf, 0xff, 0xff, 0xe7, 0x1c, 0x88, 0x36, 0x09, 0x0f,
	0x00, 0xb3
};

const static uint8 section2[] = {
	0xf0, 0x30, 0x69, 0x13, 0xe1, 0x80, 0xd8, 0x08, 0x20, 0xca, 0x03, 0x22, 0x71, 0xcf, 0xff, 0xff,
	0xe5, 0x68, 0x91, 0x35, 0x22, 0x0a, 0x1f, 0x80, 0xff, 0xff, 0xf2, 0x18, 0x29, 0x05, 0x00, 0x3e,
	0x12, 0x22, 0x11, 0x01, 0x21, 0x04, 0x0f, 0x81, 0x00, 0x00, 0xff, 0xf0, 0x21, 0x8c, 0xf0, 0x10,
	0x1a, 0x22
};

const static uint8 section3[] = {
	0xf0, 0x60, 0x10, 0x44, 0x12, 0x20, 0x11, 0x02, 0xf7, 0x87, 0x22, 0x4f, 0x03, 0x83, 0x1a, 0x20,
	0x10, 0xc4, 0xf0, 0x09, 0xba, 0xae, 0x7b, 0x50, 0x1a, 0x20, 0x10, 0x84, 0x21, 0x45, 0x01, 0xc1,
	0x1a, 0x22, 0x10, 0x44, 0x70, 0xcf, 0xff, 0x00, 0x3e, 0xd0, 0xb0, 0x60, 0xb0, 0x25, 0x7e, 0xe0,
	0x78, 0xe0
};

const static uint8 section4[] = {
	0xf0, 0x90, 0x71, 0xcf, 0xff, 0xff, 0xf2, 0x18, 0x91, 0x12, 0x72, 0xcf, 0xff, 0xff, 0xe7, 0x1c,
	0x8a, 0x57, 0x20, 0x04, 0x0f, 0x80, 0x00, 0x00, 0xff, 0xf0, 0xe2, 0x80, 0x20, 0xc5, 0x01, 0x61,
	0x20, 0xc5, 0x03, 0x22, 0xb1, 0x12, 0x71, 0xcf, 0xff, 0x00, 0x3e, 0xd0, 0xb1, 0x04, 0x7e, 0xe0,
	0x78, 0xe0
};

const static uint8 section5[] = {
	0xf0, 0xc0, 0x70, 0xcf, 0xff, 0xff, 0xe7, 0x1c, 0x88, 0x57, 0x71, 0xcf, 0xff, 0xff, 0xf2, 0x18,
	0x91, 0x13, 0xea, 0x84, 0xb8, 0xa9, 0x78, 0x10, 0xf0, 0x03, 0xb8, 0x89, 0xb8, 0x8c, 0xb1, 0x13,
	0x71, 0xcf, 0xff, 0x00, 0x30, 0xc0, 0xb1, 0x00, 0x7e, 0xe0, 0xc0, 0xf1, 0x09, 0x1e, 0x03, 0xc0,
	0xc1, 0xa1
};

const static uint8 section6[] = {
	0xf0, 0xf0, 0x75, 0x08, 0x76, 0x28, 0x77, 0x48, 0xc2, 0x40, 0xd8, 0x20, 0x71, 0xcf, 0x00, 0x03,
	0x20, 0x67, 0xda, 0x02, 0x08, 0xae, 0x03, 0xa0, 0x73, 0xc9, 0x0e, 0x25, 0x13, 0xc0, 0x0b, 0x5e,
	0x01, 0x60, 0xd8, 0x06, 0xff, 0xbc, 0x0c, 0xce, 0x01, 0x00, 0xd8, 0x00, 0xb8, 0x9e, 0x0e, 0x5a,
	0x03, 0x20
};

const static uint8 section7[] = {
	0xf1, 0x20, 0xd9, 0x01, 0xd8, 0x00, 0xb8, 0x9e, 0x0e, 0xb6, 0x03, 0x20, 0xd9, 0x01, 0x8d, 0x14,
	0x08, 0x17, 0x01, 0x91, 0x8d, 0x16, 0xe8, 0x07, 0x0b, 0x36, 0x01, 0x60, 0xd8, 0x07, 0x0b, 0x52,
	0x01, 0x60, 0xd8, 0x11, 0x8d, 0x14, 0xe0, 0x87, 0xd8, 0x00, 0x20, 0xca, 0x02, 0x62, 0x00, 0xc9,
	0x03, 0xe0
};

const static uint8 section8[] = {
	0xf1, 0x50, 0xc0, 0xa1, 0x78, 0xe0, 0xc0, 0xf1, 0x08, 0xb2, 0x03, 0xc0, 0x76, 0xcf, 0xff, 0xff,
	0xe5, 0x40, 0x75, 0xcf, 0xff, 0xff, 0xe5, 0x68, 0x95, 0x17, 0x96, 0x40, 0x77, 0xcf, 0xff, 0xff,
	0xe5, 0x42, 0x95, 0x38, 0x0a, 0x0d, 0x00, 0x01, 0x97, 0x40, 0x0a, 0x11, 0x00, 0x40, 0x0b, 0x0a,
	0x01, 0x00
};

const static uint8 section9[] = {
	0xf1, 0x80, 0x95, 0x17, 0xb6, 0x00, 0x95, 0x18, 0xb7, 0x00, 0x76, 0xcf, 0xff, 0xff, 0xe5, 0x44,
	0x96, 0x20, 0x95, 0x15, 0x08, 0x13, 0x00, 0x40, 0x0e, 0x1e, 0x01, 0x20, 0xd9, 0x00, 0x95, 0x15,
	0xb6, 0x00, 0xff, 0xa1, 0x75, 0xcf, 0xff, 0xff, 0xe7, 0x1c, 0x77, 0xcf, 0xff, 0xff, 0xe5, 0x46,
	0x97, 0x40
};

const static uint8 section10[] = {
	0xf1, 0xb0, 0x8d, 0x16, 0x76, 0xcf, 0xff, 0xff, 0xe5, 0x48, 0x8d, 0x37, 0x08, 0x0d, 0x00, 0x81,
	0x96, 0x40, 0x09, 0x15, 0x00, 0x80, 0x0f, 0xd6, 0x01, 0x00, 0x8d, 0x16, 0xb7, 0x00, 0x8d, 0x17,
	0xb6, 0x00, 0xff, 0xb0, 0xff, 0xbc, 0x00, 0x41, 0x03, 0xc0, 0xc0, 0xf1, 0x0d, 0x9e, 0x01, 0x00,
	0xe8, 0x04
};

const static uint8 section11[] = {
	0xf1, 0xe0, 0xff, 0x88, 0xf0, 0x0a, 0x0d, 0x6a, 0x01, 0x00, 0x0d, 0x8e, 0x01, 0x00, 0xe8, 0x7e,
	0xff, 0x85, 0x0d, 0x72, 0x01, 0x00, 0xff, 0x8c, 0xff, 0xa7, 0xff, 0xb2, 0xd8, 0x00, 0x73, 0xcf,
	0xff, 0xff, 0xf2, 0x40, 0x23, 0x15, 0x00, 0x01, 0x81, 0x41, 0xe0, 0x02, 0x81, 0x20, 0x08, 0xf7,
	0x81, 0x34
};

const static uint8 section12[] = {
	0xf2, 0x10, 0xa1, 0x40, 0xd8, 0x00, 0xc0, 0xd1, 0x7e, 0xe0, 0x53, 0x51, 0x30, 0x34, 0x20, 0x6f,
	0x6e, 0x5f, 0x73, 0x74, 0x61, 0x72, 0x74, 0x5f, 0x73, 0x74, 0x72, 0x65, 0x61, 0x6d, 0x69, 0x6e,
	0x67, 0x20, 0x25, 0x64, 0x20, 0x25, 0x64, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00
};

const static uint8 section13[] = {
	0xf2, 0x40, 0xff, 0xff, 0xe8, 0x28, 0xff, 0xff, 0xf0, 0xe8, 0xff, 0xff, 0xe8, 0x08, 0xff, 0xff,
	0xf1, 0x54
};

const struct MT9V117_patch_section MT9V117_patch[MT9V117_PATCH_LINE_NUM] = {
	{section1,  MT9V117_PATCH_SECTION_SIZE}, {section2,  MT9V117_PATCH_SECTION_SIZE},
	{section3,  MT9V117_PATCH_SECTION_SIZE}, {section4,  MT9V117_PATCH_SECTION_SIZE},
	{section5,  MT9V117_PATCH_SECTION_SIZE}, {section6,  MT9V117_PATCH_SECTION_SIZE},
	{section7,  MT9V117_PATCH_SECTION_SIZE}, {section8,  MT9V117_PATCH_SECTION_SIZE},
	{section9,  MT9V117_PATCH_SECTION_SIZE}, {section10, MT9V117_PATCH_SECTION_SIZE},
	{section11, MT9V117_PATCH_SECTION_SIZE}, {section12, MT9V117_PATCH_SECTION_SIZE},
	{section13, 18}
};



#endif /* VC_MT9V117_PATCH_H */

/************************/
/*  End of File Comment */
/************************/

