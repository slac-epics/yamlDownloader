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
