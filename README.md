# yamlDownloader EPICS Module for the SLAC High Performance System

## Description

This module downloads the YAML tarball storaged in the FPGA's PROM. The tarball is written and untared
to an specific destination folder. Then, it can be loaded, for example, using the yamlLoader module.

The modules takes as arguments the IP address of the target FPGA and a destination folder for the YAML
file. The YAML tarball is read from the FPGA's PROM and written into the destination folder, then the
file is untared stripping the root directory name from the tarball. In this way all the YAML files are
deposited in the destination folder.

## Documentation

You can find several README files which describe different aspects of the module:

File                        | Description
----------------------------|---------------
README.configureDriver.md   | How to configure the driver in your application.
README.dependencies.md      | Which external packages and modules are needed by this module.