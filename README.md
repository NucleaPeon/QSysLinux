# QSysLinux
Library to fill in missing Qt5.3.2 linux kernel information functionality

In Qt 5.3.2, the QSysInfo class contains ``QSysInfo::macVersion()`` and ``QSysInfo::windowsVersion()``, but no ``QSysInfo::linuxVersion()``.

While working on a library, I encountered a situation where the linux kernel version was used, but as I was 'downgrading' the library to work with older Qt versions, it failed due to missing methods:

```cpp
name = QSysInfo::kernelType () + '/' + QSysInfo::kernelVersion ();
```
