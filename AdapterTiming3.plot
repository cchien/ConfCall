set multiplot
set grid
set title "Audio adapter timing: host [rate = 44.1 kHz buffer = 512 frames] adapter [rate = 16.0 kHz buffer = 128 frames] "
set xlabel "audio cycles"
set ylabel "frames"
plot "JackAudioAdapter.log" using 6 title "Frames position in consumer ringbuffer" with lines,"JackAudioAdapter.log" using 7 title "Frames position in producer ringbuffer" with lines
 unset multiplot
set output 'AdapterTiming3.svg
set terminal svg
set multiplot
set grid
set title "Audio adapter timing: host [rate = 44.1 kHz buffer = 512 frames] adapter [rate = 16.0 kHz buffer = 128 frames] "
set xlabel "audio cycles"
set ylabel "frames"
plot "JackAudioAdapter.log" using 6 title "Frames position in consumer ringbuffer" with lines,"JackAudioAdapter.log" using 7 title "Frames position in producer ringbuffer" with lines
unset multiplot
unset output
