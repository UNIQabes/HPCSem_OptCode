#!/bin/zsh

#SBATCH -p bdw2-mixed 
#SBATCH -o report/%J_out_simpleJob.txt
#SBATCH -e report/%J_err_simpleJob.txt

echo  "orig"
./echo_avetime.sh "bin/main_orig"
echo  "swap_Loop"
./echo_avetime.sh "bin/main_swapLoop"
echo  "blocking"
./echo_avetime.sh "bin/main_blocking"
echo  "orig_blocking"
./echo_avetime.sh "bin/main_orig_blocking"
echo  "avx2"
./echo_avetime.sh "bin/main_avx2"
echo  "unroll"
./echo_avetime.sh "bin/main_unroll"
echo  "unroll_8"
./echo_avetime.sh "bin/main_unroll_8"
echo  "unroll_20"
./echo_avetime.sh "bin/main_unroll_20"

:<< "COMMENTOUT"
bin/main_orig
echo  ":orig"
bin/main_swapLoop
echo  ":swap_Loop"
bin/main_blocking
echo  ":blocking"
bin/main_blocking_188
echo  ":blocking_188"
bin/main_orig_blocking
echo  ":orig_blocking"
bin/main_unroll
echo  ":unroll"
bin/main_unroll_8
echo  ":unroll_8"
bin/main_unroll_20
echo  ":unroll_20"
bin/main_avx2
echo  ":avx2"
COMMENTOUT