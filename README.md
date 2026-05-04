# Philosophers - The Dining Philosophers Problem 🍝

![Philosophers Banner](https://miro.medium.com/1*SdI7qwsNa05IkyiMXlAmPg.png)

## Brief Overview
Philosophers is a famous concurrency project at 42 school based on Edsger Dijkstra's "Dining Philosophers Problem". The project focuses on synchronizing multiple threads (or processes) that share limited resources. In this specific implementation, philosophers sit at a round table doing one of three things: eating, thinking, or sleeping.

To eat, a philosopher needs two forks (one in their right hand, one in their left). The challenge is to prevent deadlocks, resource starvation, and data races while keeping the philosophers alive using POSIX threads (`pthread`) and mutexes.


## What I Learned
This project is an introduction to multithreading and concurrency in C. By building it, I learned:
- **Multithreading:** Creating and managing multiple threads concurrently using `pthread_create` and `pthread_join`.
- **Synchronization (Mutexes):** Protecting shared resources (like forks and print statements) from simultaneous access using `pthread_mutex_lock` and `pthread_mutex_unlock`.
- **Data Races:** Understanding race conditions and learning how to avoid them by properly scoping shared memory.
- **Deadlocks/Starvation Prevention:** Structuring thread execution and fork acquisition in a way that two philosophers don't get stuck indefinitely waiting for each other.
- **Microsecond Precision:** Using `gettimeofday` to track precise timestamps for dying, eating, and sleeping events.

## How to Use

### Prerequisites
- A UNIX-like environment (Linux/macOS)
- `gcc` or `cc` compiler
- `make`

### Building the Project
Run the following command in the root directory:
```bash
make
```
This will compile the project and create the executable `philo`.

### Running the Simulator
The program takes 4 mandatory arguments and 1 optional argument:
```bash
./philo nb_philos time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

**Parameters:**
- `nb_philos`: The number of philosophers (and forks). Maximum 200.
- `time_to_die` (ms): If a philosopher doesn’t start eating within this time after starting their last meal or the simulation start, they die. (Minimum 60)
- `time_to_eat` (ms): The time it takes for a philosopher to eat. (Minimum 60)
- `time_to_sleep` (ms): The time a philosopher spends sleeping. (Minimum 60)
- `number_of_times_each_philosopher_must_eat` (Optional): If all philosophers eat at least this many times, the simulation stops. If not specified, the simulation only stops when a philosopher dies.

**Example Usage:**
```bash
# 4 philosophers, 800ms to die, 200ms to eat, 200ms to sleep. Runs until someone dies.
./philo 4 800 200 200

# 5 philosophers, 800ms to die, 200ms to eat, 200ms to sleep. Stops after everyone eats 7 times.
./philo 5 800 200 200 7
```

## Useful Resources
- [The Dining Philosophers Problem Explained](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [POSIX Threads (pthreads) in C](https://www.geeksforgeeks.org/multithreading-c-cpp/)
- [Mutexes in C](https://www.thegeekstuff.com/2012/05/c-mutex-examples/)
- [Valgrind Helgrind (For checking Data Races)](https://valgrind.org/docs/manual/hg-manual.html)
