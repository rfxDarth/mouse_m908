/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include "rd_mouse.h"

std::string rd_mouse::detect(){
	
	std::string model = "";
	
	// libusb init
	if( libusb_init( NULL ) < 0 )
		return model;
	
	// get device list
	libusb_device **dev_list; // device list
	ssize_t num_devs = libusb_get_device_list(NULL, &dev_list);
	
	if( num_devs < 0 )
		return model;
	
	for( ssize_t i = 0; i < num_devs; i++ ){
		
		// get device descriptor
		libusb_device_descriptor descriptor;
		libusb_get_device_descriptor( dev_list[i], &descriptor );
		
		// get vendor and product id from descriptor
		uint16_t vid = descriptor.idVendor;
		uint16_t pid = descriptor.idProduct;
		
		// compare vendor and product id against known ids
		if( vid == mouse_m908::get_vid() && pid == mouse_m908::get_pid() ){
			model = "908";
			break;
		}else if( vid == mouse_m709::get_vid() && pid == mouse_m709::get_pid() ){
			model = "709";
			break;
		}else if( vid == mouse_m711::get_vid() && pid == mouse_m711::get_pid() ){
			model = "711";
			break;
		}else if( vid == mouse_m715::get_vid() && pid == mouse_m715::get_pid() ){
			model = "715";
			break;
		}
		
	}
	
	// free device list, unreference devices
	libusb_free_device_list( dev_list, 1 );
	
	// exit libusb
	libusb_exit( NULL );
		
	return model;
}

//init libusb and open mouse
int rd_mouse::_i_open_mouse( const uint16_t vid, const uint16_t pid ){
	
	//vars
	int res = 0;
	
	//libusb init
	res = libusb_init( NULL );
	if( res < 0 ){
		return res;
	}
	
	//open device
	_i_handle = libusb_open_device_with_vid_pid( NULL, vid,	pid );
	if( !_i_handle ){
		return 1;
	}
	
	if( _i_detach_kernel_driver ){
		//detach kernel driver on interface 0 if active 
		if( libusb_kernel_driver_active( _i_handle, 0 ) ){
			res += libusb_detach_kernel_driver( _i_handle, 0 );
			if( res == 0 ){
				_i_detached_driver_0 = true;
			} else{
				return res;
			}
		}
		
		//detach kernel driver on interface 1 if active 
		if( libusb_kernel_driver_active( _i_handle, 1 ) ){
			res += libusb_detach_kernel_driver( _i_handle, 1 );
			if( res == 0 ){
				_i_detached_driver_1 = true;
			} else{
				return res;
			}
		}
		
		//detach kernel driver on interface 2 if active 
		if( libusb_kernel_driver_active( _i_handle, 2 ) ){
			res += libusb_detach_kernel_driver( _i_handle, 2 );
			if( res == 0 ){
				_i_detached_driver_2 = true;
			} else{
				return res;
			}
		}
	}
	
	//claim interface 0
	res += libusb_claim_interface( _i_handle, 0 );
	if( res != 0 ){
		return res;
	}
	
	//claim interface 1
	res += libusb_claim_interface( _i_handle, 1 );
	if( res != 0 ){
		return res;
	}
	
	//claim interface 2
	res += libusb_claim_interface( _i_handle, 2 );
	if( res != 0 ){
		return res;
	}
	
	return res;
}

// init libusb and open mouse by bus and device
int rd_mouse::_i_open_mouse_bus_device( const uint8_t bus, const uint8_t device ){
	
	//vars
	int res = 0;
	
	//libusb init
	res = libusb_init( NULL );
	if( res < 0 ){
		return res;
	}
	
	//open device (_i_handle)
	libusb_device **dev_list; // device list
	ssize_t num_devs = libusb_get_device_list(NULL, &dev_list); //get device list
	
	if( num_devs < 0 )
		return 1;
	
	for( ssize_t i = 0; i < num_devs; i++ ){
		
		// check if correct bus and device
		if( bus == libusb_get_bus_number( dev_list[i] ) &&
			device == libusb_get_device_address( dev_list[i] ) ){
			
			// open device
			if( libusb_open( dev_list[i], &_i_handle ) != 0 ){
				return 1;
			} else{
				break;
			}
			
		}
		
	}
	
	//free device list, unreference devices
	libusb_free_device_list( dev_list, 1 );
	
	
	if( _i_detach_kernel_driver ){
		//detach kernel driver on interface 0 if active 
		if( libusb_kernel_driver_active( _i_handle, 0 ) ){
			res += libusb_detach_kernel_driver( _i_handle, 0 );
			if( res == 0 ){
				_i_detached_driver_0 = true;
			} else{
				return res;
			}
		}
		
		//detach kernel driver on interface 1 if active 
		if( libusb_kernel_driver_active( _i_handle, 1 ) ){
			res += libusb_detach_kernel_driver( _i_handle, 1 );
			if( res == 0 ){
				_i_detached_driver_1 = true;
			} else{
				return res;
			}
		}
		
		//detach kernel driver on interface 2 if active 
		if( libusb_kernel_driver_active( _i_handle, 2 ) ){
			res += libusb_detach_kernel_driver( _i_handle, 2 );
			if( res == 0 ){
				_i_detached_driver_2 = true;
			} else{
				return res;
			}
		}
	}
		
	//claim interface 0
	res += libusb_claim_interface( _i_handle, 0 );
	if( res != 0 ){
		return res;
	}
	
	//claim interface 1
	res += libusb_claim_interface( _i_handle, 1 );
	if( res != 0 ){
		return res;
	}
	
	//claim interface 2
	res += libusb_claim_interface( _i_handle, 2 );
	if( res != 0 ){
		return res;
	}
	
	return res;
}

//close mouse
int rd_mouse::_i_close_mouse(){
	
	//release interfaces 0, 1 and 2
	libusb_release_interface( _i_handle, 0 );
	libusb_release_interface( _i_handle, 1 );
	libusb_release_interface( _i_handle, 2 );
	
	//attach kernel driver for interface 0
	if( _i_detached_driver_0 ){
		libusb_attach_kernel_driver( _i_handle, 0 );
	}
	
	//attach kernel driver for interface 1
	if( _i_detached_driver_1 ){
		libusb_attach_kernel_driver( _i_handle, 1 );
	}
	
	
	//attach kernel driver for interface 2
	if( _i_detached_driver_2 ){
		libusb_attach_kernel_driver( _i_handle, 2);
	}
	
	//exit libusb
	libusb_exit( NULL );
	
	return 0;
}

//decode macro bytecode
int rd_mouse::_i_decode_macro( std::vector< uint8_t >& macro_bytes, std::ostream& output, std::string prefix, size_t offset ){
	
	// valid offset ?
	if( offset >= macro_bytes.size() )
		offset = 0;
	
	for( size_t i = offset; i < macro_bytes.size(); ){
		
		bool unknown_code = false;
		
		// failsafe
		if( i >= macro_bytes.size() )
			break;
		
		// mouse buttons ( 0x81 = down, 0x01 = up )
		if( macro_bytes[i] == 0x81 && macro_bytes[i+1] == 0x01 )
			output << prefix << "down\tmouse_left\n";
		else if( macro_bytes[i] == 0x81 && macro_bytes[i+1] == 0x02 )
			output << prefix << "down\tmouse_right\n";
		else if( macro_bytes[i] == 0x81 && macro_bytes[i+1] == 0x04 )
			output << prefix << "down\tmouse_middle\n";
		else if( macro_bytes[i] == 0x01 && macro_bytes[i+1] == 0x01 )
			output << prefix << "up\tmouse_left\n";
		else if( macro_bytes[i] == 0x01 && macro_bytes[i+1] == 0x02 )
			output << prefix << "up\tmouse_right\n";
		else if( macro_bytes[i] == 0x01 && macro_bytes[i+1] == 0x04 )
			output << prefix << "up\tmouse_middle\n";
		else if( macro_bytes[i] == 0x81 || macro_bytes[i] == 0x01 )
			unknown_code = true; // unknown code
		
		// keyboard key ( 0x84 = down, 0x04 = up )
		else if( macro_bytes[i] == 0x84 || macro_bytes[i] == 0x04 ){
			
			bool found_name = false;
			std::string key = "";
			
			// iterate over _c_keyboard_key_values
			for( auto keycode : _c_keyboard_key_values ){
				
				if( keycode.second == macro_bytes[i+1] ){
					key = keycode.first;
					found_name = true;
					break;
				}
				
			}
			
			// if key found, print key action
			if( found_name ){
				
				if( macro_bytes[i] == 0x84 ) // keyboard key down
					output << prefix << "down\t" << key << "\n";
				else if( macro_bytes[i] == 0x04 ) // keyboard key up
					output << prefix << "up\t" << key << "\n";
				else // failsafe
					unknown_code = true;
				
			} else{ // unknown key
				unknown_code = true;
			}
			
		}
		// delay
		else if( macro_bytes[i] == 0x06 ){
			output << prefix << "delay\t" << (int)macro_bytes[i+1] << "\n";
		}
		// padding (increment by one until a code appears)
		else if( macro_bytes[i] == 0x00 ){
			i++;
		}
		// unknown code
		else{
			unknown_code = true;
		}
		
		// if unknown code, print message + code
		if( unknown_code ){
			output << prefix << "unknown, please report as bug: ";
			output << std::hex << (int)macro_bytes[i] << " ";
			output << std::hex << (int)macro_bytes[i+1] << " ";
			output << std::hex << (int)macro_bytes[i+2];
			output << std::dec << "\n";
		}
		
		// increment (each code is 3 bytes long)
		i+=3;
		
	}
	
	return 0;
}

int rd_mouse::_i_encode_macro( std::array< uint8_t, 256 >& macro_bytes, std::istream& input, size_t offset ){
	
	macro_bytes.fill( 0x00 );
	
	// process macro
	std::string value1 = "";
	std::string value2 = "";
	std::size_t position = 0; // position in line
	int data_offset = offset; // position in macro_bytes
	
	for( std::string line; std::getline(input, line); ){
		
		// process individual line
		if( line.length() == 0 )
			continue;
		
		// maximum length reached
		if(data_offset > 212)
			return 0;

		position = 0;
		position = line.find("\t", position);
		value1 = line.substr(0, position);
		value2 = line.substr(position+1);
		
		// keyboard key down
		if( value1 == "down" && _c_keyboard_key_values.find(value2) != _c_keyboard_key_values.end() ){
			
			macro_bytes[data_offset] = 0x84;
			macro_bytes[data_offset+1] = _c_keyboard_key_values[value2];
			data_offset += 3;
		
		// keyboard key up
		} else if( value1 == "up" && _c_keyboard_key_values.find(value2) != _c_keyboard_key_values.end() ){
			
			macro_bytes[data_offset] = 0x04;
			macro_bytes[data_offset+1] = _c_keyboard_key_values[value2];
			data_offset += 3;
		
		// mouse button down	
		} else if( value1 == "down" && _c_keyboard_key_values.find(value2) == _c_keyboard_key_values.end() ){
			
			if( value2 == "mouse_left" ){
				macro_bytes[data_offset] = 0x81;
				macro_bytes[data_offset+1] = 0x01;
				data_offset += 3;
			} else if( value2 == "mouse_right" ){
				macro_bytes[data_offset] = 0x81;
				macro_bytes[data_offset+1] = 0x02;
				data_offset += 3;
			} else if( value2 == "mouse_middle" ){
				macro_bytes[data_offset] = 0x81;
				macro_bytes[data_offset+1] = 0x04;
				data_offset += 3;
			}
		
		// mouse button up
		} else if( value1 == "up" && _c_keyboard_key_values.find(value2) == _c_keyboard_key_values.end() ){
			
			if( value2 == "mouse_left" ){
				macro_bytes[data_offset] = 0x01;
				macro_bytes[data_offset+1] = 0x01;
				data_offset += 3;
			} else if( value2 == "mouse_right" ){
				macro_bytes[data_offset] = 0x01;
				macro_bytes[data_offset+1] = 0x02;
				data_offset += 3;
			} else if( value2 == "mouse_middle" ){
				macro_bytes[data_offset] = 0x01;
				macro_bytes[data_offset+1] = 0x04;
				data_offset += 3;
			}
			
		// delay
		} else if( value1 == "delay" ){
			
			int duration = (uint8_t)stoi( value2, 0, 10);
			if( duration >= 1 && duration <= 255 ){
				macro_bytes[data_offset] = 0x06;
				macro_bytes[data_offset+1] = duration;
				data_offset += 3;
			}
			
		}
		
	}
	
	return 0;
}

int rd_mouse::_i_decode_button_mapping( std::array<uint8_t, 4>& bytes, std::string& mapping ){
	
	std::stringstream output;
	bool found_name = false;
	int return_value = 0;
	
	// fire button
	if( bytes.at(0) == 0x99 ){
		
		output << "fire:";
		
		// button
		if( bytes.at(1) == 0x81 )
			output << "mouse_left:";
		else if( bytes.at(1) == 0x82 )
			output << "mouse_right:";
		else if( bytes.at(1) == 0x84 )
			output << "mouse_middle:";
		else{
			
			// iterate over _c_keyboard_key_values
			for( auto keycode : _c_keyboard_key_values ){
				
				if( keycode.second == bytes.at(1) ){
					
					output << keycode.first;
					break;
					
				}
				
			}
			output << ":";
		}
		
		// repeats
		output << (int)bytes.at(2) << ":";
		
		// delay
		output << (int)bytes.at(3);
		
		found_name = true;
		
	// snipe button
	} else if( bytes.at(0) == 0x9a && bytes.at(1) == 0x01 ){
		
		// iterate over _c_snipe_dpi_values
		for( auto dpi : _c_snipe_dpi_values ){
			
			if( dpi.second == bytes.at(2) && dpi.second == bytes.at(3) ){
				
				output << "snipe:" << dpi.first;
				found_name = true;
				break;
				
			}
			
		}
		
	// keyboard key
	} else if( bytes.at(0) == 0x90 ){
		
		// iterate over _c_keyboard_key_values
		for( auto keycode : _c_keyboard_key_values ){
			
			if( keycode.second == bytes.at(2) ){
				
				output << keycode.first;
				found_name = true;
				break;
				
			}
			
		}
		
	// modifiers + keyboard key
	} else if( bytes.at(0) == 0x8f ){
		
		// iterate over _c_keyboard_modifier_values
		for( auto modifier : _c_keyboard_modifier_values ){
			
			if( modifier.second & bytes.at(1) ){
				output << modifier.first;
			}
			
		}
		
		// iterate over _c_keyboard_key_values
		for( auto keycode : _c_keyboard_key_values ){
			
			if( keycode.second == bytes.at(2) ){
				
				output << keycode.first;
				found_name = true;
				break;
				
			}
			
		}
		
	} else{ // mousebutton or special function ?
		
		// iterate over _c_keycodes
		for( auto keycode : _c_keycodes ){
			
			if( keycode.second[0] == bytes.at(0) &&
				keycode.second[1] == bytes.at(1) && 
				keycode.second[2] == bytes.at(2) ){
				
				output << keycode.first;
				found_name = true;
				break;
				
			}
			
		}
		
	}
	
	if( !found_name ){
		output << "unknown, please report as bug: ";
		output << " " << std::hex << (int)bytes.at(0) << " ";
		output << " " << std::hex << (int)bytes.at(1) << " ";
		output << " " << std::hex << (int)bytes.at(2) << " ";
		output << " " << std::hex << (int)bytes.at(3);
		output << std::dec;
		return_value = 1;
	}
	
	mapping = output.str();
	return return_value;
}

int rd_mouse::_i_encode_button_mapping( std::string& mapping, std::array<uint8_t, 4>& bytes ){
	
	// is string in _c_keycodes? mousebuttons/special functions and media controls
	if( _c_keycodes.find(mapping) != _c_keycodes.end() ){
		
		bytes[0] = _c_keycodes[mapping][0];
		bytes[1] = _c_keycodes[mapping][1];
		bytes[2] = _c_keycodes[mapping][2];
		bytes[3] = 0x00;
	
	// fire button (multiple keypresses)
	} else if( mapping.find("fire") == 0 ){
		
		std::stringstream mapping_stream(mapping);
		std::string value1 = "", value2 = "", value3 = "";
		uint8_t keycode, repeats = 1, delay = 0;
		
		// the repeated value1 line is not a mistake, it skips the "fire:"
		std::getline( mapping_stream, value1, ':' );
		std::getline( mapping_stream, value1, ':' );
		std::getline( mapping_stream, value2, ':' );
		std::getline( mapping_stream, value3, ':' );
		
		if( value1 == "mouse_left" ){
			keycode = 0x81;
		} else if( value1 == "mouse_right" ){
			keycode = 0x82;
		} else if( value1 == "mouse_middle" ){
			keycode = 0x84;
		} else if( _c_keyboard_key_values.find(value1) != _c_keyboard_key_values.end() ){
			keycode = _c_keyboard_key_values[value1];
		} else{
			return 1;
		}
		
		repeats = (uint8_t)stoi(value2);
		delay = (uint8_t)stoi(value3);
		
		// store values
		bytes[0] = 0x99;
		bytes[1] = keycode;
		bytes[2] = repeats;
		bytes[3] = delay;
	
	// snipe button (changes dpi while pressed)
	} else if( mapping.find("snipe") == 0 ){
		
		try{
			
			int dpi_value = std::stoi( std::regex_replace( mapping, std::regex("snipe:"), "" ) );
			uint8_t dpi_byte = _c_snipe_dpi_values.at( dpi_value );
			
			bytes[0] = 0x9a;
			bytes[1] = 0x01;
			bytes[2] = dpi_byte;
			bytes[3] = dpi_byte;
			
		} catch( std::exception& f ){ // invalid mapping pattern or dpi
			return 1;
		}
		
	// string is not a key in _c_keycodes: keyboard key (+ modifiers) ?
	} else{
		
		// search for modifiers and change values accordingly: ctrl, shift ...
		uint8_t first_value = 0x90;
		uint8_t modifier_value = 0x00;
		for( auto i : _c_keyboard_modifier_values ){
			if( mapping.find( i.first ) != std::string::npos ){
				modifier_value += i.second;
				first_value = 0x8f;
			}
		}
		
		// get key value and store everything
		try{
			
			std::regex modifier_regex ("[a-z_]*\\+");
			
			// store values
			bytes[0] = first_value;
			bytes[1] = modifier_value;
			bytes[2] = _c_keyboard_key_values[std::regex_replace( mapping, modifier_regex, "" )];
			bytes[3] = 0x00;
			
		} catch( std::exception& f ){
			return 1;
		}
	}
	
	return 0;
}