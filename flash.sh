#!/bin/bash

PORT=$2
FILE=$1

avrdude -p atmega32u4 -P $PORT  -c avr109  -U flash:w:$FILE
