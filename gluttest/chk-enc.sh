#!/bin/bash
find -name *.cpp -or -name *.h | xargs nkf --guess
