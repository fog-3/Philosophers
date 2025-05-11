# Philosophers 🍝🧠

![Dining Philosophers Problem](Philo.png)

## Introduction
This project solves the classic **Dining Philosophers Problem** using threads and mutexes. Each philosopher alternates between eating, sleeping, and thinking, while avoiding deadlocks and starvation.

**Mandatory Part** ✔️

---

## Features
- Input parsing and validation
- Precise time management with `gettimeofday()`
- Threads for philosophers and monitoring
- Mutexes for shared resources (forks)
- Error handling and clean exit
- Death detection mechanism
- Optional meal limit simulation

---

## Requirements
- **Allowed functions**:  
  `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`,  
  `pthread_create`, `pthread_detach`, `pthread_join`,  
  `pthread_mutex_init`, `pthread_mutex_destroy`,  
  `pthread_mutex_lock`, `pthread_mutex_unlock`

---

## 🛠️ Installation & Usage

### Compilation
```bash
make        # Compile mandatory part
make bonus  # Compile bonus part (if implemented)
```

### Execution
```bash
./philo <number_of_philos> <time_to_die> <time_to_eat> <time_to_sleep> [meals_limit]
```

### Example
```bash
./philo 4 410 200 200  # 4 philosophers, no meal limit
./philo 5 800 200 200 7  # Stop after 7 meals per philosopher
```

---

## 📜 Example Output
```bash
0ms 1 has taken a fork
0ms 2 has taken a fork
0ms 1 is eating
200ms 1 is sleeping
200ms 2 is eating
400ms 1 is thinking
...
```

In a table it would look like that:

![table](imgof_table.jpg)

*You can see this tipes of tables giving the result of the ejecutation on this [web](https://nafuka11.github.io/philosophers-visualizer/).*

---

## Theory: Dining Philosophers Problem
A classic synchronization problem where:
- Philosophers alternate between eating and thinking
- Need **two forks** to eat
- Must avoid:
  - **Deadlocks** (circular waiting)
  - **Starvation** (philosophers never getting access)
  - **Data races** (improper mutex handling)

This implementation uses a **mutex per fork** and careful timing to ensure fairness.

---

## Testing
Recommended tests:
```bash
# Quick test (should not die)
./philo 4 410 200 200

# Meal limit test
./philo 5 800 200 200 7 | grep "eating" | wc -l

# Death simulation
./philo 3 310 200 100

# Sanitize check
make re SANITIZE=1
```

---

## 📝 Credits
- **Completed at:** 42 Malaga  
- **Author:** Fernando (@fosuna-g)  
- **Date:** [to complete]  
- Classic computer science problem by Edsger Dijkstra


📚 **42 Philosophy**: *"Share knowledge, write clean code, and never stop learning!"*

