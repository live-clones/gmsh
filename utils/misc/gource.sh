#!/bin/sh

### -f --start-date '2006-01-01'

gource -f --time-scale 2 -b 000000 --seconds-per-day 0.0001 --hide filenames --file-filter projects --file-filter data --file-filter branches --file-filter benchmarks_private --file-filter benchmarks_kst --highlight-user geuzaine -1280x720 -o - | ffmpeg -y -r 60 -f image2pipe -vcodec ppm -i - -vcodec libx264 -preset ultrafast -pix_fmt yuv420p -crf 1 -threads 0 -bf 0 gource.mp4
