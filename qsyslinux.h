#include <linux/version.h>
#include <sys/utsname.h>

const char[] linuxKernelVersion()
{
	int maj = LINUX_VERSION_CODE >> 16;
	int min = ( LINUX_VERSION_CODE - ( maj << 16 ) ) >> 8;
	int pat = LINUX_VERSION_CODE - ( maj << 16 ) - ( min << 8 );
	struct utsname unamedata;
	uname(&unamedata);
	return unamedata.release;

}
