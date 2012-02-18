#!/bin/sh

find . -type f ! -exec grep -q 'Copyright' {} \; -print
