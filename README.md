<div align="center">
  <h1>
    📗 Philosophers
  </h1>
  <p>
    <b><i> The classic synchronization and multi-threaded philosopher dining problem.</i></b>
  </p>
  <p>
    Developed using&nbsp&nbsp
    <a href="https://skillicons.dev">
      <img src="https://skillicons.dev/icons?i=c,vscode,git" />
    </a>
  </p>
</div>

<br />

## Table Of Content
- [Features](#features)
- [How It Works](#how-it-works)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Features
- Visual representation of the problem and solution (prints out the current philosopher state).
- Real-time status updates of each philosopher.
- Adjustable parameters for the simulation.
- Clean and well-commented code for better understanding.

## How It Works
The Dining Philosophers problem is a classic synchronization and multi-threaded problem which demonstrates the challenges of ensuring that multiple threads share resources without conflicts. In this project, [number of philosophers] philosophers sit at a round table, each with a bowl of spaghetti and a fork between each adjacent pair. The philosophers have 3 states, thinking, eating and sleeping. If they are thinking they cannot be eating, if they are eating they cannot be sleeping etc.. However, a philosopher needs both forks to eat, and must pick them up one at a time. This scenario leads to a number of synchronization issues which are addressed and solved in this implementation.

## Installation
Clone the repository
```bash
git clone https://github.com/RealConrad/42philosophers.git
```
Navigate to the project directory
```bash
cd 42philosophers/philo/
```
Compile the project
```bash
make
```

## Usage
> NOTE: ms = milliseconds
```
./philo [number_of_philosophers] [time_to_die_ms] [time_to_eat_ms] [time_to_sleep_ms] [OPTIONAL: eat_count]
```
Example:
```
./philo 4 600 200 200 5
```



