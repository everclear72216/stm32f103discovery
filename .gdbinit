set confirm off
set print pretty on

file ./debug/source/playwithcan
break main

target remote localhost:3333

monitor reset halt
load

monitor reset halt
continue

layout src
