# C CLI Todo Application

A simple command-line todo list application written in C.

## Features
- Add tasks
- List tasks
- Mark tasks as complete
- Delete tasks
- Store tasks persistently

## Building the Application
Ensure you have GCC installed on your system.

```bash
gcc todo.c -o todo
```

## Usage
```bash
# Add a new task
./todo add "Complete homework"

# List all tasks
./todo list

# Mark task as complete (using task number)
./todo done 1

# Delete a task (using task number)
./todo delete 1
```

## Requirements
- GCC compiler
- Standard C libraries

## Contributing
Feel free to submit issues and pull requests.

## License
MIT License