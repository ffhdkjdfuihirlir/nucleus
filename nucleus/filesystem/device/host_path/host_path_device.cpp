/**
 * (c) 2015 Alexandro Sanchez Bach. All rights reserved.
 * Released under GPL v2 license. Read LICENSE for more details.
 */

#include "host_path_device.h"
#include "host_path_file.h"

namespace fs {

HostPathDevice::HostPathDevice(const Path& mountPath, const Path& localPath)
    : IDevice(mountPath), localPath(localPath)
{
}

File* HostPathDevice::openFile(const Path& path, OpenMode mode)
{
    auto* file = new HostPathFile(localPath + path, mode);
    if (!file->isOpen()) {
        delete file;
        return nullptr;
    }

    return file;
}

}  // namespace fs
