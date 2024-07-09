#!/bin/zsh

#SBATCH -p bdw2-mixed 
#SBATCH -o report/%J_out_simpleJob.txt
#SBATCH -e report/%J_err_simpleJob.txt

bin/main_orig