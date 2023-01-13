Story:

 - 5 philosophers sitting at a round table && there is a large bowl of spaghetti
 - There are also forks on the table, as many forks as philosophers.
  - Actions are eating, sleeping, thinking 
 - Because serving and eating spaghetti with only one fork is very inconvenient, a
    philosopher takes their right and their left forks to eat, one in each hand.
  - When a philosopher has finished eating, they put their forks back on the table and
    start sleeping. Once awake, they start thinking again. The simulation stops when
    a philosopher dies of starvation.
  - Every philosopher needs to eat and should never starve.
  - Philosophers don’t know if another philosopher is about to die.
  - Philosophers should avoid dying.


So, each philosopher is a thread.
There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right
side. As fork is a shared resource, they are protected with a mutex state which prevents philosophers from duplicating the forks.

The program works with folowing commands 'number_of_philosophers time_to_die (in ms) time_to_eat (in ms) time_to_sleep (in ms) [number_of_times_each_philosopher_must_eat] ' 

No data races are allowed.

