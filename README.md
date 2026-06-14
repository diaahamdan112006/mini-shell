# Minishell

A lightweight Unix shell implementation in C that replicates Bash core functionality — command execution, pipes, redirections, environment variables, signals, and heredocs.

## Features

### Built-in Commands
| Command | Description |
|---------|-------------|
| `echo [-n]` | Print arguments to stdout (omit trailing newline with `-n`) |
| `cd [path]` | Change directory (defaults to `$HOME`) |
| `pwd` | Print working directory |
| `export [name[=value]]` | Set or display environment variables |
| `unset name` | Remove environment variable |
| `env` | Display all environment variables |
| `exit [code]` | Exit shell with optional status code |
| `clear` | Clear terminal screen |

### Shell Features
- **Command execution**: Run any system command via `execve()` with full `$PATH` resolution
- **Pipes `|`**: Chain commands, connecting stdout of one to stdin of the next
- **Redirections**:
  - `< file` — input from file
  - `> file` — output to file (truncate)
  - `>> file` — output to file (append)
  - `<< delimiter` — heredoc input
- **Environment variables**: Expand `$VAR` and `$?` (last exit status) with full quote awareness
- **Quoting**: Single quotes (`'`) preserve literals; double quotes (`"`) allow `$` expansion
- **Signal handling**:
  - `Ctrl+C` — prints new prompt without exiting
  - `Ctrl+\` — ignored in interactive mode, handled in child processes
  - `Ctrl+D` — exits the shell
- **History**: Persistent command history saved to `/tmp/.mini_History`

## Getting Started

### Prerequisites
- GCC or Clang
- GNU Readline library (`libreadline-dev`)

### Installation

```bash
# Clone the repository
git clone git@github.com:diaahamdan112006/mini-shell.git
cd mini-shell

# Build
make

# Run
./minishell
```

### Cleanup
```bash
make clean     # Remove object files
make fclean    # Remove object files and binary
make re        # Clean and rebuild
```

## Project Structure

```
├── include/          # Header files
│   ├── mini.h        # Main header (exec + builtins)
│   ├── macros.h      # Constants, colors, error messages
│   ├── parsing.h     # Parsing declarations
│   └── structures.h  # Data structure definitions
├── builtins/         # Built-in command implementations
│   ├── cd.c          # Directory navigation
│   ├── echo.c        # Output printing
│   ├── ft_env.c      # Environment display
│   ├── ft_exit.c     # Shell exit
│   ├── ft_export.c   # Environment variable management
│   ├── ft_unset.c    # Environment variable removal
│   ├── pwd.c         # Working directory display
│   ├── utils.c       # Built-in helper functions
│   └── utils2.c      # Additional utilities
├── exec/             # Execution engine
│   ├── main.c        # Entry point and main loop
│   ├── exec_cmd.c    # Fork, pipe, and execve management
│   ├── get_path.c    # $PATH resolution for commands
│   ├── handle_signals.c  # Signal handler implementations
│   ├── help_linkedlist.c # Linked list operations
│   ├── utils.c       # Command dispatch and error handling
│   └── libft/        # Custom libc implementations
│       ├── ft_atoi.c
│       ├── ft_memcpy.c
│       ├── ft_split.c
│       ├── ft_strchr.c
│       ├── ft_strlcpy.c
│       └── ft_strstr.c
├── parsing/          # Parsing and tokenization
│   ├── parsing.c     # Main parser (pipe splitting, expression parsing)
│   ├── buckets.c     # Redirection file operations
│   ├── cmd.c         # Command splitting by `|`
│   ├── errors.c      # Syntax error detection
│   ├── expressions1.c # Token extraction and expansion pipeline
│   ├── expressions2.c # Quote-aware string extraction
│   ├── here_doc.c    # Heredoc limiter parsing
│   ├── prompt.c      # Interactive prompt display
│   ├── redirect.c    # Pipe creation and I/O assignment
│   ├── run_heredoc.c # Heredoc input loop
│   ├── data_structures/  # Linked list implementations
│   │   ├── commands.c
│   │   ├── dollars.c
│   │   ├── heredocs.c
│   │   └── queue.c
│   ├── functions/    # Utility functions
│   │   ├── builtins.c
│   │   ├── compare.c
│   │   ├── conditions.c
│   │   ├── itoa.c
│   │   ├── join_strings.c
│   │   ├── quotes.c
│   │   ├── search.c
│   │   └── strings.c
│   └── variables/    # $ variable expansion
│       ├── expansion.c
│       ├── expansion1.c
│       └── get_dollars.c
├── get_next_line/    # GNL for history file reading
├── Makefile
└── README.md
```

## How It Works

### Architecture

Minishell follows a three-stage pipeline:

1. **Parsing** — Raw input is split into commands by `|`, each command is tokenized into words, redirections, and heredocs. `$` variables are expanded with full quote-awareness.

2. **Execution** — Pipes are created between commands. Each command runs in a forked child process with stdin/stdout connected to the appropriate pipe ends or redirected files. Built-in commands are detected and executed directly.

3. **Cleanup** — After all commands complete, memory is freed and the parent process waits for children, collecting exit statuses.

### Signal Handling

Three signal modes control behavior:
- **Mode 0** (main loop): `Ctrl+C` redraws prompt, `Ctrl+\` ignored
- **Mode 1** (child processes): Default signal behavior for both
- **Mode 2** (heredoc): `Ctrl+C` closes stdin to break input loop

### Environment Variables

Variables are stored as a linked list of `(name, value)` pairs. The `export` and `unset` builtins modify this list, which is converted to a `char **` array before being passed to `execve()`.


