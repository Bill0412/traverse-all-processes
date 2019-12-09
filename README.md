# Traverse All Processes Kernel Module

This Program is used to Traverse all the Processed on a Linux OS.

## Output Content
- The status of all the processes, in the format of: name [index] state parent, each occupies one line.
- Total number of processes
- The number of processes inside each state("RSDTXtZPI")

### An output sample
```console
......
[ 5419.208801] kworker/u256:2 [27780] I kthreadd
[ 5419.208802] kworker/u256:1 [29343] I kthreadd
[ 5419.208803] kworker/u256:3 [30548] I kthreadd
[ 5419.208804] Microsoft.VSCod [30995] S Microsoft.VSCod
[ 5419.208805] kworker/0:0 [31802] I kthreadd
[ 5419.208806] sudo [32614] S bash
[ 5419.208806] insmod [32615] R sudo
[ 5419.208807] Total # of proceses: 346
[ 5419.208808] R: 3
[ 5419.208808] S: 265
[ 5419.208809] D: 0
[ 5419.208809] T: 0
[ 5419.208809] X: 0
[ 5419.208810] t: 0
[ 5419.208810] Z: 0
[ 5419.208811] P: 0
[ 5419.208811] I: 78
```


## Compile
```console
$ make clean
$ make
```

## Insert the Kernel Module
```console
$ sudo insmod traverse.ko
```

## Remove the Kernel Module
```console
$ sudo rmmod traverse.ko
```

## Display the Kernel Module Output
```console
$ dmesg
```