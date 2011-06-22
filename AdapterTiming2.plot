set multiplot
set grid
set title "Audio adapter timing: host [rate = 44.1 kHz buffer = 512 frames] adapter [rate = 16.0 kHz buffer = 128 frames] "
set xlabel "audio cycles"
set ylabel "resampling ratio"
plot "JackAudioAdapter.log" using 4 title "Ratio 1" with lines,"JackAudioAdapter.log" using 5 title "Ratio 2" with lines
 unset multiplot
set output 'AdapterTiming2.svg
set terminal svg
set multiplot
set grid
set title "Audio adapter timing: host [rate = 44.1 kHz buffer = 512 frames] adapter [rate = 16.0 kHz buffer = 128 frames] "
set xlabel "audio cycles"
set ylabel "resampling ratio"
plot "JackAudioAdapter.log" using 4 title "Ratio 1" with lines,"JackAudioAdapter.log" using 5 title "Ratio 2" with lines
unset multiplot
unset output
