#ifndef SYSINFOWINDOWSIMPL_H
#define SYSINFOWINDOWSIMPL_H

#include "sysinfo.h"
#include <QVector>
#include <QtGlobal>
//#include <windows.h>

typedef struct _FILETIME FILETIME;

class SysInfoWindowsImpl : public SysInfo
{
public:
    SysInfoWindowsImpl();

    // SysInfo interface
public:
    void init() override;
    void cpuLoadAverage() override;
    double memoryUsed() override;

private:
    QVector<qulonglong> cpuRawData();
    qulonglong convertFileTime(const FILETIME& filetime) const;
private:
    QVector<qulonglong> mCpuLoadLastValues;
};

#endif // SYSINFOWINDOWSIMPL_H
