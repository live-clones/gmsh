#!/bin/sh

awk 'BEGIN{ printf "View \"xyz2pos\"{\n";  } { printf "SP(%g,%g,%g){%g};\n", $1, $2, $3, $4; } END {printf "};\n"}'
