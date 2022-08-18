# Philosophers

It is a 21 (42) school project about concurrent programming.
The programm monitors its threads, using mutexes to avoid deadlocks and data races.
The programm is available for Linux and MacOS.

It is a solution of classic computer science problem of "dining philosopers".
The philosophers sit and eat at one table. The philosopher can only eat, think and sleep. Each philosopher has only one fork, while they need two of them to eat, so they have to borrow a neighbor's fork. After a philosopher finishes eating, they will put down both forks.
The problem is how to design an algrorithm such that no philosopher will starve, assuming that no philosopher can know when others may want to eat or think (an issue of incomplete information).

## Usage
To configure run:  
`cd ./philo  
make`

Usage: `./philo number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]`
