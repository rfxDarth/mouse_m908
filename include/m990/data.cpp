/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

/*
 * This file contains internal constants and lookup tables
 */

#include "../rd_mouse.h"

const std::string mouse_m990::_c_name = "990";

// usb device vars
const uint16_t mouse_m990::_c_mouse_vid = 0x04d9;
const uint16_t mouse_m990::_c_mouse_pid = 0xfc0f;

// Names of the physical buttons TODO!
std::map< int, std::string > mouse_m990::_c_button_names = {
	{ 0, "button_left" },
	{ 1, "button_right" },
	{ 2, "button_middle" },
	{ 3, "button_fire" },
	{ 4, "button_dpi_up" },
	{ 5, "button_dpi_down" },
	{ 6, "button_1" },
	{ 7, "button_2" },
	{ 8, "button_3" },
	{ 9, "button_4" },
	{ 10, "button_5" },
	{ 11, "button_6" },
	{ 12, "button_7" },
	{ 13, "button_8" },
	{ 14, "button_9" },
	{ 15, "button_10" },
	{ 16, "button_11" },
	{ 17, "button_12" },
	{ 18, "button_13" },
	{ 19, "button_14" },
	{ 20, "button_15" },
	{ 21, "button_16" },
	{ 22, "button_mode" },
	{ 23, "button_profile" },
	{ 24, "scroll_up" },
	{ 25, "scroll_down" } };

// Mapping of real DPI values to bytecode TODO!
// Take a look the M908 implementation for details.
// Min. 50, Max. 16400
std::map< unsigned int, std::array<uint8_t, 2> > mouse_m990::_c_dpi_codes = {
};

//usb data packets
uint8_t mouse_m990::_c_data_profile[5][16] = {
	{ 0x02, 0x0b, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x07, 0x2c, 0x00, 0x01, 0x00, 0xfa, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x06, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x08, 0x40, 0x00, 0x2c, 0x00, 0xfa, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
};

uint8_t mouse_m990::_c_data_macros_1[16] = 
	{0x02, 0xf5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

uint8_t mouse_m990::_c_data_macros_2[256] = {
	0x04, 0xf3, 0x00, 0x00, 0xc8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

uint8_t mouse_m990::_c_data_macros_3[16] = 
	{0x02, 0xf5, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

uint8_t mouse_m990::_c_data_macros_codes[15][2] =  {
	{0x78, 0x04},
	{0x40, 0x05},
	{0x08, 0x06},
	{0xd0, 0x06},
	{0x98, 0x07},
	{0x60, 0x08},
	{0x28, 0x09},
	{0xf0, 0x09},
	{0xb8, 0x0a},
	{0x80, 0x0b},
	{0x48, 0x0c},
	{0x10, 0x0d},
	{0xd8, 0x0d},
	{0xa0, 0x0e},
	{0x68, 0x0f} };

uint8_t mouse_m990::_c_data_settings_16[21][16] = {
	{ 0x02, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x08, 0x40, 0x00, 0x2c, 0x00, 0xfa, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x07, 0x00, 0x01, 0x06, 0x00, 0xfa, 0xfa, 0x00, 0x00, 0xff, 0x02, 0x03, 0x74, 0x00, 0x00 },
	{ 0x02, 0x07, 0x00, 0x01, 0x06, 0x00, 0xfa, 0xfa, 0x00, 0x00, 0xff, 0x02, 0x03, 0x74, 0x00, 0x00 },
	{ 0x02, 0x07, 0xd0, 0x01, 0x06, 0x00, 0xfa, 0xfa, 0x00, 0x00, 0xff, 0x02, 0x03, 0x74, 0x00, 0x00 },
	{ 0x02, 0x07, 0x34, 0x00, 0x01, 0x00, 0xfa, 0xfa, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x07, 0xa0, 0x02, 0x06, 0x00, 0xfa, 0xfa, 0x00, 0x00, 0xff, 0x02, 0x03, 0x00, 0x00, 0x00 },
	{ 0x02, 0x07, 0x36, 0x00, 0x01, 0x00, 0xfa, 0xfa, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x07, 0x70, 0x03, 0x06, 0x00, 0xfa, 0xfa, 0x00, 0xff, 0x00, 0x02, 0x03, 0x75, 0x00, 0x00 },
	{ 0x02, 0x07, 0x38, 0x00, 0x01, 0x00, 0xfa, 0xfa, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x07, 0x40, 0x04, 0x06, 0x00, 0xfa, 0xfa, 0x00, 0xff, 0xff, 0x02, 0x03, 0x74, 0x00, 0x00 },
	{ 0x02, 0x07, 0x3a, 0x00, 0x01, 0x00, 0xfa, 0xfa, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x07, 0x50, 0x04, 0x06, 0x00, 0xfa, 0xfa, 0xff, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x07, 0x56, 0x04, 0x06, 0x00, 0xfa, 0xfa, 0xff, 0x00, 0x00, 0x02, 0x03, 0x00, 0x00, 0x00 },
	{ 0x02, 0x07, 0x5c, 0x04, 0x06, 0x00, 0xfa, 0xfa, 0xff, 0x00, 0x00, 0x02, 0x03, 0x02, 0x00, 0x00 },
	{ 0x02, 0x07, 0x2c, 0x00, 0x01, 0x00, 0xfa, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x0b, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x06, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x08, 0x40, 0x00, 0x2c, 0x00, 0xfa, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x02, 0x0b, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
};

uint8_t mouse_m990::_c_data_settings_256[5][256] = {
	
	                      { 0x04, 0x07, 0x80, 0x00, 0x6a, 0x00, 0xfa, 0xfa, 0x1a, 0x00, 0x01, 0x00,
	0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x19, 0x81, 0x03, 0x01, 0x0a, 0x00,
	0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x10, 0x00, 0x1e, 0x00, 0x10, 0x00, 0x1f, 0x00, 0x10, 0x00,
	0x20, 0x00, 0x10, 0x00, 0x21, 0x00, 0x10, 0x00, 0x22, 0x00, 0x10, 0x00, 0x23, 0x00, 0x10, 0x00,
	0x24, 0x00, 0x10, 0x00, 0x25, 0x00, 0x10, 0x00, 0x26, 0x00, 0x10, 0x00, 0x27, 0x00, 0x10, 0x00,
	0x57, 0x00, 0x10, 0x00, 0x56, 0x00, 0x10, 0x00, 0x2e, 0x00, 0x10, 0x00, 0x37, 0x00, 0x10, 0x00,
	0x55, 0x00, 0x10, 0x00, 0x54, 0x00, 0x1b, 0x04, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x0b, 0x00,
	0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00 },

	                                        { 0x04, 0x07, 0x50, 0x01, 0x6a, 0x00, 0xfa, 0xfa, 0x1a,
	0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x19, 0x81, 0x03,
	0x01, 0x0a, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x10, 0x00, 0x1e, 0x00, 0x10, 0x00, 0x1f,
	0x00, 0x10, 0x00, 0x20, 0x00, 0x10, 0x00, 0x21, 0x00, 0x10, 0x00, 0x22, 0x00, 0x10, 0x00, 0x23,
	0x00, 0x10, 0x00, 0x24, 0x00, 0x10, 0x00, 0x25, 0x00, 0x10, 0x00, 0x26, 0x00, 0x10, 0x00, 0x27,
	0x00, 0x10, 0x00, 0x57, 0x00, 0x10, 0x00, 0x56, 0x00, 0x10, 0x00, 0x2e, 0x00, 0x10, 0x00, 0x37,
	0x00, 0x10, 0x00, 0x55, 0x00, 0x10, 0x00, 0x54, 0x00, 0x1b, 0x04, 0x00, 0x00, 0x0d, 0x00, 0x00,
	0x00, 0x0b, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },

	                      { 0x04, 0x07, 0x20, 0x02, 0x6a, 0x00, 0xfa, 0xfa, 0x1a, 0x00, 0x01, 0x00,
	0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x19, 0x81, 0x03, 0x01, 0x0a, 0x00,
	0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x10, 0x00, 0x1e, 0x00, 0x10, 0x00, 0x1f, 0x00, 0x10, 0x00,
	0x20, 0x00, 0x10, 0x00, 0x21, 0x00, 0x10, 0x00, 0x22, 0x00, 0x10, 0x00, 0x23, 0x00, 0x10, 0x00,
	0x24, 0x00, 0x10, 0x00, 0x25, 0x00, 0x10, 0x00, 0x26, 0x00, 0x10, 0x00, 0x27, 0x00, 0x10, 0x00,
	0x57, 0x00, 0x10, 0x00, 0x56, 0x00, 0x10, 0x00, 0x2e, 0x00, 0x10, 0x00, 0x37, 0x00, 0x10, 0x00,
	0x55, 0x00, 0x10, 0x00, 0x54, 0x00, 0x1b, 0x04, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x0b, 0x00,
	0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00 },

                          { 0x04, 0x07, 0xf0, 0x02, 0x6a, 0x00, 0xfa, 0xfa, 0x1a, 0x00, 0x01, 0x00,
	0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x19, 0x81, 0x03, 0x01, 0x0a, 0x00,
	0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x10, 0x00, 0x1e, 0x00, 0x10, 0x00, 0x1f, 0x00, 0x10, 0x00,
	0x20, 0x00, 0x10, 0x00, 0x21, 0x00, 0x10, 0x00, 0x22, 0x00, 0x10, 0x00, 0x23, 0x00, 0x10, 0x00,
	0x24, 0x00, 0x10, 0x00, 0x25, 0x00, 0x10, 0x00, 0x26, 0x00, 0x10, 0x00, 0x27, 0x00, 0x10, 0x00,
	0x57, 0x00, 0x10, 0x00, 0x56, 0x00, 0x10, 0x00, 0x2e, 0x00, 0x10, 0x00, 0x37, 0x00, 0x10, 0x00,
	0x55, 0x00, 0x10, 0x00, 0x54, 0x00, 0x1b, 0x04, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x0b, 0x00,
	0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00 },

	                      { 0x04, 0x07, 0xc0, 0x03, 0x6a, 0x00, 0xfa, 0xfa, 0x1a, 0x00, 0x01, 0x00,
	0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x19, 0x81, 0x03, 0x01, 0x0a, 0x00,
	0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x10, 0x00, 0x1e, 0x00, 0x10, 0x00, 0x1f, 0x00, 0x10, 0x00,
	0x20, 0x00, 0x10, 0x00, 0x21, 0x00, 0x10, 0x00, 0x22, 0x00, 0x10, 0x00, 0x23, 0x00, 0x10, 0x00,
	0x24, 0x00, 0x10, 0x00, 0x25, 0x00, 0x10, 0x00, 0x26, 0x00, 0x10, 0x00, 0x27, 0x00, 0x10, 0x00,
	0x57, 0x00, 0x10, 0x00, 0x56, 0x00, 0x10, 0x00, 0x2e, 0x00, 0x10, 0x00, 0x37, 0x00, 0x10, 0x00,
	0x55, 0x00, 0x10, 0x00, 0x54, 0x00, 0x1b, 0x04, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x0b, 0x00,
	0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00 }

};

uint8_t mouse_m990::_c_data_settings_64[5][64] = {

	                      { 0x03, 0x07, 0x40, 0x00, 0x2c, 0x00, 0xfa, 0xfa, 0x05, 0x00, 0x03, 0x00,
	0x01, 0x14, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x01, 0x28, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x50, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x01, 0xa4, 0x00, 0xa4, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x48, 0x01, 0x48, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00 },

	                      { 0x03, 0x07, 0x10, 0x01, 0x2c, 0x00, 0xfa, 0xfa, 0x05, 0x00, 0x03, 0x00,
	0x01, 0x14, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x01, 0x28, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x50, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x01, 0xa4, 0x00, 0xa4, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x48, 0x01, 0x48, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00 },

	                      { 0x03, 0x07, 0xe0, 0x01, 0x2c, 0x00, 0xfa, 0xfa, 0x05, 0x00, 0x03, 0x00,
	0x01, 0x14, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x01, 0x28, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x50, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x01, 0xa4, 0x00, 0xa4, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x48, 0x01, 0x48, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00 },

	                      { 0x03, 0x07, 0xb0, 0x02, 0x2c, 0x00, 0xfa, 0xfa, 0x05, 0x00, 0x03, 0x00,
	0x01, 0x14, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x01, 0x28, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x50, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x01, 0xa4, 0x00, 0xa4, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x48, 0x01, 0x48, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00 },

	                      { 0x03, 0x07, 0x80, 0x03, 0x2c, 0x00, 0xfa, 0xfa, 0x05, 0x00, 0x03, 0x00,
	0x01, 0x14, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x01, 0x28, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x50, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x01, 0xa4, 0x00, 0xa4, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x48, 0x01, 0x48, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00 }

};
