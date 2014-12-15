#!/bin/bash

eval "rm -rf *.dat"
for i in `seq 1 1 2`
do
    echo "Sup ${i}"
    eval "dd if=/dev/urandom of=${i}thread_acc_file.dat count=65536"
done
