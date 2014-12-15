#!/bin/bash

eval "rm -rf *.txt"
eval "dd if=/dev/urandom of=2MFile.txt count=4096" 
eval "dd if=/dev/urandom of=8MFile.txt count=16384"
eval "dd if=/dev/urandom of=32MFile.txt count=65536"
eval "dd if=/dev/urandom of=256MFile.txt count=524288"
eval "dd if=/dev/urandom of=512MFile.txt count=1048576"
eval "dd if=/dev/urandom of=1GFile.txt count=2097152"
eval "dd if=/dev/urandom of=2GFile.txt count=4194304"
