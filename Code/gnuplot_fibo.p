set xlabel "Input"
set ylabel "Duration (mean in µs)"
set xr [0:100]
set yr [0:80]

set terminal png size 1000,700
set output 'running_time_plot.png'

plot 'measurements/measure_Fibo1_p' using 1:4 title 'Fibo1' with lines ls 1 ,\
		'measurements/measure_Fibo2_p' using 1:4 title 'Fibo2' with lines ls 2 ,\
		'measurements/measure_Fibo3_p' using 1:4 title 'Fibo3' with lines ls 3 ,\
		'measurements/measure_Fibo4_p' using 1:4 title 'Fibo4' with lines ls 4 ,\
		'measurements/measure_Fibo4_2_p' using 1:4 title 'Fibo4_2' with lines ls 5 ,\
		'measurements/measure_Fibo5_p' using 1:4 title 'Fibo5' with lines ls 6 ,\
		'measurements/measure_Fibo6_p' using 1:4 title 'Fibo6' with lines ls 7 
