#ifndef WINDOWS_FTDI_COMPAT_H
#define WINDOWS_FTDI_COMPAT_H

// Windows FTDI compatibility defines
// to use the same source as linux

#define ftdi_set_bitmode(a,b,c) FT_SetBitMode(a,b,c)
#define ftdi_get_error_string(a) ""
#define ftdi_read_pins(a,b) FT_GetBitMode(a,b)
#define ftdi_set_baudrate(a,b) FT_SetBaudRate(a,b)
#define usleep(a) Sleep(a)
#define	FT_CHECK(x)	(ftdi_status = (x), (ftdi_status == FT_OK ? 0 : printf("FTDI: %s returned %d in %s:%d\n", STR(x), (int32_t)ftdi_status, __FUNCTION__, __LINE__)), ftdi_status)
#define FT_CHECK_WRITE(a,b,c,d) FT_CHECK(FT_Write(a, b, c, &d))
#define FT_CHECK_DEVLIST(a,b,c) FT_CHECK(FT_CreateDeviceInfoList(&a))
#define BITMODE_CBUS FT_BITMODE_CBUS_BITBANG
#define BITMODE_BITBANG FT_BITMODE_CBUS_BITBANG
#define FT_STRUCT_DEVLIST FT_DEVICE_LIST_INFO_NODE
#endif
