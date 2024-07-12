#!/bin/zsh

#SBATCH -p bdw2-mixed 
#SBATCH -o report/%J_out_tbJob.txt
#SBATCH -e report/%J_err_tbJob.txt

:<< "COMMENTOUT"
echo  "orig"
./echo_avetime.sh "bin/main_swapLoop"
echo  "blocking(1,8,8)"
./echo_avetime.sh "bin/main_blocking_188"
echo  "blocking(2,8,8)"
./echo_avetime.sh "bin/main_blocking_288"
echo  "blocking(4,8,8)"
./echo_avetime.sh "bin/main_blocking_488"
echo  "blocking(8,8,8)"
./echo_avetime.sh "bin/main_blocking"
echo  "blocking(20,8,8)"
./echo_avetime.sh "bin/main_blocking_2088"
echo  "blocking(40,8,8)"
./echo_avetime.sh "bin/main_blocking_4088"
echo  "blocking(2,8,40)"
./echo_avetime.sh "bin/main_blocking_2840"
echo  "blocking(8,8,40)"
./echo_avetime.sh "bin/main_blocking_8840"
COMMENTOUT

bin/main_blocking_188
echo  ":blocking_188"
bin/main_blocking_288
echo  ":blocking_288"
bin/main_blocking_488
echo  ":blocking_488"
bin/main_blocking
echo  ":blocking_888"
bin/main_blocking_2088
echo  ":blocking_2088"
bin/main_blocking_4088
echo  ":blocking_4088"
bin/main_blocking_20088
echo  ":blocking_20088"
bin/main_blocking_2840
echo  ":blocking_2840"
bin/main_blocking_8840
echo  ":blocking_8840"



