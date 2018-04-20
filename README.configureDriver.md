# How to configure the yamlDownloader driver

## Overview

This module downloads the YAML tarball storaged in the FPGA's PROM. The tarball is written and untared
to an specific destination folder. Then, it can be loaded, for example, using the yamlLoader module.

This document describes how to configure the driver and load it into your IOC.

## yamlDownloader Configuration

In order to use **yamlDownloader** in your application you must call **DownloadYamlFile** on your IOC's st.cmd script.

With the following parameters:

DownloadYamlFile(FPGA_IP, DEST_PATH)

| Parameter                | Description
|--------------------------|-----------------------------
| FPGA_IP                  | Target FPGA IP Address.
| DEST_PATH                | The destination folder where the YAML file will be written.


**Notes:**
- *DEST_PATH* must be writable, for example a location under $IOC_DATA. Otherwise it will throw and exception.

## Use of the yamlLoader Module

If you plan to use the **yamlModule**, you must call **cpswLoadYamlFile()** after **DownloadYamlFile()** in your **st.cmd**.
You should pass it the location of the YAML file you used on **DownloadYamlFile()** plus your top YAML file name, which
usually will be **DEST_PATH/000TopLevel.yaml**.