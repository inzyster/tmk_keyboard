#!/bin/bash

make -f Makefile.rev2 clean
make -f Makefile.rev2 KEYMAP=fido

make -f Makefile.mouse.rev2 clean
make -f Makefile.mouse.rev2
