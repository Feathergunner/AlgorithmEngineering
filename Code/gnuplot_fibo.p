set xlabel "Input"
set ylabel "Duration (mean in µs)"
set xr [0:100]
set yr [0:200]

set style fill transparent solid 0.2

set terminal png truecolor size 1600,1200
set output 'Fibo_time.png'

plot 'measurements/time_Fibo1_p' using 1:($2):($3) notitle with filledcurve ls 1 ,\
		'measurements/time_Fibo1_p' using 1:4 title 'Fibo1' with line ls 1 ,\
		'measurements/time_Fibo2_p' using 1:($2):($3) notitle with filledcurve ls 2 ,\
		'measurements/time_Fibo2_p' using 1:4 title 'Fibo2' with line ls 2 ,\
		'measurements/time_Fibo3_p' using 1:($2):($3) notitle with filledcurve ls 3 ,\
		'measurements/time_Fibo3_p' using 1:4 title 'Fibo3' with line ls 3 ,\
		'measurements/time_Fibo4_p' using 1:($2):($3) notitle with filledcurve ls 4 ,\
		'measurements/time_Fibo4_p' using 1:4 title 'Fibo4' with line ls 4 ,\
		'measurements/time_Fibo4-2_p' using 1:($2):($3) notitle with filledcurve ls 5 ,\
		'measurements/time_Fibo4-2_p' using 1:4 title 'Fibo4_2' with line ls 5 ,\
		'measurements/time_Fibo5_p' using 1:($2):($3) notitle with filledcurve ls 6 ,\
		'measurements/time_Fibo5_p' using 1:4 title 'Fibo5' with line ls 6 ,\
		'measurements/time_Fibo6_p' using 1:($2):($3) notitle with filledcurve ls 7 ,\
		'measurements/time_Fibo6_p' using 1:4 title 'Fibo6' with line ls 7


set yr [0:200000]
set ylabel "Cycles"
set output 'Fibo_cycles.png'

plot 'measurements/cycles_Fibo1_p' using 1:($2):($3) notitle with filledcurve ls 1 ,\
		'measurements/cycles_Fibo1_p' using 1:4 title 'Fibo1' with line ls 1 ,\
		'measurements/cycles_Fibo2_p' using 1:($2):($3) notitle with filledcurve ls 2 ,\
		'measurements/cycles_Fibo2_p' using 1:4 title 'Fibo2' with line ls 2 ,\
		'measurements/cycles_Fibo3_p' using 1:($2):($3) notitle with filledcurve ls 3 ,\
		'measurements/cycles_Fibo3_p' using 1:4 title 'Fibo3' with line ls 3 ,\
		'measurements/cycles_Fibo4_p' using 1:($2):($3) notitle with filledcurve ls 4 ,\
		'measurements/cycles_Fibo4_p' using 1:4 title 'Fibo4' with line ls 4 ,\
		'measurements/cycles_Fibo4-2_p' using 1:($2):($3) notitle with filledcurve ls 5 ,\
		'measurements/cycles_Fibo4-2_p' using 1:4 title 'Fibo4_2' with line ls 5 ,\
		'measurements/cycles_Fibo5_p' using 1:($2):($3) notitle with filledcurve ls 6 ,\
		'measurements/cycles_Fibo5_p' using 1:4 title 'Fibo5' with line ls 6 ,\
		'measurements/cycles_Fibo6_p' using 1:($2):($3) notitle with filledcurve ls 7 ,\
		'measurements/cycles_Fibo6_p' using 1:4 title 'Fibo6' with line ls 7
		
