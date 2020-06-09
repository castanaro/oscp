!/bin/bash

for server in $(cat [input file] |cut -d " " -f 4);do
host -l $1 $server
done
