#pragma once

#include "PEElementDumper.h"

class PEDebugInfoTableDumper :
    public PEElementDumper
{
public:
    PEDebugInfoTableDumper() : PEElementDumper("DebugInfoTable") {}

    PEDebugInfoTableDumper & SetDumpElement(_In_ IPEDebugInfoTable *debugInfoTable) {
        _debugInfoTable = debugInfoTable;
        return *this;
    }

protected:
    void DoDump() override;
    
private:
    LibPEPtr<IPEDebugInfoTable> _debugInfoTable;
};