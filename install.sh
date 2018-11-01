#!/bin/sh

#install tcc if not already installed
dpkg -l | grep -qw tcc || apt-get install tcc

chmod +x makeBash

mv makeBash /bin/
printf "makeBash installed!\n"