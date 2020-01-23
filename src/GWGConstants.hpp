/*

Copyright 2017 Bert Melis

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#pragma once

#define VIRTUAL_READ 0xC7
#define VIRTUAL_WRITE 0xC4
#define PHYSICAL_READ 0xCB
#define PHYSICAL_WRITE 0xC8
#define EEPROM_READ 0xAE
#define EEPROM_WRITE 0xAD
#define PHYSICAL_XRAM_READ 0xC5
#define PHYSICAL_XRAM_WRITE 0xC3
#define PHYSICAL_PORT_READ 0x6E
#define PHYSICAL_PORT_WRITE 0x6D
#define PHYSICAL_BE_READ 0x6D
#define PHYSICAL_BE_WRITE 0x6D
#define PHYSICAL_KMBUS_RAM_READ 0x33
#define PHYSICAL_KMBUS_EEPROM_READ 0x43