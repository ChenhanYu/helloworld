#!/bin/bash
export HELLOWORLD_DIR=$PWD
echo "HELLOWORLD_DIR = $HELLOWORLD_DIR"

## Parallel options
export OMP_PROC_BIND=spread
export OMP_NUM_THREADS=1
