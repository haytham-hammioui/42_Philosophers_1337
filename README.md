<h1 align="center">42_PHILOSOPHERS_1337</h1>
<p align="center">
  <a href="https://github.com/haytham-hammioui/42_Philosophers_1337">
    <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/refs/heads/main/badges/philosopherse.png" alt="42 Badge">
  </a>
</p>

# Philosophers

The `Philosophers` project is part of the 42 network curriculum. It's a simulation of the classic Dining Philosophers problem, demonstrating synchronization issues in concurrent programming and solutions using `threads` and `mutexes`.

## Features

- **Thread Management**: Each philosopher runs in its own thread with proper lifecycle management.
- **Mutex Protection**: Implements robust synchronization to prevent deadlocks and race conditions.
- **State Management**: Handles all philosopher states (thinking, eating, sleeping) with precise timing.
- **Health Monitoring**: Continuous death monitoring to ensure philosophers don't starve.
- **Meal Counting**: Optional simulation termination when all philosophers reach a specified meal count.
- **Edge Case Handling**: Properly handles special scenarios like single philosopher case.
- **Resource Management**: Efficient cleanup with proper destruction of mutexes and memory freeing.

## Getting Started

### Installation

1. **Clone the Repository**
   ```sh
   git clone https://github.com/haytham-hammioui/42_Philosophers_1337.git philosophers
   ```

2. **Compile the Program**
   Navigate to the `philo` directory and run `make`. This will generate the `philo` executable.
   ```sh
   cd philosophers
   cd philo
   make
   ```

### Usage

1. Run the program with the following parameters:
    ```sh
     ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
    ```
    ## Parameters

    - **`number_of_philosophers`**: Number of philosophers and forks
    - **`time_to_die`**: Time in milliseconds before a philosopher dies if not eating  
    - **`time_to_eat`**: Time in milliseconds a philosopher spends eating
    - **`time_to_sleep`**: Time in milliseconds a philosopher spends sleeping
    - **`[number_of_times_each_philosopher_must_eat]`**: *(Optional)* If specified, simulation stops when all philosophers have eaten at least this many times

  Example:
  ```sh
     # Basic simulation with 5 philosophers
      ./philo 5 800 200 200
     # Simulation that stops after each philosopher eats 7 times
      ./philo 4 410 200 200 7
     # Single philosopher case (will die)
      ./philo 1 800 200 200
  ```
    
### Program Output
  The program displays the state of each philosopher in real-time:
  ```sh
    timestamp_in_ms X has taken a fork
    timestamp_in_ms X is eating
    timestamp_in_ms X is sleeping
    timestamp_in_ms X is thinking
    timestamp_in_ms X died
  ```
   
## Contributing

Contributions to `Philosophers` are welcome! Whether you've found a bug, have a feature request, or want to contribute code:

1. Fork the repository.
2. Create a new branch for your changes.
3. Add your contributions.
4. Push your branch and open a pull request against the `Philosophers` repository.
