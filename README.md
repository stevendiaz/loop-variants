# Loop Variant experiments with Matrix Matrix multiply

### Description

This program uses the PAPI library to measure the performance differences
between the 6 loop variants. (ijk, ikj, jik, jki, kij, kji)

### End to End Compile-Job Submit

To compile both programs and submit both to SLURM, run the following in the project root directory

```
$ make end_to_end
```

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


