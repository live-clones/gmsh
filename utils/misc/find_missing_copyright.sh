#!/bin/sh

find ../.. -not -path "*.svn*" -and -type f ! -exec grep -q 'Copyright' {} \; -print
