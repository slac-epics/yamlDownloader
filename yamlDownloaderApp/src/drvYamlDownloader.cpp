//////////////////////////////////////////////////////////////////////////////
// This file is part of 'yamlDownloader'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'yamlDownloader', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <iocsh.h>
#include <epicsExport.h>
#include <yamlReader_api.h>

extern "C" int DownloadYamlFile( const char *ipAddr, const char* destFolder )
{
    // Create YamlReader object
    YamlReader tr = IYamlReader::create( ipAddr );

    // Set output directory
    tr->setOutputDir( destFolder );

    // Read the YAML tarball from the FPGA's PROM
    tr->readTarball();

    // Untar the file, stripping the root directory
    tr->untar( true );

    return 0;
}


static const iocshArg confArg0 =    { "ipAddr",     iocshArgString };
static const iocshArg confArg1 =    { "destFolder", iocshArgString };

static const iocshArg * const confArgs[] = {
    &confArg0,
    &confArg1
};

static const iocshFuncDef configFuncDef = { "DownloadYamlFile", 2, confArgs };

static void configCallFunc( const iocshArgBuf *args )
{
    DownloadYamlFile( args[0].sval, args[1].sval );
}

void drvYamlDownloaderRegister()
{
    iocshRegister( &configFuncDef, configCallFunc );
}

extern "C"
{
    epicsExportRegistrar( drvYamlDownloaderRegister );
}
