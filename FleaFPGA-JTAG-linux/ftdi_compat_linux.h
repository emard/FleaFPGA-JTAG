#ifndef FTDI_COMPAT_LINUX_H
#define FTDI_COMPAT_LINUX_H

// Windows FTDI compatibility defines
// to use the same source as linux

#define	FT_CHECK(x)	(ftdi_status = (x), (ftdi_status >= 0 ? 0 : printf("FTDI: %s returned %d in %s:%d: %s\n", STR(x), (int32_t)ftdi_status, __FUNCTION__, __LINE__, ftdi_get_error_string(ftdi))), ftdi_status)
#define FT_CHECK_WRITE(a,b,c,d) FT_CHECK(d = ftdi_write_data(a, b, c))
#define FT_CHECK_DEVLIST(a,b,c) FT_CHECK(a = ftdi_usb_find_all(b, &c, 0, 0))
#define FT_STRUCT_DEVLIST struct ftdi_device_list
#endif
