## Rex scripts

These are a variety of scripts that I use for Rex development. Please note that you may want to change the processor count in the build scripts. My development computer is quite powerful so it handles them perfectly, but if you use them on a smaller computer, it will likely crash.

Before using any, source the setup script: `source setup.sh`.

* `build.sh` -> Performs a clean build off existing sources using CMake.
* `build-autotools.sh` -> Builds Rex using the autotools. This is similar to the other build.sh.
* `full-build.sh` -> Clones OmpParser and Rex, and builds each. Uses CMake.
* `fedora.sh` -> I use Fedora for my development systems, so this installs the equivalents to the Ubuntu listing.

