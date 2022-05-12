#!/bin/sh

cd /usr/src/minix/servers/pm && make clean && make && make install
cd /usr/src/lib/libc && make clean && make && make install
cd /usr/src/releasetools/ &&  make do-hdboot
reboot