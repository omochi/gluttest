#!/bin/bash
find . -name *.cpp -or -name *.h | xargs nkf -w8 -Lu --overwrite -g
