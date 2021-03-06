/*
	liblightmodbus - a lightweight, multiplatform Modbus library
	Copyright (C) 2017 Jacek Wieczorek <mrjjot@gmail.com>

	This file is part of liblightmodbus.

	Liblightmodbus is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Liblightmodbus is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LIGHTMODBUS_MBREGS_H
#define LIGHTMODBUS_MBREGS_H

#include <inttypes.h>
#include "../libconf.h"
#include "../lightmodbus.h"
#include "../master.h"

//Functions for building requests
#if defined(LIGHTMODBUS_F03M) || defined(LIGHTMODBUS_F04M)
extern ModbusError modbusBuildRequest0304( ModbusMaster *status, uint8_t function, uint8_t address, uint16_t index, uint16_t count );
static inline ModbusError modbusBuildRequest03( ModbusMaster *status, uint8_t address, uint16_t index, uint16_t count ) 
	{ return modbusBuildRequest0304( (status), 3, (address), (index), (count) ); }
static inline ModbusError modbusBuildRequest04( ModbusMaster *status, uint8_t address, uint16_t index, uint16_t count ) 
	{ return modbusBuildRequest0304( (status), 4, (address), (index), (count) ); }
#endif

#ifdef LIGHTMODBUS_F06M
extern ModbusError modbusBuildRequest06( ModbusMaster *status, uint8_t address, uint16_t index, uint16_t value );
#endif

#ifdef LIGHTMODBUS_F16M
extern ModbusError modbusBuildRequest16( ModbusMaster *status, uint8_t address, uint16_t index, uint16_t count, uint16_t *values );
#endif

#ifdef LIGHTMODBUS_F22M
extern ModbusError modbusBuildRequest22( ModbusMaster *status, uint8_t address, uint16_t index, uint16_t andmask, uint16_t ormask );
#endif

#endif
