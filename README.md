# Assignment 1 CS377P

### How to compile

In the root directory run 

```
$ module load papi
$ make
```

### How to run

In the root directory

```
$ make run     # Runs PAPI timers on matrix multiply
$ make run_np  # Runs clock_gettime
```

### How to submit a SLURM job

In the root directory

```
$ sbatch slurm_matrix_multiply
$ sbatch slurm_no_papi
```

Output will be in the `output/` directory

