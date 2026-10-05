set pagination off
set confirm off
set remotecache off
target extended-remote localhost:4242
break HAL_TIM_PeriodElapsedCallback
continue 1000
printf "tick = %u\n", tick
continue 1000
printf "tick = %u\n", tick
continue 1000
printf "tick = %u\n", tick
quit
