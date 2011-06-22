set multiplot
set grid
set title "Audio adapter timing: host [rate = 44.1 kHz buffer = 512 frames] adapter [rate = 16.0 kHz buffer = 128 frames] "
set xlabel "audio cycles"
set ylabel "frames"
plot "JackAudioAdapter.log" using 2 title "Ringbuffer error" with lines,"JackAudioAdapter.log" using 3 title "Ringbuffer error with timing correction" with lines
 unset multiplot
set output 'AdapterTiming1.svg
set terminal svg
set multiplot
set grid
set title "Audio adapter timing: host [rate = 44.1 kHz buffer = 512 frames] adapter [rate = 16.0 kHz buffer = 128 frames] "
set xlabel "audio cycles"
set ylabel "frames"
plot "JackAudioAdapter.log" using 2 title "Consumer interrupt period" with lines,"JackAudioAdapter.log" using 3 title "Producer interrupt period" with lines
unset multiplot
unset output
