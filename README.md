## micro-builder
Build Environment for Microcontroller Projects

[![Build Status](https://travis-ci.org/zorxx/micro-builder.svg?branch=master)](https://travis-ci.org/zorxx/micro-builder)

## Quickstart

1. git clone the micro-builder repository:
    git clone https://github.com/zorxx/micro-builder.git
2. Configure desired target architecture/board/variant/sdk by setting the environment
   variable `MB_TARGET`. Run `make variants` at the top level to see a list of all
   supported architectures and variants.
3. Execute `make` in the root of the micro-builder source tree. This will build the base
   prerequisites for the selected architecture.
4. Navigate to the examples directory to build an application. Each application should
   automatically build their required dependencies (i.e. libraries).
4a. Create your own application by creating a directory under the `user` directory and
    follow the Makefile pattern shown by the example applications.

## Configuration

The environment variable `MB_TARGET` provides information to the build system about the
target architecture, device, and other build dependencies such as an SDK or operating system.
The format of the `MB_TARGET` is: `<architecture>/<variant>`. A list of all supported
architectures and their variants can be found by executing `make variants` at the root
of the micro-builder source tree.

## Example

The following sequence of commands will configure the build for an ESP8266 NodeMCU device
using the ESP8266 SDK, build all prerequisites, then build a `hello world` application and
write it to flash:

```bash
export MB_TARGET=xtensa_nodemcu
make
cd app/esp8266/hello_world
make
make flash

``` 
Note: this assumes that the first command is executed in the root of the micro-builder
source tree and the target device is connected to the serial port /dev/ttyUSB0. 

## Build System Prerequisites

The build environment relies on the existence of the following packages. All other dependencies (i.e. target libraries and packages) are downloaded automatically during the build process.

- git
- mercurial
- subversion
- unzip
- python 2.7
- libusb-dev
- libusb-1.0.0-dev
- gperf
- texinfo
- help2man
- flex
- bison

Not all build targets require all prerequisites, so it may be possible to perform successful
builds without the availability of all the items above.

On Debian-based systems, the following command line can be used to install all prerequisites:

```bash
sudo apt install git mercurial subversion unzip python libusb-dev libusb-1.0.0-dev gperf texinfo help2man flex bison
```

## micro-builder Design

Goals:
- Simple, flexible environment for building applications for microcontrollers
- Make use of existing projects (don't re-invent wheels)

Build Environment:
- Rely only on GNU make. Never assume any particular shell exists (e.g. bash). This makes
portability of the build environment among platforms (e.g. Windows and Linux) possible.
- Never rely on absolute paths. The micro-builder root directory can exist anywhere.
- `make` can be executed from any directory in the build source tree (e.g. to build individual
example applications or all example applications)

Packages:
The packages directory contains recipes for downloading and optionally building packages
from external projects. Examples of packages are: toolchains, target flashing and debugging
tools, libraries, applications, etc. The two major components of a package are

- Makefile
    This contains all of the information for downloading and building the package
- package.inc
    When the package is defined as a prerequisite of any component, this file is included
    in the build environment. This allows the package to provide things to the build
    environment, such as include file directories (for library packages) or toolchain
    binary locations (for toolchain packages).

Libraries:
Some libraries exist directly within the micro-builder source tree. Eventually, these
libraries may be split into separate git projects (and be included as packages in
micro-builder).

Examples:
Some example applications exist directly within the micro-builder source tree. Eventually,
these applications may be split into separate git projects (and be included as packages in
micro-builder).

Notes:
Some aspects of micro-builder are similar to Buildroot, however there are some key differences:
- micro-builder is designed to allow for development of applications.
- Selected packages determine the build environment. Adding a new package can change the way
  all applications/libraries are built.

## Windows Build 

The Windows build environment is not actively maintained. Use at your own peril (or volunteer to help maintain it).

1. MinGW
   a. Download and run installer
      http://www.mingw.org/download/installer
   b. Install all necessary packages
      mingw-get install msys-bzip2 msys-gzip msys-make msys-patch msys-sed msys-tar msys-unzip msys-wget msys-xz
   c. Add packages to the windows system path
      setx path "%PATH%;C:\MinGW\msys\1.0\bin" /M
2. Git
   a. Download and run installer
      https://git-scm.com/download/win
3. Mercurial
   a. Download and run installer
      https://www.mercurial-scm.org/wiki/Download
   b. Add Mercurial to the windows system path
      setx path "%PATH%;C:\Program Files\TortoiseHg" /M
4. Python
   a. Download and run installer
      https://www.python.org/ftp/python/2.7.14/python-2.7.14.amd64.msi
   b. Add Python to the windows system path
      setx path "%PATH%;C:\Python27" /M
