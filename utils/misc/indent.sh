#!/bin/sh

# indent should be GNU indent

indent --braces-on-if-line --cuddle-do-while --honour-newlines --no-space-after-casts --no-space-after-function-call-names --no-space-after-for --no-space-after-if --no-space-after-while --no-tabs --dont-format-comments --comment-indentation1 --dont-break-procedure-type $*

# If we don't want the return type on the same line as the function
# name, just remove --dont-break-procedure-type
