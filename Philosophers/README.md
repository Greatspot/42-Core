## 🔢 ABOUT The Philosphers problem

One or more philosophers sit at a round table.

There is a large bowl of spaghetti in the middle of the table. The philosophers alternatively eat, think, or sleep. While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping; and, of course, while sleeping, they are not eating nor thinking.

There are also forks on the table. There are as many forks as philosophers.

Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.

When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.

Every philosopher needs to eat and should never starve.

Philosophers don’t speak with each other.

Philosophers don’t know if another philosopher is about to die.

No need to say that philosophers should avoid dying!

For further exploration of this problem, you can consult the <a href="https://en.wikipedia.org/wiki/Dining_philosophers_problem">Wikipedia</a> article.


#### 1º - Enter the project folder and run `make`
```bash
cd philo
make
```

#### 2º - Launch the program
> The last argument is optional for the execution of the program.
```bash
./philo [n of philos] [time to die] [time to eat] [time to sleep] [n times each philo must eat]
```

#### MAKEFILE RULES
`make` or `make all` - Compile philosophers **mandatory** files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object file) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

## MANDATORY
> Objective: can't kill the philosophers.
- [x] Each philosopher is a **thread** and each fork is a **mutex**.
- [x] They do it in order: `eat` -> `sleep` -> `think` (they don't think, they wait to have their forks to eat).
- [x] To eat they must have two forks, knowing that there is only one fork per philosopher.
- [x] If one of them dies, the simulation stops and death must be displayed in a maximum of 10 milliseconds.
- [x] Write each change of the philosopher's status.
 
## BONUS
> The bonus program takes the same arguments and it as to comply with the mandatory rules.
- [ ] All the forks are put in the middle of the table.
- [ ] They have no states in memory, but the number of available forks is represented by a semaphore.
- [ ] Each philosopher should be a process, but the main process should not be a philosopher.

## PHILOSOPHERS

```bash
./philo [arg1] [arg2] [arg3] [arg4] [arg5]
``` 

| Arg | Function | Description |
| :- | :- | :- |
| [arg1] | `number_of_philosophers`                    | Number of philosophers and number of forks.              |
| [arg2] | `time_to_die`                               | If he hasn't eaten for time_to_die milliseconds he dies. |
| [arg3] | `time_to_eat`                               | Time to eat with two forks in milliseconds.              |
| [arg4] | `time_to_sleep`                             | Time to sleep in milliseconds.                           |
| [arg5] | `number_of_times_each_philosopher_must_eat` | Number of times each philosopher must eat. (Optional)    |

#### THREADS AND MUTEXES
A **thread** is a unit of execution within a process. Each **process** has at least one **thread**, but additional **threads** can be created. A **thread** consists of unique elements and shared elements with other **threads** of the same process, such as the code section, data section, and operating system resources like open files and signals.

However, if two **threads** of the same process try to access the same shared memory variable simultaneously, it can lead to undefined behaviours, known as **data races**. To prevent this, **mutexes** are used. **Mutexes** block a piece of code, allowing only one **thread** at a time to execute that piece of code, similar to how a toilet key is used.

In the context of the given example:
* Each fork has its own **mutex**, which can be locked when a philosopher takes it.
* There is also a **mutex** shared by all the philosophers, ensuring that text is printed without mixing.

#### STRATEGY
>To prevent conflicts and ensure proper execution, the following strategies are employed:

Make even or odd philosophers start with a delay.** If all philosophers start at the same time and take their right fork, none of them will be able to eat.

```c
if (ph->id % 2 == 0)
  ft_usleep(ph->pa->eat / 10);
```
 
Each philosopher has their fork on the left (`left_fork`) and borrows the fork from their right neighbour using a pointer (`*right_fork`) that points to the left fork of the neighbour on the right.
 
```c
while (i < p->a.total)
{
  p->ph[i].id = i + 1;
  // Each philosopher has their fork on the left
  pthread_mutex_init(&p->ph[i].left_fork, NULL);
  if (i == p->a.total - 1)
    // Borrow the fork from the right neighbour if the philosopher is the last one
    p->ph[i].right_fork = &p->ph[0].left_fork;
  else
    // Borrow the fork from the right neighbor
    p->ph[i].right_fork = &p->ph[i + 1].left_fork;
  i++;
}
```
 
Death checking is performed in a separate **thread** to ensure timely detection. If the main **thread** continuously checks for death, it can significantly impact performance. So, when a philosopher performs their activities, a separate **thread** is launched to check if any philosopher has died. This **thread** sleeps for the duration specified by `time_to_die` and then checks if the philosopher is still alive.
 
```c
pthread_create(&ph->thread_death_id, NULL, is_dead, data);
void *is_dead(void *data)
{
  ft_usleep(ph->pa->die + 1);
  if (!check_death(ph, 0) && !ph->finish && ((actual_time() - ph->ms_eat) >= (long)(ph->pa->die)))
{
// The philosopher is dead
```
 
#### TIME MANAGEMENT
> Time can be managed using the following conversions:

| Second | Millisecond | Microsecond |
| :-- | :-- | :-- |
| 1     | 1000 | 1e+6 |
| 0.001 | 1    | 1000 |
 
The `gettimeofday` function is used to get the current time, which is stored in a timeval structure. The following example demonstrates how `gettimeofday` works:
```c
struct timeval current_time;
gettimeofday(&current_time, NULL);
printf("seconds : %ld\nmicro seconds : %d", current_time.tv_sec, current_time.tv_usec);
```
 
To get the current time in milliseconds using `gettimeofday`, the following function can be used:
```c
long int actual_time(void)
{
  long int time;
  struct timeval current_time;
  time = 0;
  if (gettimeofday(&current_time, NULL) == -1)
    ft_exit("Gettimeofday returned -1\n");
  //time in milliseconds
  time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
  return (time);
}
```
 
A custom `ft_usleep` function is created to provide more precise control over the sleep time compared to the actual `usleep` function, which waits at least the specified time. The custom function repeatedly checks the time difference until the desired time has passed.
```c
void ft_usleep(long int time_in_ms)
{
  long int start_time;
  start_time = 0;
  start_time = actual_time();
  while ((actual_time() - start_time) < time_in_ms)
    usleep(time_in_ms / 10);
}
````
 
#### DATA RACES
A **data race** occurs when two or more **threads** within a single process concurrently access the same memory location, with at least one of the accesses being a write operation, and no exclusive locks are used to control the accesses. **Data races** can lead to a non-deterministic order of accesses and produce different results from run to run. While some **data races** may be harmless, many are bugs in the program.

To fix **data races**, the option `-g fsanitize=thread` can be used.

The tools `valgrind --tool=helgrind` or `valgrind --tool=drd` can be utilized to detect any missing or misused **mutexes**. Warnings or errors from these tools indicate potential issues that should be manually checked. Such issues are often signs of a problematic project, even if it appears to be working.

- `detached` refers to a **thread** that cleans its memory as soon as it finishes. It is essential to ensure that the main **thread** does not terminate before the detached **thread** completes its execution.
- `reachable` refers to a **thread** that does not destroy its memory when it finishes. The `pthread_join` function can be used to block the execution until the **thread** finishes.
 
## EXAMPLES
> The performance will change if you use `-fsanitize` and `valgrind` or both together.
 
| Example | Expected Result |
| :-- | :-- |
| `./philo 1 200 200 200`           | Philosopher 1 takes a fork and dies after 200 ms.              |
| `./philo 2 800 200 200`           | No philosopher dies.                                           |
| `./philo 5 800 200 200`           | No philosopher dies.                                           |
| `./philo 5 800 200 200 7`         | The program stops when each philosopher has eaten 7 times.     |
| `./philo 4 410 200 200`           | No philosopher dies.                                           |
| `./philo 4 310 200 200`           | A philosopher dies.                                            |
| `./philo 4 500 200 1.2`           | Invalid argument.                                              |
| `./philo 4 0 200 200`             | Invalid argument. A philosopher dies.                                             |
| `./philo 4 -500 200 200`          | Invalid argument.                                              |
| `./philo 4 500 200 2147483647`    | A philosopher dies after 500 ms                                |
| `./philo 4 2147483647 200 200`    | No philosopher dies.                                           |
| `./philo 4 214748364732 200 200`  | Invalid argument.                                              |
| `./philo 4 200 210 200`           | A philosopher dies, it should display the death before 210 ms. |
| `./philo 5 800 200 150`           | No philosopher dies.                                           |
| `./philo 3 610 200 80`            | No philosopher dies.                                           |
 
## Used tests
* 42-philosophers-tester: https://github.com/dantonik/42-philosophers-tester
* Alientest_philosopher: https://github.com/lienardale/alientest_philosopher
* Philosophers-visualizer: https://nafuka11.github.io/philosophers-visualizer
* Visualizer: https://nafuka11.github.io/philosophers-visualizer/
