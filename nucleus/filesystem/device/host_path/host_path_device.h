/**
 * (c) 2015 Alexandro Sanchez Bach. All rights reserved.
 * Released under GPL v2 license. Read LICENSE for more details.
 */

#pragma once

#include "nucleus/common.h"
#include "nucleus/filesystem/device.h"

namespace fs {

class HostPathDevice : public IDevice {
    Path localPath;

public:
    HostPathDevice(const Path& mountPath, const Path& localPath);

    File* openFile(const Path& path, OpenMode mode) override;
    bool existsFile(const Path& path);
    bool removeFile(const Path& path);
};

}  // namespace fs
